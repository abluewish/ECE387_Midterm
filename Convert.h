#ifndef Convert_h
#define Convert_h

#include "Arduino.h"

class Convert{
  public:
    Morse(int pin);
    void blink();
    void func();
  private:
    int _pin;
};

#endif
