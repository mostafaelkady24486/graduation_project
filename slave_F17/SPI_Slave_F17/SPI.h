/*
 * SPI.h
 *
 * Created: 2/1/21 5:05:32 PM
 *  Author: Mostafa
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <stdlib.h>
#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "Motor_PWM.h"
#include "servo.h"


#define SPI_DataDirReg DDRB
#define SPI_PortReg PORTB

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPI_SlaveEN(Reg, BitNo) (Reg &= ~ (1<<BitNo))
#define SPI_SlaveDIS(Reg, BitNo) (Reg |= (1<<BitNo))

typedef enum{
	Slave=0,
	Master
	}SPI_StateType;
	
void SPI_Init(SPI_StateType state);//for setting master and slave 
unsigned char SPI_Tx(unsigned char data);// flag indicates when the data is completely transfered
Uint8 SPI_Rx(void);

#endif /* SPI_H_ */