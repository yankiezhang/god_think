IMG_TARGET=sector.img

GCC_PREFIX=
QEMU=qemu-system-x86_64
LD=${GCC_PREFIX}ld
GCC=${GCC_PREFIX}gcc

INCLUDE=-I../include

LD_FLAGS=-Ttext 0x0 -e 0x0 --oformat binary -m elf_i386
GCC_FLAGS=-fno-builtin -Wall -ggdb -m32 -gstabs -nostdinc  -fno-stack-protector ${INCLUDE} -Os -nostdinc -c

SRC=$(wildcard *.S)
SRC+=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(patsubst %.S,%.o,${SRC}))

BIN=$(wildcard *.bin)
IMG=$(wildcard *.img)

%.o: %.S
	${GCC} ${GCC_FLAGS} -c $< -o $@

%.o: %.c
	${GCC} ${GCC_FLAGS} -c $< -o $@

${IMG_TARGET}: ${OBJ}
	${LD} ${LD_FLAGS} $^ -o $@

all: ${IMG_TARGET}
	#${QEMU} -hda $<	
	dd if=$< of=a.img bs=512 count=1 conv=notrunc

check:
	@echo ${SRC}
	@echo ${OBJ}

clean:
	-rm -rf ${OBJ} ${BIN} ${IMG}

