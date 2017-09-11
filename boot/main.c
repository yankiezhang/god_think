#include <types.h>
#include <error.h>
#include <print.h>
#include <io.h>
#include <sector.h>
#include <reg.h>

int kernel(void) 
{
	putchar('C');
	set_es(WORD_SEL_GDT_GOD);
//	set_ds(WORD_SEL_GDT_GOD);
	readsect((void*)WORD_OFFSET_GOD, 1);
	return ERR_NONE;
}

