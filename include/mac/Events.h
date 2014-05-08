#ifndef _MAC_EVENTS_H
#define _MAC_EVENTS_H

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

/* Event numbers */
#define nullEvent 	0
#define mouseDown 	1
#define mouseUp 	2
#define keyDown 	3
#define keyUp 		4
#define autoKey 	5
#define updateEvt 	6
#define diskEvt 	7
#define activateEvt 	8
#define networkEvt 	10
#define driverEvt 	11
#define app1Evt 	12
#define app2Evt 	13
#define app3Evt 	14
#define app4Evt 	15

/* Event masks */
#define charCodeMask 	0x000000FF
#define keyCodeMask 	0x0000FF00
#define mDownMask 	2
#define mUpMask 	4
#define keyDownMask 	8
#define keyUpMask 	16
#define autoKeyMask 	32
#define updateMask 	64
#define diskMask 	128
#define activMask 	256
#define networkMask 	1024
#define driverMask 	2048
#define app1Mask 	4096
#define app2Mask 	8192
#define app3Mask 	16384
#define app4Mask 	-32768
#define everyEvent 	-1

/* Masks for the modifier bits */
#define activeFlag 	1
#define btnState 	128
#define cmdKey 		256
#define shiftKey 	512
#define alphaLock 	1024
#define optionKey 	2048

typedef struct EventRecord EventRecord;
typedef Long KeyMap[4];

/* The Event record */
struct EventRecord {
	Short what;
	Long message;
	Long when;
	Point where;
	Short modifiers;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA974) _PROTOTYPE( Boolean Button, (void) );
ROMTRAP(0xA971) _PROTOTYPE( Boolean EventAvail, (Short evtMask, EventRecord *Evt) );
_PROTOTYPE( Long GetCaretTime, (void) );
_PROTOTYPE( Long GetDblTime, (void) );
ROMTRAP(0xA976) _PROTOTYPE( void GetKeys, (KeyMap *theKeys) );
ROMTRAP(0xA972) _PROTOTYPE( void GetMouse, (Point *mouseLoc) );
ROMTRAP(0xA970) _PROTOTYPE( Boolean GetNextEvent, (Short evtMask, EventRecord *Evt) );
ROMTRAP(0xA973) _PROTOTYPE( Boolean StillDown, (void) );
ROMTRAP(0xA875) _PROTOTYPE( Long TickCount, (void) );
ROMTRAP(0xA977) _PROTOTYPE( Boolean WaitMouseUp, (void) );
#endif
