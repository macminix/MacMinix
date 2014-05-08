	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa841 Fract Fix2Frac
!	  (
!		Fixed 
!	  );
!
	.extern	_Fix2Frac
_Fix2Frac:
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
	move.l	saveda5,a5
	.data2	0xa841
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
!	romcall 0xa840 Long Fix2Long
!	  (
!		Fixed 
!	  );
!
	.extern	_Fix2Long
_Fix2Long:
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
	.data2	0xa840
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
!	romcall 0xa843 unknown type Fix2X
!	  (
!		Fixed 
!	  );
!
	.extern	_Fix2X
_Fix2X:
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
	.data2	0xa843
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
!	romcall 0xa843 Fixed FixATan2
!	  (
!		Long a,
!		Long b
!	  );
!
	.extern	_FixATan2
_FixATan2:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa843
	move.l	(sp)+,d0
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
!	romcall 0xa84d Fixed FixDiv
!	  (
!		Fixed a,
!		Fixed b
!	  );
!
	.extern	_FixDiv
_FixDiv:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa84d
	move.l	(sp)+,d0
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
!	romcall 0xa868 Fixed FixMul
!	  (
!		Fixed a,
!		Fixed b
!	  );
!
	.extern	_FixMul
_FixMul:
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
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa868
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
!	romcall 0xa869 Fixed FixRatio
!	  (
!		Short numer,
!		Short denom
!	  );
!
	.extern	_FixRatio
_FixRatio:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa869
	move.l	(sp)+,d0
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
!	romcall 0xa86c Short FixRound
!	  (
!		Fixed 
!	  );
!
	.extern	_FixRound
_FixRound:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86c
	move.w	(sp)+,d0
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
!	romcall 0xa842 Fixed Frac2Fix
!	  (
!		Fract 
!	  );
!
	.extern	_Frac2Fix
_Frac2Fix:
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
	move.l	saveda5,a5
	.data2	0xa842
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
!	romcall 0xa845 unknown type Frac2X
!	  (
!		Fract 
!	  );
!
	.extern	_Frac2X
_Frac2X:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa845
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
!	romcall 0xa847 Fract FracCos
!	  (
!		Fixed 
!	  );
!
	.extern	_FracCos
_FracCos:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa847
	move.l	(sp)+,d0
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
!	romcall 0xa84b Fract FracDiv
!	  (
!		Fract ,
!		Fract 
!	  );
!
	.extern	_FracDiv
_FracDiv:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa84b
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
!	romcall 0xa84a Fract FracMul
!	  (
!		Fract ,
!		Fract 
!	  );
!
	.extern	_FracMul
_FracMul:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa84a
	move.l	(sp)+,d0
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
!	romcall 0xa848 Fract FracSin
!	  (
!		Fixed 
!	  );
!
	.extern	_FracSin
_FracSin:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa848
	move.l	(sp)+,d0
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
!	romcall 0xa849 Fract FracSqrt
!	  (
!		Fract 
!	  );
!
	.extern	_FracSqrt
_FracSqrt:
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
	move.l	saveda5,a5
	.data2	0xa849
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
!	romcall 0xa83f Fixed Long2Fix
!	  (
!		Long 
!	  );
!
	.extern	_Long2Fix
_Long2Fix:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL30
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL30:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa83f
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
!	romcall 0xa844 Fixed X2Fix
!	  (
!		unknown type *a
!	  );
!
	.extern	_X2Fix
_X2Fix:
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
	.data2	0xa844
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
!	romcall 0xa846 Fract X2Frac
!	  (
!		unknown type *a
!	  );
!
	.extern	_X2Frac
_X2Frac:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa846
	move.l	(sp)+,d0
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
!	romcall 0xa906 StringHandle NewString
!	  (
!		inStringPtr 
!	  );
!
	.extern	_NewString
_NewString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa906
	move.l	(sp)+,d0
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
!	romcall 0xa907 void SetString
!	  (
!		StringHandle ,
!		inStringPtr 
!	  );
!
	.extern	_SetString
_SetString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa907
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
!	romcall 0xa9ba StringHandle GetString
!	  (
!		Short stringID
!	  );
!
	.extern	_GetString
_GetString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9ba
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
!	romcall 0xa9e0 Long Munger
!	  (
!		Handle ,
!		Long offset,
!		Long len1,
!		Long len2
!	  );
!
	.extern	_Munger
_Munger:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9e0
	move.l	(sp)+,d0
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
!	romcall 0xa8cf void PackBits
!	  (
!		Ptr *srcPtr,
!		Ptr *dstPtr,
!		Short srcBytes
!	  );
!
	.extern	_PackBits
