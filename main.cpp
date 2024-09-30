#include <DHT.h>
#include <ArduinoJson.h>

// Definindo o pino do sensor de temperatura (DHT)
#define DHT_pin 4
#define DHT_type DHT22
// Criando elemento DHT
DHT dht(DHT_pin, DHT_type);

// Definindo os LEDs
#define LED_vermelho 11
#define LED_amarelo 12
#define LED_verde 13

void setup() {
  // Iniciando o Serial
  Serial.begin(9600);
  // Iniciando o DHT
  dht.begin();
  // Definindo o tipo de pino
  pinMode(LED_vermelho, OUTPUT);
  pinMode(LED_amarelo, OUTPUT);
  pinMode(LED_verde, OUTPUT);
}

void loop() {
  // Desligando os LEDS no início
  digitalWrite(LED_vermelho, LOW);
  digitalWrite(LED_amarelo, LOW);
  digitalWrite(LED_verde, HIGH);

  // Lendo a temperatura e umidade
  // float temperatura = random(20, 80);
  // float umidade = random(20, 80);
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  String status = "OK";

  // Criando o JSON para enviar dados
  StaticJsonDocument<100>json;
  json["Temperatura"] = temperatura;
  json["Umidade"] = umidade;

  // Criando condicional de temperatura e umidade
  if (temperatura < 0 || temperatura > 40) {
    if (umidade < 20 || umidade > 80 ) {
      status = "Critico";
      digitalWrite(LED_vermelho, HIGH);
      digitalWrite(LED_verde, LOW);
    }
    else {
      status = "Perigo";
      digitalWrite(LED_amarelo, HIGH);
      digitalWrite(LED_verde, LOW);
    }
  }
  else {
    if (umidade < 20 || umidade > 80 ) {
      status = "Perigo";
      digitalWrite(LED_amarelo, HIGH);
      digitalWrite(LED_verde, LOW);
    }
  }
  
  // Atribuir o status ao JSON
  json["Status"] = status;
  // Enviar a telemetria para o monitor serial
  serializeJson(json, Serial);
  Serial.println();
  // Delay de 3s
  delay(3000);
}
