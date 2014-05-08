	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ed (pack number = 0) void IUDateString
!	  (
!		Long dateTime,
!		DateForm form,
!		outStringPtr result
!	  );
!
	.extern	_IUDateString
_IUDateString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.w	#0,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	tst.l	savedsp
	beq	LL1
	move.l	(sp)+,a7
LL1:
	pea	0xe(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ed (pack number = 14) void IUDatePString
!	  (
!		Long dateTime,
!		DateForm form,
!		outStringPtr result,
!		Handle intlParam
!	  );
!
	.extern	_IUDatePString
_IUDatePString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.w	#14,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	tst.l	savedsp
	beq	LL3
	move.l	(sp)+,a7
LL3:
	pea	0xe(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ed (pack number = 6) Handle IUGetIntl
!	  (
!		Short theID
!	  );
!
	.extern	_IUGetIntl
_IUGetIntl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	#6,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	move.l	(sp)+,d0
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
!	romcall 0xa9ed (pack number = 10) Short IUMagString
!	  (
!		Ptr aPtr,
!		Ptr bPtr,
!		Short aLen,
!		Short bLen
!	  );
!
	.extern	_IUMagString
_IUMagString:
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
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.w	#10,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
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
!	romcall 0xa9ed (pack number = 12) Short IUMagIDString
!	  (
!		Ptr aPtr,
!		Ptr bPtr,
!		Short aLen,
!		Short bLen
!	  );
!
	.extern	_IUMagIDString
_IUMagIDString:
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
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.w	#12,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
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
!	romcall 0xa9ed (pack number = 4) Boolean IUMetric();
!
	.extern	_IUMetric
_IUMetric:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.b	-(sp)
	move.w	#4,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	move.b	(sp)+,d0
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
!	romcall 0xa9ed (pack number = 8) void IUSetIntl
!	  (
!		Short refNum,
!		Short theID,
!		Handle intlParam
!	  );
!
	.extern	_IUSetIntl
_IUSetIntl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#8,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
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
!	romcall 0xa9ed (pack number = 2) void IUTimeString
!	  (
!		Long dateTime,
!		Boolean wantSeconds,
!		outStringPtr result
!	  );
!
	.extern	_IUTimeString
_IUTimeString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),-(sp)
	move.b	0xd(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.w	#2,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	tst.l	savedsp
	beq	LL15
	move.l	(sp)+,a7
LL15:
	pea	0xe(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ed (pack number = 16) void IUTimePString
!	  (
!		Long dateTime,
!		Boolean wantSeconds,
!		outStringPtr result,
!		Handle intlParam
!	  );
!
	.extern	_IUTimePString
_IUTimePString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),-(sp)
	move.b	0xd(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.w	#16,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ed
	tst.l	savedsp
	beq	LL17
	move.l	(sp)+,a7
LL17:
	pea	0xe(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

