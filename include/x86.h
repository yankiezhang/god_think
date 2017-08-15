#ifndef _X86_H_
#define _X86_H_

#include <types.h>

static inline u8 inb(u16 port) __attribute__((always_inline));
static inline void outb(u16 port, u8 data) __attribute__((always_inline));
static inline void insl(u32 port, void *addr, int cnt) __attribute__((always_inline));

static inline u8
inb(u16 port) {
	u8 data;
	asm volatile("inb %1, %0":"=a"(data):"d"(port));	
	return data;
}

static inline void
outb(u16 port, u8 data) {
	asm volatile("outb %0, %1"::"a"(data), "d"(port));
}

static inline void
insl(u32 port, void *addr, int cnt) {
	asm volatile(
		"cld\r\n"
		"repne\r\n"
		"insl\r\n"
		: "=D" (addr), "=c" (cnt)
		: "d"(port), "0"(addr), "1"(cnt)
		: "memory", "cc");
}

#endif
