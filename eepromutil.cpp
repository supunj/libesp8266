/*
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#include <EEPROM.h>
#include <Arduino.h>
#include <vector>

#include "eepromutil.h"
#include "serial_logger.h"

EEPROMUtil::EEPROMUtil(const int size) :
		_eeprom_size(size) {
}

EEPROMUtil::~EEPROMUtil() {
	EEPROM.end();
}

/**
 * Initialize EEPROM
 */
void EEPROMUtil::start() {
	EEPROM.begin(_eeprom_size);
	Log.info("eeprom started - " + String(_eeprom_size));
}

/**
 * Store a key/value pair
 */
void EEPROMUtil::put(String key, String value) {
	if (get(key) == "") {
		write(key, value);
	} else {
		Log.info("key exists. updating...");
		update(key, value);
	}
}

/**
 * Physically write to EEPROM
 */
void EEPROMUtil::write(const String& key, const String& value) {
	String str = key + splitChar + value + newLineChar;
	int address = getNextAddress();
	for (int j = 0; j < str.length(); ++j) {
		EEPROM.write(address, str[j]);
		address++;
	}
	delay(10);
	EEPROM.commit();
	Log.info("stored in the eeprom");
}

/**
 * Read all key/values
 */
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

/**
 * Get a value for a given key
 */
String EEPROMUtil::get(String key) {
	String item = "";
	for (int k = startAddress; k < _eeprom_size; ++k) {
		char ch = char(EEPROM.read(k));

		if (ch == newLineChar) {
			// check item
			if (item.substring(0, item.indexOf(splitChar)) == key) {
				return item.substring((item.indexOf(splitChar) + 1),
						item.length());
			} else {
				item = "";
			}
		} else {
			item += ch;
		}
	}
	return "";
}

/**
 * Get the next address to store
 */
int EEPROMUtil::getNextAddress() {
	int current = startAddress;
	for (int k = startAddress; k < _eeprom_size; ++k) {
		if (char(EEPROM.read(k)) == newLineChar) {
			current = k;
		}
	}
	return current == startAddress ? current : (current + 1);
}

/**
 * Update the value for a given key
 */
void EEPROMUtil::update(const String& key, const String& value) {
	std::vector<String> items;
	String item = "";
	for (int k = startAddress; k < _eeprom_size; ++k) {
		char ch = char(EEPROM.read(k));

		if (ch == newLineChar) {
			// check item
			if (item.substring(0, item.indexOf(splitChar)) == key) {
				items.push_back(key + splitChar + value);
			} else {
				items.push_back(item);
			}
			item = "";
		} else {
			item += ch;
		}
	}

	// clear all
	clear();

	// write the vector to the EEPROM
	for (auto &i : items) {
		write(i.substring(0, i.indexOf(splitChar)),
				i.substring((i.indexOf(splitChar) + 1), i.length()));
	}
}

/**
 * Clear the EEPROM
 */
void EEPROMUtil::clear() {
	for (int i = 0; i < _eeprom_size; ++i) {
		EEPROM.write(i, emptyChar);
	}
	// don't know why we need to do it but a new line character apparently has to be written first
	EEPROM.write(0, newLineChar);
	EEPROM.commit();
	delay(10);
	Log.info("eeprom cleared");
}
