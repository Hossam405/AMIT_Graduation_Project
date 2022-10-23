

#ifndef MCAL_REGISTERS_ADDRESSES_H_
#define MCAL_REGISTERS_ADDRESSES_H_

#define SREG 			*((volatile uint16*) 0x5F)
#define TIMSK 			*((volatile uint16*) 0x59)
#define TIFR 			*((volatile uint16*) 0x58)

#define SPH 			*((volatile uint16*) 0x5E)
#define SPL 			*((volatile uint16*) 0x5D)

#define TCCR0 			*((volatile uint16*) 0x53)
#define TCNT0 			*((volatile uint16*) 0x52)
#define OCR0 			*((volatile uint16*) 0x5C)

#define TCCR1 			*((volatile uint16*) 0x4E)
#define TCNT1 			*((volatile uint16*) 0x4C)
#define OCR1A 			*((volatile uint16*) 0x4A)
#define OCR1B 			*((volatile uint16*) 0x48)
#define ICR1 			*((volatile uint16*) 0x46)

#define TCCR2 			*((volatile uint16*) 0x45)
#define TCNT2 			*((volatile uint16*) 0x44)
#define OCR2 			*((volatile uint16*) 0x43)

#define PORTA 			*((volatile uint16*) 0x3B)
#define DDRA 			*((volatile uint16*) 0x3A)
#define PINA 			*((volatile uint16*) 0x39)

#define PORTB 			*((volatile uint16*) 0x38)
#define DDRB 			*((volatile uint16*) 0x37)
#define PINB 			*((volatile uint16*) 0x36)

#define PORTC 			*((volatile uint16*) 0x35)
#define DDRC 			*((volatile uint16*) 0x34)
#define PINC 			*((volatile uint16*) 0x33)

#define PORTD 			*((volatile uint16*) 0x32)
#define DDRD 			*((volatile uint16*) 0x31)
#define PIND 			*((volatile uint16*) 0x30)

#define GICR 			*((volatile uint16*) 0x5B)
#define GIFR 			*((volatile uint16*) 0x5A)
#define MCUCR 			*((volatile uint16*) 0x55)
#define MCUCSR 			*((volatile uint16*) 0x54)

#define SPMCR 			*((volatile uint16*) 0x57)
#define TWCR 			*((volatile uint16*) 0x56)

#define ASSR 			*((volatile uint16*) 0x42)
#define WDTCR 			*((volatile uint16*) 0x41)
#define EEARH 			*((volatile uint16*) 0x3F)
#define EEARL 			*((volatile uint16*) 0x3E)
#define EEDR 			*((volatile uint16*) 0x3D)
#define EECR 			*((volatile uint16*) 0x3C)
#define SPDR 			*((volatile uint16*) 0x2F)
#define SPSR 			*((volatile uint16*) 0x2E)
#define SPCR 			*((volatile uint16*) 0x2D)

#define UDR 			*((volatile uint16*) 0x2C)
#define UCSRA 			*((volatile uint16*) 0x2B)
#define UCSRB 			*((volatile uint16*) 0x2A)
#define UBRRL 			*((volatile uint16*) 0x29)
#define ACSR 			*((volatile uint16*) 0x28)

#define ADMUX 			*((volatile uint16*) 0x27)
#define ADCSRA			*((volatile uint16*) 0x26)
#define ADC 			*((volatile uint16*) 0x24)
#define SFIOR 			*((volatile uint16*) 0x50)

#define TWDR 			*((volatile uint16*) 0x23)
#define TWAR 			*((volatile uint16*) 0x22)
#define TWSR 			*((volatile uint16*) 0x21)
#define TWBR 			*((volatile uint16*) 0x20)

#endif /* MCAL_REGISTERS_ADDRESSES_H_ */
