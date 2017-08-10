#ifndef _SECTOR_H_
#define _SECOTR_H_

#define BIT_ON			0x1
#define BIT_CR0_PE_ON		BIT_ON

#define WORD_BOOT_SEG		0x07C0
#define WORD_BOOT_SSIZE		0x0FF
#define WORD_BOOT_LABEL		0xAA55
#define WORD_SEL_GDT_CODE	0x08

#define QUAD_GDT_NULL		0x0000000000000000
#define QUAD_GDT_CODE		0x00C09A007C0007FF

#endif
