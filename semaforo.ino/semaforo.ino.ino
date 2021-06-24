//Projeto  - Semáforo

int delayLED = 5000;
int green = 11;
int yellow = 12;
int red = 13;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(delayLED); 
  
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000); 
  
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  delay(delayLED);
  
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(1000); 
  
  digitalWrite(yellow, LOW);
  

}
