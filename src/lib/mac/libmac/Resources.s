	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ab void AddResource
!	  (
!		Handle theData,
!		ResType ,
!		Short theID,
!		inStringPtr name
!	  );
!
	.extern	_AddResource
_AddResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	pea	0x12(a6)
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
	move.w	0x10(a6),-(sp)
	move.l	0x12(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9ab
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
!	romcall 0xa9aa void ChangedResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_ChangedResource
_ChangedResource:
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
	.data2	0xa9aa
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
!	romcall 0xa99a void CloseResFile
!	  (
!		Short refNum
!	  );
!
	.extern	_CloseResFile
_CloseResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa99a
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
!	romcall 0xa80d Short Count1Resources
!	  (
!		ResType 
!	  );
!
	.extern	_Count1Resources
_Count1Resources:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa80d
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL7
	move.l	(sp)+,a7
LL7:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa81c Short Count1Types();
!
	.extern	_Count1Types
_Count1Types:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa81c
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
!	romcall 0xa99c Short CountResources
!	  (
!		ResType 
!	  );
!
	.extern	_CountResources
_CountResources:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa99c
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL11
	move.l	(sp)+,a7
LL11:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa99e Short CountTypes();
!
	.extern	_CountTypes
_CountTypes:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa99e
	move.w	(sp)+,d0
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
!	romcall 0xa9b1 void CreateResFile
!	  (
!		inStringPtr fileName
!	  );
!
	.extern	_CreateResFile
_CreateResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9b1
	tst.l	savedsp
	beq	LL15
	move.l	(sp)+,a7
LL15:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa994 Short CurResFile();
!
	.extern	_CurResFile
_CurResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa994
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
!	romcall 0xa992 void DetachResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_DetachResource
_DetachResource:
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
	.data2	0xa992
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
!	romcall 0xa80e Handle Get1IndResource
!	  (
!		ResType ,
!		Short index
!	  );
!
	.extern	_Get1IndResource
_Get1IndResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa80e
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL21
	move.l	(sp)+,a7
LL21:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa80f void Get1IndType
!	  (
!		ResType *theType,
!		Short index
!	  );
!
	.extern	_Get1IndType
_Get1IndType:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa80f
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
!	romcall 0xa820 Handle Get1NamedResource
!	  (
!		ResType ,
!		inStringPtr name
!	  );
!
	.extern	_Get1NamedResource
_Get1NamedResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	pea	0xc(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
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
	.data2	0xa820
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL25
	move.l	(sp)+,a7
LL25:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa81f Handle Get1Resource
!	  (
!		ResType ,
!		Short theID
!	  );
!
	.extern	_Get1Resource
_Get1Resource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa81f
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL27
	move.l	(sp)+,a7
LL27:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa99d Handle GetIndResource
!	  (
!		ResType ,
!		Short index
!	  );
!
	.extern	_GetIndResource
_GetIndResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa99d
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL29
	move.l	(sp)+,a7
LL29:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa99f void GetIndType
!	  (
!		ResType *res,
!		Short index
!	  );
!
	.extern	_GetIndType
_GetIndType:
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
	.data2	0xa99f
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
!	romcall 0xa9a1 Handle GetNamedResource
!	  (
!		ResType ,
!		inStringPtr name
!	  );
!
	.extern	_GetNamedResource
_GetNamedResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	pea	0xc(a6)
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
	move.l	saveda5,a5
	.data2	0xa9a1
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
!	romcall 0xa9a6 Short GetResAttrs
!	  (
!		Handle theResource
!	  );
!
	.extern	_GetResAttrs
_GetResAttrs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a6
	move.w	(sp)+,d0
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
!	romcall 0xa9f6 Short GetResFileAttrs
!	  (
!		Short refNum
!	  );
!
	.extern	_GetResFileAttrs
_GetResFileAttrs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	clr.w	-(sp)
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9f6
	move.w	(sp)+,d0
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
!	romcall 0xa9a8 void GetResInfo
!	  (
!		Handle theResource,
!		Short *theID,
!		ResType *theType,
!		StringPtr name
!	  );
!
	.extern	_GetResInfo
_GetResInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x14(a6)
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
	move.l	0x10(a6),-(sp)
	move.l	0x14(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a8
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
!	romcall 0xa9a0 Handle GetResource
!	  (
!		ResType ,
!		Short theID
!	  );
!
	.extern	_GetResource
_GetResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a0
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL41
	move.l	(sp)+,a7
LL41:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9a4 Short HomeResFile
!	  (
!		Handle theResource
!	  );
!
	.extern	_HomeResFile
_HomeResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a4
	move.w	(sp)+,d0
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
!	romcall 0xa995 Short InitResources();
!
	.extern	_InitResources
_InitResources:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa995
	move.w	(sp)+,d0
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
!	romcall 0xa9a2 void LoadResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_LoadResource
_LoadResource:
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
	.data2	0xa9a2
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
!	romcall 0xa821 Long MaxSizeRsrc
!	  (
!		Handle 
!	  );
!
	.extern	_MaxSizeRsrc
_MaxSizeRsrc:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa821
	move.l	(sp)+,d0
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
!	romcall 0xa9c4 Short OpenRFPerm
!	  (
!		inStringPtr fileName,
!		Short vRefNum,
!		Short permission
!	  );
!
	.extern	_OpenRFPerm
_OpenRFPerm:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.w	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9c4
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL51
	move.l	(sp)+,a7
LL51:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa997 Short OpenResFile
!	  (
!		inStringPtr fileName
!	  );
!
	.extern	_OpenResFile
_OpenResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa997
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL53
	move.l	(sp)+,a7
LL53:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9a3 void ReleaseResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_ReleaseResource
_ReleaseResource:
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
	.data2	0xa9a3
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
!	romcall 0xa9ad void RmveResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_RmveResource
_RmveResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9ad
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
!	romcall 0xa9af Short ResError();
!
	.extern	_ResError
_ResError:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL58
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL58:
	clr.w	-(sp)
	move.l	saveda5,a5
	.data2	0xa9af
	move.w	(sp)+,d0
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
!	romcall 0xa9c5 Long RsrcMapEntry
!	  (
!		Handle 
!	  );
!
	.extern	_RsrcMapEntry
_RsrcMapEntry:
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
	.data2	0xa9c5
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
!	romcall 0xa996 void RsrcZoneInit();
!
	.extern	_RsrcZoneInit
_RsrcZoneInit:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	move.l	saveda5,a5
	.data2	0xa996
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
!	romcall 0xa9a7 void SetResAttrs
!	  (
!		Handle theResource,
!		Short attrs
!	  );
!
	.extern	_SetResAttrs
_SetResAttrs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL64
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL64:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a7
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
!	romcall 0xa9f7 void SetResFileAttrs
!	  (
!		Short refNum,
!		Short attrs
!	  );
!
	.extern	_SetResFileAttrs
_SetResFileAttrs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL66
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL66:
	move.w	0x8(a6),-(sp)
	move.w	0xa(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9f7
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
!	romcall 0xa9a9 void SetResInfo
!	  (
!		Handle theResource,
!		Short theID,
!		inStringPtr name
!	  );
!
	.extern	_SetResInfo
_SetResInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xe(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL68
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL68:
	move.l	0x8(a6),-(sp)
	move.w	0xc(a6),-(sp)
	move.l	0xe(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a9
	tst.l	savedsp
	beq	LL69
	move.l	(sp)+,a7
LL69:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa99b void SetResLoad
!	  (
!		Boolean load
!	  );
!
	.extern	_SetResLoad
_SetResLoad:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL70
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL70:
	move.b	0x9(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa99b
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
!	romcall 0xa993 void SetResPurge
!	  (
!		Boolean install
!	  );
!
	.extern	_SetResPurge
_SetResPurge:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.b	0x9(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa993
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
!	romcall 0xa9a5 Long SizeResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_SizeResource
_SizeResource:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL74
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL74:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9a5
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
!	romcall 0xa810 Short Unique1ID
!	  (
!		ResType 
!	  );
!
	.extern	_Unique1ID
_Unique1ID:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL76
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL76:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa810
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL77
	move.l	(sp)+,a7
LL77:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9c1 Short UniqueID
!	  (
!		ResType 
!	  );
!
	.extern	_UniqueID
_UniqueID:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL78
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL78:
	clr.w	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9c1
	move.w	(sp)+,d0
	tst.l	savedsp
	beq	LL79
	move.l	(sp)+,a7
LL79:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa999 void UpdateResFile
!	  (
!		Short refNum
!	  );
!
	.extern	_UpdateResFile
_UpdateResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL80
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL80:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa999
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
!	romcall 0xa998 void UseResFile
!	  (
!		Short refNum
!	  );
!
	.extern	_UseResFile
_UseResFile:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL82
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL82:
	move.w	0x8(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa998
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
!	romcall 0xa9b0 void WriteResource
!	  (
!		Handle theResource
!	  );
!
	.extern	_WriteResource
_WriteResource:
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
	.data2	0xa9b0
	tst.l	savedsp
	beq	LL85
	move.l	(sp)+,a7
LL85:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

