/*
 * pin.h
 *
 * Created: 2016-03-03 10:58:58
 *  Author: jan.pleszynski
 */ 


#ifndef PIN_H_
#define PIN_H_

#include <stdint.h>

enum state{
	OFF,
	ON,
};

class Pin
{
public:

	//zwraca litere portu
	uint8_t get_port_letter() {	return port_letter;}

	//zwraca maske pinu. 
	uint8_t get_pin_mask(){	return pin_mask; }

protected:

	//Maska pinu
	uint8_t pin_mask;

	uint8_t port_letter;

};

class Out_pin : public Pin
{
public:

	Out_pin();

	Out_pin(uint8_t port_letter, uint8_t pin_num);
	
	//Zwraca port wyjsciowy
	volatile uint8_t* get_out_port(){ return out_port; }

	//Ustawia pin w stan wysoki
	void high(){ *(out_port) |= pin_mask; }
	
	//Ustawia pin w stan wysoki
	void low(){ *(out_port) &= ~pin_mask; }
private:
	
	//Rejestr wyjsciowy PORTX
	volatile uint8_t *out_port;

};

class In_pin : public Pin
{

public:
	In_pin();
	In_pin(uint8_t port_letter, uint8_t pin_num, bool pull_up);

	volatile uint8_t* get_in_port(){return in_port;}

	state read_state();

	virtual state get_state(){ return OFF; }

private:

	volatile uint8_t *in_port;
	volatile uint8_t *dir_port;

	bool _pull_up;

};

#endif