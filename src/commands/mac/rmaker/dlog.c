#include "res.h"
/*
 * Handle dialog template (DLOG).
 */

/*
 *
 *	typedef	struct	{
 *		Rect	boundsRect;
 *		short	procID;
 *		char	visible;
 *		char	filler1;
 *		char	goAwayFlag;
 *		char	filler2;
 *		long	refCon;
 *		short	itemsID;
 *		Str255	title;
 *	} DialogTemplate;
 */

long dlog(data, maxl, rcp)
char *data;
long   maxl;
struct res *rcp;
{
	char title[128];
	int vis,goaway,pid;
	long ref;
	int r1, r2, r3, r4;
        int iid;
	char *skipsp(), *getline(), *lp;
	char *datap = data;
	char *outp(), *outs(), *outl(), *outc();
	char *strcpy();

	if ((lp = getline()) == 0
	     || sscanf(lp, "%d %d %d %d", &r1, &r2, &r3, &r4) != 4)
		fatal("bad rectangle");
	lp = skipsp(getline());
	vis = (*lp == 'V' || *lp == 'v' ? 1 : 0);
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &pid) != 1)
		fatal("bad proc id");
	lp = skipsp(getline());
	goaway = (*lp == 'G' || *lp == 'g' ? 1 : 0);
	if ((lp = getline()) == 0 || sscanf(lp, "%ld", &ref) != 1)
		fatal("bad refcon");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &iid) != 1)
		fatal("bad items id");
	strcpy(title, skipsp(getline()));

	datap = outs(datap, r1, &maxl);
	datap = outs(datap, r2, &maxl);
	datap = outs(datap, r3, &maxl);
	datap = outs(datap, r4, &maxl);
	datap = outs(datap, pid, &maxl);
	datap = outc(datap, (char)vis, &maxl);
	datap = outc(datap, (char)0, &maxl);
	datap = outc(datap, (char)goaway, &maxl);
	datap = outc(datap, (char)0, &maxl);
	datap = outl(datap, (long)ref, &maxl);
	datap = outs(datap, iid, &maxl);
	datap = outp(datap, title, &maxl, 1);
	return (datap - data);
}
