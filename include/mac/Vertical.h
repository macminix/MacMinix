#ifndef _MAC_VERTICAL_H
#define _MAC_VERTICAL_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_OSUTILS_H
#include <mac/OSUtils.h>
#endif

typedef struct VBLTask VBLTask;

struct VBLTask {
   struct QElem *qLink;
   Short qType;
   ProcPtr vblAddr;
   Short vblCount;
   Short vblPhase;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( QHdrPtr GetVBLQHdr, (void) );
ROMTRAP(0xA033) TO( _PROTOTYPE( OSErr VInstall, (A0(QElemPtr vblTaskPtr)) ), d0);
ROMTRAP(0xA034) TO( _PROTOTYPE( OSErr VRemove, (A0(QElemPtr vblTaskPtr)) ), d0);
#endif
