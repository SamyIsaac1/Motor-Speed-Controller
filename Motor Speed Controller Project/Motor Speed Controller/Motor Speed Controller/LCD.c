#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"

void LCD_sendCmd(int x)
{
	clrbit(PORT_LCDcrtl,RS);
	PORT_LCDdata=x;
	setbit(PORT_LCDcrtl,E);
	_delay_ms(1);
	clrbit(PORT_LCDcrtl,E);
}
void LCD_init(void)
{
	DDR_LCDdata=0xFF;
	setbit(DDR_LCDcrtl,RS); //RS
	setbit(DDR_LCDcrtl,E); //Enable
	LCD_sendCmd(0x38);
	LCD_sendCmd(0x0C);
}
void LCD_sendData(char x)
{
	setbit(PORT_LCDcrtl,RS);
	PORT_LCDdata=x;
	setbit(PORT_LCDcrtl,E);
	_delay_ms(1);
	clrbit(PORT_LCDcrtl,E);
}
void LCD_sendStr(char* data2)
{
	int i=0;
	while(data2[i]!='\0')
	{
		LCD_sendData(data2[i]);
		i++;
	}
}
void LCD_sendStrAnimated(char* data2)
{
	int i=0;
	while(data2[i]!='\0')
	{
		LCD_sendData(data2[i]);
		i++;
		_delay_ms(250);
	}
}
void LCD_clr()
{
	clrbit(PORT_LCDcrtl,RS);
	PORT_LCDdata=0x01;
	setbit(PORT_LCDcrtl,E);
	_delay_ms(1);
	clrbit(PORT_LCDcrtl,E);
}
void LCD_gotoxy(unsigned char row,unsigned char col)
{
	if(row == 0)
	LCD_sendCmd(0x80+col);
	else if(row == 1)
	LCD_sendCmd(0xC0+col);
}