/*
 * input.cpp
 *
 * Created: 2016-07-23 15:59:58
 * Author : dzony
 */ 

#include <avr/io.h>
#include "communication/modbus_slave.h"
#include "utilities/clock/clock.h"
#include "utilities/pin/pin.h"

#include "inputs/pir.h"
#include "inputs/switch.h"

#define NUM_OF_INPUTS 15
int main(void)
{
	read_reg	= new Modbus_read_reg;
	frame		= new Frame();
	clock	=	new Clock;
	clock->start();
    /* Replace with your application code */
	Switch pir1('b', 2);
	Switch pir2('b', 1);
	Switch pir3('b', 0);
	Switch pir4('d', 7);
	Switch pir5('d', 6);
	Switch pir6('d', 5);
	Switch switch1('d', 4);
	Switch switch2('d', 3);
	Switch switch3('d', 2);
	Switch switch4('c', 5);
	Switch switch5('c', 4);
	Switch rs1('c', 3);
	Switch rs2('c', 2);
	Switch rs3('c', 1);
	Switch rs4('c', 0);


	In_pin *inputs[] = {&pir1, &pir2, &pir3, &pir4, &pir5, &pir6, &switch1, &switch2, &switch3, &switch4, &switch5, &rs1, &rs2, &rs3, &rs4};
    while (1) 
    {
		for (uint8_t i =0 ; i<NUM_OF_INPUTS; i++)
		{
			read_reg->regs[i] = inputs[i]->get_state();
		}
    }
}

