#pragma once
#ifndef _IRSENSOR_h_
#define _IRSENSOR_h_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define IR_THRESHOLD 30

namespace RoboApi {
	class IRSensor {
	private:
		int m_pin;
	public:
		IRSensor(int pin);
		bool isWhite();
		int value();
	};
}

#endif