#include "res.h"

#include <stdio.h>

#define MAXSIZE 10000L

/* type format handlers */
extern	long str(), hexa(), code();
extern	long dlog(), alrt(), ditl();
extern	long wind(), menu(), cntl();
extern	long bndl(), mbar(), fref();
extern	long size(), conf();

struct	typehand {
	char	*type_type;
	long	(*type_handler)(); 
	int	type_flags;
};

static char data[MAXSIZE];
static struct typehand typehand[] = {
	"STR ",	str,  0,
	"HEXA",	hexa, 0,
	"BNDL",	bndl, 0,
	"FREF",	fref, 0,
	"ALRT", alrt, 0,
	"DITL", ditl, 0,
	"DLOG", dlog, 0,
	"WIND", wind, 0,
	"MENU", menu, 0,
	"MBAR", mbar, 0,
	"CNTL", cntl, 0,
	"ICON", hexa, 0,
	"ICN#", hexa, 0,
	"CURS", hexa, 0,
	"PAT ", hexa, 0,
	"SIZE", size, 0,
	"CONF", conf, 0,
	"CODE",	0L,   R_AOUT | R_BSS,
	"BOOT",	0L,   R_AOUT | R_NOSG,
	0L,	0L,   0
};

int eof;

parse(resources, max)
struct res *resources;
int max;
{
	register struct res *rcp;
	register i;
 	char infile[32], *ip;
	struct typehand *thp;
	int items, id, att;
	long len;
	char littype[32], type[32], format[32];
	char *smalloc(), *index(), *getline(), *skipsp(), *lp;
	char *strcpy();
	char *strncpy();
 
	rcp = resources;
	while (eof == 0) {
		lp = getline();
		if (lp == 0) continue;
		littype[0] = type[0] = 0;
		items = sscanf(lp, "%s %s = %s", littype, type, format);
		if (items < 2 || strcmp(littype, "Type") != 0)
			fatal("bad Type line");
		checktype(type);
		strncpy(rcp->type, type, 4);
		rcp->type[4] = 0;
		if (items == 3) {
			checktype(format);
			strncpy(type, format, 4);
		}
		if ((lp = getline()) == 0)
			fatal("bad id");
		if ((lp = skipsp(lp)) == 0)
			fatal("bad id");
		for (i=0 ; *lp != ',' && *lp != 0 ; lp++,i++)
			infile[i] = *lp;
		infile[i] = 0;
		if (*lp != ',')
			fatal("bad id");
		lp++;
		id = att = 0;
		items = sscanf(lp, " %d(%d) ", &id, &att);
 		ip = index(infile, '|');
 		if (ip) {
 			*ip++ = 0;
 			rcp->name = smalloc((long)(strlen(ip) + 1));
 			strcpy(rcp->name, ip);
 		} else
 			rcp->name = "";
		if (items < 1)
			fatal("bad id");
		if (strlen(infile)) {
			rcp->file = smalloc((long)(strlen(infile) + 1));
 			strcpy(rcp->file, infile);
 			rcp->flags |= R_FILE;
		} else {
			rcp->file = 0;
		}
		rcp->id = id;
		rcp->attr = att;
		/* search for type handler */
		for (thp = &typehand[0] ; ; thp++) {
			if (thp->type_type == 0)
				fatal("type %s not implemented", type);
			if (strcmp(thp->type_type, type) == 0)
				break;
		}
 		rcp->flags |= thp->type_flags;
		if (rcp->file == 0) {
		  if (thp->type_handler == 0)
				fatal("type %s must be in a file", type);
		  len = (*thp->type_handler)(data, MAXSIZE, rcp);
		  if (len != 0) {
			rcp->data = smalloc(len);
			bcopy(data, rcp->data, len);
			rcp->size = len;
		  }
		}
		rcp++;
		if ((rcp - resources) >= max)
			fatal("too many resources");
	}
	return (rcp - resources);
}
