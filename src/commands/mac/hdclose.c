#include <lib.h>
#include <minix/com.h>
#include <sgtty.h>
#include <stdio.h>
#include <fcntl.h>

main(argc, argv)
int argc;
char **argv;
{
  int fd;

  if (argc != 2) {
    fprintf(stderr, "usage: hdclose /dev/hd?\n");
    exit(1);
  }
  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    perror(argv[1]);
    exit(1);
  }
  if (hdclose(fd, 1) < 0) {
    perror(argv[1]);
    exit(1);
  }
  close(fd);
}

static int hdclose(fd, request)
int fd;
int request;
{
  int n;

  _M.TTY_LINE = fd;
  _M.TTY_REQUEST = request;
  n = callx(FS, IOCTL);
  return(n);
}
