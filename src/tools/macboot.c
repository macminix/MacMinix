#include <mac/Events.h>
#include <mac/Windows.h>
#include <mac/Dialogs.h>
#include <mac/Resources.h>
#include <mac/Memory.h>
#include <mac/Fonts.h>
#include <mac/Packages.h>
#include <mac/Files.h>
#include <mac/BCD.h>
#include <mac/StdFile.h>
#include "setup.h"

#define KERNEL	"kernel"
#define MM	"mm"
#define FS	"fs"
#define INIT	"init"

#define ROUNDUPTOCLICK(amt) 	(((amt) + 0xffL) & 0xffffff00L)
#define ROUNDDOWNTOCLICK(amt) 	((amt) & 0xffffff00L)
/*
 *  Boot kernel, mm, fs, and init.
 *			Joe Pickert 10/10/88
 */

static long gsize[8];
#ifdef THINK_C
extern char *ApplLimit    : 0x0130;
extern char *HeapEnd      : 0x0114;
extern char *ApplZone     : 0x02AA;
extern char *CurrentA5    : 0x0904;
extern char *CurStackBase : 0x0908;
#else
extern char *ApplLimit;
extern char *HeapEnd;
extern char *ApplZone;
extern char *CurrentA5;
extern char *CurStackBase;
#endif

_PROTOTYPE( static void center, ( Rect *r, WindowPtr w ) );
_PROTOTYPE( static void inform, ( char *s, int font, int size, int face, int skip ) );
_PROTOTYPE( static void putc, ( char c, int font, int size, int face ) );
_PROTOTYPE( static hex, ( unsigned long i, int ndig ) );
_PROTOTYPE( static void warn, ( char *s1, char *s2, char *s3, char *s4, int fatal ) );
_PROTOTYPE( static long load, ( char *w, long *left, char *name, char *file, int idx ) );
_PROTOTYPE( int main, ( int argc, char *argv []) );
extern _PROTOTYPE(long relocate, (long *hdrp, char *txt, unsigned long segsizes[]) );
extern _PROTOTYPE( void setup, ( struct config *cf, int dbox ) );
extern _PROTOTYPE( void seta7, ( char *newa7 ) );
#ifdef THINK_C
extern _PROTOTYPE( void cstart, ( struct qd *q, long a5, long memat, long size, long kc, long kd, long mc, long md, long fc, long fd, long ic, long id ) );
#endif

static
void center(r, w)
Rect *r;
WindowPtr w;
{
   int th = (qd->thePort->portRect.right  - qd->thePort->portRect.left
		- (r->right  - r->left))/2;
   int tv = (qd->thePort->portRect.bottom - qd->thePort->portRect.top
		 - (r->bottom - r->top))/2;
   MoveWindow(w, th, tv, 1);
}

static
void inform(s, font, size, face, skip)
char   *s;
int     font, size, face, skip;
{
  static WindowPtr w = 0;
  static ypos = 0;
  Rect r;
  GrafPtr oldp;
  EventRecord e;

  if (s == 0) {
    if (w)
      CloseWindow(w);
    return;
  }
    
  GetPort(&oldp);
  if (w == 0) {
    SetRect(&r, 0, 0, 400, 135);
    w = NewWindow(0L, &r, "", 0, altDBoxProc, (WindowPtr)-1, 0, 0L);
    if (w == 0) return;
    center(&r, w);
    GetNextEvent(0, &e);
    ShowWindow(w);
    SetPort(w);
  }
  else
    SetPort(w);
  
  if (skip) {
    ypos = ypos + skip;
    MoveTo(20, ypos);
  }
  TextFont(font);
  TextSize(size);
  TextFace(face);
  DrawString(s);
  SetPort(oldp);
}

static
void putc(c, font, size, face)
char c;
int font, size, face;
{
  char s[2];
   
  s[0] = c;
  s[1] = 0;
  inform(s, font, size, face, 0);
}

static
hex(i, ndig)
unsigned long i;
{
  int j;
  
  putc('0', monaco, 9, normal);
  putc('x', monaco, 9, normal);
  for (j = ndig*4; j >= 0; j -= 4)
  	putc("0123456789ABCDEF"[(i >> j) & 0xf], monaco, 9, normal);
}

static
void warn(s1, s2, s3, s4, fatal)
char *s1, *s2, *s3, *s4;
int  fatal;
{
  ParamText(s1, s2, s3, s4);
  if (fatal) {
    StopAlert(128, 0L);
    ExitToShell();
  }
  else
    CautionAlert(128, 0L);
}

