/*
 Name:		DummyProject.ino
 Created:	10/31/2022 11:17:17 AM
 Author:	alexe
*/

#include <RoboApi.h>

// the setup function runs once when you press reset or power the board



RoboApi::MotorGroup motor(RoboApi::MotorController(2,3),RoboApi::MotorController(18,19));
RoboApi::IRSensor sensor(A0);
void setup() {
Serial.begin(9600);
motor.vorwaerts(75,5000);

}

// the loop function runs over and over again until power down or reset
void loop() {
RoboApi::TimedObjectManager::instance()->update();
}
