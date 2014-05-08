#include "res.h"
/*
 * Handle string format data.
 */
long str(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
        char *lp, *getline();
	char *datap = data;
	char *outp(), *outs(), *outl(), *outc();

	if ((lp = getline()) == 0)
		fatal("missing string");
	datap = outp(datap, lp, &maxl, 1);
	return (datap - data);
}
