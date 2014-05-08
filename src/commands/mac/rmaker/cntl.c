#include "res.h"
/*
 *	Rect	boundsRect;
 *	short	value;
 *	char	visible;
 *	char	filler1;
 *	short	max;
 *	short	min;
 *	short	procID;
 *	long	refCon;
 *	Str255	title;
 */

long cntl(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
	int vis,min,max,pid;
	int val,r1,r2,r3,r4;
	long ref;
	char title[128];
	char *skipsp(), *getline(), *lp;
	char *outp(), *outs(), *outl(), *outc();
        char *datap = data;
	char *strcpy();

	lp = skipsp(getline());
	strcpy(title,lp);
	if ((lp = getline()) == 0
	     || sscanf(lp, "%d %d %d %d", &r1, &r2, &r3, &r4) != 4)
		fatal("bad rectangle");
	lp = skipsp(getline());
	vis = (*lp == 'V' || *lp == 'v' ? 1 : 0);
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &pid) != 1)
		fatal("bad proc id");
	if ((lp = getline()) == 0 || sscanf(lp, "%ld", &ref) != 1)
		fatal("bad refcon");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &val) != 1)
		fatal("bad value");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &min) != 1)
		fatal("bad min");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &max) != 1)
		fatal("bad max");

	datap = outs(datap, r1, &maxl);
	datap = outs(datap, r2, &maxl);
	datap = outs(datap, r3, &maxl);
	datap = outs(datap, r4, &maxl);
	datap = outs(datap, val, &maxl);
	datap = outc(datap, (char)vis, &maxl);
	datap = outc(datap, (char)0, &maxl);
	datap = outs(datap, max, &maxl);
	datap = outs(datap, min, &maxl);
	datap = outs(datap, pid, &maxl);
	datap = outl(datap, (long)ref, &maxl);
	datap = outp(datap, title, &maxl, 1);
	return (datap - data);
}
