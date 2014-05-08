#include <stdio.h>
#include <signal.h>
#include <mac/Files.h>

/*
 * Directory of mac files.
 *				Joe Pickert
 */

void pvols();
void macdir();
void macread();
void macwrite();
void usage();
void doentry();
void pentry();
void pdir();
char *c2pstr();
char *p2cstr();

int Rflg = 0;
int lflg = 0;
int dflg = 0;
int aflg = 0;
int rflg = 0;
int wflg = 0;

main(argc, argv)
int argc;
char *argv[];
{
  char c;
  extern int optind;

  if (strcmp(argv[0], "macread") == 0) {
    while ((c = getopt(argc, argv, "a")) != EOF)
	  aflg++;
    if (optind != (argc-1))
	usage(argv[0], "-a file");
	rflg++;
  }
  else if (strcmp(argv[0], "macwrite") == 0) {
    while ((c = getopt(argc, argv, "a")) != EOF)
	  aflg++;
    if (optind != (argc-1))
	usage(argv[0], "-a file");
	wflg++;
  }
  else {
    dflg++;
    while ((c = getopt(argc, argv, "darwlR")) != EOF) {
      switch (c) {
        case 'd':
	  break;
        case 'a':
	  aflg++;
	  break;
        case 'r':
	  rflg++;
	  dflg = 0;
	  break;
        case 'w':
	  wflg++;
	  dflg = 0;
	  break;
        case 'l':
	  lflg++;
	  break;
        case 'R':
	  Rflg++;
	  break;
	  	default:
	  usage(argv[0], "-darwlR");
       }
    }
   }
   
   if (dflg && optind == argc)
      pvols();
   else
	  for (; optind < argc; optind++) {
	      if (dflg) macdir(argv[optind], Rflg);
	      else if (wflg) macwrite(argv[optind], aflg);
	      else if (rflg) macread(argv[optind], aflg);
	  }
}

void usage(name, s)
char *name, *s;
{
  fprintf(stderr, "usage %s %s\n", name, s);
  exit(-1);
}

void pvols()
{
  QHdrPtr vq;
  VCB *vcb;
  int j;

  vq = GetVCBQHdr();
  for (vcb = (VCB *)vq->qHead; vcb; vcb=(VCB *)vcb->qLink) {
    for (j = 1; j <= vcb->vcbVN[0]; j++)
      printf("%c", vcb->vcbVN[j]);
    printf(":\n");
  }
}

ParamBlockRec pbr;

void quit(sig)
{
  if (pbr.ParamBlkType.ioParam.ioRefNum != 0)
	PBClose(&pbr, 0);
  exit(sig);
}

void macread(file, ascii)
char *file;
int ascii;
{
  int err;
  register char *c;
  char buf[100];
  long cnt;

  pbr.ParamBlkType.ioParam.ioRefNum = 0;
  signal(SIGTERM, quit);
  signal(SIGINT, quit);
  signal(SIGHUP, quit);
  signal(SIGQUIT, quit);

  pbr.ioCompletion = 0;
  pbr.ioNamePtr = c2pstr(file);
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.ioParam.ioVersNum = 0;
  pbr.ParamBlkType.ioParam.ioPermssn = 1;
  pbr.ParamBlkType.ioParam.ioMisc = 0L;
  if ((err = PBOpen(&pbr, 0)) == 0) {
    pbr.ParamBlkType.ioParam.ioBuffer = buf;
    pbr.ParamBlkType.ioParam.ioReqCount = sizeof(buf);
    pbr.ParamBlkType.ioParam.ioPosMode = 0;
    pbr.ParamBlkType.ioParam.ioPosOffset = 0;
    err = 0;
    while (err == 0) {
	  pbr.ParamBlkType.ioParam.ioActCount = 0;
	  err = PBRead(&pbr, 0);
	  if (ascii) {
	    c = buf;
	    cnt = pbr.ParamBlkType.ioParam.ioActCount;
	    while (cnt--) {
	      if (*c == '\r') *c = '\n';
	      c++;
	    }
	  }
          cnt = pbr.ParamBlkType.ioParam.ioActCount;
	  fwrite(buf, 1, (int)pbr.ParamBlkType.ioParam.ioActCount, stdout);
    }
    if (err != -39)
    	fprintf(stderr, "error reading %s, err = %d\n", p2cstr(file), err);
    PBClose(&pbr,0);
  } else
    fprintf(stderr, "unable to open %s, err = %d\n", p2cstr(file), err);
}

OSType totype(s)
OSType *s;
{
  return *s;
}

static int writebuf(iop, b, len)
ParamBlockRec *iop;
char *b;
int len;
{
  int err;
  
  iop->ParamBlkType.ioParam.ioBuffer = b;
  iop->ParamBlkType.ioParam.ioReqCount = len;
  if ((err = PBWrite(iop, 0)) != 0)
     return err;
  if (iop->ParamBlkType.ioParam.ioActCount != len)
     return -1;
  return 0;
}

