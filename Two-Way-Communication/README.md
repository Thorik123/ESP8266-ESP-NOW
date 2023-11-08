## ESP8266 ESP-NOW Two-Way Communication

Dalam metode ini hampir sama dengan **One-Way Communication** tetapi yang menjadi pembeda adalah didalam metode ini proses komunikasi data dilakukan secara dua arah, dengan arti lain antara satu device(ESP) dengan yang lain bisa menjadi penerima maupun pengirim data secara bersamaan. Itulah mengapa disebut _two way_.

Untuk mempermudah pemahaman, saya menyebutnya dengan istilah `node` (node1, node2, dst.).

---

## Note!

- Karena device(ESP) yang dipakai nantinya berfungsi sebagai `Sender` sekaligus `Receiver` Maka perlu diperhatikan catatan dibawah ini.

- Sesuaikan MAC Address dari masing-masing device(ESP), perhatikan kode berikut:

```cpp
// Ganti dengan MAC Address Receiver
uint8_t MACAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
```

- Ganti nilai `0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF` sesuai dengan MAC Address receiver, contoh jika MAC Address `5C:7F:32:E4:3C:8F` maka menjadi `0x5C, 0x7F, 0x32, 0xE4, 0x3C, 0x8F`

- Untuk nilai MAC Address antar node harus terbalik. Maksudnya, misalkan pada program `node1` maka MAC Address diganti dengan MAC Address `node2` begitu juga sebaliknya.

- Perhatikan struktur data yang akan dikirim, jika ada perbedaan maka data tersebut akan gagal dikirim ke Receiver. Perhatikan kode berikut:

```cpp
typedef struct struct_message {
  float temp;
  float hum;
} struct_message;
```

- Struktur data antar node harus sama jika tidak maka akan gagal saat dikirim.

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

- Setelah berhasil mengetahui MAC Address tersebut silahkan masukkan nilainya pada masing-masing `node`.

---
