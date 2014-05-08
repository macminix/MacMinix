#include <mac/Vertical.h>

/*
 * NOT IN ROM Routines.
 */

QHdrPtr GetVBLQHdr()
{
  extern QHdr VBLQueue;
  return &VBLQueue;
}
