/* This file contains the terminal driver, both for the IBM console and regular
 * ASCII terminals.  It is split into two sections, a device-independent part
 * and a device-dependent part.  The device-independent part accepts
 * characters to be printed from programs and queues them in a standard way
 * for device-dependent output.  It also accepts input and queues it for
 * programs. This file contains 2 main entry points: tty_task() and keyboard().
 * When a key is struck on a terminal, an interrupt to an assembly language
 * routine is generated.  This routine saves the machine state and registers
 * and calls keyboard(), which enters the character in an internal table, and
 * then sends a message to the terminal task.  The main program of the terminal
 * task is tty_task(). It accepts not only messages about typed input, but
 * also requests to read and write from terminals, etc.
 *
 * The device-dependent part interfaces with the IBM console and ASCII
 * terminals.  The IBM keyboard is unusual in that keystrokes yield key numbers
 * rather than ASCII codes, and furthermore, an interrupt is generated when a
 * key is depressed and again when it is released.  The IBM display is memory
 * mapped, so outputting characters such as line feed, backspace and bell are
 * tricky.
 *
 * The valid messages and their parameters are:
 *
 *   HARD_INT:     output has been completed or input has arrived
 *   TTY_READ:     a process wants to read from a terminal
 *   TTY_WRITE:    a process wants to write on a terminal
 *   TTY_IOCTL:    a process wants to change a terminal's parameters
 *   TTY_SETPGRP:  indicate a change in a control terminal
 *   CANCEL:       terminate a previous incomplete system call immediately
 *
 *    m_type      TTY_LINE   PROC_NR    COUNT   TTY_SPEK  TTY_FLAGS  ADDRESS
 * |-------------+---------+---------+---------+---------+---------+---------|
 * | HARD_INT    |         |         |         |         |         |         |
 * |-------------+---------+---------+---------+---------+---------+---------|
 * | TTY_READ    |minor dev| proc nr |  count  |         |         | buf ptr |
 * |-------------+---------+---------+---------+---------+---------+---------|
 * | TTY_WRITE   |minor dev| proc nr |  count  |         |         | buf ptr |
 * |-------------+---------+---------+---------+---------+---------+---------|
 * | TTY_IOCTL   |minor dev| proc nr |func code|erase etc|  flags  |         |
 * |-------------+---------+---------+---------+---------+---------+---------|
 * | TTY_SETPGRP |minor dev| proc nr |         |         |         |         |
 * |-------------+---------+---------+---------+---------+---------+---------
 * | CANCEL      |minor dev| proc nr |         |         |         |         |
 * ---------------------------------------------------------------------------
 */

#include "kernel.h"
#include <sgtty.h>
#include <signal.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include "tty.h"

/* Array and macros to convert line numbers to structure pointers. */
PRIVATE struct tty_struct *p_tty_addr[NR_CONS + NR_RS_LINES];
#define ctty_addr(line) (&tty_struct[(line)])	/* faster if line is const */
#define tty_addr(line)  (p_tty_addr[(line)])

/* Macros for magic tty types. */
#define isconsole(tp) ((tp) < ctty_addr(NR_CONS))
#define isrs232(tp)   ((tp) >= ctty_addr(NR_CONS))

/* Macros for magic tty line numbers. */
#define isttyline(line) ((unsigned) (line) < NR_CONS + NR_RS_LINES)

/* Macros for magic tty structure pointers. */
#define FIRST_TTY (ctty_addr(0))
#define END_TTY   (ctty_addr(NR_CONS + NR_RS_LINES))

/* Miscellaneous. */
#define LF        '\012'	/* '\n' is not portablly a LF */

/* Test-and-set flag, set during tty_wakeup().  Remains set if do_int() is
 * scheduled until do_int() is finished.
 */
PUBLIC  int tty_awake;
PRIVATE int saved = FALSE;
PRIVATE message save_mess;

FORWARD _PROTOTYPE( void do_int, ( void ) );
FORWARD _PROTOTYPE( void in_char, ( struct tty_struct *tp, char ch ) );
FORWARD _PROTOTYPE( void echo, ( struct tty_struct *tp, char c ) );
FORWARD _PROTOTYPE( int chuck, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void do_read, ( struct tty_struct *tp, message *m_ptr ) );
FORWARD _PROTOTYPE( int rd_chars, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void do_write, ( struct tty_struct *tp, message *m_ptr ) );
FORWARD _PROTOTYPE( void do_ioctl, ( struct tty_struct *tp, message *m_ptr ) );
FORWARD _PROTOTYPE( void do_setpgrp, ( struct tty_struct *tp, message *m_ptr ) );
FORWARD _PROTOTYPE( void do_cancel, ( struct tty_struct *tp, message *m_ptr ) );
FORWARD _PROTOTYPE( void tty_reply, ( int code, int replyee, int proc_nr, int status ) );
FORWARD _PROTOTYPE( void back_over, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void in1_char, ( struct tty_struct *tp, char ch, char echoch ) );
FORWARD _PROTOTYPE( int out_process, ( struct tty_struct *tp, char *ubuf, int ucount ) );
FORWARD _PROTOTYPE( void rs_start, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void tty_icancel, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void tty_init, ( void ) );
FORWARD _PROTOTYPE( void tty_ocancel, ( struct tty_struct *tp ) );
FORWARD _PROTOTYPE( void uninhibit, ( struct tty_struct *tp ) );

