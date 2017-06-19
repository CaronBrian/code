#include<Wire.h>
#include <dht.h> //dht11
#include <SFE_BMP180.h>
dht DHT;
SFE_BMP180 pressure;


#define DHT11_PIN 3


int rainsensorReading;
int rain;
const int rainsensorMin = 0;
const int rainsensorMax = 1024;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pressure.begin();

}

void loop() {

  char status;
  double T,P,p0,a;

  status = pressure.startTemperature();
  if (status != 0)
  {

    delay(status);

    status = pressure.getTemperature(T);
    if (status != 0)
    {
     
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
        }
        
      }
      
    }
    
  }
  
  rainsensorReading = analogRead(A1);
  int range = map(rainsensorReading, rainsensorMin, rainsensorMax, 0, 3);
  int chk = DHT.read11(DHT11_PIN);

  

  
  

    switch (range) {
    case 0:    // Sensor getting wet
      rain=0;
      break;
    case 1:    // Sensor getting wet
       rain=1;
       break;
    case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
       rain=2;
       break;
  

    }
  
Serial.println((T,2),(P,2),(DHT.humidity,1)+":"+String(rain)));

  //Serial.print(DHT.temperature);
  //Serial.print("\t");
  //Serial.print(bmp.readAltitude());
  //Serial.print("\t");
  //Serial.print(DHT.humidity);
  //Serial.print("\t");
  //Serial.print(rain);
  //Serial.println("\t");



  //  Serial.print("Temperature = ");
//  Serial.print(bmp.readTemperature());
//  Serial.println(" *C");
//
//  Serial.print("Altitude = ");
//  Serial.print(bmp.readAltitude());
//  Serial.println(" meters");
//
//
//  
//  Serial.print("Temperature = ");
//  Serial.println(DHT.temperature);
//  Serial.print("Humidity = ");
//  Serial.println(DHT.humidity);

  
  delay(10000);

}
