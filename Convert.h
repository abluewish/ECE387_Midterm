#ifndef Convert_h
#define Convert_h

#include "Arduino.h"

class Convert{
  public:
    Convert(int pin);
    void blink(int t);
    float func(float a);
  private:
    int _pin;
    int t;
    float a;
};

#endif