/*===========================================================================*
 *				tty_task				     *
 *===========================================================================*/
PUBLIC void tty_task()
{
/* Main routine of the terminal task. */

  message tty_mess;		/* buffer for all incoming messages */
  register struct tty_struct *tp;

  tty_init();
  while (TRUE) {
	receive(ANY, &tty_mess);
	if (!isttyline(tty_mess.TTY_LINE)) {
		tty_mess.m_type = -1;	/* force error */
		tty_mess.TTY_LINE = 0;	/* so hardware ints can get through */
	}
	tp = tty_addr(tty_mess.TTY_LINE);
	switch(tty_mess.m_type) {
	    case HARD_INT:	do_int();			break;
	    case TTY_READ:	do_read(tp, &tty_mess);		break;
	    case TTY_WRITE:	do_write(tp, &tty_mess);	break;
	    case TTY_IOCTL:	do_ioctl(tp, &tty_mess);	break;
	    case TTY_SETPGRP:   do_setpgrp(tp, &tty_mess);	break;
	    case CANCEL:	do_cancel(tp, &tty_mess);	break;
	    default:		tty_reply(TASK_REPLY, tty_mess.m_source,
					  tty_mess.PROC_NR, EINVAL);
	}
	if (saved == TRUE && tty_mess.m_source == save_mess.m_source) {
	    saved = FALSE;
	    tty_reply(save_mess.m_type, save_mess.m_source,
			  save_mess.REP_PROC_NR, save_mess.REP_STATUS);
        }
  }
}


/*===========================================================================*
 *				do_int					     *
 *===========================================================================*/
PRIVATE void do_int()
{
/* The TTY task can generate two kinds of interrupts:
 *	- a character has been received from the console or an RS232 line.
 *	- an RS232 line has completed a write request (on behalf of a user).
 * The interrupt handler may delay the interrupt message at its discretion
 * to avoid swamping the TTY task.  Messages may be overwritten when the
 * lines are fast or when there are races between different lines, input
 * and output, because MINIX only provides single buffering for interrupt
 * messages (in proc.c).  This is handled by explicitly checking each line
 * for fresh input and completed output on each interrupt.  Input is given
 * priority so signal characters are not delayed by lots of small output
 * requests.  This does not signifigantly delay the detection of output
 * completions, since TTY will be scheduled to handle the output before
 * any new user can request input.
 *
 * If a reply is sent (to FS), further input/output must not be processed
 * for fear of sending a second message to FS, which would be lost under
 * certain race conditions.  E.g. when FS is now ready and is about to
 * sendrec() to TTY (usually from rw_dev()).  FS handles the deadlock
 * resulting from the _first_ send() from TTY clashing with the sendrec()
 * from FS.  But then the scheduling causes the retried sendrec() to get
 * through, so the second send() fails with an E_LOCKED error.  This might
 * be avoided by preempting tasks like TTY over servers like FS, or giving
 * preference to senders over receivers.  In practice, TTY relies on being
 * woken at a later clock tick.
 */

  char *buf;
  static struct tty_struct *last_tp = FIRST_TTY;  /* round-robin service */
  unsigned char odone;
  register char *rbuf;
  unsigned remaining;
  register struct tty_struct *tp;
  unsigned wrapcount;

  tp = last_tp;
  do {
	if (++tp >= END_TTY) tp = FIRST_TTY;

	/* Transfer any fresh input to TTY's buffer, and test output done. */
	remaining = (*tp->tty_devread)(tp->tty_line, &buf, &odone);
	if (remaining == 0)
		goto check_output;	/* avoid even uglier indentation */

	rbuf = buf;
	if (!isconsole(tp) && tp->tty_mode & RAW) {
		/* Avoid grotesquely inefficient in_char(), except for console
		 * which needs further translation.
		 * Line feeds need not be counted.
		 */

		/* If queue becomes too full, ask external device to stop. */
		if (tp->tty_incount < tp->tty_ihighwater &&
		    tp->tty_incount + remaining >= tp->tty_ihighwater)
			rs_istop(tp->tty_line);

		if (remaining > tp->tty_insize - tp->tty_incount)
			/* not all fit, discard */
			remaining = tp->tty_insize - tp->tty_incount;
		wrapcount = tp->tty_inbufend - tp->tty_inhead;
		if (wrapcount < remaining) {
			memcpy(tp->tty_inhead, rbuf, wrapcount);
			tp->tty_inhead = tp->tty_inbuf;
			rbuf += wrapcount;
			tp->tty_incount += wrapcount;
			remaining -= wrapcount;
		}
		memcpy(tp->tty_inhead, rbuf, remaining);
		tp->tty_inhead += remaining;
		tp->tty_incount += remaining;
	} else {
		do
			in_char(tp, *rbuf++);
		while (--remaining != 0);
	}

	/* Possibly restart output (in case there were xoffs or echoes). */
	(*tp->tty_devstart)(tp);

	/* See if a previously blocked reader can now be satisfied. */
	if (tp->tty_inleft != 0 && tp->tty_incount != 0 &&
	    (tp->tty_mode & (RAW | CBREAK) || tp->tty_lfct != 0)) {
		/* Tell hanging reader that chars have arrived. */
		tty_reply(REVIVE, (int) tp->tty_incaller,
			  (int) tp->tty_inproc, rd_chars(tp));
	}

check_output:
        /* maybe continue output */
	if (isconsole(tp) && tp->tty_outleft > 0)
		(*tp->tty_devstart)(tp);
	/* Finish off any completed block of output. */
	if (odone) {
		if (tp->tty_rwords > 0) {
			/* not echo */
			tp->tty_phys += tp->tty_rwords;
			tp->tty_cum += tp->tty_rwords;
			tp->tty_outleft -= tp->tty_rwords;
			if (tp->tty_outleft == 0) {
				finish(tp, tp->tty_cum);
				continue;
			}
		}
		tp->tty_rwords = 0;
		rs_ocancel(tp->tty_line);	/* tty_ocancel does too much*/
		(*tp->tty_devstart)(tp);	/* maybe continue output */
	}
  }
  while (tp != last_tp || tty_events >= EVENT_THRESHOLD);
  tty_awake = FALSE;
  last_tp = tp;
}


