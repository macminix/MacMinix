/* A simple partitioning program for minix */
/* Utility functions, global variables */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#define EXTERN	/* Actually declare globals here. */
#include "partition.h"

int readchr() {
	int chr;
	fflush( stdout );
	fflush( stderr );
	for( chr = getchar(); chr == '\012' || chr == '\015'; chr = getchar() );
	return chr;
}
/*==========================================================================*
 *				phys_read, phys_write			    *
 *==========================================================================*/

int phys_read( sid, start, num, buf )
int sid;
long start;		/* Only 20 bits are used */
int num;
char *buf;
{
	char cdb[6];
	long *temp;
	struct SCSIInstr tib[3];
	int err2, err1 = 0;
	int stat, msg;

	printf( "phys_read: id %d sct %ld num %d addr 0x%08lX\n", sid, start, num, (long) buf );
	if( num > 0 && buf != NULL && num <= 256 ) {
		/* Set up cdb, tib */
		temp = (long *)&(cdb[0]);
		*temp = start;
		cdb[0] = SCSI_READ;
		cdb[1] &= (char) 0x1F;
		cdb[4] = (num == 256) ? (char)0 :(char)num;
		cdb[5] = '\0';
	
		tib[0].scOpcode = scNoInc;
		tib[0].scParam1 = (long )buf;
		tib[0].scParam2 = (long )( 512 * num );
		tib[1].scOpcode = scStop;
		tib[1].scParam1 = (long) 0;
		tib[1].scParam2 = (long) 0;

		err1 = SCSIGet();
		if( err1 == 0 ) {
			err1 = SCSISelect( sid );
			if( err1 == 0 ) {
				err1 = SCSICmd( cdb, 6 );
				if( err1 == 0 ) {
					err1 = SCSIRead( tib );
				}
				err2 = SCSIComplete( &stat, &msg,( long ) TIMEOUT );
			}
		}
		if( err1 == 0 ){
			err1 = err2;
			if( err1 == 0 ) err1 = stat;
		}

		return err1;
	} else
		return -1;
}

int phys_write( sid, start, num, buf )
int sid;
long start;		/* Only 20 bits are used */
int num;
char *buf;
{
	char cdb[6];
	struct SCSIInstr tib[3];
	long *temp;
	int err1, err2;
	int stat, msg;
	
	printf( "phys_write: id %d sct %ld num %d addr 0x%08lX\n", sid, start, num, (long) buf );
	if( num > 0 && num <= 256 ) {
		/* Set up cdb, tib */
		temp =(long *) &cdb[0];
		*temp = start;
		cdb[0] = SCSI_WRITE;
		cdb[1] &= (char) 0x1F;
		cdb[4] = (num == 256) ? '\0' : (char )num;
		cdb[5] = '\0';
	
		tib[0].scOpcode = scNoInc;
		tib[0].scParam1 = (long )buf;
		tib[0].scParam2 = (long )(num * 512);
		tib[1].scOpcode = scStop;
		tib[1].scParam1 = 0;
		tib[1].scParam2 = 0;
		
		err1 = SCSIGet();
		if( err1 == 0 ) {
			err1 = SCSISelect( sid );
			if( err1 == 0 ) {
				err1 = SCSICmd( cdb,6 );
				if( err1 == 0 ) {
					err1 = SCSIWrite( tib );
				}	
				err2 = SCSIComplete( &stat, &msg, TIMEOUT );
			}
		}	
		if( err1 == 0 ){
			err1 = err2;
			if( err1 == 0 ) err1 = stat;
		}
		return err1;
	} else
		return -1;
}

long htoi( str )	/* Hex to long */
char *str;
{
	long output = 0;
	while ( 1 ) {
		switch( *str ) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			output = output << 4 + *str - '0';
			break;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
			output = output << 4 + 10 + *str - 'a' ;
			break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
			output = output << 4 + 10 + *str - 'A';
			break;
		default:
			return output;
			break;
		}
	}
}
