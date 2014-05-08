#include "res.h"

/*
 *  size resource
 */

long size(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
        char *lp, *skipsp(), *getline();
	char *datap = data;
	char *index(), *outp(), *outs(), *outl(), *outc();
	int flags, min, max;
        long mink, maxk;

	if ((lp = getline()) == 0 || sscanf(lp, "%x", &flags) != 1)
	   fatal("bad size flags");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &min) != 1)
	   fatal("bad size min specification");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &max) != 1)
	   fatal("bad size max specification");
        mink = min;
        mink *= 1024L;
        maxk = max;
        maxk *= 1024L;
	datap = outs(datap, (short)flags, &maxl);
	datap = outl(datap, maxk, &maxl);
	datap = outl(datap, mink, &maxl);
	return(datap - data);
}
