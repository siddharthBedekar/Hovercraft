//headlights
#include <Servo.h>
#include <IRremote.h>
IRrecv irrecv(6);
decode_results results;
Servo myServo;
int pos = 0;
int stat = 0;
int signal=0;

void setup(){
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  myServo.attach(10);
  irrecv.enableIRIn();
}

void servoControl(int pos){
  myServo.write(pos); 
}
int ledControl(int stat){
  if (digitalRead(2)==1){
    Serial.println(digitalRead(2));
    if (stat == 1){
      digitalWrite(3, LOW);
      stat = 0;
      delay(500);
    }
    else{
      digitalWrite(3, HIGH);
      stat = 1;
      delay(500);
    }
    return stat;
  }
}
void loop(){ 
  stat=ledControl(stat);
  if (irrecv.decode(&results)){
    if (results.value != signal){
      signal = results.value;
      Serial.println(signal);
      if (signal==18086 ||signal==-16094){//right
      if (pos<170){
      pos+=10;}
        servoControl(pos);}
      if (signal==25539 ||signal==-3815){//up
        servoControl(75);
      pos=75;}
      if (signal== -18154||signal==4826){//left
      if (pos>10){
      pos-=10;}
        servoControl(pos);}
    }
  irrecv.resume();
  }
/*  servoControl(0);
  delay(1000);
  servoControl(75);
  delay(1000);
  servoControl(150);
  delay(1000);*/ 
}
