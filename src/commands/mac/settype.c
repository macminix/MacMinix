#include <stdio.h>
#include <mac/Files.h>

char *c2pstr();
char *p2cstr();

/*
 * Set Type and/or Creator flags of mac files.
 *				Joe Pickert
 */

void settype();

main(argc, argv)
int argc;
char *argv[];
{
  char c;
  extern int optind;
  extern char *optarg;
  long type = 0, creator = 0;

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
  for (; optind < argc; optind++) {
      settype(argv[optind], type, creator);
  }
}

void
settype(path, type, creator)
char *path;
long type, creator;
{
  CInfoPBRec pbr;
  int err;
  char *t, *c;

  pbr.ioCompletion = 0;
  pbr.ioNamePtr = c2pstr(path);
  pbr.ioVRefNum = 0;
  pbr.ioFVersNum = 0;
  pbr.ioFDirIndex = 0;
  if ((err = PBGetFInfo(&pbr, 0)) == 0) {
    if (type == 0 && creator == 0) {
      c = (char *)&pbr.CInfoType.hfileInfo.ioFlFndrInfo.fdCreator;
      t = (char *)&pbr.CInfoType.hfileInfo.ioFlFndrInfo.fdType;
      printf("%s: Creator = %c%c%c%c Type = %c%c%c%c\n",
	p2cstr(path), c[0], c[1], c[2], c[3], t[0], t[1], t[2], t[3]);
    }
    else {
      if (creator) pbr.CInfoType.hfileInfo.ioFlFndrInfo.fdCreator = creator;
      if (type) pbr.CInfoType.hfileInfo.ioFlFndrInfo.fdType = type;
      pbr.ioCompletion = 0;
      pbr.ioNamePtr = path;
      pbr.ioVRefNum = 0;
      pbr.ioFVersNum = 0;
      pbr.ioFDirIndex = 0;
      if ((err = PBSetFInfo(&pbr, 0)) != 0)
        fprintf(stderr, "unable to set info on %s, err = %d\n", p2cstr(path), err);
    }
  } else
    fprintf(stderr, "unable to get info %s, err = %d\n", p2cstr(path), err);
}
