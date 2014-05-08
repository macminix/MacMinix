#include <lib.h>
#include <minix/com.h>
#include <sgtty.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

char *c2pstr(), *p2cstr();

main(argc, argv)
int argc;
char **argv;
{
  int fid, fd;

  if (argc != 3) {
    fprintf(stderr, "usage: hdopen macfile /dev/?d?\n");
    exit(1);
  }
  if ((fd = open(argv[2], O_RDONLY)) < 0) {
    perror(argv[2]);
    exit(1);
  }
  if (hdopen(fd, argv[1], 2) < 0)
    exit(1);
  close(fd);
}

static int hdopen(fd, name, request)
int fd;
char *name;
int request;
{
  int n;
  char nbuf[255];
  int *err;

  strncpy(nbuf, name, sizeof(nbuf)-1);

  _M.TTY_LINE = fd;
  _M.TTY_FLAGS = (long) nbuf;	/* sneak name through */
  _M.TTY_REQUEST = request;
  n = callx(FS, IOCTL);
  if (n < 0) {
    extern int errno;
    if (errno == EPERM)
       fprintf(stderr, "mac file already open on device\n");
    else if (errno == EIO) {
       err = (int *)nbuf;
       fprintf(stderr, "error setting file, mac error code %d\n", *err);
    }
    else 
	perror(name);
  }
  return(n);
}
