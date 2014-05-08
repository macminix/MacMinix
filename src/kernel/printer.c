/* This file contains the printer driver. It is a fairly simple driver,
 * supporting only one printer.  Characters that are written to the driver
 * are written to the printer without any changes at all.
 *
 * The valid messages and their parameters are:
 *
 *   TTY_WRITE:    a process wants to write on the printer
 *   CANCEL:       terminate a previous incomplete system call immediately
 *
 *    m_type      TTY_LINE   PROC_NR    COUNT    ADDRESS
 * -------------------------------------------------------
 * | TTY_WRITE   |minor dev| proc nr |  count  | buf ptr |
 * |-------------+---------+---------+---------+---------|
 * | CANCEL      |minor dev| proc nr |         |         |
 * -------------------------------------------------------
 * 
 * Note: since only 1 printer is supported, minor dev is not used at present.
 */

#include "kernel.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <mac/Print.h>
#include <mac/Fonts.h>
#include <mac/Files.h>
#include <mac/Quickdraw.h>
#include <mac/Memory.h>

/*
 * hopefully we will have device open and device close calls to
 * make this more reasonable (eventually).
 */

#define PFONT		courier	/* need ioctl to set this */
#define PSIZE		10	/* need ioctl to set this */
#define LEFTMARGIN	10
#define TOPMARGIN	10
#define BOTTOMMARGIN	TOPMARGIN
/* scale line number by ration of page size to lines per page.
   Eliminates lheight to avoid rounding too soon (i.e. want mul before div
   rather than vice versa).
*/
#define LINE(no)	(prect.top + TOPMARGIN + \
	(int) ((long) (prect.bottom - BOTTOMMARGIN - prect.top - TOPMARGIN) * \
	(long) (no) / (long) lperpage))

extern int PrintErr;		/* filled in by Mac OS */

PRIVATE phys_bytes user_phys;	/* physical address of remainder of user buf */
PRIVATE TPPrPort pport;		/* printer graf port */
PRIVATE THPrint hPrint;		/* printer handle */
PRIVATE message print_mess;	/* buffer for all incoming messages */
PRIVATE FontInfo finfo;		/* printer font info */
PRIVATE TPrStatus pstat;	/* printer status */
PRIVATE int lperpage = 66;	/* lines per page */
PRIVATE int line;		/* current line number */
PRIVATE int printing;		/* doc is currently open */
PRIVATE Rect prect;		/* printint rectangle */

FORWARD _PROTOTYPE( void do_write, ( message *m_ptr ) );
FORWARD _PROTOTYPE( void do_cancel, ( message *m_ptr ) );
FORWARD _PROTOTYPE( void reply, ( int code , int replyee , int process , int status ) );
FORWARD _PROTOTYPE( void pr_error, ( int status ) );
FORWARD _PROTOTYPE( int opendoc, ( void ) );
FORWARD _PROTOTYPE( void newpage, ( void ) );
FORWARD _PROTOTYPE( void resettimer, ( void ) );
FORWARD _PROTOTYPE( void timeout, ( void ) );

/*===========================================================================*
 *				printer_task				     *
 *===========================================================================*/
PUBLIC void printer_task()
{
/* Main routine of the printer task. */

  hPrint = (THPrint) NewHandle( (long) sizeof (TPrint));
  if (hPrint == 0) {
    printf("Unable to allocate printer handle\r\n");
    printf("You won't be able to print\r\n");
  }
  else {
    PrOpen();
    if (PrintErr == 0) {
    	PrintDefault(hPrint);
    	PrClose();
    }
    else
	pr_error(PrintErr);
  }

  while (TRUE) {
	receive(ANY, &print_mess);
	switch(print_mess.m_type) {
#ifndef DEMO
	    case TTY_WRITE:	do_write(&print_mess);	break;
	    case CANCEL   :	do_cancel(&print_mess);	break;
	    case SET_ALARM:	closedoc();		break;
#endif
	    default:		reply(TASK_REPLY, print_mess.m_source,
				      print_mess.PROC_NR, EINVAL);
							break;
	}
  }
}


/*===========================================================================*
 *				opendoc				     	     *
 *===========================================================================*/
PRIVATE int opendoc()
{
  if (hPrint == 0) return;
  if (printing == FALSE) {
  	PrOpen();
  	prect = (**hPrint).prInfo.rPage;
  	pport = PrOpenDoc(hPrint, 0L, 0L);
	printing = TRUE;
	if (PrintErr != 0)
		return EIO;
	else {
		SetPort(pport);
		line = 1;
		newpage();
	}
  }
  else 
	SetPort(pport);
  return OK;
}


/*===========================================================================*
 *				closedoc				     	     *
 *===========================================================================*/
closedoc()
{
  GrafPtr sp;
  if (printing == TRUE) {
	GetPort(&sp);
	SetPort(pport);
  	PrClosePage(pport);
  	PrCloseDoc(pport);
  	if ((**hPrint).prJob.bJDocLoop == bSpoolLoop)
		PrPicFile(hPrint, 0L, 0L, 0L, &pstat);
  	PrClose();
   	printing = FALSE;
	SetPort(sp);
   }
}


