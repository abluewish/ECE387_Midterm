#include "Arduino.h"
#include "Convert.h"


Convert::Convert(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Convert::blink(int t)
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Convert::func(float v)
{
    if(v < 0)
        break;
    int b = v/5*225;
    analogWrite(_pin, b);
    delay(10);
}

float Convert::base(float b[]){
    bool flag=true;
    float mean=b[0];
    for(int i=0;i<sizeof(b)-1;i++){
        if(abs(b[1]-b[0])>0.2 && abs(b[2]-b[0])>abs(b[2]-b[1]) && i==0){
            mean=(b[1]+b[2])/2;
            i++;
        }
        if (abs(b[i]-mean)>0.2) //elimate undesired data
            flag=false;
        if(flag){
            mean+=b[i];
            mean/=2;
        }
    }
    return mean;
}

bool Convert::light(int count, float v, float c){
    if(count>20 && v>0.5)
        if(abs(c-v)<=0.2*v)
            return true;
    return false;
}
