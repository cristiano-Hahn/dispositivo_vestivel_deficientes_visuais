#include <Ultrasonic.h>

  int echo = 3;
  int trig = 5;
  int saidaMotorVibracao = 6;
  Ultrasonic ultrassom(trig,echo);
  float timewait = 0;
  
  void setup() {
    Serial.begin(9600);
    pinMode(saidaMotorVibracao, OUTPUT);
  }
 
 void loop()
 {
   long distancia = 0;

   while (distancia == 0){
     distancia = ultrassom.Ranging(CM);
   }
     
   timewait = distancia * 4;

   if(distancia > 0 && distancia < 25){
      analogWrite(saidaMotorVibracao, 200);
      delay(50);
   }else if(distancia < 150){
      analogWrite(saidaMotorVibracao, 200);
      delay(200);
      analogWrite(saidaMotorVibracao, 0);
      delay(timewait);
   }else{
      analogWrite(saidaMotorVibracao, 0);
      delay(50);
   }
   
   Serial.print("Distância: ");
   Serial.print(distancia);
   Serial.print("cm ");

 }
 
