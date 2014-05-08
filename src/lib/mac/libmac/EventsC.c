#include <mac/Events.h>

/*
 * NOT IN ROM Routines.
 */

long GetCaretTime() 
{
  extern long DoubleTime;
  return DoubleTime;
}

long GetDblTime()
{
  extern long CaretTime;
  return CaretTime;
}
