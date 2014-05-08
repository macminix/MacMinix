LD=/usr/lib/ld
CV=/usr/lib/cv
ASFLAGS=-c -DACK -T.
AS=$(CC) $(ASFLAGS)
CFLAGS=-c -I../kernel -D_POSIX_SOURCE -D_MINIX -T.
LFLAGS = -c
LIB=/usr/lib

all:	macboot boot init.mix

macboot:	$(LIB)/crtmac.o $(LIB)/relocate.o macboot.o \
		../kernel/setup.o macboot1.o \
		 $(LIB)/libmac.a $(LIB)/libc.a $(LIB)/end.o
	$(LD) $(LFLAGS) -o macboot.ack $(LIB)/crtmac.o $(LIB)/relocate.o \
		../kernel/setup.o macboot.o macboot1.o \
		$(LIB)/libmac.a $(LIB)/libc.a $(LIB)/end.o
	$(CV) macboot.ack macboot
	@rm -f macboot.ack

boot:	macboot init.mix
	rmaker -v minix.rc NEWmacboot
	settype -c MNIX -t APPL NEWmacboot
	@echo macboot done.

init.mix:	init.o $(LIB)/libc.a $(LIB)/head.o
	$(LD) $(LFLAGS) -o init.ack $(LIB)/head.o init.o \
		$(LIB)/libc.a $(LIB)/end.o
	$(CV) init.ack init.mix
	@rm -f init.ack
	@echo init done.

clean:
	rm -f *.o *.back
