/*
 * main.c
 *
 *  Created on: Mar 4, 2020
 *      Author: SARA
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include <avr/delay.h>

void main(void)
{
	PortInit();
	CLCD_VoidIntialize();
	ADC_voidInit();

	u32	 sara;
	u8 i;
	u32 anlogVal;

	u32 oneVal;
	u32 RVal_num;
	u32 RVal_dem;
	u32 RUN;
	while(1)
	{
		sara = ADC_u8GetChnnelReading(channel_SINGLE_ADC0);
		anlogVal = (5000*sara)/1024; //mvolt
		RVal_num = (1000 *anlogVal);
		RVal_dem = (5000 - anlogVal);
		RUN = RVal_num/RVal_dem;
		CLCD_voidWriteCmd(Clear_Display);


		for(i=0;i<6;i++)
		{
			oneVal = RUN%10 +'0';
			CLCD_voidGOToLocation(CLCD_LINE_1, 5-i);

			CLCD_voidWriteDate(oneVal);
			RUN/=10;


		}
		_delay_ms(100);

	}
}
