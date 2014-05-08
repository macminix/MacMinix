/*
 * The window driver for the mac console. To have multiple windows,
 * increase the NR_CONS number in tty.h. /dev/tty0-/dev/ttyNR_CONS-1
 * will be the windows, while /dev/NR_CONS-/dev/NR_CONS+1 will be
 * the serial lines.
 *
 * We now have three output modes, depending on the value of JUMPSCROLL:
 * 1) JUMPSCROLL < 0. Each of every char is drawn on the
 *    window as we go along. This is slow.
 * 2) JUMPSCROLL == 0. All the changes to the chars in the
 *    window are buffered, and we keep track of each row that has
 *    changes. When the write is complete, each row with changes is
 *    redrawn.  Stupid if you only change a single character or
 *    two, and downright painful on a Mac Plus. A big win
 *    if one or more lines change significantly, since this method uses
 *    DrawText, which is a lot faster than a lot of DrawChars.
 * 3) JUMPSCROLL > 0. A hybrid of the above two.  If less than JUMPSCROLL
 *    chars are being written, the window is updated immediately. Else it
 *    updated when all the characters have been processed. On my mac
 *    IIcx, it takes about .175 seconds to redraw an entire 80x25 window
 *    using 25 DrawText calls, while it takes about 1.9 seconds to do it
 *    using 2000 {MoveTo, DrawChar} calls. It becomes faster to redraw
 *    the entire screen when you are going to change more than around
 *    185 chars. 
 *
 */
#include "kernel.h"
#include "proc.h"
#include <sgtty.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include "tty.h"
#include <mac/Windows.h>
#include <mac/Controls.h>
#include <mac/Fonts.h>
#include <mac/Events.h>
#include <mac/OSEvents.h>

/* attribs */
#define BOLD		 0x1
#define UNDERLINE	 0x2
#define BLINK		 0x4		/* ignored */
#define REVERSE		 0x8

/* Constants relating to the windows and fonts */
#define AUTOTRACK 	 1	/* automatically track to ouput line */
#define JUMPSCROLL     185	/* jumpscroll lines */
#define MINROW		 5	/* minimum visible rows */
#define MINCOL		15	/* minimum visible cols */
#define SCROLLW		15	/* width of scroll bar */
#define LEADING	v->leading	/* distance between rows */
#define NCOL		80	/* characters on a row  MUST be mult of 16 */
#define NROW		25	/* number of lines */
#define HBORDER		 5	/* horizontal border */
#define VBORDER		 5	/* vertical border */
#define WTOP (MBarHeight+4)     /* window origin - top */
#define WLEFT          	 3      /* window origin - left */
#define WOFFSET        	-1      /* window offset for each additional window */
#define CONSOLE		 0	/* console line for kernel printf */
#if (JUMPSCROLL >= 0)
#define cpychar(r1, c1, r2, c2) \
	vdupaintchar(v->vram[(r1 * NCOL) + c1], r2, c2, v->attx[(r1 * NCOL) + c1])
#endif
#define clrchar(r,  c) 		vdupaintchar(' ', r, c, 0)


PRIVATE struct vduinfo {
	char	vram[NCOL*NROW];/* screen chars */
	char	attx[NCOL*NROW];/* attrs bytes */
#if (JUMPSCROLL >= 0)
	char    linemod[NROW];  /* tells which lines have been modified for flush */
#endif
	int	top;		/* top row currently visible */
	int	nrow;		/* char rows on screen */
	int	savnrow;	/* saved number of rows */
	int	ncol;		/* bytes in row of chars */
	int	savncol;	/* saved number of cols */
	char	attr;		/* current attribute byte */
	int	ccol;		/* current char column */
	int	crow;		/* current char row */
	char	savattr;	/* saved attribute byte */
	int	savccol;	/* saved char column */
	int	savcrow;	/* saved char row */
	char	vbuf[20];	/* partial escape sequence */
	char	*next;		/* next char in vbuf[] */
	int     active;		/* is window active? (frontmost) */
	int	minor;		/* minor number */
	WindowRecord w;		/* the window */
	ControlHandle vcontrol; /* vertical control bar */
	Rect	termrect;	/* clipped term rect */
	int 	textheight;	/* text height */
	int 	ascent;		/* text ascent */
	int 	maxw;		/* width of max char */
	int     descent;	/* text descent */
	int     leading;	/* text descent */
	int	waspaused;	/* was this guy paused? */
};

#ifdef THINK_C
PUBLIC  struct vduinfo *vduinfo;
PUBLIC  long   vduinfosize = sizeof (struct vduinfo) * NR_CONS;
#else
PRIVATE struct vduinfo vduinfo[NR_CONS];
#endif
extern  int MBarHeight;
PRIVATE struct vduinfo *v;
PRIVATE struct tty_struct *tpl;
PRIVATE RgnHandle scrollrgn = 0;
PRIVATE Rect miscr;
PUBLIC  char vdupaused = FALSE;
PRIVATE char immed;

