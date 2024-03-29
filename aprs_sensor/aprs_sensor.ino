int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 13;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
int ledState = LOW;
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(19200);   
  pinMode(LEDpin, OUTPUT);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  //Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, LOW, HIGH);
  digitalWrite(LEDpin, LEDbrightness);
 
  delay(1000);
}
