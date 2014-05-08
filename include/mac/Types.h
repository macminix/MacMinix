#ifndef _MAC_TYPES_H
#define _MAC_TYPES_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

/* utility */
#define FALSE		0
#define TRUE    	1

/* for prototypes */
#ifndef ROMTRAP
#define ROMTRAP(trapno)
#endif
#ifndef ROMPACK
#define ROMPACK(trapno, id)
#endif
#define A0(a)		a
#define A1(a)		a
#define D0(a)		a
#define TO(a,b) 	a
#define ASYNC(a) 	a
#define RESULT(a) 	a

typedef char Boolean;			/* builtin to pascal, not c */
typedef short int Short;		/* JP 4-90 */
typedef unsigned short int UShort;	/* JP 4-90 */
typedef long int Long;			/* JP 4-90 */
typedef unsigned long int ULong;	/* JP 4-90 */
typedef Long (*ProcPtr)();		/* IM I-78 */
typedef char SignedByte;		/* IM I-81 */
typedef char Byte;			/* IM I-81 */
typedef char *Ptr;			/* IM I-81 */
typedef char **Handle;			/* IM I-81 */
typedef char Str255[256];		/* IM I-81 */
typedef char *StringPtr;		/* IM I-81 */
typedef char *inStringPtr;		/* IM I-81 */
typedef char *outStringPtr;		/* IM I-81 */
typedef char **StringHandle;		/* IM I-81 */
typedef Long Fixed;			/* IM I-81 */
#endif
