#include <sys/types.h>
#include <unistd.h>
#include <a.out.h>
#include <stdio.h>
#include <fcntl.h>
#include "res.h"


#define EHPAD(a)	a
#define EMPAD(a)	a
#define ETPAD(a)	a
#define ENPAD(a)	a
#define ERPAD(a)	a
#define EDPAD(a)	(a+112+128)

typedef unsigned long  uulong;
typedef unsigned short uushort;
typedef unsigned char  uuchar;

struct reshdr {
	uulong	hdr_doff;	/* offset to resource data */
	uulong	hdr_moff;	/* offset to resource map */
	uulong	hdr_dlen;	/* length of resource data */
	uulong	hdr_mlen;	/* length of resource map */
};

struct rmaphdr {
	char	rmaphdr_rsrv[22];
	short	rmaphdr_attr;	/* resource file attributes */
	uushort	rmaphdr_toff;	/* offset to type list */
	uushort	rmaphdr_noff;	/* offset to name list */
};

struct typehdr {
	short	thdr_ntypes;	/* number of types - 1 */
};

struct typeinfo {
	char	info_type[4];	/* resource type */
	short	info_nres;	/* number of resources of this type - 1 */
	uushort	info_roff;	/* offset to reference list */
};

struct refinfo {
	short	rinfo_id;	/* resource ID */
	uushort	rinfo_noff;	/* offset to name (from rmaphdr_noff) */
	uulong  rinfo_doff;	/* offset to resource  (UPPER 8 bits are attr)*/
	long	rinfo_handle;
};

static struct reshdr reshdr;
static struct rmaphdr *rmaphdr;
static struct typehdr *typehdr;
static struct typeinfo *typeinfo;
static struct refinfo *refinfo;
static char *resmap;

static int compare(r1, r2)
struct res *r1, *r2;
{
   return strncmp(r1->type, r2->type, 4);
}

static long size(fid)
int fid;
{
  long w, sz;
  w = lseek(fid, 0L, 1);
  sz = lseek(fid, 0L, 2);
  lseek(fid, w, 0);
  return sz;
}

static char *add(p, a, b)
char *p;
long a, b;
{
  long t = (long)p;
  t += a;
  t += b;
  return (char *)t;
}

static int myread(fid, p, sz)
int  fid;
char *p;
long sz;
{
  int cnt;
  while (sz) {
    if (sz < 10000)
	cnt = sz;
    else
	cnt = 10000;
    if (read(fid, p, cnt) != cnt)
      return 0;
    sz -= cnt;
    p  += cnt;
  }
  return 1;
}

#ifdef BUILD_ON_UNIX
int mydelete(fname)
char *fname;
{
  return unlink(fname);
}

int myopen(fname)
char *fname;
{
  int id;

  if ((id = open(fname, O_CREAT|O_TRUNC|O_WRONLY, 0666)) < 0) {
    perror(fname);
    return -1;
  }
  return id;
}

static long myseek(fid, offset, whence)
int fid;
long offset;
int whence;
{
  return lseek(fid, offset, whence);
}

void myclose(fid)
int fid;
{
  close(fid);
}

static int mywrite(fid, p, sz)
int  fid;
char *p;
long sz;
{
  int cnt;
  while (sz) {
    if (sz < 10000)
	cnt = sz;
    else
	cnt = 10000;
    if (write(fid, p, cnt) != cnt) {
      perror("error writing");
      return 0;
    }
    sz -= cnt;
    p  += cnt;
  }
  return 1;
}
#else
#include <mac/Files.h>

char *c2pstr(), *p2cstr();

int mydelete(file)
char *file;
{
  ParamBlockRec iop;
  int err;
  int c;
  char pname[256];
  char *strncpy();

  strncpy(pname, file, sizeof(pname));
  c2pstr(pname);
  iop.ioCompletion = 0;
  iop.ioNamePtr = pname;
  iop.ioVRefNum = 0;
  iop.ParamBlkType.fileParam.ioFVersNum = 0;
  err = PBDelete(&iop, 0);
  return err;
}

