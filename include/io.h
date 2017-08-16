#ifndef _IO_H_
#define _IO_H_

#include <x86.h>

#define HD_DATA		0x01F0
#define HD_ERROR	0x01F1
#define HD_NSECTOR	0x01F2
#define HD_SECTOR	0x01F3
#define HD_LCYL		0x01F4	/* hard disk cylinder */
#define HD_HCYL		0x01F5	/* hard disk track */
#define HD_CURRENT	0x01F6	/* d=driver, h=sector */
#define HD_STATUS	0x01F7
#define HD_COMMAND	0x01F7
#define HD_CMD		0x03F6

#define CMD_HD_READ	0x20

void inline readsect(void *dst, u32 secno);

#endif
