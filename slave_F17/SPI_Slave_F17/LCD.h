/*
 * LCD.h
 *
 * Created: 1/26/21 9:57:55 PM
 *  Author: Mostafa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include "util/delay.h"

/*defining the hole portA register which is 8-bit and we only use 4 of them*/
/*the problem here that we told the lcd to access the port directly without using layeredArch property*/
#define LCDPort  DIO_PortA //here we used the layered arch. property


/*defining the RS-RW-E in the included connection on the kit*/
#define RS  DIO_ChannelB1
#define RW  DIO_ChannelB2
#define E   DIO_ChannelB3

void LCD_Init();
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Uint8 data);
void LCD_String(Sint8 * string );//constant data but we can change the address of the pointer
void LCD_CustomeChar(Uint8 loc, Uint8 * msg);
void LCD_StringPos(Sint8 * string , Uint8 line , Uint8 pos);
void LCD_CharPos(Uint8 data, Uint8 line , Uint8 pos);
void LCD_Clear();

#endif /* LCD_H_ */