#ifndef _MAC_FILES_H
#define _MAC_FILES_H

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

#ifndef _MAC_DEVICES_H
#include <mac/Devices.h>
#endif

/* finder flags */
#define fOnDesk 	1
#define fHasBundle 	8192
#define fInvisible 	16384
#define fTrash 		(-3)
#define fDesktop 	(-2)
#define fDisk 		0

/* permissions */
#define fsCurPerm 	0
#define fsRdPerm 	1
#define fsWrPerm	2
#define fsRdWrPerm	3
#define fsRdWrShPerm	4

/* positioning modes */
#define fsAtMark	0
#define fsFromStart	1
#define fsFromLEOF	2
#define fsFromMark	3
#define rdVerify	64

typedef struct FInfo FInfo;
typedef struct FXInfo FXInfo;
typedef struct DInfo DInfo;
typedef struct DXInfo DXInfo;
typedef struct IOParam IOParam;
typedef struct FileParam FileParam;
typedef struct VolumeParam VolumeParam;
typedef struct ParamBlockRec ParamBlockRec;
typedef struct ParamBlockRec *ParmBlkPtr;
typedef struct HIOParam HIOParam;
typedef struct HFileParam HFileParam;
typedef struct HVolumeParam HVolumeParam;
typedef struct HParamBlockRec HParamBlockRec;
typedef struct HParamBlockRec *HParmBlkPtr;
typedef struct HFileInfo HFileInfo;
typedef struct DirInfo DirInfo;
typedef struct CInfoPBRec CInfoPBRec;
typedef struct CInfoPBRec *CInfoPBPtr;
typedef struct CMovePBRec CMovePBRec;
typedef struct CMovePBRec *CMovePBPtr;
typedef struct WDPBRec WDPBRec;
typedef struct WDPBRec *WDPBPtr;
typedef struct FCBPBRec FCBPBRec;
typedef struct FCBPBRec *FCBPBPtr;
typedef struct VCB VCB;
typedef struct VCB *VCBPtr;
typedef struct DrvQEl DrvQEl;
typedef struct DrvQEl *DrvQElPtr;

/* Finder structures */
struct FInfo {
    OSType fdType;
    OSType fdCreator;
    UShort fdFlags;
    Point fdLocation;
    Short fdFldr;
};

struct FXInfo {
    Short fdIconID;
    Short fdUnused[4];
    Short fdComment;
    Long fdPutAway;
};

struct DInfo {
    Rect frRect;
    UShort frFlags;
    Point frLocation;
    Short frView;
};

struct DXInfo {
    Point frScroll;
    Long frOpenChain;
    Short frUnused;
    Short frComment;
    Long frPutAway;
};

/* ParamBlockRec defintions */
struct IOParam {
    Short ioRefNum;
    char ioVersNum;
    char ioPermssn;
    Ptr ioMisc;
    Ptr ioBuffer;
    Long ioReqCount;
    Long ioActCount;
    Short ioPosMode;
    Long ioPosOffset;
};

struct FileParam {
    Short ioFRefNum;
    char ioFVersNum;
    char filler1;
    Short ioFDirIndex;
    unsigned char ioFlAttrib;
    unsigned char ioFlVersNum;
    FInfo ioFlFndrInfo;
    ULong ioFlNum;
    UShort ioFlStBlk;
    Long ioFlLgLen;
    Long ioFlPyLen;
    UShort ioFlRStBlk;
    Long ioFlRLgLen;
    Long ioFlRPyLen;
    ULong ioFlCrDat;
    ULong ioFlMdDat;
};

struct VolumeParam {
    Long filler2;
    Short ioVolIndex;
    ULong ioVCrDate;
    ULong ioVLsBkUp;
    UShort ioVAtrb;
    UShort ioVNmFls;
    UShort ioVDirSt;
    Short ioVBlLn;
    UShort ioVNmAlBlks;
    Long ioVAlBlkSiz;
    Long ioVClpSiz;
    UShort ioAlBlSt;
    ULong ioVNxtFNum;
    UShort ioVFrBlk;
};

struct ParamBlockRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    union {
      IOParam ioParam;
      FileParam fileParam;
      VolumeParam volumeParam;
      CntrlParam cntrlParam;	/* from Devices.h */
    } ParamBlkType;
};

