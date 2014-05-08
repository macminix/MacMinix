#ifndef _MAC_DISKINIT_H
#define _MAC_DISKINIT_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_EVENTS_H
#include <mac/Events.h>
#endif

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMPACK(0xA9E9, 0) _PROTOTYPE( Short DIBadMount, (Point where, Long evtMessage) );
ROMPACK(0xA9E9, 6) _PROTOTYPE( OSErr DIFormat, (Short drvNum) );
ROMPACK(0xA9E9, 2) _PROTOTYPE( void DILoad, (void) );
ROMPACK(0xA9E9, 4) _PROTOTYPE( void DIUnload, (void) );
ROMPACK(0xA9E9, 8) _PROTOTYPE( OSErr DIVerify, (Short drvNum) );
ROMPACK(0xA9E9,10) _PROTOTYPE( OSErr DIZero, (Short drvNum, inStringPtr volName) );
#endif
