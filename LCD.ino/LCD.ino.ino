#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);       // pinos do lcd - RS E D4 D5 D6 D7
int contador = 0;

void setup(){
  lcd.begin(16, 2);                       // inicializa lcd
  delay(500);
}

void loop(){
  lcd.clear();                          // limpa tela lcd
  lcd.setCursor(0, 0);                  // seleciona coluna 0 linha 0
  lcd.print("MLManeira");
  lcd.setCursor(1, 1);
  lcd.print(contador);
  contador++;
  if(contador == 60)
    contador = 0;
   delay(1000);
  
}
