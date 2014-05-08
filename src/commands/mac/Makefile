PROGS = anm aoutdump asize astrip cc cv eject hdclose hdopen \
	maccreate macfile settype getname
LIBS  = /usr/lib/libc.a /usr/lib/libmac.a
CFLAGS= -D_MINIX -D_POSIX_SOURCE -Iar

.c:
	@echo COMPILING $* ...
	cc $(CFLAGS) -o $* $< -lmac
	@if test "$*" = "cv"; then chmem =32768 $*; else chmem =8192 $*; fi
	@chmod 755 $*
	@chown bin $*
	@chgrp bin $*

all:		$(PROGS)
anm:		anm.c ar/out.h $(LIBS)
aoutdump:	aoutdump.c ar/out.h $(LIBS)
asize:		asize.c ar/out.h $(LIBS)
astrip:		astrip.c ar/out.h $(LIBS)
cc:		cc.c $(LIBS)
cv:		cv.c ar/out.h $(LIBS)
eject:		eject.c $(LIBS)
hdclose:	hdclose.c $(LIBS)
hdopen:		hdopen.c $(LIBS)
maccreate:	maccreate.c $(LIBS)
macfile:	macfile.c $(LIBS)
settype:	settype.c $(LIBS)
getname:	getname.c $(LIBS)

install:
	@(test -f anm && echo INSTALLING anm in /usr/bin                       \
            && strip anm && mv anm /usr/bin; exit 0)
	@(test -f aoutdump && echo INSTALLING aoutdump in /usr/bin             \
          && strip aoutdump && mv aoutdump /usr/bin; exit 0)
	@(test -f asize && echo INSTALLING asize in /usr/bin                   \
          && strip asize && mv asize /usr/bin; exit 0)
	@(test -f astrip && echo INSTALLING astrip in /usr/bin                 \
          && strip astrip && mv astrip /usr/bin; exit 0)
	@(test -f cc && echo INSTALLING cc in /usr/bin                         \
          && strip cc && mv cc /usr/bin; exit 0)
	@(test -f cv && echo INSTALLING cv in /usr/lib                         \
          && strip cv && mv cv /usr/lib; exit 0)
	@(test -f eject && echo INSTALLING eject in /etc		       \
          && strip eject && mv eject /etc; exit 0)
	@(test -f hdclose && echo INSTALLING hdclose in /etc                   \
          && strip hdclose && mv hdclose /etc; exit 0)
	@(test -f hdopen && echo INSTALLING hdopen in /etc                     \
          && strip hdopen && mv hdopen /etc; exit 0)
	@(test -f maccreate && echo INSTALLING maccreate in /usr/bin           \
          && strip maccreate && mv maccreate /usr/bin; exit 0)
	@(test -f macfile && echo INSTALLING macfile in /usr/bin               \
          && strip macfile && mv macfile /usr/bin; exit 0)
	@(test -f settype && echo INSTALLING settype in /usr/bin               \
          && strip settype && mv settype /usr/bin; exit 0)
	@(test -f getname && echo INSTALLING getname in /usr/bin               \
          && strip getname && mv getname /usr/bin; exit 0)
	@(test -f getall.sh && echo INSTALLING getall in /usr/bin              \
          && mv getall.sh /usr/bin/getall; exit 0)

clean:
	@echo CLEANING UP ...
	@rm -f *.o $(PROGS)
