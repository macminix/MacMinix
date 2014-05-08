#define GNUMAGIC	0407
#define ACKMAGIC	0x04100301

/*
 * This is a delicate piece of software.
 * Make changes here at your own risk!!!!
 *
 */

#ifdef ACK
/*===========================================================================*
 *				relocate				     *
 *===========================================================================*/
long relocate(hdrp, txt, segsizes)
long *hdrp;
char *txt;
long segsizes[];
{
    register char *text, *p;
    register c;
    register long off, adr;

    if (hdrp[0] == ACKMAGIC) {
      /* Read in relocation info from the exec file and relocate.
       * Relocation info is in GEMDOS format. Only longs can be relocated.
       *
       * The GEMDOS format starts with a long L: the offset to the
       * beginning of text for the first long to be relocated.
       * If L==0 then no relocations have to be made.
       *
       * The long is followed by zero or more bytes. Each byte B is
       * processed separately, in one of the following ways:
       *
       * B==0:
       *	end of relocation
       * B==1:
       *	no relocation, but add 254 to the current offset
       * B==0bWWWWWWW0:
       *	B is added to the current offset and the long addressed
       *	is relocated. Note that 00000010 means 1 word distance.
       * B==0bXXXXXXX1:
       *	illegal
       */

      if (txt) {
        text = txt;
        segsizes[0] = 0;
      }
      else {
        text = (char *)hdrp+hdrp[1];
        segsizes[0] = hdrp[1];
      }

      if (segsizes) {
        segsizes[0] += hdrp[2];
        segsizes[1]  = hdrp[3];
        segsizes[2]  = hdrp[4];
      }
      p = text + hdrp[2] + hdrp[3] + hdrp[4];
      if (*((long *)p) == 0)
    	return(0);	/* ok */
      off = (long)text;
      adr = off + (*(long *)p);
      p += sizeof(long);
    
      for (;;) {
    	*((long *)adr) += (long)off;
    	for (;;) {		/* once per byte */
    		c = *p++ & 0xFF;
    		if (c != 1)
    			break;
    		adr += 254;
    	}
    	if (c == 0)
    		break;
    	if (c & 1)
    		return(-1);	/* error */
    	adr += c;
      }
      return(0);	/* ok */
    }
    return -1;
}
#else
#include <a.out.h>
long relocate(hdrp, txt, segsizes)
struct exec *hdrp;
char  *txt;
long   segsizes[];
{
    struct relocation_info *ptrs[2];
    long   adjust, i, j, sizes[2];
    register struct relocation_info *rel;
    int cnt;
    register char *address;
    char *text, *start[2];
    long datum;
 
    if (hdrp->a_magic == GNUMAGIC) {
      if (hdrp->a_trsize == 0 && hdrp->a_drsize == 0)
          return 0;
  
      if (txt) {
        text = txt;
        segsizes[0] = 0;
      }
      else {
        text = (char *)hdrp + sizeof (*hdrp);
        segsizes[0] = sizeof (*hdrp);
      }

      if (segsizes) {
        segsizes[0] += hdrp->a_text;
        segsizes[1]  = hdrp->a_data;
        segsizes[2]  = hdrp->a_bss;
      }
      start[0] = text;
      start[1] = text + hdrp->a_text;
      sizes[0] = hdrp->a_trsize/sizeof(struct relocation_info);
      sizes[1] = hdrp->a_drsize/sizeof(struct relocation_info);
      ptrs[0] = (struct relocation_info *)
  	  (text+hdrp->a_text+hdrp->a_data+hdrp->a_bss);
      ptrs[1] = (struct relocation_info *)
  	  (text+hdrp->a_text+hdrp->a_data+hdrp->a_bss+hdrp->a_trsize);
      for (i = 0; i < 2; i++) {
        rel = ptrs[i];
        adjust = (long)start[i];
        cnt = sizes[i];
  
        for (j = 0; j < cnt; j++) {
          if (rel->r_extern)
  	  return -1;
  
    	address = (char*) (rel->r_address + adjust);
    
    	switch (rel->r_length) {
    	  case 0:		/* byte */
    	    datum = *address;
    	    break;
    	    
    	  case 1:		/* word */
    	    datum = *(short *)address;
    	    break;
    	    
    	  case 2:		/* long */
    	    datum = *(long *)address;
    	    break;
  
    	  default:
  	    return -1;
          }
    	    
    	switch(rel->r_symbolnum & N_TYPE) {
    	  case N_TEXT:
    	  case N_TEXT+N_EXT:
    	  case N_DATA:
    	  case N_DATA+N_EXT:
    	  case N_BSS:
    	  case N_BSS+N_EXT:
  		datum += (long)text;
    		break;
    	  case N_ABS:
    	  case N_ABS+N_EXT:
    		break;
            default:
  		return -1;
    	}
    
    	if(rel->r_pcrel)
    	     datum -= (long)text;
    
    	switch (rel->r_length) {
    	  case 0:		/* byte */
    	    *address = datum;
    	    break;
    	  case 1:		/* word */
    	    *(short *)address = datum;
    	    break;
    	  case 2:		/* long */
    	    *(long *)address = datum;
    	    break;
    	}
    	rel++;
        }
      }
      hdrp->a_trsize = 0;
      hdrp->a_drsize = 0;
      return 0;
    }
    return -1;
}
#endif
