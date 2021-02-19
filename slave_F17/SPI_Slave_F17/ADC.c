/*
 * ADC.c
 *
 * Created: 2/15/21 5:34:36 PM
 *  Author: Mostafa
 */ 

#include "ADC.h"


void ADC_Init(){
	ADMUX |= ((1<<REFS1) | (1<<REFS0));//internal voltage reference
	ADCSRA |= ((1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));//ADC enable - 128 prescaller
	
}
unsigned short ADC_Read(unsigned char channelId){
	unsigned short data = 0;
	/*clearing the 5 bits in ADMUX */
		/*
	ADMUX	   1101  1101
	&		   
			   1110  0000
			   ===========
			  (1100  0000)
			   ===========
	channelId  0010  1000
			  &
			   0001  1111
			   ==========
	channelID  0000  1000
			&
			  (1100  0000)
			   ===========
			   1100  1000	
	
	*/
	ADMUX = (ADMUX & 0b11100000)|(channelId & 0b00011111 );
	/*start conversion*/
	ADCSRA |= (1<<ADSC);
	/*flag for finish conversion */
	while(!(ADCSRA & (1<<ADIF)));
	//while((ADCSRA & (1<<ADIF)) == 0);
	//while(((ADCSRA >>ADIF) & 1) == 0);
	/*for 10 bit resolution*/
	data = ADCL;
	data |= (ADCH<<8);
	return data;
}