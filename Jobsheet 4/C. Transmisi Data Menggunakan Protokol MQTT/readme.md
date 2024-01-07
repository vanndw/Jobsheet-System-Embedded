# C. Transmisi Data Menggunakan Protokol MQTT

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Dalam percobaan ini, program ESP32 memanfaatkan protokol MQTT untuk mentransmisikan data dummy, seperti level, rainfall, dan flow. Server broker MQTT yang digunakan adalah layanan EMQ X, yang merupakan platform perangkat lunak open-source untuk implementasi MQTT. Setelah program diupload, dilakukan pemantauan melalui serial monitor untuk memastikan koneksi dan debug pada Node-Red. Hasil output dari percobaan ini meliputi data yang dipublikasikan ke topik "flood/node1", serta visualisasi data pada dashboard Node-Red.
   
## 2. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 3. Source Code
Penjelasan Kode 
![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/cd34761c-cfc2-4a97-b0ce-c0ef65e74c70)



## 5. Hasil Percobaan

1. Flow chart program ESP32
   
![Flow Chart](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/d076b79b-1194-4df9-b2f4-bd836141da65)


   
2. Output serial monitor
   
![2  Output serial monitor](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/40c538a9-3948-4fed-b89f-3c6845afcd62)

   
3. Debug Node-RED
   
 ![3  Debug Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/e0e2d373-5764-4ab1-aa52-2cc743712496)

   
4. Dashboard Node-RED
   
![4  Dashboard Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/dddfac57-0ab1-4360-a074-368e17d11eb6)



<p align="justify">
<b><p>6. Analisa </p></b>
<p>Program menggunakan tiga library, yaitu WiFi untuk koneksi Wi-Fi, PubSubClient untuk koneksi MQTT, dan ArduinoJson untuk memanipulasi data JSON. Kemudian Inisialisasi variabel-variabel yang digunakan, seperti SSID dan password untuk koneksi Wi-Fi, serta alamat server MQTT. Program mencoba untuk terhubung ke jaringan Wi-Fi dengan menggunakan SSID dan password yang telah ditentukan. Data JSON yang akan dikirimkan melibatkan perangkat ID, level, jumlah hujan, dan aliran. 
Data ini mungkin merepresentasikan informasi dari suatu perangkat atau sensor yang terkait dengan smart water management. Misalnya, dev_id mungkin adalah identifikasi perangkat, level dapat mengindikasikan tinggi air, rainfall dapat menunjukkan jumlah hujan, dan flow mungkin mencerminkan laju aliran air.

   1. **Transmisi Data IoT:** Program ini dirancang untuk aplikasi IoT (Internet of Things) di mana perangkat ESP32 terhubung ke jaringan WiFi dan mengirimkan data sensor ke broker MQTT ("broker.emqx.io"). Data sensor dalam hal ini mencakup ID perangkat, tinggi air, curah hujan, dan laju aliran, yang diformat sebagai muatan JSON.

2. **Penanganan Koneksi:** Kode ini mencakup fungsi untuk menangani koneksi WiFi (`setup_wifi()`) dan koneksi MQTT (`reconnect()`). ESP32 mencoba untuk terhubung ke jaringan WiFi yang ditentukan dan, jika terputus, terus-menerus mencoba untuk terhubung kembali ke broker MQTT. Program ini menghasilkan ID klien acak untuk komunikasi MQTT, meningkatkan keamanan dan menghindari konflik dengan perangkat lain.

3. **Pemformatan Data dengan JSON:** Data sensor diformat menggunakan pustaka ArduinoJson untuk membuat objek JSON. Objek ini kemudian dikonversi menjadi string (`payload`) dan dipublikasikan ke topik MQTT "flood/node1" pada interval reguler dalam fungsi `loop()`. Desain ini memungkinkan representasi data yang terstruktur, memudahkan untuk menguraikan dan menginterpretasikan informasi di sisi penerima.</b>

</p>
