

#ifndef PWM_H_
#define PWM_H_

#define MAX 254
#define STOP 0
#define Motor_Speed OCR0
#define Motor_Ports PORTB
#define Right 1
#define Left 0

void PWM_Init();
void Motor_CW();
void Motor_AntiCW();
void Motor_Stop();

#define setbit(reg,pos) reg|=1<<pos
#define clrbit(reg,pos) reg&=~(1<<pos)
#define togglebit(reg,pos) reg^=1<<pos


#endif /* PWM_H_ */