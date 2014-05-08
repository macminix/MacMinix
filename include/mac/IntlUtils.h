#ifndef _MAC_INTERNATIONAL_H
#define _MAC_INTERNATIONAL_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* masks for currency format */
#define currSymLead 	16
#define currNegSym 	32
#define currTrailingZ	64
#define currLeadingZ	128

/* order of Short date elements */
#define mdy		0
#define dmy		1
#define ymd		2

/* masks for Short dates */
#define dayLdingZ	32
#define mntLdingZ	64
#define century         128

/* masks for times */
#define secLeadingZ     32
#define minLeadingZ	64
#define hrLeadingZ	128

/* version information */
#define verUS 		0
#define verFrance	1
#define verBritain	2
#define verGermany	3
#define verItaly	4
#define verNetherlands	5
#define verBelgiumLux	6
#define verSweden	7
#define verSpain	8
#define verDenmark	9
#define verPortugal	10
#define verFrCanada	11
#define verNorway	12
#define verIsrael	13
#define verJapan	14
#define verAustralia	15
#define verArabia	16
#define verFinland	17
#define verFrSwiss	18
#define verGrSwiss	19
#define verGreece	20
#define verIceland	21
#define verMalta	22
#define verCyprus	23
#define verTurkey 	24
#define verYugoslavia	25

typedef struct Intl0Rec   Intl0Rec;
typedef struct Intl0Rec  *Intl0Ptr;
typedef struct Intl0Rec **Intl0Hndl;
typedef struct Intl1Rec   Intl1Rec;
typedef struct Intl1Rec  *Intl1Ptr;
typedef struct Intl1Rec **Intl1Hndl;
typedef enum { ShortDate, longDate, abbrevDate } DateForm;

struct Intl0Rec {
   char		 decimalPt;
   char 	 housSep;
   char	  	 listSep;
   char	  	 currSym1;
   char	  	 currSym2;
   char	  	 currSym3;
   unsigned char currFmt;
   unsigned char dateOrder;
   unsigned char shrtDateFmt;
   char	  	 dateSep;
   unsigned char timeCycle;
   unsigned char timeFmt;
   char		 mornStr[4];
   char		 eveStr[4];
   char	  	 timeSep;
   char	  	 time1Suff;
   char	  	 time2Suff;
   char	  	 time3Suff;
   char	  	 time4Suff;
   char	  	 time5Suff;
   char	  	 time6Suff;
   char	  	 time7Suff;
   char	  	 time8Suff;
   unsigned char metricSys;
   Short	 intl0Vers;
};

struct Intl1Rec {
   char    	 days[7][16];
   char    	 months[12][16];
   unsigned char suppressDay;
   unsigned char lngDateFmt;
   unsigned char dayLeading0;
   unsigned char abbrLen;
   char          st0[4];
   char          st1[4];
   char          st2[4];
   char          st3[4];
   char          st4[4];
   Short         intl1Vers;
   Short	 localRtn;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( Short IUCompString, (inStringPtr aStr, inStringPtr bStr) );
ROMPACK(0xA9ED,0) _PROTOTYPE( void IUDateString, (Long dateTime, DateForm form, outStringPtr result) );
ROMPACK(0xA9ED,14) _PROTOTYPE( void IUDatePString, (Long dateTime, DateForm form, outStringPtr result, Handle intlParam) );
_PROTOTYPE( Short IUEqualString, (inStringPtr aStr, inStringPtr bStr) );
ROMPACK(0xA9ED,6) _PROTOTYPE( Handle IUGetIntl, (Short theID) );
ROMPACK(0xA9ED,10) _PROTOTYPE( Short IUMagString, (Ptr aPtr, Ptr bPtr, Short aLen, Short bLen) );
ROMPACK(0xA9ED,12) _PROTOTYPE( Short IUMagIDString, (Ptr aPtr, Ptr bPtr, Short aLen, Short bLen) );
ROMPACK(0xA9ED,4) _PROTOTYPE( Boolean IUMetric, (void) );
ROMPACK(0xA9ED,8) _PROTOTYPE( void IUSetIntl, (Short refNum, Short theID, Handle intlParam) );
ROMPACK(0xA9ED,2) _PROTOTYPE( void IUTimeString, (Long dateTime, Boolean wantSeconds, outStringPtr result) );
ROMPACK(0xA9ED,16) _PROTOTYPE( void IUTimePString, (Long dateTime, Boolean wantSeconds, outStringPtr result, Handle intlParam) );
#endif
