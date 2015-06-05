void setup(){
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}
int r = 255;
int g = 0;
int b = 0;

void change(int R,int G,int B,int num){
  while (r != R && g!=G && b!=B){
  if (r< R){
  r+=1;}
  if (r > R){
  r-=1;}
  if (g< G){
  g+=1;}
  if (g > G){
  g-=1;}
  if (b< B){
  b+=1;}
  if (b > B){
  b-=1;}
  delay(num);
  Serial.println(r,g,b);
  analogWrite(11,r);
  analogWrite(10,g);
  analogWrite(9,b);
  }
  
}


void loop(){
  Serial.println((r,g,b));
change(255,255,255,100);



}

