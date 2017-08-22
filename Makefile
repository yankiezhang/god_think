.PHONY: all

BOOT=boot
GOD=god
IMG_TARGET=${BOOT}/c.img
IMG_GOD=${GOD}/god.img

all: ${IMG_GOD}
	make -C lib
	make -C ${BOOT} all
	dd if=$< of=${IMG_TARGET} bs=512 count=1 oseek=1 conv=notrunc

clean:
	make -C lib clean
	make -C boot clean
