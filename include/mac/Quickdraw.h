#ifndef _MAC_QUICKDRAW_H
#define _MAC_QUICKDRAW_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* Source transfer modes */
#define srcCopy 	0
#define srcOr		1
#define srcXor		2
#define srcBic		3
#define notSrcCopy	4
#define notSrcOr	5
#define notSrcXor	6
#define notSrcBic	7

/* patterm transfer modes */
#define patCopy		8
#define patOr		9
#define patXor		10
#define patBic		11
#define notPatCopy	12
#define notPatOr	13
#define notPatXor	14
#define notPatBic	15

/* Standard colors */
#define blackColor	33
#define whiteColor	30
#define redColor	205
#define greenColor	341
#define blueColor	409
#define cyanColor	273
#define magentaColor	137
#define yellowColor	69

/* picture comments */
#define picLParen 	0
#define picRParen	1

/* style types */
#define normal		0x00
#define bold		0x01
#define italic		0x02
#define underline	0x04
#define outline		0x08
#define shadow		0x10
#define condense	0x20
#define extend		0x40

typedef struct Point Point;
typedef struct Rect Rect;
typedef struct Region Region;
typedef struct Region *RgnPtr;
typedef struct Region **RgnHandle;
typedef struct BitMap BitMap;
typedef unsigned char Pattern[8];
typedef Short Bits16[16];
typedef struct Cursor Cursor;
typedef struct QDProcs QDProcs;
typedef struct QDProcs *QDProcsPtr;
typedef struct GrafPort GrafPort;
typedef struct GrafPort *GrafPtr;
typedef struct Picture Picture;
typedef struct Picture *PicPtr;
typedef struct Picture **PicHandle;
typedef struct Polygon Polygon;
typedef struct Polygon *PolyPtr;
typedef struct Polygon **PolyHandle;
typedef struct PenState PenState;
typedef struct FontInfo FontInfo;
typedef char Style;
typedef enum {frame,paint,erase,invert,fill} GrafVerb;

struct Point {
   Short v;
   Short h;
};

struct Rect {
   Short top;
   Short left;
   Short bottom;
   Short right;
};

struct Region {
   Short rgnSize;
   Rect  rgnBBox;
   /* more info here */
};

struct BitMap {
   Ptr   baseAddr;
   Short rowBytes;
   Rect  bounds;
};

struct Cursor {
   Bits16 data;
   Bits16 mask;
   Point  hotSpot;
};

struct QDProcs {
   Ptr textProc;
   Ptr lineProc;
   Ptr rectProc;
   Ptr rRectProc;
   Ptr ovalProc;
   Ptr arcProc;
   Ptr polyProc;
   Ptr rgnProc;
   Ptr bitsProc;
   Ptr commentProc;
   Ptr txMeasProc;
   Ptr getPicProc;
   Ptr putPicProc;
};

struct GrafPort {
   Short      device;
   BitMap     portBits;
   Rect       portRect;
   RgnHandle  visRgn;
   RgnHandle  clipRgn;
   Pattern    bkPat;
   Pattern    fillPat;
   Point      pnLoc;
   Point      pnSize;
   Short      pnMode;
   Pattern    pnPat;
   Short      pnVis;
   Short      txFont;
   Style      txFace;/* txFace is unpacked byte, but push as Short */
   char       filler;
   Short      txMode;
   Short      txSize;
   Fixed      spExtra;
   Long       fgColor;
   Long       bkColor;
   Short      colrBit;
   Short      patStretch;
   PicHandle  picSave;
   RgnHandle  rgnSave;
   PolyHandle polySave;
   QDProcsPtr grafProcs;
};

struct Picture {
   Short picSize;
   Rect  picFrame;
   /* picData is here */
};

struct Polygon {
   Short polySize;
   Rect  polyBBox;
   /* Points are here */
};

struct PenState {
   Point   pnLoc;
   Point   pnSize;
   Short   pnMode;
   Pattern pnPat;
};

struct FontInfo {
   Short ascent;
   Short descent;
   Short widMax;
   Short leading;
};

struct qd {
   char    reserved[76];
   Long    randSeed;
   BitMap  screenBits;
   Cursor  arrow;
   Pattern dkGray;
   Pattern ltGray;
   Pattern gray;
   Pattern black;
   Pattern white;
   GrafPtr thePort;
};

