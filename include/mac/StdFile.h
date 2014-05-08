#ifndef _MAC_STDFILE_H
#define _MAC_STDFILE_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

#ifndef _MAC_OSUTILS_H
#include <mac/OSUtils.h>
#endif

/* SFPutFile dialog ID */
#define putDlgID 	-3999

/* Item numbers */
#define putSave 	1
#define putCancel 	2
#define putEject 	5
#define putDrive 	6
#define putName 	7

/* SFGetFile dialog ID */
#define getDlgID 	-4000

/* Item numbers */
#define getOpen 	1
#define getCancel 	3
#define getEject 	5
#define getDrive 	6
#define getNmList 	7
#define getScroll 	8

/* type defs */
typedef OSType SFTypeList[4];
typedef struct SFReply SFReply;

/* structure defs */
struct SFReply {
   Boolean	good;
   Boolean	copy;
   OSType	fType;
   Short	vRefNum;
   Short	version;
   char         fName[63];
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMPACK(0xA9EA,2) _PROTOTYPE( void SFGetFile, (Point where, inStringPtr prompt, ProcPtr fileFilter, Short numTypes, SFTypeList *typeList, ProcPtr dlgHook, SFReply *reply) );
ROMPACK(0xA9EA,1) _PROTOTYPE( void SFPutFile, (Point where, inStringPtr prompt, inStringPtr origName, ProcPtr dlgHook, SFReply *reply) );
ROMPACK(0xA9EA,4) _PROTOTYPE( void SFPGetFile, (Point where, inStringPtr prompt, ProcPtr fileFilter, Short numTypes, SFTypeList *typeList, ProcPtr dlgHook, SFReply *reply, Short dlgID, ProcPtr filterProc) );
ROMPACK(0xA9EA,3) _PROTOTYPE( void SFPPutFile, (Point where, inStringPtr prompt, inStringPtr origName, ProcPtr dlgHook, SFReply *reply, Short dlgID, ProcPtr filterProc) );
#endif
