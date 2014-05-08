#ifndef _MAC_SCRAP_H
#define _MAC_SCRAP_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_RESOURCES_H
#include <mac/Resources.h>
#endif

typedef struct ScrapStuff  ScrapStuff;
typedef struct ScrapStuff *PScrapStuff;

struct ScrapStuff {
   Long      scrapSize;
   Handle    scrapHandle;
   Short     scrapCount;
   Short     scrapState;
   StringPtr scrapName;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9FD) _PROTOTYPE( Long GetScrap, (Handle hDest, inResType, Long *offset) );
ROMTRAP(0xA9F9) _PROTOTYPE( PScrapStuff InfoScrap, (void) );
ROMTRAP(0xA9FB) _PROTOTYPE( Long LoadScrap, (void) );
ROMTRAP(0xA9FE) _PROTOTYPE( Long PutScrap, (Long length, inResType, Ptr source) );
ROMTRAP(0xA9FA) _PROTOTYPE( Long UnloadScrap, (void) );
ROMTRAP(0xA9FC) _PROTOTYPE( Long ZeroScrap, (void) );
#endif