extern struct qd *qd;

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA87E) _PROTOTYPE( void AddPt, (Point srcPt, Point *dstPt) );
ROMTRAP(0xA863) _PROTOTYPE( void BackColor, (Long color) );
ROMTRAP(0xA87C) _PROTOTYPE( void BackPat, (Pattern *pat) );
ROMTRAP(0xA88D) _PROTOTYPE( Short CharWidth, (Short ch) );
ROMTRAP(0xA87B) _PROTOTYPE( void ClipRect, (Rect *r) );
ROMTRAP(0xA8F4) _PROTOTYPE( void ClosePicture, (void) );
ROMTRAP(0xA8CC) _PROTOTYPE( void ClosePoly, (void) );
ROMTRAP(0xA87D) _PROTOTYPE( void ClosePort, (GrafPtr gp) );
ROMTRAP(0xA8DB) _PROTOTYPE( void CloseRgn, (RgnHandle h) );
ROMTRAP(0xA864) _PROTOTYPE( void ColorBit, (Short whichBit) );
ROMTRAP(0xA8EC) _PROTOTYPE( void CopyBits, (BitMap *srcBits, BitMap *dstBits, Rect *srcRect, Rect *dstRect, Short mode, RgnHandle maskRgn) );
ROMTRAP(0xA8DC) _PROTOTYPE( void CopyRgn, (RgnHandle srcRgn, RgnHandle dstRgn) );
ROMTRAP(0xA8E6) _PROTOTYPE( void DiffRgn, (RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn) );
ROMTRAP(0xA8D9) _PROTOTYPE( void DisposeRgn, (RgnHandle h) );
ROMTRAP(0xA883) _PROTOTYPE( void DrawChar, (Short ch) );
ROMTRAP(0xA8F6) _PROTOTYPE( void DrawPicture, (PicHandle ph, Rect *dstRect) );
ROMTRAP(0xA884) _PROTOTYPE( void DrawString, (inStringPtr) );
ROMTRAP(0xA885) _PROTOTYPE( void DrawText, (Ptr textBuf, Short firstByte, Short byteCount) );
ROMTRAP(0xA8AE) _PROTOTYPE( Boolean EmptyRect, (Rect *r) );
ROMTRAP(0xA8E2) _PROTOTYPE( Boolean EmptyRgn, (RgnHandle) );
ROMTRAP(0xA881) _PROTOTYPE( Boolean EqualPt, (Point pt1, Point pt2) );
ROMTRAP(0xA8A6) _PROTOTYPE( Boolean EqualRect, (Rect *Rect1, Rect *Rect2) );
ROMTRAP(0xA8E3) _PROTOTYPE( Boolean EqualRgn, (RgnHandle rgnA, RgnHandle rgnB) );
ROMTRAP(0xA8C0) _PROTOTYPE( void EraseArc, (Rect *r, Short startAngle, Short arcAngle) );
ROMTRAP(0xA8B9) _PROTOTYPE( void EraseOval, (Rect *r) );
ROMTRAP(0xA8C8) _PROTOTYPE( void ErasePoly, (PolyHandle) );
ROMTRAP(0xA8A3) _PROTOTYPE( void EraseRect, (Rect *r) );
ROMTRAP(0xA8D4) _PROTOTYPE( void EraseRgn, (RgnHandle) );
ROMTRAP(0xA8B2) _PROTOTYPE( void EraseRoundRect, (Rect *r, Short ovalWidth, Short ovalHeight) );
ROMTRAP(0xA8C2) _PROTOTYPE( void FillArc, (Rect *r, Short startAngle, Short arcAngle, Pattern *pat) );
ROMTRAP(0xA8BB) _PROTOTYPE( void FillOval, (Rect *r, Pattern *pat) );
ROMTRAP(0xA8CA) _PROTOTYPE( void FillPoly, (PolyHandle, Pattern *pat) );
ROMTRAP(0xA8A5) _PROTOTYPE( void FillRect, (Rect *r, Pattern *pat) );
ROMTRAP(0xA8D6) _PROTOTYPE( void FillRgn, (RgnHandle, Pattern *pat) );
ROMTRAP(0xA8B4) _PROTOTYPE( void FillRoundRect, (Rect *r, Short ovalWidth, Short ovalHeight, Pattern *pat) );
ROMTRAP(0xA862) _PROTOTYPE( void ForeColor, (Long color) );
ROMTRAP(0xA8BE) _PROTOTYPE( void FrameArc, (Rect *r, Short startAngle, Short arcAngle) );
ROMTRAP(0xA8B7) _PROTOTYPE( void FrameOval, (Rect *r) );
ROMTRAP(0xA8C6) _PROTOTYPE( void FramePoly, (PolyHandle) );
ROMTRAP(0xA8A1) _PROTOTYPE( void FrameRect, (Rect *r) );
ROMTRAP(0xA8D2) _PROTOTYPE( void FrameRgn, (RgnHandle) );
ROMTRAP(0xA8B0) _PROTOTYPE( void FrameRoundRect, (Rect *r, Short ovalWidth, Short ovalHeight) );
ROMTRAP(0xA87A) _PROTOTYPE( void GetClip, (RgnHandle) );
ROMTRAP(0xA88B) _PROTOTYPE( void GetFontInfo, (FontInfo *info) );
ROMTRAP(0xA89A) _PROTOTYPE( void GetPen, (Point *p) );
ROMTRAP(0xA898) _PROTOTYPE( void GetPenState, (PenState *pnState) );
ROMTRAP(0xA865) _PROTOTYPE( Boolean GetPixel, (Short h, Short v) );
ROMTRAP(0xA874) _PROTOTYPE( void GetPort, (GrafPtr *port) );
ROMTRAP(0xA871) _PROTOTYPE( void GlobalToLocal, (Point *p) );
ROMTRAP(0xA872) _PROTOTYPE( void GrafDevice, (Short device) );
ROMTRAP(0xA852) _PROTOTYPE( void HideCursor, (void) );
ROMTRAP(0xA896) _PROTOTYPE( void HidePen, (void) );
ROMTRAP(0xA850) _PROTOTYPE( void InitCursor, (void) );
ROMTRAP(0xA86E) _PROTOTYPE( void InitGraf, (Ptr GlobalPtr) );
ROMTRAP(0xA86D) _PROTOTYPE( void InitPort, (GrafPtr) );
ROMTRAP(0xA8A9) _PROTOTYPE( void InsetRect, (Rect *r, Short dh, Short dv) );
ROMTRAP(0xA8E1) _PROTOTYPE( void InsetRgn, (RgnHandle, Short dh, Short dv) );
ROMTRAP(0xA8C1) _PROTOTYPE( void InvertArc, (Rect *r, Short startAngle, Short arcAngle) );
ROMTRAP(0xA8BA) _PROTOTYPE( void InvertOval, (Rect *r) );
ROMTRAP(0xA8C9) _PROTOTYPE( void InvertPoly, (PolyHandle) );
ROMTRAP(0xA8A4) _PROTOTYPE( void InvertRect, (Rect *r) );
ROMTRAP(0xA8D5) _PROTOTYPE( void InvertRgn, (RgnHandle) );
ROMTRAP(0xA8B3) _PROTOTYPE( void InvertRoundRect, (Rect *r, Short ovalWidth, Short ovalHeight) );
ROMTRAP(0xA8F5) _PROTOTYPE( void KillPicture, (PicHandle) );
ROMTRAP(0xA8CD) _PROTOTYPE( void KillPoly, (PolyHandle) );
ROMTRAP(0xA892) _PROTOTYPE( void Line, (Short dh, Short dv) );
ROMTRAP(0xA891) _PROTOTYPE( void LineTo, (Short h, Short v) );
ROMTRAP(0xA870) _PROTOTYPE( void LocalToGlobal, (Point *p) );
ROMTRAP(0xA8FC) _PROTOTYPE( void MapPoly, (PolyHandle, Rect *srcRect, Rect *dstRect) );
ROMTRAP(0xA8F9) _PROTOTYPE( void MapPt, (Point *p, Rect *srcRect, Rect *dstRect) );
ROMTRAP(0xA8FA) _PROTOTYPE( void MapRect, (Rect *r, Rect *srcRect, Rect *dstRect) );
ROMTRAP(0xA8FB) _PROTOTYPE( void MapRgn, (RgnHandle, Rect *srcRect, Rect *dstRect) );
ROMTRAP(0xA894) _PROTOTYPE( void Move, (Short dh, Short dv) );
ROMTRAP(0xA877) _PROTOTYPE( void MovePortTo, (Short leftGlobal, Short topGlobal) );
ROMTRAP(0xA893) _PROTOTYPE( void MoveTo, (Short h, Short v) );
ROMTRAP(0xA8D8) _PROTOTYPE( RgnHandle NewRgn, (void) );
ROMTRAP(0xA856) _PROTOTYPE( void ObscureCursor, (void) );
ROMTRAP(0xA8CE) _PROTOTYPE( void OffsetPoly, (PolyHandle, Short dh, Short dv) );
ROMTRAP(0xA8A8) _PROTOTYPE( void OffsetRect, (Rect *r, Short dh, Short dv) );
ROMTRAP(0xA8E0) _PROTOTYPE( void OffsetRgn, (RgnHandle, Short dh, Short dv) );
ROMTRAP(0xA8F3) _PROTOTYPE( PicHandle OpenPicture, (Rect *picFrame) );
ROMTRAP(0xA8CB) _PROTOTYPE( PolyHandle OpenPoly, (void) );
ROMTRAP(0xA86F) _PROTOTYPE( void OpenPort, (GrafPtr) );
ROMTRAP(0xA8DA) _PROTOTYPE( void OpenRgn, (void) );
ROMTRAP(0xA8BF) _PROTOTYPE( void PaintArc, (Rect *r, Short startAngle, Short arcAngle) );
ROMTRAP(0xA8B8) _PROTOTYPE( void PaintOval, (Rect *r) );
ROMTRAP(0xA8C7) _PROTOTYPE( void PaintPoly, (PolyHandle) );
ROMTRAP(0xA8A2) _PROTOTYPE( void PaintRect, (Rect *r) );
ROMTRAP(0xA8D3) _PROTOTYPE( void PaintRgn, (RgnHandle) );
ROMTRAP(0xA8B1) _PROTOTYPE( void PaintRoundRect, (Rect *r, Short ovalWidth, Short ovalHeight) );
ROMTRAP(0xA89C) _PROTOTYPE( void PenMode, (Short mode) );
ROMTRAP(0xA89E) _PROTOTYPE( void PenNormal, (void) );
ROMTRAP(0xA89D) _PROTOTYPE( void PenPat, (Pattern *pat) );
ROMTRAP(0xA89B) _PROTOTYPE( void PenSize, (Short width, Short height) );
ROMTRAP(0xA8F2) _PROTOTYPE( void PicComment, (Short kind, Short datasize, Handle dataHandle) );
ROMTRAP(0xA876) _PROTOTYPE( void PortSize, (Short width, Short height) );
ROMTRAP(0xA8AC) _PROTOTYPE( void Pt2Rect, (Point pt1, Point pt2, Rect *dstRect) );
ROMTRAP(0xA8AD) _PROTOTYPE( Boolean PtInRect, (Point, Rect *r) );
ROMTRAP(0xA8E8) _PROTOTYPE( Boolean PtInRgn, (Point, RgnHandle) );
ROMTRAP(0xA8C3) _PROTOTYPE( void PtToAngle, (Rect *r, Point, Short *angle) );
ROMTRAP(0xA861) _PROTOTYPE( Short Random, (void) );
ROMTRAP(0xA8E9) _PROTOTYPE( Boolean RectInRgn, (Rect *r, RgnHandle) );
ROMTRAP(0xA8DF) _PROTOTYPE( void RectRgn, (RgnHandle, Rect *r) );
ROMTRAP(0xA8F8) _PROTOTYPE( void ScalePt, (Point *p, Rect *srcRect, Rect *dstRect) );
ROMTRAP(0xA8EF) _PROTOTYPE( void ScrollRect, (Rect *r, Short dh, Short dv, RgnHandle updateRgn) );
ROMTRAP(0xA8AA) _PROTOTYPE( Boolean SectRect, (Rect *src1, Rect *src2, Rect *dstRect) );
ROMTRAP(0xA8E4) _PROTOTYPE( void SectRgn, (RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn) );
ROMTRAP(0xA879) _PROTOTYPE( void SetClip, (RgnHandle) );
ROMTRAP(0xA851) _PROTOTYPE( void SetCursor, (Cursor *c) );
ROMTRAP(0xA8DD) _PROTOTYPE( void SetEmptyRgn, (RgnHandle) );
ROMTRAP(0xA878) _PROTOTYPE( void SetOrigin, (Short h, Short v) );
ROMTRAP(0xA899) _PROTOTYPE( void SetPenState, (PenState *pnState) );
ROMTRAP(0xA873) _PROTOTYPE( void SetPort, (GrafPtr) );
ROMTRAP(0xA875) _PROTOTYPE( void SetPortBits, (BitMap *bm) );
ROMTRAP(0xA880) _PROTOTYPE( void SetPt, (Point *p, Short h, Short v) );
ROMTRAP(0xA8A7) _PROTOTYPE( void SetRect, (Rect *r, Short left, Short top, Short right, Short bottom) );
ROMTRAP(0xA8DE) _PROTOTYPE( void SetRectRgn, (RgnHandle, Short left, Short top, Short right, Short bottom) );
ROMTRAP(0xA8EA) _PROTOTYPE( void SetStdProcs, (QDProcs *procs) );
ROMTRAP(0xA853) _PROTOTYPE( void ShowCursor, (void) );
ROMTRAP(0xA897) _PROTOTYPE( void ShowPen, (void) );
ROMTRAP(0xA88E) _PROTOTYPE( void SpaceExtra, (Fixed extra) );
ROMTRAP(0xA8BD) _PROTOTYPE( void StdArc, (GrafVerb, Rect *r, Short startAngle, Short arcAngle) );
ROMTRAP(0xA8EB) _PROTOTYPE( void StdBits, (BitMap *srcBits, Rect *srcRect, Rect *dstRect, Short mode, RgnHandle maskRgn) );
ROMTRAP(0xA8F1) _PROTOTYPE( void StdComment, (Short kind, Short dataSize, Handle dataHandle) );
ROMTRAP(0xA8EE) _PROTOTYPE( void StdGetPic, (Ptr dataPtr, Short byteCount) );
ROMTRAP(0xA890) _PROTOTYPE( void StdLine, (Point newPt) );
ROMTRAP(0xA8B6) _PROTOTYPE( void StdOval, (GrafVerb, Rect *r) );
ROMTRAP(0xA8C5) _PROTOTYPE( void StdPoly, (GrafVerb, PolyHandle) );
ROMTRAP(0xA8F0) _PROTOTYPE( void StdPutPic, (Ptr dataPtr, Short byteCount) );
ROMTRAP(0xA8A0) _PROTOTYPE( void StdRect, (GrafVerb, Rect *r) );
ROMTRAP(0xA8D1) _PROTOTYPE( void StdRgn, (GrafVerb, RgnHandle) );
ROMTRAP(0xA8AF) _PROTOTYPE( void StdRRect, (GrafVerb, Rect *r, Short ovalwidth, Short ovalheight) );
ROMTRAP(0xA882) _PROTOTYPE( void StdText, (Short byteCount, Ptr textBuf, Point numer, Point denom) );
ROMTRAP(0xA8ED) _PROTOTYPE( Short StdTxMeas, (Short byteCount, Ptr textAddr, Point *numer, Point *denom, FontInfo *info) );
ROMTRAP(0xA88C) _PROTOTYPE( Short StringWidth, (inStringPtr) );
ROMTRAP(0xA866) _PROTOTYPE( void StuffHex, (Ptr thingPtr, inStringPtr) );
ROMTRAP(0xA87F) _PROTOTYPE( void SubPt, (Point srcPt, Point *dstPT) );
ROMTRAP(0xA888) _PROTOTYPE( void TextFace, (Short face) );
ROMTRAP(0xA887) _PROTOTYPE( void TextFont, (Short font) );
ROMTRAP(0xA889) _PROTOTYPE( void TextMode, (Short mode) );
ROMTRAP(0xA88A) _PROTOTYPE( void TextSize, (Short size) );
ROMTRAP(0xA886) _PROTOTYPE( Short TextWidth, (Ptr textBuf, Short firstByte, Short byteCount) );
ROMTRAP(0xA8AB) _PROTOTYPE( void UnionRect, (Rect *src1, Rect *src2, Rect *dstRect) );
ROMTRAP(0xA8E5) _PROTOTYPE( void UnionRgn, (RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn) );
ROMTRAP(0xA8E7) _PROTOTYPE( void XorRgn, (RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn) );
ROMTRAP(0xA839) _PROTOTYPE( void SeedFill, (Ptr srcPtr, Ptr dstPtr, Short srcRow, Short dstRow, Short height, Short words, Short seedH, Short seedV) );
ROMTRAP(0xA838) _PROTOTYPE( void CalcMask, (Ptr srcPtr, Ptr dstPtr, Short srcRow, Short dstRow, Short height, Short words) );
ROMTRAP(0xA817) _PROTOTYPE( void CopyMask, (BitMap *srcBits, BitMap *maskBits, BitMap *dstBits, Rect *srcRect, Rect *maskRect, Rect *dstRect) );
ROMTRAP(0xA837) _PROTOTYPE( void MeasureText, (Short count, Ptr textAddr, Ptr charLocs) );
#endif
