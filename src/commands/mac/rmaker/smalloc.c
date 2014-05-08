char *sbrk();
char *brk();

char *smalloc(size)
unsigned long size;
{
  char *p, *malloc();
  p = sbrk(0);
  if (brk(p+size+sizeof(long)) != (char *)0) {
    fatal("Exhausted mem\n");
  }
  return (p + sizeof(long) - ((long) p % sizeof(long)));
}
