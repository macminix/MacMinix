/* Keyboard driver */

#include <mac/Events.h>
#include <mac/Fonts.h>
#include <mac/Resources.h>
#include "kernel.h"
#include <sgtty.h>
#include <signal.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include "tty.h"
#include "proc.h"
#include "setup.h"
#include "keymap.h"

#define SCODE	    	    1   /* virtual key code for 's' */
#define BACKQUOTECODE	 0x32   /* virtual key code for '`' */
#define ESCCODE	 	 0x35   /* virtual key code for escape */
#define CONSOLE		    0	/* line number for console */
#define KB_IBUFSIZE	   32	/* size of keyboard input buffer */
#define controlKey       4096	/* control key bit */
#define ASCII		 8192   /* ascii key bit */

#define kb_addr(n)	   (&kb_lines[n+NR_CONS])
#define tp_addr(n)	   (&tty_struct[n+NR_CONS])

/* Keyboard structure, 1 per window. */
struct kb_s {
  int minor;			/* minor number of this line (base 0) */

  char *ibuf;			/* start of input buffer */
  char *ibufend;		/* end of input buffer */
  char *iptr;			/* next free spot in input buffer */

  char ibuf1[KB_IBUFSIZE + 1];	/* 1st input buffer, guard at end */
  char ibuf2[KB_IBUFSIZE + 1];	/* 2nd input buffer (for swapping) */
};

PRIVATE int    maptoescape = 1;
PRIVATE int    mapoption = 1;
PRIVATE int    mapcmdopt = 1;
PRIVATE int    state = 0;
PRIVATE int    control = 0;
PRIVATE int    inascii = 0;
PRIVATE int    option = 0;
PRIVATE int    capslock = 0;
PRIVATE int    command = 0;
PRIVATE int    shift = 0;
PRIVATE int    usebuiltinmap = 0;
PRIVATE struct kb_s kb_lines[NR_CONS];
PRIVATE int    ttyactive = -NR_CONS;
PRIVATE char   *scode_map[] = {"\033[D", "\033[C", "\033[B", "\033[A",
			       "\033[5~", "\033[H", "\033[4~", "\033[6~",
			       "\033[3~", "\033[1~", "\033[2~"};
PRIVATE int    scode_cnt = sizeof(scode_map)/sizeof(char *);
#ifdef THINK_C
extern ProcPtr Key1Trans : 0x29e;
extern ProcPtr Key2Trans : 0x2a2;
extern int  ROM85 : 0x28e;
extern char KbdType: 0x21e;
#else
extern ProcPtr Key1Trans;
extern ProcPtr Key2Trans;
extern int  ROM85;
extern char KbdType;
#endif

PRIVATE char unsh_map[NR_VIRTCODES] =
{
  'a','s','d','f','h','g','z','x','c','v','\0','b','q','w','e','r',
  'y','t','1','2','3','4','6','5','=','9','7','-','8','0',']','o',
  'u','[','i','p','\15','l','j','\'','k',';','\\',',','/','n','m','.',
  '\11',' ','`','\10','\3','\33','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','.','\35','*','\0','+','\34','\33','\37','\0','\0','/','\3','\36','-','\0',
  '\0','=','0','1','2','3','4','5','6','7','\0','8','9','\0','\0','\0',
  '\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20',
  '\20','\20','\5','\1','\13','\255','\20','\4','\20','\14','\20','\34','\35','\37','\36','\0'
};

PRIVATE char sh_map[NR_VIRTCODES] =
{
  'A','S','D','F','H','G','Z','X','C','V','\0','B','Q','W','E','R',
  'Y','T','!','@','#','$','^','%','+','(','&','_','*',')','}','O',
  'U','{','I','P','\15','L','J','"','K',':','|','<','?','N','M','>',
  '\11',' ','~','\10','\3','\33','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','.','*','*','\0','+','+','\33','=','\0','\0','/','\3','/','-','\0',
  '\0','=','0','1','2','3','4','5','6','7','\0','8','9','\0','\0','\0',
  '\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20',
  '\20','\20','\5','\1','\13','\255','\20','\4','\20','\14','\20','\34','\35','\37','\36','\0',
};

