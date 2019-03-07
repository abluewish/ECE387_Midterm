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

float Convert::func(float v)
{
    return 300/v*255;
}
