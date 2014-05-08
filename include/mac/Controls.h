#ifndef _MAC_CONTROLS_H
#define _MAC_CONTROLS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

#ifndef _MAC_WINDOWS_H
#include <mac/Windows.h>
#endif

/* Control def IDS */
#define pushButProc 		 0
#define checkBoxProc 		 1
#define radioButProc 		 2
#define useWFont 		 8
#define scrollBarProc 		16

/* Part Codes */
#define inButton 		10
#define inCheckBox 		11
#define inUpButton 		20
#define inDownButton 		21
#define inPageUp 		22
#define inPageDown 		23
#define inThumb 	       129

/* Messages */
#define drawCntl 		 0
#define testCntl 		 1
#define calcCRgns 		 2
#define initCntl 		 3
#define dispCntl 		 4
#define posCntl 		 5
#define thumbCntl 		 6
#define dragCntl 		 7
#define autoTrack 		 8

typedef struct ControlRecord   ControlRecord;
typedef struct ControlRecord  *ControlPtr;
typedef struct ControlRecord **ControlHandle;

/* Control record */
struct ControlRecord {
   ControlHandle           nextControl;
   WindowPtr 		   contrlOwner;
   Rect 		   contrlRect;
   unsigned char	   contrlVis;
   unsigned char       	   contrlHilite;
   Short 	      	   contrlValue;
   Short 		   contrlMin;
   Short 		   contrlMax;
   Handle 		   contrlDefProc;
   Handle 		   contrlData;
   ProcPtr 		   contrlAction;
   Long 		   contrlRfCon;
   Str255 		   contrlTitle;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

/* PROTOTYPE definitions */
ROMTRAP(0xA955) _PROTOTYPE( void DisposeControl, (ControlHandle ch) );
ROMTRAP(0xA967) _PROTOTYPE( void DragControl, (ControlHandle ch, Point pt, Rect *limit, Rect *slop, Short axis) );
ROMTRAP(0xA96D) _PROTOTYPE( void Draw1Control, (ControlHandle ch) );
ROMTRAP(0xA969) _PROTOTYPE( void DrawControls, (WindowPtr wp) );
ROMTRAP(0xA96C) _PROTOTYPE( Short FindControl, (Point wh, WindowPtr wp, ControlHandle *ch) );
ROMTRAP(0xA95A) _PROTOTYPE( Long GetCRefCon, (ControlHandle ch) );
ROMTRAP(0xA95E) _PROTOTYPE( void GetCTitle, (ControlHandle ch, inStringPtr title) );
ROMTRAP(0xA96A) _PROTOTYPE( ProcPtr GetCtlAction, (ControlHandle ch) );
ROMTRAP(0xA961) _PROTOTYPE( Short GetCtlMin, (ControlHandle ch) );
ROMTRAP(0xA962) _PROTOTYPE( Short GetCtlMax, (ControlHandle ch) );
ROMTRAP(0xA960) _PROTOTYPE( Short GetCtlValue, (ControlHandle ch) );
ROMTRAP(0xA9BE) _PROTOTYPE( ControlHandle GetNewControl, (Short ID, WindowPtr wp) );
ROMTRAP(0xA958) _PROTOTYPE( void HideControl, (ControlHandle ch) );
ROMTRAP(0xA95D) _PROTOTYPE( void HiliteControl, (ControlHandle ch, Short hiliteState) );
ROMTRAP(0xA956) _PROTOTYPE( void KillControls, (WindowPtr wp) );
ROMTRAP(0xA959) _PROTOTYPE( void MoveControl, (ControlHandle ch, Short h, Short v) );
ROMTRAP(0xA954) _PROTOTYPE( ControlHandle NewControl, (WindowPtr wp, Rect *bounds, inStringPtr title, Boolean vis, Short val, Short min, Short max, Short procID, Long refCon) );
ROMTRAP(0xA95B) _PROTOTYPE( void SetCRefCon, (ControlHandle ch, Long data) );
ROMTRAP(0xA95F) _PROTOTYPE( void SetCTitle, (ControlHandle ch, inStringPtr title) );
ROMTRAP(0xA96B) _PROTOTYPE( void SetCtlAction, (ControlHandle ch, ProcPtr actionProc) );
ROMTRAP(0xA965) _PROTOTYPE( void SetCtlMax, (ControlHandle ch, Short val) );
ROMTRAP(0xA964) _PROTOTYPE( void SetCtlMin, (ControlHandle ch, Short val) );
ROMTRAP(0xA963) _PROTOTYPE( void SetCtlValue, (ControlHandle ch, Short v) );
ROMTRAP(0xA957) _PROTOTYPE( void ShowControl, (ControlHandle ch) );
ROMTRAP(0xA95C) _PROTOTYPE( void SizeControl, (ControlHandle ch, Short w, Short h) );
ROMTRAP(0xA966) _PROTOTYPE( Short TestControl, (ControlHandle ch, Point pt) );
ROMTRAP(0xA968) _PROTOTYPE( Short TrackControl, (ControlHandle ch, Point start, ProcPtr action) );
ROMTRAP(0xA953) _PROTOTYPE( void UpdtControl, (WindowPtr wp, RgnHandle rh) );
#endif
