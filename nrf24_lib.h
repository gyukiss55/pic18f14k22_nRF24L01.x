/*
 * File:   nrf24_lib.h
 * Author: Noyel Seth (noyelseth@gamil.com)
 */
#ifndef NRF24_LIB_H
#define	NRF24_LIB_H

#include "mcc_generated_files/mcc.h"

/******************************************************************************/
// SPI and GPIO Helper Function.
/******************************************************************************/

#define NRF24L01_CSN_H()            nRF24_CSN_SetHigh()
#define NRF24L01_CSN_L()            nRF24_CSN_SetLow()
#define NRF24L01_CSN_SetOutput()    nRF24_CSN_SetDigitalOutput()
#define NRF24L01_CSN_SetInput()     nRF24_CSN_SetDigitalInput()

#define NRF24L01_CE_H()             nRF24_CE_SetHigh()
#define NRF24L01_CE_L()             nRF24_CE_SetLow()
#define NRF24L01_CE_SetOutput()     nRF24_CE_SetDigitalOutput()
#define NRF24L01_CE_SetInput()      nRF24_CE_SetDigitalInput()

#define SPI_WRITE_BYTE(dt)          SPI1_ExchangeByte(dt)
#define SPI_READ_BYTE(dt)           SPI1_ExchangeByte(dt)
#define SPI_INIT()                  SPI1_Open(SPI1_DEFAULT)

/******************************************************************************/
#define PAYLOAD_BYTES      32 // Sets the bytes to send or read.

// This data type sets the address data pipe 0.
unsigned char ADDRESS_DATA_RXPIPE0[5] = {0xe1,0xe1,0xe1,0xe1,0xe1};
unsigned char ADDRESS_DATA_RXPIPE1[5] = {0xe2,0xe2,0xe2,0xe2,0xe2};
unsigned char ADDRESS_DATA_TXPIPE0[5] = {0xe1,0xe1,0xe1,0xe1,0xe1};

typedef enum{
    NRF24_INIT_OK = 0,
    NRF24_INIT_FAILED = 1
}NRF24_INIT_STATUS;

/******************************************************************************/
// NRF24L01 Operation Modes
/******************************************************************************/
typedef enum {
    RX_MODE = 1,
    TX_MODE = 2
}NRF24_OPERATION_MODE;


/******************************************************************************/
// Register Map.
/******************************************************************************/

#define R_REGISTER          0x00  
#define W_REGISTER          0x20  
#define R_RX_PAYLOAD        0x61  
#define W_TX_PAYLOAD        0xA0  
#define FLUSH_TX            0xE1  
#define FLUSH_RX            0xE2  
#define REUSE_TX_PL         0xE3  

#define NRF24_MEM_CONFIG              0x00  
#define NRF24_MEM_EN_AA               0x01  
#define NRF24_MEM_EN_RXADDR           0x02  
#define NRF24_MEM_SETUP_AW            0x03  
#define NRF24_MEM_SETUP_RETR          0x04  
#define NRF24_MEM_RF_CH               0x05  
#define NRF24_MEM_RF_SETUP            0x06  
#define NRF24_MEM_STATUSS             0x07  
#define NRF24_MEM_OBSERVE_TX          0x08  
#define NRF24_MEM_CD                  0x09  
#define NRF24_MEM_RX_ADDR_P0          0x0A  
#define NRF24_MEM_RX_ADDR_P1          0x0B  
#define NRF24_MEM_RX_ADDR_P2          0x0C  
#define NRF24_MEM_RX_ADDR_P3          0x0D  
#define NRF24_MEM_RX_ADDR_P4          0x0E  
#define NRF24_MEM_RX_ADDR_P5          0x0F  
#define NRF24_MEM_TX_ADDR             0x10  
#define NRF24_MEM_RX_PW_P0            0x11  
#define NRF24_MEM_RX_PW_P1            0x12  
#define NRF24_MEM_RX_PW_P2            0x13  
#define NRF24_MEM_RX_PW_P3            0x14  
#define NRF24_MEM_RX_PW_P4            0x15  
#define NRF24_MEM_RX_PW_P5            0x16  
#define NRF24_MEM_FIFO_STATUS         0x17
#define NRF24_MEM_CMD_NOP             0xFF // No operation (used for reading status register)

