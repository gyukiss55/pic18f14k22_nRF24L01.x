
#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
//    LATE = 0x00;
//    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
//    TRISE = 0x07;
    TRISA = 0b11111111;    // 
    TRISB = 0b00111111;    // 7- UART-TX, 6- SPI_SCLK, 5- UART-RX, 4- SPI_MISO
    TRISC = 0b00011111;  // 7- SPI_MOSI, 6- SPI_SS, 5- CE 
//    TRISD = 0xFF;

    /**
    ANSEL registers
    */
    ANSELH = 0x0;
    ANSEL = 0x0;

    /**
    WPUx registers
    */
 //   WPUB = 0x00;
 //   INTCON2bits.nRBPU = 1;






   
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// Clear global Interrupt-On-Change flag
    INTCONbits.RBIF = 0;
}

/**
 End of File
*/