FORWARD _PROTOTYPE( void vduput, ( int c ) );
FORWARD _PROTOTYPE( void vductrl, ( int c ) );
FORWARD _PROTOTYPE( void vduansi, ( int c ) );
FORWARD _PROTOTYPE( void vduesc, ( int c ) );
FORWARD _PROTOTYPE( int vduparam, ( void ) );
FORWARD _PROTOTYPE( void vdumoveto, ( int r, int c ) );
FORWARD _PROTOTYPE( void vduattr, ( int attr ) );
FORWARD _PROTOTYPE( void vdubeep, ( void ) );
FORWARD _PROTOTYPE( void vducursor, ( int on ) );
FORWARD _PROTOTYPE( void vduscroll, ( int cnt, int set ) );
FORWARD _PROTOTYPE( void vducpyline, (int r1, int r2) );
FORWARD _PROTOTYPE( void vduclrline, (int r1) );
FORWARD _PROTOTYPE( void vduclrarea, (int r1, int c1, int r2, int c2) );
FORWARD _PROTOTYPE( void vdupaintlines, (int r, int cnt) );
FORWARD _PROTOTYPE( void vdupaintchar, ( int ch, int r, int c, char attr ) );

/*===========================================================================*
 *				scr_init				     *
 *===========================================================================*/
PUBLIC void scr_init(minor)
{
  long line = minor + NR_CONS;
  EventRecord e;

  v   = &vduinfo[line];
  tpl = &tty_struct[line];
  v->nrow = NROW;
  v->savnrow = NROW;
  v->ncol = NCOL;
  v->savncol = NCOL;
  v->attr = 0x0;
  v->minor = minor;
  v->top = 0;
  if (scrollrgn == 0)
     scrollrgn = NewRgn();
  vdusetparams(line, 1, monaco, 9, line == 0 ? 1 : 0, 1, 0L, 1, 0, 0);
}


/*===========================================================================*
 *				flush 				     	     *
 *===========================================================================*/
PUBLIC void flush(tp)
register struct tty_struct *tp;
{
#if (JUMPSCROLL >= 0)
  register int i, last;
  register char *lm;

  v = &vduinfo[tp->tty_line+NR_CONS];
  tpl = tp;
  lm = &v->linemod[v->top];
  last = v->top + v->nrow;
  for (i = v->top; i < last; i++, lm++)
    if (*lm) {
      vdupaintlines(i, 1);
      *lm = 0;
    }
#endif
}


/*===========================================================================*
 *				console					     *
 *===========================================================================*/
PUBLIC void console(tp)
register struct tty_struct *tp;
{
  register int s;
  register struct proc *rp;
  register QHdr *e;
  
  if (tp->tty_outleft == 0 || tp->tty_inhibited == TRUE)
	return;

  rp = proc_addr(tp->tty_outproc);
  v = &vduinfo[tp->tty_line+NR_CONS];
  tpl = tp;
  e = GetEvQHdr();

#if (JUMPSCROLL < 0)
  immed == TRUE;
#endif
#if (JUMPSCROLL == 0)
  immed = FALSE;
#endif
#if (JUMPSCROLL > 0)
  if (tp->tty_outleft < JUMPSCROLL)
	immed = TRUE;
  else 
	immed = FALSE;
#endif

  vducursor(0);
  do {
	vduput(*((char *)tp->tty_phys));
	tp->tty_phys++;		/* advance physical data pointer */
	tp->tty_cum++;		/* number of characters printed */
  } while (--tp->tty_outleft != 0 && e->qHead == 0 && tty_events == 0);

#if (JUMPSCROLL >= 0)
  if (immed == FALSE)
	flush(tp);
#endif

  vducursor(1);
  
  if (tp->tty_outleft == 0) {
  	rp->p_physio = FALSE;
	if (v->waspaused == TRUE)
		vdupaused = FALSE;
  	finish(tp, tp->tty_cum);
  }
  else {
  	rp->p_physio = TRUE;
  	vdupaused = TRUE;
	v->waspaused = TRUE;
  }
}

/*===========================================================================*
 *				scr_cancel				     *
 *===========================================================================*/
PUBLIC void scr_cancel(minor)
int minor;
{
  register struct tty_struct *tp = &tty_struct[minor+NR_CONS];
  
  proc_addr(tp->tty_outproc)->p_physio = FALSE;
}


/*===========================================================================*
 *				out_char 				     *
 *===========================================================================*/
PUBLIC void out_char(tp, c)
register struct tty_struct *tp;
char c;
{
  v = &vduinfo[tp->tty_line+NR_CONS];
  tpl = tp;
  immed = TRUE;
  vducursor(0);
  vduput(c);
#if 0
  flush(tp);
#endif
  vducursor(1);
}


/*===========================================================================*
 *				putc					     *
 *===========================================================================*/
