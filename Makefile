.PHONY: all

all: 
	make -C lib
	make -C boot all

clean:
	make -C lib clean
	make -C boot clean
