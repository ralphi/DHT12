#include <DHT12.h>

DHT12 DHT(0x5c);  

void setup() {
  Serial.begin(9600);
  Serial.println("DHT12 start");
}

void loop() {
	if ( DHT.readDHT12() ){
  
		Serial.print("Temperature: ");
		Serial.print(DHT.Temperature);
		Serial.print(" *C");  
		Serial.print(" Humidity: ");
		Serial.print(DHT.Humidity);
		Serial.print("% ");
		Serial.print(" Dew_point: ");
		Serial.println(DHT.Dew_point);
	}else{
		Serial.println(" ERROR: ");
	}
	delay(5000);
}
