#define sensorPin1 A0  // define entrada analógica A0
#define sensorPin2 A1  // define entrada analógica A1

int sensorValue1 = 0; 
int sensorValue2 = 0; 
float voltage1;
float voltage2;

void setup() 
{
  Serial.begin(9600);  // velocidade do monitor serial
  delay(100);  
}

void loop()
{
  sensorValue1 = analogRead(sensorPin1);  // leitura da entrada análoga A0
  sensorValue2 = analogRead(sensorPin2);  // leitura da entrada análoga A1
  voltage1 = sensorValue1 * (5.0 / 1024);  // Calculo da tensão 1
  voltage2 = sensorValue2 * (5.0 / 1024);  // Calculo da tensão 2

  Serial.print("Tensão do divisor 1: ");
  Serial.print(voltage1);  // imprime a tensão 1
  Serial.print(" Tensão do divisor 2: ");
  Serial.println(voltage2);  // imprime o tensão 2
  delay(500);
}
