#ifndef Subscriber_h
#define Subscriber_h

#include "Arduino.h"

class Subscriber{
  public:
    double value = 0;
    String name = "\0";

    Subscriber() {}
    
    Subscriber(String new_name){
      value = 0;
      name = new_name;
    }
};

#endif