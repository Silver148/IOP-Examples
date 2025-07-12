/*/

English:

Example of communication between EE and IOP by Silverhacker

Español:

Ejemplo de comunicación entre el EE y el IOP por Silverhacker

/*/

#include "irx_imports.h"
#define ID_FUNC 0x000004329

static SifRpcDataQueue_t SifDQ;
static SifRpcServerData_t SifData;
static int SifThreadID;

static unsigned char SifServerBuffer[0x1000];

IRX_ID("EEIOP", 1, 0);

static void *print_test(int fuction, void *buffer, int nbytes)
{
    buffer = 0;
    nbytes = 0;

    printf("THIS PRINT IS FROM THE IOP!\n");
    return buffer;
}

void ThreadMain(void *parameters)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(&SifDQ, GetThreadId());
    sceSifRegisterRpc(&SifData, ID_FUNC, print_test, SifServerBuffer, NULL, NULL, &SifDQ);
    sceSifRpcLoop(&SifDQ);
}

int _start()
{
    extern struct irx_export_table _exp_EEIOP;
    if(RegisterLibraryEntries(&_exp_EEIOP) < 0) {
        printf("Failed to register library entries.\n");
        return MODULE_NO_RESIDENT_END;
    }
    iop_thread_t thread;
    thread.attr = TH_C;
    thread.thread = ThreadMain;
    thread.priority = 0x20;
    thread.stacksize = 0x800;
    thread.option = 0;
    SifThreadID = CreateThread(&thread);
    if(SifThreadID < 0) {
        printf("Failed to create thread: %d\n", SifThreadID);
        return MODULE_NO_RESIDENT_END;
    }
    if(StartThread(SifThreadID, NULL) < 0) {
        printf("Failed to start thread: %d\n", SifThreadID);
        return MODULE_NO_RESIDENT_END;
    }

    return MODULE_RESIDENT_END;
}