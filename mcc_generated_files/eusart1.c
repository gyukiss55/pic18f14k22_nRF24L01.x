
/**
  Section: Included Files
*/
#include "eusart1.h"

volatile eusart1_status_t eusart1RxLastError;

/**
  Section: EUSART1 APIs
*/

void (*EUSART1_FramingErrorHandler)(void);
void (*EUSART1_OverrunErrorHandler)(void);
void (*EUSART1_ErrorHandler)(void);

void EUSART1_DefaultFramingErrorHandler(void);
void EUSART1_DefaultOverrunErrorHandler(void);
void EUSART1_DefaultErrorHandler(void);

void EUSART1_Initialize(void)
{
    uint16_t gen_reg = 51;
    uint8_t sync = 0;
    uint8_t brgh = 1;
    uint8_t brg16 = 0;
    
    TRISCbits.RC7=1;
    TRISCbits.RC6=1;
    
    SPBRGH = (gen_reg & 0xFF00) >> 8;
    SPBRG = gen_reg & 0x00FF;
    
    RCSTAbits.CREN = 1;
    RCSTAbits.SPEN = 1;
    BAUDCONbits.BRG16 = brg16;
    
    TXSTAbits.SYNC = sync;
    TXSTAbits.BRGH = brgh;
    TXSTAbits.TXEN = 1;



    EUSART1_SetFramingErrorHandler(EUSART1_DefaultFramingErrorHandler);
    EUSART1_SetOverrunErrorHandler(EUSART1_DefaultOverrunErrorHandler);
    EUSART1_SetErrorHandler(EUSART1_DefaultErrorHandler);

    eusart1RxLastError.status = 0;

}

bool EUSART1_is_tx_ready(void)
{
    return (bool)(PIR1bits.TXIF && TXSTAbits.TXEN);
}

bool EUSART1_is_rx_ready(void)
{
    return (bool)(PIR1bits.RCIF);
}

bool EUSART1_is_tx_done(void)
{
    return TXSTAbits.TRMT;
}

eusart1_status_t EUSART1_get_last_status(void){
    return eusart1RxLastError;
}

uint8_t EUSART1_Read(void)
{
    while(!PIR1bits.RCIF)
    {
    }

    eusart1RxLastError.status = 0;
    
    if(1 == RCSTAbits.OERR)
    {
        // EUSART1 error - restart

        RCSTAbits.CREN = 0; 
        RCSTAbits.CREN = 1; 
    }

    return RCREG1;
}

void EUSART1_Write(uint8_t txData)
{
    while(0 == PIR1bits.TXIF)
    {
    }

    TXREG = txData;    // Write the data byte to the USART.
}

char getch(void)
{
    return EUSART1_Read();
}

void putch(char txData)
{
    EUSART1_Write(txData);
}



void EUSART1_DefaultFramingErrorHandler(void){}

void EUSART1_DefaultOverrunErrorHandler(void){
    // EUSART1 error - restart

    RCSTAbits.CREN = 0;
    RCSTAbits.CREN = 1;

}

void EUSART1_DefaultErrorHandler(void){
}

void EUSART1_SetFramingErrorHandler(void (* interruptHandler)(void)){
    EUSART1_FramingErrorHandler = interruptHandler;
}

void EUSART1_SetOverrunErrorHandler(void (* interruptHandler)(void)){
    EUSART1_OverrunErrorHandler = interruptHandler;
}

void EUSART1_SetErrorHandler(void (* interruptHandler)(void)){
    EUSART1_ErrorHandler = interruptHandler;
}


/**
  End of File
*/