/*===========================================================================*
 *				newpage				     	     *
 *===========================================================================*/
PRIVATE void newpage()
{
  if (hPrint == 0) return;
  if (line > lperpage) 
	PrClosePage(pport);
  PrOpenPage(pport, 0L);
  TextFont(PFONT);
  TextSize(PSIZE);
  GetFontInfo(&finfo);
  lperpage = 66;
  MoveTo(prect.left+LEFTMARGIN, LINE(1));
  line = 1;
}

/*===========================================================================*
 *				do_write				     *
 *===========================================================================*/
PRIVATE void do_write(m_ptr)
register message *m_ptr;	/* pointer to the newly arrived message */
{
/* The printer is used by sending TTY_WRITE messages to it. Process one. */
  int cum;
  GrafPtr sp;
  int r;

  r = OK;

  /* Reject command if no print handle or count is not positive. */
  user_phys = numap(m_ptr->PROC_NR, (vir_bytes) m_ptr->ADDRESS, (vir_bytes) m_ptr->COUNT);
  if (user_phys == 0)  r = E_BAD_ADDR;
  if (hPrint == 0) r = EIO;
  if (m_ptr->COUNT <= 0) r = EINVAL;

  if (r == OK) {
	GetPort(&sp);
	cum = 0;
        if (opendoc() == OK)
	  do {
        	if (line > lperpage) 
	    		newpage();
		switch (*(char *)user_phys) {
		  case '\r':
	    		MoveTo(prect.left+LEFTMARGIN, LINE(line));
			break;
		  case '\n':
			++line;
	    		MoveTo(pport->gPort.pnLoc.h, LINE(line));
			break;
		  default:
			DrawChar(*(char *)user_phys);
			break;
		}
		++user_phys;
		++cum;
	  } while (--m_ptr->COUNT > 0 && PrintErr == 0);
  	if (PrintErr != 0) {
		pr_error(PrintErr);
		r = EIO;
		closedoc();
  	}
	else {
		r = cum;
		resettimer(); 
	}
        SetPort(sp);
  }

 done:
  /* Reply to FS, no matter what happened. */
  reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, r);
}


/*===========================================================================*
 *				timeout				     	     *
 *===========================================================================*/
PRIVATE void timeout()
{
  message m;
  m.m_type = SET_ALARM;
  send(PRINTER, &m);
}


/*===========================================================================*
 *				resettimer				     *
 *===========================================================================*/
PRIVATE void resettimer()
{
  message m;
  m.m_type = SET_ALARM;
  m.CLOCK_PROC_NR = PRINTER;
  m.DELTA_TICKS = 3 * 60;
  m.FUNC_TO_CALL = timeout;
  sendrec(CLOCK, &m);
}


/*===========================================================================*
 *				do_cancel				     *
 *===========================================================================*/
PRIVATE void do_cancel(m_ptr)
register message *m_ptr;	/* pointer to the newly arrived message */
{
/* Cancel a print request that has already started.  Usually this means that
 * the process doing the printing has been killed by a signal.
 */
  reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, EINTR);
}


/*===========================================================================*
 *				reply					     *
 *===========================================================================*/
PRIVATE void reply(code, replyee, process, status)
int code;			/* TASK_REPLY or REVIVE */
int replyee;			/* destination for message (normally FS) */
int process;			/* which user requested the printing */
int status;			/* number of  chars printed or error code */
{
/* Send a reply telling FS that printing has started or stopped. */

  message pr_mess;
  pr_mess.m_type = code;	/* TASK_REPLY or REVIVE */
  pr_mess.REP_STATUS = status;	/* count or EIO */
  pr_mess.REP_PROC_NR = process;	/* which user does this pertain to */
  send(replyee, &pr_mess);	/* send the message */
}


/*===========================================================================*
 *				docsetup				     *
 *===========================================================================*/
PUBLIC void docsetup()
{
  if (hPrint == 0 || printing == TRUE) return;
  PrOpen();
  PrStlDialog(hPrint);
  PrClose();
}


/*===========================================================================*
 *				jobsetup				     *
 *===========================================================================*/
PUBLIC void jobsetup()
{
  static int warned = 0;

  if (hPrint == 0 || printing == TRUE) return;
  PrOpen();
  if (warned == 0) {
    ParamText("Note that making changes here will effect every print job",
	      " sent to the line printer!", "", "");
    CautionAlert(128, 0L);
    warned = 1;
  }
  PrJobDialog(hPrint);
  PrClose();
}


/*===========================================================================*
 *				pr_error				     *
 *===========================================================================*/
PRIVATE void pr_error(status)
int status;
{
/* The printer is not ready.  Display a message on the console telling why. */

   printf("Printer error: ");
   switch (status) {
	case -4101: printf("Printer not found"); break;
	case -1:    printf("Error saving print file"); break;
	case -27:   printf("I/O Error"); break; /* very helpful */
	case -108:  printf("Not enough room in heap"); break;
	case  128:  printf("User abort"); break;
	default:    printf("Unknown error code %d", status); break;
   }
   printf("\r\n");
}
