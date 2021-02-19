/*
* LCD.c
*
* Created: 1/26/21 9:57:38 PM
*  Author: Mostafa
*/

#include "LCD.h"


void LCD_Init(){
	DIO_WriteChannel(RW, STD_Low);
	DIO_WriteChannel(E, STD_High);
	_delay_ms(20);//first delay more than 15 ms
	LCD_Cmd(0x33);//LCD Init
	_delay_us(100);//third delay more than 100 us
	LCD_Cmd(0x32);//then we send the 3 then the 2 in the initialization of lcd after the delay more than 100 us
	LCD_Cmd(0x28);//function set
	LCD_Cmd(0x06);//entry mode
	LCD_Cmd(0x0C);//display on/of
	LCD_Cmd(0x01);//for clearing the LCD
	_delay_ms(2);
}


void LCD_Cmd(Uint8 cmd){
	Uint8 PortData = 0;
	PortData = DIO_ReadPort(LCDPort);
	//we send the first 3
	PortData = (PortData & 0x0F)|(cmd & 0xF0);//for high Mable
	DIO_WritePort(LCDPort , PortData);
	DIO_WriteChannel(RS, STD_Low);
	DIO_WriteChannel(E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E, STD_High);
	
	_delay_ms(5);//second delay more than 4.1 ms
	
	PortData = DIO_ReadPort(LCDPort);
	//we send the second 3
	PortData = (PortData & 0x0F)|(cmd << 4);// for low Mable
	DIO_WritePort(LCDPort , PortData);
	DIO_WriteChannel(RS, STD_Low);
	DIO_WriteChannel(E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E, STD_High);
	_delay_ms(2);//because the lcd hardware is lagging so we must give it a break
}


void LCD_Char(Uint8 data){
	Uint8 PortData = 0;
	PortData = DIO_ReadPort(LCDPort);
	PortData = (PortData & 0x0F)|(data & 0xF0);//for high Mable
	DIO_WritePort(LCDPort, PortData);
	DIO_WriteChannel(RS, STD_High);
	DIO_WriteChannel(E, STD_Low);
	_delay_ms(100);
	DIO_WriteChannel(E, STD_High);
	
	_delay_ms(5);//second delay more than 4.1 ms
	
	PortData = DIO_ReadPort(LCDPort);
	//we send the second 3
	PortData = (LCDPort & 0x0F)|(data << 4);// for low Mable
	DIO_WritePort(LCDPort, PortData);
	DIO_WriteChannel(RS, STD_High);
	DIO_WriteChannel(E, STD_Low);
	_delay_ms(100);
	DIO_WriteChannel(E, STD_High);
	_delay_ms(2);
	
}

void LCD_String(Sint8 * string ){
	Uint8 i=0;
	/*we will use the null at the end of the string as we don't know the size of the string*/
	while(string[i] != '\0'){
		LCD_Char((Uint8)string[i]);
		i++;
	}
}

void LCD_CustomeChar(Uint8 loc, Uint8 * msg){
	Uint8 i=0;
	if (loc<8)
	{
		LCD_Cmd((0x40 + (loc*8)));
		for (i=0;i<8;i++)
		{
			LCD_Char(msg[i]) ;
		}
	}
}

void LCD_StringPos(Sint8 * string, Uint8 line , Uint8 pos){
	switch (line)
	{
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		LCD_String(string);
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		LCD_String(string);
		break;
	}
}


void LCD_CharPos(Uint8 data, Uint8 line , Uint8 pos){
	switch (line)
	{
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		LCD_Char(data);
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		LCD_Char(data);
		break;
	}
}

void LCD_Clear(){
	LCD_Cmd(0x01);
}