#ifndef Door2_h
#define Door2_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin2 = 32;
Servo servo2;
Ultrasonic ultrasonic2(2, 4);
static int d2, pos2;
void OpenDoor(int );
void CloseDoor(int );

void Door2(void *parameter){
  for(;;){
  d2 = ultrasonic2.read();
  if(d2<=10 && pos2<= 50){
    OpenDoor(pos2);
    pos2 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d2>10 && pos2>150){
    CloseDoor(pos2);
    pos2 = 0;
  }
  }
}

#endif