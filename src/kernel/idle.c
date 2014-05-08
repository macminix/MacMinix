/* This file contains the code and data for the idle task.  The idle task
 * has a single entry point, idle_task().  It accepts four message types:
 *
 *   HARD_INT:    a clock interrupt has occurred
 *
 * The input message is format m6.  The parameters are as follows:
 *
 *     m_type
 * ---------------------------------------------
 * | HARD_INT   |          |         |         |
 * ---------------------------------------------
 *
 * This task runs when a) a previosly set alarm has gone off, or
 * b) there are no ready procs in the system.  In the latter case we
 * just handle events.
 */
#include "kernel.h"
#include "proc.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/partition.h>
#include "setup.h"
#include "keymap.h"
#include "tty.h"
#include <mac/Controls.h>
#include <mac/Dialogs.h>
#include <mac/Events.h>
#include <mac/Windows.h>
#include <mac/Menus.h>
#include <mac/Desk.h>
#include <mac/Fonts.h>
#include <mac/OSEvents.h>
#include <mac/BCD.h>
#include <mac/Memory.h>
#include <mac/Scrap.h>

#ifdef DEMO
#define WANTDEBUG	0	/* want the debug menu? */
#define VERSION		"1.5D"	/* goes in the about box */
#else
#define WANTDEBUG	1	/* want the debug menu? */
#define VERSION		"1.5"	/* goes in the about box */
#endif

#define APPLEID 	256	/* apple menu resource id */
#define FILEID		257	/* file menu resource id */
#define EDITID		258	/* edit menu resource id */
#define WINDOWSID	259	/* window menu resource id */
#if WANTDEBUG==1
#define DEBUGID		260	/* debug menu resource id */
#endif

#define HSTYLE		outline	/* style of hidden windows in menu */
#define RSTYLE		outline	/* style of real font sizes in menu */
#define	LINE(p)		((WindowPeek)p)->refCon /* return the "line number" */

PRIVATE message i_mess;		/* message buffer for in and out */
PRIVATE Rect    dragrect;	/* dragrect */
PRIVATE int	windownameidx;	/* item number of first window item */
PRIVATE int	fontidx;	/* item number of first font name */
PRIVATE int	sizeidx;	/* item number of first size */
PRIVATE int	countvis;	/* count of visible windows */
PRIVATE char	name[256];	/* utility */
PRIVATE	int	foreground;	/* MINIX currently in the foreground? */
PRIVATE int 	idle_awake;	/* wake up */

_PROTOTYPE( void XOpenDeskAcc, ( _CONST char *name ) );
FORWARD _PROTOTYPE( void idle_init, ( void ) );
FORWARD _PROTOTYPE( void adjustmenus, ( void ) );
FORWARD _PROTOTYPE( void domenu, ( long select ) );
FORWARD _PROTOTYPE( void idle_events, ( void ) );
FORWARD _PROTOTYPE( int doevent, ( EventRecord *theEvent ) );

/*===========================================================================*
 *				idle task				     * 
 *===========================================================================*/
PUBLIC void idle_task()
{
/* This is the idle task.  In a normal minix sys this would be an idle loop.
   However, instead we use this handle events. */
   idle_init();

   while (TRUE) {
        rs_check();
	receive(ANY, &i_mess);
	idle_events();
	idle_awake = FALSE;
   }
}


/*===========================================================================*
 *				idle_init				     * 
 *===========================================================================*/
PRIVATE void idle_init()
{
/* init the idle task. set up menus */
  int i, item;
  char *wname;
  MenuHandle menu;
  
  printf("BOOTING MACMINIX 1.5\r\n");
  printf("MINIX Copyright 1990, 1991 Prentice-Hall Inc.\r\n");

  dragrect = qd->screenBits.bounds;
  dragrect.top += 20;			/* skip down past menu bar */
  InsetRect(&dragrect, 4, 4);
  
  SetMenuBar(GetNewMBar(256));
  AddResMenu(GetMHandle(APPLEID), (inResType)"DRVR");

#ifdef DEMO
  /* DEMO won't print */
  menu = GetMHandle(FILEID);
  DisableItem(menu, 3);
  DisableItem(menu, 4);
#endif

#if (WANTDEBUG==1)
  menu = NewMenu(DEBUGID, "Debug");
  AppendMenu(menu, "Procs;Memory;(-;Interrupt;Kill");
  InsertMenu(menu, 0);
#endif
  
  DrawMenuBar();

  menu = GetMHandle(WINDOWSID);
  /* for each window, put in a menu item */
  windownameidx = CountMItems(menu) + 1;
  wname = "TTY  / ";
  for (i = 0; i < NR_CONS; i++) {
    wname[4] = i + '0';
    wname[6] = i + '0';
    AppendMenu(menu, wname);
  }
  AppendMenu(menu, "(-");
  
  /* Add a menu item for each fixed width font */
  fontidx = CountMItems(menu) + 1;
  AddResMenu(menu, (inResType)"FONT");
  sizeidx = CountMItems(menu) + 1;
  AppendMenu(menu, "(-;9;10;12;14;18");
  item = fontidx;
  for (;;) {
	GetItem(menu, item, name);
	if (name[0] == '-')
	    break;
	
	if (isfixedwidth(name))
	    item++;
	else {
	    DelMenuItem(menu,item);
	    sizeidx--;
	}
  }
  countvis = NR_CONS;
  foreground = 1;
}


