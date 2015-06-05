
void setup(){
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}
int readr= 0;
int readg= 0;
int readb= 0;
int r=255;
int g=255;
int b=255;
void loop(){
  delay(1000);
  Serial.println(analogRead(0));
  delay(1000);
  r=1023;
  g=0;
  b=0;
  analogWrite(11,r);
  analogWrite(10,g);
  analogWrite(9,b);
  Serial.println(analogRead(0));
  delay(1000);
  r=0;
  g=0;
  b=1023;
  analogWrite(11,r);
  analogWrite(10,g);
  analogWrite(9,b);
  Serial.println(analogRead(0));
  delay(1000);
  r=0;
  g=1023;
  b=0;
  analogWrite(11,r);
  analogWrite(10,g);
  analogWrite(9,b);
  Serial.println(analogRead(0));

}
