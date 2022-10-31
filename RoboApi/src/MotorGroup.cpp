// 
// 
// 

#include "MotorGroup.h"

RoboApi::MotorGroup::MotorGroup(MotorController mtrCntrlLeft, MotorController mtrCntrlRight) : m_mtrCntrlLeft(mtrCntrlLeft), m_mtrCntrlRight(mtrCntrlRight) {}

void RoboApi::MotorGroup::vorwaerts(int speed, int dauer)
{
	m_mtrCntrlLeft.vorwaerts(speed, dauer);
	m_mtrCntrlRight.vorwaerts(speed, dauer);
}

void RoboApi::MotorGroup::rueckwaerts(int speed, int dauer)
{
	m_mtrCntrlLeft.rueckwaerts(speed, dauer);
	m_mtrCntrlRight.rueckwaerts(speed, dauer);
}

void RoboApi::MotorGroup::links(int speed, int dauer)
{
	m_mtrCntrlLeft.rueckwaerts(speed, dauer);
	m_mtrCntrlRight.vorwaerts(speed, dauer);
}

void RoboApi::MotorGroup::rechts(int speed, int dauer)
{
	m_mtrCntrlLeft.vorwaerts(speed, dauer);
	m_mtrCntrlRight.rueckwaerts(speed, dauer);
}

void RoboApi::MotorGroup::stop()
{
	m_mtrCntrlLeft.stop();
	m_mtrCntrlRight.stop();
}

RoboApi::MotorGroup::~MotorGroup()
{
}
