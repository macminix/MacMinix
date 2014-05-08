#ifndef _MAC_TEXT_H
#define _MAC_TEXT_H

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

#ifndef _MAC_OSUTILS_H
#include <mac/OSUtils.h>
#endif

/* text justification */
#define teJustLeft 	0
#define teJustCenter 	1
#define teJustRight 	-1

/* typedefs */
typedef char           Chars[32001];
typedef Chars         *CharsPtr;
typedef Chars        **CharsHandle;
typedef struct TERec   TERec;
typedef struct TERec  *TEPtr;
typedef struct TERec **TEHandle;

/* structure defs */
struct TERec {
    Rect destRect;
    Rect viewRect;
    Rect selRect;
    Short lineHeight;
    Short fontAscent;
    Point selPoint;
    Short selStart;
    Short selEnd;
    Short active;
    ProcPtr wordBreak;
    ProcPtr clikLoop;
    Long clickTime;
    Short clickLoc;
    Long caretTime;
    Short caretState;
    Short just;
    Short teLength;
    Handle hText;
    Short recalBack;
    Short recalLines;
    Short clikStuff;
    Short crOnly;
    Short txFont;
    Style txFace;           /* txFace is unpacked byte */
    char filler;
    Short txMode;
    Short txSize;
    struct GrafPort *inPort;
    ProcPtr highHook;
    ProcPtr caretHook;
    Short nLines;
    Short lineStarts[16001];
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void SetClikLoop, (ProcPtr clikProc, TEHandle) );
_PROTOTYPE( void SetWordBreak, (ProcPtr wBrkProc, TEHandle) );
ROMTRAP(0xA9D8) _PROTOTYPE( void TEActivate, (TEHandle) );
ROMTRAP(0xA813) _PROTOTYPE( void TEAutoView, (Boolean, TEHandle) );
ROMTRAP(0xA9D0) _PROTOTYPE( void TECalText, (TEHandle) );
ROMTRAP(0xA9D4) _PROTOTYPE( void TEClick, (Point, Boolean xtendsel, TEHandle) );
ROMTRAP(0xA9D5) _PROTOTYPE( void TECopy, (TEHandle) );
ROMTRAP(0xA9D6) _PROTOTYPE( void TECut, (TEHandle) );
ROMTRAP(0xA9D9) _PROTOTYPE( void TEDeactivate, (TEHandle) );
ROMTRAP(0xA9D7) _PROTOTYPE( void TEDelete, (TEHandle) );
ROMTRAP(0xA9CD) _PROTOTYPE( void TEDispose, (TEHandle) );
_PROTOTYPE( OSErr TEFromScrap, (void) );
_PROTOTYPE( Long TEGetScrapLen, (void) );
ROMTRAP(0xA9CB) _PROTOTYPE( CharsHandle TEGetText, (TEHandle) );
ROMTRAP(0xA9DA) _PROTOTYPE( void TEIdle, (TEHandle) );
ROMTRAP(0xA9CC) _PROTOTYPE( void TEInit, (void) );
ROMTRAP(0xA9DE) _PROTOTYPE( void TEInsert, (Ptr text, Long length, TEHandle) );
ROMTRAP(0xA9DC) _PROTOTYPE( void TEKey, (Short ch, TEHandle) );
ROMTRAP(0xA9D2) _PROTOTYPE( TEHandle TENew, (Rect *dstRect, Rect *viewRect) );
ROMTRAP(0xA9DB) _PROTOTYPE( void TEPaste, (TEHandle) );
ROMTRAP(0xA812) _PROTOTYPE( void TEPinScroll, (Short dh, Short dv, TEHandle) );
_PROTOTYPE( Handle TEScrapHandle, (void) );
ROMTRAP(0xA9DD) _PROTOTYPE( void TEScroll, (Short dh, Short dv, TEHandle) );
ROMTRAP(0xA811) _PROTOTYPE( void TESelView, (TEHandle) );
ROMTRAP(0xA9DF) _PROTOTYPE( void TESetJust, (Short just, TEHandle) );
_PROTOTYPE( void TESetScrapLen, (Long length) );
ROMTRAP(0xA9D1) _PROTOTYPE( void TESetSelect, (Long selStart, Long selEnd, TEHandle) );
ROMTRAP(0xA9CF) _PROTOTYPE( void TESetText, (Ptr text, Long length, TEHandle) );
_PROTOTYPE( OSErr TEToScrap, (void) );
ROMTRAP(0xA9D3) _PROTOTYPE( void TEUpdate, (Rect *rUpdate, TEHandle) );
ROMTRAP(0xA9CE) _PROTOTYPE( void TextBox, (Ptr text, Long length, Rect *box, Short just) );
#endif
