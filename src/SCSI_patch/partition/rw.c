/* A simple partitioning program for minix */
/* Read and Write partition map */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

int write_pmap() {
	int chr;
	int error = 0;

	print_pmap();
	check_pmap();
	printf( "Are you sure you want to write this partition table?" );
	chr = readchr();
	if( chr == 'y' || chr == 'Y' ) {
		printf( "Writing block zero...\n" );
		error = phys_write( id, (long) 0, (int) 1, &b0 );
		if( error == 0 ) {
			printf( "Writing partition map...\n" );
			error = phys_write( id, (long) 1, (int) parts, pmap );
			if( error == 0 )
				printf( "Finished successfully!\n" );
		}
		if( error != 0 )
			printf( "Error %d occurred writing to disk.\n", error );
	}
	return error;
}

int read_pmap() {
	int error;

	if( pmap != NULL ) {
		free( pmap );
		pmap = NULL;	
	}
	error = phys_read( id, (long) 0,(int) 1, &b0 );
	if( error != 0 ) {
		fprintf( stderr, "Error %d reading block 0!\n" );
		return error;
	}
	
	if( b0.sig != 0x4552 ) {
		fprintf( stderr, "Error: Block 0 sig = 0x%0X is incorrect.\n", b0.sig );
		fprintf( stderr, "       The disk probably has not been formatted for use\n" );
		fprintf( stderr, "       on a Macintosh computer.  Use the 'F' command to\n" );
		fprintf( stderr, "       format it.\n" );
		return 0;
	}
	
	if( b0.blksize != 512 ) {
		fprintf( stderr, "Error: Block size is not 512 bytes; this disk\n" );
		fprintf( stderr, "       cannot be used by minix.\n" );
		return -1;
	}
		
	pmap = (struct partition *) malloc( sizeof( struct partition ) );
	if( pmap != NULL ) {
		error = phys_read( id, (long)1,(int ) 1, pmap );
		if( error != 0 ) {
			fprintf( "Error %d reading partition map entry #1!\n" );
			free( pmap );
			pmap = NULL;
			return error;
		}
		if( pmap->sig != 0x504D ) {
			fprintf( stderr, "Partition map signature 0x%04X is bad.\n", pmap->sig );
			fprintf( stderr, "This drive probably has not been partitioned.\n" );
			fprintf( stderr, "Use the 'n' command to create a new partition map.\n" );
			free( pmap );
			pmap = NULL;
			return 0;
		}
		parts = pmap->mapblkcnt;
		if( parts + 1 > b0.blkcount ) {
			fprintf( stderr, "Error: Partition map is larger than the disk!\n" );
			free( pmap );
			pmap = NULL;
			return -1;
		}
		free( pmap );
		pmap = (struct partition *) calloc((int) parts, sizeof( struct partition ) );
		if( pmap == NULL ) {
			fprintf( stderr, "Not enough memory to read partition map (%ld entries)!\n", parts );
			if( parts > 20 ) fprintf( stderr, "Use the 'n' command to create a new map.\n" );
			return (parts > 20 ) ? 0 : -1;
		}
		error = phys_read( id,(long) 1,(int) parts, pmap );
		if( error != 0 ) {
			fprintf( stderr, "Error %d reading partition map entries!\n", error );
			free( pmap );
			pmap = NULL;
			return error;
		}
	} else {
		fprintf( stderr, "Nowhere near enough memory!\n" );
		exit ( -1 );
	}
}
