/*/

English:

Test of the example module "HelloWorld" in the EE

Español:

Test del modulo de ejemplo "HolaMundo" en el EE

/*/

#include <stdio.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <kernel.h>

int main()
{
    SifInitRpc(0);
    printf("Loading Module...\n");
    int module = SifLoadModule("host:HelloWorld.irx", 0, NULL);
    if(module < 0) {
        printf("Failed to load module: %d\n", module);
        return -1;
    }
    printf("Module loaded successfully!\n");
    SleepThread();
    return 0;
}