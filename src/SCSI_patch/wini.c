/* This file contains a driver for the "hard disk".
 *
 * The driver supports the following operations (using message format m2):
 *
 *    m_type      DEVICE    PROC_NR     COUNT    POSITION  ADRRESS
 * ----------------------------------------------------------------
 * |  DISK_READ | device  | proc nr |  bytes  |  offset | buf ptr |
 * |------------+---------+---------+---------+---------+---------|
 * | DISK_WRITE | device  | proc nr |  bytes  |  offset | buf ptr |
 * |------------+---------+---------+---------+---------+---------|
 * | DISK_IOCTL | device  |         |         |         |         |
 * ----------------------------------------------------------------
 * |SCATTERED_IO| device  | proc nr | requests|         | iov ptr |
 * ----------------------------------------------------------------
 *
 * The file contains one entry point:
 *
 *   winchester_task:	main entry when system is brought up
 *
 */

#include "kernel.h"
#include "setup.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/boot.h>
#include <mac/Files.h>
#include <mac/SCSI.h>
#include <stdlib.h>
#include "proc.h"
#include "scsistructs.h"

/* Configurable parameters */
#define NR_DEVICES     10	/* how many winis? */
#define USE_BLIND_READ		/* Define to use blind reads */
#define USE_BLIND_WRITE		/* Define to use blind writes */
	/* Blind reads and writes are only used within a sector */
	/* and only if the appropriate line above is defined.  */
	/* Blind reads and writes are faster but somewhat less */
	/* stable than non-blind reads and writes.  NOTE: On a */
	/* Macintosh Plus (only), blind reads and writes could */
	/* fail without giving any error indication if the device */
	/* is slow.  For most (all) hard drives and reliable SCSI */
	/* busses, blind reads and writes should be okay. */
#define SECT_SIZE	512	/* Virtually all hard drives */

/* Non-configurable parameters */
#define HD_OPEN		0	/* open code OLD--GONE AWAY */
#define HD_CLOSE	1	/* close code */
#define HD_NOPEN	2	/* new open code */
#define HD_GETFILE	3	/* new get file name code */
#define MAXBLOCKS      25	/* max blocks to coalesce */
#define SINGLE		0
#define MULTI		1
#define NO_DISK         0	/* Code for non-disk */
#define FILE_DISK       1	/* Code for (old-style) file disk */
#define SCSI_DISK	2	/* Code for SCSI partition */

struct file_wini {
  int fref;
  char name[256];
  long nblocks;
  ParamBlockRec pb;
};

struct scsi_wini {		/* Sectors are physical; blocks fs */
  int id;
  unsigned long first;		/* First sector in partition */
  unsigned long nblocks;	/* Number of blocks in partition */
  unsigned sect2block;		/* 2^sect2block sectors/block */
  int sector_sz;		/* Bytes in a sector */
  char name[32];
  int readonly;			/* Read-only device/partition? */
};

struct wini {
  int type;
  union {
	struct file_wini f;
	struct scsi_wini s;
  } u;
};
PRIVATE char tempbuf[512];	/* For partition table, etc. */
PRIVATE char fname[256];
PRIVATE char nbuf[256];
PRIVATE struct wini wini[NR_DEVICES];
PRIVATE message w_mess;		/* message buffer for in and out */
PRIVATE char cdb[6];
PRIVATE struct SCSIInstr tib[4];

FORWARD _PROTOTYPE(int w_do_rdwt, (message * m_ptr, int type));
FORWARD _PROTOTYPE(int w_do_ioctl, (message * m_ptr));
FORWARD _PROTOTYPE(char *w_open, (struct wini * w, char *name));
FORWARD _PROTOTYPE(void w_blocks, (struct wini * w));
FORWARD _PROTOTYPE(int w_do_vrdwt, (message * m_ptr));
FORWARD _PROTOTYPE(int phys_rw, (int sid, int ssize, long start, int num, char *buf, char op));

/*===========================================================================*
 *				winchester_task				     *
 *===========================================================================*/
