// 
// 
// 

#include "TimedObjectManager.h"
#include "Debug.h"

RoboApi::TimedObjectManager* RoboApi::TimedObjectManager::instance()
{
	static TimedObjectManager tObjMngrInst;
	return &tObjMngrInst;
}

void RoboApi::TimedObjectManager::update()
{
	for (int i = 0; i < m_stackPtr; ++i)
	{
		m_tObjectStack[i]->update();
	}
}

void RoboApi::TimedObjectManager::add(TimedObject* tObj)
{
	if(m_stackPtr < COUNT_OF(m_tObjectStack))
		m_tObjectStack[m_stackPtr++] = tObj;
	DEBUG_PRINT("Added TimedObject ");
	DEBUG_PRINT((__uintptr_t)tObj);
	DEBUG_PRINT(" @ index ");
	DEBUG_PRINTLN(m_stackPtr - 1);
}

void RoboApi::TimedObjectManager::remove(TimedObject* tObj)
{
	for (int i = m_stackPtr - 1; i >= 0; --i)
	{
		if (m_tObjectStack[i] == tObj)
		{
			DEBUG_PRINT("Removing TimedObject ");
			DEBUG_PRINT((__uintptr_t)tObj);
			DEBUG_PRINT(" @ index ");
			DEBUG_PRINTLN(i);
			--m_stackPtr;
			for (int j = i; j < m_stackPtr; ++j)
			{
				m_tObjectStack[j] = m_tObjectStack[j + 1]; //Alle Elemente nach links einrücken
			}
		}
	}
	DEBUG_PRINTLN("New Stack: ");
	for (int i = 0; i < m_stackPtr; ++i)
	{
		DEBUG_PRINT((__uintptr_t)m_tObjectStack[i]);
		DEBUG_PRINT(" | ");
	}
	DEBUG_PRINTLN();
}
