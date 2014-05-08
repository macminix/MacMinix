CFLAGS= -c -DACK -LIB -D_MINIX -D_POSIX_SOURCE
MFILE=Makefile

$f.o:	$f.$e
	@echo ------------------------------ $f ------------------------------
	@$(CC) $(CFLAGS) $f.$e;


clean:	
	@rm -rf *.o *.bak


all:	
	@rm -rf tmp.1 *.o *.bak
	@ls *.c >tmp.1
	@sed <tmp.1 >tmp.2 '/\.c/s///;/^/s//make -f $(MFILE) e=c f=/'
	@sh tmp.2
	@rm tmp.2
	@ls *.s >tmp.1
	@sed <tmp.1 >tmp.2 '/\.s/s///;/^/s//make -f $(MFILE) e=s f=/'
	@sh tmp.2
	@rm tmp.2
	@rm tmp.1
