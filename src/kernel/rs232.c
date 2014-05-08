/*==========================================================================*
 *		rs232.c - serial driver 				    *
 *==========================================================================*/

#include "kernel.h"
#include "proc.h"
#include "setup.h"
#include <sgtty.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include "tty.h"
#include <mac/Files.h>
#include <mac/Serial.h>
#include <mac/SysError.h>

#define ODONE       0x01	/* output completed (< output enable bits) */
#define OQUEUED     0x02	/* output buffer not empty */
#define OCANCELLED  0x04	/* output had been cancelled */
#define IPENDING    0x01	/* read has been placed on line */
#define RS_BUFSIZE  RS_IBUFSIZE	/* buffer size for serial line */

#if (NO_HANDSHAKE == 1)		/* set in minix/config.h */
#define DTRSHK	    FALSE	/* pin 1 (output) handshaking */
#define CTSSHK	    FALSE	/* pin 2 (input) handshaking */
#define SERCSCODE   10		/* sershk cs code */
#else
/*
 * HARDWARE HANDSHAKING
 *
 * IF YOU WANT TO USE HARDWARE HANDSHAKING (And you certainly do if you
 * plan on connecting to another computer at a reasonably high baud rate),
 * then read this, follow the instructions, and set the NO_HANDSHAKE flag
 * to zero in include/minix/config.h.
 *
 * The Macintosh has only one set of hardware handshake lines. The most common
 * configuration for the mac to modem/terminal cable is to
 * connect the "handshake out" (pin 1 of the mini-din8) pin of the mac to
 * the modem's DTR pin and to connect "handshake in" (pin 2) to the carrier-detect 
 * output pin. This configuration allows for no hardware handshaking.
 *
 * If you want to use hardware flow control, your modem or terminal must support
 * it (and many modems do not). If it does, however, connect "handshake out" to
 * the modem's "request to send" input, and connect "handshake in" to the
 * modem's "clear to send" output, and configure your modem or terminal to use
 * RTS/CTS handshaking.
 */
#define DTRSHK	    TRUE	/* pin 1 (output) handshaking */
#define CTSSHK	    TRUE	/* pin 2 (input) handshaking */
#if (DTRSHK == TRUE)
#define SERCSCODE   14		/* sershk cs code */
#else
#define SERCSCODE   10		/* sershk cs code */
#endif
#endif

struct rs232_s {
  int minor;			/* minor number of this line (base 0) */

  unsigned char istate;		/* combination of flags: */
  int inref;			/* Macintosh input rrsef number */
  int lastcnt;			/* available on input */
  char *ibuf;			/* which buffer we are using */
  char ibuf1[RS_IBUFSIZE + 1];	/* 1st input buffer, guard at end */
  char ibuf2[RS_IBUFSIZE + 1];	/* 2nd input buffer (for swapping) */

  unsigned char ostate;		/* combination of flags: */
  int outref; 			/* Macintosh output ref number */
  ParamBlockRec outpb;		/* pb rec for write */

  SerShk sershk;		/* operating parameters */
  
  char inbuf[RS_BUFSIZE];	/* setting buf size */

  unsigned framing_errors;	/* error counts (no reporting yet) */
  unsigned hwoverrun_errors;
  unsigned swoverrun_errors;
  unsigned parity_errors;
};

struct rs_setbuf {
  char *serBPtr;
  int   serBLen;
};

/* Table and macro to translate an RS232 minor device number to its
 * struct rs232_s pointer.
 */
#define rs_addr(minor) (p_rs_addr[minor])
PRIVATE struct rs232_s *p_rs_addr[NR_RS_LINES];
PRIVATE struct rs232_s rs_lines[NR_RS_LINES];
PRIVATE ParamBlockRec pb;

_PROTOTYPE( void rs_out_int, ( ParamBlockRec *pb ) );
FORWARD _PROTOTYPE( void rs_control, ( struct rs232_s *rs, int ref, int code, char *csp, int cslen ) );
FORWARD _PROTOTYPE( int rs_config, ( int minor, int ibaud, int obaud, int mode ) );
FORWARD _PROTOTYPE( int rs_baud, ( int br ) );
FORWARD _PROTOTYPE( long rs_avail, ( struct rs232_s *rs ) );

