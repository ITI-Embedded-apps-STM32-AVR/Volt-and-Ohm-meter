#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_interface.h"



//8 bit mode  ADC using polling
void  ADC_voidInit(void)
{
	//ADC refrence volate  on external capcitor
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	//ADC right adjusment
	CLEAR_BIT(ADMUX,5);
	//enable  ADC
	SET_BIT(ADCSRA,7);
	//prescalar to 128
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}

u16 ADC_u8GetChnnelReading(u8 channel)
{
	// set channel ADMUX

	ADMUX&=0b11100000;
	ADMUX|=channel;

	//start conversion 

	SET_BIT(ADCSRA,6);

	// polling to the interrupt flag
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4);
	//return result
	return ADC;

}