PRIVATE char opt[NR_VIRTCODES] = {
  '\214','\247','\266','\304','\372','\251','\275','\305','\215','\303','\0','\272','\317','\267','\0','\250',
  '\264','\240','\301','\252','\243','\242','\244','\260','\255','\273','\246','\320','\245','\274','\324','\277',
  '\0','\322','\0','\271','\15','\302','\306','\276','\373','\311','\307','\262','\326','\0','\265','\263',
  '\11','\312','\0','\10','\3','\33','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','.','\35','*','\0','+','\34','\33','\37','\0','\0','/','\3','\36','-','\0',
  '\0','=','0','1','2','3','4','5','6','7','\0','8','9','\0','\0','\0',
  '\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20',
  '\20','\20','\5','\1','\13','\177','\20','\4','\20','\14','\20','\34','\35','\37','\36','\0',
};

PRIVATE char opt_shift[NR_VIRTCODES] = {
  '\201','\352','\353','\354','\356','\355','\363','\364','\202','\327','\0','\365','\316','\343','\344','\345',
  '\347','\346','\332','\333','\334','\335','\337','\336','\261','\341','\340','\321','\241','\342','\325','\257',
  '\350','\323','\351','\270','\15','\361','\357','\256','\360','\362','\310','\370','\300','\366','\367','\371',
  '\11','\312','\331','\10','\3','\33','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','.','*','*','\0','+','+','\33','=','\0','\0','/','\3','/','-','\0',
  '\0','=','0','1','2','3','4','5','6','7','\0','8','9','\0','\0','\0',
  '\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20',
  '\20','\20','\5','\1','\13','\177','\20','\4','\20','\14','\20','\34','\35','\37','\36','\0',
};

PRIVATE char opt_capslock[NR_VIRTCODES] = {
  '\201','\352','\353','\354','\356','\355','\363','\364','\202','\327','\0','\365','\316','\343','\344','\345',
  '\347','\346','\301','\252','\243','\242','\244','\260','\255','\273','\246','\320','\245','\274','\324','\257',
  '\350','\322','\351','\270','\15','\361','\357','\256','\360','\311','\307','\262','\326','\366','\367','\263',
  '\11','\312','`','\10','\3','\33','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','.','\35','*','\0','+','\34','\33','\37','\0','\0','/','\3','\36','-','\0',
  '\0','=','0','1','2','3','4','5','6','7','\0','8','9','\0','\0','\0',
  '\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20','\20',
  '\20','\20','\5','\1','\13','\177','\20','\4','\20','\14','\20','\34','\35','\37','\36','\0',
};

_PROTOTYPE( unsigned char ascii, (ProcPtr keytr, int vkeycode, int modifiers) );

/*===========================================================================*
 *				kb_init					     *
 *===========================================================================*/
PUBLIC void kb_init(minor)
int minor;
{
/* Initialize the keyboard driver. */
  register struct kb_s *kb;
  register int i;
  struct config conf;
  static int beenhere = FALSE;

  if (beenhere == FALSE) {
  	setup(&conf, 0, 0);
  	usebuiltinmap = conf.keymap;
  	maptoescape = conf.maptoescape;
  	mapoption = conf.mapopt;
  	mapcmdopt = conf.mapcmdopt;
#ifdef BIND
	initbindings();
#endif
	beenhere = TRUE;
  }

  kb = kb_addr(minor);

  /* Record minor number. */
  kb->minor = minor;

  /* Set up input queue. */
  kb->iptr = kb->ibuf = kb->ibuf1;
  kb->ibufend = kb->ibuf1 + KB_IBUFSIZE;
  kb->iptr = kb->ibuf1;
}


/*===========================================================================*
 *				kb_active				     *
 *===========================================================================*/
PUBLIC void kb_active(minor)
{
/* activate the specified keyboard. */
  ttyactive = minor;
}


/*==========================================================================*
 *				kb_read					    *
 *==========================================================================*/
