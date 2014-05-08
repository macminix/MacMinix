/* This file contains a simple exception handler.  Exceptions in user
 * processes are converted to signals.  Exceptions in the kernel, MM and
 * FS cause a panic.
 */

#include "kernel.h"
#include <signal.h>
#include "proc.h"

#define BUS_ERROR	2		/* bus error vector # */
#define ADDR_ERROR	3		/* address error vector # */
#define ILLEGAL		4		/* illegal instruction error vector # */
#define ZERO_DIV	5		/* divide by zero vector # */
#define CHK		6		/* chk vector # */
#define TRAPV		7		/* trapv vector # */
#define PRIV_VIOL	8		/* priv violation vector # */
#define TRACE		9		/* trace vector # */
#define ALINE		10		/* mac os call */
#define BKPT		11		/* breakpoint trap vector # */
#define TRAP0		32		/* sys call vector # */
#define TRAP1		33		/* bkpt */
#define FPCP_BRANCH	48		/* floating point */
#define FPCP_INEXACT	49		/* floating point */
#define FPCP_ZERO_DIV	50		/* floating point */
#define FPCP_UNDERFLOW	51		/* floating point */
#define FPCP_OP_ERROR	52		/* floating point */
#define FPCP_OVERFLOW	53		/* floating point */
#define FPCP_NAN	54		/* floating point */

#ifdef THINK_C
extern char CPUFlag : 0x12f;
#else
extern char CPUFlag;
#endif

typedef void *vector;

PUBLIC int running;

_PROTOTYPE( void exception, ( unsigned vec_nr ) );
FORWARD _PROTOTYPE( int inspace, ( struct proc *rp, vir_bytes addr ) );
FORWARD _PROTOTYPE( void set_vec, ( int vec_nr, vector addr ) );
FORWARD _PROTOTYPE( vector get_curvec, ( int vec_nr ) );

/*===========================================================================*
 *                              set_exceptions                               * 
 *===========================================================================*/
PUBLIC void set_exceptions(which)
int which;
{
/* Set up new exception vectors. */
  extern void sys(), bus_error(), addr_error(), illegal();
  extern void zero_div(), chk(), trapv(), priv_viol(), trace();
  extern void aline(), bkpt(), trap1();
  extern void fpcp_branch(), fpcp_inexact(), fpcp_zero_div();
  extern void fpcp_underflow(), fpcp_op_error(), fpcp_overflow();
  extern void fpcp_nan();

  struct exception {
    unsigned int vec_nr;
    vector newvec;
    vector oldvec;
  };
  static struct exception vectable[] = {
    BUS_ERROR, (vector)bus_error, 0,
    ADDR_ERROR, (vector)addr_error, 0,
    ILLEGAL, (vector)illegal, 0,
    ZERO_DIV, (vector)zero_div, 0,
    CHK, (vector)chk, 0,
    TRAPV, (vector)trapv, 0,
    PRIV_VIOL, (vector)priv_viol, 0,
    TRACE, (vector)trace, 0,
    BKPT, (vector)bkpt, 0,
    TRAP0, (vector)sys, 0,
    TRAP1, (vector)trap1, 0,
    FPCP_BRANCH, (vector)fpcp_branch, 0,
    FPCP_INEXACT, (vector)fpcp_inexact, 0,
    FPCP_ZERO_DIV, (vector)fpcp_zero_div, 0,
    FPCP_UNDERFLOW, (vector)fpcp_underflow, 0,
    FPCP_OP_ERROR, (vector)fpcp_op_error, 0,
    FPCP_OVERFLOW, (vector)fpcp_overflow, 0,
    FPCP_NAN, (vector)fpcp_nan, 0
  };
  static int nvec = sizeof(vectable)/sizeof(vectable[0]);
  int i;
  register struct exception *vt = vectable;
  
  if (which == 0) {
    for (i = 0; i < nvec; i++, vt++) {
      vt->oldvec = get_curvec(vt->vec_nr);
      set_vec(vt->vec_nr, vt->newvec);
    }
    running = 1;
  }
      
  if (which == 1) {
    for (i = 0; i < nvec; i++, vt++)
      set_vec(vt->vec_nr, vt->oldvec);
    running = 0;
  }
}


/*==========================================================================*
 *				exception				    *
 *==========================================================================*/
