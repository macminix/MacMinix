all:	term write_tty read_tty


term:	term.o err.o 
	$(CC) -o term term.o err.o
	chmem =8192 term

write_tty:	write_tty.o do_shell.o
	$(CC) -o write_tty write_tty.o do_shell.o
	chmem =8192 write_tty

read_tty:	read_tty.o
	$(CC) -o read_tty read_tty.o
	chmem =8192 read_tty

write_tty.o:	write_tty.c const.h
	$(CC) -c -O write_tty.c

read_tty.o:	read_tty.c const.h
	$(CC) -c -O read_tty.c

term.o:	term.c
	$(CC) -c -O term.c

err.o:	err.c
	$(CC) -c -O err.c

do_shell.o: do_shell.c
	$(CC) -c -O do_shell.c

clean:	
	@rm -rf *.o *.bak

