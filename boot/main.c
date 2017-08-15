#include <types.h>
#include <error.h>
#include <print.h>
#include <io.h>

int kernel(void) 
{
	putchar('C');
	readsect((void*)0x0, 1);
	return ERR_NONE;
}

