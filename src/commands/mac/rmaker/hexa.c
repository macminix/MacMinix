#include "res.h"

/*
 * hexadecimal format data.
 */

long hexa(data, maxl, rcp)
char *data;
long maxl;
struct res *rcp;
{
	char hex[4];
	int val, len;
	char *lp, *getline();
	char *datap = data;
	char *outp(), *outs(), *outl(), *outc();
	char *strncpy();

	hex[2] = 0;
	while ((lp = getline()) != 0) {
		for (len = strlen(lp) ; len > 0 ; ) {
			if (*lp == ' ') {
				lp++;  len--;
				continue;
			}
			strncpy(hex, lp, 2);
			if (sscanf(hex, "%x", &val) != 1)
				fatal("bad digits");
			datap = outc(datap, (char)val, &maxl);
			lp += 2;  len -= 2;
		}
	}
	len = datap - data;
	if (len & 1) {
		datap = outc(datap, (char)0, &maxl);
	}
	return (datap - data);
}
