#ifndef _MAC_SCSI_H
#define _MAC_SCSI_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_OSUTILS_H
#include <mac/OSUtils.h>
#endif

#define scInc	1
#define scNoInc	2
#define scAdd	3
#define scMove	4
#define scLoop	5
#define scNop	6
#define scStop	7
#define scComp	8

#define scBadParmsErr	4
#define scCommErr	2
#define scCompareErr	6
#define scPhaseErr	5

typedef struct SCSIInstr SCSIInstr;

struct SCSIInstr {
   Short scOpcode;
   Long  scParam1;
   Long  scParam2;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMPACK(0xA815, 3) _PROTOTYPE( OSErr SCSICmd, (Ptr buffer, Short count) );
ROMPACK(0xA815, 4) _PROTOTYPE( OSErr SCSIComplete, (Short *stat, Short *message, Long wait) );
ROMPACK(0xA815, 1) _PROTOTYPE( OSErr SCSIGet, (void) );
ROMPACK(0xA815, 8) _PROTOTYPE( OSErr SCSIRBlind, (Ptr tibPtr) );
ROMPACK(0xA815, 5) _PROTOTYPE( OSErr SCSIRead, (Ptr tibPtr) );
ROMPACK(0xA815, 0) _PROTOTYPE( OSErr SCSIReset, (void) );
ROMPACK(0xA815, 2) _PROTOTYPE( OSErr SCSISelect, (Short targetID) );
ROMPACK(0xA815,10) _PROTOTYPE( Short SCSIStat, (void) );
ROMPACK(0xA815, 9) _PROTOTYPE( OSErr SCSIWBlind, (Ptr tibPtr) );
ROMPACK(0xA815, 6) _PROTOTYPE( OSErr SCSIWrite, (Ptr tibPtr) );
#endif