/* HParamBlockRec defintions */
struct HIOParam {
    Short ioRefNum;
    char ioVersNum;
    char ioPermssn;
    Ptr ioMisc;
    Ptr ioBuffer;
    Long ioReqCount;
    Long ioActCount;
    Short ioPosMode;
    Long ioPosOffset;
    Short filler1;
};

struct HFileParam {
    Short ioFRefNum;
    char ioFVersNum;
    char filler1;
    Short ioFDirIndex;
    char ioFlAttrib;
    char ioFlVersNum;
    FInfo ioFlFndrInfo;
    Long ioDirID;
    UShort ioFlStBlk;
    Long ioFlLgLen;
    Long ioFlPyLen;
    UShort ioFlRStBlk;
    Long ioFlRLgLen;
    Long ioFlRPyLen;
    ULong ioFlCrDat;
    ULong ioFlMdDat;
};

struct HVolumeParam {
    Long filler2;
    Short ioVolIndex;
    ULong ioVCrDate;
    ULong ioVLsMod;
    Short ioVAtrb;
    UShort ioVNmFls;
    Short ioVBitMap;
    Short ioAllocPtr;
    UShort ioVNmAlBlks;
    Long ioVAlBlkSiz;
    Long ioVClpSiz;
    Short ioAlBlSt;
    Long ioVNxtCNID;
    UShort ioVFrBlk;
    UShort ioVSigWord;
    Short ioVDrvInfo;
    Short ioVDRefNum;
    Short ioVFSID;
    ULong ioVBkUp;
    UShort ioVSeqNum;
    Long ioVWrCnt;
    Long ioVFilCnt;
    Long ioVDirCnt;
    Long ioVFndrInfo[8];
};

struct HParamBlockRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    union {
       HIOParam ioParam;
       HFileParam fileParam;
       HVolumeParam volumeParam;
    } ParamBlkType;
};

/* CinfoParam type */
struct HFileInfo {
    FInfo ioFlFndrInfo;
    Long ioDirID;
    UShort ioFlStBlk;
    Long ioFlLgLen;
    Long ioFlPyLen;
    UShort ioFlRStBlk;
    Long ioFlRLgLen;
    Long ioFlRPyLen;
    ULong ioFlCrDat;
    ULong ioFlMdDat;
    ULong ioFlBkDat;
    FXInfo ioFlXFndrInfo;
    Long ioFlParID;
    Long ioFlClpSiz;
};

struct DirInfo {
    DInfo ioDrUsrWds;
    Long ioDrDirID;
    UShort ioDrNmFls;
    Short filler3[9];
    ULong ioDrCrDat;
    ULong ioDrMdDat;
    ULong ioDrBkDat;
    DXInfo ioDrFndrInfo;
    Long ioDrParID;
};

struct CInfoPBRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    Short ioFRefNum;
    char ioFVersNum;
    char filler1;
    Short ioFDirIndex;
    char ioFlAttrib;
    char filler2;
    union {
      HFileInfo hfileInfo;
      DirInfo dirInfo;
    } CInfoType;
};

/* CMovePBRec */
struct CMovePBRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    Long filler1;
    StringPtr ioNewName;
    Long filler2;
    Long ioNewDirID;
    Long filler3[2];
    Long ioDirID;
};

/* WDPRec */
struct WDPBRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    Short filler1;
    Short ioWDIndex;
    Long ioWDProcID;
    Short ioWDVRefNum;
    Short filler2[7];
    Long ioWDDirID;
};

/* FCBPBRec */
struct FCBPBRec {
    struct QElem *qLink;
    Short qType;
    Short ioTrap;
    Ptr ioCmdAddr;
    ProcPtr ioCompletion;
    OSErr ioResult;
    StringPtr ioNamePtr;
    Short ioVRefNum;
    Short ioRefNum;
    Short filler;
    Short ioFCBIndx;
    Short filler1;
    Long ioFCBFlNm;
    Short ioFCBFlags;
    UShort ioFCBStBlk;
    Long ioFCBEOF;
    Long ioFCBPLen;
    Long ioFCBCrPs;
    Short ioFCBVRefNum;
    Long ioFCBClpSiz;
    Long ioFCBParID;
};

