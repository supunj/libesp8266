/*
 *  Created on: Nov 13, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#ifndef SERIAL_LOGGER_H_
#define SERIAL_LOGGER_H_

#include <WString.h>

class SerialLogger {
public:
	SerialLogger();
	virtual ~SerialLogger();

	void start(unsigned long baudrate);
	void info(String message);

private:

};

extern SerialLogger Log;

#endif /* SERIAL_LOGGER_H_ */
