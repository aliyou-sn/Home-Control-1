#ifndef Door5_h
#define Door5_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin5 = 26;
Servo servo5;
Ultrasonic ultrasonic5(25, 33);
static int d5, pos5;
void OpenDoor5();
void CloseDoor5();

void Door5(void *parameter){
  for(;;){
  d5 = ultrasonic5.read();
  if(d5<=10 && pos5<= 50){
    OpenDoor5();
    pos5 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d5>10 && pos5>150){
    CloseDoor5();
    pos5 = 0;
  }
  }
}

void OpenDoor5(){
  for(pos5 = 0; pos5 <= 180; pos5++) {
        servo5.write(pos5);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor5(){
  for(pos5 = 180; pos5 >= 0; pos5--) {
        servo5.write(pos5);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}

#endif