#include <x86.h>
#include <io.h>

void
readsect(void *dst, u32 secno) {

	u8 cnt = 1; /* read sector size */

	outb(HD_DATA, cnt);	
	outb(HD_SECTOR, (u8)(secno&0x0FF));
	outb(HD_LCYL, (secno>>8)&0x0FF);
	outb(HD_HCYL, (secno>>16)&0x0FF);
	outb(HD_CURRENT, ((secno>>25)&0x0F)|0x0E0);
	outb(HD_COMMAND, CMD_HD_READ);

	insl(HD_DATA, dst, cnt<<9);
}