/*===========================================================================*
 *				in_char					     *
 *===========================================================================*/
PRIVATE void in_char(tp, ch)
register struct tty_struct *tp;	/* terminal on which char arrived */
register char ch;		/* scan code for character that arrived */
{
/* A character has just been typed in.  Process, save, and echo it. */

  int mode, sig, scode, c;
  char *ecode, *letter_code();

  scode = ch;			/* save the scan code */

  /* Function keys are temporarily being used for debug dumps. */
  if (isconsole(tp) && func_key(ch))
	return;			/* just processed function key */
  mode = tp->tty_mode & (RAW | CBREAK);
  if (tp->tty_makebreak == TWO_INTS) {
	c = make_break(ch);	/* console give 2 ints/ch */
	if (c == -1) return;
	ch = c;
  } else if (mode != RAW)
	ch &= 0177;		/* 7-bit chars except in raw mode */

  /* Processing for COOKED and CBREAK mode contains special checks. */
  if (mode == COOKED || mode == CBREAK) {
	/* Handle erase, kill and escape processing. */
	if (mode == COOKED) {
		/* First erase processing (rub out of last character). */
		if (ch == tp->tty_erase) {
			if (tp->tty_escaped == ESCAPED || chuck(tp) != -1) {
				/* Removed it from buffer OK. */
				tp->tty_escaped = NOT_ESCAPED;
				back_over(tp);	/* remove from screen too */
			}
			return;
		}

		/* Now do kill processing (remove current line). */
		if (ch == tp->tty_kill && tp->tty_escaped == NOT_ESCAPED) {
			while(chuck(tp) == OK)	/* keep looping */ ;
			echo(tp, tp->tty_kill);
			echo(tp, '\n');
			return;
		}

		/* Handle EOT and the escape symbol (backslash). */
		if (tp->tty_escaped == NOT_ESCAPED) {
			/* Normal case: previous char was not backslash. */
			if (ch == '\\') {
				/* An escaped symbol has just been typed. */
				tp->tty_escaped = ESCAPED;
				echo(tp, ch);
				return;	/* do not store the '\' */
			}
			/* CTRL-D means end-of-file, unless it is escaped. It
			 * is stored in the text as MARKER, and counts as a
			 * line feed in terms of knowing whether a full line
			 * has been typed already.
			 */
			if (ch == tp->tty_eof) {
				ch = MARKER;
				if (tp->tty_incount < tp->tty_insize)
					tp->tty_lfct++;	/* counts as LF */
			}
		} else {
			/* Previous character was backslash. */
			tp->tty_escaped = NOT_ESCAPED;	/* turn escaping off */
			back_over(tp);	/* to overwrite or re-echo */
			if (ch != tp->tty_erase && ch != tp->tty_kill &&
			    ch != tp->tty_eof)
				/* Store the escape previously skipped over */
				in1_char(tp, '\\', '\\');
		}
	}
	/* Both COOKED and CBREAK modes come here; first map CR to LF. */
	if (ch == '\r' && (tp->tty_mode & CRMOD)) ch = '\n';

	/* Check for interrupt and quit characters. */
	if (ch == tp->tty_intr || ch == tp->tty_quit) {
		sig = (ch == tp->tty_intr ? SIGINT : SIGQUIT);
		sigchar(tp, sig);
		return;
	}

	/* Check for and process CTRL-S (terminal stop). */
	if (ch == tp->tty_xoff) {
		tp->tty_inhibited = STOPPED;
		if (isrs232(tp))
			rs_inhibit(tp->tty_line, TRUE);	/* sync avoid races */
		return;
	}

	/* Check for and process terminal start character, now anything. */
	if (tp->tty_inhibited == STOPPED) uninhibit(tp);

	/* Check for and discard xon (terminal start). */
	if (ch == tp->tty_xon) return;
  }

  /* All 3 modes come here. */
  if (ch == '\n' && tp->tty_incount < tp->tty_insize)
	tp->tty_lfct++;		/* count line feeds */

  /* The numeric pad generates ASCII escape sequences: ESC [ letter */
  if (isconsole(tp) && (ecode = letter_code(scode)) != 0) {
	/* This key is to generate an escape sequence. */
	while (*ecode) {
		if (*ecode == ESC)
			in1_char(tp, ESC, 'E');
		else
  			in1_char(tp, *ecode, *ecode);
  		ecode++;
	}
  }
  else
  	in1_char(tp, ch, ch);
}


