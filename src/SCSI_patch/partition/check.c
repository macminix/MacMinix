/* A simple partitioning program for minix */
/* Function to check partition map for validity */
/* This function gets a bit difficult to manage and */
/* a bit "far to the right"... */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

void check_pmap() {
	long this;
	long current = -1;
	long next,offset;
	long valid, done;
	int flag, i;

	/* Part 0: Check block zero stuff */
	if( b0.sig != 0x4552 ) {
		fprintf( stderr, "Error: Block 0 signature =0x04X is incorrect.\n", (long)b0.sig );
		fprintf( stderr, "       This disk was probably not formatted on a macintosh\n" );
		fprintf( stderr, "       computer; use the 'f' command to format it.  Skipping\n" );
		fprintf( stderr, "       further checks.\n" );
		return 0;
	}
	if( b0.blksize != 512 ) {
		if( b0.blksize != 128 && b0.blksize != 256 && b0.blksize != 1024 ) {
			fprintf( stderr, "Warning: Block size=%d is not 128, 256, 512, or 1024\n", b0.blksize );
			fprintf( stderr, "         blocks.  Minix cannot think of using this drive.\n" );
		} else {
			fprintf( stderr, "Warning: Block size=%d is not 512 bytes.  Minix currently\n", b0.blksize );
			fprintf( stderr, "         works only if for 512 byte blocks.  Only minor\n" );
			fprintf( stderr, "         changes to the kernel would probably be required.\n" );
		}
	}
	if( b0.blkcount != b0.blkcount & 0xFFE00000 ) {
		fprintf( stderr, "Warning: There are %ld or more blocks on this disk;\n",(long) 1<<21 );
		fprintf( stderr, "         Minix can only use blocks less than block %ld.\n",(long) 1<<21 );
	}
	if( b0.drvrcount > 61 || b0.drvrcount < 0 )
		fprintf( stderr, "Error: The driver count=%ld cannot be correct.\n", b0.drvrcount );
	for( i = 0; i < b0.drvrcount; i++ ) {
		if( b0.dd[i].block + b0.dd[i].size > b0.blkcount )
			fprintf( stderr, "Error: Driver %d extends past end of disk\n", i );
		if( b0.dd[i].block <= 1+b0.drvrcount )
			fprintf( stderr, "Error: Driver %d starts in block 0 or partition table\n", i );
	}
	
	/* Part 1: Check the signature, count fields, individual map entries. */
	valid = 0;
	if( pmap == NULL ) return 0;
	for( this = 0; this < parts; this++ ) {
		if( pmap[this].sig != 0x504D )
			fprintf( stderr, "Error: entry %ld has wrong signature = 0x%04X!\n", this, (pmap +this)->sig );
		if( pmap[this].mapblkcnt != parts )
			fprintf( stderr, "Error: entry %ld has wrong block count =%ld\n", this, (pmap +this)->mapblkcnt );
		if( (pmap[this].partstatus & VALID_ST) && !(pmap[this].partstatus & ALLOC_ST) )
			fprintf( stderr, "Warning: Entry %ld is valid but not allocated.\n", this );
		if( !(pmap[this].partstatus & VALID_ST) && !(pmap[this].partstatus & ALLOC_ST ) )
			fprintf( stderr, "Warning: Entry %ld is neither allocated nor valid.\n", this );
		if( (pmap[this].partstatus & ALLOC_ST) ) {
			valid ++;
			if( strncmp( pmap[this].partype, "Apple_partition_map", 32 ) &&
					strncmp( pmap[this].partype, "Apple_Driver", 32 ) &&
					strncmp( pmap[this].partype, "Apple_Driver43", 32 ) &&
					strncmp( pmap[this].partype, "Apple_MFS", 32 ) &&
					strncmp( pmap[this].partype, "Apple_HFS", 32 ) &&
					strncmp( pmap[this].partype, "Apple_Unix_SVR2", 32 ) &&
					strncmp( pmap[this].partype, "Apple_PRODOS", 32 ) &&
					strncmp( pmap[this].partype, "Apple_Free", 32 ) &&
					strncmp( pmap[this].partype, "Apple_Scratch", 32 ) &&
					strncmp( pmap[this].partype, "Minix_FS", 32 ) &&
					strncmp( pmap[this].partype, "Minix_Boot", 32 ) ) {
				fprintf( stderr, "Warning: Partition %ld has a partition type which I have\n", this );
				fprintf( stderr, "         have never heard of.\n", pmap[this].partype );
			}
			if( pmap[this].partstatus & VALID_ST ) {
				if( (pmap[this].partstatus & BOOT_ST ) && pmap[this].lgbootstart + (pmap[this].bootsize + 511 ) / 512 > pmap[this].partblkcnt )
					fprintf( stderr, "Warning: entry %ld has too much boot code!\n", this );
				if( !( pmap[this].partstatus & READ_ST ) && !(pmap[this].partstatus & WRITE_ST ) )
					fprintf( stderr, "Warning: entry %ld does not allow access!\n", this );
				if( pmap[this].lgdatastart + pmap[this].datacnt > pmap[this].partblkcnt )
					fprintf( stderr, "Warning: entry %ld has too much data space!\n", this );
				if( !strncmp( pmap[this].partype, "Apple_Driver", strlen( "Apple_Driver" ) ) ) {
					/* A driver partition.... */
					if( !(pmap[this].partstatus & BOOT_ST ) ) {
						fprintf( stderr, "Warning: Partition %ld claims to hold a driver, but also\n", this );
						fprintf( stderr, "         claims to have no boot code.\n" );
					}
					if( !(pmap[this].partstatus & READ_ST ) ) {
						fprintf( stderr, "Warning: Partition %ld claims to hold a driver, but also\n", this );
						fprintf( stderr, "         is marked as not readable.\n" );
					}
					/* Search for driver entry in block 0 table */
					flag = 0;
					for( i = 0; i < b0.drvrcount; i++ ) {
						if( b0.dd[i].block >= pmap[this].pypartstart &&
								b0.dd[i].block + b0.dd[i].size < pmap[this].pypartstart + pmap[this].partblkcnt ) {
							if( flag ) {
								fprintf( stderr, "Warning: Two drivers are contained in partition %ld\n", this );
							} else {
								flag = 1;
							}
						}
					}
					if( flag == 0 ) {
						fprintf( stderr, "Warning: Partition %ld claims to contain drivers, but none\n", this );
						fprintf( stderr, "         are present therein.\n" );
					}
					if( pmap[this].bootaddr & (long) 0x01 )
						fprintf( stderr, "Warning: Boot code load address of partition %ld is odd.\n", this );
					if( pmap[this].bootentry & (long) 0x01 )
						fprintf( stderr, "Error: Boot code entry point for partition %ld is odd.\n", this );
				}
			}
			if( pmap[this].pypartstart == 0 ) 
				fprintf( stderr, "Warning: Partition %ld starts with block 0\n", this );
			if( (pmap[this].pypartstart == 1 || pmap[this].pypartstart == 0 ) && current == -1)
				current = this;	/* current gets partition map's own entry */
		}	
	}

	/* Part two: check validity of partion map partition */
	if( current == -1 ) {
		fprintf( stderr, "Error: No entry in partition map for partition map!\n" );
		fprintf( stderr, "       Further checks of map cannot be completed.\n" );
	} else {
		if( strncmp( pmap[current].partype, "Apple_partition_map", 32 ) )
			fprintf( stderr, "Error: Partition map's entry is not of type Apple_partition_map!\n" );
		if( pmap[current].partblkcnt < parts ) {
			fprintf( stderr, "Error: Partition map partition is smaller than partition map.\n" );
			fprintf( stderr, "       DO NOT write this partition map to disk!!\n" );
		}
		if( BOOT_ST & pmap[current].partstatus )
			fprintf( stderr, "Warning: Partition map partition claims to be bootable.\n" );

		/* Part three: Check partitions for overlap and empty spots. */
		done = 0;
		while( done < valid ) {
			flag = 0;
			for( this = 0; this < parts; this++ ) {
				if(this != current && ( pmap[this].partstatus & ALLOC_ST ) ) {
					if(  pmap[this].pypartstart >= pmap[current].pypartstart && 
							( pmap[this].pypartstart < pmap[current].pypartstart + pmap[current].partblkcnt ) ) 
						fprintf( stderr, "Error: Partition %ld overlaps with partition %ld!\n", this, current );
					if( pmap[this].pypartstart == pmap[current].pypartstart + pmap[current].partblkcnt ) {
						if( flag )
							fprintf( stderr, "Error: Partition %ld starts at the same place as %ld!\n", this, next );
						else {
							flag = 1;
							next = this;
						}
					}
				}
			}
			
			if( flag == 0 ) {
				if( pmap[current].pypartstart + pmap[current].partblkcnt > b0.blkcount )
					fprintf( stderr, "Error: Partition %ld extends beyond end of disk!\n", current );
				else if( pmap[current].pypartstart + pmap[current].partblkcnt < b0.blkcount) {
					fprintf( stderr, "Error: Space after partition %ld is not accounted for!\n", current );
					offset = 0xFFFFFFFF;
					next = -1;
					for( this = 0; this < parts; this ++ ) {
						if( ( pmap[this].partstatus & ALLOC_ST ) ) {
							if( (pmap[this].pypartstart > pmap[current].pypartstart + pmap[current].partblkcnt ) &&
									(unsigned long) (pmap[this].pypartstart - pmap[current].pypartstart - pmap[current].partblkcnt) < (unsigned long) offset ) {
								next = this;
								offset = pmap[this].pypartstart - pmap[current].pypartstart + pmap[current].partblkcnt;
							}
						}
					}
					if( next = -1 )
						next = current;
				}
			}
			done++;
			current = next;
		};
	}
}
