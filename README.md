# DHT12
Simple Arduino and esp8266 library for the DHT12 (I2C)  

Testet on WeMos D1  

datasheet: http://www.robototehnika.ru/file/DHT12.pdf  

#include <DHT12.h>  
DHT12 DHT(0x5c);  // Init with I2C-add  

DHT.readDHT12();    // read   
DHT.Temperature;    // in °C  
DHT.Humidity            // in %  
DHT.Dew_point        // in °C  