PUBLIC void putc(c)
char c;				/* character to print */
{
/* This procedure is used by the version of printf() that is linked with
 * the kernel itself.  The one in the library sends a message to FS, which is
 * not what is needed for printing within the kernel.  This version just queues
 * the character and starts the output.
 */

  out_char(&tty_struct[CONSOLE], c);
}


/*===========================================================================*
 *				vduput 					     *
 *===========================================================================*/
/*
 * send character to VDU, collecting escape sequences
 */
PRIVATE void vduput(c)
register c;			/* character to be output */
{
  if (c == 0x7F)
	return;
#if (MACHINE != MACINTOSH)
  if ((c & 0140) == 0) {
	/*
	 * control character
	 */
	vductrl(c);
	return;
  }
  if (c & 0x80)
	/*
	 * display a fancy character (fonts 00 - 1f)
	 */
	c &= 0x1F;
#endif
#if (MACHINE == MACINTOSH)
  if ((c & 0177740) == 0) {
	/*
	 * control character
	 */
	vductrl(c);
	return;
  }
#endif
  if (v->next == 0) {
	/*
	 * normal character
	 */
#if (AUTOTRACK == 1)
  	int curbottom = v->top + v->nrow;
  
  	if (v->crow < v->top)
    		vduscroll(-(v->top - v->crow), TRUE);
  	if (v->crow >= curbottom)
    		vduscroll(v->crow - curbottom + 1, TRUE);
#endif
	vdupaintchar(c, v->crow, v->ccol, v->attr);
#if (LINEWRAP == 1)
	if (v->ccol > (NCOL-2)) {
	  if ((tpl->tty_mode & (RAW | CBREAK)) == 0) {
		vductrl(013);
		vductrl(015);
	  }
	} else
#endif
		vdumoveto(v->crow, v->ccol + 1);
	return;
  }
  if (v->next == v->vbuf && c == '[') {
	/*
	 * start of ANSI sequence
	 */
	*v->next++ = (char)c;
	return;
  }
  if (c >= 060 && (v->next == v->vbuf || v->vbuf[0] != '[')) {
	/*
	 * end of non-ANSI escape sequence
	 */
	vduesc(c);
	v->next = 0;
	return;
  }
  if (c >= 0100) {
	/*
	 * end of ANSI sequence
	 */
	vduansi(c);
	v->next = 0;
	return;
  }
  /*
   * part of escape sequence
   */
  *v->next = (char)c;
  if (v->next < &v->vbuf[sizeof(v->vbuf)])
	v->next++;
}

/*
 * control character
 */
PRIVATE void vductrl(c)
{
  register i;
  
  switch (c) {
  case 007: /* BEL */
	vdubeep(); return;
  case 010: /* BS */
	vdumoveto(v->crow, v->ccol - 1); return;
  case 011: /* HT */
	do
		if ((tpl->tty_mode & XTABS) == XTABS)
			vduput(' ');
		else
			vdumoveto(v->crow, v->ccol + 1);
	while (v->ccol & TAB_MASK);
	return;
  case 012: /* LF */
	if (tpl->tty_mode & CRMOD)
		vduput('\r');
  case 013: /* VT */
  case 014: /* FF */
	if (v->crow == NROW - 1) {
		for (i = 0; i < NROW-1; i++)
			vducpyline(i + 1, i);
		if (immed == TRUE) {
			OffsetRgn(v->w.updateRgn, 0, -v->textheight);
   			ScrollRect(&v->termrect, 0, -v->textheight, scrollrgn);
			InvalRgn(scrollrgn);
	  		miscr.left = HBORDER;
	  		miscr.right = miscr.left + v->ncol * v->maxw;
	  		miscr.top = VBORDER + v->textheight * (NROW-1 - v->top);
	  		miscr.bottom = miscr.top + v->textheight;
			ValidRect(&miscr);
		}
		vduclrline(i);
	} else
		vdumoveto(v->crow + 1, v->ccol);
	return;
  case 015: /* CR */
	vdumoveto(v->crow, 0);
	return;
  case 030: /* CAN */
  case 032: /* SUB */
	v->next = 0;
	/* no error char */
	return;
  case 033: /* ESC */
	v->next = v->vbuf;
	return;
  default:
	return;
  }
}

/*
 * execute ANSI escape sequence
 */
