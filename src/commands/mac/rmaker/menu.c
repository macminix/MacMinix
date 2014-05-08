#include "res.h"

long menu(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
	int iconid, styleid, cmdid, markid;
	char *flagsp;
        int item;
	long tmp, flags;
	register char *cp,*dp,*sp;
	char itext[128];
	static char styles[] = "BIUOS";
        char *lp, *skipsp(), *getline();
	char *datap = data;
	char *index(), *outp(), *outs(), *outl(), *outc();

	datap = outs(datap, (short)rcp->id, &maxl);
	datap = outl(datap, (long)0, &maxl);
	datap = outl(datap, (long)0, &maxl);
	flagsp = datap;
	flags = -1;
	datap = outl(datap, (long)-1, &maxl);
	lp = skipsp(getline());
	datap = outp(datap, lp, &maxl, 0);
	for (item = 1; item < 32; item++) {
	        if ((lp = skipsp(getline())) == 0)
		   break;
		iconid = styleid = cmdid = markid = 0;
		for (cp = lp, dp = itext ; *cp ; cp++) {
			switch (*cp) {
			default:
				*dp++ = *cp;
				break;

			case '(':
				flags &= ~(1<<item);
				break;

			case '^':
				cp++;
				iconid = *cp;
				break;
			
			case '/':
				cp++;
				cmdid = *cp;
				break;

			case '!':
				cp++;
				markid = *cp;
				break;

			case '<':
				cp++;
				sp = index(styles, *cp);
				if (sp == 0)
					fatal("BIUOS expected after <");
				styleid |= (1 << (sp-styles));
				break;
			}
		}
		*dp++ = 0;
		datap = outp(datap, itext, &maxl, 0);
		datap = outc(datap, (char)iconid, &maxl);
		datap = outc(datap, (char)cmdid, &maxl);
		datap = outc(datap, (char)markid, &maxl);
		datap = outc(datap, (char)styleid, &maxl);
	}
	/* end of items */
	datap = outc(datap, (char)0, &maxl);
        tmp = sizeof(long);
	outl(flagsp, flags, &tmp);
	return(datap - data);
}

/*
 *  short number of menus
 *   for each menu: resource id of menu
 */

long mbar(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
        char *lp, *skipsp(), *getline();
	char *cntp, *datap = data;
	char *index(), *outp(), *outs(), *outl(), *outc();
	long tmp;
	int id, cnt = 0;

	cntp =  datap;
        cnt = 0;
	datap = outs(datap, 0, &maxl);
	while ((lp = skipsp(getline())) != 0) {
	  if (sscanf(lp, "%d", &id) != 1)
		fatal("bad resource id");
	  datap = outs(datap, id, &maxl);
	  cnt++;
	}
 	tmp = sizeof(short);
	outs(cntp, cnt, &tmp);
	return(datap - data);
}