PUBLIC void winchester_task()
{
/* Main program of the wini disk driver task. */

  struct config conf;
  int r, caller, proc_nr;

  /* Initialize wini array--nothing open */
  for (r = 0; r < NR_DEVICES; r++) wini[r].type = NO_DISK;

  /* If I am the boot device go ahead and open the root file */
  if (BOOT_DEV == DEV_HD0) {
	setup(&conf, 0, 0);
	override(conf.root);
	if (w_open(&wini[0], conf.root) != (char *) NULL)
		panic("Cannot open root filesystem!", NO_NUM);

	if (conf.ram) {
		extern phys_bytes free_bytes;
		phys_bytes blks;
		blks = (free_bytes - code_base) / 1024L;
		/* Mm causes really bad things to happen when it
		 * detects this condition later. Detect it now
		 * instead */
		if ((wini[0].type == FILE_DISK && wini[0].u.f.nblocks > blks) ||
		  (wini[0].type == SCSI_DISK && wini[0].u.s.nblocks > blks))
			panic("Not enough memory for ram disk", NO_NUM);
	}
  }

  /* Here is the main loop of the disk task.  It waits for a message,
   * carries it out, and sends a reply. */
  while (TRUE) {
	/* First wait for a request to read or write a disk block. */
	receive(ANY, &w_mess);	/* get a request to do some work */
	if (w_mess.m_source < 0) {
		printf("wini task got message from %d ", w_mess.m_source);
		continue;
	}
	caller = w_mess.m_source;
	proc_nr = w_mess.PROC_NR;

	/* Now carry out the work. */
	switch (w_mess.m_type) {
	    case DISK_READ:
	    case DISK_WRITE:
		r = w_do_rdwt(&w_mess, SINGLE);
		break;
	    case SCATTERED_IO:
		r = w_do_vrdwt(&w_mess);
		break;
	    case DISK_IOCTL:
		r = w_do_ioctl(&w_mess);
		break;
	    default:	r = EINVAL;	break;
	}

	/* Finally, prepare and send the reply message. */
	w_mess.m_type = TASK_REPLY;
	w_mess.REP_PROC_NR = proc_nr;

	w_mess.REP_STATUS = r;	/* # of bytes transferred or error code */
	send(caller, &w_mess);	/* send reply to caller */
  }
}

#ifdef THINK_C
extern char CacheCom:0x39c;
#else
extern char CacheCom;
#endif

/*===========================================================================*
 *				w_do_rdwt				     *
 *===========================================================================*/
