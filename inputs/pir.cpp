/*
 * pir.cpp
 *
 * Created: 2016-07-25 16:30:18
 *  Author: dzony
 */ 

 #include "pir.h"

  Pir::Pir(uint8_t port, uint8_t pin) : In_pin(port, pin, true)
  {

  }	  
  
state Pir::get_state(){
	return this->read_state();
}
