/*
* SPI.c
*
* Created: 2/1/21 5:05:22 PM
*  Author: Mostafa
*/
#include "SPI.h"


void SPI_Init(SPI_StateType state){
	switch (state)
	{
		case Master:
			SPI_SlaveDIS(SPI_PortReg, SS);
			SPI_DataDirReg |= (1<<MOSI)|(1<<SS)|(1<<SCK);
			SPI_DataDirReg &=~ (1<<MISO);
			SPCR |=(1<<SPE)|(1<<MSTR);
		break;
		case Slave:
			SPI_DataDirReg &=~ (1<<MOSI)|(1<<SS)|(1<<SCK);
			SPI_DataDirReg |= (1<<MISO);
			PORTB |= (1<<SS);	//initiate the pull up resistor in the Init  
			SPCR |= (1<<SPE);
		break;
	}
	
}


Uint8 SPI_Tx(Uint8 data){
	SPDR = data;
	while(!(SPSR  & (1<<SPIF)));
	return SPDR;
}


unsigned char SPI_Rx(void){
	return SPDR;
	
}