PRIVATE int w_do_rdwt(m_ptr, type)
message *m_ptr;			/* pointer to read or write w_message */
int type;			/* SINGLE or MULTI */
{
/* Carry out a read or write request from the disk. */
  int r, device, errors = 0;
  register struct wini *w;
  IOParam *pbio;
  message m;
  extern void w_int();
  phys_bytes user_phys;
  char saveCacheCom;
  long first, my_count;
  int num, err;

  /* Decode the w_message parameters. */
  device = m_ptr->DEVICE;
  if (device < 0 || device >= NR_DEVICES || wini[device].type == NO_DISK)
	return(EIO);
  if (type == SINGLE) {
	if (m_ptr->COUNT != BLOCK_SIZE && m_ptr->PROC_NR != HARDWARE)
		return(EINVAL);
	if (m_ptr->POSITION % BLOCK_SIZE != 0) return(EINVAL);
	if ((m_ptr->COUNT & (BLOCK_SIZE - 1)) && wini[device].type == SCSI_DISK)
		return(EINVAL);	/* e.g. not whole block length */

	/* Determine address where data is to go or to come from. */
	user_phys = numap(m_ptr->PROC_NR, (vir_bytes) m_ptr->ADDRESS,
			  (vir_bytes) m_ptr->COUNT);
	if (user_phys == 0) return(E_BAD_ADDR);
  } else {			/* MULTI */
	/* Determine address where data is to go or to come from. */
	user_phys = (phys_bytes) m_ptr->ADDRESS;
	if (user_phys == 0) return(E_BAD_ADDR);
  }
  w = &wini[device];
  if (w->type == FILE_DISK) {
	/* Check for eof */
	if (( m_ptr->POSITION / BLOCK_SIZE) > w->u.f.nblocks) return(0);
	pbio = &w->u.f.pb.ParamBlkType.ioParam;
	w->u.f.pb.ioCompletion = (ProcPtr) w_int;
	pbio->ioRefNum = w->u.f.fref;
	pbio->ioActCount = 0;
	pbio->ioBuffer = (char *) user_phys;
	pbio->ioReqCount = m_ptr->COUNT;
	pbio->ioPosMode = fsFromStart;
	pbio->ioPosOffset = m_ptr->POSITION;
#ifdef THINK_C
	pbio->ioMisc = (char *) geta5();
#endif

	/* Disable Mac OS caching -- MINIX has its own cache (Tech
	 * Note #81) */
	saveCacheCom = CacheCom;
	CacheCom |= 0x80;

	if (m_ptr->m_type == DISK_READ)
		PBRead(&w->u.f.pb, TRUE);
	else
		PBWrite(&w->u.f.pb, TRUE);

	/* Reset caching */
	CacheCom = saveCacheCom;

	receive(HARDWARE, &m);
	if (w->u.f.pb.ioResult != 0 || pbio->ioActCount != m_ptr->COUNT)
		return EIO;
	return(pbio->ioActCount);
  } else {			/* SCSI Partition */
	/* Check for eom (end of medium) */
	if ((m_ptr->POSITION / BLOCK_SIZE) > w->u.s.nblocks) return(0);
	if (((m_ptr->POSITION) % BLOCK_SIZE) != 0) return (EINVAL);
	if ((m_ptr->COUNT) % BLOCK_SIZE != 0) return (EINVAL);
	if (m_ptr->COUNT == 0) return 0;
	/* First and my_count are minix block numbers. */
	first = m_ptr->POSITION / BLOCK_SIZE;
	my_count = m_ptr->COUNT / BLOCK_SIZE;

	/* Here we truncate at the end of the partition */
	if (my_count + first > w->u.s.nblocks) {
		my_count = w->u.s.nblocks - first;
		m_ptr->COUNT = my_count * BLOCK_SIZE;	/* return corrected num */
	}

	/* Transate first and my_count to physical sectors */
	first = (first << w->u.s.sect2block) + w->u.s.first;
	my_count = my_count << w->u.s.sect2block;
	while (1) {
		if (my_count > 256) {	/* Max of 256 phys sectors
					 * per scsi command */
			if (m_ptr->m_type == DISK_READ)
				err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) first, (int) my_count, (char *) user_phys, SCSI_READ);
			else
				err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) first, (int) my_count, (char *) user_phys, SCSI_WRITE);
			if (err) return EIO;
			(char *) user_phys += (long) 256 * (long) w->u.s.sector_sz;
			my_count -= 256;
			first += 256;
		} else {
			if (m_ptr->m_type == DISK_READ)
				err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) first, (int) my_count, (char *) user_phys, SCSI_READ);
			else
				err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) first, (int) my_count, (char *) user_phys, SCSI_WRITE );
			if (err) return EIO;
			return (int) m_ptr->COUNT;	/* Bytes read/written */
		}
	}
  }

}

/*===========================================================================*
 *				w_close_all				     *
 *===========================================================================*/
PUBLIC void w_close_all()
{
  register int i;
  register struct wini *w;

  for (i = 0, w = &wini[0]; i < NR_DEVICES; i++, w++) {
	if (w->type == FILE_DISK) {
		w->u.f.pb.ioCompletion = 0L;
		w->u.f.pb.ParamBlkType.ioParam.ioRefNum = w->u.f.fref;
		PBKillIO(&w->u.f.pb, 0);
		PBClose(&w->u.f.pb, 0);
		w->u.f.fref = 0;
	}
  	w->type = NO_DISK;
  }
}


