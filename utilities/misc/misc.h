 #ifndef MISC_H_
 #define MISC_H_
 #include <stdlib.h>
 #include <stdint.h>
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);

void delay_us(unsigned int us);

void * operator new(size_t size);

void operator delete(void * ptr);

#endif