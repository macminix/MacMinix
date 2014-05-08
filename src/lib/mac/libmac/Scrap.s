	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9fd Long GetScrap
!	  (
!		Handle hDest,
!		inResType ,
!		Long *offset
!	  );
!
	.extern	_GetScrap
_GetScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
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
	move.l	saveda5,a5
	.data2	0xa9fd
	move.l	(sp)+,d0
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
!	romcall 0xa9f9 PScrapStuff InfoScrap();
!
	.extern	_InfoScrap
_InfoScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa9f9
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
!	romcall 0xa9fb Long LoadScrap();
!
	.extern	_LoadScrap
_LoadScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa9fb
	move.l	(sp)+,d0
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
!	romcall 0xa9fe Long PutScrap
!	  (
!		Long length,
!		inResType ,
!		Ptr source
!	  );
!
	.extern	_PutScrap
_PutScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0xc(a6)
	jsr	__charpointertorestype
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	clr.l	-(sp)
	move.l	0x8(a6),-(sp)
	move.l	0xc(a6),-(sp)
	move.l	0x10(a6),-(sp)
	move.l	saveda5,a5
	.data2	0xa9fe
	move.l	(sp)+,d0
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
!	romcall 0xa9fa Long UnloadScrap();
!
	.extern	_UnloadScrap
_UnloadScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa9fa
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
!	romcall 0xa9fc Long ZeroScrap();
!
	.extern	_ZeroScrap
_ZeroScrap:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	clr.l	-(sp)
	move.l	saveda5,a5
	.data2	0xa9fc
	move.l	(sp)+,d0
	tst.l	savedsp
	beq	LL11
	move.l	(sp)+,a7
LL11:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

