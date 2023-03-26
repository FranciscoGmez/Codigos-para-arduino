// Prototipo:

// Desarrollo del programa.

// Variables del sensor ultrasonico:

int trig = 10;
int echo = 9;

// Variables de los LED´s:

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;

// Variables del funcionamiento del sensor ultrasonico:

int tiempo = 0;
int distancia = 0;

// Segunda parte del programa:

void setup (){

pinMode(trig, OUTPUT);
pinMode(echo,INPUT);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);

}

void loop (){

digitalWrite(trig,HIGH);
delayMicroseconds(500);
digitalWrite(trig,LOW);
tiempo = pulseIn(echo,HIGH);
distancia = tiempo/58.5;
delayMicroseconds(500);

if (distancia <= 4){
  digitalWrite(led1,HIGH);
}
else{
  digitalWrite(led1,LOW);
}
if (distancia <= 8){
  digitalWrite(led2,HIGH);
}
else{
  digitalWrite(led2,LOW);
}
if (distancia <= 12){
  digitalWrite(led3,HIGH);
}
else{
  digitalWrite(led3,LOW);
}
if (distancia <= 16){
  digitalWrite(led4,HIGH);
}
else{
  digitalWrite(led4,LOW);
}
if (distancia <= 20){
  digitalWrite(led5,HIGH);
}
else{
  digitalWrite(led5,LOW);
}
if (distancia <= 24){
  digitalWrite(led6,HIGH);
}
else{
  digitalWrite(led6,LOW);
}
if (distancia <= 28){
  digitalWrite(led7,HIGH);
}
else{
  digitalWrite(led7,LOW);
}

}



