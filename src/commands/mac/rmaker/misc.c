#include <stdio.h>

static char	line[256];		/* line buffer */
static int	linenum;		/* line number in command file */

/*
 * Get next command line.
 * Returns 0 if end of block, 1 if normal line.
 */

extern int eof;

char *getline()
{
	register i;
	char *lp;
	extern FILE *fin;

again:
	if ((fgets(line, sizeof line, fin)) == NULL) {
		eof = 1;
		return 0;
	}
	linenum++;
	i = strlen(line);
	if (line[i-1] == '\n')
		line[i-1] = 0;
	lp = line;
	if (*lp == 0)
		return 0;
	if (*lp == '*')
		goto again;
	return (lp);
}


/*
 * Abort with message.
 */
/*VARARGS*/
fatal(s,a,b,c,d)
	char *s;
{
	fprintf(stderr, "rmaker: ");
	fprintf(stderr, s, a, b, c, d);
	if (linenum)
		fprintf(stderr, "; line number %d", linenum);
	fprintf(stderr, "\n");
	quit(1);
}

/*
 * Check for legal length type.  Fix "STR ".
 */
checktype(s)
	char *s;
{
	register len;

	len = strlen(s);
	if (len < 3 || len > 4)
		fatal("bad type");
	if (len == 3) {
		s[3] = ' ';
		s[4] = 0;
	}
}

/*
 * Skip spaces.  Return 0 if end of line.
 */
char *skipsp(lp) 
char *lp;
{
	if (lp == 0)
	  return 0;
	while (*lp == ' ' && *lp != 0) 
  		lp++;
        if (*lp)
	  return lp;
	else
	  return 0;
}

bzero(dest, cnt)
register char *dest; 
register long cnt;
{
  	while (cnt--)
	  *dest++ = 0;
}

bcopy(src, dest, cnt)
register char *src; 
register char *dest; 
register long cnt;
{
  	while (cnt--)
	  *dest++ = *src++;
}

char *index(s, c)
register char *s;
char c;
{
   	while (*s) {
	  if (*s == c)
		return s;
	  s++;
	}
	return 0;
}
