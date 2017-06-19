#include <dht.h>

dht DHT;

#define DHT11_PIN 3

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print(DHT.temperature);
  Serial.print("\t");
  Serial.print(DHT.humidity);
  Serial.println("\t");
  delay(10000);
}
