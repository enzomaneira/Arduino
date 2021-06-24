#include <Servo.h> 

Servo myservo; 

#define potpin A0 
 
int val;

void setup()
{
  myservo.attach(6);
}

void loop(){
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 179);
  myservo.write(val);
  delay(15);
}
