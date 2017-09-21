.PHONY: all

BOOT=boot
GOD=god
LIB=lib
IMG_TARGET=${BOOT}/c.img
IMG_GOD=${GOD}/god.img

all:
	make -C ${LIB} 
	make -C ${BOOT} 
	make -C ${GOD}
	dd if=${IMG_GOD} of=${IMG_TARGET} bs=512 count=1 oseek=1 conv=notrunc

clean:
	make -C ${LIB} clean
	make -C ${BOOT} clean
	make -C ${GOD} clean
