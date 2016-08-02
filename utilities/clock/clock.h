#ifndef CLOCK_H_
#define CLOCK_H_



class Clock
{
	public:
	Clock();
	void start();
	void stop();
	void restart();
	unsigned long get_ms();

	private:
};

extern Clock *clock;

#endif