/* High level routines (should only be called by TTY). */

/*==========================================================================*
 *				rs_control			 	    *
 *==========================================================================*/
PRIVATE void rs_control(rs, ref, code, csp, cslen)
struct rs232_s *rs;
int    ref;
int    code;
char  *csp;
int    cslen;
{
  int err;

  if (ref == 0)
    return;
  pb.ParamBlkType.cntrlParam.ioCRefNum = ref;
  pb.ParamBlkType.cntrlParam.csCode    = code;
  memcpy((char *)pb.ParamBlkType.cntrlParam.csParam, (char *)csp, cslen);
  if ((err = PBControl(&pb, 0)) != 0)
    printf("error %d setting line paramaters on serial line %d\n", err, rs->minor);
}


/*==========================================================================*
 *				rs_config			 	    *
 *==========================================================================*/
PRIVATE int rs_config(minor, ibaud, obaud, mode)
int minor;			/* which rs line */
int ibaud;			/* input speed: 110, 300, 1200, etc */
int obaud;			/* output speed: 110, 300, 1200, etc */
int mode;			/* sgtty.h sg_mode word */
{
/* Set various line control parameters for RS232 I/O.  */
  register struct rs232_s *rs;
  int dbits, parity, info;
  
  switch (mode & 0x300) {
    case BITS5: dbits = data5; break;
    case BITS6: dbits = data6; break;
    case BITS7: dbits = data7; break;
    case BITS8: dbits = data8; break;
  }
  parity = noParity;
  if (mode & ODDP) parity = oddParity;
  if (mode & EVENP) parity = evenParity;

  rs = rs_addr(minor);
  info = stop20 + parity + dbits + rs_baud(ibaud);
  rs_control(rs, rs->inref,  8, (char *)&info, sizeof info);
  info = stop20 + parity + dbits + rs_baud(obaud);
  rs_control(rs, rs->outref, 8, (char *)&info, sizeof info);
  if (mode & RAW) {
    	rs->sershk.fXOn = FALSE;
    	rs->sershk.fInX = FALSE;
  } else {
    	rs->sershk.fXOn = TRUE;
    	rs->sershk.fInX = TRUE;
  }
  /* don't know if we need to do this on both channels */
  rs_control(rs, rs->inref,  SERCSCODE, (char *)&rs->sershk, sizeof(SerShk));
  rs_control(rs, rs->outref, SERCSCODE, (char *)&rs->sershk, sizeof(SerShk));
  return( (obaud << 8) | ibaud );
}


/*==========================================================================*
 *				rs_baud 			 	    *
 *==========================================================================*/
PRIVATE int rs_baud(br)
int br;
{
/* Translate MINIX baud rate to Macintosh baud rate */

  switch (br) {
	case B300:	br = baud300;   break;
	case B600:	br = baud600;   break;
	case B1200:	br = baud1200;  break;
	case B1800:	br = baud1800;  break;
	case B2400:	br = baud2400;  break;
	case B3600:	br = baud3600;  break;
	case B4800:	br = baud4800;  break;
	case B7200:	br = baud7200;  break;
	case B9600:	br = baud9600;  break;
	case EXTA:	br = baud19200; break;
	case EXTB: 	br = baud57600; break;
	default: 	br = baud1200;  break;
  }
  return br;
}


/*==========================================================================*
 *				rs_ioctl			 	    *
 *==========================================================================*/
PUBLIC int rs_ioctl(minor, mode, speeds)
int minor;			/* which rs line */
int mode;			/* sgtty.h sg_mode word */
int speeds;			/* low byte is input speed, next is output */
{
/* Set the UART parameters. */
  int speed, parity, in_baud, out_baud, data;

  in_baud  = speeds & BYTE;
  out_baud = (speeds>>8) & BYTE;
  return(rs_config(minor, in_baud, out_baud, mode));
}


/*==========================================================================*
 *				rs_setc					    *
 *==========================================================================*/
