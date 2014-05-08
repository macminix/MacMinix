	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa9ee (pack number = 0) void NumToString
!	  (
!		Long  : d0,
!		outStringPtr s : a0
!	  );
!
	.extern	_NumToString
_NumToString:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),d0
	move.l	0xc(a6),a0
	move.w	#0,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ee
	tst.l	savedsp
	beq	LL1
	move.l	(sp)+,a7
LL1:
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
!	romcall 0xa9ee (pack number = 1) void StringToNum
!	  (
!		inStringPtr  : a0,
!		Long *thenum : result
!	  ) : d0->result;
!
	.extern	_StringToNum
_StringToNum:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	pea	0x8(a6)
	jsr	__cstringtopstring
	add.l	#0x4,sp
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),a0
	move.w	#1,-(sp)
	move.l	saveda5,a5
	.data2	0xa9ee
	move.l	0xc(a6),a1
	move.l	d0,(a1)
	tst.l	savedsp
	beq	LL3
	move.l	(sp)+,a7
LL3:
	jsr	__cstringclear
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

