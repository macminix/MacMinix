	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa87e void AddPt
!	  (
!		Point srcPt,
!		Point *dstPt
!	  );
!
	.extern	_AddPt
_AddPt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa87e
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
!	romcall 0xa863 void BackColor
!	  (
!		Long color
!	  );
!
	.extern	_BackColor
_BackColor:
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
	.data2	0xa863
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
!	romcall 0xa87c void BackPat
!	  (
!		Pattern *pat
!	  );
!
	.extern	_BackPat
_BackPat:
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
	.data2	0xa87c
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
!	romcall 0xa88d Short CharWidth
!	  (
!		Short ch
!	  );
!
	.extern	_CharWidth
_CharWidth:
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
	move.l	saveda5,a5
	.data2	0xa88d
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
!	romcall 0xa87b void ClipRect
!	  (
!		Rect *r
!	  );
!
	.extern	_ClipRect
_ClipRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa87b
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
!	romcall 0xa8f4 void ClosePicture();
!
	.extern	_ClosePicture
_ClosePicture:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.l	saveda5,a5
	.data2	0xa8f4
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
!	romcall 0xa8cc void ClosePoly();
!
	.extern	_ClosePoly
_ClosePoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	saveda5,a5
	.data2	0xa8cc
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
!	romcall 0xa87d void ClosePort
!	  (
!		GrafPtr gp
!	  );
!
	.extern	_ClosePort
_ClosePort:
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
	.data2	0xa87d
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
!	romcall 0xa8db void CloseRgn
!	  (
!		RgnHandle h
!	  );
!
	.extern	_CloseRgn
_CloseRgn:
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
	.data2	0xa8db
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
!	romcall 0xa864 void ColorBit
!	  (
!		Short whichBit
!	  );
!
	.extern	_ColorBit
_ColorBit:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa864
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
!	romcall 0xa8ec void CopyBits
!	  (
!		BitMap *srcBits,
!		BitMap *dstBits,
!		Rect *srcRect,
!		Rect *dstRect,
!		Short mode,
!		RgnHandle maskRgn
!	  );
!
	.extern	_CopyBits
