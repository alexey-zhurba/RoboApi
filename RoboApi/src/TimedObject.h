// TimedObject.h

#ifndef _TIMEDOBJECT_h
#define _TIMEDOBJECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TimedObjectManager.h"

namespace RoboApi {
	//Objekte mit Operationen mit längerer Dauer
	class TimedObject
	{
	private:
		bool m_bStop;
	public:
		TimedObject();
		//Wird in jedem arduino loop aufgerufen
		virtual void update() = 0;
		virtual ~TimedObject() = default;
		virtual void start();
		virtual void stop();
		bool isStopped();
	};
}


#endif

