/*
 * eepromutil.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#include "eepromutil.h"
#include <EEPROM.h>
#include <ESP8266WiFi.h>

EEPROMUtil::EEPROMUtil(int size) :
		_eeprom_size(size) {
	EEPROM.begin(_eeprom_size);
	//Serial.println("_eeprom_size");
}

EEPROMUtil::~EEPROMUtil() {

}

void EEPROMUtil::put(String key, String value) {
	String str = key + '=' + value + '\n';
	int address = getNextAddress();
	for (int j = 0; j < str.length(); ++j) {
		EEPROM.write(address, str[j]);
		address++;
	}
	EEPROM.commit();
}

String EEPROMUtil::readAll() {
	String tmp;
	char ch = char(EEPROM.read(0));
	if (ch == '\0') {
		tmp = "empty";
	} else {
		for (int k = 0; k < _eeprom_size; ++k) {
			ch = char(EEPROM.read(k));
			if (ch == '\0') {
				break;
			} else {
				tmp += ch;
			}
		}
	}
	return tmp;
}

String EEPROMUtil::get(String key) {
	String item = "";
	for (int k = 0; k < _eeprom_size; ++k) {
		char ch = char(EEPROM.read(k));

		if (ch == '\n') {
			// check item
			if (item.substring(0, item.indexOf('=')) == key) {
				return item.substring((item.indexOf('=') + 1), item.length());
			} else {
				item = "";
			}
		} else {
			item += ch;
		}
	}
	return "";
}

int EEPROMUtil::getNextAddress() {
	int current = 0;
	for (int k = 0; k < _eeprom_size; ++k) {
		if (char(EEPROM.read(k)) == '\n') {
			current = k;
		}
	}
	//Serial.println(current + 1);
	return current + 1;
}

void EEPROMUtil::clear() {
	for (int i = 0; i < _eeprom_size; ++i) {
		EEPROM.write(i, 0);
	}
	//EEPROM.commit();
	delay(5);
	//Serial.println("eeprom cleared");
}

EEPROMUtil EEPROMUtility(DEF_EEPROM_SIZE);
