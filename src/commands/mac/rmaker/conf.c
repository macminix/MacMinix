#include "res.h"
#include "setup.h"		/* usr/include/minix? */

/*
 *  conf resource
 */

long conf(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
        char *p, *lp, *skipsp(), *getline();
	char *datap = data;
	char *outp(), *outs(), *outl(), *outc();
	struct config conf;
	int i;

	strncpy(conf.root, skipsp(getline()), sizeof(conf.root));
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &conf.heap) != 1)
	   fatal("bad conf heapsize");
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf keymap specification");
	conf.keymap = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf ram specification");
	conf.ram = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf porta specification");
	conf.porta = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf portb specification");
	conf.portb = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf mapopt specification");
	conf.mapopt = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf maptoescape specification");
	conf.maptoescape = i;
	if ((lp = getline()) == 0 || sscanf(lp, "%d", &i) != 1)
	   fatal("bad conf macmdopt specification");
	conf.mapcmdopt = i;
        for (p = (char *)&conf, i = 0; i < sizeof(conf); i++)
		datap = outc(datap, *p++, &maxl);
	return(datap - data);
}