/*===========================================================================*
 *				echo					     *
 *===========================================================================*/
PRIVATE void echo(tp, c)
register struct tty_struct *tp;	/* terminal on which to echo */
register char c;		/* character to echo */
{
/* Echo a character on the terminal. */

  if ( (tp->tty_mode & ECHO) == 0) return;	/* if no echoing, don't echo */
/* MARKER is meaningful only in cooked mode */
  if (c != MARKER || tp->tty_mode & (CBREAK | RAW)) {
	if (isconsole(tp)) {
		out_char(tp, c);	/* echo to console */
		flush(tp);		/* force character out onto screen */
	} else if (tp->tty_etail < tp->tty_ebufend)
		*tp->tty_etail++ = c;	/* echo to RS232 line */
  }
}


/*===========================================================================*
 *				chuck					     *
 *===========================================================================*/
PRIVATE int chuck(tp)
register struct tty_struct *tp;	/* from which tty should chars be removed */
{
/* Delete one character from the input queue.  Used for erase and kill. */

  char *prev;

  /* If input queue is empty, don't delete anything. */
  if (tp->tty_incount == 0) return(-1);

  /* Don't delete '\n' or '\r'. */
  prev = (tp->tty_inhead != tp->tty_inbuf ? tp->tty_inhead - 1 :
					    tp->tty_inbufend - 1);
  if (*prev == '\n' || *prev == '\r') return(-1);
  tp->tty_inhead = prev;

  /* If queue becomes empty enough, tell external device it can start. */
  if (--tp->tty_incount == tp->tty_ilow_water && isrs232(tp))
	rs_istart(tp->tty_line);
  return(OK);			/* char erasure was possible */
}


/*===========================================================================*
 *				do_read					     *
 *===========================================================================*/
PRIVATE void do_read(tp, m_ptr)
register struct tty_struct *tp;
message *m_ptr;			/* pointer to message sent to the task */
{
/* A process wants to read from a terminal. */

  if (tp->tty_inleft > 0) {	/* if someone else is hanging, give up */
	tty_reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, EIO);
	return;
  }

  /* Copy information from the message to the tty struct. */
  tp->tty_incaller = m_ptr->m_source;
  tp->tty_inproc = m_ptr->PROC_NR;
  tp->tty_in_vir = m_ptr->ADDRESS;
  tp->tty_inleft = m_ptr->COUNT;

  /* Try to get chars.  This call either gets enough, or gets nothing. */
  tty_reply(TASK_REPLY, m_ptr->m_source, (int) tp->tty_inproc, rd_chars(tp));
}


/*===========================================================================*
 *				rd_chars				     *
 *===========================================================================*/
PRIVATE int rd_chars(tp)
register struct tty_struct *tp;	/* pointer to terminal to read from */
{
/* A process wants to read from a terminal.  First check if enough data is
 * available. If so, pass it to the user.  If not, send FS a message telling
 * it to suspend the user.  When enough data arrives later, the tty driver
 * copies it to the user space directly and notifies FS with a message.
 */

  char *bufend;
  int ct;
  register char *rtail;
  int user_ct;
  int user_cum;
  phys_bytes user_phys;

  if (tp->tty_incount == 0 ||
      !(tp->tty_mode & (RAW | CBREAK)) && tp->tty_lfct == 0)
	return(SUSPEND);
  if ( (user_phys = numap(tp->tty_inproc, (vir_bytes) tp->tty_in_vir,
                          (vir_bytes) tp->tty_inleft)) == 0)
	return(E_BAD_ADDR);
  if (tp->tty_inleft > tp->tty_incount) tp->tty_inleft = tp->tty_incount;
  user_cum = 0;

  do {
	rtail = tp->tty_intail;
	if ( (ct = tp->tty_inleft) > tp->tty_inbufend - rtail)
		ct = tp->tty_inbufend - rtail;

	/* Be careful about CTRL-D.  In cooked
	 * mode it is not transmitted to user programs, and is not counted as
	 * a character as far as the count goes, but it does occupy space in
	 * the driver's tables and must be counted there.
	 */
	user_ct = ct;
	if (!(tp->tty_mode & (RAW | CBREAK))) {
		/* COOKED mode.
		 * Don't bother counting lines in CBREAK and RAW modes.
		 */
		for (bufend = rtail + ct; rtail < bufend;) {
			if (*rtail++ == '\n') {
				user_ct =
					tp->tty_inleft =
					ct = rtail - tp->tty_intail;
				tp->tty_lfct--;;
				break;
			}
			if (rtail[-1] == MARKER) {
				tp->tty_inleft =
					ct = rtail - tp->tty_intail;
					user_ct = ct - 1;
				tp->tty_lfct--;
				break;
			}
		}
	}

	/* Copy at least half of buffer to user space. */
	phys_copy(tp->tty_inphys + (tp->tty_intail - tp->tty_inbuf),
		  user_phys, (phys_bytes) user_ct);
	user_phys += user_ct;
	user_cum += user_ct;
	if ( (tp->tty_intail += ct) == tp->tty_inbufend)
		tp->tty_intail = tp->tty_inbuf;
	tp->tty_inleft -= ct;
	if ( (tp->tty_incount -= ct) <= tp->tty_ilow_water &&
	     tp->tty_incount + ct > tp->tty_ilow_water && isrs232(tp))
		rs_istart(tp->tty_line);
  }
  while (tp->tty_inleft != 0);
  return(user_cum);
}


