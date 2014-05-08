#include "kernel.h"
#include "setup.h"
#include "tty.h"
#include <mac/Windows.h>
#include <mac/Dialogs.h>
#include <mac/Resources.h>
#include <mac/Memory.h>
#include <mac/Fonts.h>
#include <mac/Packages.h>
#include <mac/Files.h>
#include <mac/BCD.h>
#include <mac/StdFile.h>

#define BOK		1
#define BCANCEL		2
#define BHEAP		5
#define BRAM		6
#define BMAP		7
#define BFILE		8
#define BPORTA		9
#define BPORTB		10
#define BMAPOPT		11
#define BMAPESCAPE	12
#define BMAPCMDOPT	13

#ifdef THINK_C
extern int CurApRefNum : 0x900;
#endif

PRIVATE char st[255];

FORWARD _PROTOTYPE( long totype, ( char *s ) );

/*===========================================================================*
 *				totype				     	     *
 *===========================================================================*/
PRIVATE long totype(s)
char *s;
{
  return *(long *)s;
}

/*===========================================================================*
 *				fullname				     *
 *===========================================================================*/
PUBLIC char *fullname(vol, s)
short vol;
char *s;
{
  CInfoPBRec c;
  static ParamBlockRec pb;
  int err;
  long dirid;
  char *p;
  static char out[255];
  char tmp[255];
  
  c.ioCompletion = 0;
  c.ioNamePtr = s;
  c.ioVRefNum = vol;
  c.ioFDirIndex = 0;
  c.CInfoType.hfileInfo.ioDirID = 0;
  err = PBGetCatInfo(&c, 0);
  dirid = c.CInfoType.hfileInfo.ioFlParID;
  p = &out[255];
  *p = 0;
  p -= s[0];
  memcpy(p, &s[1], s[0]);
  while (err == 0) {
    *--p = ':';
    if (dirid == 2)
      break;
    c.ioCompletion = 0;
    c.ioNamePtr = tmp;
    c.ioVRefNum = 0;
    c.ioFDirIndex = -1;
    c.CInfoType.dirInfo.ioDrDirID = dirid;
    err = PBGetCatInfo(&c, 0);
    dirid=c.CInfoType.dirInfo.ioDrParID;
    if (err == 0) {
      p = p - tmp[0];
      memcpy(p, &tmp[1], tmp[0]);
    }
  }
  pb.ioCompletion = 0;
  pb.ioNamePtr = tmp;
  pb.ioVRefNum = vol;
  pb.ParamBlkType.volumeParam.ioVolIndex = 0;
  err = PBGetVInfo(&pb, 0);
  if (err == 0) {
    p = p - tmp[0];
    memcpy(p, &tmp[1], tmp[0]);
  }
  return p;
}

/*===========================================================================*
 *				setup				             *
 *===========================================================================*/
PUBLIC void setup(cf, dbox, warn)
struct config *cf;
{
  struct config save;
  DialogPtr d;
  short ih, it;
  Handle cr, h;
  Rect box;
  SFReply sfr;
  Point w;
  char *n;
  long hs;
  SFTypeList tl;
  char *p;
  EventRecord e;
#ifndef THINK_C
  extern int CurApRefNum;
#endif
  int currentref;

  if ((cr = GetNamedResource((ResType)"CONF", "MINIX Configuration")) == 0L) {
    memcpy(cf->root, "ROOT", 5);
    cf->heap = 200;
    cf->ram = 1;
    cf->keymap = 0;
    cf->porta = 1;		/* what the heck */
    cf->portb = 1;
    cf->mapopt = 1;
    cf->maptoescape = 1;
    cf->mapcmdopt = 1;
    if (cr = NewHandle((long)sizeof (struct config))) {
	  HLock(cr);
	  BlockMove(cf, *cr, (long)sizeof (struct config));
	  HUnlock(cr);
	  HNoPurge(cr);
	  currentref = CurResFile();
	  UseResFile(CurApRefNum);
	  AddResource(cr, (ResType)"CONF", 128, "MINIX Configuration");
	  WriteResource(cr);
	  HPurge(cr);
	  UseResFile(currentref);
    }
  }
  else {
    HLock(cr);
    BlockMove(*cr, cf, (long)sizeof(struct config));
    HUnlock(cr);
  }
  save = *cf;
  
  if (dbox == 0)
    return;
    
  d = GetNewDialog(129, 0L, (WindowPtr)-1);

  if (d == 0)
    return;
    
