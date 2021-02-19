/*
 * BitMath.h
 *
 * Created: 1/21/2021 11:18:45 AM
 *  Author: Mostafa
 */ 

#ifndef BITMATH_H_
#define BITMATH_H_

/*macro use to set the desired bit by one*/
#define SetBit(Reg, BitNo)    (Reg |=(1<<BitNo))

/*macro used to clear the desired bit to 0*/
#define ClearBit(Reg, BitNo)  (Reg &= ~(1<<BitNo))

/*macro used to toggle bit 0 then 1 then 0...*/
#define ToggleBit(Reg, BitNo)  (Reg ^=(1<<BitNo))

/*macro used to get the value stored in the desired bit*/
#define GetBit(Reg, BitNo)    ((Reg>>BitNo) &1)

#endif /* BITMATH_H_ */