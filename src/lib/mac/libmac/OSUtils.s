	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9c7 void Date2Secs
!	  (
!		DateTimeRec *date : a0,
!		Long *secs : result
!	  ) : d0->result;
!
	.extern	_Date2Secs
_Date2Secs:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa9c7
	move.l	0xc(a6),a1
	move.l	d0,(a1)
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
!	romcall 0xa03b void Delay
!	  (
!		Long numTicks : a0,
!		Long *finalTicks : result
!	  ) : d0->result;
!
	.extern	_Delay
_Delay:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa03b
	move.l	0xc(a6),a1
	move.l	d0,(a1)
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
!	romcall 0xa96e OSErr DeQueue
!	  (
!		QElemPtr qEntry : a0,
!		QHdrPtr theQueue : a1
!	  ) : d0;
!
	.extern	_DeQueue
_DeQueue:
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
	move.l	saveda5,a5
	.data2	0xa96e
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
!	romcall 0xa96f void Enqueue
!	  (
!		QElemPtr qEntry : a0,
!		QHdrPtr theQueue : a1
!	  ) : d0;
!
	.extern	_Enqueue
_Enqueue:
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
	move.l	saveda5,a5
	.data2	0xa96f
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
!	romcall 0xa146 Long GetTrapAddress
!	  (
!		Short trapNum : d0
!	  ) : a0->d0;
!
	.extern	_GetTrapAddress
_GetTrapAddress:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.w	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa146
	move.l	a0,d0
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
!	romcall 0xa9e4 OSErr HandAndHand
!	  (
!		Handle aHandle : a0,
!		Handle bHandle : a1
!	  ) : d0;
!
	.extern	_HandAndHand
_HandAndHand:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	saveda5,a5
	.data2	0xa9e4
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
!	romcall 0xa03f OSErr InitUtil() : d0;
!
	.extern	_InitUtil
_InitUtil:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	saveda5,a5
	.data2	0xa03f
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
!	romcall 0xa9ef OSErr PtrAndHand
!	  (
!		void *ptr : a0,
!		Handle h : a1,
!		Long size : d0
!	  ) : d0;
!
	.extern	_PtrAndHand
_PtrAndHand:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa9ef
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
!	romcall 0xa9e3 OSErr PtrToHand
!	  (
!		void *srcPtr : a0,
!		Handle *dstHandle : result,
!		Long size : d0
!	  ) : a0->result;
!
	.extern	_PtrToHand
_PtrToHand:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	0x8(a6),a0
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa9e3
	move.l	0xc(a6),a1
	move.l	a0,(a1)
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
!	romcall 0xa9e2 OSErr PtrToXHand
!	  (
!		void *srcPtr : a0,
!		Handle dstHandle : a1,
!		Long size : d0
!	  ) : d0;
!
	.extern	_PtrToXHand
_PtrToXHand:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa9e2
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
!	romcall 0xa039 OSErr ReadDateTime
!	  (
!		Long *secs : a0
!	  ) : d0;
!
	.extern	_ReadDateTime
_ReadDateTime:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL20
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL20:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa039
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
!	romcall 0xa9c6 void Secs2Date
!	  (
!		Long secs : d0,
!		DateTimeRec *date : result
!	  ) : a0->result;
!
	.extern	_Secs2Date
_Secs2Date:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa9c6
	move.l	0xc(a6),a1
	move.l	a0,(a1)
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
!	romcall 0xa03a OSErr SetDateTime
!	  (
!		Long secs : d0
!	  ) : d0;
!
	.extern	_SetDateTime
_SetDateTime:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa03a
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
!	romcall 0xa047 void SetTrapAddress
!	  (
!		Long trapAddr : a0,
!		Short trapNum : d0
!	  ) : d0;
!
	.extern	_SetTrapAddress
_SetTrapAddress:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	move.l	0x8(a6),a0
	move.w	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa047
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
!	romcall 0xa9c8 void SysBeep
!	  (
!		Short duration
!	  );
!
	.extern	_SysBeep
_SysBeep:
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
	.data2	0xa9c8
	tst.l	savedsp
	beq	LL29
	move.l	(sp)+,a7
LL29:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

