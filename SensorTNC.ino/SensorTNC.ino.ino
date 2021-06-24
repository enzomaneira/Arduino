#define Vin 5.0               // define constante = 5
#define T0 298.15             // define constante = 298.15 Kelvin
#define Rt 10000              // resistor do divisor de tensao
#define R0 10000 .            // valor da resistencia inicial do NTC
#define T1 273.15             // [K] in datasheet 0C
#define T2 373.15             // [K] in datasheet 100C
#define RT1 35563             // [ohms] resistencia in T1
#define RT2 549               // [ohms] resistencia in T2

float beta = 0.0;             // parametros iniciais kelvin
float Rinf = 0.0;             // parametros iniciais ohm
float TempKelvin = 0.0;       // variavel output
float TempCelsius = 0.0;      // variavel output
float TempFarenheit = 0.0;    // variavel output
float Vout = 0.0;             // vout in A0
float Rout = 0.0;             // rout in A0


void setup() {
  Serial.begin(9600);
  beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2));   // calculo do beta
  Rinf = 1000 * exp(-beta / T0);                      // calculo de Rinf
  delay(100);
}

void loop() {
  Vout = Vin * ((float)(analogRead(0)) / 1024.0);   // calculo de V0 e leitura de A0
  Rout = (Rt * Vout / (Vin - Vout));                 // calculo de Rout
  TempKelvin = (beta / log(Rout / Rinf));           // calculo da temp em Kelvin
  TempCelsius = TempKelvin - 273.15;                // calculo da temp em Celsius
  TempFarenheit = (9 * (TempCelsius / 5)) + 32;
  Serial.print("Temperatura em Celsius: ");
  Serial.print(TempCelsius);
  Serial.print(" Temperatura em Farenheint: ");
  Serial.println(TempFarenheit);
  delay(500);
}