/*==========================================================================*
 *				idle_wakeup				    *
 *==========================================================================*/
PUBLIC void idle_wakeup()
{
/* Wake up the event handler when enough time has elapsed */

#define WAKEUP_TIMEOUT (HZ/6)	/* adjust to taste */

  static unsigned wakeup_timeout = WAKEUP_TIMEOUT;
  register QHdr *e = GetEvQHdr();

  if (!test_and_set(&idle_awake))
        if (e->qHead != 0 || --wakeup_timeout == 0) {
	    wakeup_timeout = WAKEUP_TIMEOUT;
	    interrupt(IDLE);
        }
        else
            idle_awake = FALSE;
}


/*===========================================================================*
 *				isfixedwidth				     * 
 *===========================================================================*/
PUBLIC int isfixedwidth(fname)
char *fname;
{
/* determine if the given font is fixed width */
    register int i, fixed, savef;
    int number;
    GrafPtr p;
    
    GetPort(&p);
    savef = p->txFont;
    GetFNum(fname, &number);
    if (number == 0)
	return 0;
    TextFont(number);
    fixed = CharWidth('.') == CharWidth('M');
    TextFont(savef);
    return (fixed);
}


/*===========================================================================*
 *				adjustmenus				     * 
 *===========================================================================*/
PRIVATE void adjustmenus()
{
/* adjust the windows menu to reflect the current situation */
  MenuHandle menu;
  int fnum, cnt, i, enable;
  WindowPeek w;
  long size;
  
  /* the edit menu is disabled unles a DA is frontmost */
  w = (WindowPeek)FrontWindow();
  menu = GetMHandle(EDITID);
  if (w && w->windowKind < 0) {
  	EnableItem(menu, 1);
  	EnableItem(menu, 3);
  	EnableItem(menu, 4);
  	EnableItem(menu, 5);
  	EnableItem(menu, 6);
  }
  else {
  	DisableItem(menu, 1);
  	DisableItem(menu, 3);
  	DisableItem(menu, 4);
	DisableItem(menu, 5);
  	DisableItem(menu, 6);
  }
  
  if (w != 0 && w->windowKind >= 0)	/* desk acc have negative window kinds */
  	enable = 1;			/* one of our windows is frontmost */
  else
  	enable = 0;
  
  menu = GetMHandle(WINDOWSID);
  if (countvis == NR_CONS) DisableItem(menu, 1); else EnableItem(menu, 1);
  if (countvis > 0)        EnableItem(menu, 2);  else DisableItem(menu, 2);
  	
  if (countvis > 1 && enable)
  	EnableItem(menu, 3);
  else
        DisableItem(menu, 3); 
        
  /* set up font items */
  for (i = fontidx; i < sizeidx; i++) {
  	CheckItem(menu, i, 0);
  	if (enable) {
  		EnableItem(menu, i);
		GetItem(menu, i, name);
		GetFNum(name, &fnum);
		if (w->port.txFont == fnum)
			CheckItem(menu, i, 1);
  	} else
  		DisableItem(menu, i);
  }
  
  /* set up size items */
  cnt = CountMItems(menu);
  for (i = sizeidx; i <= cnt; i++) {
  	CheckItem(menu, i, 0);
	SetItemStyle(menu, i, normal);
  	if (enable) {
  		EnableItem(menu, i);
		GetItem(menu, i, name);
		StringToNum(name, &size);
		if (RealFont(w->port.txFont, (int)size))
		 	SetItemStyle(menu, i, RSTYLE);
		if (w->port.txSize == size)
			CheckItem(menu, i, 1);
  	} else
  		DisableItem(menu, i);
  }
}


/*===========================================================================*
 *				quit					     * 
 *===========================================================================*/
PUBLIC void quit(syncsomeday)
int syncsomeday;
{
/* all done, go away */
  f_close_all();
  w_close_all();
  rs_close();
  end_clock();
  set_exceptions(1);
  ExitToShell();
}


