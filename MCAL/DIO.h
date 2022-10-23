

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "../MACROS.h"
#include "../Standard_Types.h"
#include "REGISTERS_ADDRESSES.h"

void DIO_SetPinDir(uint8 port, uint8 pin, uint8 dir);
void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value);
void DIO_SetPortValue(uint8 port, uint8 value);

uint8 DIO_GetPort(uint8 port);
uint8 DIO_GetPortValue(uint8 port);

typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
} PORTS;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
} PINS;

#endif /* MCAL_DIO_H_ */
