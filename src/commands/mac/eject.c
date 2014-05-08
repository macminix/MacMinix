#include <lib.h>
#include <minix/com.h>
#include <sgtty.h>
#include <stdio.h>
#include <fcntl.h>

#define EJECT	-1

main(argc, argv)
int argc;
char **argv;
{
  char *index();
  char *floppy = "/dev/fd   ";
  char *p;
  char *fx = "0";
  int fd;

  if (argc > 2) {
    fprintf(stderr, "usage: eject drive\n");
    exit(1);
  }
  if (argc == 2)
    fx = argv[1];

  p = index(floppy, ' ');
  strncpy(p, fx, strlen(p));
  if ((fd = open(floppy, O_RDONLY)) < 0) {
    perror(floppy);
    exit(1);
  }
  if (eject(fd, EJECT) < 0) {
    perror(floppy);
    exit(1);
  }
  close(fd);
}

static int eject(fd, request)
int fd;
int request;
{
  int n;

  _M.TTY_LINE = fd;
  _M.TTY_REQUEST = request;
  n = callx(FS, IOCTL);
  return(n);
}
