#include <Servo.h>
Servo myServo;
int pos = 0;

void setup(){
pinMode(1,OUTPUT);
pinMode(10,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
myServo.attach(10);
}

void loop(){
  Serial.println();
//  myServo.write(pos);
  Serial.println(pos);
 // pos = analogRead(0)/6;
  pos += 1;
  myServo.write(pos);
  delay(10);
  if (pos > 180) {
    pos = 0;
    myServo.write(pos);
    delay(1000);
  }

}
