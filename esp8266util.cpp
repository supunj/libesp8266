/*
 * CommonESP8266.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: sudiv
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include "base64.h"
#include "esp8266util.h"
//#include <ArduinoJson.h>
#include "eepromutil.h"

MDNSResponder mdns;
ESP8266WebServer server(80);
WiFiClient client;

ESP8266Util::ESP8266Util(char* sid, char* pwd, const int ind_led) :
		ssid(sid), password(pwd), indicator_led(ind_led) {
}

/**
 * Connect to the wifi
 */
void ESP8266Util::wifiConnect() {
	// set WiFi mode to station (client)
	WiFi.mode(WIFI_STA);

	// initiate
	WiFi.begin(ssid, password);
	Serial.println("");

	// Wait for connection
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	// get the ip address
	ip = WiFi.localIP();
	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(ip);

	if (mdns.begin("esp8266", ip)) {
		Serial.println("MDNS responder started");
	}
}

/**
 * Keep updating dns
 */
void ESP8266Util::mdnsUpdate() {
	mdns.update();
}

bool ESP8266Util::startWebServer() {
	// bind non-memeber functions
	std::function<void(void)> handleRoot(
			std::bind(&ESP8266Util::handleRoot, this));
	std::function<void(void)> handleNotFound(
			std::bind(&ESP8266Util::handleNotFound, this));
	std::function<void(void)> resetDevice(
			std::bind(&ESP8266Util::resetDevice, this));
	std::function<void(void)> restartDevice(
			std::bind(&ESP8266Util::restartDevice, this));
	std::function<void(void)> store(std::bind(&ESP8266Util::store, this));
	std::function<String(void)> readAll(std::bind(&ESP8266Util::readAll, this));
	std::function<void(void)> clearEEPROM(
			std::bind(&ESP8266Util::clearEEPROM, this));

	server.on("/", handleRoot);
	server.on("/reset", resetDevice);
	server.on("/restart", restartDevice);
	server.on("/store", store);
	server.on("/readall", readAll);
	server.on("/clear", clearEEPROM);
	server.onNotFound(handleNotFound);
	server.begin();
	Serial.println("HTTP server started");
	return true;
}

/**
 * handle web server root
 */
void ESP8266Util::handleRoot() {
	digitalWrite(indicator_led, 1);
	char temp[400];
	int sec = millis() / 1000;
	int min = sec / 60;
	int hr = min / 60;

	snprintf(temp, 400,

			"<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Hello from ESP8266!</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
    <img src=\"/test.svg\" />\
  </body>\
</html>",

			hr, min % 60, sec % 60);
	server.send(200, "text/html", temp);
	digitalWrite(indicator_led, 0);
}

/**
 * handle resource not found
 */
void ESP8266Util::handleNotFound() {
	digitalWrite(indicator_led, 1);
	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += (server.method() == HTTP_GET) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";

	for (uint8_t i = 0; i < server.args(); i++) {
		message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
	}

	server.send(404, "text/plain", message);
	digitalWrite(indicator_led, 0);
}

/**
 * handle web requests
 */
void ESP8266Util::handleWebClient() {
	server.handleClient();
}

/**
 * reset the device
 */
void ESP8266Util::resetDevice() {
	server.send(200, "text/plain", "device reset called");
	wdt_enable(WDTO_0MS);
	while (1) {
	}
}

/**
 * restart the device
 */
void ESP8266Util::restartDevice() {
	server.send(200, "text/plain", "device restart called");
	digitalWrite(12, LOW);
	delay(100);
	digitalWrite(12, HIGH);
}

/**
 * send http get request
 */
String ESP8266Util::httpGET(char* host, int port, String uri, const int wait) {
	if (!client.connect(host, port)) {
		Serial.println("connection failed");
		return "";
	}

	// this will send the request to the server
	client.print(
			String("GET ") + uri + " HTTP/1.1\r\n" + "Host: " + host + "\r\n"
					+ "Connection: close\r\n\r\n");

	// wait till response comes
	delay(wait);

	// read all the lines of the reply from server and print them to Serial
	String response = "";
	while (client.available()) {
		response.concat(client.readString());
		response.concat(client.readStringUntil('\r'));
	}

	//Serial.print(response);
	//Serial.println();
	Serial.println("closing connection");
	return response;
}

/**
 * send http post request
 */
String ESP8266Util::httpPOST(char* host, int port, String uri, String payload,
		const int wait) {
	if (!client.connect(host, port)) {
		Serial.println("connection failed");
		return "";
	}

	String enc = base64_encode(
			reinterpret_cast<const unsigned char*>(payload.c_str()),
			payload.length());

	// this will send the request to the server
	client.print(
			String("POST ") + uri + " HTTP/1.1\r\n" + "Host: " + host + "\r\n"
					+ "Accept: */*\r\n" + "Content-Length: " + enc.length()
					+ "\r\n"
					+ "Content-Type: application/x-www-form-urlencoded\r\n"
					+ "Connection: close\r\n\r\n" + enc);

	// wait till response comes
	delay(wait);

	// read all the lines of the reply from server and print them to Serial
	String response = "";
	while (client.available()) {
		response.concat(client.readStringUntil('\r'));
	}

	//Serial.print(response);
	//Serial.println();
	Serial.println("closing connection");
	return response;
}

void ESP8266Util::store() {
	EEPROMUtility.put("key1", "test");
	server.send(200, "text/plain", "key/value stored");
	Serial.println(EEPROMUtility.get("key1"));
}

String ESP8266Util::readAll() {
	String str = EEPROMUtility.readAll();
	Serial.println(str);
	server.send(200, "text/plain", str);
	return str;
}

void ESP8266Util::clearEEPROM() {
	EEPROMUtility.clear();
	server.send(200, "text/plain", "EEPROM cleared");
}

ESP8266Util::~ESP8266Util() {

}
