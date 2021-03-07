#ifndef Subscriber_h
#define Subscriber_h

#include "Arduino.h"

class Subscriber{
  public:
    double value = 0;
    String name;

    Subscriber() {}
    
    Subscriber(String new_name){
      name = new_name;
    }
};

#endif