	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8fd (pack number = 0xc8000000) void PrOpen();
!
	.extern	_PrOpen
_PrOpen:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	#0xc8000000,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0xd0000000) void PrClose();
!
	.extern	_PrClose
_PrClose:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	#0xd0000000,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x20040480) void PrintDefault
!	  (
!		THPrint
!	  );
!
	.extern	_PrintDefault
_PrintDefault:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.l	0x8(a6),-(sp)
	move.l	#0x20040480,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x52040498) Boolean PrValidate
!	  (
!		 THPrint
!	  );
!
	.extern	_PrValidate
_PrValidate:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	#0x52040498,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
	move.b	(sp)+,d0
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
!	romcall 0xa8fd (pack number = 0x2a040484) Boolean PrStlDialog
!	  (
!		 THPrint
!	  );
!
	.extern	_PrStlDialog
_PrStlDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	#0x2a040484,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
	move.b	(sp)+,d0
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
!	romcall 0xa8fd (pack number = 0x32040488) Boolean PrJobDialog
!	  (
!		 THPrint
!	  );
!
	.extern	_PrJobDialog
_PrJobDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	#0x32040488,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x5804049c) void PrJobMerge
!	  (
!		THPrint,
!		THPrint
!	  );
!
	.extern	_PrJobMerge
_PrJobMerge:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	#0x5804049c,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x04000c00) TPPrPoint PrOpenDoc
!	  (
!		THPrint,
!		TPPrPort,
!		Ptr
!	  );
!
	.extern	_PrOpenDoc
_PrOpenDoc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	#0x04000c00,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
	move.l	(sp)+,d0
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
!	romcall 0xa8fd (pack number = 0x08000484) void PrCloseDoc
!	  (
!		TPPrPort
!	  );
!
	.extern	_PrCloseDoc
_PrCloseDoc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),-(sp)
	move.l	#0x08000484,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x10000808) void PrOpenPage
!	  (
!		TPPrPort,
!		TPRect
!	  );
!
	.extern	_PrOpenPage
_PrOpenPage:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	#0x10000808,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x1800040c) void PrClosePage
!	  (
!		TPPrPort
!	  );
!
	.extern	_PrClosePage
_PrClosePage:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	move.l	0x8(a6),-(sp)
	move.l	#0x1800040c,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
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
!	romcall 0xa8fd (pack number = 0x60051480) void PrPicFile
!	  (
!		THPrint,
!		TTPPrPort,
!		Ptr,
!		Ptr,
!		*TPrStatus
!	  );
!
	.extern	_PrPicFile
_PrPicFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.l	#0x60051480,-(sp)
	move.l	saveda5,a5
	.data2	0xa8fd
	tst.l	savedsp
	beq	LL23
	move.l	(sp)+,a7
LL23:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts
