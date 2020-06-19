
// entradas de RGB ********************************************************************************************

int ledrojo = 9;
int ledverde= 12;
int ledazul=  8;

const int ledtest  = 13;

// entradas foto resistencias ********************************************************************************

const int fotoizquierda = A0;
const int fotoderecha = A1;


 

// entrada de motores ******************************************************************************************

int AIA =  3;
int AIB =  11;
int BIB =  6;
int BIA =  10;

int receptores = 0;
int receptorizquierdo = 0;
int receptorderecho = 0;

void setup() {
  // serial nos permite leer los valores a traves del monitor serie *****************************************************
  Serial.begin (9600);

  // inicio de los pines de salida ****************************************************************************************
 
  pinMode (ledrojo, OUTPUT);
  pinMode (ledverde, OUTPUT);
  pinMode (ledazul, OUTPUT);

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

  analogWrite(ledrojo , 0);
  analogWrite(ledverde, 0);
  analogWrite(ledazul , 0);

  // saludo inicial *************************************************************************************************

  digitalWrite (ledtest , HIGH);
  delay (500);
  digitalWrite (ledtest , LOW);
  delay(500);
  digitalWrite (ledtest , HIGH);
  delay (500);
  digitalWrite (ledtest , LOW);
  delay(500);
  digitalWrite (ledtest , HIGH);
  delay (500);
  digitalWrite (ledtest , LOW);
  delay(500);

}

void loop() {

  // con esta variable acumulo los valores de los sensores y dependiendo de cada suma activare cada color de RGB ***********************************************
  
  receptores = receptorderecho + receptorizquierdo;

  receptorizquierdo = analogRead (fotoizquierda);
  receptorderecho = analogRead (fotoderecha);

  Serial.print (receptorizquierdo);
  Serial.print ("    ,    ");
  Serial.println (receptorderecho);

// Con este condicional el robot puede verificar los niveles de luz mediante el led RGB-- ROJO> nivel bajo AZUL> nivel medio VERDE> nivel alto 

if (receptores > 1900){
  analogWrite (ledrojo, 255); 
  delay(500); 
  analogWrite (ledrojo,0);
  
}else if (receptores > 1200 && receptores <= 1800){
  analogWrite (ledazul, 255);
  delay(500);
  analogWrite (ledazul,0);
  
}else if (receptores < 600 ){
analogWrite  (ledverde,255); 
delay(200);
analogWrite (ledverde,0);
delay(200);  
} else analogWrite (ledverde,0);analogWrite (ledrojo,0);analogWrite (ledazul,0);

// este condicional determina la direccion del robot mediante la medicion de luz ****************************************************************************

  if (receptorderecho < 500 && receptorizquierdo < 500 ){
  adelante (); 
  
  } else if (receptorderecho < 500 && receptorizquierdo > 500) {
     izquierda();
    delay(50);

  } else  if (receptorderecho > 500 && receptorizquierdo < 500){
    derecha();
  
  }else  stope();
  
  delay(50);
  
  
}
  
 
  // iniciacion  de las funciones  ******************************************************************************************************************************
  
  void adelante () {
    
    analogWrite (AIA, 255);
    analogWrite (AIB, 0);
    analogWrite (BIA, 0);
    analogWrite (BIB, 255);

  }
  
  void izquierda () {
    analogWrite (AIA, 255);
    analogWrite (AIB, 0);
    analogWrite (BIA, 255);
    analogWrite (BIB, 255);

  }
   void derecha () {
    analogWrite (AIA, 255);
    analogWrite (AIB, 255);
    analogWrite (BIA, 0);
    analogWrite (BIB, 255);

  }
  
  void stope () {
    analogWrite (AIA, 0);
    analogWrite (AIB, 0);
    analogWrite (BIA, 0);
    analogWrite (BIB, 0);

  }
 
