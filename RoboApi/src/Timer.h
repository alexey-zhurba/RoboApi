// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Timer
{
private:
	unsigned long m_startTime;
	unsigned long m_stopTime;
public:
	Timer();
	void start();
	void stop();
	void reset();
	bool isRunning();
	unsigned long elapsedMillis();
};

#endif

