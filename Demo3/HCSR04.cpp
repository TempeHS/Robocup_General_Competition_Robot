#include "HCSR04.h"
#include <Arduino.h>

HCSR04::HCSR04() {
}

HCSR04::HCSR04(int trigger, int echo) {
  _trigger = trigger;
  _echo = echo;
  pinMode(_trigger, OUTPUT);
  pinMode(_echo, INPUT);
  maxDistance = 200;
  timeout = 100;
}

void HCSR04::begin() {
}

int HCSR04::getDistance() {
  digitalWrite(_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger, LOW);
  unsigned long m = pulseIn(_echo, HIGH);
  float d= m * 0.034 / 2;
  delay(15);
  if(d<=maxDistance){
    return (int)d;
  }
  else{
    return 0;
  }
}