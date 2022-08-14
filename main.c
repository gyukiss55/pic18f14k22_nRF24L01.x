/*
 * pic18F14K22 nrf24L01 TX/RX
 * File:   pic18F14K22.c
 */
#include "mcc_generated_files/mcc.h"
#include "nrf24_lib.h"
#include <string.h>

NRF24_INIT_STATUS ret;
unsigned char i;
char buffer1[20];
unsigned char bufferTX[32];
unsigned char bufferRX[32];

#define NRF24L01_TX_EX  0
#define NRF24L01_RX_EX  !NRF24L01_TX_EX

void blink_led() {
    LED_Toggle();
}

/*
                         Main application
 */
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    /*
    TRISCbits.TRISC4 = 0;
    TRISBbits.TRISB7 = 0;
    while (1)
    {
        LATBbits.LB7 = !LATBbits.LB7;
        LATCbits.LATC4 = 0;
        LATCbits.LATC4 = 1;
        LATBbits.LATB7 = 1;
        LATBbits.LATB7 = 0;
        LATBbits.LATB7 = 1;
    }
*/
    TMR0_SetInterruptHandler(blink_led);

    printf("Timer0 init Done\r\n");
    
    //while (1)
    //    EUSART1_Write ('U');

    SPI1_Open(SPI1_DEFAULT);
#if NRF24L01_TX_EX
    ret = nrf24_rf_init(TX_MODE, 115); // Tx mode with 2400+115 Ghz RF frq
//    ret = nrf24_rf_init(TX_MODE, 76); // Tx mode with 2400+115 Ghz RF frq
#elif NRF24L01_RX_EX
    ret = nrf24_rf_init(RX_MODE, 115); // Rx mode with 2400+115 Ghz RF frq
//   ret = nrf24_rf_init(RX_MODE, 76); // Rx mode with 2400+115 Ghz RF frq
#endif

    if (ret == NRF24_INIT_OK) {

        printf("###############################################################\r\n");
        printf("NRF24L01 Initialize successful\r\n");
        nrf24_printf_rf_config();
        printf("###############################################################\r\n");
        
        while (1) {
#if NRF24L01_TX_EX
            static char val = 0;
            sprintf((char*)bufferTX, "Hello Arduino %d", val);
            printf("NRF24 Send Data: %s\r\n", bufferTX);
            nrf24_send_rf_data(bufferTX);
            val++;
            __delay_ms(100);
#elif NRF24L01_RX_EX
            while (nrf24_is_rf_data_available()) {
            }
            nrf24_read_rf_data(bufferRX);
            printf("NRF24 Receive Data: %s\r\n", bufferRX);
            for (uint8_t i = 0; i < 32; ++i){
                printf("%d, ", bufferRX[i]);
            }
            printf("\n");
            __delay_ms(10);
#endif
            __delay_ms(100);
        }
    } else {
        printf("###############################################################\r\n");
        printf("Failed Initialize NRF24L01\r\n");
        printf("###############################################################\r\n");
        while (1) {

        }
    }
}
/* ------------------------------------------------------------------------- */

/**
 End of File
 */