PUBLIC void rs_setc(minor, xoff, xon)
int minor;			/* which rs line */
int xoff;			/* xoff character */
int xon;			/* xon character */
{
/* RS232 needs to know the xoff & xon characters. */
  register struct rs232_s *rs;

  rs = rs_addr(minor);
  rs->sershk.xOn  = xon;
  rs->sershk.xOff = xoff;
  /* don't know if we need to do this on both channels */
  rs_control(rs, rs->inref,  SERCSCODE, (char *)&rs->sershk, sizeof(SerShk));
  rs_control(rs, rs->outref, SERCSCODE, (char *)&rs->sershk, sizeof(SerShk));
}


/*==========================================================================*
 *				rs_init					    *
 *==========================================================================*/
PUBLIC int rs_init(minor)
int minor;			/* which rs line */
{
/* Initialize RS232 for one line. */
  int speed;
  int err;
  register struct rs232_s *rs;
  char *in, *out;
  char *c2pstr();
  struct rs_setbuf setbuf;
  struct config conf;

  setup(&conf, 0, 0);

  if (minor > 1) 
     panic("Kernel configured for more than two serial lines", NO_NUM);

  rs_istop(minor);
  rs = rs_addr(minor) = &rs_lines[minor];

  /* Record minor number. */
  rs->minor = minor;

  /* Set up operating params  */
  rs->sershk.fXOn = FALSE;
  rs->sershk.fInX = FALSE;
  rs->sershk.fCTS = CTSSHK;
  rs->sershk.xOff = XOFF_CHAR;
  rs->sershk.xOn  = XON_CHAR;
  rs->sershk.errs = 0;
  rs->sershk.evts = 0;
  rs->sershk.fDTR = DTRSHK;

  /* Set up output queue. */
  rs->ostate = 0;
  rs->istate = 0;
  rs->lastcnt = 0;

  rs->inref = 0;
  rs->outref = 0;

  if ((minor == 0 && conf.porta == 0)
   || (minor == 1 && conf.portb == 0)) {
     printf("Serial port %c not configured for use...skipping\r\n",
	minor == 0 ? 'A' : 'B');
     return 0;
  }

  if (minor == 0) {
    in = ".AIn";
    out = ".AOut";
  }
  else {
    in  = ".BIn";
    out = ".BOut";
  }

  /* open in and out, set up a read */
  pb.ioCompletion = 0L;
  pb.ioNamePtr = c2pstr(in);
  pb.ioVRefNum = 0;
  pb.ParamBlkType.ioParam.ioVersNum = 0;
  pb.ParamBlkType.ioParam.ioPermssn = fsRdPerm;
  pb.ParamBlkType.ioParam.ioMisc = 0;
  err = PBOpen(&pb, FALSE);
  if (err == 0)
    rs->inref = pb.ParamBlkType.ioParam.ioRefNum;
  else if (err == portNotCf) {
    printf("Port %d not configured for serial communications, will not use\n", minor);
    rs->outref = 0;
    return 0;
  }
  else
    printf("Unable to open serial line %d for input (err = %d)\n", rs->minor, err);
  
  pb.ioCompletion = 0L;
  pb.ioNamePtr = c2pstr(out);
  pb.ioVRefNum = 0;
  pb.ParamBlkType.ioParam.ioVersNum = 0;
  pb.ParamBlkType.ioParam.ioPermssn = fsWrPerm;
  pb.ParamBlkType.ioParam.ioMisc = 0;
  err = PBOpen(&pb, FALSE);
  if (err == 0)
    rs->outref = pb.ParamBlkType.ioParam.ioRefNum;
  else 
    printf("Unable to open serial line %d for output (err = %d)\n", rs->minor, err);

  speed = rs_config(minor, B1200, B1200, BITS8|RAW);
  rs->ibuf = rs->ibuf1;


  setbuf.serBPtr = rs->inbuf;
  setbuf.serBLen = RS_BUFSIZE;
  rs_control(rs, rs->inref, 9, (char *)&setbuf, sizeof(setbuf));
  rs_istart(minor);

  return speed;
}


/*==========================================================================*
 *				rs_close				    *
 *==========================================================================*/
