


#ifndef LCD_H_
#define LCD_H_
#define setbit(reg,pos) reg|=1<<pos
#define clrbit(reg,pos) reg&=~(1<<pos)
#define togglebit(reg,pos) reg^=1<<pos

#define DDR_LCDcrtl DDRD
#define PORT_LCDcrtl PORTD
#define DDR_LCDdata DDRC
#define PORT_LCDdata PORTC 
#define RS 0
#define E 1

void LCD_sendCmd(int);
void LCD_init(void);
void LCD_sendData(char);
void LCD_sendStr(char*);
void LCD_clr();
void LCD_gotoxy(unsigned char,unsigned char);
void LCD_sendStrAnimated(char* data2);

#endif /* INCFILE1_H_ */