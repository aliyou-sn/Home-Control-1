#ifndef Door2_h
#define Door2_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin2 = 12;
Servo servo2;
Ultrasonic ultrasonic2(4, 5);
static int d2, pos2;
void OpenDoor2();
void CloseDoor2();

void Door2(void *parameter){
  for(;;){
  d2 = ultrasonic2.read();
  if(d2<=10 && pos2<= 50){
    OpenDoor2();
    pos2 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d2>10 && pos2>150){
    CloseDoor2();
    pos2 = 0;
  }
  }
}


void OpenDoor2(){
  for(pos2 = 0; pos2 <= 180; pos2++) {
        servo2.write(pos2);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor2(){
  for(pos2 = 180; pos2 >= 0; pos2--) {
        servo2.write(pos2);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}

#endif