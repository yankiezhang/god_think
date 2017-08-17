#include <x86.h>
#include <io.h>

static void
waitdisk(void) {
    while ((inb(0x1F7) & 0xC0) != 0x40)
        /* do nothing */;
}

/**
 * @brief	read the sector to the target offset
 * @param [in]	target offset
 * @param [in]	the sector number from zero
 */
void
readsect(void *dst, u32 secno) {

	const int cnt = 1;

	waitdisk();

	outb(HD_NSECTOR, cnt);	
	outb(HD_SECTOR, secno & 0xFF);
	outb(HD_LCYL, secno>>8 & 0xFF);
	outb(HD_HCYL, secno>>16 & 0xFF);
	outb(HD_CURRENT, (secno>>24 & 0xF) | 0xE0);
	outb(HD_COMMAND, CMD_HD_READ);

	waitdisk(); //NOTE: must wait, otherwise the data would be zero

	insl(HD_DATA, dst, 1<<7);
}
