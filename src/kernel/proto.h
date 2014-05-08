/* misc lib functions */
_PROTOTYPE( int receive, ( int source, message *mess ) );
_PROTOTYPE( int send, ( int dest, message *mess ) );
_PROTOTYPE( void memcpy, ( char *dest, char *src, int cnt ) );
_PROTOTYPE( void printk, ( _CONST char *mess, ... ) );
_PROTOTYPE( int strlen, ( _CONST char *string ) );
_PROTOTYPE( char *c2pstr, ( _CONST char *string ) );

/* mpx.s */
_PROTOTYPE( int lock, ( void ) );
_PROTOTYPE( void restore, ( int level ) );
_PROTOTYPE( void unlock, ( void ) );
_PROTOTYPE( int test_and_set, ( int *flag ) );
_PROTOTYPE( reg_t getksp, (void) );
_PROTOTYPE( reg_t geta5, ( void ) );
_PROTOTYPE( long getgp, (void) );
_PROTOTYPE( void restart, (void) );

/* copy68k.s */
_PROTOTYPE( void flipclicks, (phys_clicks src, phys_clicks dst, phys_clicks count) );
_PROTOTYPE( void zeroclicks, (phys_clicks dest, phys_clicks count) );
_PROTOTYPE( void copyclicks, (phys_clicks src, phys_clicks dst, phys_clicks count) );
_PROTOTYPE( void phys_copy, ( phys_bytes src, phys_bytes dest, phys_bytes count ) );

/* clock.c */
_PROTOTYPE( void clock_task, ( void ) );
_PROTOTYPE( void clock_handler, ( void ) );
#if (MACHINE == MACINTOSH)
_PROTOTYPE( void start_clock, ( void ) );
_PROTOTYPE( void end_clock, ( void ) );
#endif

/* console.c */
_PROTOTYPE( void scr_init, ( int minor ) );
_PROTOTYPE( void flush, ( struct tty_struct *tp ) );
_PROTOTYPE( void console, ( struct tty_struct *tp ) );
_PROTOTYPE( void scr_cancel, ( int minor ) );
_PROTOTYPE( void out_char, ( struct tty_struct *tp, char c ) );
_PROTOTYPE( void putc, ( char c ) );
_PROTOTYPE( void vdutrack, ( long line, long *startpt ) );
_PROTOTYPE( void vdusetparams, (long ln, int new, int font,
			int fsize, int front, int resize, long *rpt, int show, int redraw, int zoom) );

/* cstart.c */
_PROTOTYPE( void cstart, ( struct qd *q, long a5, long memat,
			 long size, long kc, long kd, long mc, long md, long fc, long fd, long ic, long id ) );

/* dmp.c */
_PROTOTYPE( void p_dmp, ( void ) );
_PROTOTYPE( void map_dmp, ( void ) );
_PROTOTYPE( void prname, ( int i ) );
_PROTOTYPE( void set_name, ( int proc_nr, char *ptr ) );
_PROTOTYPE( void reg_dmp, ( struct proc *rp, int dummy ) );
_PROTOTYPE( void mem_dmp, ( char *adr, int len ) );
_PROTOTYPE( void tty_dmp, ( void ) );

/* exception.c */
_PROTOTYPE( void execption, ( int vec_nr ) );
_PROTOTYPE( void set_exceptions, ( int which ) );

/* floppy.c */
_PROTOTYPE( void floppy_task, ( void ) );
_PROTOTYPE( void f_close_all, ( void ) );

/* idle.c */
_PROTOTYPE( void idle_task, ( void ) );
_PROTOTYPE( void idle_wakeup, ( void ) );
_PROTOTYPE( int isfixedwidth, ( char *fname ) );
_PROTOTYPE( void quit, ( int dosync ) );

/* keyboard.c */
_PROTOTYPE( void kb_init, ( int minor ) );
_PROTOTYPE( void kb_active, ( int minor ) );
_PROTOTYPE( int kb_read, ( int minor, char **bufindirect, unsigned char *odoneindirect ) );
_PROTOTYPE( void kb_paste, ( char *chars, int count ) );
_PROTOTYPE( void kb_char, ( int scode, int mod ) );
_PROTOTYPE( int make_break, ( char ch ) );
_PROTOTYPE( char *letter_code, ( int scode ) );
_PROTOTYPE( int func_key, ( unsigned char ch ) );
_PROTOTYPE( void reboot, ( void ) );
_PROTOTYPE( void wreboot, ( void ) );

