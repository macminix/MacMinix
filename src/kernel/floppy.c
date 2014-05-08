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
#include "proc.h"

#define NR_DEVICES     10	/* how many floppys? */
#define FD_EJECT       -1	/* eject code */
#define FD_OPEN		0	/* open code OLD WILL GO AWAY */
#define FD_CLOSE	1	/* close code */
#define FD_NOPEN	2	/* new open code */
#define FD_GETFILE	3	/* new get file name code */
#define MAXBLOCKS      25	/* max blocks to coalesce */
#define SINGLE		0
#define MULTI		1

struct floppy {
  int           fref;
  char		name[256];
  long		nblocks;
  ParamBlockRec pb;
};


PRIVATE char fname[256];
PRIVATE char nbuf[256];
PRIVATE struct floppy floppy[NR_DEVICES];
PRIVATE message f_mess;		/* message buffer for in and out */

FORWARD _PROTOTYPE( int f_do_rdwt, ( message *m_ptr, int type ) );
FORWARD _PROTOTYPE( int f_do_ioctl, ( message *m_ptr ) );
FORWARD _PROTOTYPE( int f_open, ( struct floppy *f , char *name ) );
FORWARD _PROTOTYPE( void f_blocks, ( struct floppy *f ) );
FORWARD _PROTOTYPE( int f_do_vrdwt, ( message *m_ptr ) ); 

/*===========================================================================*
 *				floppy_task				     * 
 *===========================================================================*/
PUBLIC void floppy_task()
{
/* Main program of the floppy disk driver task. */

  struct config conf;
  int r, caller, proc_nr;

  /* if I am the boot device go ahead and open the root file */
  if (BOOT_DEV == DEV_FD0) {
      	setup(&conf, 0, 0);
	override(conf.root);
     	if ((r = f_open(&floppy[0], conf.root)) != 0)
	  panic("Unable to open file for root file system", r);
	if (conf.ram) {
	  extern phys_bytes free_bytes;
	  phys_bytes blks;
	  blks = (free_bytes-code_base)/1024L;
	  /* mm causes really bad things to happen
	     when it detects this condition later.
	     Detect it now instead */
	  if (floppy[0].nblocks > blks)
		panic("Not enough memory for ram disk", NO_NUM);
	}
  }
         
  /* Here is the main loop of the disk task.  It waits for a message, carries
   * it out, and sends a reply.
   */
  while (TRUE) {
	/* First wait for a request to read or write a disk block. */
	receive(ANY, &f_mess);	/* get a request to do some work */
	if (f_mess.m_source < 0) {
		printf("floppy task got message from %d ", f_mess.m_source);
		continue;
	}
	caller = f_mess.m_source;
	proc_nr = f_mess.PROC_NR;

	/* Now carry out the work. */
	switch(f_mess.m_type) {
	    case DISK_READ:
	    case DISK_WRITE:	r = f_do_rdwt(&f_mess, SINGLE);		break;
	    case SCATTERED_IO:	r = f_do_vrdwt(&f_mess); 		break;
	    case DISK_IOCTL:	r = f_do_ioctl(&f_mess);		break;
	    default:		r = EINVAL;				break;
	}

	/* Finally, prepare and send the reply message. */
	f_mess.m_type = TASK_REPLY;	
	f_mess.REP_PROC_NR = proc_nr;

	f_mess.REP_STATUS = r;	/* # of bytes transferred or error code */
	send(caller, &f_mess);	/* send reply to caller */
  }
}

#ifdef THINK_C
extern char CacheCom: 0x39c;
#else
extern char CacheCom;
#endif

/*===========================================================================*
 *				f_do_rdwt				     * 
 *===========================================================================*/