void macwrite(file, ascii)
char *file;
int ascii;
{
  int err;
  register char *c;
  char buf[100];
  int cnt, len;

  pbr.ParamBlkType.ioParam.ioRefNum = 0;
  signal(SIGTERM, quit);
  signal(SIGINT, quit);
  signal(SIGHUP, quit);
  signal(SIGQUIT, quit);

  pbr.ioCompletion = 0;
  pbr.ioNamePtr = c2pstr(file);
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.fileParam.ioFVersNum = 0;
  err = PBCreate(&pbr, 0);
  if (err != 0 && err != -48) {
    fprintf(stderr, "Error creating %s, err = %d\n", p2cstr(file), err);
    return;
  }
  pbr.ioCompletion = 0;
  pbr.ioNamePtr = file;
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.fileParam.ioFDirIndex = 0;
  if ((err = PBGetFInfo(&pbr, 0)) != 0) {
    fprintf(stderr, "Error getting info %s, err = %d\n", p2cstr(file), err);
    return;
  }
  if (ascii)
    pbr.ParamBlkType.fileParam.ioFlFndrInfo.fdType = totype("TEXT");
  else
    pbr.ParamBlkType.fileParam.ioFlFndrInfo.fdType = totype("????");
  pbr.ioCompletion = 0;
  pbr.ioNamePtr = file;
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.fileParam.ioFVersNum = 0;
  if ((err = PBSetFInfo(&pbr, 0)) != 0) {
    fprintf(stderr, "Error setting info %s, err = %d\n", p2cstr(file), err);
    return;
  }
  pbr.ioCompletion = 0;
  pbr.ioNamePtr = file;
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.ioParam.ioVersNum = 0;
  pbr.ParamBlkType.ioParam.ioPermssn = 2;
  pbr.ParamBlkType.ioParam.ioMisc = 0L;
  pbr.ParamBlkType.ioParam.ioPosMode = 0;
  pbr.ParamBlkType.ioParam.ioPosOffset = 0;
  if ((err = PBOpen(&pbr, 0)) != 0) {
    fprintf(stderr, "Error opening %s, err = %d\n", p2cstr(file), err);
    return;
  }
  err = 0;
  while (err == 0 && (len = fread(buf, 1, sizeof(buf), stdin)) > 0) {
    if (ascii) {
	c = buf;
	cnt = len;
        while (cnt--) {
          if (*c == '\n') *c = '\r';
          c++;
        }
    }
    err = writebuf(&pbr, buf, len);
  }
  if (err != 0)
    fprintf(stderr, "Error writing %s, err = %d\n", p2cstr(file), err);
  PBClose(&pbr, 0);
}

void
macdir(path)
char *path;
{
  CInfoPBRec dbr;
  ParamBlockRec v;
  int err;

  dbr.ioCompletion = 0;
  dbr.ioNamePtr = c2pstr(path);
  dbr.ioVRefNum = 0;
  dbr.ioFDirIndex = 0;
  dbr.CInfoType.hfileInfo.ioDirID = 0;
  if ((err = PBGetCatInfo(&dbr, 0)) == 0) {
    if (dbr.ioFlAttrib & (1 << 4)) {
      v.ioCompletion = 0;
      v.ioNamePtr = path;
  	  v.ioVRefNum = 0;
  	  v.ParamBlkType.volumeParam.ioVolIndex = -1;
  	  PBGetVInfo(&v, 0);
  	  dbr.ioVRefNum = v.ioVRefNum;
      pdir(&dbr);
    }
    else
      pentry(&dbr, 0);
  } else
    fprintf(stderr, "unable to open %s, err = %d\n", p2cstr(path), err);
}

#define TIMEDIFF 0x7c25b080

long mactounixtime(t)
long t;
{
  return t - TIMEDIFF;
}

void
pentry(pb, sh)
CInfoPBRec *pb;
{
  char *md, *ctime();
  char *type, *creator;
  char *t, *strrchr();
  int i;
  long szd, szr;

  p2cstr(pb->ioNamePtr);
  if (sh) {
    printf("\n\'%s\':\n", pb->ioNamePtr);
    return;
  }
  if (lflg) {
    pb->CInfoType.hfileInfo.ioFlMdDat =
	mactounixtime(pb->CInfoType.hfileInfo.ioFlMdDat);
    md = ctime(&pb->CInfoType.hfileInfo.ioFlMdDat);
    t  = strrchr(md, '\n');
    if (t) *t = 0;
    if (pb->ioFlAttrib & (1 << 4)) {
      t = "drwxrwxrwx";
      type = "    ";
      creator = "    ";
      szd = szr = 0;
    } else {
      t = "-rw-rw-rw-";
      type = (char *)&pb->CInfoType.hfileInfo.ioFlFndrInfo.fdType;
      creator = (char *)&pb->CInfoType.hfileInfo.ioFlFndrInfo.fdCreator;
      szd = pb->CInfoType.hfileInfo.ioFlLgLen;
      szr = pb->CInfoType.hfileInfo.ioFlRLgLen;
    }
    printf("%s %8ld %8ld %c%c%c%c %c%c%c%c %s \'%s\'\n", t, szr, szd,
		creator[0], creator[1], creator[2], creator[3],
		type[0], type[1], type[2], type[3], md, pb->ioNamePtr);
  } else {
    printf("\'%s\'\n", pb->ioNamePtr);
  }
}

void
pdir(pb)
CInfoPBRec *pb;
{
  int i;
  CInfoPBRec p;
  

  for (i = 1; i <= pb->CInfoType.dirInfo.ioDrNmFls; i++) {
    p = *pb;
    p.ioFDirIndex = i;
    if (PBGetCatInfo(&p, 0) == 0)
      if (Rflg && p.ioFlAttrib & (1 << 4)) {
        pentry(&p, 1);
        pdir(&p);
        printf("\n");
      }
      else {
        pentry(&p, 0);
      }
  }
}
