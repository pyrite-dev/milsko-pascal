.PHONY: all clean

all: bindgen

bindgen: bindgen.pas
	fpc -Mobjfpc -Sh bindgen.pas

clean:
	rm -f bindgen bindgen.o
