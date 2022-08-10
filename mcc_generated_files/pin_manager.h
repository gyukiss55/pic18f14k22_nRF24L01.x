
#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA1
#define LED_LAT                  LATAbits.LATA1
#define LED_PORT                 PORTAbits.RA1
#define LED_ANS                  ANSELAbits.ANSA1
#define LED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_GetValue()           PORTAbits.RA1
#define LED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set nRF24_CSN aliases
#define nRF24_CSN_TRIS                 TRISCbits.TRISC4
#define nRF24_CSN_LAT                  LATCbits.LAT4
#define nRF24_CSN_PORT                 PORTCbits.RC4
#define nRF24_CSN_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define nRF24_CSN_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define nRF24_CSN_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define nRF24_CSN_GetValue()           PORTCbits.RC4
#define nRF24_CSN_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define nRF24_CSN_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set nRF24_CE aliases
#define nRF24_CE_TRIS                 TRISCbits.TRISC5
#define nRF24_CE_LAT                  LATCbits.LATC5
#define nRF24_CE_PORT                 PORTCbits.RC5
#define nRF24_CE_ANS                  ANSELCbits.ANSC2
#define nRF24_CE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define nRF24_CE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define nRF24_CE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define nRF24_CE_GetValue()           PORTCbits.RC5
#define nRF24_CE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define nRF24_CE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define nRF24_CE_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define nRF24_CE_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)


/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/