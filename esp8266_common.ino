/*
 * esp8266_common.ino
 *
 *  Created on: Nov 16, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */
#include "esp8266util.h"
#include "eepromutil.h"
#include "serial_logger.h"

char* ssid = "MIFI-19B2";
char* password = "1234567890";
/*char* ssid = "Supun's mi4i";
 char* password = "12345678";*/
const int led = 2;
const int serial_port = 9200;
ESP8266Util esp8266(ssid, password, 2, 512);
Event *ev;

//The setup function is called once at startup of the sketch
void setup() {
	Log.start(serial_port);
	esp8266.start();
	esp8266.wifiConnect();
	esp8266.startWebServer();

	Log.info(esp8266.getMAC());

	/*EEPROMUtility.clear();
	 EEPROMUtility.put("key1", "value1");
	 Serial.println(EEPROMUtility.get("key1"));*/
}

// The loop function is called in an endless loop
void loop() {
	esp8266.mdnsUpdate();
	esp8266.handleWebClient();
	ev = esp8266.createEvent();
	ev->setSensor(Sensors().HUMIDITY);
	ev->setHub("My HUB");
	ev->setUser("supun");
	Reading rd;
	rd.setLat(6.801864);
	rd.setLon(79.8931625);
	rd.setTimestamp(esp8266.getStrDateTime());
	ev->addReading(rd);

	String res3 = esp8266.httpPOST("httpbin.org", 80, "/post", ev->toJSON(),
			1000);
	delay(5000);

	Log.info(res3);
}
