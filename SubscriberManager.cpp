#include "Arduino.h"
#include "SubscriberManager.h"
#include "Subscriber.h"

void SubscriberManager::update(){

  if(Serial.available() > 0){
    char c = 'a';
    int inputIndex = 0;
    String inputString = "";
    String inputArgs[5];
    //Serial.print("Receiving string: ");
    while(c != '\n'){
      delay(1);
      if(Serial.available() > 0) {
        c = Serial.read();
        inputString += c;
        //Serial.print(c);
      }
      
      if(c == ' '){
        inputString.remove(inputString.length()-1);
        inputArgs[inputIndex] = inputString;
        inputIndex += 1;
        inputString = "";
      }
    }
    inputString.remove(inputString.length()-1);
    inputArgs[inputIndex] = inputString;

    //Serial.println("Finished parsing");
    //Serial.print("Command: ");
    //Serial.println(inputArgs[0]);
    //Serial.println(inputArgs[1]);

    String name = inputArgs[0];
    name.trim();
    double val = inputArgs[1].toDouble();
    
    // Search through subscriber list to see if the name matches
    for(int i = 0; i < MAX_SUBS; i++){
      
      if(name.equals(subscribers[i]->name) == 1){
        Serial.println(val);
        subscribers[i]->value = val;
      }
    }
  }
}

void SubscriberManager::addSubscriber(Subscriber &subscriber){
  subscribers[num_subs] = &subscriber;
  num_subs++;
}