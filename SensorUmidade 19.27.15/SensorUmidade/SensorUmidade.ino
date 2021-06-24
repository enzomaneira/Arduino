#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11

#define DHTPIN 2
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS = 500;

void setup(){
  Serial.begin(9600);
  dht.begin();
  Serial.println("Usando Sensor DHT");
  sensor_t sensor;
}

void loop(){
  delay(delayMS);
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  if(isnan(event.relative_humidity)){
    Serial.println("Erro na leitura da umidade");
  }
  else
  {
  Serial.print("Umidade: ");
  Serial.print(event.relative_humidity);
  Serial.println("%");  
  }
}