/*===========================================================================*
 *				finish					     *
 *===========================================================================*/
PUBLIC void finish(tp, code)
register struct tty_struct *tp;
int code;			/* reply code */
{
/* A command has terminated (possibly due to DEL).  Tell caller. */

  if (tp->tty_waiting != NOT_WAITING)
{
	tty_reply(tp->tty_waiting == SUSPENDED ? REVIVE : TASK_REPLY,
		  (int) tp->tty_otcaller, (int) tp->tty_outproc, code);
tp->tty_outproc = -1;
}
  tty_ocancel(tp);
}


/*===========================================================================*
 *				do_write				     *
 *===========================================================================*/
PRIVATE void do_write(tp, m_ptr)
register struct tty_struct *tp;
register message *m_ptr;	/* pointer to message sent to the task */
{
/* A process wants to write on a terminal. */

  vir_bytes out_vir, out_left;

  /* If the slot is already in use, better return an error than mess it up. */
  if (tp->tty_outleft > 0) {	/* if someone else is hanging, give up */
	tty_reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, EIO);
	return;
  }

  /* Copy message parameters to the tty structure. */
  tp->tty_otcaller = m_ptr->m_source;
  tp->tty_outproc = m_ptr->PROC_NR;
  tp->tty_out_vir = m_ptr->ADDRESS;
  tp->tty_outleft = m_ptr->COUNT;

  /* Compute the physical address where the data is in user space. */
  out_vir = (vir_bytes) tp->tty_out_vir;
  out_left = (vir_bytes) tp->tty_outleft;
  if ( (tp->tty_phys = numap(tp->tty_outproc, out_vir, out_left)) == 0) {
	/* Buffer address provided by user is outside its address space. */
	tp->tty_outleft = 0;
	tty_reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, E_BAD_ADDR);
	return;
  }

  /* Everything is OK.  Fill in remaining tty fields.  Only tty_waiting is
   * critical - it must be held at NOT_WAITING together with tty_outleft == 0
   * for the error cases.
   */
  tp->tty_cum = 0;
  tp->tty_waiting = WAITING;

  /* Copy characters from the user process to the terminal. */
  (*tp->tty_devstart)(tp);	/* copy data to queue and start I/O */

  /* If output is for a bitmapped terminal as the IBM-PC console, the output-
   * routine will return at once so there is no need to suspend the caller,
   * on ascii terminals however, the call is suspended and later revived.
   * Oops, even bitmapped terminals need suspension after an XOFF.
   */
  if (tp->tty_outleft > 0) {
	tty_reply(TASK_REPLY, (int) tp->tty_otcaller, (int) tp->tty_outproc,
		  SUSPEND);
	tp->tty_waiting = SUSPENDED;
  }
}


/*===========================================================================*
 *				do_ioctl				     *
 *===========================================================================*/
