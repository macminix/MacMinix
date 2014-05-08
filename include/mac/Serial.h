#ifndef _MAC_SERIAL_H
#define _MAC_SERIAL_H

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

/* baud rates */
#define baud300		380
#define baud600		189
#define baud1200	94
#define baud1800	62
#define baud2400	46
#define baud3600	30
#define baud4800	22
#define baud7200	14
#define baud9600	10
#define baud19200	4
#define baud57600	0

/* stop bits */
#define stop10		16384
#define stop15		-32768
#define stop20		-16384

/* parity */
#define noParity	0
#define oddParity	4096
#define evenParity	12288

/* data bits */
#define data5		0
#define data6		2048
#define data7		1024
#define data8		3072

/* error masks */
#define swOverrunErr	1
#define parityErr	16
#define hwOverrunErr	32
#define framingErr	64

/* change masks */
#define ctsEvent	32
#define breakEvent	128

/* xoff was sent (as if you didn't know) */
#define xOffWasSent	0x80

/* dtr is negated */
#define dtrNegated	0x40

typedef struct SerShk SerShk;
typedef struct SerStaRec SerStaRec;
typedef enum { sPortA, sPortB } SPortSel;

struct SerShk {
   unsigned char fXOn;
   unsigned char fCTS;
   char		 xOn;
   char		 xOff;
   unsigned char errs;
   unsigned char evts;
   unsigned char fInX;
   unsigned char fDTR;
};

struct SetStaRec {
   unsigned char cumErrs;
   unsigned char xOffSent;
   unsigned char rdPend;
   unsigned char wrPend;
   unsigned char ctsHold;
   unsigned char xOffHold;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void RAMSDClose, (SPortSel whichPort) );
_PROTOTYPE( OSErr RAMSDOpen, (SPortSel whichPort) );
_PROTOTYPE( OSErr SerClrBrk, (Short refNum) );
_PROTOTYPE( OSErr SerGetBuf, (Short refNum, Long *count) );
_PROTOTYPE( OSErr SerHShake, (Short refNum, SerShk *flags) );
_PROTOTYPE( OSErr SerReset, (Short refNum, Short serConfig) );
_PROTOTYPE( OSErr SerSetBrk, (Short refNum) );
_PROTOTYPE( OSErr SerSetBuf, (Short refNum, Ptr serBPtr, Short serBLen) );
_PROTOTYPE( OSErr SerStatus, (Short refNum, SerStaRec *serSta) );
#endif
