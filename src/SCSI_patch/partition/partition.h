/* A simple disk partitioning utility for Minix */
/* Defines, structures, global variable EXTERN's */
#ifndef EXTERN
#define EXTERN extern
#endif

/* Some constants... */
#define TIMEOUT 300
#define SCSI_READ '\010'
#define SCSI_WRITE '\012'

/* Some macros... */
#define printf_cmds(c1,m1,c2,m2) printf( "  %-3.3s  %-24.24s%-3.3s  %s\n", c1, m1, c2, m2 )
#define printf_type(p,m) printf( "   %-22.22s   %s Partition\n",p,m )
#define get_numeric(str,lng) gets( temp_buf);printf( str ); fflush(stdout);\
	gets(temp_buf); if( temp_buf[0]!='\0' ) lng = atoi( temp_buf);
#define get_hex(str,lng) gets(temp_buf);printf( str ); fflush(stdout); \
	gets(temp_buf); if( temp_buf[0]!='\0' ) lng = htoi( temp_buf);

/* Some structures... */
struct devdrv {
	unsigned long block;
	unsigned int size;
	int type;
};

struct block0 {
	int sig;
	unsigned int blksize;
	unsigned long blkcount;
	int devtype;
	int devid;
	long data;
	int drvrcount;
	struct devdrv dd[61];
	int pad[3];
};
	
struct partition {
	unsigned int sig;
	unsigned int sigpad;
	unsigned long mapblkcnt;
	unsigned long pypartstart;
	unsigned long partblkcnt;
	char partname[32];
	char partype[32];
	unsigned long lgdatastart;
	unsigned long datacnt;
	long partstatus;
	unsigned long lgbootstart;
	unsigned long bootsize;
	long bootaddr;
	long bootaddr2;
	long bootentry;
	long bootentry2;
	long bootcksum;
	char processor[16];
	int pad[188];
};

/* Status bit definitions */
#define VALID_ST (long) 0x00000001		/* Valid partition map entry? */
#define ALLOC_ST (long) 0x00000002		/* Allocated partition? */
#define INUSE_ST (long) 0x00000004		/* Partition currently in use? */
#define BOOT_ST (long) 0x00000008		/* Partition contains boot info? */
#define READ_ST (long) 0x00000010		/* Partition allows reading? */
#define WRITE_ST (long) 0x00000020		/* Partition allows writing? */
#define PIC_ST (long) 0x00000040		/* Boot code is position independant? */
#define UNUSE_ST (long) 0x00000080		/* Unused */

/* Some globals... */
EXTERN struct partition *pmap ;
EXTERN struct block0 b0 ;
EXTERN long parts ;	/* Only valid if pmap != NULL */
EXTERN int id ;
EXTERN char temp_buf[256];	/* For string input, &c */

/* Some functions... */
void print_help();		/* Done */
void check_pmap();		/* Done; Limited driver table verification */
void print_types();		/* Done */
int print_pmap();		/* Done */
void print_block0();		/* Done */
int delete_entry();		/* Done */
int scrunch_pmap();		/* Done */
int insert_entry();		/* Done */
int print_entry();		/* Done */
int read_pmap();		/* Done */
int phys_read();		/* Done */
int phys_write();		/* Done */
int format_disk();
int update_entry();		/* Done */
int write_pmap();		/* Done */
int new_pmap();
int misc_commands();
long htoi();			/* Done */
