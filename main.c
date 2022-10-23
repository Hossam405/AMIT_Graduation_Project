

#include "MCAL/TIMERS.h"
#include "MACROS.h"
#include <stdlib.h>
#include "HALL/LCD_Driver.h"


int main() {
	LCD_Init();
	Ti2_Init(T2_PWM);
	Ti2_PWM(50);
	ICU_Init();
	Ti2_Start();

	while(1) {}
}
