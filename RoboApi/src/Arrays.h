// ArduinoC.h

#ifndef _Arrays_h
#define _Arrays_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define COUNT_OF(arr) (sizeof(arr)/sizeof(arr[0]))

#endif

