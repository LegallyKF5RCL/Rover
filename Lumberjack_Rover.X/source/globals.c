#include <p24Hxxxx.h>
#include <Generic.h>
#include "../include/globals.h"


volatile WORD_VAL Flags;
unsigned long PR23;
unsigned long PR45;

void InitGlobals(void)
{
    Flags.Val = IDLE;

    PR23 = 0xffffffff;
    PR45 = 0xffffffff;
    
    return;
}
