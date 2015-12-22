/*
 *  Created on: Nov 13, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#include "serial_logger.h"

#include <Arduino.h>

SerialLogger::SerialLogger() {
}

SerialLogger::~SerialLogger() {
}

void SerialLogger::start(unsigned long baudrate) {
	Serial.begin(baudrate);
	delay(3000);
	info("serial output on - " + String(baudrate));
}

void SerialLogger::info(String message) {
	//if (Serial.available()) {
		Serial.println("[INFO] " + message);
	//	delay(100);
	//}
}

SerialLogger Log = SerialLogger();
