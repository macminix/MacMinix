	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ea (pack number = 2) void SFGetFile
!	  (
!		Point where,
!		inStringPtr prompt,
!		ProcPtr fileFilter,
!		Short numTypes,
!		SFTypeList *typeList,
!		ProcPtr dlgHook,
!		SFReply *reply
!	  );
!
	.extern	_SFGetFile
_SFGetFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.l	0x1a(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.w	#2,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ea
	tst.l	savedsp
	beq	LL1
	move.l	(sp)+,a7
LL1:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ea (pack number = 1) void SFPutFile
!	  (
!		Point where,
!		inStringPtr prompt,
!		inStringPtr origName,
!		ProcPtr dlgHook,
!		SFReply *reply
!	  );
!
	.extern	_SFPutFile
_SFPutFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.w	#1,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ea
	tst.l	savedsp
	beq	LL3
	move.l	(sp)+,a7
LL3:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ea (pack number = 4) void SFPGetFile
!	  (
!		Point where,
!		inStringPtr prompt,
!		ProcPtr fileFilter,
!		Short numTypes,
!		SFTypeList *typeList,
!		ProcPtr dlgHook,
!		SFReply *reply,
!		Short dlgID,
!		ProcPtr filterProc
!	  );
!
	.extern	_SFPGetFile
_SFPGetFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
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
	move.l	0x10(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.l	0x1a(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.w	0x22(a6),-(sp)
	move.l	0x24(a6),-(sp)
	move.w	#4,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ea
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
!	romcall 0xa9ea (pack number = 3) void SFPPutFile
!	  (
!		Point where,
!		inStringPtr prompt,
!		inStringPtr origName,
!		ProcPtr dlgHook,
!		SFReply *reply,
!		Short dlgID,
!		ProcPtr filterProc
!	  );
!
	.extern	_SFPPutFile
_SFPPutFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.w	0x1c(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.w	#3,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ea
	tst.l	savedsp
	beq	LL7
	move.l	(sp)+,a7
LL7:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

