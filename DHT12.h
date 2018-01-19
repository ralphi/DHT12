/*
	DHT12.h - Library for DHT12 sensor.
	by ralphi Alex B.
	v0.1 
*/
#ifndef DHT12_h
#define DHT12_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#define DHT12_ADDRESS   (0x5A)
#define ERR 101

class DHT12
{
	public:
		DHT12(int id = 0x5c);
		bool readDHT12();
		float Temperature = 20;
		float Humidity = 50;
		float Dew_point = 0;
	private:
		bool read();
		byte data[10];
		int _id;
		bool readTemperature();
		bool readHumidity();
		bool getTP();
		double DD();
		double SDD();
};

#endif