# Makefile for partition program
#
OFILES = main.o utils.o rw.o insdel.o dump.o check.o notyet.o \
	update.o

CFILES = main.c utils.c rw.c insdel.c dump.c check.c notyet.c \
	update.c

CFLAGS=  -O
LIBS= -lmac

partition:	$(OFILES)
	cc -o partition $(OFILES) $(LIBS)
	chmem =16384 partition
	chmod 700 partition
	@echo Done making partition.  You may need to
	@echo adjust the memory allotment if you have lots of
	@echo partitions\; allow 1K per partition plus a bit.
	@echo Be sure to read the README file!

clean:
	rm -rf core *.o

main.o:	partition.h

utils.o:	partition.h

rw.o:	partition.h

insdel.o:	partition.h

dump.o:	partition.h

check.o:	partition.h

notyet.o:	partition.h

update.o:	partition.h
