int RainIn = A0;
int RainDigitalIn = 2;
int RainVal;
boolean Raining = false;


void setup() {
  Serial.begin(9600);
  pinMode(RainDigitalIn,INPUT);
}
void loop() {
  RainVal = analogRead(RainIn);
  Raining = !(digitalRead(RainDigitalIn));
  
  Serial.print("Raining: ");
  Serial.print(!(digitalRead(RainDigitalIn)));
  Serial.print("\t Moisture Level: ");
  Serial.println(1023-RainVal);
  
  delay(200);

}
