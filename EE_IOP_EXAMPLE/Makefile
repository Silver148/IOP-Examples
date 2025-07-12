IOP_BIN = EE_IOP_EXAMPLE.irx
IOP_OBJS = main.o imports.o exports.o
IOP_CFLAGS = -O2 -Wall

all: $(IOP_BIN)
	cp $(IOP_BIN) EE_TEST
	$(MAKE) -C EE_TEST

clean:
	rm -f $(IOP_BIN) $(IOP_OBJS) *.elf
	$(MAKE)	-C EE_TEST clean

run:
	$(MAKE) -C EE_TEST run		

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal	