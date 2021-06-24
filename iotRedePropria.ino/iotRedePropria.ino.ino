#include "SoftwareSerial.h"

SoftwareSerial ESP_Serial(10, 11); // RX, TX

String rede = "PINKAP"; 
String senha = "dago2012";
String resposta = "";

void setup() {
  Serial.begin(9600);
  ESP_Serial.begin(9600);

  Serial.println("Inicializando...");
  delay(1000);

  Serial.println("Conectando a rede...");
  String CWJAP = "\"AT+CWJAP=\"";
  CWJAP += rede;
  CWJAP += "\",\"";
  CWJAP += senha;
  CWJAP += "\"";
  sendCommand(CWJAP);
  readResponse(10000);

  delay(2000); //espera de seguranca

  if (resposta.indexOf("OK") == -1) { //procura na resposta se houve OK
    Serial.println("Atencao: Nao foi possivel conectar a rede WiFi.");
    Serial.println("Verifique se o nome da rede e senha foram preenchidos corretamente no codigo e tente novamente.");
  } else {

    Serial.println("Obtendo endereco de IP na rede...");
    sendCommand("AT+CIFSR");
    readResponse(1000);

    Serial.println("Configurando para multiplas conexoes...");
    sendCommand("AT+CIPMUX=1");
    readResponse(1000);

    Serial.println("Ligando servidor...");
    sendCommand("AT+CIPSERVER=1,80");
    readResponse(1000);

    Serial.print("Pronto, acesse o IP atraves de um dispositivo ligado na mesma rede do ESP8266.");
  }
}

void loop() {
  if (ESP_Serial.available()) {
    //le os dados vindos da serial ate o alvo, neste caso +IPD,
    if (ESP_Serial.find("+IPD,")) { .    // se id for achado 
      delay(500);
      char id = ESP_Serial.peek();//pega id da conexao
      
      //pagina web em HTML
      String webpage = String("HTTP/1.1 200 OK\r\n") +
                        "Content-Type: text/html\r\n" +
                        "Connection: close\r\n" +
                        "\r\n" +
                        "<!DOCTYPE HTML>" +
                        "<html>" +
                        "<h1>" +
                        "MLMoB NO CAP" +
                        "</h1></html>" +
                        "\r\n";

      String cipSend = "AT+CIPSEND=";
      cipSend += (int(id) - 48);        // 48 = tamanho da letra
      cipSend += ",";
      cipSend += webpage.length();
      Serial.println(webpage.length());
      sendCommand(cipSend);
      readResponse(500);

      sendCommand(webpage);
      readResponse(750);

      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += (int(id) - 48);
      sendCommand(closeCommand);
      readResponse(750);
    }
  }
}

void sendCommand(String cmd) {
  ESP_Serial.println(cmd);     // envia informação p/ ESP2866
}

void readResponse(unsigned int timeout) {
  // timout == tempo de respota do módulo
  unsigned long timeIn = millis(); //momento que entramos nessa funcao é salvo
  resposta = "";  // limpa mensagem antiga
  //cada comando AT tem um tempo de resposta diferente...
  while (timeIn + timeout > millis()) {
    if (ESP_Serial.available()) {
      char c = ESP_Serial.read();    // atribui resposta do comando a variável c 
      resposta += c;      // variável c é somada a variável resposta
    }
  }
  Serial.println(resposta);
}
