
int disparo = 2;
int eco= 4; 
int ledtest= 13; 
long tiempopulso; 
float distanciamedida; 


//inicio del main 
//iniciamos los pines de salida
void setup() {
  Serial.begin(9600); 
pinMode (ledtest, OUTPUT);
pinMode (disparo,OUTPUT);
pinMode (eco, INPUT);

digitalWrite (disparo,LOW);
digitalWrite (ledtest,LOW); 

//hacemos el saludo inicial

 digitalWrite (ledtest,HIGH); 
  delay(500); 
  digitalWrite (ledtest,LOW); 
  delay(500);
  digitalWrite (ledtest,HIGH); 
  delay(500);
  digitalWrite (ledtest,LOW); 
  delay(500);
  digitalWrite (ledtest,HIGH); 
  delay(500);
  digitalWrite (ledtest,LOW); 
  delay(500);
}

void loop() {
  digitalWrite (disparo, HIGH);
  delayMicroseconds(10); 
    digitalWrite (disparo, LOW);

    tiempopulso = pulseIn(eco,HIGH); 
    distanciamedida= 0.034 / 2 * tiempopulso; 

    Serial.println("tiempo / distancia"); 
    Serial.print(tiempopulso); 
    Serial.print('/');
    Serial.println(distanciamedida);
    delay(500);

    
}
