/* A simple partitioning program for minix */
/* Update an entry in any imaginable way */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partition.h"

int update_entry() {
	long entry;
	int chr;

	gets( temp_buf );
	entry = atol( temp_buf );
	if( entry < 0 || entry >= parts ) {
		fprintf( stderr, "Error: Entry number wrong\n" );
		return 0;
	}

	while ( 1 ) {
		printf( "Update entry %ld -- Select an option:\n", entry );
		printf_cmds( "n", "Change name", "t","Change type" );
		printf_cmds( "s", "Change size", "f", "Modify status flags" );
		printf_cmds( "l", "Low-level diddling", "d", "Play with driver table" );
		printf_cmds( "p", "Print partition info", "q", "Quit this menu" );
		printf( "What's your bidding, master?" );
		chr = readchr();
		switch( chr ) {
		case 'n':
		case 'N': 	/* Change Name */
			gets( temp_buf );
			printf( "\nEnter the new name for this partition:" );
			fflush( stdout );
			gets( temp_buf );
			if( strlen( temp_buf ) ) {
				strncpy( pmap[entry].partname, temp_buf, 32 );
				printf( "Name changed.\n" );
			} else {
				printf( "Name left alone.\n" );
			}
			break;
		
		case 't':
		case 'T':	/* Change type */
			gets( temp_buf );
			if( !strncmp( pmap[entry].partype, "Apple_partition_map", 32 ) ) {
				fprintf(stderr,  "\nError: Can't muck with partition map partition.\n" );
			} else {
				printf( "\nEnter the new type for this partition:" );
				fflush( stdout );
				gets( temp_buf );
				if( strlen( temp_buf ) && strncmp( temp_buf, "Apple_partition_map", 32 ) ) {
					strncpy( pmap[entry].partype, temp_buf, 32 );
					printf( "Partition type changed.\n" );
				} else {
					printf( "Partition type unchanged (or thwarted).\n" );
				}
			}
			break;
		case 'p':
		case 'P':
			print_entry( entry );
			break;
	
		case 's':
		case 'S':	/* Change size*/
			printf( "\nNot completed yet.\n" );
			break;

		case 'f':
		case 'F':
			/* Change flags */
			do {
				printf("\n\nYou may set these: (! indicates a dangerous flag/setting):\n" );
				printf_cmds( "v", "set to invalid", "V !", "set to valid" );
				printf_cmds( "a !", "set to deallocated", "A !", "set to allocated" );
				printf_cmds( "m !", "set to not mounted", "M", "set to mounted" );
				printf_cmds( "b !", "set to no boot info", "B !", "set to boot info" );
				printf_cmds( "r !", "set to non-readable", "R", "set to readable" );
				printf_cmds( "w", "set to non-writable", "W", "set to writable" );
				printf_cmds( "p", "set to non-PIC boot", "P !", "set to PIC boot" );
				printf_cmds( "u", "clear unused flag", "U", "set unused flag" );
				printf_cmds( "q", "Quit this menu", "", "" );
				printf( "Current settings: 0x%08X = %c%c%c%c%c%c%c%c\n",( long ) pmap[entry].partstatus,
						(pmap[entry].partstatus & VALID_ST ) ? 'V' : 'v',
						(pmap[entry].partstatus & ALLOC_ST ) ? 'A' : 'a',
						(pmap[entry].partstatus & INUSE_ST ) ? 'M' : 'm',
						(pmap[entry].partstatus & BOOT_ST ) ? 'B' : 'b',
						(pmap[entry].partstatus & READ_ST ) ? 'R' : 'r',
						(pmap[entry].partstatus & WRITE_ST ) ? 'W' : 'w',
						(pmap[entry].partstatus & PIC_ST ) ? 'P' : 'p',
						(pmap[entry].partstatus & UNUSE_ST ) ? 'U' : 'u' );
				chr = readchr();
				switch( chr ) {
				case 'q':
				case 'Q':
					break;
	
				case 'v':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ VALID_ST;
					break;
	
				case 'a':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ ALLOC_ST;
					break;
	
				case 'm':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ INUSE_ST;
					break;
	
				case 'b':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ BOOT_ST;
					break;
	
				case 'r':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ READ_ST;
					break;
	
				case 'w':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ WRITE_ST;
					break;
	
				case 'p':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ PIC_ST;
					break;
	
				case 'u':
					pmap[entry].partstatus &= 0xFFFFFFFF ^ UNUSE_ST;
					break;
	
				case 'V':
					pmap[entry].partstatus |= VALID_ST;
					break;
	
				case 'A':
					pmap[entry].partstatus |= ALLOC_ST;
					break;
	
				case 'M':
					pmap[entry].partstatus |= INUSE_ST;
					break;
	
				case 'B':
					pmap[entry].partstatus |= BOOT_ST;
					break;
	
				case 'R':
					pmap[entry].partstatus |= READ_ST;
					break;
	
				case 'W':
					pmap[entry].partstatus |= WRITE_ST;
					break;
	
				case 'P':
					pmap[entry].partstatus |= PIC_ST;
					break;
	
				case 'U':
					pmap[entry].partstatus |= UNUSE_ST;
					break;
				}
			} while( chr != 'q' && chr != 'Q' && chr != EOF );
	
			break;
	
		case 'l':
		case 'L':	/* Low-level diddling */
				printf( "\n\n WARNING: DANGEROUS POWERS LIE HEREIN.\n" );
				printf(     "-----=============================-----\n" );
			do {
				printf( "You may change:    (Current)    (Units/expected values)\n" );
				printf( "a> pmSig:          0x%04X       [0x504D or 0x5453 (old)]\n", (long) pmap[entry].sig );
				printf( "b> pmMapBlkCnt:    %-12.12ld [num of blocks]\n", pmap[entry].mapblkcnt );
				printf( "c> pmPyPartStart:  %-12.12ld [absolute block]\n", pmap[entry].pypartstart );
				printf( "d> pmPartBlkCnt:   %-12.12ld [num of blocks]\n", pmap[entry].partblkcnt );
				printf( "e> pmLgDataStart:  %-12.12ld [block offset]\n", pmap[entry].lgdatastart );
				printf( "f> pmDataCnt:      %-12.12ld [num of blocks]\n", pmap[entry].datacnt );
				printf( "g> pmLgBootStart:  %-12.12ld [block offset]\n", pmap[entry].lgbootstart );
				printf( "h> pmBootSize:     %-12.12ld [num of bytes]\n", pmap[entry].bootsize );
				printf( "i> pmBootAddr:     0x%08X   [address]\n", pmap[entry].bootaddr );
				printf( "j> pmBootAddr2:    0x%08X   [address]\n", pmap[entry].bootaddr2 );
				printf( "k> pmBootEntry:    0x%08X   [address]\n", pmap[entry].bootentry );
				printf( "l> pmBootEntry2:   0x%08X   [address]\n", pmap[entry].bootentry2 );
				printf( "m> pmBootCksum:    0x%08X   [hex number]\n", pmap[entry].bootcksum );
				printf( "n> pmProcessor:    %-15.15s\n", pmap[entry].processor );
				printf( "Cautiously select one of these, or q to quit submenu:" );
				chr = readchr();
				switch( chr ) {
				case 'a':
				case 'A':	/* pmSig */
					gets( temp_buf );
					printf( "Enter new signature (0x504D is expected): " );
					gets( temp_buf );
					if( *temp_buf != '\0' ) {
						pmap[entry].sig = (int) 0xFFFF & htoi( temp_buf );
						printf( "Signature changed.\n" );
					} else {
						printf( "Signature unchanged.\n" );
					}
					break;
				case 'b':
				case 'B':	/* pmMapBlkCnt */
					get_numeric( "Enter new number of map entries: ", pmap[entry].mapblkcnt );
					break;
				case 'c':
				case 'C':	/* pmPyPartStart */
					get_numeric( "Enter new partition start sector: ", pmap[entry].pypartstart );
					break;
				case 'd':
				case 'D':	/* pmPartBlkCnt */
					get_numeric( "Enter new partition length: ", pmap[entry].partblkcnt );
					break;
				case 'e':
				case 'E':	/* pmLgDataStart */
					get_numeric( "Enter new data start offset: ", pmap[entry].lgdatastart );
					break;
				case 'f':
				case 'F':	/* pmDataCnt */
					get_numeric( "Enter new size of data: ", pmap[entry].datacnt );
					break;
				case 'g':
				case 'G':	/* pmLgBootStart */
					get_numeric( "Enter offset to boot code: ", pmap[entry].lgbootstart );
					break;
				case 'h':
				case 'H':	/* pmBootSize */
					get_numeric( "Enter size of boot code, in BYTES: ", pmap[entry].bootsize );
					break;
				case 'i':
				case 'I':	/* pmBootAddr */
					get_hex( "Enter new boot code load address: 0x", pmap[entry].bootaddr );
					break;
				case 'j':
				case 'J':	/* pmBootAddr2 */
					get_hex( "Enter new alternate load address: 0x", pmap[entry].bootaddr2 );
					break;
				case 'k':
				case 'K':	/* pmBootEntry */
					get_hex( "Enter new boot code entry point: 0x", pmap[entry].bootentry );
					break;
				case 'l':
				case 'L':	/* pmBootEntry2 */
					get_hex( "Enter new alternate entry point: 0x", pmap[entry].bootentry2 );
					break;
				case 'm':
				case 'M':	/* pmBootCksum */
					get_hex( "Enter new boot code checksum: 0x", pmap[entry].bootcksum );
					break;
				case 'n':
				case 'N':	/* pmProcessor */
					gets( temp_buf );
					printf( "Enter new processor type for boot code: " );
					fflush( stdout );
					gets( temp_buf );
					if( strlen( temp_buf ) ) {
						strncpy( pmap[entry].processor, temp_buf, 16 );
					}
					break;
				case 'q':
				case 'Q':	/* quit submenu */
					printf( "You ought to check the partition map...\n" );
					break;
				default:
					printf( "Wrong key pressed!\n" );
					break;
				}
			} while( chr != 'q' && chr != 'Q' );
			break;
	
		case 'd':
		case 'D':	/* Driver stuff */
			printf( "Not done yet.\n" );
			break;
	
		case 'q':
		case 'Q':	/* Exit this menu */
		case EOF:
			return 0;
			break;
		
		default:
			break;
		}
	}
	return 0;
}
