#include <lib.h>
#include <minix/com.h>
#include <sgtty.h>
#include <stdio.h>
#include <fcntl.h>

char *c2pstr(), *p2cstr();

main(argc, argv)
int argc;
char **argv;
{
  int fid, fd;
  char *getname(), *n;

  if (argc != 2) {
    fprintf(stderr, "usage: getname  /dev/?d?\n");
    exit(1);
  }
  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    perror(argv[1]);
    exit(1);
  }
  if (( n = getname(fd) ) == (char *)0)
    printf("nothing open on %s\n", argv[1]);
  else
    printf("%s is open on %s\n", n, argv[1]);
  close(fd);
  exit (n == (char *)0 ? 1 : 0);
}

static char *getname(fd)
int fd;
{
  int n;
  static char nbuf[255];

  _M.TTY_LINE = fd;
  _M.TTY_FLAGS = (long) nbuf;	/* sneak name through */
  _M.TTY_REQUEST = 3;
  n = callx(FS, IOCTL);
  if (n < 0)
	return((char *)0);
  else
	return(nbuf);
}
