/* A simple partitioning program for minix */
/* Functions to insert and delete partitions */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

int insert_entry() {
	long entry;
	long offset;
	long length;
	char name[32];
	char type[32];
	long i;
	struct partition *new_pmap;

	if( pmap == NULL ) {
		fprintf(stderr, "Error: No partition map loaded.\n" );
		return 0;
	}
	gets( temp_buf );	/* Clear out CR */
	printf( "Insert entry into unused partition number:" );
	gets( temp_buf );
	entry = atol( temp_buf );
	if( entry < 0 || entry >= parts ) {
		fprintf(stderr, "No such partition number!\n" );
		return 0;
	}
	if( strncmp( pmap[entry], "Apple_Free", 32 ) &&
			strncmp( pmap[entry], "Apple_Scratch", 32 ) ) {
		fprintf( stderr, "That partition is already in use.  Delete it first.\n" );
		return 0;
	}

	/* The partition is of a reasonable type */
	/* Go ahead and insert a new partition into it. */

	printf( "Enter offset for new partition (0-%ld):", pmap[entry].partblkcnt );
	fflush( stdout);
	gets( temp_buf );
	offset = atol( temp_buf);
	if( offset < 0 || offset > pmap[entry].partblkcnt ) {
		fprintf( stderr, "Illegal offset entered.\n" );
		return 0;
	}

	printf( "Enter length for new partition (1-%ld):", pmap[entry].partblkcnt - offset );
	fflush( stdout );
	gets( temp_buf );
	length = atol( temp_buf );
	if( length < 1 || length > pmap[entry].partblkcnt - offset ) {
		fprintf( stderr, "Illegal length entered.\n" );
		return 0;
	}

	printf( "Enter the new partition's type (32 chars max):" );
	fflush( stdout );
	gets( temp_buf );
	if( temp_buf[0] == '\0' ) {
		fprintf(stderr, "Error: No type entered!\n" );
		return 0;
	}
	if( !strncmp( temp_buf, "Apple_partition_map", 32 ) ) {
		fprintf( stderr, "Error: Cannot muck with partition map partition.  Use the\n" );
		fprintf( stderr, "       'n' command to create a new partiiton table.\n" );
		return 0;
	}
	strncpy( type, temp_buf, 32 );

	printf( "Enter the new partition's name (32 chars max):" );
	fflush( stdout );
	gets( temp_buf );
	if( temp_buf[0] == '\0' ) {
		if( !strncmp( type, "Minix_FS", 32 ) ) {
			fprintf( stderr, "Error: No name entered for Minix_FS type partition.  You\n" );
			fprintf( stderr, "       must enter a name for the partition, or it will not\n" );
			fprintf( stderr, "       be openable by the disk driver.\n" );
			return 0;
		} else 
			fprintf(stderr, "Warning: No name entered!\n" );
	}
	strncpy( name, temp_buf, 32 );

	/* The data are reasonable. */

	if( offset > 0 ) {
		/* Create a new entry for the first, unused bit of the old partition */
		parts++;
		new_pmap = (struct partition *)realloc(pmap, (int) parts * sizeof( struct partition ) );
		if( new_pmap == NULL ) {
			parts--;
			fprintf( "Error: Out of memory inserting new entry!" );
			return 0;
		} else {
			pmap = new_pmap;
			memcpy( &(pmap[parts-1]), &(pmap[entry]), sizeof( struct partition) );
			pmap[parts - 1].partblkcnt = offset;
			/* These should already pretty much be okay, but...*/
			pmap[parts - 1].partstatus = ALLOC_ST | READ_ST | WRITE_ST;
			pmap[parts - 1].lgdatastart = 0;
			pmap[parts - 1].datacnt = pmap[parts - 1].partblkcnt;
			pmap[parts - 1].lgbootstart = 0;
			pmap[parts - 1].bootsize = 0;
			pmap[parts - 1].bootaddr = 0;
			pmap[parts - 1].bootaddr2 = 0;
			pmap[parts - 1].bootentry = 0;
			pmap[parts - 1].bootentry2 = 0;
			pmap[parts - 1].bootcksum = 0;
			strncpy( pmap[parts - 1].processor, "", 16 );
			/* pmap_changed = 1; */
			printf( "Allocated room for leftover blocks at start of old partition\n" );
		}
	}

	if( offset + length < pmap[entry].partblkcnt ) {
		/* Create a new entry for the last, unused bit of the old partition */
		parts++;
		new_pmap = ( struct partition *) realloc(pmap, (int)(parts * sizeof( struct partition ) ) );
		if( new_pmap == NULL ) {
			parts--;
			fprintf( "Error: Out of memory inserting new entry!" );
			return 0;
		} else {
			pmap = new_pmap;
			memcpy( &(pmap[parts-1]), &(pmap[entry]), sizeof( struct partition ) ) ;
			pmap[parts - 1].pypartstart += offset + length;
			pmap[parts - 1].partblkcnt -= (offset + length);
			/* These should already pretty much be okay, but...*/
			pmap[parts - 1].partstatus = ALLOC_ST | READ_ST | WRITE_ST ;
			pmap[parts - 1].lgdatastart = 0;
			pmap[parts - 1].datacnt = pmap[parts - 1].partblkcnt;
			pmap[parts - 1].lgbootstart = 0;
			pmap[parts - 1].bootsize = 0;
			pmap[parts - 1].bootaddr = 0;
			pmap[parts - 1].bootaddr2 = 0;
			pmap[parts - 1].bootentry = 0;
			pmap[parts - 1].bootentry2 = 0;
			pmap[parts - 1].bootcksum = 0;
			strncpy( pmap[parts - 1].processor, "", 16 );
			/* pmap_changed = 1; */
			printf( "Allocated room for leftover blocks at end of old partition\n" );
		}
	}

	/* Change the data in the partition to what we want. */
	pmap[entry].pypartstart += offset;
	pmap[entry].partblkcnt = length;
	strncpy( pmap[entry].partname, name, 32 );
	strncpy( pmap[entry].partype, type, 32 );
	pmap[entry].partstatus = ALLOC_ST | READ_ST | WRITE_ST;
	pmap[entry].lgdatastart = 0;
	pmap[entry].datacnt = length;
	pmap[entry].lgbootstart = 0;
	pmap[entry].bootsize = 0;
	pmap[entry].bootaddr = 0;
	pmap[entry].bootaddr2 = 0;
	pmap[entry].bootentry = 0;
	pmap[entry].bootentry2 = 0;
	pmap[entry].bootcksum = 0;
	strncpy( pmap[entry].processor, "", 16 );
	printf( "Set data for new partition.\n" );

	/* Reset everybody's count to the new count */

	for( i = 0; i < parts; i++ ) {
		pmap[i].mapblkcnt = parts;
	}
	return 0;
}

