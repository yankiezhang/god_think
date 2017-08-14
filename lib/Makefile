GCC_PREFIX=i386-elf-
GCC=${GCC_PREFIX}gcc
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,${SRC})

INCLUDE=-I../include

GCC_FLAGS=-fno-builtin -Wall -ggdb -m32 -gstabs -nostdinc  -fno-stack-protector ${INCLUDE} -Os -nostdinc -c

%.o: %.c
	${GCC} ${GCC_FLAGS} -c $< -o $@

all: ${OBJ}

clean:
	@echo ${SRC}
	@echo ${OBJ}
	-rm -rf ${OBJ}
