#ifndef _MAC_DISK_H
#define _MAC_DISK_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_OSUTILS_H
#include <mac/OSUtils.h>
#endif

typedef struct DrvSts DrvSts;

struct DrvSts {
   Short track;
   char  writeProt;
   char  diskInPlace;
   char  installed;
   char  sides;
   QElemPtr qLink;
   Short qType;
   Short dQDrive;
   Short dQRefNum;
   Short dQFSID;
   char  twoSideFmt;
   char  needsFlush;
   Short diskErrs;
};

_PROTOTYPE( OSErr DiskEject, (Short drvNum) );
_PROTOTYPE( OSErr SetTagBuffer, (Ptr buffPtr) );
_PROTOTYPE( OSErr DriveStatus, (Short drvNum, DrvSts *stat) );
#endif
