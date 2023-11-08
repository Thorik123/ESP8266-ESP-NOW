/*
                              ESP8266 ESP-NOW Sender

    - Sebelum melakukan uplaod program pastikan untuk MAC Address Receiver sudah benar
    - Sebagai contoh data yang dikirim ada 5 jenis:
      a => type data char
      b => type data integer
      c => type data float
      d => type data String
      e => type data boolean

*/

#include <ESP8266WiFi.h>
#include <espnow.h>

// Ganti sesuai dengan MAC Address Receiver
uint8_t MACReceiver[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

typedef struct struct_message {
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;

struct_message msg;
unsigned long lastTime = 0;

//=====================================================================
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  } else {
    Serial.println("Delivery fail");
  }
}

//=====================================================================
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(MACReceiver, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

//=====================================================================
void loop() {
  if ((millis() - lastTime) >= 1000) {

    strcpy(msg.a, "THIS IS A CHAR");
    msg.b = random(1, 20);
    msg.c = 1.2;
    msg.d = "Hello";
    msg.e = false;

    esp_now_send(MACReceiver, (uint8_t *)&msg, sizeof(msg));
    lastTime = millis();
  }
}