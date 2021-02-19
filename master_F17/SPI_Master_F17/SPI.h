/*
* SPI.h
*
* Created: 2/1/21 5:05:32 PM
*  Author: Mostafa
*/


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "UART.h"
#include <stdlib.h>

#define SPI_DataDirReg DDRB
#define SPI_PortReg PORTB

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPI_SlaveEN(Reg, BitNo) (Reg &= ~ (1<<BitNo))
#define SPI_SlaveDIS(Reg, BitNo) (Reg |= (1<<BitNo))

typedef enum{
	Slave=0,Master
}SPI_StateType;

typedef enum{
	MSB=0,LSB
}SPI_DORDType;//data order types

typedef struct{
	SPI_StateType state;
	SPI_DORDType DataOrder;
}SPI_InitType;

typedef struct{
	unsigned char MySPR :2;
	unsigned char MyCPHA:1;
	unsigned char MyCPOL:1;
	unsigned char MyMSTR:1;
	unsigned char MyDORD:1;
	unsigned char MySPE:1;
	unsigned char MySPIE:1;
}SPI_SPCRBitsType;

typedef union{
	unsigned char AllRegister;
	SPI_SPCRBitsType RegisterBits;
	}SPI_SPCRType;

typedef struct{
	SPI_SPCRType MySPCR;
	unsigned char MySPSR;
	unsigned char MySPDR;
	
}SPI_RegType;

#define SPI  ((volatile SPI_RegType *)0x2D)

void SPI_Init(SPI_InitType * MyInit);//for setting master and slave
unsigned char SPI_Tx(unsigned char data);// flag indicates when the data is completely transfered
Uint8 SPI_Rx(void);
#endif /* SPI_H_ */