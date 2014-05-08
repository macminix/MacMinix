# makefile for nroff (TOS)
#
CFLAGS		= -new -Dalcyon
# LDFLAGS for no symbols (-s) and to specify _STKSIZ in crt0.o (-stksiz)
LDFLAGS		= -new -s -stksiz
SRCS		= main.c command.c text.c io.c macros.c strings.c escape.c low.c
OBJS		= main.o command.o text.o io.o macros.o strings.o escape.o low.o
# LIBS is to get my own getenv, ctime, etc.
LIBS		= -llibc
TARGET		= nroff.ttp
MANPAGE		= nroff.1
MAN_MACRO	= tmac.an
#MS_MACRO	= tmac.s
#ME_MACRO	= tmac.e
# set these as per your system (for install)
TMACDIR		= c:\lib\tmac
BINDIR		= c:\bin
MANDIR		= c:\man\man1


# main target
#
$(TARGET):	$(OBJS)
		$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)


# install target
#
install:	$(TARGET)
		cp $(TARGET) $(BINDIR)\$(TARGET)
		cp $(MANPAGE) $(MANDIR)\$(MANPAGE)
		cp $(MAN_MACRO) $(TMACDIR)\$(MAN_MACRO)
#		cp $(MS_MACRO) $(TMACDIR)\$(MS_MACRO)
#		cp $(ME_MACRO) $(TMACDIR)\$(ME_MACRO)

clean:
		rm $(OBJS)

clobber:
		rm $(OBJS)
		rm $(TARGET)

# dependencies
#
nroff.h:	version.h
		touch nroff.h

main.o:		main.c nroff.h
command.o:	command.c nroff.h
text.o:		text.c nroff.h
io.o:		io.c nroff.h
macros.o:	macros.c nroff.h
strings.o:	strings.c nroff.h
escape.o:	escape.c nroff.h
low.o:		low.c nroff.h

