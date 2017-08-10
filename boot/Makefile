GCC_PREFIX=i386-elf-
QEMU=qemu-system-x86_64
LD=${GCC_PREFIX}ld
GCC=${GCC_PREFIX}gcc

INCLUDE=-I../include

LD_FLAGS=-Ttext 0x0 -e 0x0 --oformat binary -m elf_i386
GCC_FLAGS=-fno-builtin -Wall -ggdb -m32 -gstabs -nostdinc  -fno-stack-protector ${INCLUDE} -Os -nostdinc -c

SRC=$(wildcard *.s)
OBJ=$(patsubst %.s,%.o,${SRC})
BIN=$(wildcard *.bin)
IMG=$(wildcard *.img)

%.o: %.S
	${GCC} ${GCC_FLAGS} -c $< -o $@

%.img: %.o
	${LD} ${LD_FLAGS} $< -o $@

all: sector.img
	${QEMU} -hda $<	

clean:
	-rm -rf ${OBJ} ${BIN} ${IMG}

