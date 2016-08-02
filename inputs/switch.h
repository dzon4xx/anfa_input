/*
 * switch.h
 *
 * Created: 2016-07-25 15:56:04
 *  Author: dzony
 */ 

 #include "../utilities/pin/pin.h"

#ifndef SWITCH_H_
#define SWITCH_H_



class Switch : public In_pin{
	public:
	Switch(uint8_t port, uint8_t pin);

	state get_state();

	uint16_t debounce_time = 60; //ms of time for debounce 


	private:

	state _first_state= OFF;

	state _second_state = OFF;

	state _present_state = OFF;

	state _prev_state = OFF;

	bool _is_measure = false;

	uint32_t _debounce_timer = 0;

	// Debounces input checking if it is the same after debounce time. If not return UNDEFINED
	state _debounce();
};




#endif /* SWITCH_H_ */