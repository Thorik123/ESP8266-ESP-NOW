## ESP8266 ESP-NOW One-Way Communication

Dalam metode ini ada istilah dengan nama **Master**(Sender) dan **Slave**(Receiver). Jadi, antara satu device(ESP) dengan yang lain mempunyai fungsi dan tugas sendiri yaitu sebagai pengirim saja atau sebagai penerima saja. Itulah mengapa disebut **One-Way Communication** karena proses komunikasi datanya hanya terjadi satu arah saja atau _one way_.

Agar lebih mudah dipahami saya buat istilahnya menjadi **Sender** dan **Receiver**. **Sender** berfungsi sebagai pengirim data sedangkan **Receiver** sebagai penerima data.

---

## Note!

#### Pada bagian Sender

- Harap perhatikan untuk MAC Address Receiver, sesuaikan dengan data yang ada. Jika nilainya salah maka pengiriman data tidak akan berhasil. Perhatikan kode berikut:

```cpp
// Ganti sesuai dengan MAC Address Receiver
uint8_t MACReceiver[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
```

- Ganti nilai `0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF` sesuai dengan MAC Address receiver, contoh jika MAC Address `5C:7F:32:E4:3C:8F` maka menjadi `0x5C, 0x7F, 0x32, 0xE4, 0x3C, 0x8F`

- Perhatikan struktur data yang akan dikirim, jika ada perbedaan maka data tersebut akan gagal dikirim ke Receiver. Perhatikan kode berikut:

```cpp
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;
```

- Struktur data antara Sender dan Receiver harus sama jika tidak maka akan gagal saat dikirim.

#### Pada bagian Receiver

- Untuk mengetahui MAC Address dari device(ESP) yang dijadikan sebagai penerima data gunakan kode berikut:

```cpp
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("ESP8266 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
}

void loop() {}
```

- Setelah berhasil mengetahui MAC Address tersebut silahkan masukkan nilainya pada Sender.

---
