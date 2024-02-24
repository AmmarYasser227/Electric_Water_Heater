
#include "APP.h"


void APP()
{
	u8 Wanted_temp = 60;
	char Current_temp = 0;
	u8 State = 1;
	u8 i;
	DDRA = 0x17;
	DDRD = 0x3;
	DDRC = 0x00;
	set_bit(PORTA, 1);
	ADC_Init();
	TWI_Init();

	while (1)
	{

		switch (State)
		{
			case 1 :
			EEPROM_Read(0x00, &Wanted_temp);
			for(i = 0 ; i < 10 ; i++ ){					//Blinking the 7Seg with set temperature for 3s
				SS_1D(PORTB, (Wanted_temp % 10));		//
				SS_2D(PORTB, (Wanted_temp / 10));		//
				Toggle_port(DDRB);						//
				_delay_ms(300);
			}
			DDRB = 0xff;
			State--;
			break;
			case 2:
			if((Wanted_temp <75))
			{
				Wanted_temp += 5;
				EEPROM_Write(Wanted_temp,0x00);
				for(i = 0 ; i < 5 ; i++ )//Blinking the 7Seg with set temperature for 3s
				{
					SS_1D(PORTB, (Wanted_temp % 10));		//
					SS_2D(PORTB, (Wanted_temp / 10));		//
					Toggle_port(DDRB);						//
					_delay_ms(300);
				}
				DDRB = 0xff;
				
				State =0;
			}
			else
			{
				State = 0 ;
			}
			break;
			case 3 :
			if(Wanted_temp >35)
			{
				Wanted_temp -= 5;
				EEPROM_Write(Wanted_temp,0x00);
				for(i = 0 ; i < 5 ; i++ )//Blinking the 7Seg with set temperature for 3s
				{
					SS_1D(PORTB, (Wanted_temp % 10));		//
					SS_2D(PORTB, (Wanted_temp / 10));		//
					Toggle_port(DDRB);						//
					_delay_ms(300);
				}
				DDRB = 0xff;
				
				State =0;
			}
			else
			{
				State = 0 ;
			}
			break;
			default:
			EEPROM_Read(0x00, &Wanted_temp);
			if((read_bit(PINC,6)==1))
			{
				State=2;
				
			}
			if(read_bit(PINC,5)==1)
			{
				State = 3 ;
			}

			
			Current_temp = ADC_Read(3)/2.04;
			
			SS_1D(PORTB, (Current_temp % 10));		////Presents the current temperature
			SS_2D(PORTB, (Current_temp / 10));		//

			/*	Heating Circuit	*/
			if (Current_temp < Wanted_temp)		//Turn on the heater & the Led if the current temp
			{									//is lower than the wanted temperature
				set_bit(PORTA, 4);				//Heater ON
				set_bit(PORTD, 0);				//Red Led ON
			}
			else
			{
				clear_bit(PORTA, 4);			//Heater OFF
				clear_bit(PORTD, 0);			//Red Led OFF
			}
			/*	Cooling Circuit	*/
			if (Current_temp > Wanted_temp)
			{
				set_bit(PORTA, 0);				//Fan ON
				set_bit(PORTD, 1);				//Blue Light ON
			}
			else
			{
				clear_bit(PORTA, 0);			//Fan OFF
				clear_bit(PORTD, 1);			//Blue Light OFF
			}
			
		}


		
	}
}
