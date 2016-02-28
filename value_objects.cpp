/*
 *  Created on: Jan 9, 2016
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#include <WString.h>
#include <vector>

class Reading {

private:
	String reading;
	String value;
	String uom = "";
	String timestamp;
	double lat;
	double lon;
public:
	Reading() {
	}

	virtual ~Reading() {
	}

	double getLat() const {
		return lat;
	}

	void setLat(double lat) {
		this->lat = lat;
	}

	double getLon() const {
		return lon;
	}

	void setLon(double lon) {
		this->lon = lon;
	}

	const String& getReading() const {
		return reading;
	}

	void setReading(const String& reading) {
		this->reading = reading;
	}

	const String& getTimestamp() const {
		return timestamp;
	}

	void setTimestamp(const String& timestamp) {
		this->timestamp = timestamp;
	}

	const String& getUom() const {
		return uom;
	}

	void setUom(const String& uom) {
		this->uom = uom;
	}

	const String& getValue() const {
		return value;
	}

	void setValue(const String& value) {
		this->value = value;
	}

	String toJSON() {
		return "{\"reading\":\"" + reading + "\",\"value\":\"" + value
				+ "\",\"uom\":\"" + uom + "\",\"timestamp\":\"" + timestamp
				+ "\",\"lat\":" + lat + ",\"lon\":" + lon + "}";
	}
};

class Event {
private:
	String user;
	String hub;
	String device;
	String sensor;
	std::vector<Reading> readings;

	// get the json for readings array
	String getReadingsJSON() {
		String str = "";
		for (unsigned i = 0; i < readings.size(); i++) {
			str += readings[i].toJSON();

			if (i != (readings.size() - 1)) {
				str += ",";
			}
		}
		return str;
	}

public:
	Event() {
	}

	virtual ~Event() {
	}

	const String& getDevice() const {
		return device;
	}

	void setDevice(const String& device) {
		this->device = device;
	}

	const String& getHub() const {
		return hub;
	}

	void setHub(const String& hub) {
		this->hub = hub;
	}

	const String& getSensor() const {
		return sensor;
	}

	void setSensor(const String& sensor) {
		this->sensor = sensor;
	}

	const String& getUser() const {
		return user;
	}

	void setUser(const String& user) {
		this->user = user;
	}

	void addReading(const Reading& reading) {
		readings.push_back(reading);
	}

	void clearReadings() {
		readings.clear();
	}

	String toJSON() {
		return "{\"user\":\"" + user + "\",\"hub\":\"" + hub
				+ "\",\"device\":\"" + device + "\",\"sensor\":\"" + sensor
				+ "\",\"readings\":[" + getReadingsJSON() + "]}";
	}
};
