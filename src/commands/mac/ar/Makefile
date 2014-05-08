CFLAGS	= -O -I. -DAAL

SRC	= archiver.c rd_object.c wr_arhdr.c wr_object.c wr_ranlib.c
OBJ	= archiver.o rd_object.o wr_arhdr.o wr_object.o wr_ranlib.o

all:	ar

ar:	$(OBJ)
	$(CC) -o $@ $(OBJ)
	chmem =16000 $@
	cp ar ../../bin

clean:	
	@rm -rf *.o *.bak

kit:
	rm -rf SRC SRCZ.a; mkdir SRC
	cp *.h *.c SRC
	cd SRC; compress -f -b13 *
	../bin/ar r SRCZ.a SRC/?*.Z
	rm -rf SRC
