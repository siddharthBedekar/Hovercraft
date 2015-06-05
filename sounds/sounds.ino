void setup(){
  pinMode(11,OUTPUT);
}

void loop(){
  for (int i=0; i < 2000; i ++ ){
    tone(11,i);
  }

}
