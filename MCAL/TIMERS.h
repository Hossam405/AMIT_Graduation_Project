

#ifndef MCAL_TIMERS_H_
#define MCAL_TIMERS_H_

#include "../MACROS.h"
#include "../Standard_Types.h"
#include "REGISTERS_ADDRESSES.h"

#define T1_NORMAL 0x0000

#define T2_PWM 0x60
#define T2_PRESCALER_CODE 4

void Ti1_Init(uint16 mode);

void Ti2_Init(uint8 mode);
void Ti2_PWM(uint8 duty);
void Ti2_Start();

void ICU_Init();

extern volatile uint16 edge1;
extern volatile uint16 edge2;
extern volatile uint16 fallingEdge;
extern volatile uint8 counter;

#endif /* MCAL_TIMERS_H_ */
