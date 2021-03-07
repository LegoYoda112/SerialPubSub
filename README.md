# SerialPubSub
Simple Pub-Sub over serial library for arduino. Works great with a regex on the other side. Built it to get that ROS feeling on projects that ROS would be overkill on.

Usage (mostly for me if I forget lol):

### Includes:

```C++
#include <Publisher.h>
#include <PublisherManager.h>

#include <Subscriber.h>
#include <SubscriberManager.h>
```

### Setting up a publisher

```C++
// Create manager object
PublisherManager pm;

// Create a publisher
Publisher pub_a = Publisher("pub_a");

void setup(){
  Serial.begin(rate);
  
  // Add the publisher to the manager's list
  pm.publishers[0] = &pub_a;
}

void loop(){
  // do stuff
  
  // Update the publisher's value
  pub_a.value = value;
  
  // do stuff
  
  // Publishes all values over serial
  pm.update();
}
```

Expected output over serial is ```pub_a: value```. The output (with multible values) can be read using the regex:
```regex 
/([A-Za-z_]+):\s([-0-9.]+)/g
```


### Setting up a subscriber
```C++
// Create manager object
SubscriberManager sm;

// Create a subscriber
Subscriber sub_a = Subscriber("sub_a");

void setup(){
  Serial.begin(rate);
  
  // Add the subscriber to the manager's list
  sm.subscribers[0] = &sub_a;
}

void loop(){
  // do stuff
  
  // Do something with the subscribers value
  Serial.println(sub_a.value);
  
  // do stuff
  
  // Reads serial buffer and updates subscriber values
  sm.update();
}
```

Expected input `sub_a: value`. (only accepts one value per line... for now)

### TODO:
(if I ever get time, spoiler alert, I won't)
- Create a pubsub manager that does both!
- Better way of adding pubs and subs
- Python and js modules?? Might be overkill at this point haha
- Figure out how to dynamically resize the publisher and subscriber arrays, C++ does not like to do this
