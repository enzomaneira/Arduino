#include <Keypad.h>
#include <SegmentDisplay.h>

SegmentDisplay segmentDisplay(A0, A1, A2, A3, A4, A5, 12, 13);
// definição das portas para o segmento do display
// A0=E A1=D A2=C A3=D A4=B A5=A D12=F D13=G

const byte ROWS = 4;            // keypad 4 linhas
const byte COLS = 3;            // keypad 3 colunas

char hexaKeys[ROWS][COLS] =      // definição dos caracteres
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'E', '0', 'F'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};     // portas D11 a D8 -> linhas
byte colPins[COLS] = {7, 6, 5};          // portas D7 a D4 -> colunas 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);    // inicializa keypad

void setup() 
{
  Serial.begin(9600);
  // Definições das portas analógicas A0 a A5 como portas digitais de saidas
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  char customKey = customKeypad.getKey();   // le tecla pressionada
  int number = customKey - 48;              // converte caracter em número

  if ((number > 16) && (number < 23)){
    number = number - 7;
  }
  // se número for entre 17 e 22 subtraia 7 (para numeros hexadecimais

  if (customKey)
  {
    segmentDisplay.displayHex(number, false);   // mostra caracter no display sem ponto decimal
    Serial.println(number);
  }
}
