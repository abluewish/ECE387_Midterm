#include "Arduino.h"
#include "Convert.h"

Convert::Convert(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Convert::blink()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

float Convert::func(float v)
{
    return v/400*255;
}