_CopyBits:
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
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.w	0x18(a6),-(sp)
	move.l	0x1a(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ec
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
!	romcall 0xa8dc void CopyRgn
!	  (
!		RgnHandle srcRgn,
!		RgnHandle dstRgn
!	  );
!
	.extern	_CopyRgn
_CopyRgn:
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
	move.l	saveda5,a5
	.data2	0xa8dc
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
!	romcall 0xa8e6 void DiffRgn
!	  (
!		RgnHandle srcRgnA,
!		RgnHandle srcRgnB,
!		RgnHandle dstRgn
!	  );
!
	.extern	_DiffRgn
_DiffRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e6
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
!	romcall 0xa8d9 void DisposeRgn
!	  (
!		RgnHandle h
!	  );
!
	.extern	_DisposeRgn
_DisposeRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d9
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
!	romcall 0xa883 void DrawChar
!	  (
!		Short ch
!	  );
!
	.extern	_DrawChar
_DrawChar:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa883
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
!	romcall 0xa8f6 void DrawPicture
!	  (
!		PicHandle ph,
!		Rect *dstRect
!	  );
!
	.extern	_DrawPicture
_DrawPicture:
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
	move.l	saveda5,a5
	.data2	0xa8f6
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
!	romcall 0xa884 void DrawString
!	  (
!		inStringPtr 
!	  );
!
	.extern	_DrawString
_DrawString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa884
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
!	romcall 0xa885 void DrawText
!	  (
!		Ptr textBuf,
!		Short firstByte,
!		Short byteCount
!	  );
!
	.extern	_DrawText
_DrawText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa885
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
!	romcall 0xa8ae Boolean EmptyRect
!	  (
!		Rect *r
!	  );
!
	.extern	_EmptyRect
_EmptyRect:
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
	move.l	saveda5,a5
	.data2	0xa8ae
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
!	romcall 0xa8e2 Boolean EmptyRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_EmptyRgn
_EmptyRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e2
	move.b	(sp)+,d0
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
!	romcall 0xa881 Boolean EqualPt
!	  (
!		Point pt1,
!		Point pt2
!	  );
!
	.extern	_EqualPt
_EqualPt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa881
	move.b	(sp)+,d0
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
!	romcall 0xa8a6 Boolean EqualRect
!	  (
!		Rect *Rect1,
!		Rect *Rect2
!	  );
!
	.extern	_EqualRect
_EqualRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a6
	move.b	(sp)+,d0
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
!	romcall 0xa8e3 Boolean EqualRgn
!	  (
!		RgnHandle rgnA,
!		RgnHandle rgnB
!	  );
!
	.extern	_EqualRgn
_EqualRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e3
	move.b	(sp)+,d0
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
!	romcall 0xa8c0 void EraseArc
!	  (
!		Rect *r,
!		Short startAngle,
!		Short arcAngle
!	  );
!
	.extern	_EraseArc
_EraseArc:
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
	move.l	saveda5,a5
	.data2	0xa8c0
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
!	romcall 0xa8b9 void EraseOval
!	  (
!		Rect *r
!	  );
!
	.extern	_EraseOval
_EraseOval:
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
	.data2	0xa8b9
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
!	romcall 0xa8c8 void ErasePoly
!	  (
!		PolyHandle 
!	  );
!
	.extern	_ErasePoly
_ErasePoly:
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
	.data2	0xa8c8
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
!	romcall 0xa8a3 void EraseRect
!	  (
!		Rect *r
!	  );
!
	.extern	_EraseRect
_EraseRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a3
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
!	romcall 0xa8d4 void EraseRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_EraseRgn
_EraseRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL54
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL54:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d4
	tst.l	savedsp
	beq	LL55
	move.l	(sp)+,a7
LL55:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b2 void EraseRoundRect
!	  (
!		Rect *r,
!		Short ovalWidth,
!		Short ovalHeight
!	  );
!
	.extern	_EraseRoundRect
_EraseRoundRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b2
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
!	romcall 0xa8c2 void FillArc
!	  (
!		Rect *r,
!		Short startAngle,
!		Short arcAngle,
!		Pattern *pat
!	  );
!
	.extern	_FillArc
_FillArc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL58
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL58:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c2
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
!	romcall 0xa8bb void FillOval
!	  (
!		Rect *r,
!		Pattern *pat
!	  );
!
	.extern	_FillOval
_FillOval:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL60
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL60:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8bb
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
!	romcall 0xa8ca void FillPoly
!	  (
!		PolyHandle ,
!		Pattern *pat
!	  );
!
	.extern	_FillPoly
_FillPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ca
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
!	romcall 0xa8a5 void FillRect
!	  (
!		Rect *r,
!		Pattern *pat
!	  );
!
	.extern	_FillRect
_FillRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL64
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL64:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a5
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
!	romcall 0xa8d6 void FillRgn
!	  (
!		RgnHandle ,
!		Pattern *pat
!	  );
!
	.extern	_FillRgn
_FillRgn:
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
	.data2	0xa8d6
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
!	romcall 0xa8b4 void FillRoundRect
!	  (
!		Rect *r,
!		Short ovalWidth,
!		Short ovalHeight,
!		Pattern *pat
!	  );
!
	.extern	_FillRoundRect
_FillRoundRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL68
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL68:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b4
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
!	romcall 0xa862 void ForeColor
!	  (
!		Long color
!	  );
!
	.extern	_ForeColor
_ForeColor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL70
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL70:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa862
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
!	romcall 0xa8be void FrameArc
!	  (
!		Rect *r,
!		Short startAngle,
!		Short arcAngle
!	  );
!
	.extern	_FrameArc
_FrameArc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8be
	tst.l	savedsp
	beq	LL73
	move.l	(sp)+,a7
LL73:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b7 void FrameOval
!	  (
!		Rect *r
!	  );
!
	.extern	_FrameOval
_FrameOval:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL74
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL74:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b7
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
!	romcall 0xa8c6 void FramePoly
!	  (
!		PolyHandle 
!	  );
!
	.extern	_FramePoly
_FramePoly:
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
	.data2	0xa8c6
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
!	romcall 0xa8a1 void FrameRect
!	  (
!		Rect *r
!	  );
!
	.extern	_FrameRect
_FrameRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL78
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL78:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a1
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
!	romcall 0xa8d2 void FrameRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_FrameRgn
_FrameRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL80
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL80:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d2
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
!	romcall 0xa8b0 void FrameRoundRect
!	  (
!		Rect *r,
!		Short ovalWidth,
!		Short ovalHeight
!	  );
!
	.extern	_FrameRoundRect
_FrameRoundRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL82
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL82:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b0
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
!	romcall 0xa87a void GetClip
!	  (
!		RgnHandle 
!	  );
!
	.extern	_GetClip
_GetClip:
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
	.data2	0xa87a
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
!	romcall 0xa88b void GetFontInfo
!	  (
!		FontInfo *info
!	  );
!
	.extern	_GetFontInfo
_GetFontInfo:
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
	.data2	0xa88b
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
!	romcall 0xa89a void GetPen
!	  (
!		Point *p
!	  );
!
	.extern	_GetPen
_GetPen:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL88
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL88:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa89a
	tst.l	savedsp
	beq	LL89
	move.l	(sp)+,a7
LL89:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa898 void GetPenState
!	  (
!		PenState *pnState
!	  );
!
	.extern	_GetPenState
_GetPenState:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL90
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL90:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa898
	tst.l	savedsp
	beq	LL91
	move.l	(sp)+,a7
LL91:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa865 Boolean GetPixel
!	  (
!		Short h,
!		Short v
!	  );
!
	.extern	_GetPixel
_GetPixel:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL92
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL92:
	clr.b	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa865
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL93
	move.l	(sp)+,a7
LL93:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa874 void GetPort
!	  (
!		GrafPtr *port
!	  );
!
	.extern	_GetPort
_GetPort:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL94
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL94:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa874
	tst.l	savedsp
	beq	LL95
	move.l	(sp)+,a7
LL95:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa871 void GlobalToLocal
!	  (
!		Point *p
!	  );
!
	.extern	_GlobalToLocal
_GlobalToLocal:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL96
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL96:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa871
	tst.l	savedsp
	beq	LL97
	move.l	(sp)+,a7
LL97:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa872 void GrafDevice
!	  (
!		Short device
!	  );
!
	.extern	_GrafDevice
_GrafDevice:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL98
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL98:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa872
	tst.l	savedsp
	beq	LL99
	move.l	(sp)+,a7
LL99:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa852 void HideCursor();
!
	.extern	_HideCursor
_HideCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL100
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL100:
	move.l	saveda5,a5
	.data2	0xa852
	tst.l	savedsp
	beq	LL101
	move.l	(sp)+,a7
LL101:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa896 void HidePen();
!
	.extern	_HidePen
_HidePen:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL102
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL102:
	move.l	saveda5,a5
	.data2	0xa896
	tst.l	savedsp
	beq	LL103
	move.l	(sp)+,a7
LL103:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa850 void InitCursor();
!
	.extern	_InitCursor
_InitCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL104
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL104:
	move.l	saveda5,a5
	.data2	0xa850
	tst.l	savedsp
	beq	LL105
	move.l	(sp)+,a7
LL105:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa86e void InitGraf
!	  (
!		Ptr GlobalPtr
!	  );
!
	.extern	_InitGraf
_InitGraf:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL106
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL106:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86e
	tst.l	savedsp
	beq	LL107
	move.l	(sp)+,a7
LL107:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa86d void InitPort
!	  (
!		GrafPtr 
!	  );
!
	.extern	_InitPort
_InitPort:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL108
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL108:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86d
	tst.l	savedsp
	beq	LL109
	move.l	(sp)+,a7
LL109:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a9 void InsetRect
!	  (
!		Rect *r,
!		Short dh,
!		Short dv
!	  );
!
	.extern	_InsetRect
_InsetRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL110
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL110:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a9
	tst.l	savedsp
	beq	LL111
	move.l	(sp)+,a7
LL111:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e1 void InsetRgn
!	  (
!		RgnHandle ,
!		Short dh,
!		Short dv
!	  );
!
	.extern	_InsetRgn
_InsetRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL112
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL112:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e1
	tst.l	savedsp
	beq	LL113
	move.l	(sp)+,a7
LL113:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8c1 void InvertArc
!	  (
!		Rect *r,
!		Short startAngle,
!		Short arcAngle
!	  );
!
	.extern	_InvertArc
_InvertArc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL114
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL114:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c1
	tst.l	savedsp
	beq	LL115
	move.l	(sp)+,a7
LL115:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ba void InvertOval
!	  (
!		Rect *r
!	  );
!
	.extern	_InvertOval
_InvertOval:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL116
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL116:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ba
	tst.l	savedsp
	beq	LL117
	move.l	(sp)+,a7
LL117:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8c9 void InvertPoly
!	  (
!		PolyHandle 
!	  );
!
	.extern	_InvertPoly
_InvertPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL118
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL118:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c9
	tst.l	savedsp
	beq	LL119
	move.l	(sp)+,a7
LL119:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a4 void InvertRect
!	  (
!		Rect *r
!	  );
!
	.extern	_InvertRect
_InvertRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL120
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL120:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a4
	tst.l	savedsp
	beq	LL121
	move.l	(sp)+,a7
LL121:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8d5 void InvertRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_InvertRgn
_InvertRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL122
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL122:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d5
	tst.l	savedsp
	beq	LL123
	move.l	(sp)+,a7
LL123:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b3 void InvertRoundRect
!	  (
!		Rect *r,
!		Short ovalWidth,
!		Short ovalHeight
!	  );
!
	.extern	_InvertRoundRect
_InvertRoundRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL124
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL124:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b3
	tst.l	savedsp
	beq	LL125
	move.l	(sp)+,a7
LL125:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f5 void KillPicture
!	  (
!		PicHandle 
!	  );
!
	.extern	_KillPicture
_KillPicture:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL126
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL126:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f5
	tst.l	savedsp
	beq	LL127
	move.l	(sp)+,a7
LL127:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8cd void KillPoly
!	  (
!		PolyHandle 
!	  );
!
	.extern	_KillPoly
_KillPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL128
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL128:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8cd
	tst.l	savedsp
	beq	LL129
	move.l	(sp)+,a7
LL129:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa892 void Line
!	  (
!		Short dh,
!		Short dv
!	  );
!
	.extern	_Line
_Line:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL130
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL130:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa892
	tst.l	savedsp
	beq	LL131
	move.l	(sp)+,a7
LL131:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa891 void LineTo
!	  (
!		Short h,
!		Short v
!	  );
!
	.extern	_LineTo
_LineTo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL132
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL132:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa891
	tst.l	savedsp
	beq	LL133
	move.l	(sp)+,a7
LL133:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa870 void LocalToGlobal
!	  (
!		Point *p
!	  );
!
	.extern	_LocalToGlobal
_LocalToGlobal:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL134
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL134:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa870
	tst.l	savedsp
	beq	LL135
	move.l	(sp)+,a7
LL135:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8fc void MapPoly
!	  (
!		PolyHandle ,
!		Rect *srcRect,
!		Rect *dstRect
!	  );
!
	.extern	_MapPoly
_MapPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL136
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL136:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8fc
	tst.l	savedsp
	beq	LL137
	move.l	(sp)+,a7
LL137:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f9 void MapPt
!	  (
!		Point *p,
!		Rect *srcRect,
!		Rect *dstRect
!	  );
!
	.extern	_MapPt
_MapPt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL138
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL138:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f9
	tst.l	savedsp
	beq	LL139
	move.l	(sp)+,a7
LL139:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8fa void MapRect
!	  (
!		Rect *r,
!		Rect *srcRect,
!		Rect *dstRect
!	  );
!
	.extern	_MapRect
_MapRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL140
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL140:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8fa
	tst.l	savedsp
	beq	LL141
	move.l	(sp)+,a7
LL141:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8fb void MapRgn
!	  (
!		RgnHandle ,
!		Rect *srcRect,
!		Rect *dstRect
!	  );
!
	.extern	_MapRgn
_MapRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL142
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL142:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8fb
	tst.l	savedsp
	beq	LL143
	move.l	(sp)+,a7
LL143:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa894 void Move
!	  (
!		Short dh,
!		Short dv
!	  );
!
	.extern	_Move
_Move:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL144
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL144:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa894
	tst.l	savedsp
	beq	LL145
	move.l	(sp)+,a7
LL145:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa877 void MovePortTo
!	  (
!		Short leftGlobal,
!		Short topGlobal
!	  );
!
	.extern	_MovePortTo
_MovePortTo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL146
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL146:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa877
	tst.l	savedsp
	beq	LL147
	move.l	(sp)+,a7
LL147:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa893 void MoveTo
!	  (
!		Short h,
!		Short v
!	  );
!
	.extern	_MoveTo
_MoveTo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL148
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL148:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa893
	tst.l	savedsp
	beq	LL149
	move.l	(sp)+,a7
LL149:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8d8 RgnHandle NewRgn();
!
	.extern	_NewRgn
_NewRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL150
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL150:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa8d8
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL151
	move.l	(sp)+,a7
LL151:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa856 void ObscureCursor();
!
	.extern	_ObscureCursor
_ObscureCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL152
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL152:
	move.l	saveda5,a5
	.data2	0xa856
	tst.l	savedsp
	beq	LL153
	move.l	(sp)+,a7
LL153:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ce void OffsetPoly
!	  (
!		PolyHandle ,
!		Short dh,
!		Short dv
!	  );
!
	.extern	_OffsetPoly
_OffsetPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL154
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL154:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ce
	tst.l	savedsp
	beq	LL155
	move.l	(sp)+,a7
LL155:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a8 void OffsetRect
!	  (
!		Rect *r,
!		Short dh,
!		Short dv
!	  );
!
	.extern	_OffsetRect
_OffsetRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL156
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL156:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a8
	tst.l	savedsp
	beq	LL157
	move.l	(sp)+,a7
LL157:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e0 void OffsetRgn
!	  (
!		RgnHandle ,
!		Short dh,
!		Short dv
!	  );
!
	.extern	_OffsetRgn
_OffsetRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL158
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL158:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e0
	tst.l	savedsp
	beq	LL159
	move.l	(sp)+,a7
LL159:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f3 PicHandle OpenPicture
!	  (
!		Rect *picFrame
!	  );
!
	.extern	_OpenPicture
_OpenPicture:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL160
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL160:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f3
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL161
	move.l	(sp)+,a7
LL161:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8cb PolyHandle OpenPoly();
!
	.extern	_OpenPoly
_OpenPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL162
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL162:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa8cb
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL163
	move.l	(sp)+,a7
LL163:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa86f void OpenPort
!	  (
!		GrafPtr 
!	  );
!
	.extern	_OpenPort
_OpenPort:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL164
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL164:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86f
	tst.l	savedsp
	beq	LL165
	move.l	(sp)+,a7
LL165:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8da void OpenRgn();
!
	.extern	_OpenRgn
_OpenRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL166
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL166:
	move.l	saveda5,a5
	.data2	0xa8da
	tst.l	savedsp
	beq	LL167
	move.l	(sp)+,a7
LL167:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8bf void PaintArc
!	  (
!		Rect *r,
!		Short startAngle,
!		Short arcAngle
!	  );
!
	.extern	_PaintArc
_PaintArc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL168
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL168:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8bf
	tst.l	savedsp
	beq	LL169
	move.l	(sp)+,a7
LL169:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b8 void PaintOval
!	  (
!		Rect *r
!	  );
!
	.extern	_PaintOval
_PaintOval:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL170
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL170:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b8
	tst.l	savedsp
	beq	LL171
	move.l	(sp)+,a7
LL171:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8c7 void PaintPoly
!	  (
!		PolyHandle 
!	  );
!
	.extern	_PaintPoly
_PaintPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL172
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL172:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c7
	tst.l	savedsp
	beq	LL173
	move.l	(sp)+,a7
LL173:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a2 void PaintRect
!	  (
!		Rect *r
!	  );
!
	.extern	_PaintRect
_PaintRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL174
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL174:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a2
	tst.l	savedsp
	beq	LL175
	move.l	(sp)+,a7
LL175:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8d3 void PaintRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_PaintRgn
_PaintRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL176
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL176:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d3
	tst.l	savedsp
	beq	LL177
	move.l	(sp)+,a7
LL177:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b1 void PaintRoundRect
!	  (
!		Rect *r,
!		Short ovalWidth,
!		Short ovalHeight
!	  );
!
	.extern	_PaintRoundRect
_PaintRoundRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL178
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL178:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b1
	tst.l	savedsp
	beq	LL179
	move.l	(sp)+,a7
LL179:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa89c void PenMode
!	  (
!		Short mode
!	  );
!
	.extern	_PenMode
_PenMode:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL180
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL180:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa89c
	tst.l	savedsp
	beq	LL181
	move.l	(sp)+,a7
LL181:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa89e void PenNormal();
!
	.extern	_PenNormal
_PenNormal:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL182
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL182:
	move.l	saveda5,a5
	.data2	0xa89e
	tst.l	savedsp
	beq	LL183
	move.l	(sp)+,a7
LL183:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa89d void PenPat
!	  (
!		Pattern *pat
!	  );
!
	.extern	_PenPat
_PenPat:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL184
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL184:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa89d
	tst.l	savedsp
	beq	LL185
	move.l	(sp)+,a7
LL185:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa89b void PenSize
!	  (
!		Short width,
!		Short height
!	  );
!
	.extern	_PenSize
_PenSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL186
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL186:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa89b
	tst.l	savedsp
	beq	LL187
	move.l	(sp)+,a7
LL187:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f2 void PicComment
!	  (
!		Short kind,
!		Short datasize,
!		Handle dataHandle
!	  );
!
	.extern	_PicComment
_PicComment:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL188
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL188:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f2
	tst.l	savedsp
	beq	LL189
	move.l	(sp)+,a7
LL189:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa876 void PortSize
!	  (
!		Short width,
!		Short height
!	  );
!
	.extern	_PortSize
_PortSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL190
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL190:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa876
	tst.l	savedsp
	beq	LL191
	move.l	(sp)+,a7
LL191:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ac void Pt2Rect
!	  (
!		Point pt1,
!		Point pt2,
!		Rect *dstRect
!	  );
!
	.extern	_Pt2Rect
_Pt2Rect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL192
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL192:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ac
	tst.l	savedsp
	beq	LL193
	move.l	(sp)+,a7
LL193:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ad Boolean PtInRect
!	  (
!		Point ,
!		Rect *r
!	  );
!
	.extern	_PtInRect
_PtInRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL194
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL194:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ad
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL195
	move.l	(sp)+,a7
LL195:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e8 Boolean PtInRgn
!	  (
!		Point ,
!		RgnHandle 
!	  );
!
	.extern	_PtInRgn
_PtInRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL196
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL196:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e8
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL197
	move.l	(sp)+,a7
LL197:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8c3 void PtToAngle
!	  (
!		Rect *r,
!		Point ,
!		Short *angle
!	  );
!
	.extern	_PtToAngle
_PtToAngle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL198
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL198:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c3
	tst.l	savedsp
	beq	LL199
	move.l	(sp)+,a7
LL199:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa861 Short Random();
!
	.extern	_Random
_Random:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL200
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL200:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa861
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL201
	move.l	(sp)+,a7
LL201:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e9 Boolean RectInRgn
!	  (
!		Rect *r,
!		RgnHandle 
!	  );
!
	.extern	_RectInRgn
_RectInRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL202
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL202:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e9
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL203
	move.l	(sp)+,a7
LL203:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8df void RectRgn
!	  (
!		RgnHandle ,
!		Rect *r
!	  );
!
	.extern	_RectRgn
_RectRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL204
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL204:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8df
	tst.l	savedsp
	beq	LL205
	move.l	(sp)+,a7
LL205:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f8 void ScalePt
!	  (
!		Point *p,
!		Rect *srcRect,
!		Rect *dstRect
!	  );
!
	.extern	_ScalePt
_ScalePt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL206
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL206:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f8
	tst.l	savedsp
	beq	LL207
	move.l	(sp)+,a7
LL207:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ef void ScrollRect
!	  (
!		Rect *r,
!		Short dh,
!		Short dv,
!		RgnHandle updateRgn
!	  );
!
	.extern	_ScrollRect
_ScrollRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL208
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL208:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ef
	tst.l	savedsp
	beq	LL209
	move.l	(sp)+,a7
LL209:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8aa Boolean SectRect
!	  (
!		Rect *src1,
!		Rect *src2,
!		Rect *dstRect
!	  );
!
	.extern	_SectRect
_SectRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL210
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL210:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8aa
	move.b	(sp)+,d0
	tst.l	savedsp
	beq	LL211
	move.l	(sp)+,a7
LL211:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e4 void SectRgn
!	  (
!		RgnHandle srcRgnA,
!		RgnHandle srcRgnB,
!		RgnHandle dstRgn
!	  );
!
	.extern	_SectRgn
_SectRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL212
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL212:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e4
	tst.l	savedsp
	beq	LL213
	move.l	(sp)+,a7
LL213:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa879 void SetClip
!	  (
!		RgnHandle 
!	  );
!
	.extern	_SetClip
_SetClip:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL214
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL214:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa879
	tst.l	savedsp
	beq	LL215
	move.l	(sp)+,a7
LL215:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa851 void SetCursor
!	  (
!		Cursor *c
!	  );
!
	.extern	_SetCursor
_SetCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL216
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL216:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa851
	tst.l	savedsp
	beq	LL217
	move.l	(sp)+,a7
LL217:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8dd void SetEmptyRgn
!	  (
!		RgnHandle 
!	  );
!
	.extern	_SetEmptyRgn
_SetEmptyRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL218
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL218:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8dd
	tst.l	savedsp
	beq	LL219
	move.l	(sp)+,a7
LL219:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa878 void SetOrigin
!	  (
!		Short h,
!		Short v
!	  );
!
	.extern	_SetOrigin
_SetOrigin:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL220
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL220:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa878
	tst.l	savedsp
	beq	LL221
	move.l	(sp)+,a7
LL221:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa899 void SetPenState
!	  (
!		PenState *pnState
!	  );
!
	.extern	_SetPenState
_SetPenState:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL222
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL222:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa899
	tst.l	savedsp
	beq	LL223
	move.l	(sp)+,a7
LL223:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa873 void SetPort
!	  (
!		GrafPtr 
!	  );
!
	.extern	_SetPort
_SetPort:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL224
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL224:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa873
	tst.l	savedsp
	beq	LL225
	move.l	(sp)+,a7
LL225:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa875 void SetPortBits
!	  (
!		BitMap *bm
!	  );
!
	.extern	_SetPortBits
_SetPortBits:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL226
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL226:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa875
	tst.l	savedsp
	beq	LL227
	move.l	(sp)+,a7
LL227:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa880 void SetPt
!	  (
!		Point *p,
!		Short h,
!		Short v
!	  );
!
	.extern	_SetPt
_SetPt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL228
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL228:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa880
	tst.l	savedsp
	beq	LL229
	move.l	(sp)+,a7
LL229:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a7 void SetRect
!	  (
!		Rect *r,
!		Short left,
!		Short top,
!		Short right,
!		Short bottom
!	  );
!
	.extern	_SetRect
_SetRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL230
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL230:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a7
	tst.l	savedsp
	beq	LL231
	move.l	(sp)+,a7
LL231:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8de void SetRectRgn
!	  (
!		RgnHandle ,
!		Short left,
!		Short top,
!		Short right,
!		Short bottom
!	  );
!
	.extern	_SetRectRgn
_SetRectRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL232
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL232:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8de
	tst.l	savedsp
	beq	LL233
	move.l	(sp)+,a7
LL233:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ea void SetStdProcs
!	  (
!		QDProcs *procs
!	  );
!
	.extern	_SetStdProcs
_SetStdProcs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL234
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL234:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ea
	tst.l	savedsp
	beq	LL235
	move.l	(sp)+,a7
LL235:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa853 void ShowCursor();
!
	.extern	_ShowCursor
_ShowCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL236
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL236:
	move.l	saveda5,a5
	.data2	0xa853
	tst.l	savedsp
	beq	LL237
	move.l	(sp)+,a7
LL237:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa897 void ShowPen();
!
	.extern	_ShowPen
_ShowPen:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL238
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL238:
	move.l	saveda5,a5
	.data2	0xa897
	tst.l	savedsp
	beq	LL239
	move.l	(sp)+,a7
LL239:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa88e void SpaceExtra
!	  (
!		Fixed extra
!	  );
!
	.extern	_SpaceExtra
_SpaceExtra:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL240
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL240:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa88e
	tst.l	savedsp
	beq	LL241
	move.l	(sp)+,a7
LL241:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8bd void StdArc
!	  (
!		GrafVerb ,
!		Rect *r,
!		Short startAngle,
!		Short arcAngle
!	  );
!
	.extern	_StdArc
_StdArc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL242
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL242:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8bd
	tst.l	savedsp
	beq	LL243
	move.l	(sp)+,a7
LL243:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8eb void StdBits
!	  (
!		BitMap *srcBits,
!		Rect *srcRect,
!		Rect *dstRect,
!		Short mode,
!		RgnHandle maskRgn
!	  );
!
	.extern	_StdBits
_StdBits:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL244
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL244:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8eb
	tst.l	savedsp
	beq	LL245
	move.l	(sp)+,a7
LL245:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f1 void StdComment
!	  (
!		Short kind,
!		Short dataSize,
!		Handle dataHandle
!	  );
!
	.extern	_StdComment
_StdComment:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL246
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL246:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f1
	tst.l	savedsp
	beq	LL247
	move.l	(sp)+,a7
LL247:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ee void StdGetPic
!	  (
!		Ptr dataPtr,
!		Short byteCount
!	  );
!
	.extern	_StdGetPic
_StdGetPic:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL248
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL248:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ee
	tst.l	savedsp
	beq	LL249
	move.l	(sp)+,a7
LL249:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa890 void StdLine
!	  (
!		Point newPt
!	  );
!
	.extern	_StdLine
_StdLine:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL250
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL250:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa890
	tst.l	savedsp
	beq	LL251
	move.l	(sp)+,a7
LL251:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8b6 void StdOval
!	  (
!		GrafVerb ,
!		Rect *r
!	  );
!
	.extern	_StdOval
_StdOval:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL252
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL252:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8b6
	tst.l	savedsp
	beq	LL253
	move.l	(sp)+,a7
LL253:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8c5 void StdPoly
!	  (
!		GrafVerb ,
!		PolyHandle 
!	  );
!
	.extern	_StdPoly
_StdPoly:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL254
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL254:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c5
	tst.l	savedsp
	beq	LL255
	move.l	(sp)+,a7
LL255:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8f0 void StdPutPic
!	  (
!		Ptr dataPtr,
!		Short byteCount
!	  );
!
	.extern	_StdPutPic
_StdPutPic:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL256
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL256:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8f0
	tst.l	savedsp
	beq	LL257
	move.l	(sp)+,a7
LL257:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8a0 void StdRect
!	  (
!		GrafVerb ,
!		Rect *r
!	  );
!
	.extern	_StdRect
_StdRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL258
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL258:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8a0
	tst.l	savedsp
	beq	LL259
	move.l	(sp)+,a7
LL259:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8d1 void StdRgn
!	  (
!		GrafVerb ,
!		RgnHandle 
!	  );
!
	.extern	_StdRgn
_StdRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL260
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL260:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d1
	tst.l	savedsp
	beq	LL261
	move.l	(sp)+,a7
LL261:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8af void StdRRect
!	  (
!		GrafVerb ,
!		Rect *r,
!		Short ovalwidth,
!		Short ovalheight
!	  );
!
	.extern	_StdRRect
_StdRRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL262
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL262:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8af
	tst.l	savedsp
	beq	LL263
	move.l	(sp)+,a7
LL263:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa882 void StdText
!	  (
!		Short byteCount,
!		Ptr textBuf,
!		Point numer,
!		Point denom
!	  );
!
	.extern	_StdText
_StdText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL264
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL264:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa882
	tst.l	savedsp
	beq	LL265
	move.l	(sp)+,a7
LL265:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ed Short StdTxMeas
!	  (
!		Short byteCount,
!		Ptr textAddr,
!		Point *numer,
!		Point *denom,
!		FontInfo *info
!	  );
!
	.extern	_StdTxMeas
_StdTxMeas:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL266
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL266:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.l	0x16(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ed
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL267
	move.l	(sp)+,a7
LL267:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa88c Short StringWidth
!	  (
!		inStringPtr 
!	  );
!
	.extern	_StringWidth
_StringWidth:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL268
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL268:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa88c
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL269
	move.l	(sp)+,a7
LL269:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa866 void StuffHex
!	  (
!		Ptr thingPtr,
!		inStringPtr 
!	  );
!
	.extern	_StuffHex
_StuffHex:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL270
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL270:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa866
	tst.l	savedsp
	beq	LL271
	move.l	(sp)+,a7
LL271:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa87f void SubPt
!	  (
!		Point srcPt,
!		Point *dstPT
!	  );
!
	.extern	_SubPt
_SubPt:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL272
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL272:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa87f
	tst.l	savedsp
	beq	LL273
	move.l	(sp)+,a7
LL273:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa888 void TextFace
!	  (
!		Short face
!	  );
!
	.extern	_TextFace
_TextFace:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL274
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL274:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa888
	tst.l	savedsp
	beq	LL275
	move.l	(sp)+,a7
LL275:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa887 void TextFont
!	  (
!		Short font
!	  );
!
	.extern	_TextFont
_TextFont:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL276
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL276:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa887
	tst.l	savedsp
	beq	LL277
	move.l	(sp)+,a7
LL277:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa889 void TextMode
!	  (
!		Short mode
!	  );
!
	.extern	_TextMode
_TextMode:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL278
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL278:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa889
	tst.l	savedsp
	beq	LL279
	move.l	(sp)+,a7
LL279:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa88a void TextSize
!	  (
!		Short size
!	  );
!
	.extern	_TextSize
_TextSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL280
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL280:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa88a
	tst.l	savedsp
	beq	LL281
	move.l	(sp)+,a7
LL281:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa886 Short TextWidth
!	  (
!		Ptr textBuf,
!		Short firstByte,
!		Short byteCount
!	  );
!
	.extern	_TextWidth
_TextWidth:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL282
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL282:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa886
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL283
	move.l	(sp)+,a7
LL283:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8ab void UnionRect
!	  (
!		Rect *src1,
!		Rect *src2,
!		Rect *dstRect
!	  );
!
	.extern	_UnionRect
_UnionRect:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL284
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL284:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8ab
	tst.l	savedsp
	beq	LL285
	move.l	(sp)+,a7
LL285:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e5 void UnionRgn
!	  (
!		RgnHandle srcRgnA,
!		RgnHandle srcRgnB,
!		RgnHandle dstRgn
!	  );
!
	.extern	_UnionRgn
_UnionRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL286
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL286:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e5
	tst.l	savedsp
	beq	LL287
	move.l	(sp)+,a7
LL287:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa8e7 void XorRgn
!	  (
!		RgnHandle srcRgnA,
!		RgnHandle srcRgnB,
!		RgnHandle dstRgn
!	  );
!
	.extern	_XorRgn
_XorRgn:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL288
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL288:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8e7
	tst.l	savedsp
	beq	LL289
	move.l	(sp)+,a7
LL289:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa839 void SeedFill
!	  (
!		Ptr srcPtr,
!		Ptr dstPtr,
!		Short srcRow,
!		Short dstRow,
!		Short height,
!		Short words,
!		Short seedH,
!		Short seedV
!	  );
!
	.extern	_SeedFill
_SeedFill:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL290
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL290:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.w	0x16(a6),-(sp)
	move.w	0x18(a6),-(sp)
	move.w	0x1a(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa839
	tst.l	savedsp
	beq	LL291
	move.l	(sp)+,a7
LL291:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa838 void CalcMask
!	  (
!		Ptr srcPtr,
!		Ptr dstPtr,
!		Short srcRow,
!		Short dstRow,
!		Short height,
!		Short words
!	  );
!
	.extern	_CalcMask
_CalcMask:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL292
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL292:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.w	0x12(a6),-(sp)
	move.w	0x14(a6),-(sp)
	move.w	0x16(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa838
	tst.l	savedsp
	beq	LL293
	move.l	(sp)+,a7
LL293:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa817 void CopyMask
!	  (
!		BitMap *srcBits,
!		BitMap *maskBits,
!		BitMap *dstBits,
!		Rect *srcRect,
!		Rect *maskRect,
!		Rect *dstRect
!	  );
!
	.extern	_CopyMask
_CopyMask:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL294
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL294:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	0x18(a6),-(sp)
	move.l	0x1c(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa817
	tst.l	savedsp
	beq	LL295
	move.l	(sp)+,a7
LL295:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa837 void MeasureText
!	  (
!		Short count,
!		Ptr textAddr,
!		Ptr charLocs
!	  );
!
	.extern	_MeasureText
_MeasureText:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL296
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL296:
	move.w	0x8(a6),-(sp)
	move.l	0xa(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa837
	tst.l	savedsp
	beq	LL297
	move.l	(sp)+,a7
LL297:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

