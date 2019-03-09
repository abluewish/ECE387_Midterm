#include <Arduino.h>
#include <Convert.h>

int sensorValue = 0;
int ledPin = 13;
Convert a=Convert(ledPin);
int count=0;
float base;
float arr[20];
float arr2[2]={0.0,0.0};
int force=1.2; //subject to be changed by the user(from 0 to 2.5) 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue=analogRead(A0);
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(voltage);
  if(count<20){
    if (abs(arr[count-1]-voltage)>0.3 && count>1)
      count--;
    arr[count]=voltage;
    base=0;
  }
  count++;
  if(count==20){
    base=a.base(arr);
    Serial.print("The base voltage is");
    Serial.print(base);
  }
  float vol=(voltage-base)/(5-base)*5;
  Serial.print(vol);
  Serial.println("V");
  int blightness=voltage/2;
  arr2[0]=arr2[1];
  arr2[1]=vol;
  bool lightflag=a.light(count, vol,arr2[0]);
  if(lightflag){
//    a.blink(20);
//    for(int i=0; i<vol;i++){
//      a.blink(20);
//    }
    a.func(vol/force);
  }
}
