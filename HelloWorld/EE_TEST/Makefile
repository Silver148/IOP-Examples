EE_BIN = HelloWorldIOP_test.elf
EE_OBJS = main.o
EE_LIBS = -lkernel
EE_CFLAGS = -O2 -Wall

all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS) *.irx

run:
	ps2client execee host:$(EE_BIN)	

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal	