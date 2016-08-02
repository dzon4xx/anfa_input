/*
 * pir.h
 *
 * Created: 2016-07-25 16:30:30
 *  Author: dzony
 */ 

#include "../utilities/pin/pin.h"

#ifndef PIR_H_
#define PIR_H_

class Pir : public In_pin{

	public:
	Pir(uint8_t port, uint8_t pin);

	state get_state();

	private:

};



#endif /* PIR_H_ */