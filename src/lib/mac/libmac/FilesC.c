#include <mac/Files.h>

/*
 * NOT IN ROM Routines.
 */

QHdrPtr GetVCBQHdr()
{
  extern QHdr VCBQHdr;
  return &VCBQHdr;
}
