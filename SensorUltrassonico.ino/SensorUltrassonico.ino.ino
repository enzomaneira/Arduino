int PinTrigger = 2;         // pino usada para disparar os pulsos do sensor

int PinEcho = 3;            // pino usada para ler a saída do sensor

float TempEcho = 0;         // variável tempo do eco

const float velocidadeSom_mps = 340;

const float velocidadeSom_mpus = 0.000340; 
 
void setup()
{
 pinMode(PinTrigger, OUTPUT);      
 digitalWrite(PinTrigger, LOW);   
 pinMode(PinEcho, INPUT);
 Serial.begin(9600);
 delay(100); 
}

void loop() 
{
  DisparaPulsoUltrassonico(); 
  TempEcho = pulseIn(PinEcho, HIGH);      // mede duracao do pulso HIGH de eco em microseg
  Serial.print("Distancia em metros: ");
 
  Serial.println(CalculaDistancia(TempEcho));
  Serial.print("Distancia em centímetros: ");
  Serial.println(CalculaDistancia(TempEcho) * 100);
  delay(2000); 
}

void DisparaPulsoUltrassonico()
{
  digitalWrite(PinTrigger, HIGH);
  delay(300);
  digitalWrite(PinTrigger, LOW);
}

float CalculaDistancia(float tempo_us)
{
  return ((tempo_us * velocidadeSom_mpus) / 2);
}
