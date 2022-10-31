#include "MotorController.h"
#include "Debug.h"

void RoboApi::MotorController::vorwaertsInternal(int speed)
{
	PRINT_ENTER_FUNC();
	Serial.print("Speed: ");
	Serial.println(speed);
	digitalWrite(m_pinIA, LOW);
	digitalWrite(m_pinIB, HIGH);
	PRINT_EXIT_FUNC();
}

void RoboApi::MotorController::rueckwaertsInternal(int speed)
{
	analogWrite(m_pinIA, speed);
	digitalWrite(m_pinIB, LOW);
}

RoboApi::MotorController::MotorController(int pinIA, int pinIB) : m_pinIA(pinIA), m_pinIB(pinIB), m_bVor(false), m_bRueck(false)
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
	start();
}

void RoboApi::MotorController::stop()
{
	PRINT_ENTER_FUNC();
	TimedObject::stop();
	m_bRueck = false;
	m_bVor = false;
	digitalWrite(m_pinIA, LOW);
	digitalWrite(m_pinIB, LOW);
	PRINT_EXIT_FUNC();
}

void RoboApi::MotorController::update()
{
	PRINT_ENTER_FUNC();

	if (m_bVor && (!m_dauerVor || m_tmrVor.elapsedMillis() < m_dauerVor))
	{
		vorwaertsInternal(m_speedVor);
	}
	else if(m_bRueck && (!m_dauerRueck || m_tmrRueck.elapsedMillis() < m_dauerRueck))
	{
		rueckwaertsInternal(m_speedRueck);
	}
	else
	{
		stop();
	}
	PRINT_EXIT_FUNC();
}
