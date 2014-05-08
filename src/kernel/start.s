#
! This is the C run-time start-off routine.

! public labels
	.define	EXIT
	.define	.trpim
	.define	.trppc
	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
! external references
	.extern	_cstart

	.sect	.text
start:	
	move.l	8(a7),saveda5
	jmp	_cstart
EXIT:
L0:	bra	L0

	.define _geta5
_geta5:
	move.l	saveda5,d0
	rts

	.define _getksp
_getksp:
	move.l	savedsp,d0
	rts

	.define _getgp
_getgp:
	move.l	saveda5,a0
	move.l	(a0),a0
	move.l	(a0),d0
	rts

	.define _setksp
_setksp:
	move.l	a7,savedsp
	rts

	.sect	.data
	.define	saveda5
	.define	savedsp
	.define	saveaddr
	.define	savesr
	.define	saverts
	.define	inclock
saveda5:.data4	0
savedsp:.data4	0
saveaddr:.data4	0
savesr:.data2	0
saverts:.data4	0
inclock:.data2	0
.trpim:	.data2	0
.trppc:	.data4	0
