#include "Arduino.h"
#include "PublisherManager.h"
#include "Publisher.h"

void PublisherManager::update(){
    String send_string = "";

    // Generate stirng to send
    for(int i = 0; i < MAX_PUBS; i++){
        // If publisher is not empty
        if(publishers[i]->name != "\0"){
            send_string += " " + publishers[i]->name + ": ";
            send_string += String(publishers[i]->value) + " ";
        }
    }
    
    // "Yeet!"
    Serial.println(send_string + extra_string);

    // Purge extra_string
    extra_string = "";
}

void PublisherManager::manualPub(String name, double value){
    extra_string += " " + name + ": ";
    extra_string += String(value) + " ";
}