#define NRF24_MEM_REGISTER_MASK     0x1F


/******************************************************************************/
// NRF24L01 Functions.
/******************************************************************************/

/**
 * @brief  Write or update value into the Memory Address of NRF24L01
 *
 * @param[in]	mnemonic_addr NRF24L01 Memory Address
 * @param[in]	value NRF24L01 Memory Address's value
 *
 */
void nrf24_write_register(unsigned char mnemonic_addr, unsigned char value);

/**
 * @brief  Read value from the Memory Address of NRF24L01
 *
 * @param[in]	mnemonic_addr NRF24L01 Memory Address
 * 
 * @return      current value of the read NRF24L01 Memory Address
 *
 */
unsigned char nrf24_read_register(unsigned char mnemonic_addr);

/**
 * @brief  Write or update buffer into the Memory Address of NRF24L01
 *
 * @param[in]	mnemonic_addr NRF24L01 Memory Address
 * @param[in]	buffer write buffer data for NRF24L01 Memory Address's value
 * @param[in]	bytes size of the write buffer
 *
 */
void nrf24_write_buff(unsigned char mnemonic_addr, unsigned char *buffer, unsigned char bytes);

/**
 * @brief  Read buffer data from the Memory Address of NRF24L01
 *
 * @param[in]	mnemonic_addr NRF24L01 Memory Address
 * @param[out]	buffer read buffer for read NRF24L01 Memory Address's data
 * @param[in]	bytes size of the read buffer
 *
 */
void nrf24_read_buff(unsigned char mnemonic_addr, unsigned char *buffer, unsigned char bytes);

/**
 * @brief  Initialize NRF24L01 in Tx Operation or Rx Operation Mode
 *
 * @param[in]	mode NRF24L01 Tx/Rx Operation Mode
 * @param[in]	rf_channel NRF24L01 RF channel - radio frequency channel, value from 0 to 127
 * 
 * @return 
 *          NRF24_INIT_OK succesfully Initialize the nRF24
 *          NRF24_INIT_FAILED failed Initialize the nRF24
 * 
 * @Note: NRF24L01 frequency will be (2400 + channel)MHz
 *
 */
NRF24_INIT_STATUS nrf24_rf_init(unsigned char mode, unsigned char rf_channel);

/**
 * @brief  Set the NRF24L01 Operation Mode Tx/Rx
 *
 * @param[in]	mode NRF24L01 Tx/Rx Operation Mode
 *
 */
void nrf24_set_rf_mode(NRF24_OPERATION_MODE mode);

/**
 * @brief  Send Payload to NRF24L01
 *
 * @param[in]	buffer NRF24L01 Send Payload buffer pointer
 *
 */
void nrf24_send_rf_data(unsigned char *buffer);

/**
 * @brief  Receive data availability check
 * 
 * @return  1 if data present
 *          0 if data not present
 *
 */
unsigned char nrf24_is_rf_data_available(void);

/**
 * @brief  Read payload from NRF24L01
 *
 * @param[out]	buffer pointer buffer for receive payload
 *
 */
void nrf24_read_rf_data(unsigned char *buffer);

/**
 * @brief  Set NRF24L01 RF Channel Frequency
 *
 * @param[in]	rf_channel NRF24L01 RF channel - radio frequency channel, value from 0 to 127
 * 
 * @Note: NRF24L01 frequency will be (2400 + rf_channel)GHz
 *
 */
void nrf24_set_channel_frq(unsigned char rf_channel);

/**
 * @brief  Get NRF24L01 RF Channel Frequency
 *
 * @return rf_channel NRF24L01 RF channel - radio frequency channel, value from 0 to 127
 * 
 * @Note: For actual NRF24L01 frequency will be (2400 + rf_channel)GHz
 *
 */
unsigned char nrf24_get_channel_frq(void);

/**
 * @brief  Set NRF24L01 into StandBy-I
 * 
 */
void nrf24_standby_I(void);

/**
 * @brief  Flush the Tx an Rx
 *
 */
void nrf24_flush_tx_rx(void);

/**
 * @brief  Print The NRF24L01 Current Configuration
 *
 */
void nrf24_printf_rf_config(void);


#endif	/* NRF24_LIB_H */

