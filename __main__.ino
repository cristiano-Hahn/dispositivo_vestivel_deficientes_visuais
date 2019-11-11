#include <Ultrasonic.h>

  int echo = 3;
  int trig = 5;
  int saidaMotorVibracao = 6;
  Ultrasonic ultrassom(trig,echo);
  float frequencia = 0;
  
  void setup() {
    Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
    pinMode(saidaMotorVibracao, OUTPUT);
  }
 
 void loop()
 {
   
   long distancia = ultrassom.Ranging(CM);
   if(distancia > 0 && distancia < 120){
      frequencia = 200 - distancia;
   }else if (distancia > 120){
    frequencia = 0;
   }
  
   analogWrite(saidaMotorVibracao, frequencia);

   /*
   Serial.print("Distância: ");
   Serial.print(distancia);
   Serial.print("cm ");
   Serial.print("Frequência: ");
   Serial.println(frequencia);
   */
   delay(50);
 }
 
