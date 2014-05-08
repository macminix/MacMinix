	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa02e void BlockMove
!	  (
!		void *sourcePtr : a0,
!		void *destPtr : a1,
!		Size byteCount : d0
!	  ) : d0->MemErr;
!
	.extern	_BlockMove
_BlockMove:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	0x8(a6),a0
	move.l	0xc(a6),a1
	move.l	0x10(a6),d0
	move.l	saveda5,a5
	.data2	0xa02e
	move.w	d0,_MemErr
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
!	romcall 0xa04c Size CompactMem
!	  (
!		Size cbNeeded : d0
!	  ) : d0->MemErr;
!
	.extern	_CompactMem
_CompactMem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL2
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL2:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa04c
	move.w	d0,_MemErr
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
!	romcall 0xa023 void DisposHandle
!	  (
!		Handle 
!	  ) : d0->MemErr;
!
	.extern	_DisposHandle
_DisposHandle:
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
	.data2	0xa023
	move.w	d0,_MemErr
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
!	romcall 0xa01f void DisposPtr() : d0->MemErr;
!
	.extern	_DisposPtr
_DisposPtr:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	saveda5,a5
	.data2	0xa01f
	move.w	d0,_MemErr
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
!	romcall 0xa02b void EmptyHandle
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_EmptyHandle
_EmptyHandle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL8
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL8:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa02b
	move.w	d0,_MemErr
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
!	romcall 0xa01c Long FreeMem() : d0->MemErr;
!
	.extern	_FreeMem
_FreeMem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL10
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL10:
	move.l	saveda5,a5
	.data2	0xa01c
	move.w	d0,_MemErr
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
!	romcall 0xa025 Size GetHandleSize
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_GetHandleSize
_GetHandleSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL12
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL12:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa025
	move.w	d0,_MemErr
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
!	romcall 0xa021 Size GetPtrSize
!	  (
!		Ptr  : a0
!	  ) : d0->MemErr;
!
	.extern	_GetPtrSize
_GetPtrSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL14
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL14:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa021
	move.w	d0,_MemErr
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
!	romcall 0xa11a THz GetZone() : d0->MemErr : a0->d0;
!
	.extern	_GetZone
_GetZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL16
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL16:
	move.l	saveda5,a5
	.data2	0xa11a
	move.w	d0,_MemErr
	move.l	a0,d0
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
!	romcall 0xa126 THz HandleZone
!	  (
!		Handle  : a0
!	  ) : d0->MemErr : a0->d0;
!
	.extern	_HandleZone
_HandleZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL18
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL18:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa126
	move.w	d0,_MemErr
	move.l	a0,d0
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
!	romcall 0xa068 void HClrRBit
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HClrRBit
_HClrRBit:
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
	.data2	0xa068
	move.w	d0,_MemErr
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
!	romcall 0xa069 SignedByte HGetState
!	  (
!		Handle  : a0
!	  ) : d0;
!
	.extern	_HGetState
_HGetState:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL22
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL22:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa069
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
!	romcall 0xa029 void HLock
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HLock
_HLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL24
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL24:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa029
	move.w	d0,_MemErr
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
!	romcall 0xa04a void HNoPurge
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HNoPurge
_HNoPurge:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL26
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL26:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa04a
	move.w	d0,_MemErr
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
!	romcall 0xa049 void HPurge
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HPurge
_HPurge:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL28
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL28:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa049
	move.w	d0,_MemErr
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
!	romcall 0xa067 void HSetRBit
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HSetRBit
_HSetRBit:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL30
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL30:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa067
	move.w	d0,_MemErr
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
!	romcall 0xa06a void HSetState
!	  (
!		Handle  : a0,
!		SignedByte flags : d0
!	  ) : d0->MemErr;
!
	.extern	_HSetState
_HSetState:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	move.l	0x8(a6),a0
	move.b	0xd(a6),d0
	move.l	saveda5,a5
	.data2	0xa06a
	move.w	d0,_MemErr
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
!	romcall 0xa02a void HUnlock
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_HUnlock
_HUnlock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL34
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL34:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa02a
	move.w	d0,_MemErr
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
!	romcall 0xa02c void InitApplZone() : d0->MemErr;
!
	.extern	_InitApplZone
_InitApplZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	move.l	saveda5,a5
	.data2	0xa02c
	move.w	d0,_MemErr
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
!	romcall 0xa063 void MaxApplZone() : d0->MemErr;
!
	.extern	_MaxApplZone
_MaxApplZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL38
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL38:
	move.l	saveda5,a5
	.data2	0xa063
	move.w	d0,_MemErr
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
!	romcall 0xa061 Long MaxBlock() : d0->MemErr;
!
	.extern	_MaxBlock
_MaxBlock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	move.l	saveda5,a5
	.data2	0xa061
	move.w	d0,_MemErr
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
!	romcall 0xa11d Size MaxMem
!	  (
!		Size *grow : result
!	  ) : d0->MemErr : a0->result;
!
	.extern	_MaxMem
