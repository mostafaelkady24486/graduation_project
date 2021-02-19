/*
 * UART.c
 *
 * Created: 1/29/21 11:29:58 AM
 *  Author: Mostafa
 */ 


#include "UART.h"

void Uart_Init(void){
	//Tx & Rx - 1STOP 
	UCSRB = (1<<RXEN)|(1<<TXEN);
	//asynchronous mode- 8BIT
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = (char)MyUBRR;
	UBRRH = (char)(MyUBRR>>8);
}

void Uart_TxChar(unsigned char data){
	//to check if the register is empty
	while(!(UCSRA & (1<<UDRE)));
	//while(((UCSRA>>UDRE)&1
	
	UDR = data;
	
}

void Uart_TxString(char * string){
	unsigned char i = 0;
	while (string[i] != '\0')
	{
		Uart_TxChar(string[i]);
		i++;
	}
}

unsigned char Uart_RxChar(){
	//receive flag
	while(!(UCSRA & (1<<RXC)));
	return UDR;
	
}