/*
 * UART.h
 *
 * Created: 1/29/21 11:30:11 AM
 *  Author: Mostafa
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BaudRate 9600

#define DoubleSpeed 0

#if (DoubleSpeed == 0) 
	#define MyUBRR ((F_CPU/(16UL*BaudRate))-1)
#else
	#define MyUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif

void Uart_Init(void);
/*function to send one char*/
void Uart_TxChar(unsigned char data);
/*function to send a string*/
void Uart_TxString(char * string);
/*function to receive char*/
unsigned char Uart_RxChar(void);
#endif /* UART_H_ */