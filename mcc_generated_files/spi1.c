
#include "spi1.h"
#include <xc.h>

#define SPI_DIR_SDO TRISCbits.TRISC7
#define SPI_DIR_CLK TRISBbits.TRISB6
#define SPI_DIR_SDI TRISBbits.TRISB4
#define SPI_DIR_CS  TRISCbits.TRISC4

#define SPI_CS LATCbits.LATC4


volatile bool spi_rx_data_ready = false;
//con1 == SSPxCON1, stat == SSPxSTAT, add == SSPxADD, operation == Master/Slave


void SPI1_Initialize(void)
{
    //SPI setup
    SSPCON1bits.SSPEN = 0;
    
    SPI_DIR_SDO = 0;
    SPI_DIR_SDI = 1;
    SPI_DIR_CLK = 0;
    SPI_DIR_CS = 0;
    
    SPI_CS = 1;
    
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
    
    SSPCON1bits.CKP = 1;
    SSPCON1bits.SSPM = 0b0001;
    
    PIE2bits.BCLIE = 1;
//    IPR2bits.BCLIP = 1;
    
    PIE1bits.SSPIE = 1;
//    IPR1bits.SSPIP = 1;

    TRISCbits.TRISC3 = 0;
    SSPCON1bits.SSPEN = 0;
}

bool SPI1_Open(spi1_modes_t spi1UniqueConfiguration)
{
    if(!SSPCON1bits.SSPEN)
    {
        PIR1bits.CCP1IF = 0;
        PIR2bits.BCLIF = 0;
        SSPCON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

void SPI1_Close(void)
{
    SSPCON1bits.SSPEN = 0;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    SSPBUF = data;
    while((!spi_rx_data_ready) && (PIR1bits.SSPIF == 0)) {
        asm ("NOP");
    }
    //printf("SPI1_ExchangeByte %x SSPIF: %d", data, PIR1bits.SSPIF);
    spi_rx_data_ready = false;
    PIR1bits.SSPIF = 0;
    uint8_t ret = SSPBUF;
    //printf(" ret: %x \r\n", ret);
    return ret;
}

void SPI1_ExchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SSPBUF = *data;
        while((!spi_rx_data_ready) && (PIR1bits.SSPIF == 0)) {
            asm ("NOP");
        }
        spi_rx_data_ready = false;
        PIR1bits.SSPIF = 0;
        *data++ = SSPBUF;
    }
}

// Half Duplex SPI Functions
void SPI1_WriteBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI1_ExchangeByte(*data++);
    }
}

void SPI1_ReadBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI1_ExchangeByte(0);
    }
}

void SPI1_WriteByte(uint8_t byte)
{
    SSPBUF = byte;
}

uint8_t SPI1_ReadByte(void)
{
    uint8_t ret = SSPBUF;
    printf("SPI1_ReadByte %d \r\n", ret);
    return ret;
}