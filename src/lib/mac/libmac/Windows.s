	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa922 void BeginUpdate
!	  (
!		WindowPtr 
!	  );
!
	.extern	_BeginUpdate
_BeginUpdate:
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
	.data2	0xa922
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
!	romcall 0xa920 void BringToFront
!	  (
!		WindowPtr 
!	  );
!
	.extern	_BringToFront
_BringToFront:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa920
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
!	romcall 0xa909 void CalcVis
!	  (
!		WindowPeek 
!	  );
!
	.extern	_CalcVis
_CalcVis:
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
	.data2	0xa909
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
!	romcall 0xa90a void CalcVisBehind
!	  (
!		WindowPeek startWindow,
!		RgnHandle clobberedRgn
!	  );
!
	.extern	_CalcVisBehind
_CalcVisBehind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90a
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
!	romcall 0xa911 Boolean CheckUpdate
!	  (
!		EventRecord *theEvent
!	  );
!
	.extern	_CheckUpdate
_CheckUpdate:
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
	move.l	saveda5,a5
	.data2	0xa911
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
!	romcall 0xa90b void ClipAbove
!	  (
!		WindowPeek 
!	  );
!
	.extern	_ClipAbove
_ClipAbove:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90b
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
!	romcall 0xa92d void CloseWindow
!	  (
!		WindowPtr 
!	  );
!
	.extern	_CloseWindow
_CloseWindow:
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
	.data2	0xa92d
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
!	romcall 0xa914 void DisposeWindow
!	  (
!		WindowPtr 
!	  );
!
	.extern	_DisposeWindow
_DisposeWindow:
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
	.data2	0xa914
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
!	romcall 0xa905 Long DragGrayRgn
!	  (
!		RgnHandle ,
!		Point startPt,
!		Rect *limitRect,
!		Rect *slopRect,
!		Short axis,
!		ProcPtr actionProc
!	  );
!
	.extern	_DragGrayRgn
_DragGrayRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.w	0x18(a6),-(sp)
	move.l	0x1a(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa905
	move.l	(sp)+,d0
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
!	romcall 0xa925 void DragWindow
!	  (
!		WindowPtr ,
!		Point startPt,
!		Rect *boundsRect
!	  );
!
	.extern	_DragWindow
_DragWindow:
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
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa925
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
!	romcall 0xa904 void DrawGrowIcon
!	  (
!		WindowPtr 
!	  );
!
	.extern	_DrawGrowIcon
_DrawGrowIcon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa904
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
!	romcall 0xa90f void DrawNew
!	  (
!		WindowPeek ,
!		Boolean update
!	  );
!
	.extern	_DrawNew
_DrawNew:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.l	0x8(a6),-(sp)
	move.b	0xd(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90f
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
!	romcall 0xa923 void EndUpdate
!	  (
!		WindowPtr 
!	  );
!
	.extern	_EndUpdate
_EndUpdate:
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
	.data2	0xa923
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
!	romcall 0xa92c Short FindWindow
!	  (
!		Point thePt,
!		WindowPtr *whichWind
!	  );
!
	.extern	_FindWindow
_FindWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa92c
	move.w	(sp)+,d0
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
!	romcall 0xa924 WindowPtr FrontWindow();
!
	.extern	_FrontWindow
_FrontWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa924
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
!	romcall 0xa9bd WindowPtr GetNewWindow
!	  (
!		Short windowID,
!		WindowPeek wStorage,
!		WindowPtr behind
!	  );
!
	.extern	_GetNewWindow
_GetNewWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL30
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL30:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9bd
	move.l	(sp)+,d0
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
!	romcall 0xa92f PicHandle GetWindowPic
!	  (
!		WindowPtr 
!	  );
!
	.extern	_GetWindowPic
_GetWindowPic:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa92f
	move.l	(sp)+,d0
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
!	romcall 0xa910 void GetWMgrPort
!	  (
!		GrafPtr *wPort
!	  );
!
	.extern	_GetWMgrPort
_GetWMgrPort:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa910
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
!	romcall 0xa917 Long GetWRefCon
!	  (
!		WindowPtr 
!	  );
!
	.extern	_GetWRefCon
_GetWRefCon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa917
	move.l	(sp)+,d0
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
!	romcall 0xa919 void GetWTitle
!	  (
!		WindowPtr ,
!		outStringPtr title
!	  );
!
	.extern	_GetWTitle
_GetWTitle:
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
	.data2	0xa919
	tst.l	savedsp
	beq	LL39
	move.l	(sp)+,a7
LL39:
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
!	romcall 0xa92b Long GrowWindow
!	  (
!		WindowPtr ,
!		Point startPt,
!		Rect *sizeRect
!	  );
!
	.extern	_GrowWindow
_GrowWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa92b
	move.l	(sp)+,d0
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
!	romcall 0xa916 void HideWindow
!	  (
!		WindowPtr 
!	  );
!
	.extern	_HideWindow
_HideWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa916
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
!	romcall 0xa91c void HiliteWindow
!	  (
!		WindowPtr ,
!		Boolean fHilite
!	  );
!
	.extern	_HiliteWindow
_HiliteWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.l	0x8(a6),-(sp)
	move.b	0xd(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91c
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
!	romcall 0xa912 void InitWindows();
!
	.extern	_InitWindows
_InitWindows:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	saveda5,a5
	.data2	0xa912
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
!	romcall 0xa928 void InvalRect
!	  (
!		Rect *badRect
!	  );
!
	.extern	_InvalRect
_InvalRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa928
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
!	romcall 0xa927 void InvalRgn
!	  (
!		RgnHandle badRgn
!	  );
!
	.extern	_InvalRgn
_InvalRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa927
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
!	romcall 0xa91b void MoveWindow
!	  (
!		WindowPtr ,
!		Short hGlobal,
!		Short vGlobal,
!		Boolean front
!	  );
!
	.extern	_MoveWindow
_MoveWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.b	0x11(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91b
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
!	romcall 0xa913 WindowPtr NewWindow
!	  (
!		WindowPeek wStorage,
!		Rect *boundsRect,
!		inStringPtr title,
!		Boolean visible,
!		Short procID,
!		WindowPtr behind,
!		Boolean goAwayFlag,
!		Long refCon
!	  );
!
	.extern	_NewWindow
_NewWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x10(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL54
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL54:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.b	0x15(a6),-(sp)
	move.w	0x16(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.b	0x1d(a6),-(sp)
	move.l	0x1e(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa913
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL55
	move.l	(sp)+,a7
LL55:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa90d void PaintBehind
!	  (
!		WindowPeek startWindow,
!		RgnHandle clobberedRgn
!	  );
!
	.extern	_PaintBehind
_PaintBehind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90d
	tst.l	savedsp
	beq	LL57
	move.l	(sp)+,a7
LL57:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa90c void PaintOne
!	  (
!		WindowPeek ,
!		RgnHandle clobberedRgn
!	  );
!
	.extern	_PaintOne
_PaintOne:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL58
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL58:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90c
	tst.l	savedsp
	beq	LL59
	move.l	(sp)+,a7
LL59:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa94e Long PinRect
!	  (
!		Rect *r,
!		Point 
!	  );
!
	.extern	_PinRect
_PinRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL60
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL60:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa94e
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL61
	move.l	(sp)+,a7
LL61:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa90e void SaveOld
!	  (
!		WindowPeek 
!	  );
!
	.extern	_SaveOld
_SaveOld:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa90e
	tst.l	savedsp
	beq	LL63
	move.l	(sp)+,a7
LL63:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa91f void SelectWindow
!	  (
!		WindowPtr 
!	  );
!
	.extern	_SelectWindow
_SelectWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL64
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL64:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91f
	tst.l	savedsp
	beq	LL65
	move.l	(sp)+,a7
LL65:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa921 void SendBehind
!	  (
!		WindowPtr theWindow,
!		WindowPtr behindWindow
!	  );
!
	.extern	_SendBehind
_SendBehind:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL66
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL66:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa921
	tst.l	savedsp
	beq	LL67
	move.l	(sp)+,a7
LL67:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa92e void SetWindowPic
!	  (
!		WindowPtr ,
!		PicHandle 
!	  );
!
	.extern	_SetWindowPic
_SetWindowPic:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL68
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL68:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa92e
	tst.l	savedsp
	beq	LL69
	move.l	(sp)+,a7
LL69:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa918 void SetWRefCon
!	  (
!		WindowPtr ,
!		Long data
!	  );
!
	.extern	_SetWRefCon
_SetWRefCon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL70
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL70:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa918
	tst.l	savedsp
	beq	LL71
	move.l	(sp)+,a7
LL71:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa91a void SetWTitle
!	  (
!		WindowPtr ,
!		inStringPtr title
!	  );
!
	.extern	_SetWTitle
_SetWTitle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91a
	tst.l	savedsp
	beq	LL73
	move.l	(sp)+,a7
LL73:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa908 void ShowHide
!	  (
!		WindowPtr ,
!		Boolean showFlag
!	  );
!
	.extern	_ShowHide
_ShowHide:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL74
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL74:
	move.l	0x8(a6),-(sp)
	move.b	0xd(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa908
	tst.l	savedsp
	beq	LL75
	move.l	(sp)+,a7
LL75:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa915 void ShowWindow
!	  (
!		WindowPtr 
!	  );
!
	.extern	_ShowWindow
_ShowWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL76
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL76:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa915
	tst.l	savedsp
	beq	LL77
	move.l	(sp)+,a7
LL77:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa91d void SizeWindow
!	  (
!		WindowPtr ,
!		Short w,
!		Short h,
!		Boolean fUpdate
!	  );
!
	.extern	_SizeWindow
_SizeWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL78
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL78:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.b	0x11(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91d
	tst.l	savedsp
	beq	LL79
	move.l	(sp)+,a7
LL79:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa83b Boolean TrackBox
!	  (
!		WindowPtr ,
!		Point ,
!		Short partCode
!	  );
!
	.extern	_TrackBox
_TrackBox:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL80
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL80:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa83b
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL81
	move.l	(sp)+,a7
LL81:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa91e Boolean TrackGoAway
!	  (
!		WindowPtr ,
!		Point thePt
!	  );
!
	.extern	_TrackGoAway
_TrackGoAway:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL82
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL82:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa91e
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL83
	move.l	(sp)+,a7
LL83:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa92a void ValidRect
!	  (
!		Rect *goodRect
!	  );
!
	.extern	_ValidRect
_ValidRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL84
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL84:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa92a
	tst.l	savedsp
	beq	LL85
	move.l	(sp)+,a7
LL85:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa929 void ValidRgn
!	  (
!		RgnHandle goodRgn
!	  );
!
	.extern	_ValidRgn
_ValidRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL86
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL86:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa929
	tst.l	savedsp
	beq	LL87
	move.l	(sp)+,a7
LL87:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa83a void ZoomWindow
!	  (
!		WindowPtr ,
!		Short partCode,
!		Boolean front
!	  );
!
	.extern	_ZoomWindow
_ZoomWindow:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL88
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL88:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.b	0xf(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa83a
	tst.l	savedsp
	beq	LL89
	move.l	(sp)+,a7
LL89:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