static
long load(w, left, name, file, idx)
char *w;
long *left;
char *name, *file;
int idx;
{
  Handle  h;
  unsigned long    sizes[3];
  unsigned long    need, tsize;
  long *hdr;
  char *loadat, *src, *p;
  long relocsize, i;

  if ((h = GetNamedResource((ResType)"BOOT", file)) == (Handle)0)
    warn("Can't find ", file, "", "", 1);
  HLock(h);
  hdr = (long *)*h;
  src = *h;
  src += 0x20;
  loadat = w;
  relocsize = GetHandleSize(h) - 0x20L - hdr[2] - hdr[3];
  need = hdr[2] + hdr[3] + hdr[4] + relocsize;
  if (need > *left)
    warn("Not enough memory left to load ", file, "", "", 1);
  BlockMove(src, w, hdr[2] + hdr[3]);
  src += hdr[2] + hdr[3];
  w += hdr[2] + hdr[3];
  for (p = w, i = 0; i < hdr[4]; i++)
    *p++ = 0;
  w += hdr[4];
  BlockMove(src, w, relocsize);
  if (relocate(hdr, loadat, sizes) < 0)
    warn(file, ": Error in relocation", "", "", 1);
  HUnlock(h);
  ReleaseResource(h);
  inform(name, monaco, 9, bold, 12);
  inform(" at ", monaco, 9, normal, 0);
  hex((unsigned long)loadat, 5);
  inform(" : ", monaco, 9, normal, 0);
  hex(sizes[0], 5);
  putc('+', monaco, 9, normal);
  hex(sizes[1], 5);
  putc('+', monaco, 9, normal);
  hex(sizes[2], 5);
  tsize = ROUNDUPTOCLICK(sizes[0] + sizes[1] + sizes[2]);
  gsize[idx] = sizes[0];
  gsize[idx+1] = tsize - gsize[idx];
  *left = *left - tsize;
  return tsize;
}

#ifdef THINK_C
extern char *saveda5;
#endif

main(argc, argv)
int argc;
char *argv[];
{
  char *mem;
  long sleft, left;
  int (*save)();
  Handle h;
  long g;
  struct config conf;

#ifdef THINK_C
  static struct qd qdg;
  saveda5 = CurrentA5;
  qd = &qdg;
#endif
  InitGraf((Ptr)&qd->thePort);
  InitFonts();
  InitWindows();
  InitMenus();
  TEInit();
  InitDialogs(0L);
  InitCursor();
  FlushEvents((short)-1, (short)0);

  setup(&conf, Button() == 1, 0);

  inform("   MacMINIX 1.5 Copyright ", systemFont, 12, normal, 40);
  putc(0xa9, systemFont, 12, normal);
  inform(" 1991 Prentice-Hall Inc.", systemFont, 12, normal, 0);

  /*
   * Get as much memory as is reasonable.  It is allocated on the 
   * STACK!
   */

  MaxMem(&g);
  SetApplLimit((char *)((long)ApplZone + ((long)conf.heap * 1024L)));
  if (HeapEnd > ApplLimit)
	SetApplLimit(HeapEnd);
  mem = (char *)ROUNDDOWNTOCLICK((long)ApplLimit + (long)(32*1024L));
  save = (int (*)())mem;
  left = ROUNDUPTOCLICK((long)CurStackBase - (long)mem);
  seta7(mem);
  sleft = left;

  /*
   * load & relocate kernel, mm, fs, and init
   */
  inform("", monaco, 9, normal, 15);
#ifdef THINK_C
  {
	extern long t_stacksize;
	extern char *t_stack;
	extern long pagesize;
	extern char *page;
	extern long vduinfosize;
	extern char *vduinfo;
	extern char *k_stackptr;
	extern long w_block_buf_size;
	extern char *w_block_buf;
	extern long w_iovec_size;
	extern char *w_iovec;
	extern long f_iovec_size;
	extern char *f_iovec;
	extern long f_block_buf_size;
	extern char *f_block_buf;
	char *z = mem;
	long i;
      
	gsize[0] = 0;
	gsize[1] = 0;

	k_stackptr = z+8192;
	z += 8192;
	gsize[0] += 8192;
	left -= 8192;

	vduinfo = z;
	z += vduinfosize;
	gsize[0] += vduinfosize;
	left -= vduinfosize;

	w_block_buf = z;
	z += w_block_buf_size;
	gsize[0] += w_block_buf_size;
	left -= w_block_buf_size;

	w_iovec = z;
	z += w_iovec_size;
	gsize[0] += w_iovec_size;
	left -= w_iovec_size;

	f_iovec = z;
	z += f_iovec_size;
	gsize[0] += f_iovec_size;
	left -= f_iovec_size;

	f_block_buf = z;
	z += f_block_buf_size;
	gsize[0] += f_block_buf_size;
	left -= f_block_buf_size;

	t_stack = z+10000;
	z += t_stacksize+10000;
	gsize[0] += t_stacksize+10000;
	left -= t_stacksize+10000;

	page = z;
	z += pagesize;
	gsize[0] += pagesize;
	left -= pagesize;

	gsize[0] = ROUNDUPTOCLICK(gsize[0]);
	for (z = mem, i = 0; i < gsize[0]; i++)
	   *z++ = 0;
	mem += gsize[0];
  }
#else
  mem += load(mem, &left, "    kernel ", KERNEL, 0);
#endif
  mem += load(mem, &left, "    mm     ", MM, 2);
  mem += load(mem, &left, "    fs     ", FS, 4);
  mem += load(mem, &left, "    init   ", INIT, 6);
  
  inform(0L, monaco, 9, normal, 0);
#ifdef THINK_C
  cstart(qd, (long)CurrentA5, (long)save, sleft, gsize[0], gsize[1], gsize[2],
	gsize[3], gsize[4], gsize[5], gsize[6], gsize[7]);
#else
  (*save)(qd, (long)CurrentA5, (long)save, sleft, gsize[0], gsize[1], gsize[2],
	gsize[3], gsize[4], gsize[5], gsize[6], gsize[7]);

#endif
  return 0;
}
