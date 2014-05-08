#ifndef _MAC_SEGMENTS_H
#define _MAC_SEGMENTS_H

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

#define appOpen 	0
#define appPrint 	1

typedef struct AppFile AppFile;

struct AppFile {
   Short	vRefNum;
   OSType	fType;
   Short	versNum;
   Str255	fName;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void ClrAppFiles, (Short index) );
_PROTOTYPE( void CountAppFiles, (Short *message, Short *count) );
ROMTRAP(0xA9F4) _PROTOTYPE( void ExitToShell, (void) );
_PROTOTYPE( void GetAppFiles, (Short index, AppFile *theFile) );
ROMTRAP(0xA9F5) _PROTOTYPE( void GetAppParms, (outStringPtr apName, Short *apRefNum, Handle *apParam) );
ROMTRAP(0xA9F1) _PROTOTYPE( void UnloadSeg, (ProcPtr routineAddr) );
#endif
