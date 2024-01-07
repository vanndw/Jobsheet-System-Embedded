# D. Akuisi Data dan Kendali Perangkat IoT Menggunakan Protokol MQTT

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Dalam percobaan ini program ESP32 menggunakan protokol MQTT untuk mengakuisisi data sensor dan mengendalikan perangkat, seperti LED, melalui topik-topik MQTT. Setelah program diupload, dilakukan pemantauan melalui serial monitor dan dashboard Node-Red untuk mengendalikan nyala LED melalui tombol switch pada dashboard. Program yang kedua merupakan pengendalian LED ESP32 menggunakan layanan Adafruit MQTT, dalam hal ini pengendalian LED melalui dashboard yang ada di laman Adafruit.
   
## 2. Alat dan Bahan
1. Node-RED
2. Laman Adafruit
3. ESP32
4. Kabel jumper
5. LED
6. XAMPP

## 3. Source Code

![Penjelasan Kode](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/0827cb55-e728-464c-9de8-2fb46006f384)


## 4. Flow Program
![flow program ](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/b81a6645-f5a4-4e38-a4db-43f2d1430a81)


## 5. Hasil Percobaan Kontrol Nyala LED Melalui Dashboard Node-RED

1. Flow chart program ESP32
   
  ![Flow chart program ESP32](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/871c806f-8bc7-4e62-be1d-d9e49bbf8c69)

   
2. Dokumentasi
   
![2  Dokumentasi 1](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/e211629d-a585-4f43-8d32-5f48cf0a737a)


3. Debug Node-RED
   
![3  Debug Node-RED](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/3edb5f96-525e-41d9-813c-4e7a1c1a2d57)

   
4. Dashboard Node-RED
   
  ![dashboard1](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/683139e0-5528-4f5e-8de5-9493d4fbfae5)


## 6. Hasil Percobaan Kontrol Nyala LED Melalui Dashboard Adafruit
1. Flow chart program ESP32

 ![Flowchart program 2](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/d32033f6-c1f6-486f-abf4-8a6199a6b174)


2. Dokumentasi 
   
   ![2  Dokumentasi 2](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/945bcbd8-1ace-4a20-b597-2d4fd04f2b31)

   
3. Widget On/Off Adafruit
![2  Dokumentasi](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/69ba2e42-9187-401f-9f36-bc6f6c39cdc0)


<b><p>7. Analisa </p></b>
<p>Kode ini mengimpor beberapa pustaka yang diperlukan, termasuk pustaka WiFi dan pustaka MQTT dari Adafruit. Kode tersebut digunakan sebagai implementasi untuk menghubungkan perangkat ESP8266 dengan protokol MQTT (Message Queuing Telemetry Transport) ke server Adafruit IO. Program juga akan meng-handle pesan yang diterima dari topik MQTT 'led'. Jika pesan adalah "1", maka pin keluaran akan diaktifkan (HIGH), jika bukan "1", maka pin keluaran akan dimatikan (LOW). Dilakukanlah pengecekan, apakah koneksi ke server MQTT sudah terhubung. Jika belum, maka akan melakukan koneksi ulang dengan retry dan menunggu 5 detik di setiap percobaan.</p>
