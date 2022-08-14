# 1 "mcc_generated_files/drivers/spi_master.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/Apoca/.mchp_packs/Microchip/PIC18F-K_DFP/1.6.125/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "mcc_generated_files/drivers/spi_master.c" 2
# 33 "mcc_generated_files/drivers/spi_master.c"
# 1 "mcc_generated_files/drivers/spi_master.h" 1
# 37 "mcc_generated_files/drivers/spi_master.h"
# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 1 3
# 13 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef signed char int8_t;






typedef signed int int16_t;







typedef __int24 int24_t;







typedef signed long int int32_t;







typedef signed long long int int64_t;







typedef unsigned char uint8_t;





typedef unsigned int uint16_t;






typedef __uint24 uint24_t;






typedef unsigned long int uint32_t;






typedef unsigned long long int uint64_t;
# 88 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_least8_t;







typedef signed int int_least16_t;
# 109 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_least24_t;
# 118 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef signed long int int_least32_t;
# 127 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef signed long long int int_least64_t;
# 136 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_least8_t;






typedef unsigned int uint_least16_t;
# 154 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_least24_t;







typedef unsigned long int uint_least32_t;







typedef unsigned long long int uint_least64_t;
# 181 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_fast8_t;






typedef signed int int_fast16_t;
# 200 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_fast24_t;







typedef signed long int int_fast32_t;







typedef signed long long int int_fast64_t;







typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
# 240 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_fast24_t;






typedef unsigned long int uint_fast32_t;






typedef unsigned long long int uint_fast64_t;
# 263 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef int64_t intmax_t;
# 278 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef uint64_t uintmax_t;
# 289 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 3
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 37 "mcc_generated_files/drivers/spi_master.h" 2

# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdbool.h" 1 3
# 38 "mcc_generated_files/drivers/spi_master.h" 2

# 1 "mcc_generated_files/drivers/../spi1.h" 1








# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 1 3



# 1 "C:/Users/Apoca/.mchp_packs/Microchip/PIC18F-K_DFP/1.6.125/xc8\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 4 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 2 3

# 1 "C:/Users/Apoca/.mchp_packs/Microchip/PIC18F-K_DFP/1.6.125/xc8\\pic\\include\\__null.h" 1 3
# 5 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 2 3






# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdarg.h" 1 3






typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);
# 11 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 2 3
# 43 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 3
struct __prbuf
{
 char * ptr;
 void (* func)(char);
};
# 85 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 3
# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\conio.h" 1 3







# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\errno.h" 1 3
# 29 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\errno.h" 3
extern int errno;
# 8 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\conio.h" 2 3




extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);



extern char * cgets(char *);
extern void cputs(const char *);
# 85 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 2 3



extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);
# 180 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdio.h" 3
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);
# 9 "mcc_generated_files/drivers/../spi1.h" 2

# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdint.h" 1 3
# 10 "mcc_generated_files/drivers/../spi1.h" 2

# 1 "E:\\Program Files\\Microchip\\xc8\\v2.36\\pic\\include\\c90\\stdbool.h" 1 3
# 11 "mcc_generated_files/drivers/../spi1.h" 2



typedef enum {
    MASTER0_CONFIG,
    SPI1_DEFAULT
} spi1_modes_t;

void SPI1_Initialize(void);
_Bool SPI1_Open(spi1_modes_t spi1UniqueConfiguration);
void SPI1_Close(void);
uint8_t SPI1_ExchangeByte(uint8_t data);
void SPI1_ExchangeBlock(void *block, size_t blockSize);
void SPI1_WriteBlock(void *block, size_t blockSize);
void SPI1_ReadBlock(void *block, size_t blockSize);
void SPI1_WriteByte(uint8_t byte);
uint8_t SPI1_ReadByte(void);
# 39 "mcc_generated_files/drivers/spi_master.h" 2






typedef enum {
    MASTER0
} spi_master_configurations_t;





typedef struct { void (*spiClose)(void);
                    _Bool (*spiOpen)(void);
                    uint8_t (*exchangeByte)(uint8_t b);
                    void (*exchangeBlock)(void * block, size_t blockSize);
                    void (*writeBlock)(void * block, size_t blockSize);
                    void (*readBlock)(void * block, size_t blockSize);
                    void (*writeByte)(uint8_t byte);
                    uint8_t (*readByte)(void);
                    void (*setSpiISR)(void(*handler)(void));
                    void (*spiISR)(void);
} spi_master_functions_t;

extern const spi_master_functions_t spiMaster[];

_Bool spi_master_open(spi_master_configurations_t config);
# 33 "mcc_generated_files/drivers/spi_master.c" 2


_Bool MASTER0_open(void);

const spi_master_functions_t spiMaster[] = {
    { SPI1_Close, MASTER0_open, SPI1_ExchangeByte, SPI1_ExchangeBlock, SPI1_WriteBlock, SPI1_ReadBlock, SPI1_WriteByte, SPI1_ReadByte, (0), (0) }
};

_Bool MASTER0_open(void){
    return SPI1_Open(MASTER0_CONFIG);
}
# 56 "mcc_generated_files/drivers/spi_master.c"
_Bool spi_master_open(spi_master_configurations_t config){
    switch(config){
        case MASTER0:
            return MASTER0_open();
        default:
            return 0;
    }
}