/*===========================================================================*
 *				domenu					     * 
 *===========================================================================*/
PRIVATE void domenu(select)
long	select;
{
/* perform the menu selection */
	int		menuID = HiWord(select);
  	int		menuItem = LoWord(select);
  	GrafPtr		savePort;
  	struct config   conf;
  	DialogPtr	d;
  	int		i, j;
  	MenuHandle	menu;
	long		fsize;
	
	switch (menuID)
	{
	    case APPLEID:
	        if (menuItem == 1) {
	          extern phys_bytes mem_bytes;
	          	
	          fsize =  (mem_bytes-code_base+1023)/1024;
		  NumToString(fsize, name);
	          ParamText(name, VERSION, "", "");
	          d = GetNewDialog(256, 0L, (WindowPtr)-1);
	          ShowWindow(d);
     		  ModalDialog(0L, &i);
     		  CloseDialog(d);
	        }
	        else {
		  GetPort(&savePort);
		  /* This is awful. Desk acc's have nulls as the first char 
		   * of their name, so we have to provide for it.  The following
		   * depends on some intimate knowledge of how the mac lib works.
		   */ 
	          for (i = 0; i < sizeof(name); i++)
	        	name[i] = 0;
		  GetItem(GetMHandle(APPLEID), menuItem, &name[1]);
		  /* it's gotten worse, as 7.0 apparently buts 2 nulls first */
		  for (i = 0; i < 255 && name[i] == 0; i++);
		  name[0] = strlen(&name[i])+i-1;
		  XOpenDeskAcc(name);
		  SetPort(savePort);
		}
		break;
	
	    case FILEID:
		switch (menuItem){
		  case 1: setup(&conf, 1, 1); break;	/* config */
		  case 3: docsetup();	      break;	/* page setup */
		  case 4: jobsetup();	      break;	/* set up for next jobs */
		  case 6: quit(1);	      break;    /* quit */
		}
		break;
  				
	  case	EDITID:
		if (!SystemEdit(menuItem-1)) SysBeep(2);
		break;
		
	  case	WINDOWSID:
		menu = GetMHandle(WINDOWSID);
		switch (menuItem){
		  case 1:				/* show all */
		        for (i = 0; i < NR_CONS; i++) {
			  vdusetparams((long)i, 0, -1, -1, 0, 0, 0L, 1, 0, 0);
			  GetItemStyle(menu, windownameidx+i, &j);
			  if (j & HSTYLE)
			    countvis++;
			  SetItemStyle(menu, windownameidx+i, normal);
		        }
		        break;
		        
		  case 2:				/* hide all */
		        for (i = 0; i < NR_CONS; i++) {
			  vdusetparams((long)i, 0, -1, -1, 0, 0, 0L, 0, 0, 0);
			  GetItemStyle(menu, windownameidx+i, &j);
			  if (j == normal)
			    countvis--;
			  SetItemStyle(menu, windownameidx+i, HSTYLE);
		        }
		     	break;
		     	
		  case 3:				/* rotate */
		     	SendBehind(FrontWindow(), 0L);
			SelectWindow(FrontWindow());
		     	break;
		     	
		  default:				/* show, font or size */
		     	if (menuItem >= windownameidx && menuItem < fontidx) {
			  vdusetparams((long)(menuItem-windownameidx), 0, -1, -1, 1, 0, 0L, 1, 0, 0);
			  GetItemStyle(menu, menuItem, &i);
			  if (i & HSTYLE)
			    countvis++;
			  SetItemStyle(menu, menuItem, normal);
		     	}
		     	else if (menuItem >= fontidx && menuItem < sizeidx) {
			  GetItem(menu, menuItem, name);
			  GetFNum(name, &i);
			  vdusetparams(LINE(FrontWindow()), 0, i, -1, 1, 1, 0L, 1, 0, 0);
		     	}
		     	else {
			  GetItem(menu, menuItem, name);
			  StringToNum(name, &fsize);
			  vdusetparams(LINE(FrontWindow()), 0, -1, (int)fsize, 1, 1, 0L, 1, 0, 0);
		     	}
		     	break;
		}
		break;

#if WANTDEBUG==1
	  case	DEBUGID:
		switch (menuItem){
		  case 1: kb_char(VPROC, 0); break;
		  case 2: kb_char(VMAP,  0); break;
		  case 4: kb_char(VINT,  0); break;
		  case 5: kb_char(VKILL, 0); break;
		}
		break;
#endif

	}
	HiliteMenu(0);
}


/*===========================================================================*
 *				idle_events				     * 
 *===========================================================================*/