_PackBits:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8cf
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
!	romcall 0xa8d0 void UnpackBits
!	  (
!		Ptr *srcPtr,
!		Ptr *dstPtr,
!		Short dstBytes
!	  );
!
	.extern	_UnpackBits
_UnpackBits:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.w	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8d0
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
!	romcall 0xa85d Boolean BitTst
!	  (
!		Ptr bytePtr,
!		Long bitNum
!	  );
!
	.extern	_BitTst
_BitTst:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	clr.b	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa85d
	move.b	(sp)+,d0
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
!	romcall 0xa85e void BitSet
!	  (
!		Ptr bytePtr,
!		Long bitNum
!	  );
!
	.extern	_BitSet
_BitSet:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa85e
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
!	romcall 0xa85f void BitClr
!	  (
!		Ptr bytePtr,
!		Long bitNum
!	  );
!
	.extern	_BitClr
_BitClr:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa85f
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
!	romcall 0xa858 Long BitAnd
!	  (
!		Long val1,
!		Long val2
!	  );
!
	.extern	_BitAnd
_BitAnd:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL54
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL54:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa858
	move.l	(sp)+,d0
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
!	romcall 0xa85b Long BitOr
!	  (
!		Long val1,
!		Long val2
!	  );
!
	.extern	_BitOr
_BitOr:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa85b
	move.l	(sp)+,d0
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
!	romcall 0xa859 Long BitXor
!	  (
!		Long val1,
!		Long val2
!	  );
!
	.extern	_BitXor
_BitXor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL58
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL58:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa859
	move.l	(sp)+,d0
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
!	romcall 0xa85a Long BitNot
!	  (
!		Long val
!	  );
!
	.extern	_BitNot
_BitNot:
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
	move.l	saveda5,a5
	.data2	0xa85a
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
!	romcall 0xa85c Long BitShift
!	  (
!		Long val,
!		Short count
!	  );
!
	.extern	_BitShift
_BitShift:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa85c
	move.l	(sp)+,d0
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
!	romcall 0xa86a Short HiWord
!	  (
!		Long 
!	  );
!
	.extern	_HiWord
_HiWord:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL64
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL64:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86a
	move.w	(sp)+,d0
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
!	romcall 0xa86b Short LoWord
!	  (
!		Long 
!	  );
!
	.extern	_LoWord
_LoWord:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL66
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL66:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa86b
	move.w	(sp)+,d0
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
!	romcall 0xa867 void LongMul
!	  (
!		Long a,
!		Long b,
!		Int64Bit *dest
!	  );
!
	.extern	_LongMul
_LongMul:
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
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa867
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
!	romcall 0xa9bb Handle GetIcon
!	  (
!		Short iconID
!	  );
!
	.extern	_GetIcon
_GetIcon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL70
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL70:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9bb
	move.l	(sp)+,d0
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
!	romcall 0xa94b void PlotIcon
!	  (
!		Rect *r,
!		Handle theIcon
!	  );
!
	.extern	_PlotIcon
_PlotIcon:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa94b
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
!	romcall 0xa9b8 PatHandle GetPattern
!	  (
!		Short patID
!	  );
!
	.extern	_GetPattern
_GetPattern:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL74
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL74:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9b8
	move.l	(sp)+,d0
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
!	romcall 0xa9b9 CursHandle GetCursor
!	  (
!		Short cursorID
!	  );
!
	.extern	_GetCursor
_GetCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL76
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL76:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9b9
	move.l	(sp)+,d0
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
!	romcall 0xa855 void ShieldCursor
!	  (
!		Rect *shieldRect,
!		Point offsetPt
!	  );
!
	.extern	_ShieldCursor
_ShieldCursor:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL78
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL78:
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa855
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
!	romcall 0xa9bc PicHandle GetPicture
!	  (
!		Short picID
!	  );
!
	.extern	_GetPicture
_GetPicture:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL80
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL80:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9bc
	move.l	(sp)+,d0
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
!	romcall 0xa94f Long DeltaPoint
!	  (
!		Point ptA,
!		Point PtB
!	  );
!
	.extern	_DeltaPoint
_DeltaPoint:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL82
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL82:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa94f
	move.l	(sp)+,d0
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
!	romcall 0xa8bc Fixed SlopeFromAngle
!	  (
!		Short angle
!	  );
!
	.extern	_SlopeFromAngle
_SlopeFromAngle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL84
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL84:
	clr.l	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8bc
	move.l	(sp)+,d0
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
!	romcall 0xa8c4 Short AngleFromSlope
!	  (
!		Fixed slope
!	  );
!
	.extern	_AngleFromSlope
_AngleFromSlope:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL86
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL86:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa8c4
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL87
	move.l	(sp)+,a7
LL87:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

