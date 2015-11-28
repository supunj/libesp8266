/*
 * eepromutil.h
 *
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#ifndef EEPROMUTIL_H_
#define EEPROMUTIL_H_

#define DEF_EEPROM_SIZE 512

#include <WString.h>

class EEPROMUtil {
private:
	int getNextAddress();
public:
	EEPROMUtil(int size);
	virtual ~EEPROMUtil();

	void put(String key, String value);
	String get(String key);
	String readAll();
	void clear();
protected:
	int _eeprom_size;
};

extern EEPROMUtil EEPROMUtility;

#endif /* EEPROMUTIL_H_ */
