	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
	.sect	.text
!
! This interface routine generated automatically
! according to the prototype:
!
!	romcall 0xa016 void FInitQueue() : d0;
!
	.extern	_FInitQueue
_FInitQueue:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL0
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL0:
	move.l	saveda5,a5
	.data2	0xa016
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
!	romcall 0xa010 OSErr PBAllocate
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBAllocate
_PBAllocate:
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
	tst.b	0xd(a6)
	beq	LL3
	.data2	0xa410
	bra	LL4
LL3:
	.data2	0xa010
LL4:
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
!	romcall 0xa210 OSErr PBAllocContig
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBAllocContig
_PBAllocContig:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL6
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL6:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL7
	.data2	0xa610
	bra	LL8
LL7:
	.data2	0xa210
LL8:
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
!	romcall 0xa001 OSErr PBClose
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBClose
_PBClose:
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
	tst.b	0xd(a6)
	beq	LL11
	.data2	0xa401
	bra	LL12
LL11:
	.data2	0xa001
LL12:
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
!	romcall 0xa004 OSErr PBControl
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBControl
_PBControl:
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
	tst.b	0xd(a6)
	beq	LL15
	.data2	0xa404
	bra	LL16
LL15:
	.data2	0xa004
LL16:
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
!	romcall 0xa008 OSErr PBCreate
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBCreate
_PBCreate:
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
	tst.b	0xd(a6)
	beq	LL19
	.data2	0xa408
	bra	LL20
LL19:
	.data2	0xa008
LL20:
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
!	romcall 0xa009 OSErr PBDelete
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBDelete
_PBDelete:
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
	tst.b	0xd(a6)
	beq	LL23
	.data2	0xa409
	bra	LL24
LL23:
	.data2	0xa009
LL24:
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
!	romcall 0xa017 OSErr PBEject
!	  (
!		ParmBlkPtr  : a0
!	  ) : d0;
!
	.extern	_PBEject
_PBEject:
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
	.data2	0xa017
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
!	romcall 0xa045 OSErr PBFlushFile
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBFlushFile
_PBFlushFile:
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
	tst.b	0xd(a6)
	beq	LL29
	.data2	0xa445
	bra	LL30
LL29:
	.data2	0xa045
LL30:
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
!	romcall 0xa013 OSErr PBFlushVol
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBFlushVol
_PBFlushVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL32
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL32:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL33
	.data2	0xa413
	bra	LL34
LL33:
	.data2	0xa013
LL34:
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
!	romcall 0xa011 OSErr PBGetEOF
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetEOF
_PBGetEOF:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL36
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL36:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL37
	.data2	0xa411
	bra	LL38
LL37:
	.data2	0xa011
LL38:
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
!	romcall 0xa007 OSErr PBGetVInfo
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetVInfo
_PBGetVInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL40
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL40:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL41
	.data2	0xa407
	bra	LL42
LL41:
	.data2	0xa007
LL42:
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
!	romcall 0xa00c OSErr PBGetFInfo
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetFInfo
_PBGetFInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL44
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL44:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL45
	.data2	0xa40c
	bra	LL46
LL45:
	.data2	0xa00c
LL46:
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
!	romcall 0xa018 OSErr PBGetFPos
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetFPos
_PBGetFPos:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL48
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL48:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL49
	.data2	0xa418
	bra	LL50
LL49:
	.data2	0xa018
LL50:
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
!	romcall 0xa014 OSErr PBGetVol
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetVol
_PBGetVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL52
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL52:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL53
	.data2	0xa414
	bra	LL54
LL53:
	.data2	0xa014
LL54:
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
!	romcall 0xa006 OSErr PBKillIO
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBKillIO
_PBKillIO:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL56
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL56:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL57
	.data2	0xa406
	bra	LL58
LL57:
	.data2	0xa006
LL58:
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
!	romcall 0xa00f OSErr PBMountVol
!	  (
!		ParmBlkPtr  : a0
!	  ) : d0;
!
	.extern	_PBMountVol
_PBMountVol:
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
	.data2	0xa00f
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
!	romcall 0xa035 OSErr PBOffLine
!	  (
!		ParmBlkPtr  : a0
!	  ) : d0;
!
	.extern	_PBOffLine
_PBOffLine:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL62
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL62:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa035
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
!	romcall 0xa000 OSErr PBOpen
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBOpen
_PBOpen:
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
	tst.b	0xd(a6)
	beq	LL65
	.data2	0xa400
	bra	LL66
LL65:
	.data2	0xa000
LL66:
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
!	romcall 0xa00a OSErr PBOpenRF
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBOpenRF
_PBOpenRF:
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
	tst.b	0xd(a6)
	beq	LL69
	.data2	0xa40a
	bra	LL70
LL69:
	.data2	0xa00a
