CFLAGS= -c -DACK -LIB -D_MINIX -D_POSIX_SOURCE
BUILD=echo
MFILE=Makefile
FILES = Vertical.h Files.h Controls.h Desk.h Dialogs.h Events.h Fonts.h \
	Memory.h Menus.h OSEvents.h OSUtils.h Quickdraw.h Resources.h \
	Segments.h Toolutils.h Windows.h Packages.h

$f.o:	$f.$e
	@echo ------------------------------ $f ------------------------------
	@$(CC) $(CFLAGS) $f.$e


clean:	
	@rm -rf *.o *.bak


all:	
	@rm -rf tmp.1 *.o *.bak
	@for i in ../../../include/mac/*.h;	\
	  do					\
	    $(BUILD) `basename $$i .h` -ack;	\
          done;
	@ls *.c >tmp.1
	@sed <tmp.1 >tmp.2 '/\.c/s///;/^/s//make -f $(MFILE) e=c f=/'
	@sh tmp.2
	@rm tmp.2
	@rm tmp.1
	@ls *.s >tmp.1
	@sed <tmp.1 >tmp.2 '/\.s/s///;/^/s//make -f $(MFILE) e=s f=/'
	@sh tmp.2
	@rm tmp.2
	@rm tmp.1
