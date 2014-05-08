#include <stdio.h>
#include <mac/Files.h>

char *c2pstr();
char *p2cstr();
void create();

#define BLOCKSIZE 1024

/*
 * Create a  mac file.
 *				Joe Pickert
 */
 
long totype(s)
long *s;
{
  return *s;
}

main(argc, argv)
int argc;
char *argv[];
{
  char c;
  extern int optind;
  extern char *optarg;
  long type = 0, creator = 0;
  long nblocks;

  while ((c = getopt(argc, argv, "c:t:")) != EOF) {
      switch (c) {
        case 'c':
	  strncpy(&creator, optarg, 4);
	  break;
        case 't':
	  strncpy(&type, optarg, 4);
	  break;
       }
  }
  if ((argc - optind) < 2)
      usage(argv[0]);
  if (type == 0) type = totype("MXFS");
  if (creator == 0) creator = totype("MNIX");
  nblocks = atol(argv[optind++]);
  for (; optind < argc; optind++) {
      create(argv[optind], nblocks, type, creator);
  }
}

usage(s)
char *s;
{
  fprintf(stderr, "Usage: %s nblocks filename\n", s);
  exit(1);
}

void
create(file, nblocks, type, creator)
char *file;
long nblocks;
long type, creator;
{
  ParamBlockRec pbr;
  ParamBlockRec iop;
  int err;
  long rsize = nblocks;
  
  rsize *= BLOCKSIZE;

  pbr.ioCompletion = 0;
  pbr.ioNamePtr = c2pstr(file);
  pbr.ioVRefNum = 0;
  pbr.ParamBlkType.fileParam.ioFVersNum = 0;
  err = PBCreate(&pbr, 0);
  if (err == -48)
    fatal("%s already exists\n", file);
  if (err != 0)
    fatal("Error creating %s, err = %d\n", file, err);
  if ((err = PBGetFInfo(&pbr, 0)) != 0)
    fatal("Error getting info %s, err = %d\n", file, err);
  pbr.ParamBlkType.fileParam.ioFlFndrInfo.fdType = type;
  pbr.ParamBlkType.fileParam.ioFlFndrInfo.fdCreator = creator;
  if ((err = PBSetFInfo(&pbr, 0)) != 0)
    fatal("Error setting info %s, err = %d\n", file, err);
  iop.ioCompletion = 0;
  iop.ioNamePtr = file;
  iop.ioVRefNum = 0;
  iop.ParamBlkType.ioParam.ioVersNum = 0;
  iop.ParamBlkType.ioParam.ioPermssn = 2;
  iop.ParamBlkType.ioParam.ioMisc = 0L;
  iop.ParamBlkType.ioParam.ioPosMode = 0;
  iop.ParamBlkType.ioParam.ioPosOffset = 0;
  if ((err = PBOpen(&iop, 0)) != 0)
	    fatal("Error opening %s, err = %d\n", file, err);
  iop.ParamBlkType.ioParam.ioMisc = (Ptr)rsize;
  if ((err = PBSetEOF(&iop, 0)) != 0)
	    fatal("Error allocating %s, err = %d\n", file, err);
  PBClose(&iop, 0);
}

/*VARARGS*/
fatal(s,a,b)
char *s;
char *a;
{
  fprintf(stderr, "maccreate: ");
  p2cstr(a);
  fprintf(stderr, s, a, b);
  fprintf(stderr, "\n");
  exit(1);
}
