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

![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/8b570eaa-05b9-4dec-a3c8-7ed339528289)



## 4. Flow Program

![flowprogram](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/e4aaa58f-0056-42c0-a7d3-c1376b9aa72e)


## 5. Hasil Percobaan Kontrol Nyala LED Melalui Dashboard Node-RED

1. Flow chart program ESP32
   
  ![flowchart](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/4e1fd5a9-aea5-4639-9ba9-ea0f78178884)

   
2. Dokumentasi
   
![dokumentasi](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/989fa9e7-4e97-4301-90c3-afcd8114f20a)


3. Debug Node-RED
   
![3  Debug Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/080ce587-d28a-40d8-b48b-bf1453a19029)

   
4. Dashboard Node-RED
   
 ![dashboard_node_red](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/53db050f-415e-4605-8cd0-e3369edf84c9)


## 6. Hasil Percobaan Kontrol Nyala LED Melalui Dashboard Adafruit
1. Flow chart program ESP32

 ![flowchart1](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/b7655954-83be-47c8-a2de-b9db9fac6264)


2. Dokumentasi 
   
  ![dokumentasi1](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/c21637e6-7d3c-462a-9a22-e49fdd064cc5)

   
3. Widget On/Off Adafruit
![2  Dokumentasi](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/60dae022-ccc4-4a1d-b231-b76f71c99a2c)


Analisa
1. Kedua program digunakan untuk mengontrol perangkat (LED) melalui protokol MQTT menggunakan platform mikrokontroler ESP32 (Program 1) dan ESP8266 (Program 2).
2. Koneksi WiFi digunakan dalam kedua program untuk menghubungkan perangkat ke jaringan, memungkinkan pertukaran data melalui protokol MQTT.
3. Program 1 menggunakan broker MQTT "broker.emqx.io", sementara Program 2 terhubung ke layanan io.adafruit.com untuk pertukaran pesan.
4. Keduanya memiliki mekanisme untuk mencoba terus terkoneksi ke broker MQTT jika koneksi terputus, sehingga memastikan kehandalan komunikasi.
5. Penggunaan topik MQTT dan payload khusus dalam kedua program memungkinkan pengendalian LED dan pertukaran data suhu dengan format JSON pada Program 1.
