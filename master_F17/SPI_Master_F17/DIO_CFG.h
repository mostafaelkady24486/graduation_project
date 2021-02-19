/*
 * DIO_CFG.h
 *
 * Created: 1/21/21 11:53:20 PM
 *  Author: Mostafa
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct  
{
	DIO_DirTypes ChannelDir;
	STD_LevelTypes Level;
}DIO_PinCFG;

#define PINCOUNT 32

void DIO_Init(void);



#endif /* DIO_CFG_H_ */