
#include <avr/io.h>
#include "../../LIB/STDMACROS.h"
#include "../../LIB/Clock.h"
#include <util/delay.h>

#define ADC_value *((volatile uint16_t*) 0x24);

void ADC_Init(){
	//using the internal 2.56V source
	set_bit(ADMUX, REFS0);
	clear_bit(ADMUX, REFS1);	//cleared = external ref, set = internal ref
	
	//Enable ADC
	set_bit(ADCSRA, ADEN);
	
	//set the prescaler value to be divided by 16
	set_bit(ADCSRA, ADPS2);
	
	//ADLAR pin is left with 0 as right adjust
}

uint16_t ADC_Read(uint16_t ADC_Channel){
	
	//uint16_t ADC_Value = 0;
	ADMUX = (ADMUX&0xE0) | ADC_Channel;
	
	//Start Conversion
	set_bit(ADCSRA, ADSC);
	
	//Wait until the conversion is done and flag is set to 1
	while(read_bit(ADCSRA, ADIF) == 0);
	
	//wait until the value is stored (just for safety)
	_delay_ms(10);
	
	//ADCL is the lower bits in first Reg, ADCH is higher bits in second Reg
	//ADCH*256 is to get the right value assuming the two bits are ones we get 768 not 3 like normal binary
	//ADC_Value = (int)ADCL + (int)ADCH * 256;
	
	return ADC_value;


}