LL70:
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
!	romcall 0xa002 OSErr PBRead
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBRead
_PBRead:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL72
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL72:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL73
	.data2	0xa402
	bra	LL74
LL73:
	.data2	0xa002
LL74:
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
!	romcall 0xa00b OSErr PBRename
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBRename
_PBRename:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL76
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL76:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL77
	.data2	0xa40b
	bra	LL78
LL77:
	.data2	0xa00b
LL78:
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
!	romcall 0xa042 OSErr PBRstFLock
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBRstFLock
_PBRstFLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL80
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL80:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL81
	.data2	0xa442
	bra	LL82
LL81:
	.data2	0xa042
LL82:
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
!	romcall 0xa012 OSErr PBSetEOF
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetEOF
_PBSetEOF:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL84
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL84:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL85
	.data2	0xa412
	bra	LL86
LL85:
	.data2	0xa012
LL86:
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
!	romcall 0xa00d OSErr PBSetFInfo
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetFInfo
_PBSetFInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL88
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL88:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL89
	.data2	0xa40d
	bra	LL90
LL89:
	.data2	0xa00d
LL90:
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
!	romcall 0xa241 OSErr PBSetFLock
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetFLock
_PBSetFLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL92
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL92:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL93
	.data2	0xa641
	bra	LL94
LL93:
	.data2	0xa241
LL94:
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
!	romcall 0xa044 OSErr PBSetFPos
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetFPos
_PBSetFPos:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL96
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL96:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL97
	.data2	0xa444
	bra	LL98
LL97:
	.data2	0xa044
LL98:
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
!	romcall 0xa043 OSErr PBSetFVers
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetFVers
_PBSetFVers:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL100
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL100:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL101
	.data2	0xa443
	bra	LL102
LL101:
	.data2	0xa043
LL102:
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
!	romcall 0xa015 OSErr PBSetVol
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetVol
_PBSetVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL104
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL104:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL105
	.data2	0xa415
	bra	LL106
LL105:
	.data2	0xa015
LL106:
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
!	romcall 0xa005 OSErr PBStatus
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBStatus
_PBStatus:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL108
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL108:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL109
	.data2	0xa405
	bra	LL110
LL109:
	.data2	0xa005
LL110:
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
!	romcall 0xa00e OSErr PBUnMountVol
!	  (
!		ParmBlkPtr  : a0
!	  ) : d0;
!
	.extern	_PBUnMountVol
_PBUnMountVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL112
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL112:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	.data2	0xa00e
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
!	romcall 0xa003 OSErr PBWrite
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBWrite
_PBWrite:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL114
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL114:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL115
	.data2	0xa403
	bra	LL116
LL115:
	.data2	0xa003
LL116:
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
!	romcall 0xa260 (pack number = -16) OSErr PBLockRange
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBLockRange
_PBLockRange:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL118
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL118:
	move.l	0x8(a6),a0
	move.w	#16,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL119
	.data2	0xa660
	bra	LL120
LL119:
	.data2	0xa260
