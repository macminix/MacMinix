	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 3) OSErr SCSICmd
!	  (
!		Ptr buffer,
!		Short count
!	  );
!
	.extern	_SCSICmd
_SCSICmd:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	#3,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL1
	move.l	(sp)+,a7
LL1:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 4) OSErr SCSIComplete
!	  (
!		Short *stat,
!		Short *message,
!		Long wait
!	  );
!
	.extern	_SCSIComplete
_SCSIComplete:
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
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	#4,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL3
	move.l	(sp)+,a7
LL3:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 1) OSErr SCSIGet();
!
	.extern	_SCSIGet
_SCSIGet:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	clr.w	-(sp)
	move.w	#1,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL5
	move.l	(sp)+,a7
LL5:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 8) OSErr SCSIRBlind
!	  (
!		Ptr tibPtr
!	  );
!
	.extern	_SCSIRBlind
_SCSIRBlind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	#8,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL7
	move.l	(sp)+,a7
LL7:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 5) OSErr SCSIRead
!	  (
!		Ptr tibPtr
!	  );
!
	.extern	_SCSIRead
_SCSIRead:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	#5,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL9
	move.l	(sp)+,a7
LL9:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 0) OSErr SCSIReset();
!
	.extern	_SCSIReset
_SCSIReset:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.w	-(sp)
	move.w	#0,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL11
	move.l	(sp)+,a7
LL11:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 2) OSErr SCSISelect
!	  (
!		Short targetID
!	  );
!
	.extern	_SCSISelect
_SCSISelect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	#2,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL13
	move.l	(sp)+,a7
LL13:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 10) Short SCSIStat();
!
	.extern	_SCSIStat
_SCSIStat:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	clr.w	-(sp)
	move.w	#10,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL15
	move.l	(sp)+,a7
LL15:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 9) OSErr SCSIWBlind
!	  (
!		Ptr tibPtr
!	  );
!
	.extern	_SCSIWBlind
_SCSIWBlind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	#9,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL17
	move.l	(sp)+,a7
LL17:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa815 (pack number = 6) OSErr SCSIWrite
!	  (
!		Ptr tibPtr
!	  );
!
	.extern	_SCSIWrite
_SCSIWrite:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	#6,-(sp)
	move.l	saveda5,a5
	.data2	0xa815
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL19
	move.l	(sp)+,a7
LL19:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

