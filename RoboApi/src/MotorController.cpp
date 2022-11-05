#include "MotorController.h"
#include "Debug.h"

void RoboApi::MotorController::vorwaertsInternal(int speed)
{
	PRINT_ENTER_FUNC();
	DEBUG_PRINT("Speed: ");
	DEBUG_PRINTLN(speed);
	analogWrite(m_pinIA, 0);
	analogWrite(m_pinIB, speed);
	PRINT_EXIT_FUNC();
}

void RoboApi::MotorController::rueckwaertsInternal(int speed)
{
	analogWrite(m_pinIA, speed);
	analogWrite(m_pinIB, 0); //writing analog and digital to same pin causes problems
}

RoboApi::MotorController::MotorController(int pinIA, int pinIB) : m_pinIA(pinIA), m_pinIB(pinIB), m_bVor(false), m_bRueck(false), m_accelaration(40)
{
	pinMode(pinIA, OUTPUT);
	pinMode(pinIB, OUTPUT);
}

RoboApi::MotorController::~MotorController()
{
	stop();
}

void RoboApi::MotorController::vorwaerts(int speed, int dauer)
{
	PRINT_ENTER_FUNC();
	m_speedVor = speed;
	m_dauerVor = dauer;
	m_bVor = true;
	m_bRueck = false;
	m_bImpulseVor = false;
	m_tmrVor.start();
	start();
	PRINT_EXIT_FUNC();
}

void RoboApi::MotorController::rueckwaerts(int speed, int dauer)
{
	m_speedRueck = speed;
	m_dauerRueck = dauer;
	m_tmrRueck.start();
	m_bRueck = true;
	m_bVor = false;
	m_bImpulseRueck = false;
	start();
}

void RoboApi::MotorController::stop()
{
	PRINT_ENTER_FUNC();
	TimedObject::stop();
	m_bRueck = false;
	m_bVor = false;
	analogWrite(m_pinIA, 255);
	analogWrite(m_pinIB, 255);
	DEBUG_PRINTLN(m_pinIA);
	DEBUG_PRINTLN(m_pinIB);
	PRINT_EXIT_FUNC();
}

void RoboApi::MotorController::update()
{
	PRINT_ENTER_FUNC();

	if (m_bVor && (!m_dauerVor || m_tmrVor.elapsedMillis() < m_dauerVor))
	{
		/*int c = 255 - m_speedVor;
		int speedAdd = MAX(c - (int)((c * m_tmrVor.elapsedMillis()) / m_accelaration), 0);*/
		if (!m_bImpulseVor)
		{
			//	m_tmrImpulseVor.start();
			m_bImpulseVor = true;
			vorwaertsInternal(150);
			delay(100);
		}
		//if (m_tmrImpulseVor.elapsedMillis() < m_accelaration) 
		//{
		//	vorwaertsInternal(140);
		//}
		//else
		//{
		//	vorwaertsInternal(m_speedVor); //nach m_accelaration + 1 max speed
		//}
		vorwaertsInternal(m_speedVor);
	}
	else if (m_bRueck && (!m_dauerRueck || m_tmrRueck.elapsedMillis() < m_dauerRueck))
	{
		/*int c = 255 - m_speedRueck;
		int speedAdd = MAX(c - (int)((c * m_tmrRueck.elapsedMillis()) / m_accelaration), 0);
		rueckwaertsInternal(m_speedRueck + speedAdd);*/
		if (!m_bImpulseRueck)
		{
			//	m_tmrImpulseRueck.start();
			m_bImpulseRueck = true;
			rueckwaertsInternal(180);
			delay(15);
		}
		//if (m_tmrImpulseRueck.elapsedMillis() < m_accelaration)
		//{
		//	rueckwaertsInternal(140);
		//}
		//else
		//{
		//	rueckwaertsInternal(m_speedRueck); //nach m_accelaration + 1 max speed
		//}
		rueckwaertsInternal(m_speedRueck);
	}
	else
	{
		stop();
	}
	PRINT_EXIT_FUNC();
}