int delete_entry() {
	long entry;
	long i;
	int flag;
	int error = 0;

	gets( temp_buf );
	entry = atol( temp_buf) ;
	if( entry >= parts || entry < 0 ) {
		/* Invalid entry number */
		fprintf(stderr,  "Error: No such entry %s=%ld!\n", temp_buf, entry );
		return 0;
	}
	if( !(pmap[entry].partstatus & ALLOC_ST ) ) {
		/* Not valid entry */
		fprintf(stderr,  "Error: Entry %s=%ld is not allocated!\n", temp_buf, entry );
		fprintf(stderr,  "       I cannot delete it...\n" );
		return 0;
	}
	if( !strncmp( pmap[entry].partype, "Apple_partition_map", 32 ) ) {
		/* Partition map partition--don't fiddle with this */
		fprintf(stderr,  "Error: Cannot muck with partition map partition.  Use the\n" );
		fprintf(stderr,  "       'n' command to generate a new map of arbitrary size.\n" );
		return 0;
	}

	if( !strncmp( pmap[entry].partype, "Apple_Free", 32 ) ||
			!strncmp( pmap[entry].partype, "Apple_Scratch", 32 ) ) {
		printf( "Note: Entry %s=%ld is not allocated.\n", temp_buf, entry );
		printf( "      I'll try to fold it with the previous or next partition,\n" );
		printf( "      but I can not delete it entirely.\n" );
	}
	if( !strncmp( pmap[entry].partype, "Apple_Driver", strlen( "Apple_Driver" ) ) ) {
		/* Driver entry--delete from driver table in block zero */
		flag = 0;
		for( i = 0; i < b0.drvrcount; i++ ) {
			if( b0.dd[i].block >= pmap[entry].pypartstart && b0.dd[i].block < pmap[entry].pypartstart + pmap[entry].partblkcnt ) 
				flag = 1 ;
			if( flag == 1 && i < 60 )
				memcpy(&b0.dd[i], &b0.dd[i+1], sizeof( struct devdrv ) );
		}
		if( flag == 1 )
			b0.drvrcount--;
	}

	/* Find previous partition, fold if appropriate */
	/* This folding will not be done for Apple_Scratch vs Apple_Free */
	flag = 0;
	for( i = 0; i < parts; i++ ) {
		if((pmap[i].partstatus & ALLOC_ST ) &&
				 pmap[i].pypartstart + pmap[i].partblkcnt == pmap[entry].pypartstart ) {
			if( ( !strncmp( pmap[i].partype, "Apple_Free", 32 ) &&
					strncmp( pmap[entry].partype, "Apple_Scratch", 32 ) ) ||
					(!strncmp (pmap[i].partype, "Apple_Scratch", 32 ) &&
					strncmp( pmap[entry].partype, "Apple_Free", 32 ) ) ) {
				/* Fold; This is tricky--we combine these two partitions, and set entry=i */
				pmap[i].partblkcnt += pmap[entry].partblkcnt;
				pmap[entry].partstatus &= !(ALLOC_ST | VALID_ST );
				printf( "Partition %ld folded into previous partition (%ld)\n", entry, i );
				entry = i;
				flag = 1;
			}
			i = parts;
		}
	}

	/* Find following partition, fold if appropriate */
	/* This folding will not be done for Apple_Scratch vs Apple_Free */
	for( i = 0; i < parts; i++ ) {
		if( (pmap[i].partstatus & ALLOC_ST ) &&
				 pmap[i].pypartstart == pmap[entry].pypartstart + pmap[entry].partblkcnt ) {
			if( ( !strncmp( pmap[i].partype, "Apple_Free", 32 ) &&
					strncmp( pmap[entry].partype, "Apple_Scratch", 32 ) ) ||
					(!strncmp (pmap[i].partype, "Apple_Scratch", 32 ) &&
					strncmp( pmap[entry].partype, "Apple_Free", 32 ) ) ) {
				/* Fold */
				pmap[i].pypartstart = pmap[entry].pypartstart;
				pmap[i].partblkcnt += pmap[entry].partblkcnt;
				pmap[entry].partstatus &= !(ALLOC_ST | VALID_ST );
				printf( "Partition %ld folded into next partition (%ld)\n", entry, i );
				flag = 1;
			}
			i = parts;
		}
	}

	/* If we didn't fold, this partition should become */
	/* an Apple_Free partition, assuming it isn't already. */
	if( flag == 0 && strncmp( pmap[entry].partype, "Apple_Free", 32) &&
			strncmp( pmap[entry].partype, "Apple_Scratch", 32 ) ) {
		strncpy( pmap[entry].partype, "Apple_Free", 32 );
		strncpy( pmap[entry].partname, "Deleted_Partition", 32 );
		pmap[entry].lgdatastart = 0;
		pmap[entry].datacnt = 0;
		pmap[entry].partstatus = ALLOC_ST | READ_ST | WRITE_ST;
		pmap[entry].lgbootstart = 0;
		pmap[entry].bootsize = 0;
		pmap[entry].bootaddr = 0;
		pmap[entry].bootaddr2 = 0;
		pmap[entry].bootentry = 0;
		pmap[entry].bootentry2 = 0;
		pmap[entry].bootcksum = 0;
		strncpy( pmap[entry].processor, "", 16 );
		printf( "Partition %ld deleted!\n", entry );
	} else {
		error = scrunch_pmap();
	}
	return error;
}

