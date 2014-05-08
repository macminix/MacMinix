/* A simple partitioning program for minix */
/* Functions to dump out various data structures */
/* and other big blocks of output */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

void print_help() {
	printf( "Commands are (# = partition number):\n" );
	printf_cmds( "d #", "Delete an entry", "r", "Read (forget changes)");
	printf_cmds( "i", "Insert an entry", "s #", "Show entry details" );
	printf_cmds( "p", "Print partitions", "u #", "Update an entry" );
	printf_cmds( "q", "Quit (no save)", "n", "New partition map");
	printf_cmds( "h", "Show help", "c", "Check partition map" );
	printf_cmds( "f", "Format a disk", "w", "Write the table" );
	printf_cmds( "t", "Show partition types", "b", "Print Block 0" );
	printf_cmds( "m", "Miscellaneous commands", "", "" );
}

void print_types() {
	printf( "Partition types are:\n" );
	printf_type( "Apple_partition_map","The partition map" );
	printf_type( "Apple_Driver","A SCSI Disk Driver" );
	printf_type( "Apple_Driver43", "A new SCSI Disk Driver" );
	printf_type( "Apple_MFS", "An (ancient) MFS" );
	printf_type( "Apple_HFS", "A MacOS (HFS)" );
	printf_type( "Apple_Unix_SVR2", "An AU/X" );
	printf_type( "Apple_PRODOS", "An Apple ][ PRODOS" );
	printf_type( "Apple_Free", "An unused" );
	printf_type( "Apple_Scratch", "An empty" );
	printf_type( "Minix_Boot", "A Minix Kernel" );
	printf_type( "Minix_FS", "A Minix File System" );
}

int print_pmap() {
	long i;
	
	if( pmap != NULL ) {
		printf( "Partition map for dev=%d (%ld blocks of %d bytes):\n", id, b0.blkcount, b0.blksize );
		printf( "Number Type                             Start      Size\n" );
		printf( "       Name                             Flags\n" );
		printf( "===============================================================\n" );
		/*
		printf( "1...5...10...15...20...25...30...35...40...45...50...55...60.63 " );
		printf( "123456 12345678901234567890123456789012 1234567890 1234567890\n" );
		printf( "       12345678901234567890123456789012 alc mnt boot rd wrt pic" ); */
		
		for( i = 0; i < parts; i++ ) {
			if( pmap[i].partstatus & ALLOC_ST ) {
				printf( "%6.6ld %-32.32s %-10.10ld %-10.10ld\n", i, pmap[i].partype, pmap[i].pypartstart, pmap[i].partblkcnt );
				printf( "       %-32.32s %s %s %s %s %s %s\n", pmap[i].partname,
						(pmap[i].partstatus & (VALID_ST) ) ? "vld" : "   ",
						(pmap[i].partstatus & (INUSE_ST) ) ? "mnt" : "   ",
						(pmap[i].partstatus & (BOOT_ST) ) ? "boot" : "    ",
						(pmap[i].partstatus & (READ_ST) ) ? "rd" : "  ",
						(pmap[i].partstatus & (WRITE_ST) ) ? "wrt" : "   ",
						(pmap[i].partstatus & (PIC_ST) ) ? "pic" : "" );
			}
		}
	} else {
		printf( "No partition map loaded!\n" );
	}
	return 0;
}

int print_entry() {
	long entry;
	
	if( pmap == NULL ) {
		fprintf( stderr, "No partition map in memory!\n" );
		return 0;
	}
	gets( temp_buf );
	entry = atol( temp_buf );
	if( entry >= parts ) entry = parts - 1;
	
	printf( "\nDevice ID %d, Partition #%ld:\n", id, entry );
	/*                111111111122222222223333333333444444444455555555556666 */
	/*       123456789012345678901234567890123456789012345678901234567890123 */
	printf( "pmSig:        0x%04X           (Should be 0x504D)\n",(long)pmap[entry].sig );
	printf( "pmSigPad:     0x%04X           pmMapBlkCnt:   %ld\n",(long)pmap[entry].sigpad,pmap[entry].mapblkcnt);
	printf( "pmPyPartStart:%-10.10ld       pmPartBlkCnt:  %ld\n", pmap[entry].pypartstart, pmap[entry].partblkcnt );
	printf( "pmPartName:   %-32.32s\npmParType:    %-32.32s\n", pmap[entry].partname, pmap[entry].partype );
	printf( "pmLgDataStart:%-10.10ld       pmDataCnt:     %ld\n", pmap[entry].lgdatastart, pmap[entry].datacnt );
	printf( "pmPartStatus: %sValid %sAllocated %sInUse %sBoot\n              %sRead %sWrite %sPICBoot Unused=%s  [0x%08lX]\n",
			( pmap[entry].partstatus & (VALID_ST) ) ? "  " : "In" ,
			( pmap[entry].partstatus & (ALLOC_ST) ) ? "  " : "De" ,
			( pmap[entry].partstatus & (INUSE_ST) ) ? "   " : "Not" ,
			( pmap[entry].partstatus & (BOOT_ST) ) ? "  " : "No" ,
			( pmap[entry].partstatus & (READ_ST) ) ? "  " : "No" ,
			( pmap[entry].partstatus & (WRITE_ST) ) ? "  " : "No" ,
			( pmap[entry].partstatus & (PIC_ST) ) ? "   " : "Not" ,
			( pmap[entry].partstatus & (UNUSE_ST) ) ? "1" : "0" ,
			pmap[entry].partstatus );
	printf( "pmLgBootStart:%-10.10ld       pmBootSize:    %ld\n", pmap[entry].lgbootstart, pmap[entry].bootsize );
	printf( "pmBootAddr:   0x%08lX       pmBootAddr2:   0x%08lX\n", pmap[entry].bootaddr, pmap[entry].bootaddr2 );
	printf( "pmBootEntry:  0x%08lX       pmBootEntry2:  0x%08lX\n", pmap[entry].bootentry, pmap[entry].bootentry2 );
	printf( "pmBootCksum:  0x%08lX       pmProcessor:   %-16s\n", pmap[entry].bootcksum, pmap[entry].processor );
	
	return 0;
}

void print_block0() {
	int i;

	if( pmap == NULL ) {
		fprintf( "No partition table loaded!\n" );
	} else {
		printf( "Driver Descriptor Record for dev=%d:\n", id );
		printf( "sbSig:        0x%04X           (should be 0x4552)\n",(long) b0.sig );
		printf( "sbBlkSize:    %-5d            sbBlkCount:    %ld\n", b0.blksize, b0.blkcount );
		printf( "sbDevType:    0x%04X           sbDevId:       0x%04X\n", (long) b0.devtype, (long) b0.devid );
		printf( "sbData:       0x%08X       sbDrvrCount:   %d\n",b0.data, b0.drvrcount );
		for( i = 0; i < b0.drvrcount; i++ ) {
			printf( "  ddBlock: %-10ld   ddSize: %-5d   ddType: %d\n", b0.dd[i].block, b0.dd[i].size, b0.dd[i].type );
		}
	}
}
