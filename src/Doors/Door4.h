#ifndef Door4_h
#define Door4_h
#include <Servo.h>
#include <Ultrasonic.h>
static const int servoPin4 = 27;
Servo servo4;
Ultrasonic ultrasonic4(21,22);
static int d4, pos4;
void OpenDoor4();
void CloseDoor4();

void Door4(void *parameter){
  for(;;){
  d4 = ultrasonic4.read();
  if(d4<=10 && pos4<= 50){
    OpenDoor4();
    pos4 = 180;
  }
  vTaskDelay(300 / portTICK_PERIOD_MS);
  if(d4>10 && pos4>150){
    CloseDoor4();
    pos4 = 0;
  }
  }
}

void OpenDoor4(){
  for(pos4 = 0; pos4 <= 180; pos4++) {
        servo4.write(pos4);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}
void CloseDoor4(){
  for(pos4 = 180; pos4 >= 0; pos4--) {
        servo4.write(pos4);
        vTaskDelay(15 / portTICK_PERIOD_MS);
    }
}

#endif