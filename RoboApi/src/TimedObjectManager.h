// TimedObjectManager.h

#ifndef _TIMEDOBJECTMANAGER_h
#define _TIMEDOBJECTMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TimedObject.h"
#include "Arrays.h"

//Singleton klasse für das managen von vielen TimedObject (max 200)
namespace RoboApi {
	class TimedObjectManager
	{
	private:
		TimedObjectManager() : m_stackPtr(0) {};
		class TimedObject* m_tObjectStack[200] = {0};
		int m_stackPtr;
	public:
		TimedObjectManager(TimedObjectManager const&) = delete;
		void operator =(TimedObjectManager const&) = delete;
		static TimedObjectManager* instance();
		void update();
		void add(class TimedObject* tObj);
		void remove(class TimedObject* tObj);
	};
}


#endif

