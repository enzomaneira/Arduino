  int LED = 10;

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500); 
}
