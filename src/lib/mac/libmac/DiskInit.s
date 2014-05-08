	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e9 (pack number = 0) Short DIBadMount
!	  (
!		Point where,
!		Long evtMessage
!	  );
!
	.extern	_DIBadMount
_DIBadMount:
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
	move.l	0xc(a6),-(sp)
	move.w	#0,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
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
!	romcall 0xa9e9 (pack number = 6) OSErr DIFormat
!	  (
!		Short drvNum
!	  );
!
	.extern	_DIFormat
_DIFormat:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	#6,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
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
!	romcall 0xa9e9 (pack number = 2) void DILoad();
!
	.extern	_DILoad
_DILoad:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.w	#2,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
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
!	romcall 0xa9e9 (pack number = 4) void DIUnload();
!
	.extern	_DIUnload
_DIUnload:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.w	#4,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
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
!	romcall 0xa9e9 (pack number = 8) OSErr DIVerify
!	  (
!		Short drvNum
!	  );
!
	.extern	_DIVerify
_DIVerify:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	#8,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
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
!	romcall 0xa9e9 (pack number = 10) OSErr DIZero
!	  (
!		Short drvNum,
!		inStringPtr volName
!	  );
!
	.extern	_DIZero
_DIZero:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xa(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.w	#10,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e9
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL11
	move.l	(sp)+,a7
LL11:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

