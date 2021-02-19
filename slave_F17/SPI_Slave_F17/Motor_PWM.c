/*
 * Motor_PWM.c
 *
 * Created: 2/18/21 5:31:04 PM
 *  Author: Mostafa
 */ 

#include "Motor_PWM.h"

void Motor_Init(unsigned char speed){
	DDRC |= ((1<<5)|(1<<6));
	DDRD |= (1<<5);
	TCCR1A |= (1<<COM1A1) | (1<<WGM10);//FPWM 8 Bit
	TCCR1B |= (1<<WGM12) | (1<<CS11) | (1<<CS10) ; //N= 64
	OCR1A = speed;
}