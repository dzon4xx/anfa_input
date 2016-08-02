 
#include "misc.h"
#include <util/delay.h>

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void delay_us(unsigned int us)
{
	for (unsigned int i=0; i<us; i++)
	{
		_delay_us(1);
	}
}

 void * operator new(size_t size)
 {
	 return malloc(size);
 }

 void operator delete(void * ptr)
 {
	 free(ptr);
 }


