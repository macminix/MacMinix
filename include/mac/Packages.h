#ifndef _MAC_PACKAGES_H
#define _MAC_PACKAGES_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* Control def IDS */
#define listMgr 	0
#define dskInit 	2
#define stdFile 	3
#define flPoint 	4
#define trFunc 		5
#define intUtil 	6
#define bdConv 		7

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9E6) _PROTOTYPE( void InitAllPacks, (void) );
ROMTRAP(0xA9E5) _PROTOTYPE( void InitPack, (Short packID) );
#endif
