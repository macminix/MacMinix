/* Miscellaneous constants used in assembler code. */
#define HCHIGH_MASK	0x0F	/* h/w click mask for low byte of hi word */
#define HCLOW_MASK	0xF0	/* h/w click mask for low byte of low word */
#define TEST1PATTERN	0x55	/* memory test pattern 1 */
#define TEST2PATTERN	0xAA	/* memory test pattern 2 */

/* Magic numbers for color status port. */
#define COLOR_STATUS_PORT	0x3DA
#	define VERTICAL_RETRACE_MASK	0x08

/* 8259 mask bits. */
#define AT_WINI_MASK	0x40	/* (1 << (AT_WINI_IRQ & 0x07)), etc */
#define CLOCK_MASK	0x01
#define ETHER_MASK	0x08
#define FLOPPY_MASK	0x40
#define KEYBOARD_MASK	0x02
#define PRINTER_MASK	0x80
#define RS232_MASK	0x10
#define SECONDARY_MASK	0x08
#define XT_WINI_MASK	0x20

/* Device interrupt acknowledge ports and bits. */
#define CLOCK_ACK_BIT	0x80
#define CLOCK_ACK_PORT	PORT_B

/* Offsets in struct proc. They MUST match proc.h. */
#define P_STACKBASE	0
#define ESREG		0
#define DSREG		2
#define DIREG		4
#define SIREG		6
#define BPREG		8
#define STREG		10	/* hole for another SP */
#define BXREG		12
#define DXREG		14
#define CXREG		16
#define AXREG		18
#define RETADR		20	/* return address for save() call */
#define PCREG		22
#define CSREG		24
#define PSWREG		26
#define SPREG		28
#define SSREG		30
#define P_STACKTOP	32

#if INTEL_32BITS
/* The registers are twice as wide. There are 2 extra segment regs, but
 * these are packed in the double-width es and ds slots.
 */
EAXREG		=	2 * AXREG	/* use "=" to avoid parentheses */
ERETADR		=	2 * RETADR
EPCREG		=	2 * PCREG
ECSREG		=	2 * CSREG
EPSWREG		=	2 * PSWREG
P3_STACKTOP	=	2 * P_STACKTOP
#define P_LDT_SEL	P3_STACKTOP
#define Msize		18
#define SIZEOF_INT	4
#else
#define P_LDT_SEL	P_STACKTOP
#define Msize		12	/* size of a message in 16-bit words */
#define SIZEOF_INT	2
#endif

P_LDT		=	P_LDT_SEL + SIZEOF_INT
P_SPLIMIT	=	P_LDT_SEL + 16	/* 16 is from 2 8-byte descriptors */

/* Macros to handle bitwise complementation cleanly. */
#if ASLD
#define notop(n)	[-[n]-1]
#else
#define notop(n)	(!(n))
#endif /* ASLD */

/* Macros to handle some 286 instructions with asld. */
#if ASLD
#define ESC2		.byte	0x0F	/* escape for some 286 instructions */
#define deflgdt(adr)	ESC2;	add	adr,dx	/* may not be general */
#define deflidt(adr)	ESC2;	add	adr,bx	/* may not be general */
#define deflldt(adr)	ESC2;	addb	adr,dl	/* may not be general */
#define defltrax	ESC2;	.byte	0x00,0xD8
#define defsgdt(adr)	ESC2;	add	adr,ax	/* may not be general */
#define defsidt(adr)	ESC2;	add	adr,cx	/* may not be general */
#define defsldt(adr)	ESC2;	addb	adr,al	/* may not be general */
#define insw		.byte	0x6D
#define outsw		.byte	0x6F
#define popa		.byte	0x61
#define pusha		.byte	0x60
#define pushi8(n)	.byte	0x6A;	.byte	n
#define pushi16(n)	.byte	0x68;	.word	n
#else
#define deflgdt(adr)	lgdt	adr
#define deflidt(adr)	lidt	adr
#define deflldt(adr)	lldt	adr
#define defltrax	ltr	ax
#define defsgdt(adr)	sgdt	adr
#define defsidt(adr)	sidt	adr
#define defsldt(adr)	sldt	adr
#define pushi8(n)	push	#n
#define pushi16(n)	push	#n
#endif /* ASLD */
