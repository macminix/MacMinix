#ifndef _MAC_DEVICES_H
#define _MAC_DEVICES_H

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

#ifndef _MAC_WINDOWS_H
#include <mac/Windows.h>
#endif

/* Chooser messages */
#define newSelMsg	12
#define fillListMsg	13
#define getSelMsg	14
#define selectMsg	15
#define deselectMsg	16
#define terminateMsg	17
#define buttonMsg	19

/* caller values */
#define chooserID	1

typedef struct DCtlEntry DCtlEntry;
typedef struct DCtlEntry *DCtlPtr;
typedef struct DCtlEntry **DCtlHandle;
typedef struct CntrlParam CntrlParam;

struct DCtlEntry {
   Ptr dCtlDriver;
   Short dCtlFlags;
   QHdr dCtlQHdr;
   Long dCtlPosition;
   Handle dCtlStorage;
   Short dCtlRefNum;
   Long dCtlCurTicks;
   WindowPtr dCtlWindow;
   Short dCtlDelay;
   Short dCtlEMask;
   Short dCtlMenu;
};

struct CntrlParam {
   Short ioCRefNum;
   Short csCode;
   Short csParam[10];
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( DCtlHandle GetDCtlEntry, (Short refNum) );
_PROTOTYPE( OSErr OpenDriver, (StringPtr name, Short *refNum) );
_PROTOTYPE( OSErr KillIO, (Short refNum) );
_PROTOTYPE( OSErr Status, (Short refNum, Short csCode, Ptr csParamPtr) );
_PROTOTYPE( OSErr CloseDriver, (Short refNum) );
_PROTOTYPE( OSErr Control, (Short refNum, Short csCode, Ptr csParamPtr) );
#endif
