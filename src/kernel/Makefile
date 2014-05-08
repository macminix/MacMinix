# Makefile for kernel using standard Minix directory layout and compiler.
# CPP may need changing to /usr/lib/cpp.
END		=$l/end.o
LDFLAGS 	= -c
LIBS		=$l/libc.a $l/libmac.a
START		=start.o
OTHER		=
CFLAGS		=-DACK -T. $(OTHER)
ASFLAGS		=-DACK -c -T.
CV		=/usr/lib/cv
AS		=$(CC) $(ASFLAGS)
LIB		=/usr/lib
INC		=/usr/include
LD		=/usr/lib/ld

a		=$i/errno.h $i/limits.h $s/types.h \
		 $h/config.h $h/const.h $h/type.h const.h type.h
h		=$(INC)/minix
i		=$(INC)
l		=$(LIB)
s		=$(INC)/sys

KEROBJS		=cstart.o mpx.o wini.o \
	table.o main.o tty.o floppy.o system.o proc.o bind.o \
	idle.o clock.o memory.o console.o rs232.o $(RS2) printer.o \
	exception.o dmp.o shadow.o setup.o misc.o keyboard.o copy68k.o
SOBJS		=

kernel.mix: $(START) $(KEROBJS) $(LIBS) $(END)
	$(LD) $(LDFLAGS) -o kernel.ack $(START) $(KEROBJS) \
	$(LIBS) $(END)
	$(CV) kernel.ack kernel.mix
	@rm -f kernel.ack

clean:
	rm -f $(START) $(KEROBJS) $(SOBJS)

clock.o:	$i/signal.h
clock.o:	$a
clock.o:	$h/callnr.h
clock.o:	$h/com.h
clock.o:	glo.h
clock.o:	proc.h

console.o:	$i/sgtty.h
console.o:	$a
console.o:	$h/callnr.h
console.o:	$h/com.h
console.o:	glo.h
console.o:	protect.h
console.o:	tty.h

floppy.o:	$a
floppy.o:	$h/callnr.h
floppy.o:	$h/com.h
floppy.o:	glo.h
floppy.o:	setup.h

dmp.o:		$a
dmp.o:		$h/callnr.h
dmp.o:		$h/com.h
dmp.o:		glo.h
dmp.o:		proc.h

exception.o:	$a
exception.o:	glo.h
exception.o:	proc.h
exception.o:	$i/signal.h

idle.o:	$a
idle.o:	$h/callnr.h
idle.o:	$h/com.h
idle.o:	glo.h
idle.o:	proc.h
idle.o:	keymap.h
idle.o:	setup.h

main.o:	$i/signal.h
main.o:	$a
main.o:	$h/callnr.h
main.o:	$h/com.h
main.o:	glo.h
main.o:	proc.h

memory.o:	$a
memory.o:	$h/callnr.h
memory.o:	$h/com.h
memory.o:	glo.h

printer.o:	$a
printer.o:	$h/callnr.h
printer.o:	$h/com.h
printer.o:	glo.h

proc.o:	$a
proc.o:	$h/callnr.h
proc.o:	$h/com.h
proc.o:	glo.h
proc.o:	proc.h

rs232.o:	$a
rs232.o:	$i/sgtty.h
rs232.o:	glo.h
rs232.o:	tty.h
rs232.o:	setup.h

shadow.o:	$a
shadow.o:	$h/callnr.h
shadow.o:	$h/com.h
shadow.o:	glo.h
shadow.o:	proc.h

system.o:	$i/signal.h
system.o:	$a
system.o:	$h/boot.h
system.o:	$h/callnr.h
system.o:	$h/com.h
system.o:	glo.h
system.o:	proc.h
system.o:	protect.h

table.o:	$a
table.o:	$h/com.h
table.o:	glo.h
table.o:	proc.h
table.o:	tty.h

tty.o:		$i/sgtty.h
tty.o:		$i/signal.h
tty.o:		$a
tty.o:		$h/callnr.h
tty.o:		$h/com.h
tty.o:		glo.h
tty.o:		tty.h

wini.o:	$a
wini.o:	$h/callnr.h
wini.o:	$h/com.h
wini.o:	$h/partition.h
wini.o:	glo.h
wini.o:	setup.h

cstart.o:	$a
cstart.o:	$h/boot.h
cstart.o:	glo.h
cstart.o:	setup.h

keyboard.o:	$i/sgtty.h
keyboard.o:	$i/signal.h
keyboard.o:	$a
keyboard.o:	$h/callnr.h
keyboard.o:	$h/com.h
keyboard.o:	glo.h
keyboard.o:	tty.h
keyboard.o:	keymap.h
keyboard.o:	setup.h

misc.o:	$a
misc.o:	$h/com.h
misc.o:	glo.h
misc.o:	proc.h

setup.o:	$a
setup.o:	setup.h
