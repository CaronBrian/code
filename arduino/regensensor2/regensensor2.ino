int RainAnaloog = A0;
int RainDigitalIn = 2;


void setup() {
  Serial.begin(9600);
  pinMode(RainAnaloog, OUTPUT);
}
void loop() {
  // analoge output
  if(analogRead(0)<300) Serial.println("heavy raining");
  else if (analogRead(0)<500) Serial.println("light rain");
  else Serial.println("no rain");


  // // digitale output
  // if digitalRead(3) == HIGH) Serial.println("No Rain detected");
  // else Serial.println("rain detected");
  delay(250);

}
