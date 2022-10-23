

#include "LCD_Driver.h"


/* LCD Initialization Function */
void LCD_Init() {
	DIO_SetPinDir(LCD_CMD_PORT, LCD_RS, HIGH);
	DIO_SetPinDir(LCD_CMD_PORT, LCD_RW, HIGH);
	DIO_SetPinDir(LCD_CMD_PORT, LCD_E, HIGH);

	DIO_SetPinDir(LCD_DATA_PORT, D4_PIN, HIGH);
	DIO_SetPinDir(LCD_DATA_PORT, D5_PIN, HIGH);
	DIO_SetPinDir(LCD_DATA_PORT, D6_PIN, HIGH);
	DIO_SetPinDir(LCD_DATA_PORT, D7_PIN, HIGH);

	_delay_ms(100);

	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);

	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x02);
}


/* LCD Command Function */
void LCD_WriteCommand(uint8 cmd) {
	uint8 command, portValue;

	DIO_SetPinValue(LCD_CMD_PORT, LCD_RS, LOW);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_RW, LOW);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	portValue = DIO_GetPortValue(LCD_DATA_PORT);
	command = (cmd & 0xf0) | ( portValue & 0x0f);

	DIO_SetPortValue(LCD_DATA_PORT, command);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, HIGH);

	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	portValue = DIO_GetPortValue(LCD_DATA_PORT);
	command = (cmd << 4) | (portValue & 0x0f);

	DIO_SetPortValue(LCD_DATA_PORT, command);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, HIGH);

	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	_delay_ms(5);
}


/* Function To Determine The Starting Position On LCD  */
void LCD_GoTo(uint8 row , uint8 col) {
	uint8 pos[2] = {0x80 , 0xc0};
	LCD_WriteCommand(pos[row] + col);
}


/* Writing Character ON LCD Function */
void LCD_WriteChar(uint8 chr) {
	uint8 data, portValue;

	DIO_SetPinValue(LCD_CMD_PORT, LCD_RS, HIGH);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_RW, LOW);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	portValue = DIO_GetPortValue(LCD_DATA_PORT);
	data = (chr & 0xf0) | (portValue & 0x0f);

	DIO_SetPortValue(LCD_DATA_PORT, data);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, HIGH);

	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	portValue = DIO_GetPortValue(LCD_DATA_PORT);
	data = (chr << 4) | (portValue & 0x0f);

	DIO_SetPortValue(LCD_DATA_PORT, data);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, HIGH);

	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT, LCD_E, LOW);

	_delay_ms(5);
}

/* Function To Write a String Of Characters On LCD */
void LCD_WriteString(uint8* str) {
	uint8 i = 0;

	while(str[i] != '\0') {
		LCD_WriteChar(str[i]);
		i++;
	}
}

/* Function To Write Double Character On LCD */
void LCD_WriteDouble(double nbr, uint8 prec) {
	char output[16] = " ";
	dtostrf(nbr, 4, prec, output);

	LCD_WriteString(output);
}