/*===========================================================================*
 *				w_do_ioctl				     *
 *===========================================================================*/
PRIVATE int w_do_ioctl(m_ptr)
message *m_ptr;			/* pointer to read or write w_message */
{
  int device = m_ptr->TTY_LINE;
  int request = m_ptr->TTY_REQUEST;
  int len, err;
  register struct wini *w;
  phys_bytes nme;
  char *n, *dst, *sn;

  if (device < 0 || device >= NR_DEVICES) return(EINVAL);
  w = &wini[device];

  switch (request) {
      case HD_OPEN:
	/* This is the OLD way -- will go away. The PBOpen command
	 * has been taken out of the users hands. */
	/* Code is now commented out (SCSI patch) */
	/* If (w->u.f.fref != 0) return(EIO); w->u.f.fref =
	 * m_ptr->TTY_FLAGS; w_blocks(f); strcpy(w->u.f.name,
	 * "UNKNOWN"); */
	return EINVAL;
	break;
      case HD_CLOSE:
	if (w->type == FILE_DISK) {
		w->u.f.pb.ioCompletion = 0L;
		w->u.f.pb.ParamBlkType.ioParam.ioRefNum = w->u.f.fref;
		if (PBClose(&w->u.f.pb, 0) != 0) return(EIO);
		w->u.f.fref = 0;
		w->type = NO_DISK;
	} else if (w->type == SCSI_DISK) {	/* SCSI_DISK */
		w->type = NO_DISK;
	} else
		return(EPERM);	/* Not open */
	break;
      case HD_NOPEN:
	if (w->type != NO_DISK) return(EPERM);
	nme = umap(proc_addr(m_ptr->PROC_NR), D,
	   (vir_bytes) m_ptr->TTY_FLAGS, (vir_bytes) sizeof(fname));
	if (nme == 0) return(EFAULT);
	phys_copy(nme, fname, (long) sizeof(fname));
	dst = w_open(w, fname);	/* handles both SCSI and FILE disks */
	if (dst != (char *) NULL) {
		strcpy(nme, dst);
		return(EIO);
	}
	break;
      case HD_GETFILE:
	/* Get file name */
	if (w->type == NO_DISK) return(EIO);
	if (w->type == FILE_DISK) {
		if (w->u.f.name[0] != ':' && index(w->u.f.name, ':'))
			n = w->u.f.name;	/* already full name */
		else {
			nbuf[0] = strlen(w->u.f.name);
			dst = &nbuf[1];
			sn = w->u.f.name;
			while (*sn) {
				*dst++ = *sn++;
			}
			n = fullname(0, nbuf);
		}
	} else			/* SCSI DISK */
		n = w->u.s.name;
	len = strlen(n);
	nme = umap(proc_addr(m_ptr->PROC_NR), D,
		   (vir_bytes) m_ptr->TTY_FLAGS, (vir_bytes) len);
	if (nme == 0) return(EIO);
	phys_copy(n, nme, (long) len);
	break;
      default:	return(EIO);
}
  return OK;
}


/*===========================================================================*
 *				w_open					     *
 *===========================================================================*/