PUBLIC void rs_close()
{
  register int i;
  register struct rs232_s *rs;
  struct rs_setbuf setbuf;

  for (i = 0; i < NR_RS_LINES; i++) {
     rs = rs_addr(i);
     rs_ocancel(rs->minor);
     /* set back to default buffer */
     setbuf.serBPtr = 0;
     setbuf.serBLen = 0;
     rs_control(rs, rs->inref, 9, (char *)&setbuf, sizeof(setbuf));
     if (rs->inref != 0) {
	     pb.ioCompletion = 0L;
	     pb.ParamBlkType.ioParam.ioRefNum = rs->inref;
	     pb.ioVRefNum = 0;
	     PBClose(&pb, FALSE);
     }
     if (rs->outref != 0) {
	     pb.ioCompletion = 0L;
	     pb.ParamBlkType.ioParam.ioRefNum = rs->outref;
	     pb.ioVRefNum = 0;
	     PBClose(&pb, FALSE);
     }
  }
}


/*==========================================================================*
 *				rs_inhibit				    *
 *==========================================================================*/
PUBLIC void rs_inhibit(minor, inhibit)
int minor;			/* which rs line */
int inhibit;			/* nonzero to inhibit, zero to uninhibit */
{
/* Update output inhibition state to keep in sync with TTY. */

  register struct rs232_s *rs;

  if (inhibit)
    printf("rs_inhibit: tty told us to inhibit");
}


/*==========================================================================*
 *				rs_istop				    *
 *==========================================================================*/
PUBLIC void rs_istop(minor)
int minor;			/* which rs line */
{
/* TTY wants RS232 to stop input.
 */

  register struct rs232_s *rs;

  rs = rs_addr(minor);
  rs->istate |= STOPPED;
}


/*==========================================================================*
 *				rs_istart				    *
 *==========================================================================*/
PUBLIC void rs_istart(minor)
int minor;			/* which rs line */
{
/* TTY is ready for another buffer full of input from RS232.
 */

  register struct rs232_s *rs;
  int err;

  rs = rs_addr(minor);
  rs->istate &= ~STOPPED;
}


/*==========================================================================*
 *				rs_avail				    *
 *==========================================================================*/
PRIVATE long rs_avail(rs)
register struct rs232_s *rs;
{
  register long *l;

  if (rs->istate & STOPPED || rs->inref == 0)
    return 0;

#ifdef SER_ERROR
  pb.ParamBlkType.cntrlParam.ioCRefNum = rs->inref;
  pb.ParamBlkType.cntrlParam.csCode    = 8;
  if (PBStatus(&pb, 0) == 0) {
    if (pb.ParamBlkType.cntrlParam.csParam[0] & 0xff00)
      printf("ERROR %x\n",(pb.ParamBlkType.cntrlParam.csParam[0] & 0xff00) >> 8);
  }
#endif

  l = (long *)&pb.ParamBlkType.cntrlParam.csParam[0];
  *l = 0;
  pb.ParamBlkType.cntrlParam.ioCRefNum = rs->inref;
  pb.ParamBlkType.cntrlParam.csCode    = 2;
  if (PBStatus(&pb, 0) != 0)
    return 0;
  
  return *l;
}


/*==========================================================================*
 *				rs_check				    *
 *==========================================================================*/
PUBLIC int rs_check()
{
  register int i;
  int cnt, s;
  register struct rs232_s *rs;

  for (i = 0; i < NR_RS_LINES; i++) {
     rs = rs_addr(i);
     if (cnt = rs_avail(rs)) {
     	s = lock();
  	tty_events += (cnt - rs->lastcnt);
	rs->lastcnt = cnt;
  	restore(s);
     }
  }
}


/*==========================================================================*
 *				rs_read					    *
 *==========================================================================*/
