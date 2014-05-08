#include <mac/Dialogs.h>

/*
 * NOT IN ROM Routines.
 */

#define NOTYET(a,b)

NOTYET( void DlgCut, (DialogPtr dp) );
NOTYET( void DlgCopy, (DialogPtr dp) );
NOTYET( void DlgDelete, (DialogPtr dp) );
NOTYET( void DlgPaste, (DialogPtr dp) );

short GetAlrtStage()
{
   extern short ACount;
   return ACount;
}

void ResetAlrtStage()
{
   extern short ACount;
   ACount = 0;
}

void SetDAFont(fontNum)
short fontNum;
{
   extern short DlgFont;
   DlgFont = fontNum;
}