PRIVATE char *w_open(w, name)
register struct wini *w;
char *name;
{
  int cnt = 0, err = -1;
  int flag;
  int stat, msg;
  char *dst = &nbuf[1];
  char *sn;
  struct partition *part;
  struct block0 *b0;
  static char *errmsgs[] = {
	  "Error getting SCSI Bus",	/* 0 */
	  "Error selecting ID--no device at ID",	/* 1 */
	  "Error sending SCSI Inquiry",	/* 2 */
	  "Error reading SCSI data",	/* 3 */
	  "Error in SCSIComplete",	/* 4 */
	  "Illegal SCSI Device type",	/* 5 */
	  "Illegal SCSI block size",	/* 6 */
	  "Bad block0 sig",	/* 7 */
	  "Bad partition table sig",	/* 8 */
	  "SCSI ID invalid",	/* 9 */
	  "No such partition",	/* 10 */
	  "Error reading block 0",	/* 11 */
	  "Error reading number of partitions",	/* 12 */
	  "Error reading partition info",	/* 13 */
	  "General file manip error",	/* 14 */
	  "Unknown error",	/* 15 */
	  "Partition too far in disk",	/* 16 */
	  "Partition already open"	/* 17 */
  };

  /* Determine if this is a SCSI disk open request. */
  /* Format of scsi request: <id>::<partition_name> */
  /* This does not conflict with any mac pathnames since */
  /* It's an absolute path which ends up at a device. */

  if (name[1] == ':' && name[2] == ':') {
	if (name[0] >= '0' && name[0] <= '6') {
		/* Get ID */
		w->u.s.id = (int) (name[0] - '0');
		w->u.s.readonly = 0;
		strncpy(w->u.s.name, &(name[3]), 32);	/* Partition name */

		/* Is partition already open? */
		for( flag = 0; flag < NR_DEVICES; flag++ ) {
			if( wini[flag].type == SCSI_DISK &&
				wini[flag].u.s.id == w->u.s.id &&
				!strncmp( wini[flag].u.s.name, w->u.s.name, 32 ) )
				return errmsgs[17];
		}
		/* Perform inquiry command--is this a disk? */
		flag = 0;
		err = SCSIGet();
		if (err != 0) {
			return errmsgs[0];
		} else {
			err = SCSISelect(w->u.s.id);
			if (err != 0) {
				return errmsgs[1];
			} else {

				cdb[0] = SCSI_INQUIRY;	/* opcode (0x12) */
				cdb[1] = '\0';	/* LUN and reserved */
				cdb[2] = '\0';	/* Reserved */
				cdb[3] = '\0';	/* Reserved */
				cdb[4] = '\05';	/* Transer five bytes */
				cdb[5] = '\0';	/* Reserved, etc. */

				err = SCSICmd(cdb, 6);
				if (err != 0) {
					err = SCSIComplete(&stat, &msg, TIMEOUT);
					return errmsgs[2];
				} else {
					tib[0].scOpcode = scNoInc;
					tib[0].scParam1 = (long) tempbuf;
					tib[0].scParam2 = (long) 5;
					tib[1].scOpcode = scStop;
					tib[1].scParam1 = 0;
					tib[1].scParam2 = 0;

					err = SCSIRead(tib);
					if (err == 0)
						flag = 1;
					else {
						err = SCSIComplete(&stat, &msg, TIMEOUT);
						return errmsgs[3];
					}
				}
				cnt = SCSIComplete(&stat, &msg, TIMEOUT);
				if (err == 0) err = cnt;
				if (err == 0) err = stat;
				if (err) {
					return errmsgs[4];
				}
			}
		}		/* Got through SCSI inquiry! */

		if (flag == 0) {/* Error along the way */
			return errmsgs[15];
		}
		if (tempbuf[1] != '\00' && tempbuf[1] != '\04' && tempbuf[1] != '\05') {
			/* Not a CDROM or HD */
			return errmsgs[5];
		}
		if (tempbuf[1] != '\0')
			w->u.s.readonly = 1;	/* Not HD, but WORM or ROM */

		/* Read block zero */
		err = phys_rw(w->u.s.id, SECT_SIZE, (long) 0, (int) 1, tempbuf, SCSI_READ );
		if (err != 0) {	/* This needs work for sectors <> 512
				 * bytes. */
			return errmsgs[11];
		}
		b0 = (struct block0 *) tempbuf;
		if (b0->sig != BLOCK0_SIG) {
			w->type = NO_DISK;
			return errmsgs[7];
		}
		w->u.s.sector_sz = b0->blksize;
		switch (b0->blksize) {
		    case 1024:	/* Some MO disks */
			w->u.s.sect2block = 0;
			break;
		    case 512:	/* Virtually all hard disks */
			w->u.s.sect2block = 1;
			break;
		    case 256:	/* Some really old hard disks? */
			w->u.s.sect2block = 2;
			break;
		    case 128:	/* Probably no devices */
			w->u.s.sect2block = 3;
			break;
		    default:	/* Probably no devices */
			w->type = NO_DISK;
			return errmsgs[6];
			break;
		}

		/* Get number of partitions */
		err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) 1, (int) 1, tempbuf, SCSI_READ);

		if (err != 0) {
			return errmsgs[12];
		}
		part = (struct partition *) tempbuf;
		if (part->sig != PARTITION_SIG) {
			return errmsgs[8];
		} else {
			cnt = (int) part->mapblkcnt;	/* Assumption: Less than
							 * 32K partitions. */
			w->u.s.first = 0;
			for (flag = 1; flag <= cnt; flag++) {
				err = phys_rw(w->u.s.id, w->u.s.sector_sz, (long) flag, (int) 1, tempbuf, SCSI_READ);
				if (err != 0 || part->sig != PARTITION_SIG) {
					return errmsgs[13];
				}
				if (!strncmp(part->partname, w->u.s.name, 32) &&
				    !strncmp(part->partype, "Minix_FS", 32)) {
					if (((part->pypartstart + part->partblkcnt) & 0xFFE00000) != (long) 0) {
						return errmsgs[16];	/* Minix cannot see all */
									/* of this partition. */
					}
					w->u.s.first = part->pypartstart;
					w->u.s.nblocks = (unsigned) part->partblkcnt >> w->u.s.sect2block;
					w->type = SCSI_DISK;
					if (!(part->partstatus & WRITE_ST))
						w->u.s.readonly = 1;	/* Read-only partition */
					/* No support for write-only
					 * partitions. */
					return(char *) NULL;
				}
			}	/* No such partition found */
			return errmsgs[10];
		}
	} else {		/* e.g. ID not in range of 0..6 */
		return errmsgs[9];
	}

  } else {
	/* Convert filename to pascal syntax */
	sn = name;
	nbuf[0] = strlen(sn);
	while (*sn) {
		*dst++ = *sn++;
	}
	w->u.f.pb.ioCompletion = 0L;
	w->u.f.pb.ioNamePtr = nbuf;
	w->u.f.pb.ioVRefNum = 0;
	w->u.f.pb.ParamBlkType.ioParam.ioVersNum = 0;
	w->u.f.pb.ParamBlkType.ioParam.ioPermssn = fsRdWrPerm;
	w->u.f.pb.ParamBlkType.ioParam.ioMisc = 0;
	err = PBOpen(&w->u.f.pb, 0);
	if (err == 0) {
		w->u.f.fref = w->u.f.pb.ParamBlkType.ioParam.ioRefNum;
		w_blocks(w);
		strcpy(w->u.f.name, name);
		w->type = FILE_DISK;
		return(char *) NULL;
	} else {
		w->type = NO_DISK;
		return errmsgs[14];
	}
  }
  return errmsgs[15];
}


