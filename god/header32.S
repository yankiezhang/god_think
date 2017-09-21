#include <sector.h>

.section .text
.code32
	movw	%cs, %ax
	movw	%ax, %ds
	movw	%ax, %es
	jmp	.
