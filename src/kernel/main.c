/* This file contains the main program of MINIX.  The routine main()
 * initializes the system and starts the ball rolling by setting up the proc
 * table, interrupt vectors, and scheduling each task to run to initialize
 * itself.
 * 
 * The entries into this file are:
 *   main:		MINIX main program
 *   panic:		abort MINIX due to a fatal error
 */

#include "kernel.h"
#include <signal.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include "proc.h"
#include <mac/Segments.h>

#define SAFETY            32	/* safety margin for stack overflow (bytes) */

/*===========================================================================*
 *                                   main                                    * 
 *===========================================================================*/
#ifdef THINK_C
PUBLIC void _main()
#else
PUBLIC void main()
#endif
{
/* Start the ball rolling. */

  register struct proc *rp;
  register int t;
  int sizeindex;
  phys_clicks base_click;
  phys_clicks text_base;
  vir_clicks text_clicks;
  vir_clicks data_clicks;
  phys_bytes phys_b;
  int stack_size;
  reg_t ktsb;			/* kernel task stack base */

  /* Clear the process table.
   * Set up mappings for proc_addr() and proc_number() macros.
   */
  for (rp = BEG_PROC_ADDR, t = -NR_TASKS; rp < END_PROC_ADDR; ++rp, ++t) {
	rp->p_flags = P_SLOT_FREE;
	rp->p_nr = t;		/* proc number from ptr */
	(pproc_addr + NR_TASKS)[t] = rp;	/* proc ptr from number */
  }

  /* Set up proc table entries for tasks and servers.  Be very careful about
   * sp, since in real mode the 3 words prior to it will be clobbered when
   * the kernel pushes pc, cs, and psw onto the USER's stack when starting
   * the user the first time.  If an interrupt happens before the user loads
   * a better stack pointer, these 3 words will be used to save the state,
   * and the interrupt handler will use another 3, and a debugger trap will
   * use another 3 or 4, and an "impossible" non-maskable interrupt may use
   * more!  This means that with INIT_SP == 0x1C, user programs must leave
   * the memory between 0x0008 and 0x001B free.  FS currently violates this
   * by using the word at 0x0008.
   */

  base_click = code_base >> CLICK_SHIFT;	/* base for tasks */

  /* Align stack base suitably. */
  ktsb = ((reg_t) t_stack + (ALIGNMENT - 1)) & ~((reg_t) ALIGNMENT - 1);

  for (rp = BEG_PROC_ADDR, t = -NR_TASKS; rp <= BEG_USER_ADDR; ++rp, ++t) {
	if (t < 0) {
		stack_size = tasktab[t+NR_TASKS].stksize;
		ktsb += stack_size;
		rp->p_reg.sp = ktsb;
		text_base = base_click;	/* tasks are all in the kernel */
		sizeindex = 0;		/* and use the full kernel sizes */
	} else {
		sizeindex = 2 * t + 2;	/* MM, FS, INIT have their own sizes */
	}
	rp->p_reg.pc = (reg_t) tasktab[t + NR_TASKS].initial_pc;
	rp->p_reg.psw = istaskp(rp) ? INIT_TASK_PSW : INIT_PSW;

	text_clicks = sizes[sizeindex];
	data_clicks = sizes[sizeindex + 1];

#if (CHIP == M68000)
	rp->p_reg.savtt = 0;
	rp->p_reg.a5    = geta5();
	rp->p_grafptr   = getgp();
	if (!istaskp(rp) && !isidlehardware(proc_number(rp))) {
   	  rp->p_reg.pc = (reg_t) text_base;
   	  rp->p_reg.pc = rp->p_reg.pc << CLICK_SHIFT;
   	  /* rp->p_reg.sp = (reg_t) text_base+text_clicks;
   	  rp->p_reg.sp = rp->p_reg.sp << CLICK_SHIFT; */
   	  rp->p_reg.sp = getksp();
   	  rp->p_reg.sp += INIT_SP;
        }
	rp->p_map[T].mem_phys = text_base;
	rp->p_map[T].mem_len  = text_clicks;
	rp->p_map[D].mem_phys = text_base + text_clicks;
	rp->p_map[D].mem_len  = data_clicks;
	rp->p_map[S].mem_phys = text_base + text_clicks + data_clicks;
	rp->p_map[S].mem_vir  = data_clicks;	/* empty - stack is in data */
#ifdef THINK_C
    	if (t < 0) {
	  rp->p_map[D].mem_phys = 0;
	  rp->p_map[D].mem_len  = 65000;
    	}
#endif
	rp->p_map[T].mem_vir = rp->p_map[T].mem_phys;
	rp->p_map[D].mem_vir = rp->p_map[D].mem_phys;
#endif

	text_base += text_clicks + data_clicks;	/* ready for next, if server */

	if (!isidlehardware(t)) lock_ready(rp);	/* IDLE, HARDWARE neveready */
	rp->p_flags = 0;
  }

  rp = proc_addr(HARDWARE);
  rp->p_map[D].mem_phys = 0;
  rp->p_map[D].mem_vir = 0;
  rp->p_map[D].mem_len = ~0;
  
  bill_ptr = cproc_addr(IDLE);  /* it has to point somewhere */
  lock_pick_proc();

  /* Now go to the assembly code to start running the current process. */
  restart();
}


/*===========================================================================*
 *                                   panic                                   * 
 *===========================================================================*/
PUBLIC void panic(s,n)
char *s;
int n; 
{
/* The system has run aground of a fatal error.  Terminate execution.
 * If the panic originated in MM or FS, the string will be empty and the
 * file system already syncked.  If the panic originates in the kernel, we are
 * kind of stuck. 
 */

  if (*s != 0) {
	printf("\r\nKernel panic: %s",s); 
	if (n != NO_NUM) printf(" %d", n);
	printf("\r\n");
  }
#if (CHIP == INTEL)
  if (db_exists) {
	db_enabled = TRUE;
	db();
  }
#endif /* CHIP == INTEL */

  wreboot();
}


/*===========================================================================*
 *                                   checksp                                 * 
 *===========================================================================*/
PUBLIC void checksp()
{
  register struct proc *rp;
  register phys_bytes ad;

  rp = proc_ptr;
  if (rp->p_reg.sp < rp->p_splow)
	rp->p_splow = rp->p_reg.sp;
  if (rp->p_map[S].mem_len == 0)
	return;
  if (!isuserp(rp)) return;
  ad = (phys_bytes)rp->p_map[D].mem_vir;
  ad += (phys_bytes)rp->p_map[D].mem_len;
  ad <<= CLICK_SHIFT;
  if ((phys_bytes)rp->p_reg.sp < ad + CLICK_SIZE) {
	/* stack violation */
	printf("Stack low (pid=%d,pc=%X,sp=%X,end=%X)\n",
		rp->p_pid, (long)rp->p_reg.pc,
		(long)rp->p_reg.sp, (long)ad);
  	cause_sig(proc_number(rp), SIGSTKFLT);
  }
}


/*===========================================================================*
 *				override				             *
 *===========================================================================*/
PUBLIC void override(name)
char *name;
{
  short cnt, msg;
  AppFile af;
  char *n;

  CountAppFiles(&msg, &cnt);
  if (cnt == 0)
	return;
  if (msg) 
	panic("Can't print file system files!\n", NO_NUM);
  if (cnt != 1)
	panic("More than one root file system selected", NO_NUM);
   GetAppFiles(1, &af);
   n = fullname(af.vRefNum, c2pstr(af.fName));
   printf("Using %s as root file system\n", n);
   strcpy(name, n);
   ClrAppFiles(1);
}
