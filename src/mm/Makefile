LD=/usr/lib/ld
CV=/usr/lib/cv
LIB=/usr/lib
INC=/usr/include

CFLAGS=-T.
LFLAGS = -c
s=$(INC)/sys
h=$(INC)/minix
a=const.h $h/const.h $h/type.h $h/config.h $(INC)/errno.h $\
	$(INC)/limits.h $s/types.h

obj =	main.o forkexit.o break.o exec.o signal.o getset.o \
	alloc.o utility.o table.o putc.o trace.o

mm.mix:	$(LIB)/head.o $(obj) $(LIB)/libc.a $(LIB)/end.o
	$(LD) $(LFLAGS) -o mm.ack $(LIB)/head.o $(obj) \
		$(LIB)/libc.a $(LIB)/end.o
	$(CV) mm.ack mm.mix
	@rm -f mm.ack

clean:
	rm -f $(obj)

alloc.o:	$a
alloc.o:	glo.h

break.o:	$a
break.o:	$(INC)/signal.h
break.o:	glo.h
break.o:	mproc.h
break.o:	param.h

exec.o:		$a
exec.o:		$h/callnr.h
exec.o:		$s/stat.h
exec.o:		glo.h
exec.o:		mproc.h
exec.o:		param.h

forkexit.o:	$a
forkexit.o:	$h/callnr.h
forkexit.o:	glo.h
forkexit.o:	mproc.h
forkexit.o:	param.h

getset.o:	$a
getset.o:	$h/callnr.h
getset.o:	glo.h
getset.o:	mproc.h
getset.o:	param.h

main.o:		$a
main.o:		$h/callnr.h
main.o:		$h/com.h
main.o:		glo.h
main.o:		mproc.h
main.o:		param.h

putc.o:		$a
putc.o:		$h/com.h
putc.o:		glo.h

signal.o:	$a
signal.o:	$h/callnr.h
signal.o:	$h/com.h
signal.o:	$(INC)/signal.h
signal.o:	glo.h
signal.o:	mproc.h
signal.o:	param.h

table.o:	$a
table.o:	$h/callnr.h
table.o:	glo.h
table.o:	mproc.h
table.o:	param.h

trace.o:	$a
trace.o:	$(INC)/signal.h
trace.o:	glo.h
trace.o:	mproc.h
trace.o:	param.h

utility.o:	$a
utility.o:	$h/callnr.h
utility.o:	$h/com.h
utility.o:	$s/stat.h
utility.o:	glo.h
utility.o:	mproc.h
