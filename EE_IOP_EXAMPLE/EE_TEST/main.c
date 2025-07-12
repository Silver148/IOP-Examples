/*/

English:

Testing communication between the EE and the IOP by Silverhacker

Español:

Test de la comunicación entre el EE y el IOP por Silverhacker

/*/
#include <stdio.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <kernel.h>

#define ID_MODULE_FUNC 0x000004329

static SifRpcClientData_t SifRpcClient;

static unsigned char RpcBuffer[0x1000] ALIGNED(64);


void BindRpc()
{
    nopdelay();
    while(SifBindRpc(&SifRpcClient, ID_MODULE_FUNC, 0) < 0 || SifRpcClient.server==NULL) {
        printf("Waiting for IOP module...\n");
    }
}

int CallRpc(int function, void *buffer, int nbytes)
{
    int ret = SifCallRpc(&SifRpcClient, function, 0, buffer, nbytes, RpcBuffer, sizeof(RpcBuffer), NULL, NULL);
    if (ret < 0) {
        printf("RPC call failed: %d\n", ret);
        return -1;
    }
    return ret;
}

int main()
{
    SifInitRpc(0);
    printf("Loading Module...\n");
    int module = SifLoadModule("host:EE_IOP_EXAMPLE.irx", 0, NULL);
    if(module < 0) {
        printf("Failed to load module: %d\n", module);
        return -1;
    }
    printf("Module loaded successfully!\n");
    BindRpc();
    CallRpc(1, NULL, 0);
    SleepThread();
    return 0;
}