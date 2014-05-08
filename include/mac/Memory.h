#ifndef _MAC_MEMORY_H
#define _MAC_MEMORY_H

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

typedef Long         Size;
typedef struct Zone  Zone;
typedef struct Zone *THz;

struct Zone {
   Ptr bkLim;
   Ptr purgePtr;
   Ptr hFstFree;
   Long zcbFree;
   ProcPtr gzProc;
   Short moreMast;
   Short flags;
   Short cntRel;
   Short maxRel;
   Short cntNRel;
   Short maxNRel;
   Short cntEmpty;
   Short cntHandles;
   Long minCBFree;
   ProcPtr purgeProc;
   Ptr sparePtr;
   Ptr allocPtr;
   Short heapData;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( THz ApplicZone, (void) );
ROMTRAP(0xA02E) TO( _PROTOTYPE( void BlockMove, (A0(void *sourcePtr), A1(void *destPtr), D0(Size byteCount))),d0->MemErr );
ROMTRAP(0xA04C) TO( _PROTOTYPE( Size CompactMem, (D0(Size cbNeeded)) ), d0->MemErr);
ROMTRAP(0xA023) TO( _PROTOTYPE( void DisposHandle, (Handle) ), d0->MemErr);
ROMTRAP(0xA01F) TO( _PROTOTYPE( void DisposPtr, (A0(void *)) ), d0->MemErr);
ROMTRAP(0xA02B) TO( _PROTOTYPE( void EmptyHandle, (A0(Handle)) ), d0->MemErr);
ROMTRAP(0xA01C) TO( _PROTOTYPE( Long FreeMem, (void) ), d0->MemErr);
_PROTOTYPE( Ptr GetApplLimit, (void) );
ROMTRAP(0xA025) TO( _PROTOTYPE( Size GetHandleSize, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA021) TO( _PROTOTYPE( Size GetPtrSize, (A0(Ptr))), d0->MemErr);
ROMTRAP(0xA11A) TO( _PROTOTYPE( THz GetZone, (void)), d0->MemErr:a0->d0);
_PROTOTYPE( Handle GZSaveHnd, (void) );
ROMTRAP(0xA126) TO( _PROTOTYPE( THz HandleZone, (A0(Handle))), d0->MemErr:a0->d0);
ROMTRAP(0xA068) TO( _PROTOTYPE( void HClrRBit, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA069) TO( _PROTOTYPE( SignedByte HGetState, (A0(Handle)) ), d0);
ROMTRAP(0xA029) TO( _PROTOTYPE( void HLock, (A0(Handle))),d0->MemErr );
ROMTRAP(0xA04A) TO( _PROTOTYPE( void HNoPurge, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA049) TO( _PROTOTYPE( void HPurge, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA067) TO( _PROTOTYPE( void HSetRBit, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA06A) TO( _PROTOTYPE( void HSetState, (A0(Handle), D0(SignedByte flags))), d0->MemErr);
ROMTRAP(0xA02A) TO( _PROTOTYPE( void HUnlock, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA02C) TO( _PROTOTYPE( void InitApplZone, (void)), d0->MemErr);
_PROTOTYPE( void InitZone, (ProcPtr, Short cMoreMstrs, Ptr limitPtr, Ptr startPtr) );
ROMTRAP(0xA063) TO( _PROTOTYPE( void MaxApplZone, (void)), d0->MemErr);
ROMTRAP(0xA061) TO( _PROTOTYPE( Long MaxBlock, (void)), d0->MemErr);
ROMTRAP(0xA11D) TO( _PROTOTYPE( Size MaxMem, (RESULT(Size *grow))), d0->MemErr: a0->result);
_PROTOTYPE( OSErr MemError, (void) );
ROMTRAP(0xA036) _PROTOTYPE( void MoreMasters, (void) );
ROMTRAP(0xA064) TO( _PROTOTYPE( void MoveHHi, (A0(Handle))), d0->MemErr);
ROMTRAP(0xA066) TO( _PROTOTYPE( Handle NewEmptyHandle, (void)), a0->d0);
ROMTRAP(0xA122) TO( _PROTOTYPE( Handle NewHandle, (D0(Size logicalSize))),d0->MemErr:a0->d0 );
ROMTRAP(0xA11E) TO( _PROTOTYPE( Ptr NewPtr, (D0(Size logicalSize))), d0->MemErr:a0->d0);
ROMTRAP(0xA148) TO( _PROTOTYPE( THz PtrZone, (A0(Ptr))), d0->MemErr:a0->d0);
ROMTRAP(0xA04D) TO( _PROTOTYPE( void PurgeMem, (D0(Size cbNeeded))),d0->MemErr);
_PROTOTYPE( void PurgeSpace, (Long *total, Long *contig) );
ROMTRAP(0xA027) TO( _PROTOTYPE( void ReallocHandle, (A0(Handle), D0(Size logicalSize))), d0->MemErr);
ROMTRAP(0xA128) TO( _PROTOTYPE( Handle RecoverHandle, (A0(Ptr))), a0->d0);
ROMTRAP(0xA040) TO( _PROTOTYPE( void ResrvMem, (D0(Size cbNeeded))), d0->MemErr);
ROMTRAP(0xA057) TO( _PROTOTYPE( void SetApplBase, (A0(Ptr startPtr))), d0->MemErr);
ROMTRAP(0xA02D) TO( _PROTOTYPE( void SetApplLimit, (A0(Ptr zoneLimit))), d0->MemErr);
ROMTRAP(0xA04B) TO( _PROTOTYPE( void SetGrowZone, (A0(ProcPtr))), d0->MemErr);
ROMTRAP(0xA024) TO( _PROTOTYPE( void SetHandleSize, (A0(Handle), D0(Size newSize))),d0->MemErr );
ROMTRAP(0xA020) TO( _PROTOTYPE( void SetPtrSize, (A0(Ptr), D0(Size newSize))), d0->MemErr );
ROMTRAP(0xA01B) TO( _PROTOTYPE( void SetZone, (A0(THz))), d0->MemErr);
ROMTRAP(0xA065) TO( _PROTOTYPE( Long StackSpace, (void) ), d0);
_PROTOTYPE( THz SystemZone, (void) );
_PROTOTYPE( Ptr TopMem, (void) );
#endif