int myopen(file)
char *file;
{
  ParamBlockRec iop;
  int err;
  int c;
  char pname[256];
  char *strncpy();

  strncpy(pname, file, sizeof(pname));
  c2pstr(pname);

  iop.ioCompletion = 0;
  iop.ioNamePtr = pname;
  iop.ioVRefNum = 0;
  iop.ParamBlkType.fileParam.ioFVersNum = 0;
  err = PBCreate(&iop, 0);
  if (err == -48) {
    printf("%s already exists, overwrite? ", file);
    c = getchar();
    if (c != EOF && (c == 'y' || c == 'Y')) {
  	iop.ioNamePtr = pname;
        err = PBDelete(&iop, 0);
 	if (err == 0)
        	err = PBCreate(&iop, 0);
    }
    else
    	fatal("%s already exists\n", file);
  }
  if (err != 0)
    fatal("Error creating %s, err = %d\n", file, err);
  iop.ioCompletion = 0;
  iop.ioNamePtr = pname;
  iop.ioVRefNum = 0;
  iop.ParamBlkType.ioParam.ioVersNum = 0;
  iop.ParamBlkType.ioParam.ioPermssn = fsWrPerm;
  iop.ParamBlkType.ioParam.ioMisc = 0L;
  if ((err = PBOpenRF(&iop, 0)) != 0)
    fatal("Error opening resource fork %s, err = %d\n", file, err);
  return iop.ParamBlkType.ioParam.ioRefNum;
}

static long myseek(fid, offset, whence)
int fid;
long offset;
int whence;
{
  ParamBlockRec iop;
  int err;
  long eof;

  iop.ioCompletion = 0;
  iop.ParamBlkType.ioParam.ioRefNum = fid;
  if ((err = PBGetEOF(&iop, 0)) != 0)
    fatal("Error getting eof in file, err = %d\n", err);
  eof = (long)iop.ParamBlkType.ioParam.ioMisc;

  switch (whence) {
    case 0: break;
    case 1: iop.ParamBlkType.ioParam.ioRefNum = fid;
            if ((err = PBGetFPos(&iop, 0)) != 0)
              fatal("Error getting file pos in file, err = %d\n", err);
	    offset += iop.ParamBlkType.ioParam.ioPosOffset;
	    break;
    case 2: offset += eof;
	    break;
  }
  if (offset > eof) { /* extend file */
    iop.ioCompletion = 0;
    iop.ParamBlkType.ioParam.ioRefNum = fid;
    iop.ParamBlkType.ioParam.ioMisc = (Ptr)offset;
    if ((err = PBSetEOF(&iop, 0)) != 0)
      fatal("Error setting eof in file, err = %d\n", err);
  }
  iop.ioCompletion = 0;
  iop.ParamBlkType.ioParam.ioRefNum = fid;
  iop.ParamBlkType.ioParam.ioPosOffset = offset;
  iop.ParamBlkType.ioParam.ioPosMode = fsFromStart;
  if ((err = PBSetFPos(&iop, 0)) != 0)
    fatal("Error seeking in file, err = %d\n", err);
  return 1;
}

void myclose(fid)
int fid;
{
  ParamBlockRec iop;

  iop.ioCompletion = 0;
  iop.ParamBlkType.ioParam.ioRefNum = fid;
  PBClose(&iop, 0);
}

static int mywrite(fid, p, sz)
int  fid;
char *p;
long sz;
{
  ParamBlockRec iop;
  int err;

  iop.ioCompletion = 0;
  iop.ParamBlkType.ioParam.ioRefNum = fid;
  iop.ParamBlkType.ioParam.ioBuffer = p;
  iop.ParamBlkType.ioParam.ioReqCount = sz;
  iop.ParamBlkType.ioParam.ioPosMode = fsFromMark;
  iop.ParamBlkType.ioParam.ioPosOffset = 0;
  if ((err = PBWrite(&iop, 0)) != 0)
    fatal("Error writing resource file, err = %d\n", err);
  return 1;
}
#endif

/*
 * Build a Macintosh executable from the resources described in
 * in the "resources" array.
 */

