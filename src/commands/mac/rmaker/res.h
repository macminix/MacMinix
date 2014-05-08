#define R_DATA		0
#define R_FILE		1
#define R_AOUT		2
#define R_DCMD  	4
#define R_NOSG  	8
#define R_BSS  		16

#define GNUMAGIC	0407
#define ACKMAGIC	0x04100301

/* FROM Inside Mac */

#define mapReadOnly	128
#define mapCompact	64
#define mapChanged	32

#define resSysHeap	64
#define resPurgeable	32
#define resLocked	16
#define resProtected	8
#define resPreload	4
#define resChanged	2

struct res {
  char  type[5];
  short id; 
  char  flags;
  char *file;
  char *name;
  short attr;
  long  size;
  char *data;
};

struct rid {
  char *id;
  char *name;
  int   resattrs; 
};

struct resp {
  struct resp *link;
  struct resp *next;		/* next def */
  struct resp *block;		/* next def in block */
  int type;
};

struct rid *new_rid();
struct resp *new_res();
struct resp *chain_res();
