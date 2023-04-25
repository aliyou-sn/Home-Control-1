#include <Arduino.h>
#include "Doors/Door1.h"
#include "Doors/Door2.h"
#include "Doors/Door3.h"
#include "Doors/Door4.h"
// #include "Doors/Door5.h"
// #include "Doors/Door6.h"
void setup(){
    Serial.begin(9600);
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
    servo3.attach(servoPin3);
    servo4.attach(servoPin4);
    // servo5.attach(servoPin5);
    // servo6.attach(servoPin6);
    xTaskCreate(Door1,"Door1", 5000, NULL, 2, NULL);
    xTaskCreate(Door2,"Door2", 3000, NULL, 3, NULL);
    xTaskCreate(Door3,"Door3", 5000, NULL, 5, NULL);
    xTaskCreate(Door4,"Door4", 5000, NULL, 5, NULL);
    // xTaskCreate(Door5,"Door5", 5000, NULL, 5, NULL);
    // xTaskCreate(Door6,"Door6", 5000, NULL, 5, NULL);
    
}

void loop() {
}
