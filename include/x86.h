#ifndef _X86_H_
#define _X86_H_

#include <types.h>

#if 0
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

typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

static inline uint8_t inb(uint16_t port) __attribute__((always_inline));
static inline void insl(uint32_t port, void *addr, int cnt) __attribute__((always_inline));
static inline void outb(uint16_t port, uint8_t data) __attribute__((always_inline));

static inline uint8_t
inb(uint16_t port) {
    uint8_t data;
    asm volatile ("inb %1, %0" : "=a" (data) : "d" (port));
    return data;
}

static inline void
insl(uint32_t port, void *addr, int cnt) {
    asm volatile (
            "cld;"
            "repne; insl;"
            : "=D" (addr), "=c" (cnt)
            : "d" (port), "0" (addr), "1" (cnt)
            : "memory", "cc");
}

static inline void
outb(uint16_t port, uint8_t data) {
    asm volatile ("outb %0, %1" :: "a" (data), "d" (port));
}

#endif
