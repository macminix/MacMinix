#ifndef _MAC_WINDOWS_H
#define _MAC_WINDOWS_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_QUICKDRAW_H
#include <mac/Quickdraw.h>
#endif

#ifndef _MAC_EVENTS_H
#include <mac/Events.h>
#endif

/* window def ids */
#define documentProc 	0
#define dBoxProc 	1
#define plainDBox 	2
#define altDBoxProc 	3
#define noGrowDocProc 	4
#define zoomDocProc 	8
#define zoomNoGrow 	12
#define rDocProc 	16

/* window classes */
#define dialogKind 	2
#define userKind 	8

/* returned by FindWindow */
#define inDesk 		0
#define inMenuBar 	1
#define inSysWindow 	2
#define inContent 	3
#define inDrag 		4
#define inGrow 		5
#define inGoAway 	6
#define inZoomIn 	7
#define inZoomOut 	8

/* Axis contraints */
#define noConstraint 	0
#define hAxisOnly 	1
#define vAxisOnly 	2

/* messages to window def */
#define wDraw 		0
#define wHit 		1
#define wCalcRgns 	2
#define wNew 		3
#define wDispose 	4
#define wGrow 		5
#define wDrawGIcon 	6

/* returned by hit def */
#define wNoHit 		0
#define wInContent 	1
#define wInDrag 	2
#define wInGrow 	3
#define wInGoAway 	4
#define wInZoomIn 	5
#define wInZoomOut 	6

/* res id of desktop pattern */
#define deskPatID 	16

typedef struct WindowRecord *WindowPeek;
typedef struct WStateData WStateData;
typedef struct WindowRecord  WindowRecord;
typedef GrafPtr WindowPtr;

struct WindowRecord {
    GrafPort 	port;
    Short	windowKind;
    Boolean 	visible;
    Boolean	hilited;
    Boolean	goAwayFlag;
    Boolean	spareFlag;
    RgnHandle	strucRgn;
    RgnHandle	contRgn;
    RgnHandle	updateRgn;
    Handle	windowDefProc;
    Handle	dataHandle;
    StringHandle titleHandle;
    Short	titleWidth;
    struct ControlRecord **controlList;
    struct WindowRecord *nextWindow;
    PicHandle	windowPic;
    Long	refCon;
};

struct WStateData {
    Rect 	userState;
    Rect	stdState;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA922) _PROTOTYPE( void BeginUpdate, (WindowPtr) );
