#ifndef PublisherManager_h
#define PublisherManager_h

#include "Arduino.h"
#include "Publisher.h"

class PublisherManager{
    public:
        static const int MAX_PUBS = 5;
        Publisher *publishers[MAX_PUBS];

        String extra_string = "";

        void update();
        void manualPub(String name, double value);
        void addPublisher(Publisher publisher); // TODO
};

#endif