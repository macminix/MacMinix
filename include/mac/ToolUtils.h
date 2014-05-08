#ifndef _MAC_TOOLUTILS_H
#define _MAC_TOOLUTILS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

/* standard pattern list res id */
#define sysPatListID 	0

/* cursor res id */
#define iBeamCursor 	1
#define crossCursor 	2
#define plusCursor 	3
#define watchCursor 	4

typedef struct Int64Bit Int64Bit;
typedef struct Cursor  *CursPtr;
typedef struct Cursor **CursHandle;
typedef Pattern        *PatPtr;
typedef Pattern       **PatHandle;
typedef Long            Fract;		/* IM IV-63 */

struct Int64Bit {
	Long hiLong;
	Long loLong;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

/* fixed and fractional */
ROMTRAP(0xA841) _PROTOTYPE( Fract Fix2Frac, (Fixed) );
ROMTRAP(0xA840) _PROTOTYPE( Long Fix2Long, (Fixed) );
ROMTRAP(0xA843) _PROTOTYPE( double Fix2X, (Fixed) );
ROMTRAP(0xA843) _PROTOTYPE( Fixed FixATan2, (Long a, Long b) );
ROMTRAP(0xA84D) _PROTOTYPE( Fixed FixDiv, (Fixed a, Fixed b) );
ROMTRAP(0xA868) _PROTOTYPE( Fixed FixMul, (Fixed a, Fixed b) );
ROMTRAP(0xA869) _PROTOTYPE( Fixed FixRatio, (Short numer, Short denom) );
ROMTRAP(0xA86C) _PROTOTYPE( Short FixRound, (Fixed) );
ROMTRAP(0xA842) _PROTOTYPE( Fixed Frac2Fix, (Fract) );
ROMTRAP(0xA845) _PROTOTYPE( double Frac2X, (Fract) );
ROMTRAP(0xA847) _PROTOTYPE( Fract FracCos, (Fixed) );
ROMTRAP(0xA84B) _PROTOTYPE( Fract FracDiv, (Fract, Fract) );
ROMTRAP(0xA84A) _PROTOTYPE( Fract FracMul, (Fract, Fract) );
ROMTRAP(0xA848) _PROTOTYPE( Fract FracSin, (Fixed) );
ROMTRAP(0xA849) _PROTOTYPE( Fract FracSqrt, (Fract) );
ROMTRAP(0xA83F) _PROTOTYPE( Fixed Long2Fix, (Long) );
ROMTRAP(0xA844) _PROTOTYPE( Fixed X2Fix, (double *a) );
ROMTRAP(0xA846) _PROTOTYPE( Fract X2Frac, (double *a) );

/* strings */
ROMTRAP(0xA906) _PROTOTYPE( StringHandle NewString, (inStringPtr) );
ROMTRAP(0xA907) _PROTOTYPE( void SetString, (StringHandle, inStringPtr) );
ROMTRAP(0xA9BA) _PROTOTYPE( StringHandle GetString, (Short stringID) );
_PROTOTYPE( void GetIndString, (outStringPtr, Short strListID, Short index) );

/* byte manipulation */
ROMTRAP(0xA9E0) _PROTOTYPE( Long Munger, (Handle, Long offset, void *, Long len1, void *, Long len2) );
ROMTRAP(0xA8CF) _PROTOTYPE( void PackBits, (Ptr *srcPtr, Ptr *dstPtr, Short srcBytes) );
ROMTRAP(0xA8D0) _PROTOTYPE( void UnpackBits, (Ptr *srcPtr, Ptr *dstPtr, Short dstBytes) );

/* bit manipulation */
ROMTRAP(0xA85D) _PROTOTYPE( Boolean BitTst, (Ptr bytePtr, Long bitNum) );
ROMTRAP(0xA85E) _PROTOTYPE( void BitSet, (Ptr bytePtr, Long bitNum) );
ROMTRAP(0xA85F) _PROTOTYPE( void BitClr, (Ptr bytePtr, Long bitNum) );

/* logical operations */
ROMTRAP(0xA858) _PROTOTYPE( Long BitAnd, (Long val1, Long val2) );
ROMTRAP(0xA85B) _PROTOTYPE( Long BitOr, (Long val1, Long val2) );
ROMTRAP(0xA859) _PROTOTYPE( Long BitXor, (Long val1, Long val2) );
ROMTRAP(0xA85A) _PROTOTYPE( Long BitNot, (Long val) );
ROMTRAP(0xA85C) _PROTOTYPE( Long BitShift, (Long val, Short count) );

/* other */
ROMTRAP(0xA86A) _PROTOTYPE( Short HiWord, (Long) );
ROMTRAP(0xA86B) _PROTOTYPE( Short LoWord, (Long) );
ROMTRAP(0xA867) _PROTOTYPE( void LongMul, (Long a, Long b, Int64Bit *dest) );

/* graph utils */
_PROTOTYPE( void ScreenRes, (Short *scrnVRes, Short *scrnHres) );
ROMTRAP(0xA9BB) _PROTOTYPE( Handle GetIcon, (Short iconID) );
ROMTRAP(0xA94B) _PROTOTYPE( void PlotIcon, (Rect *r, Handle theIcon) );
ROMTRAP(0xA9B8) _PROTOTYPE( PatHandle GetPattern, (Short patID) );
_PROTOTYPE( void GetIndPattern, (PatPtr, Short patListID, Short index) );
ROMTRAP(0xA9B9) _PROTOTYPE( CursHandle GetCursor, (Short cursorID) );
ROMTRAP(0xA855) _PROTOTYPE( void ShieldCursor, (Rect *shieldRect, Point offsetPt) );
ROMTRAP(0xA9BC) _PROTOTYPE( PicHandle GetPicture, (Short picID) );


/* misc */
ROMTRAP(0xA94F) _PROTOTYPE( Long DeltaPoint, (Point ptA, Point PtB) );
ROMTRAP(0xA8BC) _PROTOTYPE( Fixed SlopeFromAngle, (Short angle) );
ROMTRAP(0xA8C4) _PROTOTYPE( Short AngleFromSlope, (Fixed slope) );
#endif