PRIVATE void do_ioctl(tp, m_ptr)
register struct tty_struct *tp;
message *m_ptr;			/* pointer to message sent to task */
{
/* Perform IOCTL on this terminal. */

  long flags, erki, erase, kill, intr, quit, xon, xoff, eof;
  int r;
  int speed;
  message ioctl_mess;

  r = OK;
  flags = 0;
  erki = 0;
  switch(m_ptr->TTY_REQUEST) {
     case TIOCSETP:
	/* Set erase, kill, and flags. */
	tp->tty_erase = (char) ((m_ptr->TTY_SPEK >> 8) & BYTE);	/* erase  */
	tp->tty_kill  = (char) ((m_ptr->TTY_SPEK >> 0) & BYTE);	/* kill  */
	tp->tty_mode  = (int) m_ptr->TTY_FLAGS & 0xFFFF;	/* mode word*/
	if (!(tp->tty_mode & (RAW | CBREAK))) {
		/* (Re)calculate the line count. The logic of rd_chars()
		 * requires newlines and MARKERs returned in cooked mode
		 * to be interpreted as line ends, even if they were
		 * received in another mode.
		 */
		int ct;
		register char *rtail;

		tp->tty_lfct = 0;
		for (rtail = tp->tty_intail, ct = tp->tty_incount;
		     ct-- != 0;) {
			if (*rtail == '\n' || *rtail == MARKER)
				++tp->tty_lfct;
			if (++rtail == tp->tty_inbufend)
				rtail = tp->tty_inbuf;
		}
		/* The column should really be recalculated for RS232, but
		 * is too much trouble.
		 */
	}
	if (tp->tty_mode & RAW)
		/* Inhibited RAW mode makes no sense since there is no way
		 * to uninhibit it. The inhibition flag must be cleared
		 * explicitly since the drivers check it in all modes.
		 */
		uninhibit(tp);
	speed = (int) (m_ptr->TTY_SPEK >> 16);
	if (speed != 0) tp->tty_speed = speed;
	if (isrs232(tp)) tp->tty_speed = rs_ioctl(tp->tty_line, tp->tty_mode,
						  tp->tty_speed);
	break;

     case TIOCSETC:
	/* Set intr, quit, xon, xoff, eof (brk not used). */
	tp->tty_intr = (char) ((m_ptr->TTY_SPEK >> 24) & BYTE);	/* interrupt */
	tp->tty_quit = (char) ((m_ptr->TTY_SPEK >> 16) & BYTE);	/* quit */
	tp->tty_xon  = (char) ((m_ptr->TTY_SPEK >>  8) & BYTE);	/* CTRL-S */
	tp->tty_xoff = (char) ((m_ptr->TTY_SPEK >>  0) & BYTE);	/* CTRL-Q */
	tp->tty_eof  = (char) ((m_ptr->TTY_FLAGS >> 8) & BYTE);	/* CTRL-D */
	if (isrs232(tp)) rs_setc(tp->tty_line, tp->tty_xoff, tp->tty_xon);
	break;

     case TIOCGETP:
	/* Get erase, kill, and flags. */
	erase = ((long) tp->tty_erase) & BYTE;
	kill  = ((long) tp->tty_kill) & BYTE;
	erki  = ((long) tp->tty_speed << 16) | (erase << 8) | kill;
	flags =  (long) tp->tty_mode;
	break;

     case TIOCGETC:
	/* Get intr, quit, xon, xoff, eof. */
	intr  = ((long) tp->tty_intr) & BYTE;
	quit  = ((long) tp->tty_quit) & BYTE;
	xon   = ((long) tp->tty_xon)  & BYTE;
	xoff  = ((long) tp->tty_xoff) & BYTE;
	eof   = ((long) tp->tty_eof)  & BYTE;
	erki  = (intr << 24) | (quit << 16) | (xon << 8) | (xoff << 0);
	flags = (eof <<8);
	break;

#ifdef TIOCFLUSH
     case TIOCFLUSH:
	/* Discard current input and output. */
	tty_icancel(tp);
	tty_ocancel(tp);
	break;
#endif
  }

  /* Send the reply. Like tty_reply() with extra arguments flags and erki. */
  ioctl_mess.m_type = TASK_REPLY;
  ioctl_mess.REP_PROC_NR = m_ptr->PROC_NR;
  ioctl_mess.REP_STATUS = r;
  ioctl_mess.TTY_FLAGS = flags;
  ioctl_mess.TTY_SPEK = erki;
  send(m_ptr->m_source, &ioctl_mess);
}


/*===========================================================================*
 *				do_setpgrp				     *
 *===========================================================================*/
PRIVATE void do_setpgrp(tp, m_ptr)
register struct tty_struct *tp;
message *m_ptr;			/* pointer to message sent to task */
{
/* A control process group has changed */

  tp->tty_pgrp = m_ptr->TTY_PGRP;
  tty_reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, OK);
}


/*===========================================================================*
 *				do_cancel				     *
 *===========================================================================*/
PRIVATE void do_cancel(tp, m_ptr)
register struct tty_struct *tp;
message *m_ptr;			/* pointer to message sent to task */
{
/* A signal has been sent to a process that is hanging trying to read or write.
 * The pending read or write must be finished off immediately.
 */

  int caller;
  int mode;

  /* Check the parameters carefully, to avoid cancelling twice, but don't
   * generate error replies since it is normal for sigchar() to have
   * already done the cancellation.
   */
  caller = m_ptr->PROC_NR;
  mode = m_ptr->COUNT;
  if (mode & R_BIT && tp->tty_inleft != 0 && caller == tp->tty_inproc) {
	/* Process was reading when killed.  Clean up input. */
	tty_icancel(tp);
	tp->tty_inleft = 0;
  }
  if (mode & W_BIT && tp->tty_outleft != 0 && caller == tp->tty_outproc)
	/* Process was writing when killed.  Clean up output. */
	tty_ocancel(tp);
  tty_reply(TASK_REPLY, m_ptr->m_source, m_ptr->PROC_NR, EINTR);
}


/*===========================================================================*
 *				tty_reply				     *
 *===========================================================================*/
PRIVATE void tty_reply(code, replyee, proc_nr, status)
int code;			/* TASK_REPLY or REVIVE */
int replyee;			/* destination address for the reply */
int proc_nr;			/* to whom should the reply go? */
int status;			/* reply code */
{
/* Send a reply to a process that wanted to read or write data. */

  message tty_mess;

  tty_mess.m_type = code;
  tty_mess.REP_PROC_NR = proc_nr;
  tty_mess.REP_STATUS = status;
  status = send(replyee, &tty_mess);

  if (status == ELOCKED) {
	/* FS is currently sending request to us, so 
	  first respond to that message and then send this result */
	saved = TRUE;
	save_mess = tty_mess;
	save_mess.m_source = replyee;			/* cheat */
   }
   else if (status != OK)
	printf("\r\ntty_reply failed with status %d\r\n", status);
}


/*===========================================================================*
 *				sigchar					     *
 *===========================================================================*/