/* main.c */
#ifdef THINK_C
_PROTOTYPE( void _main, ( void ) );
#else
_PROTOTYPE( void main, ( void ) );
#endif
_PROTOTYPE( void checksp, ( void ) );
_PROTOTYPE( void panic, ( char *s, int n ) );
_PROTOTYPE( void override, ( char *name ) );

/* memory.c */
_PROTOTYPE( void mem_task, ( void ) );

/* misc.c */
_PROTOTYPE( void mem_init, ( void ) );
_PROTOTYPE( int do_vrdwt, ( message *m_ptr, int (*do_rdwt )()) );

/* printer.c */
_PROTOTYPE( void printer_task, ( void ) );
_PROTOTYPE( void docsetup, ( void ) );
_PROTOTYPE( void jobsetup, ( void ) );

/* proc.c */
_PROTOTYPE( void interrupt, ( int task ) );
_PROTOTYPE( int sys_call, ( int function, int src_dest, message *m_ptr ) );
_PROTOTYPE( int lock_mini_send, ( struct proc *caller_ptr, int dest, message *m_ptr ) );
_PROTOTYPE( void lock_pick_proc, ( void ) );
_PROTOTYPE( void lock_ready, ( struct proc *rp ) );
_PROTOTYPE( void lock_sched, ( void ) );
_PROTOTYPE( void lock_unready, ( struct proc *rp ) );
_PROTOTYPE( void unhold, ( void ) );

/* rs232.c */
_PROTOTYPE( int rs_ioctl, ( int minor, int mode, int speeds ) );
_PROTOTYPE( void rs_setc, ( int minor, int xoff, int xon ) );
_PROTOTYPE( int rs_init, ( int minor ) );
_PROTOTYPE( void rs_close, ( void ) );
_PROTOTYPE( void rs_inhibit, ( int minor, int inhibit ) );
_PROTOTYPE( void rs_istop, ( int minor ) );
_PROTOTYPE( void rs_istart, ( int minor ) );
_PROTOTYPE( int rs_check, ( void ) );
_PROTOTYPE( int rs_read, ( int minor, char **bufindirect, unsigned char *odoneindirect ) );
_PROTOTYPE( void rs_ocancel, ( int minor ) );
_PROTOTYPE( void rs_write, ( int minor, char *buf, int nbytes ) );

/* setup.c */
_PROTOTYPE( void setup, ( struct config *cf, int dbox, int warn ) );
_PROTOTYPE( char *fullname, ( int vol, char *s ) );

/* shadow.c */
#if (CHIP == M68000)
_PROTOTYPE( void mkshadow, ( struct proc *p, phys_clicks c2 ) );
_PROTOTYPE( void rmshadow, ( struct proc *p, phys_clicks *basep, phys_clicks *sizep ) );
_PROTOTYPE( void unshadow, ( struct proc *p ) );
#endif

/* system.c */
_PROTOTYPE( void sys_task, ( void ) );
_PROTOTYPE( void cause_sig, ( int proc_nr, int sig_nr ) );
_PROTOTYPE( void inform, ( void ) );
_PROTOTYPE( phys_bytes numap, ( int proc_nr, vir_bytes vir_addr, vir_bytes bytes ) );
_PROTOTYPE( phys_bytes umap, ( struct proc *rp, int seg, vir_bytes vir_addr, vir_bytes bytes ) );
_PROTOTYPE( void alloc_segments, ( struct proc *rp ) );

/* table.c */
_PROTOTYPE( void ___dummy, ( void ) );

/* tty.c */
_PROTOTYPE( void tty_task, ( void ) );
_PROTOTYPE( void finish, ( struct tty_struct *tp, int code ) );
_PROTOTYPE( void sigchar, ( struct tty_struct *tp, int sig ) );
_PROTOTYPE( void tty_wakeup, ( void ) );

/* wini.c */
_PROTOTYPE( void winchester_task, ( void ) );
_PROTOTYPE( void w_close_all, ( void ) );
