#ifndef _MAC_DIALOGS_H
#define _MAC_DIALOGS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

#ifndef _MAC_TEXT_H
#include <mac/TextEdit.h>
#endif

#ifndef _MAC_WINDOWS_H
#include <mac/Windows.h>
#endif

/* Item types */
#define ctrlItem 		4
#define btnCtrl 		0
#define chkCtrl 		1
#define radCtrl 		2
#define resCtrl 		3
#define statText 		8
#define editText 	       16
#define iconItem     	       32
#define picItem 	       64
#define userItem 		0
#define itemDisable 	      128

/* Item numbers */
#define ok 			1
#define cancel 			2

/* Resource IDs */
#define stopIcon 		0
#define noteIcon 		1
#define cautionIcon 		2

typedef Short                   StageList;   	/* need bitfields */
typedef WindowPtr               DialogPtr;
typedef struct DialogRecord     DialogRecord;
typedef struct DialogRecord    *DialogPeek;
typedef struct DialogTemplate   DialogTemplate;
typedef struct DialogTemplate  *DialogTPtr;
typedef struct DialogTemplate **DialogTHndl;
typedef struct AlertTemplate    AlertTemplate;
typedef struct AlertTemplate   *AlertTPtr;
typedef struct AlertTemplate  **AlertTHndl;

struct DialogRecord {
   WindowRecord 	window;
   Handle 		items;
   TEHandle		textH;
   Short 		editField;
   Short 		editOpen;
   Short 		aDefItem;
};

struct DialogTemplate {
   Rect 		boundsRect;
   Short 		procID;
   Boolean 		visible;
   Boolean 		filler1;
   Boolean 		goAwayFlag;
   Boolean 		filler2;
   Long 		refCon;
   Short 		itemsID;
   Str255 		title;
};

struct AlertTemplate {
   Rect 		boundsRect;
   Short 		itemsID;
   StageList 		stages;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA985) _PROTOTYPE( Short Alert, (Short alertID, ProcPtr filterProc) );
ROMTRAP(0xA988) _PROTOTYPE( Short CautionAlert, (Short alertID, ProcPtr filterProc) );
ROMTRAP(0xA982) _PROTOTYPE( void CloseDialog, (DialogPtr dp) );
ROMTRAP(0xA989) _PROTOTYPE( void CouldAlert, (Short alertID) );
ROMTRAP(0xA979) _PROTOTYPE( void CouldDialog, (Short dialogID) );
ROMTRAP(0xA980) _PROTOTYPE( Boolean DialogSelect, (EventRecord *theEvent, DialogPtr *theDialog, Short *itemHit) );
ROMTRAP(0xA983) _PROTOTYPE( void DisposDialog, (DialogPtr dp) );
_PROTOTYPE( void DlgCut, (DialogPtr dp) );
_PROTOTYPE( void DlgCopy, (DialogPtr dp) );
_PROTOTYPE( void DlgDelete, (DialogPtr dp) );
_PROTOTYPE( void DlgPaste, (DialogPtr dp) );
ROMTRAP(0xA981) _PROTOTYPE( void DrawDialog, (DialogPtr dp) );
ROMTRAP(0xA98C) _PROTOTYPE( void ErrorSound, (ProcPtr soundProc) );
ROMTRAP(0xA984) _PROTOTYPE( Short FindDItem, (DialogPtr dp, Point pt) );
ROMTRAP(0xA98A) _PROTOTYPE( void FreeAlert, (Short alertID) );
ROMTRAP(0xA97A) _PROTOTYPE( void FreeDialog, (Short dialogID) );
_PROTOTYPE( Short GetAlrtStage, (void) );
ROMTRAP(0xA98D) _PROTOTYPE( void GetDItem, (DialogPtr dp, Short itemNo, Short *itemType, Handle *item, Rect *box) );
ROMTRAP(0xA990) _PROTOTYPE( void GetIText, (Handle item, outStringPtr text) );
ROMTRAP(0xA97C) _PROTOTYPE( DialogPtr GetNewDialog, (Short dlogID, DialogPeek dStorage, WindowPtr behind) );
ROMTRAP(0xA827) _PROTOTYPE( void HideDItem, (DialogPtr dp, Short itemNo) );
ROMTRAP(0xA97B) _PROTOTYPE( void InitDialogs, (ProcPtr resumeProc) );
ROMTRAP(0xA97F) _PROTOTYPE( Boolean IsDialogEvent, (EventRecord *theEvent) );
ROMTRAP(0xA991) _PROTOTYPE( void ModalDialog, (ProcPtr filterProc, Short *itemHit) );
ROMTRAP(0xA97D) _PROTOTYPE( DialogPtr NewDialog, (DialogPeek dStorage, Rect *bounds, inStringPtr title, Boolean vis, Short procID, WindowPtr behind, Boolean goAway, Long refCon, Handle items) );
ROMTRAP(0xA987) _PROTOTYPE( Short NoteAlert, (Short alertID, ProcPtr filterProc) );
ROMTRAP(0xA98B) _PROTOTYPE( void ParamText, (inStringPtr param0, inStringPtr param1, inStringPtr param2, inStringPtr param3) );
_PROTOTYPE( void ResetAlrtStage, (void) );
ROMTRAP(0xA97E) _PROTOTYPE( void SelIText, (DialogPtr dp, Short itemNo, Short strtSel, Short endSel) );
_PROTOTYPE( void SetDAFont, (Short fontNum) );
ROMTRAP(0xA98E) _PROTOTYPE( void SetDItem, (DialogPtr dp, Short itemNo, Short itemType, Handle item, Rect *box) );
ROMTRAP(0xA98F) _PROTOTYPE( void SetIText, (Handle item, inStringPtr text) );
ROMTRAP(0xA828) _PROTOTYPE( void ShowDItem, (DialogPtr dp, Short itemNo) );
ROMTRAP(0xA986) _PROTOTYPE( Short StopAlert, (Short alertID, ProcPtr filterProc) );
ROMTRAP(0xA978) _PROTOTYPE( void UpdtDialog, (DialogPtr dp, RgnHandle updateRgn) );
#endif
