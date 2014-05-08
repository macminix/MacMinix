#include "res.h"

/*
 *	Rect	boundsRect;
 *	short	itemsID;
 *	short	stages;
 */

long alrt(data, maxl, rcp) 
char *data;
long  maxl;
struct res *rcp;
{
	char *lp, *getline();
	int i, s;
	int r1, r2, r3, r4;
	char *datap = data;
	char *outp(), *outs(), *outl(), *outc();

	if ((lp = getline()) == 0
              || sscanf(lp, "%d %d %d %d", &r1, &r2, &r3, &r4) != 4)
		fatal("bad rectangle specification");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
		fatal("bad item id specification");
	if ((lp = getline()) == 0 || sscanf(lp, "%x", &s) != 1)
		fatal("bad stages specification");

	datap = outs(datap, r1, &maxl);
	datap = outs(datap, r2, &maxl);
	datap = outs(datap, r3, &maxl);
	datap = outs(datap, r4, &maxl);
	datap = outs(datap, i, &maxl);
	datap = outs(datap, s, &maxl);
	return (datap - data);
}
