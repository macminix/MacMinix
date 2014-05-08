#ifndef _MAC_PRINT_H
#define _MAC_PRINT_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

/* methods */
#define bDraftLoop 	0
#define bSpoolLoop	1

/* printer spec */
#define bDevCItoh	1
#define bDevLaser	3

/* max pages in spool file */
#define iPFMaxPgs	128

/* prctlcall params */
#define iPrDevCtl	7
#define lPrReset	0x10000
#define lPrLineFeed	0x30000
#define lPrLFSixth	0x3FFFF
#define lPrPageEnd	0x20000
#define iPrBitsCtl	4
#define lScreenBits	0
#define	lPaintBits	1
#define iPrIOCtl	5

/* driver info */
#define sPrDrvr		".Print"
#define iPrDrvrRef	-3

/* type defs */
typedef struct TPrInfo  TPrInfo;
typedef struct TPrJob   TPrJob;
typedef struct TPrStl   TPrStl;
typedef struct TPrXInfo TPrXInfo;
typedef struct TPrStatus TPrStatus;
typedef struct TPrPort  TPrPort;
typedef struct TPrPort *TPPrPort;
typedef struct TPrint   TPrint;
typedef struct TPrint   *TPPrint;
typedef struct TPrint   **THPrint;
typedef struct Rect     *TPRect;

/* structures */
struct TPrPort {
   GrafPort gPort;
   QDProcs  gProcs;
   Long	    param[4];
   Boolean  Ptr;
   Boolean  Bits;
};

struct TPrInfo {
   Short iDev;
   Short iVRes;
   Short iHRes;
   Rect  rPage;
};

struct TPrJob {
   Short iFstPage;
   Short iLstPage;
   Short iCopies;
   char  bJDocLoop;
   Boolean fFromUsr;
   ProcPtr pIdleProc;
   StringPtr pFileName;
   Short iFileVol;
   char bFileVers;
   char bJobX;
};

struct TPrStl {
   Short wDev;
   Short iPageV;
   Short iPageH;
   char  bPort;
   char feed;
};

struct TPrXInfo {
   Short iRowBytes;
   Short iBandV;
   Short iBandH;
   Short iDevBytes;
   Short iBands;
   char  bPatScale;
   char  bULThick;
   char  bULOffset;
   char  bULShadow;
   char scan;
   char  bXInfoX;
};

struct TPrint {
   Short iPrVersion;
   TPrInfo prInfo;
   Rect rPaper;
   TPrStl  prStl;
   TPrInfo prInfoPT;
   TPrXInfo prXInfo;
   TPrJob prJob;
   Short prntX[19];
};

struct TPrStatus {
   Short iTotPages;
   Short iCurPage;
   Short iTotCopies;
   Short iCurCopy;
   Short iTotBands;
   Short iCurBand;
   Boolean fPgDirty;
   Boolean fImaging;
   THPrint hPrint;
   TPPrPort pPrPort;
   PicHandle hPic;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void PrClose, (void) );
_PROTOTYPE( void PrintDefault, (THPrint) );
_PROTOTYPE( void PrCloseDoc, (TPPrPort) );
_PROTOTYPE( void PrClosePage, (TPPrPort) );
_PROTOTYPE( void PrCtlCall, (Short iWhichCtl, Long lparm1, Long lparm2, Long lparm3) );
_PROTOTYPE( void PrDrvrClose, (void) );
_PROTOTYPE( Handle PrDrvrDCE, (void) );
_PROTOTYPE( void PrDrvrOpen, (void) );
_PROTOTYPE( Short PrDrvrVers, (void) );
_PROTOTYPE( Short PrError, (void) );
_PROTOTYPE( Boolean PrJobDialog, (THPrint) );
_PROTOTYPE( void PrJobMerge, (THPrint hPrintSrc, THPrint hPrintDst) );
_PROTOTYPE( void PrOpen, (void) );
_PROTOTYPE( TPPrPort PrOpenDoc, (THPrint, TPPrPort, Ptr pIOBuf) );
_PROTOTYPE( void PrOpenPage, (TPPrPort, TPRect pPageFrame) );
_PROTOTYPE( void PrPicFile, (THPrint, TPPrPort, Ptr pIOBuf, Ptr pDevBuf, TPrStatus *prStatus) );
_PROTOTYPE( void PrSetError, (Short iErr) );
_PROTOTYPE( Boolean PrStlDialog, (THPrint) );
_PROTOTYPE( Boolean PrValidate, (THPrint) );
#endif
