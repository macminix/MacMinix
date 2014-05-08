	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa031 Boolean GetOSEvent
!	  (
!		Short evtMask : d0,
!		EventRecord *Evt : a0
!	  ) : d0;
!
	.extern	_GetOSEvent
_GetOSEvent:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.w	0x8(a6),d0
	move.l	0xa(a6),a0
	move.l	saveda5,a5
	.data2	0xa031
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
!	romcall 0xa030 Boolean OSEventAvail
!	  (
!		Short evtMask : d0,
!		EventRecord *Evt : a0
!	  ) : d0;
!
	.extern	_OSEventAvail
_OSEventAvail:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.w	0x8(a6),d0
	move.l	0xa(a6),a0
	move.l	saveda5,a5
	.data2	0xa030
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
!	romcall 0xa02f OSErr PostEvent
!	  (
!		Short evtCode : a0,
!		Long evtMsg : d0
!	  ) : d0;
!
	.extern	_PostEvent
_PostEvent:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL4
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL4:
	move.w	0x8(a6),a0
	move.l	0xa(a6),d0
	move.l	saveda5,a5
	.data2	0xa02f
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
!	romcall 0xa12f OSErr PPostEvent
!	  (
!		Short evtCode : a0,
!		Long evtMsg : d0,
!		EvQEl *qEl : result
!	  ) : a0->result;
!
	.extern	_PPostEvent
_PPostEvent:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.w	0x8(a6),a0
	move.l	0xa(a6),d0
	move.l	saveda5,a5
	.data2	0xa12f
	move.l	0xe(a6),a1
	move.l	a0,(a1)
	tst.l	savedsp
	beq	LL7
	move.l	(sp)+,a7
LL7:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

