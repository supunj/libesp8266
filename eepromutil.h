/*
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#ifndef EEPROMUTIL_H_
#define EEPROMUTIL_H_

#define DEF_EEPROM_SIZE 512

#include <WString.h>

class EEPROMUtil {
private:
	const int startAddress = 1;
	int getNextAddress();
	static const char emptyChar = '\0';
	static const char newLineChar = '\n';
	static const char splitChar = '=';

	void update(const String& key, const String& value);
	void write(const String& key, const String& value);
public:
	EEPROMUtil(const int size = DEF_EEPROM_SIZE);
	virtual ~EEPROMUtil();

	void put(String key, String value);
	String get(String key);
	String readAll();
	void clear();
	void start();
protected:
	int _eeprom_size;
};

#endif /* EEPROMUTIL_H_ */
