#ifndef Door1_h
#define Door1_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin1 = 33;
Servo servo1;
Ultrasonic ultrasonic1(13, 12);
static int d1, pos1;
void OpenDoor(int);
void CloseDoor(int);

void Door1(void *parameter){
  for(;;){
  d1 = ultrasonic1.read();
  if(d1<=10 && pos1<= 50){
    OpenDoor(pos1);
    pos1 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d1>10 && pos1>150){
    CloseDoor(pos1);
    pos1 = 0;
  }
  }
}

#endif
