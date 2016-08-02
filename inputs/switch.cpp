/*
 * switch.cpp
 *
 * Created: 2016-07-25 15:55:51
 *  Author: dzony
 */ 

 #include "switch.h"
 #include "../utilities/clock/clock.h"

 Switch::Switch(uint8_t port, uint8_t pin ) : In_pin(port, pin, true)
 {
 }

 state Switch::get_state(){

	this->_debounce();

	if (this->_present_state != this->_prev_state)
	{
		this->_prev_state = this->_present_state;
	}
	return this->_present_state ;
 }

state Switch::_debounce(){

	if(!this->_is_measure){
		this->_is_measure = true;
		this->_first_state = this->read_state();
		this->_debounce_timer = clock->get_ms();
	}

	if (clock->get_ms() - this->_debounce_timer >= this->debounce_time)
	{
		this->_is_measure = false;
		this->_second_state = this->read_state();
		if (this->_second_state == this->_first_state){
		this->_present_state = this->_first_state;
		}

	}

	return this->_present_state;
}
 