	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa835 void FontMetrics
!	  (
!		FMetricRec *theMetrics
!	  );
!
	.extern	_FontMetrics
_FontMetrics:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa835
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
!	romcall 0xa901 FMOutPtr FMSwapFont
!	  (
!		FMInput *inRec
!	  );
!
	.extern	_FMSwapFont
_FMSwapFont:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa901
	move.l	(sp)+,d0
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
!	romcall 0xa900 void GetFNum
!	  (
!		inStringPtr infontName,
!		Short *theNum
!	  );
!
	.extern	_GetFNum
_GetFNum:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa900
	tst.l	savedsp
	beq	LL5
	move.l	(sp)+,a7
LL5:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ff void GetFontName
!	  (
!		Short fontNum,
!		outStringPtr theName
!	  );
!
	.extern	_GetFontName
_GetFontName:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ff
	tst.l	savedsp
	beq	LL7
	move.l	(sp)+,a7
LL7:
	pea	0xa(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8fe void InitFonts();
!
	.extern	_InitFonts
_InitFonts:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.l	saveda5,a5
	.data2	0xa8fe
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
!	romcall 0xa902 Boolean RealFont
!	  (
!		Short fontNum,
!		Short size
!	  );
!
	.extern	_RealFont
_RealFont:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.b	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa902
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
!	romcall 0xa903 void SetFontLock
!	  (
!		Boolean lockFlag
!	  );
!
	.extern	_SetFontLock
_SetFontLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.b	0x9(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa903
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
!	romcall 0xa834 void SetFScaleDisable
!	  (
!		Boolean 
!	  );
!
	.extern	_SetFScaleDisable
_SetFScaleDisable:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.b	0x9(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa834
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
!	romcall 0xa814 void SetFractEnable
!	  (
!		Boolean 
!	  );
!
	.extern	_SetFractEnable
_SetFractEnable:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.b	0x9(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa814
	tst.l	savedsp
	beq	LL17
	move.l	(sp)+,a7
LL17:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

