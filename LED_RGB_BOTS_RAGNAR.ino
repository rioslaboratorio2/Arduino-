
  //INICIACION PARA LED RGB 

int ledrojo = 9;
int ledverde= 10;
int ledazul=  11;
int ledtest = 13,

int rojo=0; 
int verde= 0;
int azul = 0 ;
int todos= 0;


void setup() {






  
// iniciando los pines de salida
pinMode (ledrojo, OUTPUT);
pinMode (ledverde, OUTPUT);
pinMode (ledazul, OUTPUT);
pinMode (ledtest, OUTPUT);

analogWrite(ledrojo , 0);
analogWrite(ledverde ,0);
analogWrite(ledazul , 0);

analogWrite(ledtest,LOW);


// SALUDO INICIAL ... 
  for (int i = 0 ; i<3;i++){
    digitalWrite(ledtest, HIGH); 
    delay (1000);
    digitalWrite(ledtest, LOW); 
    delay (500); 
  }
}

void loop() {
// DEFINICION DE FUNCION QUE ENCIENDAN TODOS LOS LED 
for (rojo =0 ; rojo>=255; rojo++){
  analogWrite(ledrojo, rojo); 
  delay(10); 
}for (rojo=255; rojo>=0;rojo--){
  analogWrite(ledrojo,rojo); 
  delay(10); 
  
}for (verde =0 ; verde>=255; verde++){
  analogWrite(ledverde, verde); 
  delay(10); 
}for (verde=255; verde>=0;verde--){
  analogWrite(ledverde,verde); 
  delay(10); 
  
}for (azul =0 ; azul>=255; azul++){
  analogWrite(ledazul, azul); 
  delay(10); 
}for (azul=255; azul>=0;azul--){
  analogWrite(ledazul,azul); 
  delay(10); 
}

analogWrite (ledrojo,255);
analogWrite (ledverde,0);
analogWrite (ledazul,0);

for (verde=0; verde<=255;verde++){
  analogWrite(ledverde, verde);
  delay(10);}

  for (azul=0; azul<=255;azul++){
  analogWrite(ledazul, azul);
  delay(10)}

  for (verde=255; verde>=0;verde--){
  analogWrite(ledverde,verde); 
  delay(10); }

for (rojo=255; rojo>=0;rojo--){
  analogWrite(ledrojo,rojo); 
  delay(10); }
  
for (azul=255; azul>=0;azul--){
  analogWrite(ledazul,azul); 
  delay(10); }

  delay(100); 

  for (todos=0; todos<=255;todos++){
    analogWrite(ledrojo,todos); 
    analogWrite(ledverde,todos);
    analogWrite(ledazul,todos);
    delay(30); 
  }
  for (todos=0; todos>=0;todos--){
    analogWrite(ledrojo,todos); 
    analogWrite(ledverde,todos);
    analogWrite(ledazul,todos);
    delay(30); 
  }
}
