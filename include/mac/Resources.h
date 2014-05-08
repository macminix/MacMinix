#ifndef _MAC_RESOURCES_H
#define _MAC_RESOURCES_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* masks for resource attrs */
#define resSysHeap	64
#define resPurgeable	32
#define resLocked	16
#define resProtected	8
#define resPreload	4
#define resChanged	2

/* masks for resource file attrs */
#define mapReadOnly	128
#define mapCompact	64
#define mapChanged	32

typedef ULong ResType;
typedef ULong inResType;
typedef ULong outResType;

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9AB) _PROTOTYPE( void AddResource, (Handle theData, ResType, Short theID, inStringPtr name) );
ROMTRAP(0xA9AA) _PROTOTYPE( void ChangedResource, (Handle theResource) );
ROMTRAP(0xA99A) _PROTOTYPE( void CloseResFile, (Short refNum) );
ROMTRAP(0xA80D) _PROTOTYPE( Short Count1Resources, (ResType) );
ROMTRAP(0xA81C) _PROTOTYPE( Short Count1Types, (void) );
ROMTRAP(0xA99C) _PROTOTYPE( Short CountResources, (ResType) );
ROMTRAP(0xA99E) _PROTOTYPE( Short CountTypes, (void) );
ROMTRAP(0xA9B1) _PROTOTYPE( void CreateResFile, (inStringPtr fileName) );
ROMTRAP(0xA994) _PROTOTYPE( Short CurResFile, (void) );
ROMTRAP(0xA992) _PROTOTYPE( void DetachResource, (Handle theResource) );
ROMTRAP(0xA80E) _PROTOTYPE( Handle Get1IndResource, (ResType, Short index) );
ROMTRAP(0xA80F) _PROTOTYPE( void Get1IndType, (ResType *theType, Short index) );
ROMTRAP(0xA820) _PROTOTYPE( Handle Get1NamedResource, (ResType, inStringPtr name) );
ROMTRAP(0xA81F) _PROTOTYPE( Handle Get1Resource, (ResType, Short theID) );
ROMTRAP(0xA99D) _PROTOTYPE( Handle GetIndResource, (ResType, Short index) );
ROMTRAP(0xA99F) _PROTOTYPE( void GetIndType, (ResType *res, Short index) );
ROMTRAP(0xA9A1) _PROTOTYPE( Handle GetNamedResource, (ResType, inStringPtr name) );
ROMTRAP(0xA9A6) _PROTOTYPE( Short GetResAttrs, (Handle theResource) );
ROMTRAP(0xA9F6) _PROTOTYPE( Short GetResFileAttrs, (Short refNum) );
ROMTRAP(0xA9A8) _PROTOTYPE( void GetResInfo, (Handle theResource, Short *theID, ResType *theType, StringPtr name) );
ROMTRAP(0xA9A0) _PROTOTYPE( Handle GetResource, (ResType, Short theID) );
ROMTRAP(0xA9A4) _PROTOTYPE( Short HomeResFile, (Handle theResource) );
ROMTRAP(0xA995) _PROTOTYPE( Short InitResources, (void) );
ROMTRAP(0xA9A2) _PROTOTYPE( void LoadResource, (Handle theResource) );
ROMTRAP(0xA821) _PROTOTYPE( Long MaxSizeRsrc, (Handle) );
ROMTRAP(0xA9C4) _PROTOTYPE( Short OpenRFPerm, (inStringPtr fileName, Short vRefNum, Short permission) );
ROMTRAP(0xA997) _PROTOTYPE( Short OpenResFile, (inStringPtr fileName) );
ROMTRAP(0xA9A3) _PROTOTYPE( void ReleaseResource, (Handle theResource) );
ROMTRAP(0xA9AD) _PROTOTYPE( void RmveResource, (Handle theResource) );
ROMTRAP(0xA9AF) _PROTOTYPE( Short ResError, (void) );
ROMTRAP(0xA9C5) _PROTOTYPE( Long RsrcMapEntry, (Handle) );
ROMTRAP(0xA996) _PROTOTYPE( void RsrcZoneInit, (void) );
ROMTRAP(0xA9A7) _PROTOTYPE( void SetResAttrs, (Handle theResource, Short attrs) );
ROMTRAP(0xA9F7) _PROTOTYPE( void SetResFileAttrs, (Short refNum, Short attrs) );
ROMTRAP(0xA9A9) _PROTOTYPE( void SetResInfo, (Handle theResource, Short theID, inStringPtr name) );
ROMTRAP(0xA99B) _PROTOTYPE( void SetResLoad, (Boolean load) );
ROMTRAP(0xA993) _PROTOTYPE( void SetResPurge, (Boolean install) );
ROMTRAP(0xA9A5) _PROTOTYPE( Long SizeResource, (Handle theResource) );
ROMTRAP(0xA810) _PROTOTYPE( Short Unique1ID, (ResType) );
ROMTRAP(0xA9C1) _PROTOTYPE( Short UniqueID, (ResType) );
ROMTRAP(0xA999) _PROTOTYPE( void UpdateResFile, (Short refNum) );
ROMTRAP(0xA998) _PROTOTYPE( void UseResFile, (Short refNum) );
ROMTRAP(0xA9B0) _PROTOTYPE( void WriteResource, (Handle theResource) );
#endif