LL120:
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
!	romcall 0xa260 (pack number = -17) OSErr PBUnlockRange
!	  (
!		ParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBUnlockRange
_PBUnlockRange:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL122
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL122:
	move.l	0x8(a6),a0
	move.w	#17,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL123
	.data2	0xa660
	bra	LL124
LL123:
	.data2	0xa260
LL124:
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
!	romcall 0xa207 OSErr PBHGetVInfo
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHGetVInfo
_PBHGetVInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL126
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL126:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL127
	.data2	0xa607
	bra	LL128
LL127:
	.data2	0xa207
LL128:
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
!	romcall 0xa214 OSErr PBHGetVol
!	  (
!		WDPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHGetVol
_PBHGetVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL130
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL130:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL131
	.data2	0xa614
	bra	LL132
LL131:
	.data2	0xa214
LL132:
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
!	romcall 0xa215 OSErr PBHSetVol
!	  (
!		WDPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHSetVol
_PBHSetVol:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL134
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL134:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL135
	.data2	0xa615
	bra	LL136
LL135:
	.data2	0xa215
LL136:
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
!	romcall 0xa200 OSErr PBHOpen
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHOpen
_PBHOpen:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL138
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL138:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL139
	.data2	0xa600
	bra	LL140
LL139:
	.data2	0xa200
LL140:
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
!	romcall 0xa20a OSErr PBHOpenRF
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHOpenRF
_PBHOpenRF:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL142
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL142:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL143
	.data2	0xa60a
	bra	LL144
LL143:
	.data2	0xa20a
LL144:
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
!	romcall 0xa208 OSErr PBHCreate
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHCreate
_PBHCreate:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL146
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL146:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL147
	.data2	0xa608
	bra	LL148
LL147:
	.data2	0xa208
LL148:
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
!	romcall 0xa260 (pack number = -6) OSErr PBDirCreate
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBDirCreate
_PBDirCreate:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL150
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL150:
	move.l	0x8(a6),a0
	move.w	#6,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL151
	.data2	0xa660
	bra	LL152
LL151:
	.data2	0xa260
LL152:
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
!	romcall 0xa209 OSErr PBHDelete
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHDelete
_PBHDelete:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL154
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL154:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL155
	.data2	0xa609
	bra	LL156
LL155:
	.data2	0xa209
LL156:
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
!	romcall 0xa20c OSErr PBHGetFInfo
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHGetFInfo
_PBHGetFInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL158
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL158:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL159
	.data2	0xa60c
	bra	LL160
LL159:
	.data2	0xa20c
LL160:
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
!	romcall 0xa20d OSErr PBHSetFInfo
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHSetFInfo
_PBHSetFInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL162
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL162:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL163
	.data2	0xa60d
	bra	LL164
LL163:
	.data2	0xa20d
LL164:
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
!	romcall 0xa242 OSErr PBHRstFLock
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHRstFLock
_PBHRstFLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL166
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL166:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL167
	.data2	0xa642
	bra	LL168
LL167:
	.data2	0xa242
LL168:
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
!	romcall 0xa241 OSErr PBHSetFLock
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHSetFLock
_PBHSetFLock:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL170
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL170:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL171
	.data2	0xa641
	bra	LL172
LL171:
	.data2	0xa241
LL172:
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
!	romcall 0xa20b OSErr PBHRename
!	  (
!		HParmBlkPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBHRename
_PBHRename:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL174
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL174:
	move.l	0x8(a6),a0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL175
	.data2	0xa60b
	bra	LL176
LL175:
	.data2	0xa20b
LL176:
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
!	romcall 0xa260 (pack number = -9) OSErr PBGetCatInfo
!	  (
!		CInfoPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetCatInfo
_PBGetCatInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL178
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL178:
	move.l	0x8(a6),a0
	move.w	#9,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL179
	.data2	0xa660
	bra	LL180
LL179:
	.data2	0xa260
LL180:
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
!	romcall 0xa260 (pack number = -10) OSErr PBSetCatInfo
!	  (
!		CInfoPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBSetCatInfo
_PBSetCatInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL182
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL182:
	move.l	0x8(a6),a0
	move.w	#10,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL183
	.data2	0xa660
	bra	LL184
LL183:
	.data2	0xa260
LL184:
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
!	romcall 0xa260 (pack number = -5) OSErr PBCatMove
!	  (
!		CMovePBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBCatMove
_PBCatMove:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL186
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL186:
	move.l	0x8(a6),a0
	move.w	#5,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL187
	.data2	0xa660
	bra	LL188
LL187:
	.data2	0xa260
LL188:
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
!	romcall 0xa260 (pack number = -1) OSErr PBOpenWD
!	  (
!		WDPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBOpenWD
_PBOpenWD:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL190
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL190:
	move.l	0x8(a6),a0
	move.w	#1,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL191
	.data2	0xa660
	bra	LL192
LL191:
	.data2	0xa260
LL192:
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
!	romcall 0xa260 (pack number = -2) OSErr PBCloseWD
!	  (
!		WDPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBCloseWD
_PBCloseWD:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL194
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL194:
	move.l	0x8(a6),a0
	move.w	#2,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL195
	.data2	0xa660
	bra	LL196
LL195:
	.data2	0xa260
LL196:
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
!	romcall 0xa260 (pack number = -7) OSErr PBGetWDInfo
!	  (
!		WDPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetWDInfo
_PBGetWDInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL198
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL198:
	move.l	0x8(a6),a0
	move.w	#7,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL199
	.data2	0xa660
	bra	LL200
LL199:
	.data2	0xa260
LL200:
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
!	romcall 0xa260 (pack number = -8) OSErr PBGetFCBInfo
!	  (
!		FCBPBPtr  : a0,
!		Boolean  : async
!	  ) : d0;
!
	.extern	_PBGetFCBInfo
_PBGetFCBInfo:
	link	a6,#0
	movem.l	d2/a5,-(sp)
	tst.l	savedsp
	beq	LL202
	move.l	a7,a0
	move.l	savedsp,a7
	move.l	a0,-(sp)
LL202:
	move.l	0x8(a6),a0
	move.w	#8,d0
	move.l	saveda5,a5
	tst.b	0xd(a6)
	beq	LL203
	.data2	0xa660
	bra	LL204
LL203:
	.data2	0xa260
LL204:
	tst.l	savedsp
	beq	LL205
	move.l	(sp)+,a7
LL205:
	movem.l	(sp)+,d2/a5
	unlk	a6
	rts

