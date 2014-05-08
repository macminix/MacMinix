	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa032 void _FlushEvents_
!	  (
!		Long mask : d0
!	  );
!
	.extern	__FlushEvents_
__FlushEvents_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa032
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
!	romcall 0xa03c Boolean _CmpString_
!	  (
!		char *aStr : a0,
!		char *bStr : a1,
!		Long lengths : d0
!	  ) : d0;
!
	.extern	__CmpString_
__CmpString_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa03c
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
!	romcall 0xa13c Boolean _CmpString_M_
!	  (
!		char *aStr : a0,
!		char *bStr : a1,
!		Long lengths : d0
!	  ) : d0;
!
	.extern	__CmpString_M_
__CmpString_M_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa13c
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
!	romcall 0xa23c Boolean _CmpString_C_
!	  (
!		char *aStr : a0,
!		char *bStr : a1,
!		Long lengths : d0
!	  ) : d0;
!
	.extern	__CmpString_C_
__CmpString_C_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa23c
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
!	romcall 0xa33c Boolean _CmpString_CM_
!	  (
!		char *aStr : a0,
!		char *bStr : a1,
!		Long lengths : d0
!	  ) : d0;
!
	.extern	__CmpString_CM_
__CmpString_CM_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa33c
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
!	romcall 0xa9e1 OSErr _HandToHand_
!	  (
!		Handle hin : a0,
!		Handle *hout : result
!	  ) : a0->result;
!
	.extern	__HandToHand_
__HandToHand_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa9e1
	move.l	0xc(a6),a1
	move.l	a0,(a1)
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
!	romcall 0xa054 Boolean _UprString_
!	  (
!		char *Str : a0,
!		Short len : d0
!	  ) : d0;
!
	.extern	__UprString_
__UprString_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),a0
	move.w	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa054
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
!	romcall 0xa154 Boolean _UprString_M_
!	  (
!		char *Str : a0,
!		Short len : d0
!	  ) : d0;
!
	.extern	__UprString_M_
__UprString_M_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),a0
	move.w	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa154
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
!	romcall 0xa038 OSErr _WriteParam_
!	  (
!		Ptr sp : a0,
!		Long minusone : d0
!	  ) : d0;
!
	.extern	__WriteParam_
__WriteParam_:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),a0
	move.l	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa038
	tst.l	savedsp
	beq	LL17
	move.l	(sp)+,a7
LL17:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

