#ifdef DEMO
#define NR_CONS            1	/* how many consoles can system handle */
#define	NR_RS_LINES	   0	/* how many rs232 terminals can system handle*/
#else
#define NR_CONS            2	/* how many consoles can system handle */
#define	NR_RS_LINES	   2	/* how many rs232 terminals can system handle*/
#endif
#define KB_IN_BYTES      200   	/* keyboard input queue size */
#define RS_IN_BYTES   (1024 + 2 * RS_IBUFSIZE)	/* RS232 input queue size */
#define TTY_RAM_WORDS    320	/* ram buffer size */
#define TTY_BUF_SIZE     256	/* unit for copying to/from queues */
#define TAB_SIZE           8	/* distance between tabs */
#define TAB_MASK          07	/* mask for tty_column when tabbing */
#define MAX_ESC_PARMS      2	/* number of escape sequence params allowed */

#define ERASE_CHAR      '\b'	/* default erase character */
#define KILL_CHAR        '@'	/* default kill character */
#define INTR_CHAR (char)0177	/* default interrupt character */
#define QUIT_CHAR (char) 034	/* default quit character */
#define XOFF_CHAR (char) 023	/* default x-off character (CTRL-S) */
#define XON_CHAR  (char) 021	/* default x-on character (CTRL-Q) */
#define EOT_CHAR  (char) 004	/* CTRL-D */

/*
 * This MARKER is used as an unambiguous flag for an unescaped end of
 * file character.  It is meaningful only in cooked mode.  0200 should
 * never be used in cooked mode, since that is supposed to be used only
 * for 7-bit ASCII.  Be careful that code only checks
 * for MARKER in cooked mode.  This kludge is needed because
 * chars are stored in char arrays, so there's no way to have a
 * completely out of band value.
 */
#define MARKER   (char) 0200	/* non-escaped CTRL-D stored as MARKER */
#define ESC       (char) 033	/* escape */
#define BRACKET          '['	/* Part of the ESC [ letter escape seq */

#define EVENT_THRESHOLD   64	/* events to accumulate before waking TTY */
#define RS_IBUFSIZE      256	/* RS232 input buffer size */

EXTERN struct tty_struct {
  /* Input queue.  Typed characters are stored here until read by a program. */
  char *tty_inbuf;		/* pointer to input buffer */
  char *tty_inbufend;		/* pointer to place after last in buffer */
  char *tty_inhead;		/* pointer to place where next char goes */
  int tty_ihighwater;		/* threshold for queue too full */
  int tty_ilow_water;		/* threshold for queue not too full */
  int tty_insize;		/* size of buffer */
  char *tty_intail;		/* pointer to next char to be given to prog */
  phys_bytes tty_inphys;	/* physical address of input buffer */
  int tty_incount;		/* # chars in tty_inqueue */
  int tty_lfct;			/* # line feeds in tty_inqueue */
  int (*tty_devread)();		/* routine to read from low level buffers */

  /* Output section. */
  phys_bytes tty_outphys;	/* physical address of output buffer */
  int tty_rwords;		/* number of WORDS (not bytes) in outqueue */
  int tty_org;			/* location in RAM where 6845 base points */
  int tty_vid;			/* current position of cursor in video RAM */
  char tty_esc_state;		/* 0=normal, 1=ESC, 2=ESC[ */
  char tty_esc_intro;		/* Distinguishing character following ESC */
  int tty_esc_parmv[MAX_ESC_PARMS];	/* list of escape parameters */
  int *tty_esc_parmp;		/* pointer to current escape parameter */
  void (*tty_devstart)();	/* routine to start actual device output */

  /* Echo buffer. Echoing is also delayed by output in progress. */
  char *tty_ebufend;		/* end of echo buffer */
  char *tty_etail;		/* tail of echo buffer (head is fixed) */

  /* Terminal parameters and status. */
  int tty_mode;			/* terminal mode set by IOCTL */
  int tty_speed;		/* low byte is ispeed; high byte is ospeed */
  int tty_column;		/* current column number (0-origin) */
  int tty_row;			/* current row (0 at top of screen) */
  char tty_busy;		/* 1 when output in progress, else 0 */
  char tty_escaped;		/* 1 when '\' just seen, else 0 */
  char tty_inhibited;		/* 1 when CTRL-S just seen (stops output) */
  char tty_makebreak;		/* 1 for terminals that interrupt twice/key */
  char tty_waiting;		/* 1 when output process waiting for reply */
  int tty_pgrp;			/* slot number of controlling process */

  /* User settable characters: erase, kill, interrupt, quit, x-on; x-off. */
  char tty_erase;		/* char used to erase 1 char (init ^H) */
  char tty_kill;		/* char used to erase a line (init @) */
  char tty_intr;		/* char used to send SIGINT  (init DEL) */
  char tty_quit;		/* char used for core dump   (init CTRL-\) */
  char tty_xon;			/* char used to start output (init CTRL-Q)*/
  char tty_xoff;		/* char used to stop output  (init CTRL-S) */
  char tty_eof;			/* char used to stop output  (init CTRL-D) */

  /* Information about incomplete I/O requests is stored here. */
  char tty_incaller;		/* process that made the call (usually FS) */
  char tty_inproc;		/* process that wants to read from tty */
  char *tty_in_vir;		/* virtual address where data is to go */
  int tty_inleft;		/* how many chars are still needed */
  char tty_otcaller;		/* process that made the call (usually FS) */
  char tty_outproc;		/* process that wants to write to tty */
  char *tty_out_vir;		/* virtual address where data comes from */
  phys_bytes tty_phys;		/* physical address where data comes from */
  int tty_outleft;		/* # chars yet to be output */
  int tty_cum;			/* # chars output so far */

  /* Cross reference to avoid slow pointer subtraction. */
  int tty_line;			/* line number of this tty less NR_CONS */

  /* Large arrays moved to end for shorter addresses. */
  short tty_ramqueue[TTY_RAM_WORDS];	/* buffer for video RAM */
  char tty_ebuf[32];		/* echo buffer */
} tty_struct[NR_CONS+NR_RS_LINES];


/* Values for the fields. */
#define NOT_ESCAPED        0	/* previous character on this line not '\' */
#define ESCAPED            1	/* previous character on this line was '\' */
#define RUNNING            0	/* no CRTL-S has been typed to stop the tty */
#define STOPPED            1	/* CTRL-S has been typed to stop the tty */
#define INACTIVE           0	/* the tty is not printing */
#define BUSY               1	/* the tty is printing */
#define ONE_INT            0	/* regular terminals interrupt once per char */
#define TWO_INTS           1	/* IBM console interrupts two times per char */
#define NOT_WAITING        0	/* no output process is hanging */
#define WAITING            1	/* an output process is waiting for a reply */
#define SUSPENDED          2	/* like WAITING but different reply type */

EXTERN char tty_buf[TTY_BUF_SIZE];	/* scratch buffer to/from user space */

EXTERN unsigned tty_events;	/* weighted input chars + output completions*/
EXTERN phys_bytes tty_bphys;	/* physical address of tty_buf buffer */

/* Appropiately sized buffers for keyboard and RS232 lines. */
EXTERN char kb_inbuf[NR_CONS][KB_IN_BYTES];
EXTERN char rs_inbuf[NR_RS_LINES][RS_IN_BYTES];
