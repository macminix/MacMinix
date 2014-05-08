	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa955 void DisposeControl
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_DisposeControl
_DisposeControl:
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
	.data2	0xa955
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
!	romcall 0xa967 void DragControl
!	  (
!		ControlHandle ch,
!		Point pt,
!		Rect *limit,
!		Rect *slop,
!		Short axis
!	  );
!
	.extern	_DragControl
_DragControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
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
	move.w	0x18(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa967
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
!	romcall 0xa96d void Draw1Control
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_Draw1Control
_Draw1Control:
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
	.data2	0xa96d
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
!	romcall 0xa969 void DrawControls
!	  (
!		WindowPtr wp
!	  );
!
	.extern	_DrawControls
_DrawControls:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa969
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
!	romcall 0xa96c Short FindControl
!	  (
!		Point wh,
!		WindowPtr wp,
!		ControlHandle *ch
!	  );
!
	.extern	_FindControl
_FindControl:
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
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa96c
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
!	romcall 0xa95a Long GetCRefCon
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_GetCRefCon
_GetCRefCon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa95a
	move.l	(sp)+,d0
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
!	romcall 0xa95e void GetCTitle
!	  (
!		ControlHandle ch,
!		inStringPtr title
!	  );
!
	.extern	_GetCTitle
_GetCTitle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa95e
	tst.l	savedsp
	beq	LL13
	move.l	(sp)+,a7
LL13:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa96a ProcPtr GetCtlAction
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_GetCtlAction
_GetCtlAction:
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
	move.l	saveda5,a5
	.data2	0xa96a
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
!	romcall 0xa961 Short GetCtlMin
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_GetCtlMin
_GetCtlMin:
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
	move.l	saveda5,a5
	.data2	0xa961
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
!	romcall 0xa962 Short GetCtlMax
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_GetCtlMax
_GetCtlMax:
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
	move.l	saveda5,a5
	.data2	0xa962
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
!	romcall 0xa960 Short GetCtlValue
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_GetCtlValue
_GetCtlValue:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa960
	move.w	(sp)+,d0
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
!	romcall 0xa9be ControlHandle GetNewControl
!	  (
!		Short ID,
!		WindowPtr wp
!	  );
!
	.extern	_GetNewControl
_GetNewControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9be
	move.l	(sp)+,d0
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
!	romcall 0xa958 void HideControl
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_HideControl
_HideControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa958
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
!	romcall 0xa95d void HiliteControl
!	  (
!		ControlHandle ch,
!		Short hiliteState
!	  );
!
	.extern	_HiliteControl
_HiliteControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa95d
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
!	romcall 0xa956 void KillControls
!	  (
!		WindowPtr wp
!	  );
!
	.extern	_KillControls
_KillControls:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa956
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
!	romcall 0xa959 void MoveControl
!	  (
!		ControlHandle ch,
!		Short h,
!		Short v
!	  );
!
	.extern	_MoveControl
_MoveControl:
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
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa959
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
!	romcall 0xa954 ControlHandle NewControl
!	  (
!		WindowPtr wp,
!		Rect *bounds,
!		inStringPtr title,
!		Boolean vis,
!		Short val,
!		Short min,
!		Short max,
!		Short procID,
!		Long refCon
!	  );
!
	.extern	_NewControl
_NewControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.b	0x15(a6),-(sp)
	move.w	0x16(a6),-(sp)
	move.w	0x18(a6),-(sp)
	move.w	0x1a(a6),-(sp)
	move.w	0x1c(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa954
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL33
	move.l	(sp)+,a7
LL33:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa95b void SetCRefCon
!	  (
!		ControlHandle ch,
!		Long data
!	  );
!
	.extern	_SetCRefCon
_SetCRefCon:
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
	move.l	saveda5,a5
	.data2	0xa95b
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
!	romcall 0xa95f void SetCTitle
!	  (
!		ControlHandle ch,
!		inStringPtr title
!	  );
!
	.extern	_SetCTitle
_SetCTitle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa95f
	tst.l	savedsp
	beq	LL37
	move.l	(sp)+,a7
LL37:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa96b void SetCtlAction
!	  (
!		ControlHandle ch,
!		ProcPtr actionProc
!	  );
!
	.extern	_SetCtlAction
_SetCtlAction:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa96b
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
!	romcall 0xa965 void SetCtlMax
!	  (
!		ControlHandle ch,
!		Short val
!	  );
!
	.extern	_SetCtlMax
_SetCtlMax:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa965
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
!	romcall 0xa964 void SetCtlMin
!	  (
!		ControlHandle ch,
!		Short val
!	  );
!
	.extern	_SetCtlMin
_SetCtlMin:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa964
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
!	romcall 0xa963 void SetCtlValue
!	  (
!		ControlHandle ch,
!		Short v
!	  );
!
	.extern	_SetCtlValue
_SetCtlValue:
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
	move.l	saveda5,a5
	.data2	0xa963
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
!	romcall 0xa957 void ShowControl
!	  (
!		ControlHandle ch
!	  );
!
	.extern	_ShowControl
_ShowControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa957
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
!	romcall 0xa95c void SizeControl
!	  (
!		ControlHandle ch,
!		Short w,
!		Short h
!	  );
!
	.extern	_SizeControl
_SizeControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa95c
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
!	romcall 0xa966 Short TestControl
!	  (
!		ControlHandle ch,
!		Point pt
!	  );
!
	.extern	_TestControl
_TestControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa966
	move.w	(sp)+,d0
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
!	romcall 0xa968 Short TrackControl
!	  (
!		ControlHandle ch,
!		Point start,
!		ProcPtr action
!	  );
!
	.extern	_TrackControl
_TrackControl:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa968
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
!	romcall 0xa953 void UpdtControl
!	  (
!		WindowPtr wp,
!		RgnHandle rh
!	  );
!
	.extern	_UpdtControl
_UpdtControl:
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
	.data2	0xa953
	tst.l	savedsp
	beq	LL55
	move.l	(sp)+,a7
LL55:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

