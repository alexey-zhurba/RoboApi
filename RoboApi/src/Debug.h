#pragma once
#ifndef _Debug_h_
#define _Debug_h_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#ifdef ARDUINO
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

#define PRINT_ENTER_FUNC() { \
Serial.print("--> ");\
Serial.println(__FUNCTION__);\
}

#define PRINT_EXIT_FUNC() {\
Serial.print("<-- ");\
Serial.println(__FUNCTION__);\
}

#define WRAP_ENTEREXIT_FUNC(x) {PRINT_ENTER_FUNC(); {x} PRINT_EXIT_FUNC();}
#endif