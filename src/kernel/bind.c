#ifdef BIND
#include "kernel.h"
#include "keymap.h"
#include <mac/Events.h>

/* 
 * Keyboard bindings.  This code allows you to bind a key to a string
 * of chars.
 */

#define MODMASK	      0x1f00
#define VCODEMASK	0x7f
#define MAXBINDINGS	  60

char keymapbits[512];

struct binding {
  int bit_nr;
  char *macro;
} bound[MAXBINDINGS];

_PROTOTYPE( void initbindings, (void) );
_PROTOTYPE( char *checkbinding, (int vcode, int mods) );

FORWARD _PROTOTYPE( void binderr, (char *s) );
FORWARD _PROTOTYPE( void bind, (int vcode, int mods, char *c) );
FORWARD _PROTOTYPE( struct binding *getbinding, (int bit_nr) );

PRIVATE void binderr(s)
char *s;
{
   ParamText(s, "", "", "");
   StopAlert(128, 0L);
}

PUBLIC void initbindings()
{
   register int i;
   
   for (i = 0; i < MAXBINDINGS; i++)
   	bound[i].bit_nr = -1;			/* unbound */
   	
   bind(VHOME, 0, "\033[H");
   bind(VENTER, 0, "\033[1~");
   bind(VEND, 0, "\033[6~");
   bind(VHELP, 0, "\033[5~");
   bind(VPAGEUP, 0, "\033[4~");
   bind(VPAGEDOWN, 0, "\033[3~");
   bind(VCLEAR, 0, "\033[2~");
   bind(VLEFT, 0, "\033[D");
   bind(VLEFTPLUS, 0, "\033[D");
   bind(VRIGHT, 0, "\033[C");
   bind(VRIGHTPLUS, 0, "\033[C");
   bind(VDOWN, 0, "\033[B");
   bind(VDOWNPLUS, 0, "\033[B");
   bind(VUP, 0, "\033[A");
   bind(VUPPLUS, 0, "\033[A");
   bind(VF1, 0, "ls -C\r");
   bind(VF2, 0, "ls -lt\r");
   bind(VF3, 0, "date\r");
   bind(VF4, 0, "");
   bind(VF5, 0, "");
   bind(VF6, 0, "");
   bind(VF7, 0, "");
   bind(VF8, 0, "");
   bind(VF9, 0, "");
   bind(VF10, 0, "");
   bind(VF11, 0, "");
   bind(VF12, 0, "");
   bind(VF13, 0, "");
   bind(VF14, 0, "");
   bind(VF15, 0, "");
   bind(0x32, shiftKey|optionKey, "\033");
   bind(0x29, cmdKey|optionKey, "This is cmd-opt-0\r");
   bind(0x18, cmdKey|optionKey, "This is cmd-opt-1\r");
   bind(0x19, cmdKey|optionKey, "This is cmd-opt-2\r");
   bind(0x20, cmdKey|optionKey, "This is cmd-opt-3\r");
   bind(0x21, cmdKey|optionKey, "This is cmd-opt-4\r");
   bind(0x23, cmdKey|optionKey, "This is cmd-opt-5\r");
   bind(0x22, cmdKey|optionKey, "This is cmd-opt-6\r");
}

PRIVATE struct binding *getbinding(bit_nr)
int bit_nr;
{
   register int i;
   
   if (keymapbits[bit_nr/8] & (1 << (bit_nr%8))) {
   	for (i = 0; i < MAXBINDINGS; i++)
   	  if (bound[i].bit_nr == bit_nr)
   	  	return &bound[i];
   }
   return 0L;
}

PUBLIC void bind(vcode, mods, macro)
int   vcode;	/* the key code */
int   mods;	/* the modifier keys */
char *macro;	/* the macro */
/* Define a new keyboard macro */
{
   register int i;
   int bit_nr;
   register struct binding *b;
   
   bit_nr = ((mods & MODMASK) >> 1) + (vcode & VCODEMASK);
   if (b = getbinding(bit_nr))
   	b->macro = macro;
   else {
   	for (i = 0; i < MAXBINDINGS; i++)
   	  if (bound[i].bit_nr == -1) {
   	  	bound[i].bit_nr = bit_nr;
   	  	bound[i].macro = macro;
   	  	keymapbits[bit_nr/8] |= (1 << (bit_nr%8));
   	  	return;
   	  }
   	binderr("MAXBINDINGS exceeded");
   }
}

PUBLIC char *checkbinding(vcode, mods)
{
   int bit_nr;
   register struct binding *b;
   
   vcode = vcode >> 8;
   /* check that it won't cause an infinite expansion */
   bit_nr = ((mods & MODMASK) >> 1) + (vcode & VCODEMASK);
   if (b = getbinding(bit_nr)) {
   	return b->macro;
   }
   else
   	return 0L;
}
#endif
