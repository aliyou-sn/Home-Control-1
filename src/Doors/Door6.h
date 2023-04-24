#ifndef Door6_h
#define Door6_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin6 = 35;
Servo servo6;
Ultrasonic ultrasonic6(27, 26);
static int d6, pos6;
void OpenDoor(int );
void CloseDoor(int );

void Door6(void *parameter){
  for(;;){
  d6 = ultrasonic6.read();
  if(d6<=10 && pos6<= 50){
    OpenDoor(pos6);
    pos6 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d6>10 && pos6>150){
    CloseDoor(pos6);
    pos6 = 0;
  }
  }
}

#endif