buildrf(fout, resources, rescount, verbose)
struct res *resources;
int rescount;
int verbose;
{
  int rid, ntypes, i, j;
  char *cname, *nameinfo, curtype[4];
  uushort hdrsize, typeinfosize, refinfosize; 
  uulong attr, doff, namesize, totalmapsize;
  long sizeaout(), copyaout();
  char *strncpy(), *smalloc();

  /*
   * Nothing so far
   */
  reshdr.hdr_doff = 0;
  reshdr.hdr_dlen = 0;
  reshdr.hdr_moff = 0;
  reshdr.hdr_mlen = 0;

  ntypes = 0;
  namesize = 0;
  strncpy(curtype, "\0\0\0\0", 4);
  qsort(resources, rescount, sizeof (struct res), compare);

  for (i = 0; i < rescount; i++) {
    /*
     * Include some data file
     */
    if (resources[i].flags & R_FILE) {
      if (resources[i].flags & R_AOUT) {
        /*
         * Do an a.out.
         */
        resources[i].size = sizeaout(resources[i].file,  resources[i].flags);
        if (resources[i].size < 0)
          return -1;
      } else {
        if ( (rid = open(resources[i].file, O_RDONLY, 0)) < 0
	  || (resources[i].size = size(rid)) < 0
	  || (resources[i].data = smalloc(resources[i].size)) == NULL
	  || myread(rid, resources[i].data, resources[i].size) != 1 ) {
    	  perror(resources[i].file);
          return -1;
        }
        close(rid);
      }
    }
    /*
     * count the number of different types and the amount of
     * room needed for the resource names.
     */
    if (strncmp(curtype, resources[i].type, 4) != 0) {
      ntypes++;
      strncpy(curtype, resources[i].type, 4);
    }
    namesize += strlen(resources[i].name) + 1;
  }
#ifdef DEBUG
  printf("ntypes = %d\n", ntypes);
#endif
  hdrsize      = EHPAD(sizeof (struct rmaphdr));
  typeinfosize = ETPAD(sizeof (struct typehdr)
		  + ntypes * sizeof (struct typeinfo));
  refinfosize  = ERPAD(rescount * sizeof (struct refinfo));
  namesize     = ENPAD(namesize);
  totalmapsize = hdrsize + typeinfosize + refinfosize + namesize;

  resmap = smalloc((long)totalmapsize);
  rmaphdr =  (struct rmaphdr *) resmap;
  rmaphdr -> rmaphdr_attr = mapReadOnly;
  rmaphdr -> rmaphdr_toff = hdrsize;
  rmaphdr -> rmaphdr_noff = hdrsize + typeinfosize + refinfosize;
  typehdr = (struct typehdr *)(resmap + hdrsize);
  typehdr -> thdr_ntypes = ntypes - 1;
  typeinfo= (struct typeinfo *) (resmap + hdrsize + sizeof (struct typehdr));
  refinfo = (struct refinfo *) ((char *)typehdr + typeinfosize);
  nameinfo = (char *)refinfo + refinfosize;
  cname = nameinfo;
  doff = 0;

  for (i = 0, j = 0; i < ntypes; i++) {
    strncpy(typeinfo[i].info_type, resources[j].type, 4);
    typeinfo[i].info_nres = 0;
    typeinfo[i].info_roff = (char *)&refinfo[j] - (char *)typehdr;
    while (strncmp(resources[j].type,typeinfo[i].info_type,4) == 0) {
      if (verbose) {
        printf("Add %s: name = %s, id = %d, attrs = %d, size = %D\n",
	  resources[j].type, resources[j].name, resources[j].id,
	  resources[j].attr, resources[j].size);
      }
      typeinfo[i].info_nres++;
      refinfo[j].rinfo_id = resources[j].id;
      refinfo[j].rinfo_noff = cname - nameinfo;
      attr = resources[j].attr;
      refinfo[j].rinfo_doff = doff | (attr << 24);
      refinfo[j].rinfo_handle = 0;
      *cname = (unsigned char) strlen(resources[j].name);
      strncpy(cname+1,resources[j].name, (int)*cname);
      cname += *cname + 1;
      doff += resources[j].size + sizeof(uulong);
      j++;
    }
    typeinfo[i].info_nres -= 1;		/* one less than true number */
#ifdef DEBUG
    printf("%4s = %d\n", typeinfo[i].info_type, typeinfo[i].info_nres+1);
#endif
  }

  reshdr.hdr_doff = EDPAD(sizeof (struct reshdr));
  reshdr.hdr_dlen = doff;
  reshdr.hdr_moff = EMPAD(reshdr.hdr_doff + reshdr.hdr_dlen);
  reshdr.hdr_mlen = totalmapsize;

  if (mywrite(fout, (char *)&reshdr, (long)sizeof reshdr) != 1)
    return -1;
  if (myseek(fout, reshdr.hdr_doff, 0) < 0)
    return -1;
  for (i = 0; i < rescount; i++) {
    uulong size;
    size = resources[i].size;
    if (resources[i].flags & R_AOUT) {
        if (mywrite(fout, (char *)&size, (long)sizeof(size)) != 1
         || copyaout(&resources[i], fout) != resources[i].size)
        	return -1;
    } else {
        if (mywrite(fout, (char *)&size, (long)sizeof(size)) != 1
	  || mywrite(fout, resources[i].data, resources[i].size) != 1)
        	return -1;
    }
  }
  if (myseek(fout, reshdr.hdr_moff, 0) < 0
   || mywrite(fout, resmap, (long)totalmapsize) != 1) {
    return -1;
  }
  return 0;
}