struct VCB {
    struct QElem *qLink;
    Short qType;
    Short vcbFlags;
    UShort vcbSigWord;
    ULong vcbCrDate;
    ULong vcbLsMod;
    Short vcbAtrb;
    UShort vcbNmFls;
    Short vcbVBMSt;
    Short vcbAllocPtr;
    UShort vcbNmAlBlks;
    Long vcbAlBlkSiz;
    Long vcbClpSiz;
    Short vcbAlBlSt;
    Long vcbNxtCNID;
    UShort vcbFreeBks;
    char vcbVN[28];
    Short vcbDrvNum;
    Short vcbDRefNum;
    Short vcbFSID;
    Short vcbVRefNum;
    Ptr vcbMAdr;
    Ptr vcbBufAdr;
    Short vcbMLen;
    Short vcbDirIndex;
    Short vcbDirBlk;
    ULong vcbVolBkUp;
    UShort vcbVSeqNum;
    Long vcbWrCnt;
    Long vcbXTClpSiz;
    Long vcbCTClpSiz;
    UShort vcbNmRtDirs;
    Long vcbFilCnt;
    Long vcbDirCnt;
    Long vcbFndrInfo[8];
    UShort vcbVCSize;
    UShort vcbVBMCSiz;
    UShort vcbCtlCSiz;
    UShort vcbXTAlBlks;
    UShort vcbCTAlBlks;
    Short vcbXTRef;
    Short vcbCTRef;
    Ptr vcbCtlBuf;
    Long vcbDirIDM;
    Short vcbOffsM;
};

