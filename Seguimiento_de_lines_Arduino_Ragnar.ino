//variables de salidas 

const int emisorizquierda = 9;
const int emisorderecha = 8;

const int ledtest = 13;

//variables de los motores 

const int AIA =11 ; 
const int AIB= 3;
const int BIA = 10;
const int BIB = 6; 

//variables de entrada (recetores)

const int receptorizquierda = A0;
const int receptorderecha = A1 ; 

//valores

int valorizquierda = 0;
int valorderecha = 0; 



void setup() {

//iniciando salidas 

pinMode (emisorizquierda , OUTPUT);
pinMode (emisorderecha, OUTPUT);
pinMode (ledtest , OUTPUT); 

digitalWrite (ledtest, LOW);
analogWrite (emisorizquierda,0);
analogWrite (emisorderecha , 0) ;

 pinMode(AIA,OUTPUT);
 pinMode(AIB,OUTPUT);
 pinMode(BIA,OUTPUT);
 pinMode(BIB,OUTPUT);

  analogWrite (AIA,0);
 analogWrite (AIB,0);
 analogWrite (BIA,0);
 analogWrite (BIB,0);

//saludo unicial 
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

Serial.begin(9600);
}

void loop() {
  digitalWrite (ledtest, HIGH);
  digitalWrite (emisorizquierda, HIGH);
  valorizquierda = analogRead (receptorizquierda); 
  
  digitalWrite (emisorderecha, HIGH);
  valorderecha = analogRead (receptorderecha); 
digitalWrite (ledtest, LOW);


Serial.print (valorizquierda);
Serial.print (",");
Serial.print (valorderecha); 

movimiento();
delay(500);
}

void movimiento() {
  if (valorderecha <970 && valorizquierda <970){
    atras();
    }else if (valorderecha >970 && valorizquierda>970){
      adelante();
    }else if (valorderecha < 970 && valorizquierda > 970){
      derecha();   
    }else if (valorderecha >970 && valorizquierda <970){
      izquierda(); 
    }
 }

void adelante(){
  analogWrite (AIA ,150);
  analogWrite (AIB ,0);
  analogWrite (BIA ,150);
  analogWrite (BIB ,0);
}
void atras(){
  analogWrite (AIA ,0);
  analogWrite (AIB ,255);
  analogWrite (BIA ,0);
  analogWrite (BIB ,255);
}
void derecha(){
  analogWrite (AIA ,255);
  analogWrite (AIB ,255);
  analogWrite (BIA ,0);
  analogWrite (BIB ,255);
}
void izquierda(){
  analogWrite (AIA ,255);
  analogWrite (AIB ,0);
  analogWrite (BIA ,255);
  analogWrite (BIB ,255);
}
