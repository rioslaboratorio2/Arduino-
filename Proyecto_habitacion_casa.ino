#include <Servo.h>

// variables 

//variables de luces 
int ledrojo = 9;
int ledverde = 10;

//servo movimiento cerradura 
Servo servo1;

//ultrasonido
int disparo = 7;
const int echo = 8;
int ledTest = 13;

//Inicio variables temporales

long tiempoPulso;
float distancia;

int rojo = 0;
int verde = 0;

void setup() {
 
  Serial.begin(9600);

 // ENTRADAS / SALIDAS
//iniciacion servo movimiento
  servo1.attach (A1);

   //salidas de los led 
   pinMode (ledrojo,OUTPUT);
   pinMode (ledverde, OUTPUT);
   
  
// iniciacion ultrasonido 
  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(disparo, LOW);

//encendido de led 
  pinMode (ledrojo  ,0);
  pinMode (ledverde ,0); 
  
  //Saludo Inicial
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
}


void loop() {
  
  //  Disparo de la senial.
  
  digitalWrite(disparo, HIGH);    // envio del pulso 
  delayMicroseconds(10);         //pausa para el control 
  digitalWrite(disparo, LOW);      
  
  tiempoPulso = pulseIn(echo, HIGH);
  distancia = 0.0340 / 2 * tiempoPulso;

  if(distancia<=7){
    servo1.write(90); 
  }else servo1.write(0); ;  
 
 if(distancia<=7){
  analogWrite  (ledverde ,255);  
 }else analogWrite  (ledverde ,0);analogWrite (ledrojo, 255);
  
    


  Serial.println(" Distancia"); 
  Serial.println(distancia);
  
    delay(1000);
}


  
