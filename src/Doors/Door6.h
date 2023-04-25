#ifndef Door6_h
#define Door6_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin6 = 32;
Servo servo6;
Ultrasonic ultrasonic6(35, 34);
static int d6, pos6;
void OpenDoor6();
void CloseDoor6();

void Door6(void *parameter){
  for(;;){
  d6 = ultrasonic6.read();
  if(d6<=10 && pos6<= 50){
    OpenDoor6();
    pos6 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d6>10 && pos6>150){
    CloseDoor6();
    pos6 = 0;
  }
  }
}

void OpenDoor6(){
  for(pos6 = 0; pos6 <= 180; pos6++) {
        servo6.write(pos6);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor6(){
  for(pos6 = 180; pos6 >= 0; pos6--) {
        servo6.write(pos6);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}

#endif