/*===========================================================================*
 *				w_blocks				     *
 *===========================================================================*/
PRIVATE void w_blocks(w)	/* For files only */
register struct wini *w;
{
  w->u.f.pb.ioCompletion = 0L;
  w->u.f.pb.ParamBlkType.ioParam.ioRefNum = w->u.f.fref;
  w->u.f.pb.ParamBlkType.ioParam.ioMisc = 0;
  PBGetEOF(&(w->u.f.pb), 0);
  w->u.f.nblocks = (long) w->u.f.pb.ParamBlkType.ioParam.ioMisc/BLOCK_SIZE;
}


#ifdef THINK_C
char *w_block_buf;
long w_block_buf_size = MAXBLOCKS * BLOCK_SIZE;
extern long Ticks:0x16a;
struct iorequest_s *w_iovec;
long w_iovec_size = sizeof(struct iorequest_s) * NR_BUFS;
#else
static char w_block_buf[MAXBLOCKS * BLOCK_SIZE];
#endif


/*==========================================================================*
 *				w_do_vrdwt				    *
 *==========================================================================*/
PRIVATE int w_do_vrdwt(m_ptr)
message *m_ptr;			/* pointer to read or write message */
{
/* Carry out a scattered read or write request. */

  int base;
  struct wini *wp;
  register char *bbptr;
#ifdef THINK_C
#define iovec w_iovec
#else
  static struct iorequest_s iovec[NR_BUFS];
#endif
  phys_bytes iovec_phys;
  int result, i, num, limit, bytes, requests;
  unsigned nr_requests;
  phys_bytes user_iovec_phys;
  message vmessage;

#ifdef TIMING
  {
	long startall, endall;
	long start, end, prologue = 0, io = 0, epilogue = 0;
	startall = Ticks;
#endif

	/* Fetch i/o vector from caller's space. */
	nr_requests = m_ptr->COUNT;
	if (nr_requests > NR_BUFS)
		panic("FS gave wini driver too big an i/o vector", nr_requests);
	iovec_phys = umap(proc_ptr, D, (vir_bytes) iovec, (vir_bytes) sizeof iovec);
	user_iovec_phys = numap(m_ptr->PROC_NR, (vir_bytes) m_ptr->ADDRESS,
		       (vir_bytes) (nr_requests * sizeof iovec[0]));
	if (user_iovec_phys == 0)
		panic("FS gave wini driver bad i/o vector", NO_NUM);
	phys_copy(user_iovec_phys, iovec_phys,
		  (phys_bytes) nr_requests * sizeof iovec[0]);

	wp = &wini[m_ptr->DEVICE];


	for (base = 0; base < nr_requests; base = limit) {

#ifdef TIMING
		start = Ticks;
#endif
		/* Handle all requests adjacent to base request. */
		bytes = iovec[base].io_nbytes;
		requests = 1;

		/* Find the adjacent requests and coalesce */
		for (limit = base + 1; limit < nr_requests; limit++) {
			if (iovec[limit].io_request == iovec[limit - 1].io_request
			    && iovec[limit].io_position == iovec[limit - 1].io_position + iovec[limit - 1].io_nbytes
			    && bytes + iovec[limit].io_nbytes < BLOCK_SIZE * MAXBLOCKS) {
				requests++;
				bytes += iovec[limit].io_nbytes;
			} else
				break;
		}

		vmessage.m_type = iovec[base].io_request & ~OPTIONAL_IO;
		vmessage.DEVICE = m_ptr->DEVICE;
		vmessage.PROC_NR = m_ptr->PROC_NR;
		vmessage.COUNT = bytes;
		vmessage.POSITION = iovec[base].io_position;
		if (requests == 1)
			vmessage.ADDRESS = iovec[base].io_buf;
		else {
			vmessage.ADDRESS = w_block_buf;
			if (vmessage.m_type == DISK_WRITE) {
				bbptr = w_block_buf;
				for (i = base; i < limit; i++) {
					memcpy(bbptr, iovec[i].io_buf, iovec[i].io_nbytes);
					bbptr += iovec[i].io_nbytes;
				}
			}
		}
#ifdef TIMING
		end = Ticks;
		prologue += (end - start);
#endif

#ifdef TIMING
		start = Ticks;
#endif
		result = w_do_rdwt(&vmessage, MULTI);
#ifdef TIMING
		end = Ticks;
		io += (end - start);
#endif

#ifdef TIMING
		start = Ticks;
#endif
		if (result == 0) break;	/* EOF */
		if (result < 0) {
			iovec[base].io_nbytes = result;
			if (iovec[base].io_request & OPTIONAL_IO)
				break;	/* abort if opt */
			limit = base + 1;
		}
		bbptr = w_block_buf;
		for (i = base; i < limit && result > 0; i++) {
			num = (result > iovec[i].io_nbytes) ? iovec[i].io_nbytes : result;
			result -= num;
			iovec[i].io_nbytes -= num;
			if (vmessage.m_type == DISK_READ && requests > 1) {
				memcpy(iovec[i].io_buf, bbptr, num);
				bbptr += num;
			}
		}
#ifdef TIMING
		end = Ticks;
		epilogue += (end - start);
#endif
	}

	/* Return most results in caller's i/o vector. */
	phys_copy(iovec_phys, user_iovec_phys,
		  (phys_bytes) nr_requests * sizeof iovec[0]);

#ifdef TIMING
	endall = Ticks;
	printf("Time to do %d requests = %D (pro = %D io = %D ep = %D)\n",
	    nr_requests, endall - startall, prologue, io, epilogue);
  }
#endif
  return(OK);
}

