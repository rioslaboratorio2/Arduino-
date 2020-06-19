
//definir constantes de entrada 

const int emisorizquierda = 9;
const int emisorderecha = 8;
const int ledtest = 13; 

//definir constantes de entrada 

const int receptorizquierda = A0;
const int receptorderecha = A1;

//datos de reflactividad 

int refleizquierda = 0;
int reflederecha = 0;

void setup() {
Serial.begin (9600);
  
pinMode (emisorizquierda, OUTPUT);
pinMode (emisorderecha, OUTPUT);
pinMode (ledtest, OUTPUT);

digitalWrite (emisorizquierda, LOW);
digitalWrite (emisorderecha, LOW);
digitalWrite (ledtest, LOW);

//saludo inicial 

for (int i=0;i<3; i++){
  digitalWrite(ledtest, HIGH);
  delay(500);
  digitalWrite(ledtest, LOW);
  delay(500);
}

}

void loop() {

  digitalWrite(emisorizquierda, HIGH);
    refleizquierda = analogRead (receptorizquierda);
    delay(100);
  digitalWrite (emisorizquierda,LOW);

  digitalWrite(emisorderecha, HIGH);
    reflederecha = analogRead (receptorderecha);
    delay(100);
  digitalWrite (emisorderecha,LOW);

  //enviamos al puerto serie informacion 

 Serial.println("Izquierda / Derecha");
 Serial.print(refleizquierda);
 Serial.print(",");
 Serial.println(reflederecha);
 delay(500);  
}
