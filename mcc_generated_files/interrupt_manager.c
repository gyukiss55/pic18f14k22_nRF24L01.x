
#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    RCONbits.IPEN = 0;
}

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1){
        TMR0_ISR();
    }
    if(PIR2bits.BCLIF == 1)
    {
        SSPCON1 &= 0x3F;
        PIR2bits.BCLIF = 0;
    }
    if(PIR1bits.SSPIF){
        spi_rx_data_ready = true;
        PIR1bits.SSPIF = 0;
    }
}
/**
 End of File
*/
