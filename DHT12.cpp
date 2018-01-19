
#include "DHT12.h"

DHT12::DHT12(int id)
{
	_id = id;
	Wire.begin();  
}

bool DHT12::read() {

	Wire.beginTransmission( _id );
	Wire.write( 0x00 );
	if (Wire.endTransmission() != 0) return false;  
	
	Wire.requestFrom( _id, 5);
	byte i = 0;
	while(Wire.available()) {
		data[i] = Wire.read();
		i++;
	};
	delay(50);
	if (i < 5) return false;
	if (data[4] != (data[0]+data[1]+data[2]+data[3]) ) return false;
	
	return true;
}

bool DHT12::readDHT12() {
	if ( ! read() ) return false; 
	if ( ! getTP() ) return false;
		return true;
}

bool DHT12::readTemperature() {
	float result = 0;
	if ( (data[2] & 0x80) ){
		result = (-1) * ( data[2] + ( (float)data[3] / 10 ) ); // negativer Wert
	}else{
		result = ( (data[2] & 0x7f) + ( (float)data[3]/10 ) ); // positiver Wert
	}
	Temperature = result; // ***************
	return true;
}

bool DHT12::readHumidity()
{
	float result;
	result = (data[0]+(float)data[1]/10);

	Humidity = result;
	return true;
}

// Dew_point
bool DHT12::getTP() {
	if ( ! readTemperature()) { return false; }
	if ( ! readHumidity() ) { return false; }
  float a = (Temperature >= 0) ? 7.5 : 7.6;
  float b = (Temperature >= 0) ? 237.3 : 240.7;
  float v = log10(DD() / 6.1078);
  float td = b * v / (a - v);
  
  Dew_point = td;
  return true;
}

double DHT12::DD() {
  double dd = Humidity / 100 * SDD();
  return dd;
}
double DHT12::SDD() {
  float a = (Temperature >= 0) ? 7.5 : 7.6;
  float b = (Temperature >= 0) ? 237.3 : 240.7;
  float exponent = ((a * Temperature) / (b + Temperature));
  float sdd = 6.1078 * pow(10, exponent);
  return sdd;
}

