/*
 * ntpclient.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Supun Jayathilake (supunj@gmail.com)
 */

#ifndef NTPCLIENT_H_
#define NTPCLIENT_H_

#include <Udp.h>

class NTPClient {
public:
	NTPClient();
	virtual ~NTPClient();
	static unsigned long ntpUnixTime(UDP &udp);
};

#endif /* NTPCLIENT_H_ */
