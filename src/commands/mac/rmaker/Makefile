CFLAGS= -O -D_MINIX -D_POSIX_SOURCE

OBJ = alrt.o bndl.o buildrf.o cntl.o ditl.o dlog.o fref.o hexa.o main.o	\
      menu.o misc.o out.o parse.o size.o smalloc.o str.o wind.o conf.o

install:	../../bin/rmaker
	@(test -f ../../bin/rmaker && echo INSTALLING rmaker in /usr/bin                       \
            && strip ../../bin/rmaker && mv ../../bin/rmaker /usr/bin; exit 0)

rmaker:	$(OBJ)
	$(CC) -o ../../bin/rmaker $(OBJ) -lmac
	chmem =65000 ../../bin/rmaker

conf.o: conf.c /usr/src/kernel/setup.h
	$(CC) $(CFLAGS) -I/usr/src/kernel -c conf.c

clean:
	rm -f rmaker *.o
