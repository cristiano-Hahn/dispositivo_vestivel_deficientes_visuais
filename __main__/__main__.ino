#include <Ultrasonic.h>

  int echo = 3;
  int trig = 5;
  int saidaMotorVibracao = 6;
  Ultrasonic ultrassom(trig,echo);
  
  void setup() {
    Serial.begin(9600);
    pinMode(saidaMotorVibracao, OUTPUT);
  }
 
 void loop()
 {
   long distancia = ultrassom.read(CM);

   if(distancia > 0 && distancia < 50){
      analogWrite(saidaMotorVibracao, 200);
   }else if(distancia >= 50 && distancia < 120){
      analogWrite(saidaMotorVibracao, 200);
      delay(200);
      analogWrite(saidaMotorVibracao, 0);
      delay(distancia);
   }else{
      analogWrite(saidaMotorVibracao, 0);
   }
   
   Serial.print("Distância: ");
   Serial.print(distancia);
   Serial.println("cm ");
 }
 
