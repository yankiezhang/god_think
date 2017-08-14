#include <types.h>
#include <error.h>
#include <print.h>

int kernel(void) 
{
	putchar('A');
	return ERR_NONE;
}

