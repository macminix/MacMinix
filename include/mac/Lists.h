#ifndef _MAC_LIST_H
#define _MAC_LIST_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_CONTROLS_H
#include <mac/Controls.h>
#endif

#define lDoHAutoscroll 	1
#define lDoVAutoscroll 	2

#define lOnlyOne 	-128
#define lExtendDrag 	0x40
#define lNoDisjoint 	0x20
#define lNoExtend 	0x10
#define lNoRect 	0x08
#define lUseSense 	0x04
#define lNoNilHilite 	0x02

#define lInitMsg 	0
#define lDrawMsg 	1
#define lHiliteMsg 	2
#define lCloseMsg 	3

typedef Point            Cell;
typedef struct ListRec   ListRec;
typedef struct ListRec  *ListPtr;
typedef struct ListRec **ListHandle;

struct ListRec {
    Rect 		rView;
    struct GrafPort    *port;
    Point 		indent;
    Point 		cellSize;
    Rect 		visible;
    ControlHandle	vScroll;
    ControlHandle	hScroll;
    char 		selFlags;
    char 		lActive;
    char 		lReserved;
    char 		listFlags;
    Long 		clikTime;
    Point 		clikLoc;
    Point 		mouseLoc;
    ProcPtr 		lClikLoop;
    Cell 		lastClick;
    Long 		refCon;
    Handle 		listDefProc;
    Handle		userHandle;
    Rect		dataBounds;
    Handle		cells;
    Short		maxIndex;
    /* cell array is here */
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMPACK(0xA9E7,68) _PROTOTYPE( ListHandle LNew, (Rect *rView, Rect *dataBounds, Point cSize, Short theProc, WindowPtr theWindow, Boolean drawIt, Boolean hasGrow, Boolean scrollHoriz, Boolean scrollVert) );
ROMPACK(0xA9E7,40) _PROTOTYPE( void LDispose, (ListHandle) );
ROMPACK(0xA9E7,4) _PROTOTYPE( Short LAddColumn, (Short count, Short colNum, ListHandle) );
ROMPACK(0xA9E7,8) _PROTOTYPE( Short LAddRow, (Short count, Short rowNum, ListHandle) );
ROMPACK(0xA9E7,32) _PROTOTYPE( void LDelColumn, (Short count, Short colNum, ListHandle) );
ROMPACK(0xA9E7,36) _PROTOTYPE( void LDelRow, (Short count, Short rowNum, ListHandle) );
ROMPACK(0xA9E7,12) _PROTOTYPE( void LAddToCell, (Ptr data, Short dataLen, Cell, ListHandle) );
ROMPACK(0xA9E7,28) _PROTOTYPE( void LClrCell, (Cell, ListHandle) );
ROMPACK(0xA9E7,56) _PROTOTYPE( void LGetCell, (Ptr data, Short *dataLen, Cell, ListHandle) );
ROMPACK(0xA9E7,88) _PROTOTYPE( void LSetCell, (Ptr data, Short dataLen, Cell, ListHandle) );
ROMPACK(0xA9E7,20) _PROTOTYPE( void LCellSize, (Point, ListHandle) );
ROMPACK(0xA9E7,56) _PROTOTYPE( Boolean LGetSelect, (Boolean next, Cell *cell, ListHandle) );
ROMPACK(0xA9E7,92) _PROTOTYPE( void LSetSelect, (Boolean setIt, Cell, ListHandle) );
ROMPACK(0xA9E7,24) _PROTOTYPE( Boolean LClick, (Point, Short modifiers, ListHandle) );
ROMPACK(0xA9E7,64) _PROTOTYPE( long LLastClick, (ListHandle) ); /* really returns a Cell */
ROMPACK(0xA9E7,52) _PROTOTYPE( void LFind, (Short *offset, Short *len, Cell, ListHandle) );
ROMPACK(0xA9E7,72) _PROTOTYPE( Boolean LNextCell, (Boolean hNext, Boolean vNext, Cell *cell, ListHandle) );
ROMPACK(0xA9E7,76) _PROTOTYPE( void LRect, (Rect *r, Cell, ListHandle) );
ROMPACK(0xA9E7,84) _PROTOTYPE( Boolean LSearch, (Ptr dataPtr, Short dataLen, ProcPtr searchProc, Cell *cell, ListHandle) );
ROMPACK(0xA9E7,96) _PROTOTYPE( void LSize, (Short listWidth, Short listHeight, ListHandle) );
ROMPACK(0xA9E7,48) _PROTOTYPE( void LDraw, (Cell, ListHandle) );
ROMPACK(0xA9E7,44) _PROTOTYPE( void LDoDraw, (Boolean drawIt, ListHandle) );
ROMPACK(0xA9E7,80) _PROTOTYPE( void LScroll, (Short dCols, Short dRows, ListHandle) );
ROMPACK(0xA9E7,16) _PROTOTYPE( void LAutoScroll, (ListHandle) );
ROMPACK(0xA9E7,100) _PROTOTYPE( void LUpdate, (RgnHandle, ListHandle) );
ROMPACK(0xA9E7,0) _PROTOTYPE( void LActivate, (Boolean, ListHandle) );
#endif
