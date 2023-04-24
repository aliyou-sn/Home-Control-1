#ifndef Door4_h
#define Door4_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin4 = 34;
Servo servo4;
Ultrasonic ultrasonic4(19, 21);
static int d4, pos4;
void OpenDoor(int );
void CloseDoor(int );

void Door4(void *parameter){
  for(;;){
  d4 = ultrasonic4.read();
  if(d4<=10 && pos4<= 50){
    OpenDoor(pos4);
    pos4 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d4>10 && pos4>150){
    CloseDoor(pos4);
    pos4 = 0;
  }
  }
}

#endif