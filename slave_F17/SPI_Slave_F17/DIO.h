/*
 * DIO.h
 *
 * Created: 1/21/21 11:31:58 PM
 *  Author: Mostafa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

/**/
void DIO_WriteChannel (DIO_ChannelTypes ChannelId, STD_LevelTypes level);
Uint8 DIO_ReadChannel(DIO_ChannelTypes ChannelId);
void DIO_ToggleChannel(DIO_ChannelTypes ChannelId);
void DIO_WritePort(DIO_PortTypes PortId, Uint8 data);
Uint8 DIO_ReadPort(DIO_PortTypes portId);
 


#endif /* DIO_H_ */