#ifndef Door1_h
#define Door1_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin1 = 13;
Servo servo1;
Ultrasonic ultrasonic1(15, 2);
static int d1, pos1;
void OpenDoor1();
void CloseDoor1();
void Door1(void *parameter){
  for(;;){
  d1 = ultrasonic1.read();
  if(d1<=10 && pos1<= 50){
    OpenDoor1();
    pos1 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d1>10 && pos1>150){
    CloseDoor1();
    pos1 = 0;
  }
  }
}

void OpenDoor1(){
  for(pos1 = 0; pos1 <= 180; pos1++) {
        servo1.write(pos1);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor1(){
  for(pos1 = 180; pos1 >= 0; pos1--) {
        servo1.write(pos1);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
#endif
