#include <types.h>

size_t
strlen(const char* s) {
	size_t cnt = 0;

	while (*s ++ != '\0') {
	cnt ++;
	}
	return cnt;
}
