/*
 * eepromutil.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#include "eepromutil.h"
#include <EEPROM.h>
#include <ESP8266WiFi.h>

EEPROMUtil::EEPROMUtil(const int size) :
		_eeprom_size(size) {
}

EEPROMUtil::~EEPROMUtil() {
	EEPROM.end();
}

void EEPROMUtil::start() {
	EEPROM.begin(_eeprom_size);
	Serial.println("eeprom started - " + String(_eeprom_size));
}

void EEPROMUtil::put(String key, String value) {
	String str = key + '=' + value + '\n';
	int address = getNextAddress();
	Serial.println(address);
	for (int j = 0; j < str.length(); ++j) {
		EEPROM.write(address, str[j]);
		address++;
	}
	delay(10);
	EEPROM.commit();
	Serial.println("stored in the eeprom");
}

String EEPROMUtil::readAll() {
	String tmp;
	char ch = char(EEPROM.read(startAddress));
	if (ch == emptyChar) {
		tmp = "empty";
	} else {
		for (int k = startAddress; k < _eeprom_size; ++k) {
			ch = char(EEPROM.read(k));
			if (ch == emptyChar) {
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
	for (int k = startAddress; k < _eeprom_size; ++k) {
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
	int current = startAddress;
	for (int k = startAddress; k < _eeprom_size; ++k) {
		if (char(EEPROM.read(k)) == '\n') {
			current = k;
		}
	}
	return current == 1 ? current : (current + 1);
}

void EEPROMUtil::clear() {
	for (int i = 0; i < _eeprom_size; ++i) {
		EEPROM.write(i, emptyChar);
	}
	// don't know why we need to do it but a new line character apparently has to be written first
	EEPROM.write(0, '\n');
	EEPROM.commit();
	delay(10);
	Serial.println("eeprom cleared");
}
