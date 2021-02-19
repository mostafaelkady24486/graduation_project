/*
* SPI_Master_F17.c
*
* Created: 2/1/21 5:04:27 PM
* Author : Mostafa
*/

#include "SPI.h"



int main(void)
{
	int reciver_from_spi=0 ;
	unsigned short temp = 0;
	char tempString[50];
	Uint8 array[30];
	Uint8 speed1 = 250; 
	Motor_Init(speed1);
	//Servo_Init();
	DIO_Init();
	LCD_Init();
	ADC_Init();
	servo_Init();
	SPI_Init(Slave);
	while (1)
	{
		reciver_from_spi =SPI_Rx() ;
		
		switch (reciver_from_spi)
		{
			/*temperature*/
			case 0x01:
			{LCD_Clear();
				temp = ADC_Read(1);
				temp /= 4;
				itoa(temp,tempString,10);
				LCD_String(tempString);
				//itoa(temp,data,16);
				SPI_Tx(temp);
			}
			break;
			/*motor on */
			/*the motor speeds up gradually*/
			case 0x02 :
			{
				LCD_Clear();
				LCD_String("motor on");
				SetBit(PORTC,5);
				ClearBit(PORTC,6);
				itoa(speed1,array,10);
				LCD_Cmd(0xC0);
				LCD_String("speed");
				LCD_Cmd(0xC6);
				LCD_String(array);
				SPI_Tx(speed1);
				

			}
			break;
			
			
/*motor off*/
/*the motor stops gradually and doesn't stop immediately after you press the key*/
		case 0x03:
		{
			LCD_Clear();
			LCD_String("motor off");
			ClearBit(PORTC,5);
			ClearBit(PORTC,6);
			LCD_Cmd(0xC0);
			LCD_String("speed is 0");
			SPI_Tx(0);
		}
		break;



		case 0x04:
			LCD_Clear();
		break;

	}

   }
}
