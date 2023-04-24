#ifndef Door3_h
#define Door3_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin3 = 35;
Servo servo3;
Ultrasonic ultrasonic3(5, 18);
static int d3, pos3;
void OpenDoor(int );
void CloseDoor(int );

void Door3(void *parameter){
  for(;;){
  d3= ultrasonic3.read();
  if(d3<=10 && pos3<= 50){
    OpenDoor(pos3);
    pos3 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d3>10 && pos3>150){
    CloseDoor(pos3);
    pos3 = 0;
  }
  }
}

#endif