PUBLIC int kb_read(minor, bufindirect, odoneindirect)
int minor;
char **bufindirect;
unsigned char *odoneindirect;
{
/* Swap the keyboard input buffers, giving the old one to TTY. */

  register char *ibuf;
  register struct kb_s *kb;
  int s, nread;
  kb = kb_addr(minor);
  *odoneindirect = FALSE;
  if (kb->iptr == (ibuf = kb->ibuf)) return 0;
  *bufindirect = ibuf;
  nread = kb->iptr - ibuf;
  s = lock();
  tty_events -= nread * EVENT_THRESHOLD;
  if (ibuf == kb->ibuf1)
	ibuf = kb->ibuf2;
  else
	ibuf = kb->ibuf1;
  kb->ibufend = ibuf + KB_IBUFSIZE;
  kb->iptr = ibuf;
  restore(s);
  kb->ibuf = ibuf;
  return nread;
}


/*===========================================================================*
 *				kb_paste			     	     *
 *===========================================================================*/
PUBLIC void kb_paste(chars, count)
register char *chars;
register int count;
{
  while (count-- > 0) 
    kb_char(*chars++, ASCII);
}


/*===========================================================================*
 *				kb_char				     	     *
 *===========================================================================*/
PUBLIC void kb_char(scode, mod)
int scode;
int mod;
{
  register struct kb_s *kb;
  register struct tty_struct *tp;
  int s;
  

  /* Fetch the characters from the keyboard and
  /* store then in memory so the task can get at it later. */
  kb = kb_addr(ttyactive);
  tp = tp_addr(ttyactive);
  
  /* mac plus keyboard does not have an escape key,
     so ~ can be mapped to escape key */
  if (maptoescape && scode == BACKQUOTECODE && (mod & shiftKey)) {
	scode = ESCCODE;
        mod &= ~shiftKey;
  }

  /* command-opt-[0-5] mapped onto extended keys */
  if (mapcmdopt && (mod & cmdKey) && (mod & optionKey) && scode >= 0x12 && scode <= 0x1d)
     switch(scode) {
       case 0x1d: mod &= ~(optionKey|cmdKey); scode = VHELP; break;
       case 0x12: mod &= ~(optionKey|cmdKey); scode = VHOME; break;
       case 0x13: mod &= ~(optionKey|cmdKey); scode = VPAGEUP; break;
       case 0x14: mod &= ~(optionKey|cmdKey); scode = VEND; break;
       case 0x15: mod &= ~(optionKey|cmdKey); scode = VPAGEDOWN; break;
       case 0x17: mod &= ~(optionKey|cmdKey); scode = VENTER; break;
       case 0x16: mod &= ~(optionKey|cmdKey); scode = VCLEAR; break;
       default:   break;
     }

  /* option key mapped to control key */
  if (mapoption && (mod & optionKey)) {
        mod &= ~optionKey;
	mod |= controlKey;
  }

  if (mod != state) {
      /* the modifier keys have changed.  We encode this as a virtual
          key with the high bit set so it can be noticed below in the
          routine to convert it to its ascii equiv.
      */
      state = mod;
      *kb->iptr = 0x80 | ((mod >> 8) & 0x3f);
      if (kb->iptr < kb->ibufend) {
	      ++kb->iptr;
	      s = lock();
	      tty_events += EVENT_THRESHOLD;
	      restore(s);
      }
  }

  /* Check to see if character is CTRL-S, to stop output.*/
  if (!(tp->tty_mode & RAW) &&
      (state & controlKey) && scode == SCODE &&
      tp->tty_xoff == XOFF_CHAR) {
	  tp->tty_inhibited = STOPPED;
	  return;
  }

  *kb->iptr = scode;
  if (kb->iptr < kb->ibufend) {
      ++kb->iptr;
      s = lock();
      tty_events += EVENT_THRESHOLD;
      restore(s);
  }
  /* Else it doesn't fit - discard it. */
}


/*===========================================================================*
 *				make_break				     *
 *===========================================================================*/
