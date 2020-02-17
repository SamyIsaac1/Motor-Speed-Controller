#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"

void PWM_Init()
{
	setbit(DDRB,0);    //IN1
	setbit(DDRB,1);    //IN2
	// Fast PWM mode & clear OC0 on Comare match &  clock/1024 prescaler
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS02)|(1<<CS00);
	setbit(DDRB,3);   //Enable
}
void Motor_CW()
{
	setbit(Motor_Ports,Right);  //pin PB0=1
	clrbit(Motor_Ports,Left);   //pin PB1=0
}
void Motor_AntiCW()
{
	setbit(Motor_Ports,Left);  //pin PB0=0
	clrbit(Motor_Ports,Right); //pin PB1=1
}
void Motor_Stop()
{
	clrbit(Motor_Ports,Left);  //pin PB0=0
	clrbit(Motor_Ports,Right); //pin PB1=0
}

