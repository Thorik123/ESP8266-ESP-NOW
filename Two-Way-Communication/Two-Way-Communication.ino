/*
               ESP8266 ESP-NOW Two-Way Communication
*/

#include <ESP8266WiFi.h>
#include <espnow.h>

// Ganti dengan MAC Address Receiver
uint8_t MACAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

float temperature;
float humidity;

float receiveTemp;
float receiveHum;

unsigned long previousMillis = 0;
String success;

typedef struct struct_message {
  float temp;
  float hum;
} struct_message;

struct_message SendReading;
struct_message ReceiveReading;

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  } else {
    Serial.println("Delivery fail");
  }
}

void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&ReceiveReading, incomingData, sizeof(ReceiveReading));
  Serial.print("Bytes received: ");
  Serial.println(len);
  receiveTemp = ReceiveReading.temp;
  receiveHum = ReceiveReading.hum;
}

void getReadings() {
  temperature = random(1, 99);
  humidity = random(1, 99);
}

void printIncomingReadings() {
  Serial.println("INCOMING READINGS");
  Serial.print("Temperature: ");
  Serial.print(receiveTemp);
  Serial.println(" ºC");
  Serial.print("Humidity: ");
  Serial.print(receiveHum);
  Serial.println(" %");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(MACAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  if ((millis() - previousMillis) >= 5000) {

    getReadings();

    SendReading.temp = temperature;
    SendReading.hum = humidity;

    esp_now_send(MACAddress, (uint8_t *)&SendReading, sizeof(SendReading));
    printIncomingReadings();
    previousMillis = millis();
  }
}