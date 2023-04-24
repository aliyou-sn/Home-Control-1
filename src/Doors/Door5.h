#ifndef Door5_h
#define Door5_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin5 = 36;
Servo servo5;
Ultrasonic ultrasonic5(22, 23);
static int d5, pos5;
void OpenDoor(int );
void CloseDoor(int );

void Door5(void *parameter){
  for(;;){
  d5 = ultrasonic5.read();
  if(d5<=10 && pos5<= 50){
    OpenDoor(pos5);
    pos5 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d5>10 && pos5>150){
    CloseDoor(pos5);
    pos5 = 0;
  }
  }
}

#endif