/* Driver Q Element */
struct DrvQEl {
    struct QElem *qLink;
    Short qType;
    Short dQDrive;
    Short dQRefNum;
    Short dQFSID;
    UShort dQDrvSz;
    UShort dQDrvSz2;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( OSErr Allocate, (Short refnum, Long *count) );
_PROTOTYPE( OSErr Create, (StringPtr fileName, Short vRef, OSType creator, OSType fileType) );
_PROTOTYPE( OSErr Eject, (StringPtr volName, Short vRef) );
_PROTOTYPE( OSErr FlushVol, (StringPtr volName, Short vRef) );
_PROTOTYPE( OSErr FSClose, (Short ref) );
_PROTOTYPE( OSErr FSDelete, (StringPtr fileName, Short vRef) );
_PROTOTYPE( OSErr FSOpen, (StringPtr fileName, Short vRef, Short *ref) );
_PROTOTYPE( OSErr FSRead, (Short refnum, Long *count, void *buffPtr) );
_PROTOTYPE( OSErr FSWrite, (Short refnum, Long *count, void *buffPtr) );
_PROTOTYPE( OSErr GetEOF, (Short refnum, Long *logEOF) );
_PROTOTYPE( OSErr GetFInfo, (StringPtr fileName, Short vRef, FInfo *fndInfo) );
_PROTOTYPE( OSErr GetFPos, (Short refnum, Long *filePos) );
_PROTOTYPE( QHdrPtr GetDrvHdr, (void) );
_PROTOTYPE( QHdrPtr GetFSQHdr, (void) );
_PROTOTYPE( QHdrPtr GetVCBQHdr, (void) );
_PROTOTYPE( OSErr GetVInfo, (Short drvNum, StringPtr volName, Short *vRef, Long *freeBytes) );
_PROTOTYPE( OSErr GetVol, (StringPtr volName, Short *vRef) );
_PROTOTYPE( OSErr GetVRefNum, (Short pathRef, Short *vRef) );
_PROTOTYPE( OSErr OpenRF, (StringPtr fileName, Short vRef, Short *ref) );
_PROTOTYPE( OSErr Rename, (StringPtr oldName, Short vRef, StringPtr newName) );
_PROTOTYPE( OSErr RstFLock, (StringPtr fileName, Short vRef) );
_PROTOTYPE( OSErr SetEOF, (Short refnum, Long logEOF) );
_PROTOTYPE( OSErr SetFInfo, (StringPtr fileName, Short vRef, FInfo *fndInfo) );
_PROTOTYPE( OSErr SetFLock, (StringPtr fileName, Short vRef) );
_PROTOTYPE( OSErr SetFPos, (Short refnum, Short posMode, Long posOff) );
_PROTOTYPE( OSErr SetVol, (StringPtr volName, Short vRef) );
_PROTOTYPE( OSErr UnMountVol, (StringPtr volName, Short vRef) );
ROMTRAP(0xA016) TO(_PROTOTYPE( void FInitQueue, (void) ), d0);
ROMTRAP(0xA010) TO(_PROTOTYPE( OSErr PBAllocate, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA210) TO(_PROTOTYPE( OSErr PBAllocContig, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA001) TO(_PROTOTYPE( OSErr PBClose, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA004) TO(_PROTOTYPE( OSErr PBControl, ( A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA008) TO(_PROTOTYPE( OSErr PBCreate, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA009) TO(_PROTOTYPE( OSErr PBDelete, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA017) TO(_PROTOTYPE( OSErr PBEject, (A0(ParmBlkPtr)) ), d0);
ROMTRAP(0xA045) TO(_PROTOTYPE( OSErr PBFlushFile, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA013) TO(_PROTOTYPE( OSErr PBFlushVol, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA011) TO(_PROTOTYPE( OSErr PBGetEOF, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA007) TO(_PROTOTYPE( OSErr PBGetVInfo, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00C) TO(_PROTOTYPE( OSErr PBGetFInfo, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA018) TO(_PROTOTYPE( OSErr PBGetFPos, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA014) TO(_PROTOTYPE( OSErr PBGetVol, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA006) TO(_PROTOTYPE( OSErr PBKillIO, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00F) TO(_PROTOTYPE( OSErr PBMountVol, (A0(ParmBlkPtr)) ), d0);
ROMTRAP(0xA035) TO(_PROTOTYPE( OSErr PBOffLine, (A0(ParmBlkPtr)) ), d0);
ROMTRAP(0xA000) TO(_PROTOTYPE( OSErr PBOpen, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00A) TO(_PROTOTYPE( OSErr PBOpenRF, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA002) TO(_PROTOTYPE( OSErr PBRead, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00B) TO(_PROTOTYPE( OSErr PBRename, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA042) TO(_PROTOTYPE( OSErr PBRstFLock, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA012) TO(_PROTOTYPE( OSErr PBSetEOF, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00D) TO(_PROTOTYPE( OSErr PBSetFInfo, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA241) TO(_PROTOTYPE( OSErr PBSetFLock, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA044) TO(_PROTOTYPE( OSErr PBSetFPos, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA043) TO(_PROTOTYPE( OSErr PBSetFVers, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA015) TO(_PROTOTYPE( OSErr PBSetVol, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA005) TO(_PROTOTYPE( OSErr PBStatus, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA00E) TO(_PROTOTYPE( OSErr PBUnMountVol, (A0(ParmBlkPtr)) ), d0);
ROMTRAP(0xA003) TO(_PROTOTYPE( OSErr PBWrite, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-16) TO(_PROTOTYPE( OSErr PBLockRange, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-17) TO(_PROTOTYPE( OSErr PBUnlockRange, (A0(ParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA207) TO(_PROTOTYPE( OSErr PBHGetVInfo, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA214) TO(_PROTOTYPE( OSErr PBHGetVol, (A0(WDPBPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA215) TO(_PROTOTYPE( OSErr PBHSetVol, (A0(WDPBPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA200) TO(_PROTOTYPE( OSErr PBHOpen, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA20A) TO(_PROTOTYPE( OSErr PBHOpenRF, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA208) TO(_PROTOTYPE( OSErr PBHCreate, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-6) TO(_PROTOTYPE( OSErr PBDirCreate, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA209) TO(_PROTOTYPE( OSErr PBHDelete, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA20C) TO(_PROTOTYPE( OSErr PBHGetFInfo, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA20D) TO(_PROTOTYPE( OSErr PBHSetFInfo, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA242) TO(_PROTOTYPE( OSErr PBHRstFLock, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA241) TO(_PROTOTYPE( OSErr PBHSetFLock, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMTRAP(0xA20B) TO(_PROTOTYPE( OSErr PBHRename, (A0(HParmBlkPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-9) TO(_PROTOTYPE( OSErr PBGetCatInfo, (A0(CInfoPBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-10) TO(_PROTOTYPE( OSErr PBSetCatInfo, (A0(CInfoPBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-5) TO(_PROTOTYPE( OSErr PBCatMove, (A0(CMovePBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-1) TO(_PROTOTYPE( OSErr PBOpenWD, (A0(WDPBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-2) TO(_PROTOTYPE( OSErr PBCloseWD, (A0(WDPBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-7) TO(_PROTOTYPE( OSErr PBGetWDInfo, (A0(WDPBPtr), ASYNC(Boolean)) ), d0);
ROMPACK(0xA260,-8) TO(_PROTOTYPE( OSErr PBGetFCBInfo, (A0(FCBPBPtr), ASYNC(Boolean)) ), d0);
#endif
