

int disparo = 4;
int eco = 2; 

int ledtest = 13; 

int ledrojo = 11;
int ledverde=10;
int ledazul = 9; 
int intensidad = 0; 

long tiempopulso; 
long tiempovalor;



void setup() {

  pinMode(ledtest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(eco, INPUT);

  digitalWrite(disparo,LOW);
  analogWrite(ledrojo,0);
  analogWrite(ledverde,0);
  analogWrite(ledazul,0);

  for(int i=0; i <3; i++){
    digitalWrite(ledtest,HIGH);
    delay (500);
    digitalWrite(ledtest,LOW);
    delay (500);
  }
  
}

void loop() {

  digitalWrite(disparo,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(disparo,LOW);
  delayMicroseconds(10);

  tiempopulso = pulseIn(eco,HIGH);

  if (tiempopulso < 550){
    analogWrite(ledrojo,  255);
    analogWrite(ledverde, 0);
    analogWrite(ledazul,  0);
  
  }else if (tiempopulso>=550 && tiempopulso<860){
    analogWrite(ledrojo, 255);
    analogWrite(ledverde, 255);
    analogWrite(ledazul, 0);

  }else if (tiempopulso>=860&& tiempopulso<1140){
    analogWrite(ledrojo, 0);
    analogWrite(ledverde, 255);
    analogWrite(ledazul, 0);
  }else{
    tiempovalor = constrain (tiempopulso,1140, 5700);
    
    intensidad = map(tiempovalor,1140,5700,0,255); 
    
    analogWrite(ledrojo,intensidad);
    analogWrite(ledverde,intensidad); 
    analogWrite(ledazul,intensidad);  
  }
  
  
}
