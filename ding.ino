Microwave oven just lost the ding when turned to off. This file is a bookmark of curiosity into:
Sound sensors and how to calculate rotation of a knob.

C Code would look something like:
```
#include <stdio.h>
int calculateRotation(int soundLevel) {
  // Adjust these thresholds based on your specific sound sensor and knob rotation characteristics
  int rotationThreshold1 = 500;
  int rotationThreshold2 = 1000;
  int rotationThreshold3 = 1500;
  
  int rotation = 0;
  
  if (soundLevel < rotationThreshold1) {
    rotation = 0;
  } else if (soundLevel < rotationThreshold2) {
    rotation = 1;
  } else if (soundLevel < rotationThreshold3) {
    rotation = 2;
  } else {
    rotation = 3;
  }
  
  return rotation;
}

int main() {
  int soundLevel = 1200; // Replace this with the actual sound level from the sound sensor
  
  int rotation = calculateRotation(soundLevel);
  
  printf("Rotation: %d\n", rotation);
  
  return 0;
}
```

Rough-out for Arduino code:
```
const int soundSensorPin = A0; // Analog pin connected to the sound sensor

int calculateRotation(int soundLevel) {
  // Adjust these thresholds based on your specific sound sensor and knob rotation characteristics
  int rotationThreshold1 = 500;
  int rotationThreshold2 = 1000;
  int rotationThreshold3 = 1500;
  
  int rotation = 0;
  
  if (soundLevel < rotationThreshold1) {
    rotation = 0;
  } else if (soundLevel < rotationThreshold2) {
    rotation = 1;
  } else if (soundLevel < rotationThreshold3) {
    rotation = 2;
  } else {
    rotation = 3;
  }
  
  return rotation;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int soundLevel = analogRead(soundSensorPin);
  int rotation = calculateRotation(soundLevel);
  
  Serial.print("Rotation: ");
  Serial.println(rotation);
  
  delay(1000); // Adjust the delay as needed
}
```

