/* A simple partitioning program for minix */
/* Main entry point and top-level menu */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mac/SCSI.h>
#include "partition.h"

int main( argc, argv )
int argc;
char **argv;
{
	int error;
	int cmd;

	/* Init globals */

	pmap = NULL;	
	parts = 0;
	id = -1;

	if( argc != 2 ) {
		fprintf( stderr, "No ID specified.\n" );
		exit( 1 );
	}
	id = atoi( argv[1] );
	if( id < 0 || id > 7 ) {
		fprintf( stderr, "%s = %d is not a valid id.\n", argv[1], id );
	}
	b0.sig = 0x0000;	/* Start with this invalid */
	error = read_pmap();
	if( error != 0 ) exit ( error );
	check_pmap();
	error = print_pmap();
	while( error == 0 ) {
		/* check_pmap(); */
		printf( "Enter command(s):" );
		cmd = readchr();
		printf( "\n\n" );
		switch( cmd ) {
		case 'r':
		case 'R':	/* (Re)read partition map */
			error = read_pmap();
			break;
		
		case 'f':
		case 'F':	/* Format disk */
			error = format_disk();
			break;
			
		case 'n':
		case 'N':	/* New partition map */
			error = new_pmap();
			break;

		case 'p':
		case 'P':	/* print out partition map */
			error = print_pmap();
			break;

		case 'd':
		case 'D':	/* Delete a partition */
			error = delete_entry();
			break;
		
		case 'I':
		case 'i':	/* Insert a partition */
			error = insert_entry();
			break;
		
		case 'U':
		case 'u':	/* Update an entry's name or whatever */
			error = update_entry();
			break;
		
		case 'S':
		case 's':	/* Print out an entry in all its glory */
			error = print_entry();
			break;
		
		case 'w':
		case 'W':	/* Write partition map to disk */
			error = write_pmap();
			break;
			
		case 'q':	/* Quit */
		case 'Q':
		case EOF:
			exit( 0 );
			break;

		case 'h':
		case 'H':
		case '?':	/* Show the help screen */
			print_help();
			break;

		case 't':
		case 'T':	/* List types of partitions */
			print_types();
			break;

		case 'c':
		case 'C':	/* Perform various checks on pmap */
			check_pmap();
			break;

		case 'b':
		case 'B':	/* Dump block 0 information */
			print_block0();
			break;

		case 'm':
		case 'M':	/* Misc. commands */
			error = misc_commands();
			break;

		default:	/* Unexpected input */
			break;
		}
	};
	fprintf( stderr, "Error %d occurred! Exiting!\n", error );
	return error;
}
