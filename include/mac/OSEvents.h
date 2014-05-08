#ifndef _MAC_OSEVENTS_H
#define _MAC_OSEVENTS_H

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

#ifndef _MAC_EVENTS_H
#include <mac/Events.h>
#endif

typedef struct EvQEl EvQEl;

struct EvQEl {
   struct QElem *qLink;
   Short qType;
   Short evtQWhat;
   Long  evtQMessage;
   Long  evtQWhen;
   Point evtQWhere;
   Short evtQModifiers;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void FlushEvents, (Short EvtMask, Short Mask) );
_PROTOTYPE( QHdrPtr GetEvQHdr, (void) );
ROMTRAP(0xA031) TO( _PROTOTYPE( Boolean GetOSEvent, (D0(Short evtMask), A0(EventRecord *Evt)) ), d0);
ROMTRAP(0xA030) TO( _PROTOTYPE( Boolean OSEventAvail, (D0(Short evtMask), A0(EventRecord *Evt)) ), d0);
ROMTRAP(0xA02F) TO( _PROTOTYPE( OSErr PostEvent, (A0(Short evtCode), D0(Long evtMsg)) ), d0);
ROMTRAP(0xA12F) TO( _PROTOTYPE( OSErr PPostEvent, (A0(Short evtCode), D0(Long evtMsg), RESULT(EvQEl **qEl)) ), a0->result);
_PROTOTYPE( void SetEventMask, (Short theMask) );
#endif
