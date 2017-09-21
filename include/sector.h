#ifndef _SECTOR_H_
#define _SECOTR_H_

#define BIT_ON			0x1
#define BIT_CR0_PE_ON		BIT_ON


#define WORD_BOOT_SEG		0x07C0
#define WORD_BOOT_SSIZE		0x07FF
#define WORD_BOOT_LABEL		0xAA55

#define WORD_SEL_GDT_CODE	0x08
#define WORD_SEL_GDT_VIDEO	0x10
#define WORD_SEL_GDT_DATA	0x18
#define WORD_SEL_GDT_GOD_DATA	0x20
#define WORD_SEL_GDT_GOD_CODE	0x28

#define WORD_PHY_ADD_GOD	0x10000
#define WORD_OFFSET_GOD		0x00000

//#define WORD_PHY_ADD_GOD       	0x8000
//#define WORD_OFFSET_GOD		((WORD_PHY_ADD_GOD) - ((WORD_BOOT_SEG) << 4 ))

#define QUAD_GDT_NULL		0x0000000000000000
#define QUAD_GDT_CODE		0x00C09A007C0007FF /* 0x7C00 ~ 0x83FF */
#define QUAD_GDT_VIDEO		0x00C0920B80000FFF
#define QUAD_GDT_DATA		0x00C093007C0007FF /* 0x7C00 ~ 0x83FF */
#define QUAD_GDT_GOD_DATA	0x00C09310000007FF /* 0x100000 ~ 0x107FF */
#define QUAD_GDT_GOD_CODE	0x00C09A10000007FF /* 0x100000 ~ 0x107FF */


#endif