PRIVATE int f_do_rdwt(m_ptr, type)
message *m_ptr;			/* pointer to read or write f_message */
int type;			/* SINGLE or MULTI */
{
/* Carry out a read or write request from the disk. */
  int r, device, errors = 0;
  register struct floppy *f;
  IOParam *pbio;
  message m;
  extern void f_int();
  phys_bytes user_phys;
  char saveCacheCom;
  
  /* Decode the f_message parameters. */
  device = m_ptr->DEVICE;
  if (device < 0 || device >= NR_DEVICES)
	return(EIO);
  if (type == SINGLE) {
     if (m_ptr->COUNT != BLOCK_SIZE && m_ptr->PROC_NR != HARDWARE)
	return(EINVAL);
     if (m_ptr->POSITION % BLOCK_SIZE != 0)
	return(EINVAL);

     /* Determine address where data is to go or to come from. */
     user_phys = numap(m_ptr->PROC_NR, (vir_bytes) m_ptr->ADDRESS,
		    (vir_bytes) m_ptr->COUNT);
     if (user_phys == 0) return(E_BAD_ADDR);
  }
  else {
     /* Determine address where data is to go or to come from. */
     user_phys = (phys_bytes)m_ptr->ADDRESS;
     if (user_phys == 0) return(E_BAD_ADDR);
  }
  f = &floppy[device];
  /* check for eof */
  if ((m_ptr->POSITION / BLOCK_SIZE) > f->nblocks)
	return(0);
  pbio = &f->pb.ParamBlkType.ioParam;
  f->pb.ioCompletion = (ProcPtr)f_int;
  pbio->ioRefNum = f->fref;
  pbio->ioActCount = 0;
  pbio->ioBuffer = (char *)user_phys;
  pbio->ioReqCount = m_ptr->COUNT;
  pbio->ioPosMode = fsFromStart;
  pbio->ioPosOffset = m_ptr->POSITION;
#ifdef THINK_C
  pbio->ioMisc = (char *)geta5();
#endif

  /* Disable Mac OS caching -- MINIX has its own cache (Tech Note #81) */
  saveCacheCom = CacheCom;
  CacheCom |= 0x80;
  
  if (m_ptr->m_type == DISK_READ)
       PBRead(&f->pb, TRUE);
  else
       PBWrite(&f->pb, TRUE);

  /* reset caching */   
  CacheCom = saveCacheCom;
  
  receive(HARDWARE, &m);
  if (f->pb.ioResult != 0 || pbio->ioActCount != m_ptr->COUNT)
    return EIO;
  return(pbio->ioActCount);
}


/*===========================================================================*
 *				f_close_all				     * 
 *===========================================================================*/
PUBLIC void f_close_all()
{
  register int i;
  register struct floppy *f;
  
  for (i = 0, f = &floppy[0]; i < NR_DEVICES; i++, f++)
    if (f->fref != 0) {
  	f->pb.ioCompletion = 0L;
  	f->pb.ParamBlkType.ioParam.ioRefNum = f->fref;
  	PBKillIO(&f->pb, 0);
   	PBClose(&f->pb, 0);
  	f->fref = 0;
    }
}


/*===========================================================================*
 *				f_do_ioctl				     * 
 *===========================================================================*/
PRIVATE int f_do_ioctl(m_ptr)
message *m_ptr;			/* pointer to read or write f_message */
{
  int device = m_ptr->TTY_LINE;
  int request = m_ptr->TTY_REQUEST;
  int len, err;
  register struct floppy *f;
  phys_bytes nme;
  char *n, *dst, *sn;
  
  if (device < 0 || device >= NR_DEVICES)
	return(EIO);
  f = &floppy[device];
  	
  switch (request) {
  	case FD_EJECT:
		f->pb.ioCompletion = 0L;
		f->pb.ioVRefNum = device+1;
		f->pb.ioNamePtr = 0L;
		PBOffLine(&f->pb);
		if ((err = PBEject(&f->pb, 0)) != 0) {
		   printf("eject error code %d\n", err);
		   return(EIO);
		}
		break;
  	case FD_OPEN:	
		/* This is the OLD way -- will go away.
		   The PBOpen command has been taken out of the
		   users hands. */
		if (f->fref != 0)
		   return(EIO);
		f->fref = m_ptr->TTY_FLAGS;
		f_blocks(f);
		strcpy(f->name, "UNKNOWN");
		break;
  	case FD_CLOSE:  
		f->pb.ioCompletion = 0L;
		f->pb.ParamBlkType.ioParam.ioRefNum = f->fref;
		if (PBClose(&f->pb, 0) != 0)
		   return(EIO);
		f->fref = 0;
		break;
  	case FD_NOPEN:	
		if (f->fref != 0)
		   return(EPERM);
		nme = umap(proc_addr(m_ptr->PROC_NR), D, 
			(vir_bytes)m_ptr->TTY_FLAGS, (vir_bytes)sizeof(fname));
		if (nme == 0)
		   return(EFAULT);
		phys_copy(nme, fname, (long) sizeof(fname));
     		err =  f_open(f, fname);
		if (err != 0) {
		   phys_copy(&err, nme, (long) sizeof(err));
		   return(EIO);
		}
		break;
	case FD_GETFILE:
		/* get file name */
		if (f->fref == 0)
		   return(EIO);
		if (f->name[0] != ':' && index(f->name, ':')) 
			n = f->name; /* already full name */
		else {
  			nbuf[0] = strlen(f->name);
			dst = &nbuf[1];
			sn = f->name;
  			while (*sn) {
    		   	  *dst++ = *sn++;
			}
			n = fullname(0, nbuf);
  		}
		len = strlen(n);
		nme = umap(proc_addr(m_ptr->PROC_NR), D, 
			(vir_bytes)m_ptr->TTY_FLAGS, (vir_bytes)len);
		if (nme == 0)
		   return(EIO);
		phys_copy(n, nme, (long) len);
		break;
	default:
		return(EIO);
  }
  return OK;
}


/*===========================================================================*
 *				f_open					     * 
 *===========================================================================*/
