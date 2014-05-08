	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa985 Short Alert
!	  (
!		Short alertID,
!		ProcPtr filterProc
!	  );
!
	.extern	_Alert
_Alert:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa985
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
!	romcall 0xa988 Short CautionAlert
!	  (
!		Short alertID,
!		ProcPtr filterProc
!	  );
!
	.extern	_CautionAlert
_CautionAlert:
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
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa988
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
!	romcall 0xa982 void CloseDialog
!	  (
!		DialogPtr dp
!	  );
!
	.extern	_CloseDialog
_CloseDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa982
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
!	romcall 0xa989 void CouldAlert
!	  (
!		Short alertID
!	  );
!
	.extern	_CouldAlert
_CouldAlert:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa989
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
!	romcall 0xa979 void CouldDialog
!	  (
!		Short dialogID
!	  );
!
	.extern	_CouldDialog
_CouldDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa979
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
!	romcall 0xa980 Boolean DialogSelect
!	  (
!		EventRecord *theEvent,
!		DialogPtr *theDialog,
!		Short *itemHit
!	  );
!
	.extern	_DialogSelect
_DialogSelect:
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
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa980
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
!	romcall 0xa983 void DisposDialog
!	  (
!		DialogPtr dp
!	  );
!
	.extern	_DisposDialog
_DisposDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa983
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
!	romcall 0xa981 void DrawDialog
!	  (
!		DialogPtr dp
!	  );
!
	.extern	_DrawDialog
_DrawDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa981
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
!	romcall 0xa98c void ErrorSound
!	  (
!		ProcPtr soundProc
!	  );
!
	.extern	_ErrorSound
_ErrorSound:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98c
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
!	romcall 0xa984 Short FindDItem
!	  (
!		DialogPtr dp,
!		Point pt
!	  );
!
	.extern	_FindDItem
_FindDItem:
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
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa984
	move.w	(sp)+,d0
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
!	romcall 0xa98a void FreeAlert
!	  (
!		Short alertID
!	  );
!
	.extern	_FreeAlert
_FreeAlert:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98a
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
!	romcall 0xa97a void FreeDialog
!	  (
!		Short dialogID
!	  );
!
	.extern	_FreeDialog
_FreeDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97a
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
!	romcall 0xa98d void GetDItem
!	  (
!		DialogPtr dp,
!		Short itemNo,
!		Short *itemType,
!		Handle *item,
!		Rect *box
!	  );
!
	.extern	_GetDItem
_GetDItem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98d
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
!	romcall 0xa990 void GetIText
!	  (
!		Handle item,
!		outStringPtr text
!	  );
!
	.extern	_GetIText
_GetIText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa990
	tst.l	savedsp
	beq	LL27
	move.l	(sp)+,a7
LL27:
	pea	0xc(a6)
	jsr	__pstringtocstring
	add.l	#0x4,sp
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa97c DialogPtr GetNewDialog
!	  (
!		Short dlogID,
!		DialogPeek dStorage,
!		WindowPtr behind
!	  );
!
	.extern	_GetNewDialog
_GetNewDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97c
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
!	romcall 0xa827 void HideDItem
!	  (
!		DialogPtr dp,
!		Short itemNo
!	  );
!
	.extern	_HideDItem
_HideDItem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL30
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL30:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa827
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
!	romcall 0xa97b void InitDialogs
!	  (
!		ProcPtr resumeProc
!	  );
!
	.extern	_InitDialogs
_InitDialogs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97b
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
!	romcall 0xa97f Boolean IsDialogEvent
!	  (
!		EventRecord *theEvent
!	  );
!
	.extern	_IsDialogEvent
_IsDialogEvent:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97f
	move.b	(sp)+,d0
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
!	romcall 0xa991 void ModalDialog
!	  (
!		ProcPtr filterProc,
!		Short *itemHit
!	  );
!
	.extern	_ModalDialog
_ModalDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa991
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
!	romcall 0xa97d DialogPtr NewDialog
!	  (
!		DialogPeek dStorage,
!		Rect *bounds,
!		inStringPtr title,
!		Boolean vis,
!		Short procID,
!		WindowPtr behind,
!		Boolean goAway,
!		Long refCon,
!		Handle items
!	  );
!
	.extern	_NewDialog
_NewDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.b	0x15(a6),-(sp)
	move.w	0x16(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.b	0x1d(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.l	0x22(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97d
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL39
	move.l	(sp)+,a7
LL39:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa987 Short NoteAlert
!	  (
!		Short alertID,
!		ProcPtr filterProc
!	  );
!
	.extern	_NoteAlert
_NoteAlert:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa987
	move.w	(sp)+,d0
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
!	romcall 0xa98b void ParamText
!	  (
!		inStringPtr param0,
!		inStringPtr param1,
!		inStringPtr param2,
!		inStringPtr param3
!	  );
!
	.extern	_ParamText
_ParamText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	pea	0x14(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98b
	tst.l	savedsp
	beq	LL43
	move.l	(sp)+,a7
LL43:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa97e void SelIText
!	  (
!		DialogPtr dp,
!		Short itemNo,
!		Short strtSel,
!		Short endSel
!	  );
!
	.extern	_SelIText
_SelIText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa97e
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
!	romcall 0xa98e void SetDItem
!	  (
!		DialogPtr dp,
!		Short itemNo,
!		Short itemType,
!		Handle item,
!		Rect *box
!	  );
!
	.extern	_SetDItem
_SetDItem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98e
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
!	romcall 0xa98f void SetIText
!	  (
!		Handle item,
!		inStringPtr text
!	  );
!
	.extern	_SetIText
_SetIText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa98f
	tst.l	savedsp
	beq	LL49
	move.l	(sp)+,a7
LL49:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa828 void ShowDItem
!	  (
!		DialogPtr dp,
!		Short itemNo
!	  );
!
	.extern	_ShowDItem
_ShowDItem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa828
	tst.l	savedsp
	beq	LL51
	move.l	(sp)+,a7
LL51:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa986 Short StopAlert
!	  (
!		Short alertID,
!		ProcPtr filterProc
!	  );
!
	.extern	_StopAlert
_StopAlert:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa986
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL53
	move.l	(sp)+,a7
LL53:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa978 void UpdtDialog
!	  (
!		DialogPtr dp,
!		RgnHandle updateRgn
!	  );
!
	.extern	_UpdtDialog
_UpdtDialog:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL54
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL54:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa978
	tst.l	savedsp
	beq	LL55
	move.l	(sp)+,a7
LL55:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

