LD=/usr/lib/ld
CV=/usr/lib/cv
LIB=/usr/lib
INC=/usr/include

CFLAGS=-T. -DFASTLOAD
s=$(INC)/sys
h=$(INC)/minix
LFLAGS = -c
a=const.h type.h $h/const.h $h/type.h $h/config.h $(INC)/errno.h \
	$(INC)/limits.h $s/types.h

obj =	main.o open.o \
	read.o write.o pipe.o device.o \
	path.o mount.o link.o super.o inode.o cache.o filedes.o \
	stadir.o protect.o time.o misc.o utility.o table.o \
	putc.o

fs.mix:	$(LIB)/head.o $(obj) $(LIB)/libc.a $(LIB)/end.o
	$(LD) $(LFLAGS) -o fs.ack $(LIB)/head.o $(obj) \
		 $(LIB)/libc.a $(LIB)/end.o
	$(CV) fs.ack fs.mix
	@rm -f fs.ack

clean:
	rm -f $(obj)

cache.o:	$a
cache.o:	$h/com.h
cache.o:	$h/boot.h
cache.o:	buf.h
cache.o:	file.h
cache.o:	fproc.h
cache.o:	glo.h
cache.o:	inode.h
cache.o:	super.h

device.o:	$a
device.o:	$h/com.h
device.o:	dev.h
device.o:	file.h
device.o:	fproc.h
device.o:	glo.h
device.o:	inode.h
device.o:	param.h

filedes.o:	$a
filedes.o:	file.h
filedes.o:	fproc.h
filedes.o:	glo.h
filedes.o:	inode.h

inode.o:	$a
inode.o:	$h/boot.h
inode.o:	buf.h
inode.o:	file.h
inode.o:	fproc.h
inode.o:	glo.h
inode.o:	inode.h
inode.o:	super.h

link.o:		$a
link.o:		$s/stat.h
link.o:		buf.h
link.o:		file.h
link.o:		fproc.h
link.o:		glo.h
link.o:		inode.h
link.o:		param.h

main.o:		$a
main.o:		$h/callnr.h
main.o:		$h/com.h
main.o:		$h/boot.h
main.o:		buf.h
main.o:		file.h
main.o:		fproc.h
main.o:		glo.h
main.o:		inode.h
main.o:		param.h
main.o:		super.h

misc.o:		$a
misc.o:		$h/callnr.h
misc.o:		$h/com.h
misc.o:		$h/boot.h
misc.o:		buf.h
misc.o:		file.h
misc.o:		fproc.h
misc.o:		glo.h
misc.o:		inode.h
misc.o:		param.h
misc.o:		super.h

mount.o:	$a
mount.o:	buf.h
mount.o:	$s/stat.h
mount.o:	file.h
mount.o:	fproc.h
mount.o:	glo.h
mount.o:	inode.h
mount.o:	param.h
mount.o:	super.h

open.o:		$a
open.o:		$h/callnr.h
open.o:		buf.h
open.o:		file.h
open.o:		fproc.h
open.o:		glo.h
open.o:		inode.h
open.o:		param.h

path.o:		$a
path.o:		buf.h
path.o:		file.h
path.o:		fproc.h
path.o:		glo.h
path.o:		inode.h
path.o:		super.h

pipe.o:		$a
pipe.o:		$h/callnr.h
pipe.o:		$h/com.h
pipe.o:		$(INC)/signal.h
pipe.o:		dev.h
pipe.o:		file.h
pipe.o:		fproc.h
pipe.o:		glo.h
pipe.o:		inode.h
pipe.o:		param.h

protect.o:	$a
protect.o:	buf.h
protect.o:	file.h
protect.o:	fproc.h
protect.o:	glo.h
protect.o:	inode.h
protect.o:	param.h
protect.o:	super.h

putc.o:		$a
putc.o:		$h/com.h
putc.o:		glo.h

read.o:		$a
read.o:		$h/com.h
read.o:		buf.h
read.o:		file.h
read.o:		fproc.h
read.o:		glo.h
read.o:		inode.h
read.o:		param.h
read.o:		super.h

stadir.o:	$a
stadir.o:	$s/stat.h
stadir.o:	file.h
stadir.o:	fproc.h
stadir.o:	glo.h
stadir.o:	inode.h
stadir.o:	param.h

super.o:	$a
super.o:	$h/boot.h
super.o:	buf.h
super.o:	glo.h
super.o:	inode.h
super.o:	super.h

table.o:	$a
table.o:	$h/com.h
table.o:	$h/callnr.h
table.o:	$s/stat.h
table.o:	buf.h
table.o:	dev.h
table.o:	file.h
table.o:	fproc.h
table.o:	glo.h
table.o:	inode.h
table.o:	super.h

time.o:		$a
time.o:		$h/callnr.h
time.o:		$h/com.h
time.o:		file.h
time.o:		fproc.h
time.o:		glo.h
time.o:		inode.h
time.o:		param.h

utility.o:	$a
utility.o:	$h/com.h
utility.o:	$h/boot.h
utility.o:	buf.h
utility.o:	file.h
utility.o:	fproc.h
utility.o:	glo.h
utility.o:	inode.h
utility.o:	param.h
utility.o:	super.h

write.o:	$a
write.o:	buf.h
write.o:	file.h
write.o:	fproc.h
write.o:	glo.h
write.o:	inode.h
write.o:	super.h
