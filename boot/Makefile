IMG_TARGET=sector.img
SRC=$(wildcard *.S)
SRC+=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(patsubst %.S,%.o,${SRC}))
LIB=$(wildcard ../lib/*.o)
BIN=$(wildcard *.bin)
IMG=$(wildcard *.img)

GCC_PREFIX=i386-elf-
QEMU=qemu-system-x86_64
LD=${GCC_PREFIX}ld
GCC=${GCC_PREFIX}gcc

INCLUDE=-I../include
LD_FLAGS=-Tkernel.lds -e 0x0 -m elf_i386 --as-needed
GCC_FLAGS=-fno-builtin -Wall -ggdb -m32 -gstabs -nostdinc  -fno-stack-protector ${INCLUDE} -Os -nostdinc

%.o: %.S
	${GCC} ${GCC_FLAGS} -c $< -o $@

%.o: %.c
	${GCC} ${GCC_FLAGS} -c $< -o $@

${IMG_TARGET}: ${OBJ}
	${LD} ${LD_FLAGS} $^ ${LIB} -o tmp.o
	${LD} ${LD_FLAGS} --oformat binary $^ ${LIB} -o $@

all: ${IMG_TARGET}
	dd if=$< of=c.img bs=512 count=1 conv=notrunc

check:
	@echo ${SRC}
	@echo ${OBJ}

clean:
	rm sector.img
	-rm -rf ${OBJ} ${BIN} 

