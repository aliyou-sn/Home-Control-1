#ifndef Door3_h
#define Door3_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin3 = 14;
Servo servo3;
Ultrasonic ultrasonic3(18, 19);
static int d3, pos3;
void OpenDoor3();
void CloseDoor3();
void Door3(void *parameter){
  for(;;){
  d3= ultrasonic3.read();
  if(d3<=10 && pos3<= 50){
    OpenDoor3();
    pos3 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d3>10 && pos3>150){
    CloseDoor3();
    pos3 = 0;
  }
  }
}

void OpenDoor3(){
  for(pos3 = 0; pos3 <= 180; pos3++) {
        servo3.write(pos3);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor3(){
  for(pos3 = 180; pos3 >= 0; pos3--) {
        servo3.write(pos3);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}

#endif