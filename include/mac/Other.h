#ifndef _MAC_OTHER_H
#define _MAC_OTHER_H

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

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

/*
 * These are routines which, for one reason or another, could not be
 * called directly.  They are called by lib routines.
 */

ROMTRAP(0xA032) _PROTOTYPE( void _FlushEvents_, (D0(Long mask)) );
ROMTRAP(0xA03C) TO( _PROTOTYPE( Boolean _CmpString_, (A0(char *aStr), A1(char *bStr), D0(Long lengths)) ), d0);
ROMTRAP(0xA13C) TO( _PROTOTYPE( Boolean _CmpString_M_, (A0(char *aStr), A1(char *bStr), D0(Long lengths)) ), d0);
ROMTRAP(0xA23C) TO( _PROTOTYPE( Boolean _CmpString_C_, (A0(char *aStr), A1(char *bStr), D0(Long lengths)) ), d0);
ROMTRAP(0xA33C) TO( _PROTOTYPE( Boolean _CmpString_CM_, (A0(char *aStr), A1(char *bStr), D0(Long lengths)) ), d0);
ROMTRAP(0xA9E1) TO( _PROTOTYPE( OSErr _HandToHand_, (A0(Handle hin),RESULT(Handle *hout) )), a0->result);
ROMTRAP(0xA054) TO( _PROTOTYPE( Boolean _UprString_, (A0(char *Str), D0(Short len)) ), d0);
ROMTRAP(0xA154) TO( _PROTOTYPE( Boolean _UprString_M_, (A0(char *Str), D0(Short len)) ), d0);
ROMTRAP(0xA038) TO(_PROTOTYPE( OSErr _WriteParam_, (A0(Ptr sp),D0(Long minusone)) ), d0);
#endif
