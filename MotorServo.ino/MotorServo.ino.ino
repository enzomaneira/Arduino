#include <Servo.h>

Servo myservo;                      // cria objeto myservo

#define potpin A0                  

int va1 = 0;                 

void setup() {
  myservo.attach(9);                // configura pino D6 - controle do Servo
}

void loop() {
 for(va1 = 0; va1 <= 180;  va1 += 1) {
   myservo.write(va1);                // controle PWM do servo 
   delay(15);                         // atraso de 15 milisegundos
 }
}
