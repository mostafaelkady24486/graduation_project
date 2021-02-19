/*
 * servo.c
 *
 * Created: 2/18/21 8:34:09 PM
 *  Author: Mostafa
 */ 


#include "servo.h"

#define  MiniAngle 0
#define  MaxAngle 180

#define  MiniCount 250
#define  MaxCount  500

void servo_Init(void){
	DDRD  |= (1<<5);
	TCCR1A |= ((1<<WGM11) | (1<<COM1A1));
	TCCR1B |= ((1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11));
	ICR1   = 4999;
}

void Servo (long angle){
	OCR1A = (((angle-MiniAngle)*(MaxCount-MiniCount))/(MaxAngle-MiniAngle))+ MiniCount - 1 ;
	
}