#ifndef Publisher_h
#define Publisher_h

#include "Arduino.h"

// Replace with message type?

class Publisher{
  public:
    double value = 0;
    String name;

    Publisher() {}
    
    Publisher(String new_name){
      name = new_name;
    }
};

#endif