/*==========================================================================*
 *				phys_rw
 *==========================================================================*/

int phys_rw(sid, ssize, start, num, buf, op )
int sid;			/* SCSI ID */
int ssize;			/* Sector Size */
long start;			/* Only 21 bits are used! */
int num;			/* 1 to 256 sectors */
char *buf;			/* Transfer to where? */
char op;			/* SCSI_READ or SCSI_WRITE */
{
  long *temp;
  int err2, err1 = 0;
  int stat, msg;

  if (num > 0 && buf != (char *) 0 && num <= 256 &&
		( op == SCSI_READ || op == SCSI_WRITE ) ) {
	/* Set up cdb, tib */

	/* Format of CDB (6 bytes) : */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 0    |          COMMAND CODE         | */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 1    |    LUN    |    SECTOR MSB     | */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 2    |             SECTOR            | */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 3    |          SECTOR LSB           | */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 4    |      SECTORS TO TRANSFER      | */
	/*           +---+---+---+---+---+---+---+---+ */
	/* Byte 5    |  RESERVED, LINK & FLAG BITS   | */
	/*           +---+---+---+---+---+---+---+---+ */

	temp = (long *) &(cdb[0]);
	*temp = start;
	cdb[0] = op;		/* SCSI_READ or SCSI_WRITE */
	cdb[1] &= (char) 0x1F;	/* Force LUN of zero */
	cdb[4] = (num == 256) ? (char) 0 : (char) num;
				/* If zero, transfers 256 sectors */
	cdb[5] = '\0';		/* We don't use link, etc. */

	tib[0].scOpcode = scInc;		/* Transfer data and inc ptr */
	tib[0].scParam1 = (long) buf;		/* Start of buffer ptr */
	tib[0].scParam2 = (long) ssize;		/* Number of bytes (one sector) */

	tib[1].scOpcode = scLoop;		/* Decrement and Branch if > 0 */
	tib[1].scParam1 = (long) -10;		/* Branch to tib[0] */
	tib[1].scParam2 = (long) num;		/* Thing to decrement -- do num sects */

	tib[2].scOpcode = scStop;		/* End of transfer */
	tib[2].scParam1 = (long) 0;		/* Unused */
	tib[2].scParam2 = (long) 0;		/* Unused */

	err1 = SCSIGet();		/* Get SCSI bus */
	if (err1 == 0) {
		err1 = SCSISelect(sid);	/* Select device */
		if (err1 == 0) {
			err1 = SCSICmd(cdb, 6);	/* Send command */
			if (err1 == 0) {
				if( op == SCSI_READ ) 
					/* Read data--blind or otherwise */
#ifdef USE_BLIND_READ
					err1 = SCSIRBlind(tib);
#else
					err1 = SCSIRead(tib);
#endif
				else
					/* Write data--blind or otherwise */
#ifdef USE_BLIND_WRITE
					err1 = SCSIWBlind(tib);
#else
					err1 = SCSIWrite( tib );
#endif
			}
			err2 = SCSIComplete(&stat, &msg, (long) TIMEOUT);
				/* Finish transaction */
		}
	}
	if (err1 == 0) {
		err1 = err2;
		if (err1 == 0) err1 = stat;
	}
	return err1;
  } else
	return -1;
}
