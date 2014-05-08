#ifndef _MAC_TIME_H
#define _MAC_TIME_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_OSUTILS_H
#include<mac/OSUtils.h>
#endif

typedef struct TMTask TMTask;

struct TMTask {
   QElemPtr qLink;
   Short    qType;
   ProcPtr  tmAddr;
   Short    tmCount;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA058) TO( _PROTOTYPE( OSErr InsTime, (A0(QElemPtr)) ), d0);
ROMTRAP(0xA05A) TO( _PROTOTYPE( OSErr PrimeTime, (A0(QElemPtr), D0(Long count)) ), d0);
ROMTRAP(0xA059) TO( _PROTOTYPE( OSErr RmvTime, (A0(QElemPtr)) ), d0);
#endif