PRIVATE void vduansi(c)
{
  register i;
  register j;

  if (v->next >= &v->vbuf[sizeof(v->vbuf)])
	return;
  *v->next = 0;
  v->next = &v->vbuf[1];
  j = vduparam();
  if ((i = j) <= 0)
	i = 1;
  switch (c) {
  case 'A': /* CUU: cursor up */
	if ((i = v->crow - i) < 0)
		i = 0;
	vdumoveto(i, v->ccol);
	return;
  case 'B': /* CUD: cursor down */
	if ((i += v->crow) >= NROW)
		i = NROW-1;
	vdumoveto(i, v->ccol);
	return;
  case 'C': /* CUF: cursor forward */
	if ((i += v->ccol) >= NCOL)
		i = NCOL-1;
	vdumoveto(v->crow, i);
	return;
  case 'D': /* CUB: cursor backward */
	if ((i = v->ccol - i) < 0)
		i = 0;
	vdumoveto(v->crow, i);
	return;
  case 'H': /* CUP: cursor position */
  case 'f': /* HVP: horizontal and vertical position */
	j = vduparam();
	if (j <= 0)
		j = 1;
	if (i > NROW)
		i = NROW;
	if (j > NCOL)
		j = NCOL;
	vdumoveto(i - 1, j - 1);
	return;
  case 'J': /* ED: erase in display */
	if (j <= 0)
		vduclrarea(v->crow, v->ccol, NROW-1, NCOL-1);
	else if (j == 1)
		vduclrarea(0, 0, v->crow, v->ccol);
	else if (j == 2)
		vduclrarea(0, 0, NROW-1, NCOL-1);
	return;
  case 'K': /* EL: erase in line */
	if (j <= 0)
		vduclrarea(v->crow, v->ccol, v->crow, NCOL-1);
	else if (j == 1)
		vduclrarea(v->crow, 0, v->crow, v->ccol);
	else if (j == 2)
		vduclrarea(v->crow, 0, v->crow, NCOL-1);
	return;
  case 'm': /* SGR: set graphic rendition */
	do {
#ifdef COLOR
		static colors[] = {
			RGB_BLACK,
			RGB_RED,
			RGB_GREEN,
			RGB_YELLOW,
			RGB_BLUE,
			RGB_MAGENTA,
			RGB_CYAN,
			RGB_WHITE,
			RGB_LGREY,
			RGB_DGREY,
		};
#endif
		switch (j) {
             		case 0:  v->attr  = 0;    		break;
             		case 1:  v->attr |= BOLD; 	        break;
              		case 4:  v->attr |= UNDERLINE;		break;
             		case 5:  v->attr |= BLINK;		break;
             		case 7:  v->attr |= REVERSE;         	break;
             		default: v->attr  = 0;			break;
                }
#ifdef COLOR
		else if (j >= 30 && j <= 39)
			VIDEO->vd_rgb[1] = colors[j - 30];
		else if (j >= 40 && j <= 49)
			VIDEO->vd_rgb[0] = colors[j - 40];
#endif
	} while ((j = vduparam()) >= 0);
	return;
  case 'L': /* IL: insert line */
	if (i > NROW - v->crow)
		i = NROW - v->crow;
	for (j = NROW-1; j >= v->crow+i; j--)
		vducpyline(j - i, j);
	if (immed == TRUE) {
		miscr = v->termrect;
		miscr.top += (v->crow-v->top)*v->textheight;
		OffsetRgn(v->w.updateRgn, 0, i*v->textheight);
		ScrollRect(&miscr, 0, i*v->textheight, scrollrgn);
		InvalRgn(scrollrgn);
	}
	while (--i >= 0)
		vduclrline(j--);
	return;
  case 'M': /* DL: delete line */
	if (i > NROW - v->crow)
		i = NROW - v->crow;
	for (j = v->crow; j < NROW-i; j++)
		vducpyline(j + i, j);
	if (immed == TRUE) {
		miscr = v->termrect;
		miscr.top += (v->crow-v->top)*v->textheight;
		OffsetRgn(v->w.updateRgn, 0, -i*v->textheight);
		ScrollRect(&miscr, 0, -i*v->textheight, scrollrgn);
		InvalRgn(scrollrgn);
	}
	while (--i >= 0)
		vduclrline(j++);
	return;
  case '@': /* ICH: insert char */
	j = NCOL - v->ccol;
	if (i > j)
		i = j;
	j -= i;
	if (immed == TRUE) {
	  while (--j >= 0) {
		v->vram[v->crow * NCOL + v->ccol + j + i] =
			v->vram[v->crow * NCOL + v->ccol + j];
		v->attx[v->crow * NCOL + v->ccol + j + i] =
			v->attx[v->crow * NCOL + v->ccol + j];
		v->vram[v->crow * NCOL + v->ccol + j] = ' ';
		v->attx[v->crow * NCOL + v->ccol + j] = ' ';
	  }
	  miscr.left = HBORDER + v->ccol*v->maxw;
	  miscr.right = v->ncol * v->maxw;
	  miscr.top = VBORDER + (v->textheight * (v->crow - v->top));
	  miscr.bottom = miscr.top + v->textheight;
	  ScrollRect(&miscr, i*v->maxw, 0, scrollrgn);
	  InvalRgn(scrollrgn);
	}
	else {
	  while (--j >= 0)
		cpychar(v->crow, v->ccol + j, v->crow, v->ccol + j + i);
	}
	vduclrarea(v->crow, v->ccol, v->crow, v->ccol + i - 1);
	return;
  case 'P': /* DCH: delete char */
	j = NCOL - v->ccol;
	if (i > j)
		i = j;
	j -= i;
	if (immed == TRUE) {
	  while (--j >= 0) {
		v->vram[v->crow * NCOL + NCOL-1 - j - i] =
			v->vram[v->crow * NCOL + NCOL-1 - j];
		v->attx[v->crow * NCOL + NCOL-1 - j - i] =
			v->attx[v->crow*NCOL + NCOL-1 - j];
		v->vram[v->crow * NCOL + NCOL-1 - j] = ' ';
		v->attx[v->crow * NCOL + NCOL-1 - j] = 0;
	  }
	  miscr.left = HBORDER + v->ccol*v->maxw;
	  miscr.right = v->ncol * v->maxw;
	  miscr.top = VBORDER + (v->textheight * (v->crow - v->top));
	  miscr.bottom = miscr.top + v->textheight;
	  ScrollRect(&miscr, -i*v->maxw, 0, scrollrgn);
	  InvalRgn(scrollrgn);
	}
	else {
	  while (--j >= 0)
		cpychar(v->crow, NCOL-1 - j, v->crow, NCOL-1 - j - i);
	}
	vduclrarea(v->crow, NCOL - i, v->crow, NCOL-1);
	return;
  case '~': /* MACINTOSH specific escape sequence */
	/*
	 * Handle the following escape sequence:
	 *   ESC [ f;s; '~'
	 * where
 	 *   f = font number
	 *   s = size
	 */
	if (j < 0)
	  j = -1;		/* no change to font */
	else {
	  char name[256];
	  
	  GetFontName(j, (outStringPtr)name);
	  if (name[0] == '\0')
	     j = -1;		/* not a valid font number */
	  else if (isfixedwidth(name) == 0)
	     j = -1;		/* not a fixed width font */
	}
	i = vduparam();
	if (i < 0)
	  i = -1;		/* no change to size */
	if (j != -1)
	  vdusetparams((long)v->minor + NR_CONS, 0, j, -1, 1, 1, 0L, 1, 0, 0);
	if (i != -1)
	  vdusetparams((long)v->minor + NR_CONS, 0, -1, i, 1, 1, 0L, 1, 0, 0);
	return;
  default:
	return;
  }
}

