

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "PWM.h"
#include "LCD.h"
typedef unsigned char uint8;
volatile uint8 Direction=0;
void ExtInt_Init();

int main(void)
{
	
	char Display[10];
	ADC_Init();
	LCD_init();
	PWM_Init();
	ExtInt_Init();
	sei();
	LCD_clr();
	LCD_gotoxy(1,15);
	LCD_sendStr("Welcome\0");
	_delay_ms(500);
	LCD_clr();
	LCD_sendStr("Speed Motor =\0");

    while(1)
    {
	   
   	   ADC_StartConversion();
	   Motor_Speed= ADC * (0.245);    // compressed the 10 bits ADC to 8 bit for OCR0
	   itoa(Motor_Speed,Display,10);  // when the speed reaches to smaller than  100
									  // LCD displays the speed multiplied by 10 reset the project to see the actual number
	   _delay_ms(100);
	   LCD_gotoxy(1,15);
       LCD_sendStr(Display);
	    
    }
}

void ExtInt_Init()
{
	GICR=(1<<INT0);
	MCUCR=(1<<ISC01);  //The falling Edge of INT0 generates IRQ
}

ISR(INT0_vect)
{
	switch (Direction)
	{
		
		case Right:
			Motor_CW();
			Direction=Left;
			break;
		
		case Left:
			Motor_AntiCW();
			Direction=Right;
			break;
		
		default:break;
	}
}