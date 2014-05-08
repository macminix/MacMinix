.sect .text
.sect .rom
.sect .data
.sect .bss

.sect .text

.define _flush040
_flush040:
	.data2 0xf4f8 ! CPUSHA IC,DC
	rts
