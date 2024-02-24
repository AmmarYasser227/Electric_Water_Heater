
/*
#include "../Include/ADC.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/STDMACROS.h"
#include "../../DIO/Include/DIO_Registers.h"
#include "../../DIO/Include/DIO.h"

#include <util/delay.h>


void ADC_voidInit()
{
	DIO_u8SetPinDirection(DIO_PortA,DIO_Pin0,DIO_pinINPUT);
	set_bit(ADMUX,ADMUX_REFS0);
	clear_bit(ADMUX,ADMUX_REFS1);
	
	set_bit(ADCSRA,ADCSRA_ADEN);
	set_bit(ADCSRA,ADCSRA_ADPS2);
	clear_bit(ADCSRA,ADCSRA_ADPS1);
	clear_bit(ADCSRA,ADCSRA_ADPS0);
	
	
}

int  ADC_intRead(char Copy_Channel)
{
	int Ain,AinLow;
	
	ADMUX = (ADMUX & 0xE0) | Copy_Channel;
	set_bit(ADCSRA,ADCSRA_ADSC);
	while(read_bit(ADCSRA,ADCSRA_ADIF)==0);
	_delay_us(10);
	AinLow = (int)ADCL;
	Ain = (int)ADCH*256;
	Ain = Ain+AinLow;
	return Ain;
	
}
*/
