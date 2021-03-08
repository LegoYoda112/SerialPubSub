#ifndef PublisherManager_h
#define PublisherManager_h

#include "Arduino.h"
#include "Publisher.h"

class PublisherManager{
    public:
        static const int MAX_PUBS = 10;
        Publisher *publishers[MAX_PUBS];

        int num_pubs = 0;

        String extra_string = "";

        void update();
        void manualPub(String name, double value);
        void addPublisher(Publisher &publisher); // TODO
};

#endif