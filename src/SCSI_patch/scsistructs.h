#define TIMEOUT (long) 300
#define SCSI_READ '\010'
#define SCSI_WRITE '\012'
#define SCSI_INQUIRY '\022'	/* 0x12 */

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

#define BLOCK0_SIG 0x4552
	
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

#define PARTITION_SIG 0x504D

/* Status bit definitions */
#define VALID_ST (long) 0x00000001		/* Valid partition map entry? */
	/* NOTE:  This status (above) and the next are */
	/* probably misused in this program; I assumed */
	/* that 'valid' meant there was a valid FILE   */
	/* SYSTEM on the partition and 'allocated'     */
	/* meant the partition table entry was in use. */
	/* In actuality, this usage is probably the    */
	/* opposite of what ought to be--valid means   */
	/* the partition map entry is valid, while     */
	/* allocated means the partition is being used.*/
	/* According to Apple, these statuses are only */
	/* used by A/UX; the MINIX driver will (does)  */
	/* also use these for its partitions.          */
#define ALLOC_ST (long) 0x00000002		/* Allocated partition? */
#define INUSE_ST (long) 0x00000004		/* Partition currently in use? */
#define BOOT_ST (long) 0x00000008		/* Partition contains boot info? */
#define READ_ST (long) 0x00000010		/* Partition allows reading? */
#define WRITE_ST (long) 0x00000020		/* Partition allows writing? */
#define PIC_ST (long) 0x00000040		/* Boot code is position independant? */
#define UNUSE_ST (long) 0x00000080		/* Unused */