long sizeaout(name, flags)
char *name;
int  flags;
{
  int aid;
  long totsize;
  long hdr[8];
  long text, data, bss, trsize, drsize;

  if ((aid  = open(name, O_RDONLY, 0)) < 0
   || myread(aid, hdr, (long)sizeof hdr) != 1) {
    perror(name);
    return -1;
  }
  if (flags & R_DCMD)
    totsize = 3*sizeof(short);
  else
    if (flags  & R_NOSG)
      totsize = 0;
    else
      totsize = 2*sizeof(short);
  if (hdr[0] == GNUMAGIC) {		/* gnu a.out */
    text   = hdr[1];
    data   = hdr[2];
    if (flags & R_BSS)
      bss    = hdr[3];
    else
      bss    = 0;
    trsize = hdr[6];
    drsize = hdr[7];
  }
  else if (hdr[0] == ACKMAGIC) {
    if (hdr[1] != sizeof hdr) {
      fprintf(stderr, "%s: wrong ack header size\n", name);
      return -1;
    }
    text   = hdr[2];
    data   = hdr[3];
    if (flags & R_BSS)
      bss    = hdr[4];
    else
      bss    = 0;
    trsize = size(aid) - text - data - hdr[7] - sizeof(hdr);
    drsize = 0;
  }
  else {
    fprintf(stderr, "%s: not gnu or ack a.out\n", name);
    return -1;
  }
  totsize += sizeof hdr + text + data + bss + trsize + drsize;
  close(aid);
  return totsize;
}

static long copybytes(from, to, amount)
int  from, to;
long amount;
{
  char buf[100];
  long cnt;
  long tot = 0;

  while (amount > 0) {
    if (amount < sizeof(buf))
	cnt = amount;
    else
	cnt = sizeof(buf);

    if (myread(from, buf, cnt) != 1)
      return(tot);
    if (mywrite(to, buf, cnt) != 1)
      return(tot);

    amount -= cnt;
    tot += cnt;
  }
  return tot;
}

static long zerobytes(fout, amount)
int  fout;
long amount;
{
  char buf[100];
  long cnt;
  long tot = 0;
  int i;

  for (i = 0; i < sizeof(buf); i++)
    buf[i] = 0;

  while (amount > 0) {
    if (amount < sizeof(buf))
	cnt = amount;
    else
	cnt = sizeof(buf);

    if (mywrite(fout, buf, cnt) != 1)
      return(tot);

    amount -= cnt;
    tot += cnt;
  }
  return tot;
}

long copyaout(r, fout)
struct res *r;
int fout;
{
  long hdr[8];
  short dcmdhdr[3];
  short seghdr[2];
  int aid;
  long tot = 0;
  long text, data, bss, trsize, drsize;

  if ((aid  = open(r->file, O_RDONLY, 0)) < 0
   || myread(aid, hdr, (long)sizeof hdr) != 1) {
    perror(r->file);
    return -1;
  }

  if (hdr[0] == GNUMAGIC) {		/* gnu a.out */
    text   = hdr[1];
    data   = hdr[2];
    bss    = hdr[3];
    trsize = hdr[6];
    drsize = hdr[7];
  }
  else if (hdr[0] == ACKMAGIC) {
    if (hdr[1] != sizeof hdr) {
      fprintf(stderr, "%s: wrong ack header size\n", r->file);
      return -1;
    }
    text   = hdr[2];
    data   = hdr[3];
    bss    = hdr[4];
    trsize = size(aid) - text - data - hdr[7] - sizeof(hdr);
    drsize = 0;
  }
  else {
    fprintf(stderr, "%s: not gnu or ack a.out\n", r->file);
    return -1;
  }

  if (r->flags & R_DCMD) {
    /*
     * 'dcmd' header for macsbug
     */
    dcmdhdr[0] = 1;				/* version number */
    dcmdhdr[1] = 0;				/* a5 global size */
    dcmdhdr[2] = sizeof(struct exec);		/* entry point */
   	
    if (mywrite(fout, (char *)dcmdhdr, (long)sizeof(dcmdhdr)) != 1)
      return -1;
    tot += sizeof(dcmdhdr);
  }
  else 
    if (!(r->flags & R_NOSG)) {
      /*
       * normal segment header for mac os
       */
      seghdr[0] = 0;
      seghdr[1] = 1;
      if (mywrite(fout, (char *)seghdr, (long)sizeof(seghdr)) != 1)
        return -1;
      tot += sizeof(seghdr);
    }

  /*
   * copy the header
   */
  if (mywrite(fout, (char *)hdr, (long)sizeof(hdr)) != 1)
        return -1;
  tot += sizeof(hdr);
  /*
   * copy text and data
   */
  if (copybytes(aid, fout, text+data) != text+data)
    return -1;
  tot += text+data;
  /*
   * bss
   */
  if (r->flags & R_BSS) {
    if (zerobytes(fout, bss) != bss)
      return -1;
    tot += bss;
  }
  /*
   * skip syms
   */
  lseek(aid, hdr[7], 1);
  /*
   * text and data relocation info.
   */
  if (trsize+drsize > 0) {
    if (copybytes(aid, fout, trsize+drsize) != trsize+drsize)
      return -1;
    tot += trsize+drsize;
  }

  close(aid);
  return tot;
}
