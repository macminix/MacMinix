/*
 * Compile data
 */

char *outc(p, c, maxl)
char *p;
char c;
long *maxl;
{
  if (*maxl < sizeof(char))
    fatal("out of space to store resource");
  *maxl = *maxl - sizeof(char);
  *p++ = c;
  return p;
}

char *outs(p, s, maxl)
char *p;
short s;
long *maxl;
{
  short *q = (short *)p;
  if (*maxl < sizeof(short))
    fatal("out of space to store resource");
  *maxl = *maxl - sizeof(short);
  *q++ = s;
  return (char *)q;
}

char *outl(p, l, maxl)
char *p;
long l;
long *maxl;
{
  long *q = (long *)p;
  if (*maxl < sizeof(long))
    fatal("out of space to store resource");
  *maxl = *maxl - sizeof(long);
  *q++ = l;
  return (char *)q;
}

char *outp(data, sp, maxl, round)
char *data;
long *maxl;
char *sp;
int round;
{
  char *datap = data;

  datap = outc(datap, (char)strlen(sp), maxl);
  while (*sp)
	datap = outc(datap, *sp++, maxl);
  if (round && ((datap-data) & 1))
	datap = outc(datap, 0, maxl);
  return (datap);
}
