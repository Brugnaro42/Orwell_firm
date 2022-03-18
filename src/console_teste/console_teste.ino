#include <Servo.h>

Servo servo1;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  servo1.write(val);
//  delay(100);
//  val = val+5;
//  Serial.println(val);
//  if (val==180){
//    val = 0;
//  }
//  delay(15);
}
