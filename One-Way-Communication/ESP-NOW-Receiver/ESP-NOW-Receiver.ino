/*
                                  ESP8266 ESP-NOW Receiver

    - Sebelum melakukan uplaod program pastikan untuk MAC Address dari Sender sudah benar
    - Sebagai contoh data yang diterima ada 5 jenis:
      a => type data char
      b => type data integer
      c => type data float
      d => type data String
      e => type data boolean

*/

#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct struct_message {
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;

struct_message msg;

//=========================================================================
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&msg, incomingData, sizeof(msg));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(msg.a);
  Serial.print("Int: ");
  Serial.println(msg.b);
  Serial.print("Float: ");
  Serial.println(msg.c);
  Serial.print("String: ");
  Serial.println(msg.d);
  Serial.print("Bool: ");
  Serial.println(msg.e);
  Serial.println();
}

//=========================================================================
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

//=========================================================================
void loop() {}