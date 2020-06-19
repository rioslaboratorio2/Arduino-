
int ledRojo = 11;
int ledVerde = 10;
int ledAzul = 9;
int disparo = 4;
int echo =2;
int rojo = 0;
int verde = 0;
int azul = 0;
long tiempoPulso;
float dstMedida;
void setup() {
pinMode(ledRojo, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledAzul, OUTPUT);
pinMode(disparo, OUTPUT);
pinMode(echo, INPUT);
analogWrite(ledRojo, 255);
analogWrite(ledVerde, 255);
analogWrite(ledAzul, 255);
}
void loop() {
  
digitalWrite(disparo, LOW);
delayMicroseconds(5);
digitalWrite(disparo, HIGH);
delayMicroseconds(10);

digitalWrite(disparo, LOW);
tiempoPulso = pulseIn(echo, HIGH);
dstMedida = 0.0340 / 2 * tiempoPulso;

Serial.println(dstMedida);

if (dstMedida < 20){
  analogWrite(ledVerde, 0);
  analogWrite(ledAzul, 0);
  analogWrite(ledRojo, 255);
  delay(50);
  
  analogWrite(ledRojo, 255);
  delay(50);}
else {
analogWrite(ledRojo, 255);
analogWrite(ledVerde, 0);
analogWrite(ledAzul,255);
}
}
