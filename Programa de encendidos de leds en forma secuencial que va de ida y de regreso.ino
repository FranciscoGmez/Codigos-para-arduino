
void setup() {

  // put your setup code here, to run once:

for(int x=0; x<=4; x++){
pinMode(x, OUTPUT);

}
}

void loop() {

  // put your main code here, to run repeatedly:

for (int y=0; y<=4; y=y+1){
  digitalWrite(y, HIGH);
  delay(100);
  digitalWrite(y, LOW);
}

for (int y=4; y>=0; y=y-1){
  digitalWrite(y, HIGH);
  delay(100);
  digitalWrite(y, LOW);
}
}
