
#include "mcc.h"


void SYSTEM_Initialize(void)
{
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize(); 
    TMR0_Initialize();
    INTERRUPT_Initialize();
    EUSART1_Initialize();
    SPI1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    OSCCONbits.IDLEN = 0;
    OSCCONbits.IRCF = 0x07;//0x01;//0x07;
    OSCCONbits.SCS = 0x03;
}


/**
 End of File
*/
