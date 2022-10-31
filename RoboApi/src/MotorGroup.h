// MotorGroup.h

#ifndef _MOTORGROUP_h
#define _MOTORGROUP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "MotorController.h"

namespace RoboApi {
	class MotorGroup{
	private:
		MotorController m_mtrCntrlLeft;
		MotorController m_mtrCntrlRight;
	public:
		MotorGroup(MotorController mtrCntrlLeft, MotorController mtrCntrlRight);
		void vorwaerts(int speed = 255, int dauer = 0);
		void rueckwaerts(int speed = 255, int dauer = 0);
		void links(int speed = 255, int dauer = 0);
		void rechts(int speed = 255, int dauer = 0);
		void stop();
		~MotorGroup();
	};
}


#endif