/*
 * execute non-ANSI escape sequence
 */
PRIVATE void vduesc(c)
{
  register i;

  if (v->next >= &v->vbuf[sizeof(v->vbuf)-1])
	return;
  *v->next = (char)c;
  switch (v->vbuf[0]) {
  case '8': /* DECRC: restore cursor */
	v->ccol = v->savccol;
	v->crow = v->savcrow;
	v->attr = v->savattr;
	vdumoveto(v->crow, v->ccol);
	return;
  case '7': /* DECSC: save cursor */
	v->savccol = v->ccol;
	v->savcrow = v->crow;
	v->savattr = v->attr;
	return;
  case 'E': /* NEL: next line */
	vductrl(015);
	/* fall through */
  case 'D': /* IND: index */
	vductrl(012);
	return;
  case 'M': /* RI: reverse index */
	if (v->crow == 0) {
		for (i = NROW - 1; i > 0; i--)
			vducpyline(i - 1, i);
		if (immed  == TRUE) {
   		  ScrollRect(&v->termrect, 0, v->textheight, scrollrgn);
		  InvalRgn(scrollrgn);
		}
		vduclrline(i);
	} else
		vdumoveto(v->crow - 1, v->ccol);
	return;
  case 'c': /* RIS: reset to initial state */
	scr_init(tpl->tty_line);
	vducursor(0);
	return;
  default:
	return;
  }
}

/*
 * compute next parameter out of ANSI sequence
 */
PRIVATE int vduparam()
{
  register c;
  register i;

  i = -1;
  c = *v->next++;
  if (c >= '0' && c <= '9') {
	i = 0;
	do {
		i *= 10;
		i += (c - '0');
		c = *v->next++;
	} while (c >= '0' && c <= '9');
  }
  if (c != ';')
	v->next--;
  return(i);
}

/*===========================================================================*
 *				manipulate videoram 			     *
 *===========================================================================*/

/*
 * copy line r1 to r2
 */
PRIVATE void vducpyline(r1, r2)
{
  register long *src;
  register long *dst;
  register long *srca;
  register long *dsta;
  register i;

  src  = (long*)&v->vram[r1 * NCOL];
  dst  = (long*)&v->vram[r2 * NCOL];
  srca = (long*)&v->attx[r1 * NCOL];
  dsta = (long*)&v->attx[r2 * NCOL];
  i = NCOL >> 4;
  while (--i >= 0) {
	*dst++  = *src++;
	*dst++  = *src++;
	*dst++  = *src++;
	*dst++  = *src++;
	*dsta++ = *srca++;
	*dsta++ = *srca++;
	*dsta++ = *srca++;
	*dsta++ = *srca++;
  }
  if (immed == FALSE)
  	v->linemod[r2] = 1;
}