ROMTRAP(0xA920) _PROTOTYPE( void BringToFront, (WindowPtr) );
ROMTRAP(0xA909) _PROTOTYPE( void CalcVis, (WindowPeek) );
ROMTRAP(0xA90A) _PROTOTYPE( void CalcVisBehind, (WindowPeek startWindow, RgnHandle clobberedRgn) );
ROMTRAP(0xA911) _PROTOTYPE( Boolean CheckUpdate, (EventRecord *theEvent) );
ROMTRAP(0xA90B) _PROTOTYPE( void ClipAbove, (WindowPeek) );
ROMTRAP(0xA92D) _PROTOTYPE( void CloseWindow, (WindowPtr) );
ROMTRAP(0xA914) _PROTOTYPE( void DisposeWindow, (WindowPtr) );
ROMTRAP(0xA905) _PROTOTYPE( Long DragGrayRgn, (RgnHandle, Point startPt, Rect *limitRect, Rect *slopRect, Short axis, ProcPtr actionProc) );
ROMTRAP(0xA925) _PROTOTYPE( void DragWindow, (WindowPtr, Point startPt, Rect *boundsRect) );
ROMTRAP(0xA904) _PROTOTYPE( void DrawGrowIcon, (WindowPtr) );
ROMTRAP(0xA90F) _PROTOTYPE( void DrawNew, (WindowPeek, Boolean update) );
ROMTRAP(0xA923) _PROTOTYPE( void EndUpdate, (WindowPtr) );
ROMTRAP(0xA92C) _PROTOTYPE( Short FindWindow, (Point thePt, WindowPtr *whichWind) );
ROMTRAP(0xA924) _PROTOTYPE( WindowPtr FrontWindow, (void) );
ROMTRAP(0xA9BD) _PROTOTYPE( WindowPtr GetNewWindow, (Short windowID, WindowPeek wStorage, WindowPtr behind) );
ROMTRAP(0xA92F) _PROTOTYPE( PicHandle GetWindowPic, (WindowPtr) );
ROMTRAP(0xA910) _PROTOTYPE( void GetWMgrPort, (GrafPtr *wPort) );
ROMTRAP(0xA917) _PROTOTYPE( Long GetWRefCon, (WindowPtr) );
ROMTRAP(0xA919) _PROTOTYPE( void GetWTitle, (WindowPtr, outStringPtr title) );
ROMTRAP(0xA92B) _PROTOTYPE( Long GrowWindow, (WindowPtr, Point startPt, Rect *sizeRect) );
ROMTRAP(0xA916) _PROTOTYPE( void HideWindow, (WindowPtr) );
ROMTRAP(0xA91C) _PROTOTYPE( void HiliteWindow, (WindowPtr, Boolean fHilite) );
ROMTRAP(0xA912) _PROTOTYPE( void InitWindows, (void) );
ROMTRAP(0xA928) _PROTOTYPE( void InvalRect, (Rect *badRect) );
ROMTRAP(0xA927) _PROTOTYPE( void InvalRgn, (RgnHandle badRgn) );
ROMTRAP(0xA91B) _PROTOTYPE( void MoveWindow, (WindowPtr, Short hGlobal, Short vGlobal, Boolean front) );
ROMTRAP(0xA913) _PROTOTYPE( WindowPtr NewWindow, (WindowPeek wStorage, Rect *boundsRect, inStringPtr title, Boolean visible, Short procID, WindowPtr behind, Boolean goAwayFlag, Long refCon) );
ROMTRAP(0xA90D) _PROTOTYPE( void PaintBehind, (WindowPeek startWindow, RgnHandle clobberedRgn) );
ROMTRAP(0xA90C) _PROTOTYPE( void PaintOne, (WindowPeek, RgnHandle clobberedRgn) );
ROMTRAP(0xA94E) _PROTOTYPE( Long PinRect, (Rect *r, Point) );
ROMTRAP(0xA90E) _PROTOTYPE( void SaveOld, (WindowPeek) );
ROMTRAP(0xA91F) _PROTOTYPE( void SelectWindow, (WindowPtr) );
ROMTRAP(0xA921) _PROTOTYPE( void SendBehind, (WindowPtr theWindow, WindowPtr behindWindow) );
ROMTRAP(0xA92E) _PROTOTYPE( void SetWindowPic, (WindowPtr, PicHandle) );
ROMTRAP(0xA918) _PROTOTYPE( void SetWRefCon, (WindowPtr, Long data) );
ROMTRAP(0xA91A) _PROTOTYPE( void SetWTitle, (WindowPtr, inStringPtr title) );
ROMTRAP(0xA908) _PROTOTYPE( void ShowHide, (WindowPtr, Boolean showFlag) );
ROMTRAP(0xA915) _PROTOTYPE( void ShowWindow, (WindowPtr) );
ROMTRAP(0xA91D) _PROTOTYPE( void SizeWindow, (WindowPtr, Short w, Short h, Boolean fUpdate) );
ROMTRAP(0xA83B) _PROTOTYPE( Boolean TrackBox, (WindowPtr, Point, Short partCode) );
ROMTRAP(0xA91E) _PROTOTYPE( Boolean TrackGoAway, (WindowPtr, Point thePt) );
ROMTRAP(0xA92A) _PROTOTYPE( void ValidRect, (Rect *goodRect) );
ROMTRAP(0xA929) _PROTOTYPE( void ValidRgn, (RgnHandle goodRgn) );
ROMTRAP(0xA83A) _PROTOTYPE( void ZoomWindow, (WindowPtr, Short partCode, Boolean front) );
#endif
