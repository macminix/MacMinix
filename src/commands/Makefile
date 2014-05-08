# To make  'cp', type:   make f=cp
# To make  'ls', type:   make f=ls
# To make  'cat', type:   make f=cat
# Get the idea?

# To make everything, use:
#  mkdir bin
#  for i in *.c
#  do make f=`basename $i .c`
#  done
#
# Furthermore, many commands need a different memory allocation, so chmem must
# be run to change it.  See the shell script 'changemem' in tools.

l=/usr/lib
CFLAGS=  -D_MINIX -D_POSIX_SOURCE
MFILE=Makefile

File:	$l/libc.a $f.c
	@$(CC) $(CFLAGS) -o bin/$f $f.c
	@chmem =8192 bin/$f >/dev/null

clean:	
	@rm -f *.o *.bak
	@rm -f */*.o
	@rm -f */*.bak

all:	
	@ls *.c >tmp.1
	@sed <tmp.1 >tmp.2 '/\.c/s///;/^/s//make -f $(MFILE) f=/'
	@rm -rf tmp.1 bin
	@mkdir bin
	@sh tmp.2
	@rm tmp.2
