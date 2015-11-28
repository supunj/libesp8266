/*
 * esp8266_common.ino
 *
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#include "esp8266util.h"
#include "eepromutil.h"

char* ssid = "MIFI-19B2";
char* password = "1234567890";
const int led = 2;

ESP8266Util esp8266(ssid, password);

//The setup function is called once at startup of the sketch
void setup() {
	pinMode(led, OUTPUT);
	digitalWrite(led, 0);
	Serial.begin(115200);
	esp8266.wifiConnect();
	esp8266.startWebServer();
	//String res1 = esp8266.httpGET("httpbin.org", 80, "/ip", 50);
	//Serial.print(res1);
	String res2 =
			esp8266.httpPOST("httpbin.org", 80, "/post",
					"dfsfsdghdsfjghjkdfhgjkdsf475483759483759834752312312hgdkjhfgdgjh&^%#^$^^^@#$@!$#^%!@#$@%^#!@#",
					1000);
	Serial.print(res2);

	EEPROMUtility.clear();
	EEPROMUtility.put("key1", "value1");
	Serial.println(EEPROMUtility.get("key1"));
}

// The loop function is called in an endless loop
void loop() {
	esp8266.mdnsUpdate();
	esp8266.handleWebClient();
}
