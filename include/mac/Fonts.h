#ifndef _MAC_FONTS_H
#define _MAC_FONTS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

/* font numbers */
#define systemFont	0
#define applFont	1
#define newYork		2
#define geneva		3
#define monaco		4
#define venice 		5
#define london 		6
#define athens 		7
#define sanFran 	8
#define toronto 	9
#define cairo 		11
#define losAngeles 	12
#define times 		20
#define helvetica 	21
#define courier 	22
#define symbol 		23
#define mobile 		24

/* special characters */
#define commandMark 	0x11
#define checkMark 	0x12
#define diamondMark 	0x13
#define appleMark 	0x14

/* font types */
#define propFont 	0x9000
#define prpFntH 	0x9001
#define prpFntW 	0x9002
#define prpFntHW 	0x9003
#define fixedFont 	0xB000
#define fxdFntH 	0xB001
#define fxdFntW 	0xB002
#define fxdFntHW 	0xB003
#define fontWid 	0xACB0

/* typed efinitions */
typedef struct FMInput    FMInput;
typedef struct FMOutput   FMOutput;
typedef struct FMOutput  *FMOutPtr;
typedef struct FontRec    FontRec;
typedef struct FMetricRec FMetricRec;
typedef struct WidthTable WidthTable;
typedef struct FamRec     FamRec;

/* structures */
struct FMInput {
   Short family;
   Short size;
   Style face;
   Boolean needBits;
   Short device;
   Point numer;
   Point denom;
};

struct FMOutput {
   Short errNum;
   Handle fontHandle;
   unsigned char boldPixels;
   unsigned char italicPixels;
   unsigned char ulOffset;
   unsigned char ulShadow;
   unsigned char ulThick;
   unsigned char shadowPixels;
   char extra;
   unsigned char ascent;
   unsigned char descent;
   unsigned char widMax;
   char leading;
   char unused;
   Point numer;
   Point denom;
};

struct FontRec {
   Short fontType;
   Short firstChar;
   Short lastChar;
   Short widMax;
   Short kernMax;
   Short nDescent;
   Short fRectWidth;
   Short fRectHeight;
   Short owTLoc;
   Short ascent;
   Short descent;
   Short leading;
   Short rowWords;
};

struct FMetricRec {
   Fixed ascent;
   Fixed descent;
   Fixed leading;
   Fixed widMax;
   Handle wTabHandle;
};

struct FamRec {
   Short ffFlags;
   Short ffFamId;
   Short ffFirstChar;
   Short ffLastChar;
   Short ffAscent;
   Short ffDescent;
   Short ffLeading;
   Short ffWidMax;
   Long ffWTabOff;
   Long ffKernOff;
   Long ffStylOff;
   Short ffProperty[9];
   Short ffIntl[2];
   Short ffVersion;
};

struct WidthTable {
   Fixed tabData[256];
   Handle tabFont;
   Long sExtra;
   Long style;
   Short fID;
   Short fSize;
   Short face;
   Short device;
   Point inNumer;
   Point inDenom;
   Short aFID;
   Handle fHand;
   Boolean usedFam;
   unsigned char aFace;
   Short vOutput;
   Short hOutput;
   Short vFactor;
   Short hFactor;
   Short aSize;
   Short tabSize;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA835) _PROTOTYPE( void FontMetrics, (FMetricRec *theMetrics) );
ROMTRAP(0xA901) _PROTOTYPE( FMOutPtr FMSwapFont, (FMInput *inRec) );
ROMTRAP(0xA900) _PROTOTYPE( void GetFNum, (inStringPtr infontName, Short *theNum) );
ROMTRAP(0xA8FF) _PROTOTYPE( void GetFontName, (Short fontNum, outStringPtr theName) );
ROMTRAP(0xA8FE) _PROTOTYPE( void InitFonts, (void) );
ROMTRAP(0xA902) _PROTOTYPE( Boolean RealFont, (Short fontNum, Short size) );
ROMTRAP(0xA903) _PROTOTYPE( void SetFontLock, (Boolean lockFlag) );
ROMTRAP(0xA834) _PROTOTYPE( void SetFScaleDisable, (Boolean) );
ROMTRAP(0xA814) _PROTOTYPE( void SetFractEnable, (Boolean) );
#endif