/*
 * clear line r
 */
PRIVATE void vduclrline(r)
{
  register long			*p, *q;
  register			i;

  p = (long*)&v->vram[r * NCOL];
  q = (long*)&v->attx[r * NCOL];
  i = NCOL >> 4;	/* 16 bytes per iteration */
  while (--i >= 0) {
	*p++ = 0x20202020L;
	*p++ = 0x20202020L;
	*p++ = 0x20202020L;
	*p++ = 0x20202020L;
	*q++ = 0L;
	*q++ = 0L;
	*q++ = 0L;
	*q++ = 0L;
  }
  if (immed == TRUE) {
  	miscr.left = HBORDER;
  	miscr.right = miscr.left + v->ncol * v->maxw;
  	miscr.top = VBORDER + (v->textheight * (r - v->top));
  	miscr.bottom = miscr.top + v->textheight;
  	EraseRect(&miscr);
  }
  else
  	v->linemod[r] = 1;
}

/*
 * clear part of screen between two points inclusive
 */
PRIVATE void vduclrarea(r1, c1, r2, c2)
{
  if (++c2 == NCOL) {
	c2 = 0;
	r2++;
  }
  if (c1 > 0 && r1 < r2) {
	do
		clrchar(r1, c1);
	while (++c1 < NCOL);
	c1 = 0;
	r1++;
  }
  while (r1 < r2)
	vduclrline(r1++);
  while (c1 < c2)
	clrchar(r1, c1++);
}


/*===========================================================================*
 *				vdumoveto				     *
 *===========================================================================*/
PRIVATE void vdumoveto(r, c)
{
  if (r < 0 || r >= NROW || c < 0 || c > NCOL)
	return;
  v->crow = r;
  v->ccol = c;
}


/*===========================================================================*
 *				vduattr					     *
 *===========================================================================*/
PRIVATE void vduattr(attr)
{
  register int face = normal;
  register int mode = srcCopy;
  if (attr) {
  	if (attr & BOLD) face |= (bold + condense);
  	if (attr & UNDERLINE) face |= underline;
  	if (attr & (REVERSE | BLINK)) mode = notSrcCopy;
  }
  v->w.port.txFace = face;
  v->w.port.txMode = mode;
}


/*===========================================================================*
 *				vdupaintlines				     *
 *===========================================================================*/
/*
 * redraw the specified line
 */
PRIVATE void vdupaintlines(r, cnt)
{
  register char *p, *q, *e;
  register int   last, acnt;
  
  while (cnt--) {
    MoveTo(HBORDER, VBORDER + (v->textheight * (r - v->top)) + v->ascent);
    p = &v->vram[r * NCOL];
    q = &v->attx[r * NCOL];
    e = &v->attx[r * NCOL + v->ncol];
    last = *q++;
    acnt = 1;
    while (q < e) {
        if (*q != last) {
           vduattr(last);
           DrawText(p, 0, acnt);
           p += acnt;
           last = *q++;
           acnt = 1;
        }
        acnt++;
    	q++;
    }
    if (acnt) {
      vduattr(last);
      DrawText(p, 0, acnt);
    }
    r++;
  }
}


/*===========================================================================*
 *				vdubeep					     *
 *===========================================================================*/

PRIVATE void vdubeep()
{
  register i, s;

  SysBeep(3);
}

/*===========================================================================*
 *				vducursor				     *
 *===========================================================================*/
/*
 * (un-)display the cursor
 * parameter onoff reserved for future use (e.g. blinking)
 */
PRIVATE void vducursor(on)
int	on;
{
  Rect r;
  int t,l;
  
  if (v->ccol == NCOL)
    v->ccol--;
    
  if (on == 0)
      SetPort((WindowPtr)&v->w);
  if (v->active == 0)
      return;
  t = VBORDER + v->textheight * (v->crow - v->top);
  l = HBORDER + v->maxw * v->ccol;
  SetRect(&r, l, t, l + v->maxw, t + v->ascent + v->descent);
  InvertRect(&r);
}


/*===========================================================================*
 *				vdupaintchar				     *
 *===========================================================================*/
PRIVATE void vdupaintchar(ch, r, c, attr)
char attr;
{
  register int p;		/* ptr into video memory */

  p = (r * NCOL) + c;
  if (immed == TRUE) {
  	vduattr(attr);
  	MoveTo(HBORDER + v->maxw * c,
		VBORDER + (v->textheight * (r - v->top)) + v->ascent);
  	DrawChar(ch);
  }
  else
  	v->linemod[r]++;
  v->vram[p] = ch;
  v->attx[p] = attr;
}


/*===========================================================================*
 *				vduscroll				     *
 *===========================================================================*/