_MaxMem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL42
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL42:
	move.l	saveda5,a5
	.data2	0xa11d
	move.w	d0,_MemErr
	move.l	0x8(a6),a1
	move.l	a0,(a1)
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
!	romcall 0xa036 void MoreMasters();
!
	.extern	_MoreMasters
_MoreMasters:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.l	saveda5,a5
	.data2	0xa036
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
!	romcall 0xa064 void MoveHHi
!	  (
!		Handle  : a0
!	  ) : d0->MemErr;
!
	.extern	_MoveHHi
_MoveHHi:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL46
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL46:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa064
	move.w	d0,_MemErr
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
!	romcall 0xa066 Handle NewEmptyHandle() : a0->d0;
!
	.extern	_NewEmptyHandle
_NewEmptyHandle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	saveda5,a5
	.data2	0xa066
	move.l	a0,d0
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
!	romcall 0xa122 Handle NewHandle
!	  (
!		Size logicalSize : d0
!	  ) : d0->MemErr : a0->d0;
!
	.extern	_NewHandle
_NewHandle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL50
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL50:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa122
	move.w	d0,_MemErr
	move.l	a0,d0
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
!	romcall 0xa11e Ptr NewPtr
!	  (
!		Size logicalSize : d0
!	  ) : d0->MemErr : a0->d0;
!
	.extern	_NewPtr
_NewPtr:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa11e
	move.w	d0,_MemErr
	move.l	a0,d0
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
!	romcall 0xa148 THz PtrZone
!	  (
!		Ptr  : a0
!	  ) : d0->MemErr : a0->d0;
!
	.extern	_PtrZone
_PtrZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL54
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL54:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa148
	move.w	d0,_MemErr
	move.l	a0,d0
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
!	romcall 0xa04d void PurgeMem
!	  (
!		Size cbNeeded : d0
!	  ) : d0->MemErr;
!
	.extern	_PurgeMem
_PurgeMem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa04d
	move.w	d0,_MemErr
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
!	romcall 0xa027 void ReallocHandle
!	  (
!		Handle  : a0,
!		Size logicalSize : d0
!	  ) : d0->MemErr;
!
	.extern	_ReallocHandle
_ReallocHandle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL58
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL58:
	move.l	0x8(a6),a0
	move.l	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa027
	move.w	d0,_MemErr
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
!	romcall 0xa128 Handle RecoverHandle
!	  (
!		Ptr  : a0
!	  ) : a0->d0;
!
	.extern	_RecoverHandle
_RecoverHandle:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL60
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL60:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa128
	move.l	a0,d0
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
!	romcall 0xa040 void ResrvMem
!	  (
!		Size cbNeeded : d0
!	  ) : d0->MemErr;
!
	.extern	_ResrvMem
_ResrvMem:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	move.l	0x8(a6),d0
	move.l	saveda5,a5
	.data2	0xa040
	move.w	d0,_MemErr
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
!	romcall 0xa057 void SetApplBase
!	  (
!		Ptr startPtr : a0
!	  ) : d0->MemErr;
!
	.extern	_SetApplBase
_SetApplBase:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL64
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL64:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa057
	move.w	d0,_MemErr
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
!	romcall 0xa02d void SetApplLimit
!	  (
!		Ptr zoneLimit : a0
!	  ) : d0->MemErr;
!
	.extern	_SetApplLimit
_SetApplLimit:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL66
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL66:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa02d
	move.w	d0,_MemErr
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
!	romcall 0xa04b void SetGrowZone
!	  (
!		ProcPtr  : a0
!	  ) : d0->MemErr;
!
	.extern	_SetGrowZone
_SetGrowZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL68
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL68:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa04b
	move.w	d0,_MemErr
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
!	romcall 0xa024 void SetHandleSize
!	  (
!		Handle  : a0,
!		Size newSize : d0
!	  ) : d0->MemErr;
!
	.extern	_SetHandleSize
_SetHandleSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL70
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL70:
	move.l	0x8(a6),a0
	move.l	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa024
	move.w	d0,_MemErr
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
!	romcall 0xa020 void SetPtrSize
!	  (
!		Ptr  : a0,
!		Size newSize : d0
!	  ) : d0->MemErr;
!
	.extern	_SetPtrSize
_SetPtrSize:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.l	0x8(a6),a0
	move.l	0xc(a6),d0
	move.l	saveda5,a5
	.data2	0xa020
	move.w	d0,_MemErr
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
!	romcall 0xa01b void SetZone
!	  (
!		THz  : a0
!	  ) : d0->MemErr;
!
	.extern	_SetZone
_SetZone:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL74
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL74:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa01b
	move.w	d0,_MemErr
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
!	romcall 0xa065 Long StackSpace() : d0;
!
	.extern	_StackSpace
_StackSpace:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL76
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL76:
	move.l	saveda5,a5
	.data2	0xa065
	tst.l	savedsp
	beq	LL77
	move.l	(sp)+,a7
LL77:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

