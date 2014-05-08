#include "res.h"

/*
 * type
 * resource id
 * number of bundles
 *  type localid resid
 *  type localid resid
 *  ...
 */

long bndl(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
	char *rcntp, *skipsp(), *getline(), *lp;
	char *outp(), *outs(), *outl(), *outc();
        char *datap = data;
	int j, m1, m2, rcnt, bcnt, resid;
	long tmp;
        char *map, *index();

	if ((lp = skipsp(getline())) == 0)
		fatal("no type specified");
	checktype(lp);
        datap = outc(datap, lp[0], &maxl);
        datap = outc(datap, lp[1], &maxl);
        datap = outc(datap, lp[2], &maxl);
        datap = outc(datap, lp[3], &maxl);
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &resid) != 1)
		fatal("bad res id");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &bcnt) != 1)
		fatal("bad res id");
	datap = outs(datap, resid, &maxl);
        datap = outs(datap, bcnt-1, &maxl);
        for (j = 0; j < bcnt; j++) {
          if ((lp = skipsp(getline())) == 0)
	    fatal("missing bundle resource def");
	  map = index(lp, ' ');
	  if (map)
	    *map++ = 0;
	  checktype(lp);
          datap = outc(datap, lp[0], &maxl);
          datap = outc(datap, lp[1], &maxl);
          datap = outc(datap, lp[2], &maxl);
          datap = outc(datap, lp[3], &maxl);
	  rcntp = datap;
	  rcnt  = 0;
	  datap = outs(datap, 0, &maxl);
	  while (map && sscanf(map, "%d %d", &m1, &m2) == 2) {
            rcnt++;
	    datap = outs(datap, m1, &maxl);
	    datap = outs(datap, m2, &maxl);
	    if (map = index(map, ';'))
	      map++;
          }
          tmp = sizeof(short);
          outs(rcntp, rcnt-1, &tmp);
        }
	return (datap - data);
}
