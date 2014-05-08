#ifndef _MAC_DESK_H
#define _MAC_DESK_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_EVENTS_H
#include <mac/Events.h>
#endif

#ifndef _MAC_WINDOWS_H
#include <mac/Windows.h>
#endif

#define accEvent 		64
#define accRun 			65
#define accCursor 		66
#define accMenu 		67
#define accUndo 		68
#define accCut 			70
#define accCopy 		71
#define accPaste 		72
#define accClear 		73

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9B7) _PROTOTYPE( void CloseDeskAcc, (Short ref) );
ROMTRAP(0xA9B6) _PROTOTYPE( Short OpenDeskAcc, (inStringPtr Acc) );
ROMTRAP(0xA9B3) _PROTOTYPE( void SystemClick, (EventRecord *e, WindowPtr wp) );
ROMTRAP(0xA9C2) _PROTOTYPE( Boolean SystemEdit, (Short cmd) );
ROMTRAP(0xA9B2) _PROTOTYPE( Boolean SystemEvent, (EventRecord *e) );
ROMTRAP(0xA9B5) _PROTOTYPE( void SystemMenu, (Long result) );
ROMTRAP(0xA9B4) _PROTOTYPE( void SystemTask, (void) );
#endif
