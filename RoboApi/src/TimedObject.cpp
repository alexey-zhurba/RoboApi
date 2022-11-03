#include "TimedObject.h"

RoboApi::TimedObject::TimedObject() : m_bStop(true) {};

RoboApi::TimedObject::~TimedObject()
{
	if (!isStopped())
		stop();
}

void RoboApi::TimedObject::start()
{
	RoboApi::TimedObjectManager::instance()->add(this);
	m_bStop = false;
}

void RoboApi::TimedObject::stop()
{
	RoboApi::TimedObjectManager::instance()->remove(this);
	m_bStop = true;
}

bool RoboApi::TimedObject::isStopped()
{
	return m_bStop;
}
