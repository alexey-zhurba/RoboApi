#include "IRSensor.h"

RoboApi::IRSensor::IRSensor(int pin) : m_pin(pin){}

bool RoboApi::IRSensor::isWhite()
{
	return value() < IR_THRESHOLD;
}

int RoboApi::IRSensor::value()
{
	return map(analogRead(m_pin), 0, 4095, 0, 255);
}