#define MAXSTRINGS 7

static unsigned char strbuf[MAXSTRINGS][256];
static int           strnext = 0;

void _cstringclear()
{
   strnext = 0;
}

void _cstringtopstring(s)
unsigned char **s;
{
   register unsigned char *p, *q;
   int len = 0;

   while (strnext >= MAXSTRINGS)
     /* loop forever, should NEVER happen */;

   p = *s;
   q = &strbuf[strnext][1];
   while (*p && len < 256) {
     *q++ = *p++;
     len++;
   }
   strbuf[strnext][0] = len;
   *s = &strbuf[strnext][0];
   strnext++;
}

void _pstringtocstring(s)
unsigned char **s;
{
   char *p2cstr();
   *s = (unsigned char *)p2cstr(*s);
}

/*
 * Convert a 4 character string into a ResType.
 */
void _charpointertorestype(s)
char **s;
{
  int i;
  unsigned long l = 0;
  char *q;
  long lv, sv;

  for (q = *s, i = 0; i < 4; i++) {
    lv = q[i];
    sv = (3-i)*8;
    lv = lv << sv;
    l |= lv;
  }
  *(unsigned long *)s = l;
}

char *p2cstr(s)
char *s;
{
  long len = s[0];
  register char *p, *q;
  p = &s[0];
  q = &s[1];
  while (len--) {
    *p++ = *q++;
  }
  *p = 0;
  return s;
}

char *c2pstr(s)
char *s;
{
  long len = strlen(s);
  register char *p, *q;
  int cnt;

  p = &s[len];
  q = &s[len-1];
  cnt = len;
  while (cnt--) {
    *p-- = *q--;
  }
  s[0] = (char)len;
  return s;
}
