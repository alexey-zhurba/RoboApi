// MotorController.h

#ifndef _MOTORCONTROLLER_h
#define _MOTORCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "TimedObject.h"
#include "Timer.h"

namespace RoboApi {
	//Klasse für die Steuerung einzelner Motoren
	class MotorController : public virtual TimedObject {
	private:
		int m_pinIA;
		int m_pinIB;
		Timer m_tmrVor;
		Timer m_tmrRueck;
		int m_speedVor;
		int m_speedRueck;
		int m_dauerVor;
		int m_dauerRueck;
		bool m_bVor;
		bool m_bRueck;
		void vorwaertsInternal(int speed);
		void rueckwaertsInternal(int speed);
	public:
		MotorController(int pinIA, int pinIB);
		virtual ~MotorController();
		void vorwaerts(int speed = 255, int dauer = 0);
		void rueckwaerts(int speed = 255, int dauer = 0);
		virtual void stop();
		virtual void update();
	};
}

#endif
