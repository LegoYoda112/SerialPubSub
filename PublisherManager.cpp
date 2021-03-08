#include "Arduino.h"
#include "PublisherManager.h"
#include "Publisher.h"

void PublisherManager::update(){
    String send_string = "";

    // Generate stirng to send
    for(int i = 0; i < num_pubs; i++){
        send_string += " " + publishers[i]->name + ": ";
        send_string += String(publishers[i]->value) + " ";
    }
    
    // "Yeet!"
    Serial.print(extra_string);
    Serial.println(send_string);

    // Purge extra_string
    extra_string = "";
}

void PublisherManager::manualPub(String name, double value){
    extra_string += " " + name + ": ";
    extra_string += String(value) + " ";
}

void PublisherManager::addPublisher(Publisher &publisher){
  publishers[num_pubs] = &publisher;
  num_pubs++;
}