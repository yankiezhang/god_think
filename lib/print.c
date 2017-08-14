#include <types.h>

void
putchar(const char c)
{
	const u32 w = 11;
	u32 pos = (80*w+w)*2;

	asm volatile(
	"xorl %%eax, %%eax\n\t"
	"movw $0x010, %%ax\n\t"
	"movw %%ax, %%gs\n\t"
	"movl %0, %%edi\n\t"
	"movb $0x0C, %%ah\n\t"
	"movb $'A', %%al\n\t"
	"movw %%ax, %%gs:(%%edi)\n\t"
	::"r"(pos):"ax","di");
}
