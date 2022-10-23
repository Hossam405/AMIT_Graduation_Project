

#ifndef HALL_LCD_DRIVER_H_
#define HALL_LCD_DRIVER_H_

#include <util/delay.h>
#include <stdlib.h>

#include "../MCAL/DIO.h"
#include "LCD_Config.h"

void LCD_Init();
void LCD_WriteCommand(uint8 cmd);
void LCD_GoTo(uint8 row , uint8 col);

void LCD_WriteChar(uint8 chr);
void LCD_WriteString(uint8* str);
void LCD_WriteDouble(double nbr, uint8 prec);

#endif /* HALL_LCD_DRIVER_H_ */
