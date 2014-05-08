#include "res.h"

/* Item types */
#define ctrlItem 		4
#define btnCtrl 		0
#define chkCtrl 		1
#define radCtrl 		2
#define resCtrl 		3
#define statText 		8
#define editText 	       16
#define iconItem     	       32
#define picItem 	       64
#define userItem 		0
#define itemDisable 	      128

/*
 *	long	zero;
 *	Rect	itemrect;
 *	char	itemtype;
 *	char	itemlength;
 *	...  			followed by variable length data
 */

static struct keywords {
	char *name;
	int value;
} keywords[] = {
	"ctrlItem",ctrlItem,
	"CtrlItem",ctrlItem,
	"btnCtrl",btnCtrl,
	"BtnCtrl",btnCtrl,
	"chkCtrl",chkCtrl,
	"ChkCtrl",chkCtrl,
	"radCtrl",radCtrl,
	"RadCtrl",radCtrl,
	"resCtrl",resCtrl,
	"ResCtrl",resCtrl,
 	"radioItem",radCtrl+ctrlItem,
 	"RadioItem",radCtrl+ctrlItem,
 	"chkItem",chkCtrl+ctrlItem,
 	"ChkItem",chkCtrl+ctrlItem,
	"statText",statText,
	"StatText",statText,
	"editText",editText,
	"EditText",editText,
	"iconItem",iconItem,
	"IconItem",iconItem,
	"picItem",picItem,
	"PicItem",picItem,
	"userItem",userItem,
	"UserItem",userItem,
	"itemDisable",itemDisable,
	"ItemDisable",itemDisable,
	"btnItem",btnCtrl+ctrlItem,
	"BtnItem",btnCtrl+ctrlItem,
	"enabled",0,
	"Enabled",0,
	"disabled",itemDisable,	
	"Disabled",itemDisable,
	"disable",itemDisable,
	"Disable",itemDisable,
	"itemDisabled",itemDisable,
	0,0
};


long ditl(data, maxl, rcp) 
char *data;
long   maxl;
struct res *rcp;
{
	int len, id, j;
	int r1, r2, r3, r4;
	int val,types;
	register struct keywords *dk;
	char *datap = data;
	char *p, *lp, *skipsp(), *getline();
	char *outp(), *outs(), *outl(), *outc();

	if ((lp = getline()) == 0 || sscanf(lp, "%d", &val) < 1)
		fatal("bad item count");
	datap = outs(datap, val - 1, &maxl);

	for ( j = 0; j < val; j++) {
		datap = outl(datap, (long)0, &maxl);
 		if (getline() == 0)		/* line with item types */
			fatal("Missing item type");
		types = 0;
		while (lp = skipsp(lp)) {
			for (dk = &keywords[0] ; dk->name ; dk++)
			    if (strncmp(dk->name,lp,
				strlen(dk->name)) == 0)
					goto found;
			fatal("bad item type %s",lp);
		found:
			lp += strlen(dk->name);
			types += dk->value;
		}
	        if ((lp = getline()) == 0
	             || sscanf(lp, "%d %d %d %d", &r1, &r2, &r3, &r4) != 4)
		        fatal("bad rectangle");
	        datap = outs(datap, r1, &maxl);
	        datap = outs(datap, r2, &maxl);
	        datap = outs(datap, r3, &maxl);
	        datap = outs(datap, r4, &maxl);
	        datap = outc(datap, (char)types, &maxl);
 		if (((lp = skipsp(getline())) == 0) && (types&(~itemDisable) != editText))
			fatal("Missing data");

		types &= ~itemDisable;		/* don't care about this bit */

		switch (types) {	

		case iconItem:
		case picItem:
		case ctrlItem+resCtrl: 
	                if (sscanf(lp, "%d", &id) != 1)
			    fatal("missing resource id");
		        datap = outc(datap, (char)sizeof(short), &maxl);
		        datap = outs(datap, id, &maxl);
			break;	
		
		case userItem:
		        datap = outc(datap, (char)0, &maxl);
			break;

		case ctrlItem+btnCtrl:
		case ctrlItem+chkCtrl:
		case ctrlItem+radCtrl:
		case statText:	
		case editText:
			len = strlen(lp);
			datap = outc(datap, (char)len, &maxl);
			p = lp;
			while (*p)
			  datap = outc(datap, *p++, &maxl);
			if (len & 1)
			  datap = outc(datap, (char)0, &maxl);
			break;
		} 
	}
        return (datap - data);
}
