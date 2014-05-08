#include <mac/Segments.h>

/*
 * NOT IN ROM Routines.
 */

static AppFile *findidx(index)
short index;
{
  extern Handle AppParmHandle;
  short mess, cnt;
  char *p;

  CountAppFiles(&mess, &cnt);
  if (index > cnt)
    return 0L;

  p = *AppParmHandle;
  p += 2*sizeof(short);
  while (--index) {
    p += 3*sizeof(short);	/* skip ref, ftype, versnum */
    p += *p + 1;		/* skip len, name */
  }
  return (AppFile *)p;
}

void ClrAppFiles(index)
short index;
{
  extern Handle AppParmHandle;
  AppFile *p;

  if (p = findidx(index))
    p->fType = 0;
}

void CountAppFiles(message, count)
short *message;
short *count;
{
  extern Handle AppParmHandle;
  short *p;

  if (GetHandleSize(AppParmHandle) < (2*sizeof(short)))
   return;

  p = (short *)*AppParmHandle;
  *message = *p++;
  *count   = *p;
}

void GetAppFiles(index, theFile)
short index;
AppFile *theFile;
{
  short i,len;
  AppFile *p;

  if (p = findidx(index)) {
    theFile->vRefNum = p->vRefNum;
    theFile->fType = p->fType;
    theFile->versNum = p->versNum;
    len = p->fName[0];
    for (i = 0; i < len; i++) {
      theFile->fName[i] = p->fName[i+1];
    }
    theFile->fName[len] = 0;
  }
}
