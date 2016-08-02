#include "clock.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define  OVF_VAL 7	//wartosc rejestru TCNT0 aby timer przepelnial sie co 1ms
unsigned long m = 0;

 Clock::Clock()
{
	TCNT0 = OVF_VAL;
	TIMSK0 |= (1<<TOIE0);			
}

void Clock::start()
{
	TCCR0B |= (1<<CS00)|(1<<CS01);
}

void Clock::stop()
{
	TCCR0B &= ~((1<<CS00)|(1<<CS01));
}

void Clock::restart()
{
	m=0;
	this->stop();
	TCNT0 = OVF_VAL;
	this->start();
}

unsigned long Clock::get_ms()
{
	return m;
}

Clock *clock;

ISR (TIMER0_OVF_vect, ISR_NOBLOCK) 
{
	m++;
}