#include "Arduino.h"
#include "Convert.h"

Convert::Convert(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Convert::blink(int t)  // let LED blink in a period of 2t
{
  digitalWrite(_pin, HIGH);
  delay(t);
  digitalWrite(_pin, LOW);
  delay(t);  
}

float Convert::func(float v) //convert the voltage signal from sensor to the PWM input we will use
{
    return 300/v*255;
}