PUBLIC int make_break(ch)
char ch;		  			/* virtual key code of key */
{
  int mods;
  ProcPtr k;
  
  if (ch & 0x80) {				/* change in mod keys */
    mods = (ch & 0x3f) << 8;
    control = mods & controlKey;
    shift = mods & shiftKey;
    option = mods & optionKey;
    command = mods & cmdKey;
    capslock = mods & alphaLock;
    inascii = mods & ASCII;
    return(-1);
  }
     
  if (inascii)
    return(ch);

  if (letter_code(ch))
    return(0);
    
  if (ch == ESCCODE)
    return(ESC);
    
  /* ordinary keys */
  if (!usebuiltinmap) {
    if (ch > 64)
	k = Key2Trans;
    else
	k = Key1Trans;
    if (k != (ProcPtr)-1) {
	ch = ascii(k, ch, (shift|option|capslock) >> 9);
	if (control)
    	  ch &= 037;
    	return(ch);
    }
  }
   
  /* using the builtin map */
  if (option) {
    if (capslock)
      ch = opt_capslock[ch];
    else if (shift)
      ch = opt_shift[ch];
    else
      ch = opt[ch];
  }
  else if (shift)
     ch = sh_map[ch];
  else
     ch = unsh_map[ch];

  if (capslock)
    if (ch >= 'A' && ch <= 'Z')
	ch += 'a' - 'A';
    else if (ch >= 'a' && ch <= 'z')
	ch -= 'a' - 'A';
	
  if (control)
    ch &= 037;
	
  return ch;
}


/*===========================================================================*
 *				letter_code				     *
 *===========================================================================*/
PUBLIC char *letter_code(scode)
int scode;			/* scan code from key press */
{
/* Convert scan codes from numeric keypad to letters for use in escape seqs. */

  if (inascii) return 0;

  if (scode >= 0x40) {
    switch (scode) {
      	case VLEFTPLUS:
      	case VLEFT:     return scode_map[0];		/* left arrow key */
      	case VRIGHTPLUS:
      	case VRIGHT:    return scode_map[1];		/* right arrow key */
      	case VDOWNPLUS:
      	case VDOWN:     return scode_map[2];		/* down arrow key */
      	case VUPPLUS:
      	case VUP:       return scode_map[3];		/* up arrow key */
      	case VHELP:     return scode_map[4];		/* help key */
      	case VHOME:     return scode_map[5];		/* home key */
      	case VPAGEUP:   return scode_map[6];		/* page up key */
      	case VEND:      return scode_map[7];		/* end key */
      	case VPAGEDOWN: return scode_map[8];		/* page down key */
      	case VENTER:    return scode_map[9];		/* enter key */
      	case VCLEAR:    return scode_map[10];		/* clear key */
      	default:        return 0;			/* nothing I know about */
    }
  }
  return 0;
}


/*===========================================================================*
 *				func_key				     *
 *===========================================================================*/
PUBLIC int func_key(ch)
unsigned char ch;			/* scan code for a function key */
{
/* This procedure traps function keys for debugging and control purposes. */

  if (inascii) return(FALSE);

  if (ch >= VF5 && ch <= VF1) {
    switch (ch) {
	case VF1:
	case VF2:
	case VF3:
	case VF4: break;
	
	case VF5: p_dmp();   break;	/* print process table */
	case VF6: map_dmp(); break;	/* print memory map */
#if AM_KERNEL
#if !NONET
	case VF7: net_init();break;	/* re-initialise the ethernet card */
#endif /* !NONET */
#endif /* AM_KERNEL */
    	case VF8: sigchar(&tty_struct[CONSOLE], SIGINT); break;
    	case VF9: sigchar(&tty_struct[CONSOLE], SIGKILL);break;
    	
    	case VF10:
    	case VF11:
    	case VF12:
    	case VF13:
    	case VF14:
    	case VF15: break;
    	default:   return(FALSE);	/* some misc codes in here */
    }
    return(TRUE);
  }
  return(FALSE);			/* not our job */
}


/*==========================================================================*
 *				reboot					    *
 *==========================================================================*/
PUBLIC void reboot()
{
/* Reboot the machine. * NOT REALLY * */
  quit(0);
}


/*==========================================================================*
 *				wreboot					    *
 *==========================================================================*/
PUBLIC void wreboot()
{
  EventRecord event;

  printf("Type any key to exit\r\n");
  FlushEvents(keyUp|keyDown|autoKey, 0);
  while (!GetNextEvent(keyUpMask|keyDownMask|autoKeyMask,&event));
  reboot();
}
