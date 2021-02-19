/*
 * ADC.h
 *
 * Created: 2/15/21 5:34:48 PM
 *  Author: Mostafa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();
/*it's unsigned as the value stored in the register is the value of level of adc not the temp of lm35*/
/*and we send the value of the channel we want to use as there are 5 bits that decide which channel*/
unsigned short ADC_Read(unsigned char channelId);


#endif /* ADC_H_ */