PRIVATE void idle_events()
{
/* Handle events */
  EventRecord theEvent;
  extern char vdupaused;
  Boolean haveEvent;
  int i, keypresses = 0;
  
  set_exceptions(1);		/* reset normal exception */
  end_clock();			/* reset clock interrupt */
  SystemTask();
  do {
    haveEvent = GetNextEvent(everyEvent, &theEvent);
    if (haveEvent)
      	keypresses += doevent(&theEvent);
  } while (haveEvent);
  start_clock();		/* reset clock interrupt */
  set_exceptions(0);
  if (keypresses)
	ObscureCursor();	/* people prefer this */
  if (keypresses || (vdupaused == TRUE))
  	interrupt(TTY);		/* tty may have suspended output for events */
}


/*===========================================================================*
 *				doevent				     	     * 
 *===========================================================================*/
PRIVATE int doevent(theEvent)
register EventRecord *theEvent;
{
/* do a specific event */
  Point   evtPt;
  GrafPtr evtPort;
  register short evtPart;
  register char evtChar;
  register int evtMods;
  register long evtMsge;
  int item, keys = 0;

  evtPt = theEvent->where;
  evtMods = theEvent->modifiers;
  evtMsge = theEvent->message;

  switch (theEvent->what) {

    case mouseUp:
    	break;
    	
    case mouseDown:
	evtPart = FindWindow(evtPt, &evtPort);

	switch (evtPart) {

  		case inSysWindow:
      			SystemClick(theEvent, evtPort);
     			break;

  		case inMenuBar:
  			adjustmenus();
    			domenu(MenuSelect(theEvent->where));
      			break;

  		case inGrow:
        		vdusetparams(LINE(evtPort), 0, -1, -1, -1, 1, (long *)&evtPt, -1, 0, 0);
      			break;

  		case inDrag:
      			if (evtPort != FrontWindow() && (evtMods & cmdKey) == 0)
				SelectWindow(evtPort);
      			DragWindow(evtPort, evtPt, &dragrect);
      			break;

  		case inGoAway:
      			if (TrackGoAway(evtPort, evtPt)) {
			  vdusetparams(LINE(evtPort), 0, -1, -1, 0, 0, 0L, 0, 0, 0);
			  item = LINE(evtPort) + windownameidx;
			  SetItemStyle(GetMHandle(WINDOWSID), item, HSTYLE);
			  countvis--;
      			}
     		 	break;

 		case inZoomIn:
 		case inZoomOut:
      			if (TrackBox(evtPort, evtPt, evtPart))
        		  vdusetparams(LINE(evtPort), 0, -1, -1, -1, -1, 0L, -1, 0, 1);
      		break;

  		case inContent:
      			if (evtPort != FrontWindow())
			    SelectWindow(evtPort);
		    	else	/* scroll bar */
			    vdutrack(LINE(evtPort), (long *)&evtPt);
      			break;
	}
	break;

    case keyDown:
    case autoKey:
      	if ((evtMods & cmdKey) != 0 && (evtMods & optionKey) == 0) {
	  adjustmenus();
	  domenu(MenuKey((char) (evtMsge & charCodeMask)));
      	}
      	else {
#ifdef BIND
	  char *s, *checkbinding();

	  if (s = checkbinding((int)evtMsge, evtMods)) {
	     kb_paste(s, strlen(s));
	     keys += strlen(s);
	  }
	  else {
             kb_char((int)(evtMsge & keyCodeMask) >> 8, evtMods);
	     keys++;
	  }
#else
          kb_char((int)(evtMsge & keyCodeMask) >> 8, evtMods);
	  keys++;
#endif
	}
      	break;

    case updateEvt:
	BeginUpdate((WindowPtr)evtMsge);
	vdusetparams(LINE(evtMsge), 0, -1, -1, -1, 0, 0L, -1, 1, 0);
    	EndUpdate((WindowPtr)evtMsge);
	break;

    case activateEvt:
	if ((evtMods & activeFlag) != 0)
          vdusetparams(LINE(evtMsge), 0, -1, -1, 1, 0, 0L, -1, 0, 0);
	else
          vdusetparams(LINE(evtMsge), 0, -1, -1, 0, 0, 0L, -1, 0, 0);
	break;

    case app4Evt:
    	if (evtMsge & 1) {
    	  extern struct qd *qd;
    	  foreground = 1;
    	  SetCursor(&qd->arrow);	/* some apps mess with the cursor */
    	}
    	else
    	  foreground = 0;		/* call getnext event a lot in background */
    	break;
    	
    default:
    	break;
  }
  return keys;
}
