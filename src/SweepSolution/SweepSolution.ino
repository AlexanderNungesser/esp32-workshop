#include <ESP32Servo.h>

#define SERVO_PIN 33
#define LEFT 0
#define RIGHT 180

Servo servo;
int pos = 1;
int step = 1;

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {
  servo.write(pos);
  if (pos <= LEFT || pos >= RIGHT) {
    step = step * (-1);
  }
  pos += step;
  delay(30);
}
