#ifndef _MAC_APPLETALK_H
#define _MAC_APPLETALK_H

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

#define lapSize	20
#define ddpSize	26
#define nbpSize	26
#define atpSize 56

typedef struct ABusRecord ABusRecord;
typedef struct ABusRecord *ABRecPtr;
typedef struct ABusRecord **ABRecHandle;
typedef struct lapProto lapProto;
typedef struct ddpProto ddpProto;
typedef struct nbpProto nbpProto;
typedef struct atpProto atpProto;
typedef enum {tLapRead, tLAPWrite, tDDPRead, tDDPWrite,
	      tNBPLookup, tNBPConfirm, tNBPRegister,
	      tATBSndRequest, tATPGetRequest, tATPSdRsp,
	      tATPAddRsp, tATPRequest, tATPResponse } ABCallType;
typedef struct LAPAddrBlock LAPAddrBlock;
typedef char ABByte;
typedef struct AddrBlock AddrBlock;
typedef struct BDSElement BDSElement;
typedef char BitMapType[8];
typedef struct EntityName EntityName;
typedef struct EntityName *EntityPtr;
typedef struct RetransType RetransType;

struct LAPAddrBlock {
   unsigned char dstNodeID;
   unsigned char srcNodeID;
   ABByte lapProtType;
};

struct AddrBlock {
   Short aNet;
   unsigned char aNode;
   unsigned char aSocket;
};

struct BDSElement {
   Short buffSize;
   Ptr buffPtr;
   Short dataSize;
   Long userBytes;
};

typedef struct BDSElement BDSType[8];
typedef BDSType *BDSPtr;

struct EntityName {
   char objStr[32];
   char typeStr[32];
   char zoneStr[32];
};

struct RetransType {
   unsigned char retransInterval;
   unsigned char retransCount;
};

struct lapProto {
   LAPAddrBlock  lapAddress;
   Short lapReqCount;
   Short lapActCount;
   Ptr   lapDataPtr;
};

struct ddpProto {
   unsigned char ddpType;
   unsigned char ddpSocket;
   AddrBlock ddpAddress;
   Short ddpReqCount;
   Short ddpActCount;
   Ptr   ddpDataPtr;
   unsigned char ddpNodeID;
};

struct nbpProto {
   EntityPtr nbpEntityPtr;
   Ptr npbBufPtr;
   Short nbpBufSize;
   Short nbpDataField;
   AddrBlock nbpAddress;
   RetransType nbpRetransmitInfo;
};

struct atpProto {
   unsigned char atpSocket;
   AddrBlock atpAddress;
   Short atpReqCount;
   Ptr atpDataPtr;
   BDSPtr atpRspBDSPtr;
   BitMapType atpBitMap;
   Short atpTransID;
   Short atpActCount;
   Long atpUserData;
   Boolean atpXO;
   Boolean atpEOM;
   unsigned char atpTimeOut;
   unsigned char atpRetries;
   unsigned char atpNumBufs;
   unsigned char atpNumRsp;
   unsigned char atpBDSSize;
   Long atpRspUData;
   Ptr atpRspBuf;
   Short atpRspSize;
};

struct ABusRecord {
  ABCallType abOpcode;
  Short abResult;
  Long abUserReference;
  union {
    lapProto lapProto;
    ddpProto ddpProto;
    nbpProto nbpProto;
    atpProto atpProto;
  } ABProtoType;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( OSErr ATPAddRsp, (ABRecHandle h) );
_PROTOTYPE( OSErr ATPCloseSocket, (Short atpSocket) );
_PROTOTYPE( OSErr ATPGetRequest, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPLoad, (void) );
_PROTOTYPE( OSErr ATPOpenSocket, (AddrBlock addrRcvd, unsigned char *atpSocket) );
_PROTOTYPE( OSErr ATPReqCancel, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPRequest, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPResponse, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPRspCancel, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPSndRequest, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPSndRsp, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr ATPUnload, (void) );
_PROTOTYPE( OSErr DDPCloseSocket, (Short theSocket) );
_PROTOTYPE( OSErr DDPOpenSocket, (unsigned char *theSocket, Ptr sktListener) );
_PROTOTYPE( OSErr DDPRdCancel, (ABRecHandle h) );
_PROTOTYPE( OSErr DDPRead, (ABRecHandle h, Boolean retCksumErrs, Boolean async) );
_PROTOTYPE( OSErr DDPWrite, (ABRecHandle h, Boolean doChecksum, Boolean async) );
_PROTOTYPE( OSErr GetNodeAddress, (Short *myNode, Short *myNet) );
_PROTOTYPE( Boolean IsATPOpen, (void) );
_PROTOTYPE( Boolean IsMPPOpen, (void) );
_PROTOTYPE( OSErr LAPCloseProtocol, (ABByte theLAPType) );
_PROTOTYPE( OSErr LAPOpenProtocol, (ABByte theLAPType, Ptr protoPtr) );
_PROTOTYPE( OSErr LAPRdCancel, (ABRecHandle h) );
_PROTOTYPE( OSErr LAPRead, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr LAPWrite, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr MPPClose, (void) );
_PROTOTYPE( OSErr MPPOpen, (void) );
_PROTOTYPE( OSErr NBPConfirm, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr NBPExtract, (Ptr theBuffer, Short numInBuf, Short whichOne, EntityName *abEntity, AddrBlock *address) );
_PROTOTYPE( OSErr NBPLoad, (void) );
_PROTOTYPE( OSErr NBPLookup, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr NBPRegister, (ABRecHandle h, Boolean async) );
_PROTOTYPE( OSErr NBPRemove, (EntityPtr abEntity) );
_PROTOTYPE( OSErr NBPUnload, (void) );
#endif
