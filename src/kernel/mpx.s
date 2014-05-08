#
! assembler support routines

#define LOCK            or.w	#0x0700,sr
#define UNLOCK          and.w	#0xF8FF,sr
#define RTE		rte

sava6 	= 56
savsp 	= 60
savsr 	= 64
savpc 	= 66
savtt 	= 70
savgp   = 72
proc_nr = 88

TASK_Q	= 0
PRINTER	= -7
FLOPPY	= -5
WINCHESTER = -6

	.globl _CPUFlag; _CPUFlag=0x012f
	.globl _Key1Trans; _Key1Trans=0x029e
	.globl _Key2Trans; _Key2Trans=0x02a2
	.globl _CacheCom; _CacheCom=0x039c
	.globl _KbdType; _KbdType=0x021e

	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss

	.sect	.text

!*===========================================================================*
!*				clocktick			     	     *
!*===========================================================================*
	.define _clocktick
_clocktick:
	move.l	a0,-(sp)
	move.l	d0,-(sp)
	move.l  _VIA,a0
	move.b	0x1a00(a0),-(sp)		! save interrupt flag reg
	tst.b	_CPUFlag
	beq	noformat
	move.w	#0,-(sp)
    noformat:
	pea	ret
	move.w	sr,-(sp)
	move.l	_clk_vec,a0
	jmp	(a0)
		
     ret:
      	add.b	#1,_k_reenter

	move.b	(sp)+,d0			! check if VRT int
	and.b	#0x2,d0
	beq	go
		
	tst.w	_running			! test if I am the current ap running
	beq	go

	move.l	10(sp),a0			! check pc
	cmp.l	_ApplZone,a0
	blt	go
	cmp.l	_CurStackBase,a0
	bgt	go

    	move.l	savedsp,a0			! test if mac call
	cmp.l	a7,a0
    	bge	go
    	
	movem.l	a1-a2/d1-d3,-(sp)
	jsr	_clock_handler
	movem.l	(sp)+,a1-a2/d1-d3

	move.l	_proc_ptr,a0			! don't switch away from kernel proc
	tst.w	proc_nr(a0)
	bmi	go

	cmp.l	#0,_rdy_head+TASK_Q		! any task now ready?
	beq	go				! no: branch and return from interrupt

	move.l	(sp)+,d0	
	move.l	(sp)+,a0
	LOCK
	sub.b	#1,_k_reenter
	bge	done
	jsr	save
	jsr	_lock_pick_proc
	lea 	_restart,a0
	jmp	(a0)
	
     intonint:
        add.l	#1,_pending_ticks
     go:
	move.l	(sp)+,d0	
	move.l	(sp)+,a0
     nope:
	LOCK
	sub.b	#1,_k_reenter
     done:
	rte

!*===========================================================================*
!*				XOpenDeskAcc				     *
!*===========================================================================*
!  slightly modified version of OpenDeskAcc

	.define _XOpenDeskAcc
_XOpenDeskAcc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9b6
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL3
	move.l	(sp)+,a7
LL3:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts


!*===========================================================================*
!*				ascii				     	     *
!*===========================================================================*
! Translate virtual key code to ascii equiv.

	.define _ascii
_ascii:
  	link	a6,#0
	move.l	0x8(a6),a0
	move.w	0xc(a6),d2
	move.w	0xe(a6),d1
	jsr	(a0)
	unlk	a6
	rts

!*===========================================================================*
!*				trap				     	     *
!*===========================================================================*
!  exception vectors

#define EXCEPTION(name, num) \
	.define name; \
name: \
  	jsr	save; \
	move.w	num,-(sp); \
	UNLOCK; \
	jsr	_exception; \
	add.l	#2,sp; \
	LOCK; \
	move.w	d0,-(sp); \
	lea 	_restart,a0; \
	jmp	(a0)

