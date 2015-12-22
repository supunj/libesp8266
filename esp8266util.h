/*
 *  Created on: Nov 13, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#ifndef ESP8266UTIL_H_
#define ESP8266UTIL_H_

#include <IPAddress.h>
#include <WString.h>

#include "eepromutil.h"

enum Sensor {
	Temperature, Humidity, Motion
};

class ESP8266Util {
private:
	char* ssid;
	char* password;
	IPAddress ip;
	int indicator_led;
	int eeprom_size;
	//char* mqtt_server;
	void handleRoot();
	void handleNotFound();

public:
	ESP8266Util(char* ssid = "", char* passwords = "", const int ind_led = 2,
			const int rom_size = DEF_EEPROM_SIZE);
	virtual ~ESP8266Util();
	// initialize
	void start();
	// connect to wifi
	void wifiConnect();
	// keep on updating dns
	void mdnsUpdate();
	// start the web server
	bool startWebServer();
	// handle web client
	void handleWebClient();
	// resset the device
	void resetDevice();
	// resset the device
	void restartDevice();

	// call https end point
	String httpGET(char* host, int port, String uri, const int wait = 10);
	// call https end point
	String httpPOST(char* host, int port, String uri, String payload,
			const int wait = 10);

	// write/read data to and from EEPROM
	void store();
	String readAll();
	void clearEEPROM();
	void eepromStore();

	// Json handling
	String getJson(Sensor sensor);

	// get NTP date/time
	static time_t getNTPTime();

	// get date/time
	uint32_t getDateTime();
	String getStrDateTime();

	// converts the IPAddress to String
	String ipToString(IPAddress ip);
};

#endif /* ESP8266UTIL_H_ */
