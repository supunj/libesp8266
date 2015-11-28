/*
 * CommonESP8266.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#ifndef ESP8266UTIL_H_
#define ESP8266UTIL_H_

#include <IPAddress.h>
#include <WString.h>

class ESP8266Util {
private:
	char* ssid;
	char* password;
	IPAddress ip;
	int indicator_led;
	void handleRoot();
	void handleNotFound();

public:
	ESP8266Util(char* ssid, char* passwords, const int ind_led = 2);
	virtual ~ESP8266Util();
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
};

#endif /* ESP8266UTIL_H_ */
