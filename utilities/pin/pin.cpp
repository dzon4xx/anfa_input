/*
 * pin.cpp
 *
 * Created: 2016-03-03 10:58:24
 *  Author: jan.pleszynski
 */ 

#include <avr/io.h>
#include "pin.h"


#define NUM_OF_PORTS 3
uint8_t port_letters[]	=	{'b', 'c', 'd'};
volatile uint8_t *out_ports[]	= {&PORTB, &PORTC, &PORTD,};
volatile uint8_t *in_ports[]	= {&PINB, &PINC, &PIND, };
volatile uint8_t *dir_ports[]	= {&DDRB, &DDRC, &DDRD, };


 Out_pin::Out_pin(uint8_t port_letter, uint8_t pin_num)
 {
	pin_mask = (1<<pin_num);
	this->port_letter = port_letter; 
	for(uint8_t i=0; i<NUM_OF_PORTS; i++)
	{
		if (port_letter == port_letters[i])
		{
			out_port = out_ports[i];
			*dir_ports[i] |= pin_mask;
			break;
		}
	}
 }


In_pin::In_pin(uint8_t port_letter, uint8_t pin_num, bool pull_up)
{
	this->pin_mask = (1<<pin_num);
	this->port_letter = port_letter;
	
	for (uint8_t i=0; i<NUM_OF_PORTS; i++)
	{
		if (port_letter == port_letters[i])
		{
			this->in_port	= in_ports[i];
			this->dir_port	= dir_ports[i];
			*(this->dir_port) &= ~pin_mask;
			if (pull_up)
			{
				*out_ports[i] |= pin_mask;
			}
			break;
		}		
	}	
}

state In_pin::read_state(){

	bool present_state = *in_port & pin_mask;
	if(this->_pull_up){
		if(present_state){return OFF;}
		else{return ON;}
	}
	else{
		if(present_state){return ON;}
		else{return OFF;}
	}
}

