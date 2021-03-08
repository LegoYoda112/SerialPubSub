#ifndef SubscriberManager_h
#define SubscriberManager_h

#include "Arduino.h"
#include "Subscriber.h"

class SubscriberManager{
  public:
    static const int MAX_SUBS = 10;
    Subscriber *subscribers[MAX_SUBS];

    int num_subs = 0;

    void update();
    void addSubscriber(Subscriber &subscriber); // TODO
};

#endif