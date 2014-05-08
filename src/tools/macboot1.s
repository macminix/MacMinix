#
#ifdef ACK
	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss

	.sect	.text
	.define	_cura7
	.define	_seta7

_cura7:
	move.l	a7,d0
	rts

_seta7:
	move.l	(sp)+,a0
	move.l	(sp)+,a1
	move.l  a1,a7
	move.l  a1,-(sp)
	move.l  a0,-(sp)
	rts
#endif
