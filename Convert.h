#ifndef Convert_h
#define Convert_h
#include<Math.h>

#include "Arduino.h"

class Convert{
  public:
    Convert(int pin);
    void blink(int t);
    void func(float a);
    float base(float b[]);
    bool light(int count, float v, float c);
  private:
    int _pin;
    int t;
    int count;
    float a, v;
    float c;
    float b[];
};

#endif