PRIVATE void vduscroll(cnt, set)
register int cnt;
int set;
{
   int dv;
   v->top += cnt;
   dv = cnt * v->textheight;
   ScrollRect(&v->termrect, 0, -dv, scrollrgn);
   if (dv < 0)
       vdupaintlines(v->top, -cnt);
   else
       vdupaintlines(v->top + v->nrow - cnt, cnt);
   if (set == TRUE) {
       ClipRect(&v->w.port.portRect);
       SetCtlValue(v->vcontrol, v->top);
       ClipRect(&v->termrect);
   }
}


/*===========================================================================*
 *				vdutrack				     *
 *===========================================================================*/
PUBLIC void vdutrack(line, pt)
long line;
long *pt;
{
  register int saved, scrolled;
  ControlHandle origcontrol = 0, c = 0;
  int origpart = -1, part;
  long ft;
  Point *startpt = (Point *)pt;
 
  v = &vduinfo[line];
  vducursor(0);
  GlobalToLocal(startpt);
  do { 
    ClipRect(&v->w.port.portRect);
    part = FindControl(*startpt, (WindowPtr)&v->w, &c);
    if (origpart == -1)
      origpart = part;
    if (origcontrol == 0)
      origcontrol = c;
    if (part == origpart && c == origcontrol) {
      scrolled = 0;
      saved = (*c)->contrlValue;
      switch (part)
	{
	case inUpButton:
	    HiliteControl(c, part);
	    if ((*c)->contrlValue > (*c)->contrlMin)
	    	scrolled = -1;
	    break;
	case inDownButton:
	    HiliteControl(c, part);
	    if ((*c)->contrlValue < (*c)->contrlMax)
	        scrolled = 1;
	    break;
	case inPageUp:
	    scrolled = -v->nrow;
	    break;
	case inPageDown:
	    scrolled = v->nrow;
	    break;
	 case inThumb:
  	    TrackControl(c, *startpt, 0L);
	    break;
	 default:
	    break;		/* nothing to do */
	}
        if (scrolled != 0)
    	  SetCtlValue(c, (*c)->contrlValue + scrolled);
    	scrolled = (*c)->contrlValue - saved;
    	if (scrolled != 0) {
    	    ClipRect(&v->termrect);
    	    vduscroll(scrolled, FALSE);
         }
    } else
 	if (origcontrol)
 		HiliteControl(origcontrol, 0);
    GetMouse(startpt);
    Delay(5L, &ft);
  } while (StillDown());
  ClipRect(&v->w.port.portRect);
  HiliteControl(v->vcontrol, 0);
  ClipRect(&v->termrect);
  vducursor(1);
}


/*===========================================================================*
 *				vdusetparams				     *
 *===========================================================================*/
