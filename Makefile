all:
	$(MAKE) -C HelloWorld
	$(MAKE) -C EE_IOP_EXAMPLE

clean:
	$(MAKE) -C HelloWorld clean
	$(MAKE) -C EE_IOP_EXAMPLE clean	