int scrunch_pmap() {
	int error;
	long i;
	long new_parts = 0;
	struct partition *new_pmap;
	/* Remove all deallocated entries, reset partition count */

	for( i = 0; i < parts; i++ ) {
		if( ( pmap[i].partstatus & ALLOC_ST ) ) {
			++new_parts;
		}
	}

	if( new_parts == parts )
		return 0;	/* No scrunch needed. */

	for( i = 0; i < new_parts; i++ ) {
		if( !( pmap[i].partstatus & ALLOC_ST ) ) {
			while( !(pmap[parts - 1].partstatus & VALID_ST ) && !(pmap[parts-1].partstatus & ALLOC_ST ) ) {
				parts--;
			};
			memcpy( &(pmap[i]), &(pmap[parts-1]), sizeof( struct partition ) );
			printf( "Moved entry %ld to spot %ld during scrunch.\n", parts-1, i );
			parts--;
		}
	}

	/* For error check below--move parts to no longer include deallocated entries */
	while( !(pmap[parts - 1].partstatus & VALID_ST ) && !(pmap[parts-1].partstatus & ALLOC_ST ) ) {
		parts--;
	};

	if( parts != new_parts ) {
		fprintf( stderr, "Internal error: scrunch failed, parts=%ld, new_parts=%ld\n", parts, new_parts );
		return -1;
	}

	new_pmap = (struct partition *)realloc(pmap, (int)parts * sizeof( struct partition) );

	if( new_pmap != NULL ) {
		pmap = new_pmap;
	} else {
		fprintf( stderr, "Error: Out of memory in scrunch!  Use chmem to make the\n" );
		fprintf( stderr, "       memory allocation for partition larger--it should be\n" );
		fprintf( stderr, "       at least 8K + 1K per partition to be edited.\n" );
		return -1;
	}

	for( i = 0; i < parts; i++ ) {
		pmap[i].mapblkcnt = parts;
	}
	return 0;
}
