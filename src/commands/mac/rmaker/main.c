#include <stdio.h>
#include <signal.h>
#include "res.h"

#define MAXRES		200

static struct res resources[MAXRES];
FILE *fin;
static int fout = 0;
static char *oname;
void myclose();

void quit(n)
{
  /* make sure the res file gets closed */
  signal(SIGQUIT, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  if (fout != 0) {
  	printf("CAUTION: output file %s is not usable...trying to remove...", oname);
	myclose(fout);
	if (mydelete(oname) == 0)
	  printf("gone");
	else
	  printf("BUT I CAN'T");
	printf("\n");
  }
  exit(n);
}

main(argc, argv)
int  argc;
char **argv;
{
  int i, verbose = 0, rescount = 0, err;
  extern int optind;
  char c;

  while ((c = getopt(argc, argv, "v")) != -1)
    switch (c) {
 	case 'v':  verbose++; break;
	default :  break;
    }

  if ((argc - optind) != 2) {
    fprintf(stderr, "Usage: %s file.r outputfile\n", argv[0]);
    exit(-1);
  }
  if ((fin = fopen(argv[optind], "r")) == NULL) {
      fprintf(stderr, "Unable to open %s\n", argv[optind]);
      exit(-1);
  }
  for (i = 1; i <= _NSIG; i++)
      signal(i, quit);
  oname = argv[optind+1];
  if ((fout = myopen(oname)) < 0)
    return -1;
  if ((rescount = parse(resources, MAXRES)) > 0)
    if ((err = buildrf(fout, resources, rescount, verbose)) != 0) {
      printf("Error %d while making %s\n", err, argv[2]);
      quit(err);
    }
  myclose(fout);
  exit(0);
}
