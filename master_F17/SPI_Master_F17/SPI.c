/*
* SPI.c
*
* Created: 2/1/21 5:05:22 PM
*  Author: Mostafa
*/
#include "SPI.h"


void SPI_Init(SPI_InitType * MyInit){
	switch (MyInit->state)
	{
		case Master:
		SPI_SlaveDIS(SPI_PortReg, SS);
		SPI_DataDirReg |= (1<<MOSI)|(1<<SS)|(1<<SCK);
		SPI_DataDirReg &=~ (1<<MISO);
		//SPCR |=(1<<SPE)|(1<<MSTR);
		//SPI->MySPCR.AllRegister = 0x50;
		SPI->MySPCR.RegisterBits.MyMSTR = 1;
		SPI->MySPCR.RegisterBits.MySPE = 1;
		break;
		
		case Slave:
		SPI_DataDirReg &=~ (1<<MOSI)|(1<<SS)|(1<<SCK);
		SPI_DataDirReg |= (1<<MISO);
		SPCR |= (1<<SPE);
		break;
	}
	
}

Uint8 SPI_Tx(Uint8 data){
	SPI->MySPDR = data;
	while(!(SPI->MySPSR  & (1<<SPIF)));
	return SPI->MySPDR;
}


unsigned char SPI_Rx(void){
	return SPI->MySPDR;
	
}