PRIVATE int f_open(f, name)
register struct floppy *f;
char *name;
{
  int cnt = 0, err = 0;
  char *dst = &nbuf[1];
  char *sn;

  sn = name;
  nbuf[0] = strlen(sn);
  while (*sn) {
    *dst++ = *sn++;
  }
  f->pb.ioCompletion = 0L;
  f->pb.ioNamePtr = nbuf;
  f->pb.ioVRefNum = 0;
  f->pb.ParamBlkType.ioParam.ioVersNum = 0;
  f->pb.ParamBlkType.ioParam.ioPermssn = fsRdWrPerm;
  f->pb.ParamBlkType.ioParam.ioMisc = 0;
  err = PBOpen(&f->pb, 0);
  if (err == 0) {
  	f->fref = f->pb.ParamBlkType.ioParam.ioRefNum;
  	f_blocks(f);
	strcpy(f->name, name);
  }
  return (err);
}


/*===========================================================================*
 *				f_blocks				     * 
 *===========================================================================*/
PRIVATE void f_blocks(f)
register struct floppy *f;
{
  f->pb.ioCompletion = 0L;
  f->pb.ParamBlkType.ioParam.ioRefNum = f->fref;
  f->pb.ParamBlkType.ioParam.ioMisc = 0;
  PBGetEOF(&f->pb, 0);
  f->nblocks = (long)f->pb.ParamBlkType.ioParam.ioMisc/BLOCK_SIZE;
}


#ifdef THINK_C
char *f_block_buf;
long f_block_buf_size = MAXBLOCKS * BLOCK_SIZE;
extern long Ticks:0x16a;
struct iorequest_s *f_iovec;
long f_iovec_size =  sizeof(struct iorequest_s) * NR_BUFS;
#else
static char f_block_buf[MAXBLOCKS * BLOCK_SIZE];
#endif


/*==========================================================================*
 *				f_do_vrdwt				    *
 *==========================================================================*/
PRIVATE int f_do_vrdwt(m_ptr)
message *m_ptr;			/* pointer to read or write message */
{
/* Carry out a scattered read or write request. */

  int base;
  struct floppy *fp;
  register char *bbptr;
#ifdef THINK_C
#define iovec f_iovec
#else
  static struct iorequest_s iovec[NR_BUFS];
#endif
  phys_bytes iovec_phys;
  int result, i, num,  limit, bytes, requests;
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
	panic("FS gave floppy driver too big an i/o vector", nr_requests);
  iovec_phys = umap(proc_ptr, D, (vir_bytes) iovec, (vir_bytes) sizeof iovec);
  user_iovec_phys = numap(m_ptr->PROC_NR, (vir_bytes) m_ptr->ADDRESS,
			  (vir_bytes) (nr_requests * sizeof iovec[0]));
  if (user_iovec_phys == 0)
	panic("FS gave floppy driver bad i/o vector", NO_NUM);
  phys_copy(user_iovec_phys, iovec_phys,
	    (phys_bytes) nr_requests * sizeof iovec[0]);

  fp = &floppy[m_ptr->DEVICE];

  
  for (base = 0; base < nr_requests; base = limit) {

#ifdef TIMING  
  	start = Ticks;
#endif
	/* Handle all requests adjacent to base request. */
	bytes = iovec[base].io_nbytes;
	requests = 1;
	
	/* Find the adjacent requests and coalesce */
	for (limit = base+1; limit < nr_requests; limit++) {
		if (iovec[limit].io_request == iovec[limit-1].io_request
		 && iovec[limit].io_position == iovec[limit-1].io_position+iovec[limit-1].io_nbytes
		 && bytes + iovec[limit].io_nbytes < BLOCK_SIZE * MAXBLOCKS) {
			requests++;
			bytes += iovec[limit].io_nbytes;
		}
		else
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
	   	vmessage.ADDRESS = f_block_buf;
	   	if (vmessage.m_type == DISK_WRITE) {
	   		bbptr = f_block_buf;
			for (i = base; i < limit; i++) {
	   	  		memcpy(bbptr, iovec[i].io_buf, iovec[i].io_nbytes);
	   	  		bbptr += iovec[i].io_nbytes;
	   		}
	   	}
	}
#ifdef TIMING  
  	end = Ticks;
  	prologue += (end-start);
#endif
		
#ifdef TIMING  
  	start = Ticks;
#endif
	result = f_do_rdwt(&vmessage, MULTI);
#ifdef TIMING  
  	end = Ticks;
  	io += (end-start);
#endif
	
#ifdef TIMING  
  	start = Ticks;
#endif
	if (result == 0) break;				   	/* EOF */
	if (result < 0) {
		iovec[base].io_nbytes = result;
		if (iovec[base].io_request & OPTIONAL_IO) break;/* abort if opt */
		limit = base + 1;
	}
	bbptr = f_block_buf;
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
  	epilogue += (end-start);
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

