
#include <Adafruit_BMP085.h>
#include <dht.h> //dht11

dht DHT;

#define DHT11_PIN 7
Adafruit_BMP085 bmp;

int rainsensorReading;
const int rainsensorMin = 0;
const int rainsensorMax = 1024;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bmp.begin();

}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");


  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);

  rainsensorReading = analogRead(A1);
  int range = map(rainsensorReading, rainsensorMin, rainsensorMax, 0, 3);
  


  switch (range) {
    case 0:    // Sensor getting wet
      Serial.println("Rainsensor: Raining");
      break;
    case 1:    // Sensor getting wet
       Serial.println("Rainsensor: Light rain");
       break;
    case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
       Serial.println("Rainsensor:  Not raining");
       break;
  }
  delay(2500);

}
