#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>

const int DHT_PIN = 15;
DHTesp dht;
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttUser = ""; 
const char* mqttPassword = "";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

float temp = 0;
float hum = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.println("Conectando a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem chegou [");
  Serial.print(topic);
  Serial.print("]");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqttUser, mqttPassword)) {
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("falhou, rc= .");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup () {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqttPort);
  client.setKeepAlive(10);
  client.setCallback(callback);
  dht.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    TempAndHumidity data = dht.getTempAndHumidity();

    if (client.connected()) {
      String temperatureStr = String(data.temperature, 2);
      client.publish("/temp", temperatureStr.c_str());
      String humidityStr = String(data.humidity, 1);
      client.publish("/hum", humidityStr.c_str());

      Serial.print("Temperatura: ");
      Serial.println(temperatureStr);
      Serial.print("Umidade: ");
      Serial.println(humidityStr);
    }
  }
}