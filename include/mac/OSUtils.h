#ifndef _MAC_OSUTILS_H
#define _MAC_OSUTILS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* Values returned by Environs */
#define macXLMachine 	0
#define macMachine 	1

/* traptype from volume iv */
typedef ULong OSType;
typedef Short OSErr;
typedef struct SysParmType  SysParmType;
typedef struct SysParmType *SysPPtr;
typedef struct QElem  QElem;
typedef struct QElem *QElemPtr;
typedef struct QHdr   QHdr;
typedef struct QHdr  *QHdrPtr;
typedef struct DateTimeRec DateTimeRec;
typedef enum { OSTrap, ToolTrap } TrapType;

struct SysParmType {
   unsigned char  valid;
   unsigned char  aTalkA;
   unsigned char  aTalkB;
   unsigned char  config;
   Short portA;
   Short portB;
   Long  alarm;
   Short font;
   Short kbdPrint;
   Short volClik;
   Short misc;
};

struct QHdr {
   Short    qFlags;
   QElemPtr qHead;
   QElemPtr qTail;
};

struct QElem {
   struct QElem *qLink;
   Short         qType;
};

struct DateTimeRec {
   Short year;
   Short month;
   Short day;
   Short hour;
   Short minute;
   Short second;
   Short dayOfWeek;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9C7) TO( _PROTOTYPE( void Date2Secs, (A0(DateTimeRec *date), RESULT(Long *secs)) ), d0->result);
ROMTRAP(0xA03B) TO( _PROTOTYPE( void Delay, (A0(Long numTicks), RESULT(Long *finalTicks)) ), d0->result);
ROMTRAP(0xA96E) TO( _PROTOTYPE( OSErr DeQueue, (A0(QElemPtr qEntry), A1(QHdrPtr theQueue)) ), d0);
ROMTRAP(0xA96F) TO( _PROTOTYPE( void Enqueue, (A0(QElemPtr qEntry), A1(QHdrPtr theQueue)) ), d0);
_PROTOTYPE( void Environs, (Short *rom, Short *machine) );
_PROTOTYPE( Boolean EqualString, (inStringPtr aStr, inStringPtr bStr, Boolean caseSens, Boolean diacSens) );
_PROTOTYPE( void GetDateTime, (Long *secs) );
_PROTOTYPE( SysPPtr GetSysPPtr, (void) );
_PROTOTYPE( void GetTime, (DateTimeRec *date) );
ROMTRAP(0xA146) TO( _PROTOTYPE( Long GetTrapAddress, (D0(Short trapNum)) ), a0->d0);
ROMTRAP(0xA9E4) TO( _PROTOTYPE( OSErr HandAndHand, (A0(Handle aHandle), A1(Handle bHandle)) ), d0);
_PROTOTYPE( OSErr HandToHand, (Handle *h) );
ROMTRAP(0xA03F) TO( _PROTOTYPE( OSErr InitUtil, (void) ), d0);
_PROTOTYPE( Long NGetTrapAddress, (Short trapNum, TrapType trapt) );
_PROTOTYPE( void NSetTrapAddress, (Long trapAddr, Short trapNum, TrapType trapt) );
ROMTRAP(0xA9EF) TO( _PROTOTYPE( OSErr PtrAndHand, (A0(void *ptr), A1(Handle h), D0(Long size)) ), d0);
ROMTRAP(0xA9E3) TO( _PROTOTYPE( OSErr PtrToHand, (A0(void *srcPtr), RESULT(Handle *dstHandle), D0(Long size)) ), a0->result);
ROMTRAP(0xA9E2) TO( _PROTOTYPE( OSErr PtrToXHand, (A0(void *srcPtr), A1(Handle dstHandle), D0(Long size)) ), d0);
ROMTRAP(0xA039) TO( _PROTOTYPE( OSErr ReadDateTime, (A0(Long *secs)) ), d0);
_PROTOTYPE( void Restart, (void) );
ROMTRAP(0xA9C6) TO( _PROTOTYPE( void Secs2Date, (D0(Long secs), RESULT(DateTimeRec *date)) ), a0->result);
ROMTRAP(0xA03A) TO( _PROTOTYPE( OSErr SetDateTime, (Long D0(secs)) ), d0);
_PROTOTYPE( void SetTime, (DateTimeRec *date) );
ROMTRAP(0xA047) TO( _PROTOTYPE( void SetTrapAddress, (A0(Long trapAddr), D0(Short trapNum)) ), d0);
ROMTRAP(0xA9C8) _PROTOTYPE( void SysBeep, (Short duration) );
_PROTOTYPE( void UprString, (inStringPtr, Boolean diacSens) );
_PROTOTYPE( OSErr WriteParam, (void) );
#endif
