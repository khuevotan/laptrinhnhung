#include "DHT.h"
#define dht_1 2 
#define DHTTYPE DHT11
DHT dht(dht_1, DHTTYPE);
void setup() {
  dht.begin();
}

void loop() {
  float doam = dht.readHumidity();
  float nhietdo = dht.readTemperature();
  if(nhietdo > 30) {
    digitalWrite(12,HIGH);
   } 
   else
    digitalWrite(12,LOW);
  if(doam <40 ) {
    digitalWrite(13,HIGH);
   } 
   else
    digitalWrite(13,LOW);
}
