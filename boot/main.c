#include <types.h>
#include <error.h>
#include <print.h>
#include <io.h>
#include <sector.h>

int kernel(void) 
{
	putchar('C');
	readsect((void*)WORD_OFFSET_GOD, 1);
	return ERR_NONE;
}

