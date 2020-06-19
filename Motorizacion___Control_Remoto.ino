#include <IRremote.h>

//definir variables 

int ledtest = 13;

//seteo del receptor 

int receptorcontrol = 2; 

IRrecv receptorIr (receptorcontrol);

decode_results codigoleido; 
decode_results codigoleidoNuevo;

int AIA =  3;
int AIB =  11;
int BIB =  6;
int BIA =  10;

// seteo del led rojo 

int ledrojo  =  9 ;
int ledverde = 8;
int ledazul  =  12;

int potenciarojo  = 0;
int potenciaverde  = 0;
int potenciaazul  = 0;

void setup() {

Serial.begin(9600);
receptorIr.enableIRIn();

  pinMode (ledtest, OUTPUT);
  pinMode (AIA, OUTPUT);
  pinMode (AIB, OUTPUT);
  pinMode (BIA, OUTPUT);
  pinMode (BIB, OUTPUT);

  digitalWrite(ledtest , LOW);
  analogWrite (AIA, 0);
  analogWrite (AIB, 0);
  analogWrite (BIA, 0);
  analogWrite (BIB, 0);
  


pinMode (ledrojo ,OUTPUT);
pinMode (ledverde ,OUTPUT);
pinMode (ledazul,OUTPUT);


analogWrite (ledrojo, 0);
analogWrite (ledverde, 0);
analogWrite (ledazul, 0);

pinMode (ledtest ,OUTPUT);
pinMode (ledtest ,LOW);


//SALUDO INICIAL 

digitalWrite (ledtest, HIGH);
delay (500);
digitalWrite (ledtest, LOW);
delay (500);
digitalWrite (ledtest, HIGH);
delay (500);
digitalWrite (ledtest, LOW);
delay (500);
digitalWrite (ledtest, HIGH);
delay (500);
digitalWrite (ledtest, LOW);
delay (500);
}

void loop() {
  
if(receptorIr.decode (&codigoleidoNuevo)){
  receptorIr.resume ();
  }

if (codigoleidoNuevo.value!= codigoleido.value && codigoleidoNuevo.value != 0xFFFFFFFF){
  digitalWrite (ledtest ,HIGH);
  delay(50);
  digitalWrite (ledtest, LOW);

  Serial.println(codigoleido.value, HEX);
  codigoleido = codigoleidoNuevo; 


if (codigoleido.value==0xFF18E7) {
  adelante();(ledverde,255);  
  delay(1000); 
  
}else if (codigoleido.value==0xFF4AB5){
  atras (); (ledrojo,255);
  delay(1000); 
  
  
}else if (codigoleido.value==0xFF38C7){
  stope();(ledrojo,0); (ledverde,0); (ledazul,0);
  delay(100); 
  
}else if (codigoleido.value==0xFF30CF){
  izquierda();(ledazul,255); 
  delay(1000); 
  
}else if (codigoleido.value==0xFF7A85){
  derecha();(ledrojo,255); (ledverde,255); (ledazul,255);
  delay(1000); 
}
  
  
  }
}


void adelante () { 
  analogWrite (AIA,255);
  analogWrite (AIB,0);
  analogWrite (BIA,0);
  analogWrite (BIB,255);
}

void atras (){
  analogWrite (AIA,0);
  analogWrite (AIB,255);
  analogWrite (BIA,255);
  analogWrite (BIB,0);
}


void derecha () { 
  analogWrite (AIA,255);
  analogWrite (AIB,255);
  analogWrite (BIA,0);
  analogWrite (BIB,255);
}

 void izquierda () {
    analogWrite (AIA, 255);
    analogWrite (AIB, 0);
    analogWrite (BIA, 255);
    analogWrite (BIB, 255);

  }
  void stope () {
    analogWrite (AIA, 0);
    analogWrite (AIB, 0);
    analogWrite (BIA, 0);
    analogWrite (BIB, 0);

  }
