	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 68) ListHandle LNew
!	  (
!		Rect *rView,
!		Rect *dataBounds,
!		Point cSize,
!		Short theProc,
!		WindowPtr theWindow,
!		Boolean drawIt,
!		Boolean hasGrow,
!		Boolean scrollHoriz,
!		Boolean scrollVert
!	  );
!
	.extern	_LNew
_LNew:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.b	0x1b(a6),-(sp)
	move.b	0x1d(a6),-(sp)
	move.b	0x1f(a6),-(sp)
	move.b	0x21(a6),-(sp)
	move.w	#68,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.l	(sp)+,d0
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
!	romcall 0xa9e7 (pack number = 40) void LDispose
!	  (
!		ListHandle 
!	  );
!
	.extern	_LDispose
_LDispose:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),-(sp)
	move.w	#40,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 4) Short LAddColumn
!	  (
!		Short count,
!		Short colNum,
!		ListHandle 
!	  );
!
	.extern	_LAddColumn
_LAddColumn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#4,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 8) Short LAddRow
!	  (
!		Short count,
!		Short rowNum,
!		ListHandle 
!	  );
!
	.extern	_LAddRow
_LAddRow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#8,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 32) void LDelColumn
!	  (
!		Short count,
!		Short colNum,
!		ListHandle 
!	  );
!
	.extern	_LDelColumn
_LDelColumn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#32,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 36) void LDelRow
!	  (
!		Short count,
!		Short rowNum,
!		ListHandle 
!	  );
!
	.extern	_LDelRow
_LDelRow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#36,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 12) void LAddToCell
!	  (
!		Ptr data,
!		Short dataLen,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LAddToCell
_LAddToCell:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.w	#12,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 28) void LClrCell
!	  (
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LClrCell
_LClrCell:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#28,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 56) void LGetCell
!	  (
!		Ptr data,
!		Short *dataLen,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LGetCell
_LGetCell:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.w	#56,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
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
!	romcall 0xa9e7 (pack number = 88) void LSetCell
!	  (
!		Ptr data,
!		Short dataLen,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LSetCell
_LSetCell:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.w	#88,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL19
	move.l	(sp)+,a7
LL19:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 20) void LCellSize
!	  (
!		Point ,
!		ListHandle 
!	  );
!
	.extern	_LCellSize
_LCellSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#20,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL21
	move.l	(sp)+,a7
LL21:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 56) Boolean LGetSelect
!	  (
!		Boolean next,
!		Cell *cell,
!		ListHandle 
!	  );
!
	.extern	_LGetSelect
_LGetSelect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	clr.b	-(sp)
	move.b	0x9(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.w	#56,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL23
	move.l	(sp)+,a7
LL23:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 92) void LSetSelect
!	  (
!		Boolean setIt,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LSetSelect
_LSetSelect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.b	0x9(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.w	#92,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL25
	move.l	(sp)+,a7
LL25:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 24) Boolean LClick
!	  (
!		Point ,
!		Short modifiers,
!		ListHandle 
!	  );
!
	.extern	_LClick
_LClick:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.w	#24,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL27
	move.l	(sp)+,a7
LL27:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 64) long LLastClick
!	  (
!		ListHandle 
!	  );
!
	.extern	_LLastClick
_LLastClick:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	#64,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL29
	move.l	(sp)+,a7
LL29:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 52) void LFind
!	  (
!		Short *offset,
!		Short *len,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LFind
_LFind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL30
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL30:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.w	#52,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL31
	move.l	(sp)+,a7
LL31:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 72) Boolean LNextCell
!	  (
!		Boolean hNext,
!		Boolean vNext,
!		Cell *cell,
!		ListHandle 
!	  );
!
	.extern	_LNextCell
_LNextCell:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	clr.b	-(sp)
	move.b	0x9(a6),-(sp)
	move.b	0xb(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	#72,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL33
	move.l	(sp)+,a7
LL33:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 76) void LRect
!	  (
!		Rect *r,
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LRect
_LRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	#76,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL35
	move.l	(sp)+,a7
LL35:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 84) Boolean LSearch
!	  (
!		Ptr dataPtr,
!		Short dataLen,
!		ProcPtr searchProc,
!		Cell *cell,
!		ListHandle 
!	  );
!
	.extern	_LSearch
_LSearch:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.w	#84,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL37
	move.l	(sp)+,a7
LL37:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 96) void LSize
!	  (
!		Short listWidth,
!		Short listHeight,
!		ListHandle 
!	  );
!
	.extern	_LSize
_LSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#96,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL39
	move.l	(sp)+,a7
LL39:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 48) void LDraw
!	  (
!		Cell ,
!		ListHandle 
!	  );
!
	.extern	_LDraw
_LDraw:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#48,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL41
	move.l	(sp)+,a7
LL41:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 44) void LDoDraw
!	  (
!		Boolean drawIt,
!		ListHandle 
!	  );
!
	.extern	_LDoDraw
_LDoDraw:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	move.b	0x9(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.w	#44,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL43
	move.l	(sp)+,a7
LL43:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 80) void LScroll
!	  (
!		Short dCols,
!		Short dRows,
!		ListHandle 
!	  );
!
	.extern	_LScroll
_LScroll:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#80,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL45
	move.l	(sp)+,a7
LL45:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 16) void LAutoScroll
!	  (
!		ListHandle 
!	  );
!
	.extern	_LAutoScroll
_LAutoScroll:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	0x8(a6),-(sp)
	move.w	#16,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL47
	move.l	(sp)+,a7
LL47:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 100) void LUpdate
!	  (
!		RgnHandle ,
!		ListHandle 
!	  );
!
	.extern	_LUpdate
_LUpdate:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	#100,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL49
	move.l	(sp)+,a7
LL49:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9e7 (pack number = 0) void LActivate
!	  (
!		Boolean ,
!		ListHandle 
!	  );
!
	.extern	_LActivate
_LActivate:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	move.b	0x9(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.w	#0,-(sp)
	move.l	saveda5,a5
	.data2	0xa9e7
	tst.l	savedsp
	beq	LL51
	move.l	(sp)+,a7
LL51:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

