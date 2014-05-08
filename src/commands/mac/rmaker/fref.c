#include "res.h"
/*
 *	long	ftype;
 *	short	iconid;
 *	Str255  filename;
 */

long fref(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
	char *skipsp(), *getline(), *lp;
	char *outp(), *outs(), *outl(), *outc();
        char *datap = data;
	int iconid;

	if ((lp = skipsp(getline())) == 0)
		fatal("no type specified");
	checktype(lp);
        datap = outc(datap, lp[0], &maxl);
        datap = outc(datap, lp[1], &maxl);
        datap = outc(datap, lp[2], &maxl);
        datap = outc(datap, lp[3], &maxl);
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &iconid) != 1)
		fatal("bad icon id");
	datap = outs(datap, iconid, &maxl);
	datap = outc(datap, (char)0, &maxl);
	return (datap - data);
}
