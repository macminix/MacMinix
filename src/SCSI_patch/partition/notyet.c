/* A simple partitioning program for minix */
/* Functions which remain to be implemented */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

int format_disk () {
	printf( "Format disk called...routine not yet done\n" );
	return 0;
}

int new_pmap() {
	printf( "New partition table called...routine not yet done\n" );
	return 0;
}

int misc_commands() {
	printf( "This is where some cool utilities will reside:\n" );
	printf( "    o  Driver installation\n" );
	printf( "    o  Saving/restoring partition map to/from a file\n" );
	printf( "    o  Moving partitions (keeping their information intact)\n" );
	printf( "    o  Performing an image copy of a disk\n" );
	printf( "    o  Repairing damaged partition maps (?) \n" );	printf( "    o  Sorting the partition map\n" );
	return 0;
}