EXCEPTION(_bus_error, #2)
EXCEPTION(_addr_error, #3)
EXCEPTION(_illegal, #4)
EXCEPTION(_zero_div, #5)
EXCEPTION(_chk, #6)
EXCEPTION(_trapv, #7)
EXCEPTION(_priv_viol, #8)
EXCEPTION(_trace, #9)
EXCEPTION(_bkpt, #11)
EXCEPTION(_trap1, #33)
EXCEPTION(_fpcp_branch, #48)
EXCEPTION(_fpcp_inexact, #49)
EXCEPTION(_fpcp_zero_div, #50)
EXCEPTION(_fpcp_underflow, #51)
EXCEPTION(_fpcp_op_error, #52)
EXCEPTION(_fpcp_overflow, #53)
EXCEPTION(_fpcp_nan, #54)


!*===========================================================================*
!*				sys				     	     *
!*===========================================================================*
!  System call stuff

	.define _sys
_sys:
  	jsr	save
	move.l	_proc_ptr,a1
	move.l	a1,-(sp)
	move.l	a0,-(sp)
	move.w	d1,-(sp)
	move.w	d0,-(sp)
	UNLOCK
	jsr	_sys_call
	add.l	#8,sp
	LOCK
	move.l	(sp)+,a1
	move.l	d0,(a1)
	move.w	d0,-(sp)
	lea 	_restart,a0
	jmp	(a0)

save:
	LOCK
	add.b	#1,_k_reenter
	bne	push_stack
	move.l	a6,-(sp)
	move.l	_proc_ptr,a6
	movem.l	d0-d7/a0-a5,(a6)
	move.l	(sp)+,sava6(a6)
	tst.b	_CPUFlag
	beq	is68000
	lea	12(sp),a1
	bra	continue
is68000:
	lea	10(sp),a1
continue:
	btst	#5,4(sp)
	bne	L5
	move.l	usp,a1
L5:	move.l	a1,savsp(a6)
	move.l	(sp)+,a1
	move.w	(sp)+,savsr(a6)
	move.l	(sp)+,savpc(a6)
!
! 68000's do not have format words
!
	tst.b	_CPUFlag
	beq	L100
	move.w	(sp)+,savtt(a6)	
L100:
	move.l	saveda5,a5
	move.l	(a5),a5
	move.l	(a5),savgp(a6)

	move.l	#_k_stack+8192,sp
	jmp	(a1)

push_stack:
	move.l	(sp)+,saverts
	movem.l	d0-d2/a0-a1,-(sp)
	move.l	saverts,a1
	jmp	(a1)

	.define _restart
_restart:
  	LOCK
  	tst.l	_held_head
	beq	none_held
	jsr	_unhold
none_held:

	sub.b	#1,_k_reenter
	bge	restart1

! check if stack has run into data
	jsr	_checksp

	move.l	_proc_ptr,a6
	move.l	savsp(a6),a0
	btst	#5,savsr(a6)
	bne	L6
	move.l	a0,usp
	bra	L7
L6:	move.l	a0,sp
L7: 	
	! 68000's do not have a format word as part of the
	! stack frame.  So do not restore it.
	tst.b	_CPUFlag
	beq	L101
	move.w	savtt(a6),-(sp)
L101:
	move.l	savpc(a6),-(sp)
	move.w	savsr(a6),-(sp)
	move.l	saveda5,a5
	move.l	(a5),a5
	move.l	savgp(a6),(a5)
	movem.l	(a6),d0-d7/a0-a6
	RTE

restart1:
	movem.l	(sp)+,d0-d2/a0-a1
	RTE

!*===========================================================================*
!*				lock				     	     *
!*===========================================================================*
! lock the processor

	.define _lock
_lock:
  	move.w	sr,d0
	and.w	#0x700,d0
	or.w	#0x700,sr
	rts

!*===========================================================================*
!*				restore				             *
!*===========================================================================*
! restore the sr to previous value

	.define _restore
_restore:
  	move.w	sr,d0
	and.w	#0xF8FF,d0
	or.w	4(sp),d0
	move.w	d0,sr
	rts

!*===========================================================================*
!*				unlock				             *
!*===========================================================================*
! unlock processor

	.define _unlock
_unlock:
  	move.w	sr,d0
	and.w	#0xF8FF,sr
	rts

!*===========================================================================*
!*				rs_write_int			             *
!*===========================================================================*
! serial line write completion interrupt

	.define _rs_writeint
_rs_writeint:
	add.b	#1,_k_reenter
   	move.l	a0,-(sp)
	jsr	_rs_out_int
	add.l	#4,sp
	sub.b	#1,_k_reenter
	rts

!*===========================================================================*
!*				f_int			             	     *
!*===========================================================================*
! floppy completion interrupt

	.define _f_int
_f_int:
	add.b	#1,_k_reenter
	move.w	#FLOPPY,-(sp)
  	jsr	_interrupt
  	lea	2(sp),sp
	sub.b	#1,_k_reenter
  	rts

!*===========================================================================*
!*				w_int			             	     *
!*===========================================================================*
! wini completion interrupt

	.define _w_int
_w_int:
	add.b	#1,_k_reenter
	move.w	#WINCHESTER,-(sp)
  	jsr	_interrupt
  	lea	2(sp),sp
	sub.b	#1,_k_reenter
  	rts

!*===========================================================================*
!*				pr_int			             	     *
!*===========================================================================*
! printer completion interrupt

	.define _pr_int
_pr_int:
	add.b	#1,_k_reenter
	move.w	#PRINTER,-(sp)
  	jsr	_interrupt
  	lea	2(sp),sp
	sub.b	#1,_k_reenter
  	rts

!*===========================================================================*
!*				test_and_set				     *
!*===========================================================================*
! PUBLIC int test_and_set(int *flag);
! Set the flag to TRUE, indivisibly with getting its old value.
! Return old flag.

	.define _test_and_set
_test_and_set:
	move.l	4(sp),a0
	tas	(a0)
	beq	L1
	move.l	#1,d0
	rts
L1: 	move.l	#0,d0
	rts

!*===========================================================================*
!*				Debugger				     *
!*===========================================================================*
! Drop into macsbug
	.define _Debugger
_Debugger:
	.data2	0xa9ff
	rts
