CFLAGS=-DATARI_ST -I/usr/src -T/usr/tmp -DVOLATILE=""
OBJS=mdb.o mdbexp.o mdbdis.o strtol.o

all: mdb

mdb: $(OBJS)
	cc -o mdb $(OBJS)
	chmem =15000 $@
