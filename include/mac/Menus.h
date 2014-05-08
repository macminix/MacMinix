#ifndef _MAC_MENUS_H
#define _MAC_MENUS_H

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

#ifndef _MAC_RESOURCES_H
#include <mac/Resources.h>
#endif

/* item has no mark */
#define noMark 		0

/* messages to emu defs */
#define mDrawMsg 	0
#define mChooseMsg 	1
#define mSizeMsg 	2

/* res id of standard menu def */
#define textMenuProc 	0

typedef struct MenuInfo   MenuInfo;
typedef struct MenuInfo  *MenuPtr;
typedef struct MenuInfo **MenuHandle;

struct MenuInfo {
   Short  menuID;
   Short  menuWidth;
   Short  menuHeight;
   Handle menuProc;
   Long   enableFlags;
   Str255 menuData;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

ROMTRAP(0xA94D) _PROTOTYPE( void AddResMenu, (MenuHandle, inResType) );
ROMTRAP(0xA933) _PROTOTYPE( void AppendMenu, (MenuHandle, inStringPtr data) );
ROMTRAP(0xA948) _PROTOTYPE( void CalcMenuSize, (MenuHandle) );
ROMTRAP(0xA945) _PROTOTYPE( void CheckItem, (MenuHandle, Short item, Boolean checked) );
ROMTRAP(0xA934) _PROTOTYPE( void ClearMenuBar, (void) );
ROMTRAP(0xA950) _PROTOTYPE( Short CountMItems, (MenuHandle) );
ROMTRAP(0xA936) _PROTOTYPE( void DeleteMenu, (Short menuID) );
ROMTRAP(0xA952) _PROTOTYPE( void DelMenuItem, (MenuHandle, Short item) );
ROMTRAP(0xA93A) _PROTOTYPE( void DisableItem, (MenuHandle, Short item) );
ROMTRAP(0xA932) _PROTOTYPE( void DisposeMenu, (MenuHandle) );
ROMTRAP(0xA937) _PROTOTYPE( void DrawMenuBar, (void) );
ROMTRAP(0xA939) _PROTOTYPE( void EnableItem, (MenuHandle, Short item) );
ROMTRAP(0xA94C) _PROTOTYPE( void FlashMenuBar, (Short menuID) );
ROMTRAP(0xA946) _PROTOTYPE( void GetItem, (MenuHandle, Short item, outStringPtr itemString) );
ROMTRAP(0xA93F) _PROTOTYPE( void GetItemIcon, (MenuHandle, Short item, Short *icon) );
ROMTRAP(0xA943) _PROTOTYPE( void GetItemMark, (MenuHandle, Short item, Short *markChar) );
ROMTRAP(0xA941) _PROTOTYPE( void GetItemStyle, (MenuHandle, Short item, Short *chStyle) );
ROMTRAP(0xA9BF) _PROTOTYPE( MenuHandle GetMenu, (Short resourceID) );
ROMTRAP(0xA93B) _PROTOTYPE( Handle GetMenuBar, (void) );
ROMTRAP(0xA949) _PROTOTYPE( MenuHandle GetMHandle, (Short menuID) );
ROMTRAP(0xA9C0) _PROTOTYPE( Handle GetNewMBar, (Short menuBarID) );
ROMTRAP(0xA938) _PROTOTYPE( void HiliteMenu, (Short menuID) );
ROMTRAP(0xA930) _PROTOTYPE( void InitMenus, (void) );
ROMTRAP(0xA935) _PROTOTYPE( void InsertMenu, (MenuHandle, Short beforeID) );
ROMTRAP(0xA951) _PROTOTYPE( void InsertResMenu, (MenuHandle, inResType, Short afterItem) );
ROMTRAP(0xA826) _PROTOTYPE( void InsMenuItem, (MenuHandle, inStringPtr, Short afterItem) );
ROMTRAP(0xA93E) _PROTOTYPE( Long MenuKey, (Short) );
ROMTRAP(0xA93D) _PROTOTYPE( Long MenuSelect, (Point startPt) );
ROMTRAP(0xA931) _PROTOTYPE( MenuHandle NewMenu, (Short menuID, inStringPtr title) );
ROMTRAP(0xA947) _PROTOTYPE( void SetItem, (MenuHandle, Short item, inStringPtr itemString) );
ROMTRAP(0xA940) _PROTOTYPE( void SetItemIcon, (MenuHandle, Short item, Short icon) );
ROMTRAP(0xA942) _PROTOTYPE( void SetItemStyle, (MenuHandle, Short item, Short chStyle) );
ROMTRAP(0xA944) _PROTOTYPE( void SetItemMark, (MenuHandle, Short item, Short markChar) );
ROMTRAP(0xA93C) _PROTOTYPE( void SetMenuBar, (Handle menuList) );
ROMTRAP(0xA94A) _PROTOTYPE( void SetMenuFlash, (Short count) );
#endif
