
const int ledtest = 13; 
int ledazul = 8;

//constantes de entradas 

const int fotoizquierda = A0;
const int fotoderecha = A1;

// datos de salida 

int valorderecha = 0 ;
int valorizquierda = 0 ; 
int azul = 0 ; 

void setup() {

 Serial.begin(9600);

 //iniciamos entradas y salidas 
 
 pinMode (ledazul ,OUTPUT); 
 analogWrite (azul, 0 );
 
 pinMode (ledtest , OUTPUT);
 digitalWrite (ledtest , LOW);
 delay(500);
 digitalWrite (ledtest, HIGH );
 delay(500);
 digitalWrite (ledtest, LOW  );
 delay(500);
 digitalWrite (ledtest, HIGH );
 delay(500);
 digitalWrite (ledtest, LOW  );
 delay(500);
 digitalWrite (ledtest, HIGH );
 delay(500); 
}

void loop() {
  
valorizquierda = analogRead (fotoizquierda);
delay(500);
valorderecha = analogRead (fotoderecha);
delay(500);

// condicion que nos permite saber si hay bajo nivel de luz y encender nuestro led de iluminacion 

if (valorderecha > 400 && valorizquierda > 400){
  analogWrite (ledazul , 255);  
}else { analogWrite (ledazul, 0); 

}
delay (500); 


Serial.println ("IZQUIERDA / DERECHA");
Serial.print (valorizquierda);
Serial.println (valorderecha);
delay(500); 
}