PUBLIC void sigchar(tp, sig)
register struct tty_struct *tp;
int sig;			/* SIGINT, SIGQUIT, or SIGKILL */
{
/* Process a SIGINT, SIGQUIT or SIGKILL char from the keyboard */

  uninhibit(tp);		/* do implied CRTL-Q */
  finish(tp, EINTR);		/* reply and/or cancel output if necessary */
  tty_icancel(tp);
  if (tp->tty_pgrp) cause_sig(tp->tty_pgrp, sig);
}


/*==========================================================================*
 *				back_over				    *
 *==========================================================================*/
PRIVATE void back_over(tp)
register struct tty_struct *tp;
{
/* Backspace to previous character on screen and erase it. */

  echo(tp, '\b');
  echo(tp, ' ');
  echo(tp, '\b');
}


/*==========================================================================*
 *				in1_char				    *
 *==========================================================================*/
PRIVATE void in1_char(tp, ch, echoch)
register struct tty_struct *tp;
char ch;			/* character to be queued */
char echoch;			/* character to be echoed */
{
/* Put character in terminal input queue without preprocessing, and echo. */

  if (tp->tty_incount >= tp->tty_insize)
	return;			/* no room, discard char */
  *tp->tty_inhead++ = ch;	/* save the character in the input queue */
  if (tp->tty_inhead == tp->tty_inbufend)
	tp->tty_inhead = tp->tty_inbuf;	/* handle wraparound */
  if (++tp->tty_incount == tp->tty_ihighwater && isrs232(tp))
	rs_istop(tp->tty_line);
  echo(tp, echoch);
}


/*==========================================================================*
 *				out_process				    *
 *==========================================================================*/
PRIVATE int out_process(tp, ubuf, ucount)
register struct tty_struct *tp;
char *ubuf;			/* input buffer */
int ucount;			/* size of input buffer */
{
/* Perform output processing on a buffer, translating it into tty_ramqueue.
 * The "RAM" queue is now mis-named and has a poorly chosen type even for RAM.
 */

  unsigned char ch;
  int spacecount;
  register char *tbuf;
  char *tbufend;
  char *ubufstart;

  tbuf = (char *) tp->tty_ramqueue;
  tbufend = tbuf + (sizeof tp->tty_ramqueue - TAB_SIZE);
  ubufstart = ubuf;
  while (ucount-- != 0 && tbuf < tbufend) {
	if ( (ch = *ubuf++) >= ' ') {
		++tp->tty_column;
		*tbuf++ = ch;
		continue;
	}
	switch(ch) {
	case '\b':
		if (tp->tty_column != 0) --tp->tty_column;
		break;
	case '\r': tp->tty_column = 0;	break;
	case LF:
		if (tp->tty_mode & CRMOD) {
			/* Map LF to CR+LF. */
			tp->tty_column = 0;
			*tbuf++ = '\r';
		}
		break;
	case '\t':
		if (tp->tty_mode & XTABS) {
			/* Tabs must be expanded, best guess. */
			spacecount = TAB_SIZE - (tp->tty_column & TAB_MASK);
			tp->tty_column += spacecount;
			do
				*tbuf++ = ' ';
			while (--spacecount != 0);
			continue;
		}
		/* Tabs are output directly, don't need column. */
		break;
	default:
		/* Can't tell if column will change. */
		break;
	}
	*tbuf++ = ch;
  }
  tp->tty_rwords = ubuf - ubufstart;
  return(tbuf - (char *) tp->tty_ramqueue);
}


/*==========================================================================*
 *				rs_start				    *
 *==========================================================================*/
PRIVATE void rs_start(tp)
register struct tty_struct *tp;
{
/* (*devstart)() routine for RS232. */

  int count;

  if (tp->tty_rwords != 0)
	return;			/* already going - xon handled at lower level*/

  if ( (count = tp->tty_etail - tp->tty_ebuf) > 0) {
	/* Do output processing on echo buffer and write result. */
	if (tp->tty_mode & RAW)
		memcpy((char *) tp->tty_ramqueue, tp->tty_ebuf, count);
	else
		count = out_process(tp, tp->tty_ebuf, count);
	rs_write(tp->tty_line, (char *) tp->tty_ramqueue, count);
	tp->tty_etail = tp->tty_ebuf;	/* small ebuf all fitted */
	tp->tty_rwords = -1;	/* kludge echo flag */
  } else if ( (count = tp->tty_outleft) != 0) {
	/* Do output processing on user buffer and write result. */
	if (tp->tty_mode & RAW) {
		if (count > sizeof tp->tty_ramqueue)
			count = sizeof tp->tty_ramqueue;
		phys_copy(tp->tty_phys, tp->tty_outphys, (phys_bytes) count);
		tp->tty_rwords = count;
	} else {
		if (count > sizeof tty_buf) count = sizeof tty_buf;
		phys_copy(tp->tty_phys, tty_bphys, (phys_bytes) count);
		count = out_process(tp, tty_buf, count);
	}
	rs_write(tp->tty_line, (char *) tp->tty_ramqueue, count);
  }
}


/*==========================================================================*
 *				tty_icancel				    *
 *==========================================================================*/
PRIVATE void tty_icancel(tp)
register struct tty_struct *tp;
{
/* Discard all data in tty input buffer and driver buffers. */

  char *buf;
  unsigned char odone;

  tp->tty_intail = tp->tty_inhead = tp->tty_inbuf;
  if (tp->tty_incount > tp->tty_ilow_water && isrs232(tp))
	rs_istart(tp->tty_line);
  tp->tty_incount = 0;
  tp->tty_lfct = 0;
  (*tp->tty_devread)(tp->tty_line, &buf, &odone); /* read fast to discard */
}


