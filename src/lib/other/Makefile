CFLAGS= -c -LIB -D_MINIX -D_POSIX_SOURCE
MFILE=Makefile

$f.o:	$f.c
	@echo ------------------------------ $f ------------------------------
	@$(CC) $(CFLAGS) $f.c


clean:	
	@rm -rf *.o *.bak


all:	
	@ls *.c >tmp.1
	@sed <tmp.1 >tmp.2 '/\.c/s///;/^/s//make -f $(MFILE) f=/'
	@rm -rf tmp.1 *.o *.bak
	@sh tmp.2
	@rm tmp.2