PUBLIC void exception(vec_nr)
unsigned vec_nr;
{
  u16_t fmt;
  struct ex_s {
	char *msg;
	int signum;
  };
  static struct ex_s ex_data[] = {
  	NIL_PTR, SIGILL,			/* Reset sp */
  	NIL_PTR, SIGILL,			/* reset pc */
	"Bus Error", SIGBUS,
	"Address Error", SIGSEGV,
	"Illegal Instruction", SIGILL,
	"Divide by zero", SIGFPE,
	"CHK Instruction", SIGILL,
	"TRAPV Instruction", SIGILL,
	"Privilege violation", SIGILL,
	"Trace", SIGTRAP,
	"Line 1010 emulator", SIGEMT,		/* Mac OS Call vector */

	"Breakpoint", SIGEMT,
	"Reserved 12", SIGILL,
	"Coprocessor protocol violation", SIGFPE,
	"Format Error", SIGFPE,
	"Unitialized interrupt", SIGILL,
	"Reserved 16", SIGILL,
	"Reserved 17", SIGILL,
	"Reserved 18", SIGILL,
	"Reserved 19", SIGILL,
	"Reserved 20", SIGILL,

	"Reserved 21", SIGILL,
	"Reserved 22", SIGILL,
	"Reserved 23", SIGILL,
	"Spurious interrupt", SIGILL,
	"Level 1 Interrupt", SIGILL,
	"Level 2 Interrupt", SIGILL,
	"Level 3 Interrupt", SIGILL,
	"Level 4 Interrupt", SIGILL,
	"Level 5 Interrupt", SIGILL,
	"Level 6 Interrupt", SIGILL,

	"Level 7 Interrupt", SIGILL,
	"Trap 0", SIGILL,
	"Trap 1", SIGILL,
	"Trap 2", SIGILL,
	"Trap 3", SIGILL,
	"Trap 4", SIGILL,
	"Trap 5", SIGILL,
	"Trap 6", SIGILL,
	"Trap 7", SIGILL,
	"Trap 8", SIGILL,

	"Trap 9", SIGILL,
	"Trap 10", SIGILL,
	"Trap 11", SIGILL,
	"Trap 12", SIGILL,
	"Trap 13", SIGILL,
	"Trap 14", SIGILL,
	"Trap 15", SIGILL,
	"FPCP unordered condition", SIGFPE,
	"FPCP inexact result", SIGFPE,

	"FPCP divide by zero", SIGFPE,
	"FPCP underflow", SIGFPE,
	"FPCP operand error", SIGFPE,
	"FPCP overflow", SIGFPE,
	"FPCP NAN", SIGFPE,
	"Unexpected interrupt vector >= 55", SIGILL,
  };
  register struct ex_s *ep;

  if (vec_nr >= 0 && vec_nr < sizeof(ex_data)/sizeof(ex_data[0]))
	ep = &ex_data[vec_nr];
  else
	ep = &ex_data[sizeof(ex_data)/sizeof(ex_data[0])-1];

#ifdef E_DEBUG
  printf("Vector = %s(%d) proc = %d (savtt=0x%x)\r\nreturn to 0x%X, sr = %x inspace = %d\r\n",
  	 ep->msg == NIL_PTR ? "Unknown" : ep->msg,
  	 vec_nr, proc_number(proc_ptr), proc_ptr->p_reg.savtt,
  	 proc_ptr->p_reg.pc, proc_ptr->p_reg.psw,
  	 inspace(proc_ptr, (vir_bytes)proc_ptr->p_reg.pc));
#endif E_DEBUG

  if (CPUFlag >= 2) {
  	/* modify the stack pointer to remove the extended formats. This has
  	   to be done because when signals are caught and processed, the process
  	   can't use rte to restore the environment that caused the
  	   exception.  The process should somehow return to the kernel, which
  	   should then do the rte on the processes behalf. */
  	fmt = proc_ptr->p_reg.savtt & 0xf000;
    	switch(fmt) {
		case 0x0000: break;
		case 0x1000: break;				/* 4 word stack frame */
		case 0x2000: proc_ptr->p_reg.sp +=  4; break;
		case 0x9000: proc_ptr->p_reg.sp += 12; break;
		case 0xa000: proc_ptr->p_reg.sp += 24; break;
		case 0xb000: proc_ptr->p_reg.sp += 84; break;
		default:     panic("bad exception format word", NO_NUM);
    	}
    	proc_ptr->p_reg.savtt &= 0x0fff;			/* reset to format 0 */
  }
  
  if (k_reenter == 0 && isuserp(proc_ptr)) {
      	if (vec_nr == TRACE && !inspace(proc_ptr, (vir_bytes)proc_ptr->p_reg.pc))
          return;
        cause_sig(proc_number(proc_ptr), ep->signum);
        return;
  }
        
  /* This is not supposed to happen. */
  if (ep->msg == NIL_PTR)
	printf("\r\nReserved exception %d\r\n", vec_nr);
  else
	printf("\r\n%s\r\n", ep->msg);
  printf("process number %d, pc = 0x%lx\r\n",
	 proc_number(proc_ptr),
  	 (unsigned long) proc_ptr->p_reg.pc);
  panic("exception in kernel, mm or fs", NO_NUM);
}



/*===========================================================================*
 *				in_space				     * 
 *===========================================================================*/
PRIVATE int inspace(rp, vir_addr)
register struct proc *rp;	/* pointer to proc table entry for process */
vir_bytes vir_addr;		/* virtual address */
{
/* Determine if the given address is in the address space of the proc. */
  vir_clicks vc;		/* the virtual address in clicks */

  vc = vir_addr >> CLICK_SHIFT;	/* click */

  if (vc >= rp->p_map[T].mem_vir &&
      vc <= rp->p_map[T].mem_vir + rp->p_map[T].mem_len)
	return( 1 );
  if (vc >= rp->p_map[D].mem_vir &&
      vc <= rp->p_map[D].mem_vir + rp->p_map[D].mem_len)
	return( 1 );
  if (vc >= rp->p_map[S].mem_vir &&
      vc <= rp->p_map[S].mem_vir + rp->p_map[S].mem_len)
	return( 1 );
   return( 0 );
}


/*===========================================================================*
 *                                   set_vec                                 * 
 *===========================================================================*/
PRIVATE void set_vec(vec_nr, addr)
int vec_nr;			/* which vector */
vector addr;			/* where to start */
{
/* Set up an interrupt vector. */
  vector *lo = (vector *) 0;
   
  lo[vec_nr] = (vector)addr;
}



/*===========================================================================*
 *                                   get_curvec                              * 
 *===========================================================================*/
PRIVATE vector get_curvec(vec_nr)
int vec_nr;			/* which vector */
{
/* Set up an interrupt vector. */
  vector *lo = (vector *) 0;
   
  return(lo[vec_nr]);
}
