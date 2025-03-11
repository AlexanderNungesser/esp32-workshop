#include <ESP32Servo.h>

#define SERVO_PIN 33
#define PHOTO_PIN_1 32
#define PHOTO_PIN_2 34
#define LEFT 0
#define MIDDLE 90
#define RIGHT 180
#define MAX_PHOTO_VALUE 4096.0
#define SERVO_VALUE_RANGE 100.0

Servo servo;

void setup() {
  pinMode(PHOTO_PIN_1, INPUT);
  pinMode(PHOTO_PIN_2, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  int value_left = analogRead(PHOTO_PIN_1);
  int value_right = analogRead(PHOTO_PIN_2);
  int diff = value_right - value_left;
  float factor = SERVO_VALUE_RANGE / MAX_PHOTO_VALUE;
  float value = (diff * factor);
  int pos = (int)(value + MIDDLE);
  servo.write(pos);
  delay(1000);
}
