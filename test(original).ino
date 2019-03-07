#include <Arduino.h>
#include <Convert.h>

int sensorValue = 0;
int ledPin = 13;
Convert a=Convert(ledPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue=analogRead(A0);
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(sensorValue);
  int blightness=voltage/2;
  delay(2);
  if(sensorValue>300){
    int t1=1;
    a.blink(20);
    float b=a.func((float)voltage);
    delay(2);
  }
}
