#
! This is the C run-time start-off routine for STAND ALONE MAC APPLICATIONS.
! It's job is to relocate itself and hand execution to _main.
	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.data

	.extern	_etext
	.extern	_edata
	.extern	_end

	.define	EXIT
	.define	.trpim
	.define	.trppc
	.define	_qd
	.define	saveda5
	.define	savedsp

	.globl	start
	.globl	_relocate

	.sect	.text
	.extern	_main
start: 	lea 	0(pc),a0
	sub.l 	#32,a0
	move.l 	#0,-(sp)
	move.l 	#0,-(sp)
	move.l 	a0,-(sp)
	bsr	_relocate
	add.l	#12,sp
	tst.l	d0
	bne	EXIT		! relocation failed
	move.l	a5,saveda5
	move.l	a5,a0
	sub.l	#210,a0
	move.l	a0,_qd
	move.l 	#0,-(sp)
	move.w 	#0,-(sp)
	jsr	_main
	add.l	#6,sp
EXIT:	.data2  0xa9f4

	.sect	.data
_qd:	.data4	0
.trpim:	.data2	0
.trppc:	.data4	0
saveda5:.data4	0
savedsp:.data4	0
