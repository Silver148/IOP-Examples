/*/

English:

Example of "Hello World" on the IOP by Silverhacker

Español:

Ejemplo de "Hola Mundo" en el IOP por Silverhacker

/*/

#include "irx_imports.h"

IRX_ID("HelloWorld", 1, 0);

int _start()
{
    sceSifInitRpc(0);
    printf("Hello World from IOP!\n");
    return MODULE_NO_RESIDENT_END;
}