/*==========================================================================*
 *				tty_init				    *
 *==========================================================================*/
PRIVATE void tty_init()
{
/* Initialize tty structure and call driver initialization routines. */

  int line;
  register struct tty_struct *tp;

  for (line = 0; line < NR_CONS + NR_RS_LINES; ++line) {
	tp = &tty_struct[line];
	tp->tty_line = line - NR_CONS;
	p_tty_addr[line] = tp;
	tty_bphys = umap(proc_ptr, D, (vir_bytes) tty_buf,
			    (vir_bytes)sizeof tty_buf);
	if (isconsole(tp)) {
		tp->tty_inbuf = kb_inbuf[line];
		tp->tty_inbufend = tp->tty_inbuf + KB_IN_BYTES;
		tp->tty_ihighwater = KB_IN_BYTES;
		tp->tty_ilow_water = KB_IN_BYTES;
		tp->tty_insize = KB_IN_BYTES;
	} else {
		tp->tty_inbuf = rs_inbuf[tp->tty_line];
		tp->tty_inbufend = tp->tty_inbuf + RS_IN_BYTES;
		tp->tty_ihighwater = RS_IN_BYTES - 2 * RS_IBUFSIZE;
		tp->tty_ilow_water = (RS_IN_BYTES - 2 * RS_IBUFSIZE) * 7 / 8;
		tp->tty_insize = RS_IN_BYTES;
	}
	tp->tty_inphys = umap(proc_ptr, D, (vir_bytes) tp->tty_inbuf,
			      (vir_bytes)tp->tty_insize);
	tp->tty_intail = tp->tty_inhead = tp->tty_inbuf;
	tp->tty_outphys = umap(proc_ptr, D, (vir_bytes) tp->tty_ramqueue,
			       (vir_bytes)sizeof tp->tty_ramqueue);
	tp->tty_etail = tp->tty_ebuf;
	tp->tty_ebufend = tp->tty_ebuf + sizeof tp->tty_ebuf;
	tp->tty_erase = ERASE_CHAR;
	tp->tty_kill  = KILL_CHAR;
	tp->tty_intr  = INTR_CHAR;
	tp->tty_quit  = QUIT_CHAR;
	tp->tty_xon   = XON_CHAR;
	tp->tty_xoff  = XOFF_CHAR;
	tp->tty_eof   = EOT_CHAR;
	if (isconsole(tp)) {
		tp->tty_devread = kb_read;
		tp->tty_devstart = console;
		tp->tty_mode = CRMOD | XTABS | ECHO;
		tp->tty_makebreak = TWO_INTS;
		scr_init(tp->tty_line);
		kb_init(tp->tty_line);
	} else {
		tp->tty_devread = rs_read;
		tp->tty_devstart = rs_start;
		tp->tty_mode = RAW | BITS8;
		tp->tty_makebreak = ONE_INT;
		tp->tty_speed = rs_init(tp->tty_line);
		rs_setc(tp->tty_line, tp->tty_xoff, tp->tty_xon);
	}
  }
}


/*==========================================================================*
 *				tty_ocancel				    *
 *==========================================================================*/
PRIVATE void tty_ocancel(tp)
register struct tty_struct *tp;
{
/* Discard all data in tty output buffer and driver buffers. */

  tp->tty_waiting = NOT_WAITING;
  tp->tty_outleft = 0;
  tp->tty_rwords = 0;
  tp->tty_etail = tp->tty_ebuf;
  if (isrs232(tp)) rs_ocancel(tp->tty_line);
  if (isconsole(tp)) scr_cancel(tp->tty_line);
}


/*==========================================================================*
 *				tty_wakeup				    *
 *==========================================================================*/
PUBLIC void tty_wakeup()
{
/* Wake up TTY when the threshold is reached, or when there is something to
 * do but no new events (slow typist), or after a timeout. The threshold
 * dominates for fast terminal input and all keyboard input and output
 * completions. The timeout smooths slow terminal input.
 *
 * Wakeup_timeout and previous_events are probably deadwood (always use
 * timeout 1) but tty_awake is probably important to help avoid calling TTY
 * too often, apart from its locking function.
 */

#define WAKEUP_TIMEOUT (HZ/60)	/* adjust to taste, 1 for fast processor */

  static unsigned previous_events;
  static unsigned wakeup_timeout = WAKEUP_TIMEOUT;

  if (tty_events != 0 && !test_and_set(&tty_awake)) {
	if (tty_events >= EVENT_THRESHOLD || tty_events == previous_events ||
	    --wakeup_timeout == 0) {
		wakeup_timeout = WAKEUP_TIMEOUT;
		interrupt(TTY);
	} else
		tty_awake = FALSE;
	previous_events = tty_events;
  }
}


/*==========================================================================*
 *				uninhibit				    *
 *==========================================================================*/
PRIVATE void uninhibit(tp)
register struct tty_struct *tp;
{
/* (Re)allow terminal output. */

  tp->tty_inhibited = RUNNING;
  if (isrs232(tp)) rs_inhibit(tp->tty_line, FALSE);
}
