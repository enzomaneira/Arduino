const byte ledAm = 9;        
const byte ledAz = 10;
const byte ledV = 11;
const byte botao1 = 2;
const byte botao2 = 3;

void setup()
{
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(ledAm, OUTPUT);
  pinMode(ledAz, OUTPUT);
  pinMode(ledV, OUTPUT);
  
}

void loop(){
  if((digitalRead(botao2) == HIGH)&&(digitalRead(botao1)==LOW)){
    // se interruptor 2 estiver ligado e 1 desligado 
    digitalWrite(ledAm, HIGH); // apenas led amarela liga
    digitalWrite(ledAz, LOW);
    digitalWrite(ledV, LOW);
    delay(100);
  }
  else if((digitalRead(botao2) == LOW)&&(digitalRead(botao1)==HIGH)){
    // se interruptor 1 estiver ligado e 2 desligado
    digitalWrite(ledAm, LOW);
    digitalWrite(ledAz, HIGH); // apenas led azul liga
    digitalWrite(ledV, LOW);
    delay(100);
  }
  else if((digitalRead(botao2) == HIGH)&&(digitalRead(botao1)==HIGH)){
    // se ambos interruptores estirem ligados todos leds ligam 
    digitalWrite(ledAm, HIGH);
    digitalWrite(ledAz, HIGH);
    digitalWrite(ledV, HIGH);
    delay(100);
  }
  else{
    // se nenhum interruptor estiver ligado nenhum led acende
    digitalWrite(ledAm, LOW);
    digitalWrite(ledAz, LOW);
    digitalWrite(ledV, LOW);
  }
}
