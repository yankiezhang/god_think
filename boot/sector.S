#include <sector.h>

.set bit_cr0_pe_on,		BIT_CR0_PE_ON

.set word_boot_seg,		WORD_BOOT_SEG
.set word_boot_ssize,		WORD_BOOT_SSIZE /*stack size*/
.set word_boot_label,		WORD_BOOT_LABEL
.set word_sel_gdt_code, 	WORD_SEL_GDT_CODE
.set word_sel_gdt_video,	WORD_SEL_GDT_VIDEO

.set quad_gdt_null,		QUAD_GDT_NULL
.set quad_gdt_code,		QUAD_GDT_CODE
.set quad_gdt_video,		QUAD_GDT_VIDEO

.code16
.section .text

_start:
	ljmp	$word_boot_seg, $_entry

.p2align 2
_gdt:
	.quad	QUAD_GDT_NULL
	.quad	QUAD_GDT_CODE
	.quad	QUAD_GDT_VIDEO

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
	movw	$word_boot_ssize, %ax
	movw	%ax,	%sp
	movw	%sp,	%bp


	call	_cls /* clear the screen */

	//NOTE:  load the GDT and enable cr0 for 32 bit
	cli
	lgdt	_gdt_desc
	movl	%cr0,	%eax
	orl	$bit_cr0_pe_on,	%eax
	movl	%eax, %cr0
	ljmp	$word_sel_gdt_code, $_start32

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
	movw	%cs,	%ax
	movw	%ax,	%ds
	movw	%ax,	%es
	movw	%ax,	%fs

	xorl	%eax,	%eax
	movw	$0x010,	%ax
	movw	%ax,	%gs
	movl	$(80 * 11 + 11) * 2,	%edi
	movb	$0x0C,	%ah
	movb	$'A',	%al
	movw	%ax,	%gs:(%edi)
	jmp	.

_msg:
	.ascii	"Hello, world\r\n"
	.equ	_len, . - _msg

_msg_tt:
	.ascii	"TTTTTTTTTTTTTTTtt\r\n"
	.equ	_len_tt, . - _msg_tt

	.org 510
	.word	word_boot_label
