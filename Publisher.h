#ifndef Publisher_h
#define Publisher_h

#include "Arduino.h"

// Replace with message type?

class Publisher{
  public:
    double value = 0;
    String name = "\0";

    Publisher() {}
    
    Publisher(String new_name){
      value = 0;
      name = new_name;
    }
};

#endif