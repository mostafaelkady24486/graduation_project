/*
* SPI_Master_F17.c
*
* Created: 2/1/21 5:04:27 PM
* Author : Mostafa
*/

#include "SPI.h"
#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	Uart_Init();
	SPI_InitType MyInit = {Master, MSB};
	SPI_Init(&MyInit);
	SPI_SlaveEN(SPI_PortReg, SS);
	_delay_ms(500);
	Uint8 op = 0;
	Uint8 arr[20];
	Uint8 array[30];
	Uint8 ary[30];
	while (1)
	{
		/*you have to send the number of op twice(to make over write) as the value in SPDR is still stored in it from previous operation*/
		op = Uart_RxChar();//receiving the value from UART

		switch(op){
			/*temperature sensor*/
			case '1':
				LCD_Clear();
				SPI_Tx(0x01);//sending a dummy value to slave to check on it
				_delay_ms(100);
				LCD_Clear();
				LCD_String("temp");
				int  x = SPI_Rx();//receive temperature from slave
				itoa(x,arr,10);
				LCD_Cmd(0xC0);
				LCD_String(arr);
			break;
			/*Motor on */
			/*the motor speeds up gradually*/
			case '2':
				LCD_Clear();
				SPI_Tx(0x02);
				_delay_ms(100);
				LCD_String("Dc Motor on");
				Uint8 data = SPI_Rx();//received value from slave
				itoa(data,array,10);
				LCD_Cmd(0xC0);
				LCD_String("speed:");
				LCD_Cmd(0xC7);
				LCD_String(array);
			break;
			
			/*motor off*/
			/*the motor speed decreases gradually and doesn't stop immediately after you press the key*/
			case '3' :
			
				LCD_Clear();
				SPI_Tx(0x03);
				_delay_ms(100);
				LCD_String("Dc Motor off");
				Uint8 rec = SPI_Rx();
				itoa(rec,ary,10);
				LCD_Cmd(0xC0);
				LCD_String(ary);
			
			break;
			
			/*clearing lcd on both master and slave*/
			case '4':
			LCD_Clear();
			SPI_Tx(0x04);
			_delay_ms(100);
			break;
			
			

		}
		
	}
	

}





















/*if(Uart_RxChar() == '1'){
if (SPI_TxRx(0x01) == 0x55)
{
_delay_ms(100);
}
LCD_String("temp");
}*/


