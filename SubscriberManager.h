#ifndef SubscriberManager_h
#define SubscriberManager_h

#include "Arduino.h"
#include "Subscriber.h"

class SubscriberManager{
  public:
    Subscriber *subscribers[5];
    void update();
    void addSubscriber(Subscriber subscriber); // TODO
};

#endif