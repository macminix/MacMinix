#ifndef _MAC_BCD_H
#define _MAC_BCD_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMPACK(0xA9EE,0) _PROTOTYPE( void NumToString, (D0(Long),A0(outStringPtr s)) );
ROMPACK(0xA9EE,1) TO( _PROTOTYPE( void StringToNum, (A0(inStringPtr), RESULT(Long *thenum))), d0->result);
#endif
