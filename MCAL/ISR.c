

#include "avr/interrupt.h"
#include <math.h>

#include "../HALL/LCD_Driver.h"
#include "TIMERS.h"


/* Interrupt Service Routine For Timer1  */
ISR(TIMER1_CAPT_vect) {
	double high = 0, period = 0;
	static uint8  cnt = 0;

	if (cnt == 0) {
		edge1 = ICR1;
		TCCR1 = 0X0001;
		cnt = 1;
	} else if (cnt == 1) {
		fallingEdge = ICR1;
		TCCR1 = 0X0041;
		cnt = 2;
	} else if (cnt == 2) {
		edge2 = ICR1;
		TCCR1 = 0x0000;
		cnt = 3;

		high = (fallingEdge + (counter * 65536)) - edge1;
		period = (edge2 + (counter * 65536))  - edge1;

		double duty = (high) / (period + (256 * counter));

		LCD_WriteString("FR=");
		LCD_WriteDouble(16000000.0 / period, 1);

		LCD_WriteString("DU=");
		LCD_WriteDouble(duty * 100, 0);
		LCD_WriteChar('%');

		LCD_GoTo(1, 0);
		int column = 0;
		for (int row = 0; row < 16; row++) {
			column++;

			if (row == 10) {
				column = 0;
			}

			if (row > 10) {
				LCD_WriteChar(column < round(duty * 10) ? '-' : '_');
			} else {
				LCD_WriteChar(column <= round(duty * 10) ? '-' : '_');
			}
		}
	}
}

ISR(TIMER1_OVF_vect) {
	counter++;                /* Increase Counter When Timer Reach Overflow */
}
