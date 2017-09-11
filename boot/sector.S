#include <sector.h>

.code16
.section .text

_start:
	ljmp	$WORD_BOOT_SEG, $_entry

.p2align 2
_gdt:
	.quad	QUAD_GDT_NULL
	.quad	QUAD_GDT_CODE
	.quad	QUAD_GDT_VIDEO
	.quad	QUAD_GDT_DATA
	.quad	QUAD_GDT_GOD_DATA

_gdt_desc:
	.word	_gdt_desc - _gdt - 1
	.long	_gdt + ( WORD_BOOT_SEG << 4 ) /* physical address*/
	
_entry:
	movw	%cs,	%ax
	movw	%ax,	%ds
	movw	%ax,	%es
	movw	%ax,	%ss
	movw	%ax,	%gs

	//NOTE: set the stack size for the boot
	movw	$WORD_BOOT_SSIZE, %ax
	movw	%ax,	%sp
	movw	%sp,	%bp


	call	_cls /* clear the screen */

	//NOTE:  load the GDT and enable cr0 for 32 bit
	cli
	lgdt	_gdt_desc
	movl	%cr0,	%eax
	orl	$BIT_CR0_PE_ON,	%eax
	movl	%eax, %cr0
	ljmp	$WORD_SEL_GDT_CODE, $_start32

	//NOTE: arg0 is the length, arg1 is the address
_print:
	pushw	%bp
	movw	%sp, %bp
	movw	4(%bp),	%ax
	movw	6(%bp),	%cx
	movw	%ax,	%bp

	movw	$0x1301,%ax
	movw	$0x0c,	%bx
	movb	$0x0,	%dl
	int	$0x10
	popw	%bp
	ret

_cls:
	xorw	%ax, %ax
	movw	$0x0600, %ax
	movw	$0x0,	%cx
	movw	$0x6079, %dx
	int	$0x10

	movb	$0x02,	%ah
	movw	$0x0,	%bx
	movw	$0x0,	%dx
	ret

.code32
_start32:
	movw	$WORD_SEL_GDT_DATA, %ax
	movw	%ax,	%ds
	movw	%ax,	%ss
	movw	%ax,	%es

	movl	$WORD_BOOT_SSIZE, %eax
	movl	%eax,	%esp
	movl	%esp,	%ebp

	call	kernel
	jmp	.

_msg:
	.ascii	"Hello, world\r\n"
	.equ	_len, . - _msg

_msg_tt:
	.ascii	"TTTTTTTTTTTTTTTtt\r\n"
	.equ	_len_tt, . - _msg_tt

.section .label
	.word	WORD_BOOT_LABEL
