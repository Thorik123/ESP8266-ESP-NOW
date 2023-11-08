## ESP8266 ESP-NOW Communication

Project ini adalah implementasi dari protokol komunikasi menggunakan **ESP-NOW**. **ESP-NOW** adalah sebuah protokol komunikasi yang diciptakan oleh [Espressif](https://www.espressif.com/) untuk menghubungkan beberapa modul ESP tanpa menggunakan koneksi WiFi.

---

## How To Works?

Setidaknya ada dua metode dalam proses pengiriman dan penerimaan data, yaitu:

- #### One-Way Communication
  - Dalam metode ini ada istilah dengan nama **Master**(Sender) dan **Slave**(Receiver). Jadi, antara satu device(ESP) dengan yang lain mempunyai fungsi dan tugas sendiri yaitu sebagai pengirim saja atau sebagai penerima saja. Itulah mengapa disebut **One-Way Communication** karena proses komunikasi datanya hanya terjadi satu arah saja atau _one way_.
- #### Two-Way Communication
  - Sementara itu, dalam metode ini hampir sama dengan **One-Way Communication** tetapi yang menjadi pembeda adalah didalam metode ini proses komunikasi data dilakukan secara dua arah, dengan arti lain antara satu device(ESP) dengan yang lain bisa menjadi penerima maupun pengirim data secara bersamaan. Itulah mengapa disebut _two way_.

Dari penjelasan tersebut, dengan metode yang sudah disebutkan sebelumnya proses komunikasi dapat dikembangkannya lagi sehingga muncul istilah **one slave multiple master** atau **one master multiple slave**

---

Atau bisa baca selengkapnya mengenai dokumentasi dari [ESP-NOW](https://demo-dijiudu.readthedocs.io/en/latest/api-reference/wifi/esp_now.html)
