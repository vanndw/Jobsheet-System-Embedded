# C. Transmisi Data Menggunakan Protokol MQTT

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Dalam percobaan ini, program ESP32 memanfaatkan protokol MQTT untuk mentransmisikan data dummy, seperti level, rainfall, dan flow. Server broker MQTT yang digunakan adalah layanan EMQ X, yang merupakan platform perangkat lunak open-source untuk implementasi MQTT. Setelah program diupload, dilakukan pemantauan melalui serial monitor untuk memastikan koneksi dan debug pada Node-Red. Hasil output dari percobaan ini meliputi data yang dipublikasikan ke topik "flood/node1", serta visualisasi data pada dashboard Node-Red.
   
## 2. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 3. Source Code

 ![Penjelasan Kode](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/c400b610-3a73-4e09-a7be-0058007e3e06)


## 5. Hasil Percobaan

1. Flow chart program ESP32
   
 ![Flow Chart](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/ecb66904-4caa-4bcd-b655-761c3a22ff23)

   
2. Output serial monitor
   
![2  Output serial monitor](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/78c60d31-81a2-4c43-9626-4c539b573188)

   
3. Debug Node-RED
   
  ![3  Debug Node-RED](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/e683f449-42d4-4e46-b99c-588133006b39)

   
4. Dashboard Node-RED
   
![4  Dashboard Node-RED](https://github.com/hendrawansantana231/Sistem-Embedded/assets/155714822/0f27698a-f5e9-4b44-bbd8-a61b6980d072)


<p align="justify">
<b><p>6. Analisa </p></b>
<p>Program menggunakan tiga library, yaitu WiFi untuk koneksi Wi-Fi, PubSubClient untuk koneksi MQTT, dan ArduinoJson untuk memanipulasi data JSON. Kemudian Inisialisasi variabel-variabel yang digunakan, seperti SSID dan password untuk koneksi Wi-Fi, serta alamat server MQTT. Program mencoba untuk terhubung ke jaringan Wi-Fi dengan menggunakan SSID dan password yang telah ditentukan. Data JSON yang akan dikirimkan melibatkan perangkat ID, level, jumlah hujan, dan aliran. 
Data ini mungkin merepresentasikan informasi dari suatu perangkat atau sensor yang terkait dengan smart water management. Misalnya, dev_id mungkin adalah identifikasi perangkat, level dapat mengindikasikan tinggi air, rainfall dapat menunjukkan jumlah hujan, dan flow mungkin mencerminkan laju aliran air.

</p>
