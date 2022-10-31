// 
// 
// 

#include "Timer.h"

Timer::Timer() : m_startTime(0), m_stopTime(0) {};

void Timer::start()
{
	m_startTime = millis();
}

void Timer::stop()
{
	m_stopTime = millis();
}

void Timer::reset()
{
	m_startTime = 0;
	m_stopTime = 0;
}

bool Timer::isRunning()
{
	return !m_startTime;
}

unsigned long Timer::elapsedMillis()
{
	if (m_stopTime)
	{
		return m_stopTime - m_startTime;
	}
	else
	{
		return millis() - m_startTime;
	}
}
