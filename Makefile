FPC = fpc -Mobjfpc -Sh -Fusrc

.PHONY: all lib clean

all: lib

bindgen: bindgen.pas
	fpc -Mobjfpc -Sh bindgen.pas

lib: src/mwbind.ppu

src/mwbind.ppu: src/mwbind.pas src/*.inc
	$(FPC) src/mwbind.pas

clean:
	rm -f bindgen bindgen.o src/*.o src/*.ppu
