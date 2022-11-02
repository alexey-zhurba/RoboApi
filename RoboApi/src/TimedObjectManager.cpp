// 
// 
// 

#include "TimedObjectManager.h"

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
}

void RoboApi::TimedObjectManager::remove(TimedObject* tObj)
{
	for (int i = m_stackPtr - 1; i >= 0; --i)
	{
		if (m_tObjectStack[i] == tObj)
		{
			--m_stackPtr;
			for (int j = i; j < m_stackPtr; ++j)
			{
				m_tObjectStack[j] = m_tObjectStack[j + 1]; //Alle Elemente nach links einrücken
			}
		}
	}
}
