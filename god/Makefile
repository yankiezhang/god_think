.PHONY: all
IMG_TARGET=god.img
SRC=$(wildcard *.S)
SRC+=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(patsubst %.S,%.o,${SRC}))
LIB=
BIN=$(wildcard *.bin)
IMG=$(wildcard *.img)

OBJ_TMP=tmp.o

GCC_PREFIX=i386-elf-
QEMU=qemu-system-x86_64
LD=${GCC_PREFIX}ld
GCC=${GCC_PREFIX}gcc

INCLUDE=-I../include
LD_FLAGS=-Tgod.lds -e 0x0 -m elf_i386 --as-needed
GCC_FLAGS=-fno-builtin -Wall -ggdb -m32 -gstabs -nostdinc  -fno-stack-protector ${INCLUDE} -Os -nostdinc

%.o: %.S
	${GCC} ${GCC_FLAGS} -c $< -o $@

%.o: %.c
	${GCC} ${GCC_FLAGS} -c $< -o $@

${IMG_TARGET}: ${OBJ}
	${LD} ${LD_FLAGS} $^ ${LIB} -o ${OBJ_TMP}
	${LD} ${LD_FLAGS} --oformat binary $^ ${LIB} -o $@

all: ${IMG_TARGET}

clean:
	-rm -rf ${IMG_TARGET} ${wildcard *.o}