PUBLIC int rs_read(minor, bufindirect, odoneindirect)
int minor;			/* which rs line */
char **bufindirect;		/* where to return pointer to our buffer */
unsigned char *odoneindirect; 	/* where to return output-done status */
{
/* Swap the input buffers, giving the old one to TTY, and restart input. */

  register char *ibuf;
  int nread, s;
  long cnt;
  register struct rs232_s *rs;
  message m;

  rs = rs_addr(minor);
  *odoneindirect = rs->ostate & ODONE;
  if (rs->inref == 0 || rs->lastcnt == 0) return(0);
  ibuf = rs->ibuf;
  *bufindirect = ibuf;
  nread = rs->lastcnt > RS_IBUFSIZE ? RS_IBUFSIZE : rs->lastcnt;
  s = lock();
  tty_events  -= nread;
  rs->lastcnt -= nread;
  restore(s);
  pb.ParamBlkType.ioParam.ioRefNum = rs->inref;
  pb.ParamBlkType.ioParam.ioBuffer = ibuf;
  pb.ParamBlkType.ioParam.ioReqCount = nread;
  pb.ParamBlkType.ioParam.ioPosMode = fsAtMark;
  pb.ParamBlkType.ioParam.ioPosOffset = 0;
  if ((cnt = rs_avail(rs)) < nread) {
	/* Another app is stealing serial chars. Sad, but nothing
	   we can do about it.  Just read what's there.
	   printf("another app is stealing serial chars!\r\n");
	 */
	pb.ParamBlkType.ioParam.ioReqCount = cnt;
	nread = cnt;
  }
  if (PBRead(&pb, FALSE) != 0)
     nread = 0;
  if (ibuf == rs->ibuf1)
	ibuf = rs->ibuf2;
  else
	ibuf = rs->ibuf1;
  rs->ibuf = ibuf;
  return(nread);
}


/*==========================================================================*
 *				rs_out_int				    *
 *==========================================================================*/
PUBLIC void rs_out_int(pb)
ParamBlockRec *pb;	
{
/* Completion interrupt for output write. */

  register struct rs232_s *rs;
  int s;

  rs = (struct rs232_s *)pb->ioNamePtr;
  rs->ostate &= ~OQUEUED;
  if ((rs->ostate & OCANCELLED) == 0) {
  	rs->ostate |= ODONE;
  	s = lock();
  	tty_events += EVENT_THRESHOLD;
  	restore(s);
  }
}


/*==========================================================================*
 *				rs_ocancel				    *
 *==========================================================================*/
PUBLIC void rs_ocancel(minor)
int minor;			/* which rs line */
{
/* Cancel pending output. */

  register struct rs232_s *rs;
  int s;

  rs = rs_addr(minor);
  if (rs->ostate & OQUEUED) {
   	rs->ostate |= OCANCELLED;
  	PBKillIO(&rs->outpb, 0);
  }
  if (rs->ostate & ODONE) {
  	s = lock();
  	tty_events -= EVENT_THRESHOLD;
  	restore(s);
  }
  rs->ostate = 0;
}


/*==========================================================================*
 *				rs_write				    *
 *==========================================================================*/
PUBLIC void rs_write(minor, buf, nbytes)
int minor;			/* which rs line */
char *buf;			/* pointer to buffer to write */
int nbytes;			/* number of bytes to write */
{
/* Start output.
 * Previous output must have completed.
 */
  register struct rs232_s *rs;
  extern void rs_writeint();
  int err;

  rs = rs_addr(minor);
  if (rs->outref == 0)
	return;

  rs->outpb.ioCompletion = (ProcPtr)rs_writeint;
  rs->outpb.ioNamePtr = (StringPtr)rs; /*cheating*/
  rs->outpb.ParamBlkType.ioParam.ioRefNum = rs->outref;
  rs->outpb.ParamBlkType.ioParam.ioBuffer = buf;
#ifdef THINK_C
  rs->outpb.ParamBlkType.ioParam.ioMisc = (char *)geta5();
#endif
  rs->outpb.ParamBlkType.ioParam.ioReqCount = nbytes;
  rs->outpb.ParamBlkType.ioParam.ioPosMode = fsAtMark;
  rs->outpb.ParamBlkType.ioParam.ioPosOffset = 0;
  rs->ostate |= OQUEUED;
  if ((err = PBWrite(&rs->outpb, 1)) != 0)
    printf("Unable to start output on serial line %d (err = %d)\n", rs->minor, err);
}
