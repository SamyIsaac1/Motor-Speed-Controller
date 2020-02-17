
#include <avr/io.h>


void ADC_Init()
{
	DDRA&=~(1<<PA0);   // // make Pin A0 an input for ADC input
	// Make ADC enable and select CLK/128
	// 2.56V Vref internal, right justified,
	ADCSRA=0x87;
	
	// select ADC Channel 0
	ADMUX = 0xC0;
}
void ADC_StartConversion()
{
	ADCSRA|=(1<<ADSC); // start conversion
	while( (ADCSRA&(1<<ADIF) )== 0 ) ;
	// wait for conversion to finish
	
	
}