PUBLIC void vdusetparams(ln, new, font, fsize, front, resize, pt, show, redraw, zoom)
long ln;
long *pt;
{
  char *name;
  Rect br;
  int hz, vz;
  WindowPtr wp;
  FontInfo f;
  int maxh, maxv;
  int line = ln;
  int woffset;
  Point *rpt = (Point *)pt;
  
  v = &vduinfo[line];
  wp = (WindowPtr)&v->w;
  
  /* make a new window if desired */
  if (new) {
    name = "TTY  ";
    name[4] = line + '0';
#if (WOFFSET >= 0)
    /* each window is WOFFSET from the previous one */
    woffset = WOFFSET;
#else
    /* calculate it from the screen size */
    if ((qd->screenBits.bounds.right - qd->screenBits.bounds.left) <= 512)
      woffset = 0;	/* 13 inch screen */
    else
      woffset = 10;	/* anything else */
#endif
    SetRect(&br,
        WLEFT+(line*woffset),
        WTOP+(line*woffset)+SCROLLW,
        WLEFT+(line*woffset)+1,
        WTOP+(line*woffset)+SCROLLW+1
    );
    NewWindow((WindowPeek)wp, &br, (inStringPtr)name, FALSE, 8, (WindowPtr)-1L, TRUE, ln);
    if (front == 0)
      SendBehind((WindowPtr)&v->w, 0L);
    v->vcontrol = NewControl(wp, &br, "", FALSE, 0, 0, NROW - 1, scrollBarProc, 0L);
    vdumoveto(0, 0);			/* move cursor to upper left corner */
    vducursor(0);
    vduclrarea(0, 0, NROW-1, NCOL-1);
    vducursor(1);
    redraw = 1;
  }

  vducursor(0);
  
  /* change the font */
  if (font >= 0 || fsize >= 0) {
    if (font >= 0) {
      TextFont(font);
      TextMode(srcCopy);
    }
    if (fsize >= 0)
      TextSize(fsize);
    GetFontInfo(&f);
    v->textheight = f.ascent + f.descent + f.leading;
    v->ascent     = f.ascent;
    v->descent    = f.descent;
    v->maxw       = CharWidth('W');
    v->leading	  = f.leading;
    br = v->w.port.portRect;
    InvalRect(&br);
  }

  maxh = 2*HBORDER + (v->maxw * NCOL) + SCROLLW;
  maxv = 2*VBORDER + (v->textheight * NROW) - LEADING;

  if (front >= 0) {
    if (front) {
      v->active = 1;
      SelectWindow((WindowPtr)&v->w);
      vz = v->w.port.portRect.bottom - v->w.port.portRect.top;
      if (vz == maxv)
      	HiliteControl(v->vcontrol,255);
       else
      	HiliteControl(v->vcontrol,0);
      hz = v->w.port.portRect.right - v->w.port.portRect.left;
      kb_active(v->minor);
    }
    else {
      v->active = 0;
      HiliteControl(v->vcontrol, 255);
    }
    br = v->w.port.portRect;
    br.left = br.right - SCROLLW;
    ClipRect(&br);
    DrawGrowIcon((WindowPtr)&v->w);
    DrawControls((WindowPtr)&v->w);
    ClipRect(&v->termrect);
  }
  
  if (zoom) {
     int tmp1, tmp2;
     tmp1 = v->nrow;
     tmp2 = v->ncol;
     v->nrow = v->savnrow;
     v->ncol = v->savncol;
     if (v->nrow < NROW || v->ncol < NCOL) {
     	v->savnrow = NROW;
     	v->savncol = NCOL;
     }
     else {
     	v->savnrow = tmp1;
     	v->savncol = tmp2;
     }
     resize = 1;
  }
  
  if (resize) {
    unsigned long size;

    if (rpt == 0) {
      hz = 2*HBORDER + (v->maxw * v->ncol) + SCROLLW;
      vz = 2*VBORDER + (v->textheight * v->nrow) - LEADING;
      SizeWindow(wp, hz, vz, 1);
    }
    else {
      
      SetRect(&br,
        2*HBORDER + (v->maxw * MINCOL)+SCROLLW,
        2*VBORDER + (v->textheight * MINROW) - LEADING,
        maxh+1,
        maxv+1
      );
      size = GrowWindow(wp, *rpt, &br);

      if (size == 0)
      	goto nochange;
      	
      hz = (short)size - (2 * HBORDER + SCROLLW);
      hz /= v->maxw;
      if (hz < MINCOL)
        hz = MINCOL;
      if (hz > NCOL)
        hz = NCOL;
      v->ncol = hz;
      hz = (2 * HBORDER) + SCROLLW + (hz) * v->maxw;
      
      vz = (short) (size >> 16) - (2 * VBORDER - LEADING);
      vz /= v->textheight;
      if (vz < MINROW)
        vz = MINROW;
      if (vz > NROW)
        vz = NROW;
      v->nrow = vz;
      vz = 2 * VBORDER - LEADING + (vz) * v->textheight;
      
      if (v->nrow < NROW || v->ncol < NCOL) {
      	v->savnrow = NROW;
      	v->savncol = NCOL;
      }
      SizeWindow(wp, hz, vz, 1);
    }

    ClipRect(&v->w.port.portRect);
    EraseRect(&v->w.port.portRect);
    redraw = 1;
    InvalRect(&v->w.port.portRect);
    if (v->top + v->nrow > NROW)
    	v->top = NROW - v->nrow;

    /*
     * keep the controls form being drawn twice
     * by setting the clip rect to v=0 h=0
     */
    br = v->w.port.portRect;
    br.right  = br.left;
    br.bottom  = br.top;
    ClipRect(&br);
    
    MoveControl(v->vcontrol, hz-SCROLLW, -1);
    SizeControl(v->vcontrol, SCROLLW+1, vz-SCROLLW+2);
    if (vz == maxv)
      HiliteControl(v->vcontrol,255);
    else
      HiliteControl(v->vcontrol,0);
    SetCtlMax(v->vcontrol, NROW-v->nrow);
    v->termrect = v->w.port.portRect;
    v->termrect.left  += HBORDER;
    v->termrect.right -= HBORDER;
    v->termrect.right -= SCROLLW;
    v->termrect.top   += VBORDER;
    v->termrect.bottom-= VBORDER;
  }

nochange:
  if (show >= 0) {
    if (show) {
	ShowWindow(wp);
	ShowControl(v->vcontrol);
    }
    else
	HideWindow(wp);
  }

  if (redraw) {
    br = v->w.port.portRect;
    br.left = br.right - SCROLLW;
    ClipRect(&br);
    DrawGrowIcon((WindowPtr)&v->w);
    DrawControls((WindowPtr)&v->w);
    br.right -= SCROLLW;
    br.left = v->w.port.portRect.left;
    ClipRect(&br);
    /*EraseRect(&br);*/
    ClipRect(&v->termrect);
    vdupaintlines(v->top, v->nrow);
    ValidRect(&v->w.port.portRect);
  }
  
  vducursor(1);
}