    GetDItem(d, BFILE, &it, &h, &box);
    SetIText(h, cf->root);
    NumToString((long)cf->heap, st);
    GetDItem(d, BHEAP, &it, &h, &box);
    SetIText(h, st);
    GetDItem(d, BMAP, &it, &h, &box);
    SetCtlValue(h, cf->keymap);
    GetDItem(d, BRAM, &it, &h, &box);
    SetCtlValue(h, cf->ram);
    GetDItem(d, BPORTA, &it, &h, &box);
    SetCtlValue(h, cf->porta);
    GetDItem(d, BPORTB, &it, &h, &box);
    SetCtlValue(h, cf->portb);
    GetDItem(d, BMAPOPT, &it, &h, &box);
    SetCtlValue(h, cf->mapopt);
    GetDItem(d, BMAPESCAPE, &it, &h, &box);
    SetCtlValue(h, cf->maptoescape);
    GetDItem(d, BMAPCMDOPT, &it, &h, &box);
    SetCtlValue(h, cf->mapcmdopt);
    GetNextEvent(0, &e);
    ShowWindow(d);
    if (Button()) DrawDialog(d);
    while (Button());
    FlushEvents(mUpMask|mDownMask,0);
    do {
      ModalDialog(0L, &ih);
      switch (ih) {
        case BMAP:
          cf->keymap = !cf->keymap;
	  GetDItem(d, BMAP, &it, &h, &box);
	  SetCtlValue(h, cf->keymap);
          break;
          
        case BRAM:
          cf->ram = !cf->ram;
	  GetDItem(d, BRAM, &it, &h, &box);
	  SetCtlValue(h, cf->ram);
          break;
          
        case BPORTA:
          cf->porta = !cf->porta;
	  GetDItem(d, BPORTA, &it, &h, &box);
	  SetCtlValue(h, cf->porta);
          break;
          
        case BPORTB:
          cf->portb = !cf->portb;
	  GetDItem(d, BPORTB, &it, &h, &box);
	  SetCtlValue(h, cf->portb);
          break;
          
        case BMAPOPT:
          cf->mapopt = !cf->mapopt;
	  GetDItem(d, BMAPOPT, &it, &h, &box);
	  SetCtlValue(h, cf->mapopt);
          break;

        case BMAPESCAPE:
          cf->maptoescape = !cf->maptoescape;
	  GetDItem(d, BMAPESCAPE, &it, &h, &box);
	  SetCtlValue(h, cf->maptoescape);
          break;

        case BMAPCMDOPT:
          cf->mapcmdopt = !cf->mapcmdopt;
	  GetDItem(d, BMAPCMDOPT, &it, &h, &box);
	  SetCtlValue(h, cf->mapcmdopt);
          break;

        case BFILE:
          GetDItem(d, BFILE, &it, &h, &box);
          w.h = 100;
          w.v = 100;
          tl[0] = totype("MXFS");
          SFGetFile(w, "", 0L, 1, tl, 0L, &sfr);
          if (sfr.good) {
            n = fullname(sfr.vRefNum, sfr.fName);
	    memcpy(cf->root, n, strlen(n)+1);
	  }
          else
            n = cf->root;
	  GetDItem(d, BFILE, &it, &h, &box);
	  SetIText(h, n);
          break;
          
        case BOK:
	  GetDItem(d, BHEAP, &it, &h, &box);
	  GetIText(h, st);
	  for (p = st; *p; p++)
	    if (*p < '0' || *p > '9') {
	  	ParamText("Please use a number for the heap size!", "", "", "");
	  	CautionAlert(128, 0L);
	  	ih = -1;
	  	break;
	    }
	  StringToNum(st, &hs);
	  if (hs < 150) {
	  	ParamText("Please use as least 150K for the heap size!", "", "", "");
	  	CautionAlert(128, 0L);
	  	ih = -1;
	  }
	  else
	  	cf->heap = hs;
          break;
          
        default:
          break;
      }
    } while (ih != BOK && ih != BCANCEL);
    
    if (ih == BOK) {
        HLock(cr);
        BlockMove(cf, *cr, (long)sizeof (struct config));
        HUnlock(cr);
	HNoPurge(cr);
        ChangedResource(cr);
	WriteResource(cr);
	HPurge(cr);
    }
    else
      *cf = save;
    CloseDialog(d);
    if (warn && ih == BOK) {
	ParamText("You must restart for any configuration changes to take effect.", "", "", "");
	NoteAlert(128, 0L);
    }
}
