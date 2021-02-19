 /*
* DIO_CFG.c
*
* Created: 1/21/21 11:53:05 PM
*  Author: Mostafa
*/

#include "DIO_CFG.h"


const DIO_PinCFG PinCFG[] = {
	//portA
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	//portB
	{Input, STD_Low},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	//portC
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Output, STD_Low},
	{Output, STD_Low},
	{Output, STD_Low},
	//PortD
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Output, STD_Low},
	{Output, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low}
};

void DIO_Init(){
	Uint8 count = 0;
	DIO_PortTypes portx;
	DIO_ChannelTypes ChannelPos;
	for (count=DIO_ChannelA0;count<PINCOUNT;count++){
		portx = count/8;
		ChannelPos = count%8;
		switch(portx){
			case DIO_PortA :
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRA_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRA_Reg,ChannelPos);
			}
			break;
			
			/*port B*/
			case DIO_PortB :
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRB_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRB_Reg,ChannelPos);
			}
			break;
			
			/*portC*/
			case DIO_PortC :
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRC_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRC_Reg,ChannelPos);
			}
			break;
			
			/*portD*/
			case DIO_PortD :
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRD_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRD_Reg,ChannelPos);
			}
			break;
		}
		
	}
	
	
}
