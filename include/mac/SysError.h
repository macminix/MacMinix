#ifndef _MAC_SYSERROR_H
#define _MAC_SYSERROR_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volume 4, appendix A.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#define noErr 		0

/* Operating System Event Manager Error */
#define evtNotEnb	1

/* Printing Manager Errors */
#define iPrAbort	128
#define iPrSavPFil	-1

/* Queuing Errors */
#define qErr		-1
#define vTypErr		-2

/* Device Manager Errors */
#define controlErr	-17
#define statusErr	-18
#define readErr		-19
#define writErr		-20
#define badUnitErr	-21
#define unitEmptyErr	-22
#define openErr		-23
#define dRemovErr	-25
#define dInstErr	-26
#define abortErr	-27
#define notOpenErr	-28

/* File Manager Errors */
#define dirFulErr	-33 
#define dskFulErr	-34
#define nsvErr		-35
#define ioErr		-36
#define bdNamErr	-37
#define fnOpnErr	-38
#define eofErr		-39
#define posErr		-40
#define tmfoErr		-42
#define fnfErr		-43
#define wPrErr		-44
#define fLckdErr	-45
#define vLckdErr	-46
#define fBsyErr		-47
#define dupFNErr	-48
#define opWrErr		-49
#define paramErr	-50
#define rfNumErr	-51
#define gfpErr		-52
#define volOffLinErr	-53
#define permErr		-54
#define volOnLinErr	-55
#define nsDrvErr	-56
#define noMacDskErr	-57
#define extFSErr	-58
#define fsRnErr		-59
#define badMDBErr	-60
#define wrPermErr	-61

/* Low-Level Disk Errors */
#define noDriveErr	-64
#define offLinErr	-65
#define noNybErr	-66
#define noAdrMkErr	-67
#define dataVerErr	-68
#define badCksmErr	-69
#define badBtSlpErr	-70
#define noDtaMkErr	-71
#define badDCksum	-72
#define bad DBtSlp	-73
#define wrUnderrun	-74
#define cantStepErr	-75
#define tk0BadErr	-76
#define initIWNErr	-77
#define twoSideErr	-78
#define spdAdjErr	-79
#define seekErr		-80
#define sectNFErr	-81

/* Also, to check for any low-level disk error: */
#define firstDskErr	-84
#define lastDskErr	-64

/* Clock Chip Errors */
#define clkRdErr	-85
#define clkWrErr	-86
#define prWrErr		-87
#define prInitErr	-88

/* AppleTalk Manager Errors */
#define ddpSktErr	-91
#define ddpLenErr	-92
#define noBridgeErr	-93
#define lapProtErr	-94
#define excessCollsns	-95
#define portInUse	-97
#define portNotCf	-98

/* Scrap Manager Errors */
#define noScrapErr	-100
#define noTypeErr	-102

/* Memory Manager Errors */
#define memFullErr	-108
#define nilHandleErr	-109
#define memWZErr	-111
#define memPurErr	-112
#define memLockedErr	-117

/* Resource Manager Errors */
#define resNotFound	-192
#define resFNotFound	-193
#define addResFailed	-194
#define rmvResFailed	-196

/* Additional AppleTalk Manager Errors */
#define nbpBuffOvr	-1024
#define nbpNoConfirm	-1025
#define nbpConfDiff	-1026
#define nbpDuplicate	-1027
#define nbpNotFound	-1028
#define nbpNISErr	-1029
#define reqFailed	-1096
#define tooManyReqs	-1097
#define tooManySkts	-1098
#define badATPSkt	-1099
#define badBuffNum	-1100
#define noRelErr	-1101
#define cbNotFound	-1102
#define noSendResp	-1103
#define noDataArea	-1104
#define reqAborted	-1105
#define buf2SmallErr	-3101
#define noMPPError	-3102
#define cksumErr	-3103
#define extractErr	-3104
#define readQErr	-3105
#define atpLenErr	-3106
#define atpBadRsp	-3107
#define recNotFnd	-3108
#define sktClosedErr	-3109

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA9C9) _PROTOTYPE( void SysError, (Short code) );
#endif
