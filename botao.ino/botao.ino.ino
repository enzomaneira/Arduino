const byte led = 13;       // declara pino de entrada do led
const byte interruptor = 2;  // declara pino de entrada do interruptor
const byte buzzer = 12;     // declara pino de entrada buzzer
volatile byte state = HIGH; // declara variavel mutavel state como high


void setup()
{              
  pinMode(interruptor, INPUT_PULLUP);   // inicializa interrutor como input
  pinMode(buzzer, OUTPUT);   // inicializa buzzer como output
  pinMode(led, OUTPUT);  // inicia led output
  attachInterrupt(digitalPinToInterrupt(interruptor),blink,CHANGE);
  // inicializa função de interrupção quando interrutor 
  // muda de estado
}

void loop()
{
  // se state for TRUE(ou seja, não foi acionado) 
  while(state)
  { 
  noTone(buzzer); // buzzer fica silencioso
  digitalWrite(led, HIGH); 
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  // led pisca
  }
  // se state for FALSE(ou seja, foi acionado)
  digitalWrite(led, HIGH); // led fica aceso
    tone(buzzer,300,100); // buzer toca
    delay(100);
  
}

void blink()
{ 
  // função de interrupção muda o estado
  state = !state;
  
}
