# B. Transmisi Data Menggunakan Protokol HTTP

## 1. Keterangan Singkat (Abstrak)
<p align="justify">Percobaan ini dimulai dengan pembuatan database lokal "banjir_db" dan tabel "smartwater" menggunakan phpMyAdmin. Lalu diberikan kode JSON untuk flow program Multi-Protocol IoT Server yang perlu diimport di Node-RED. Selanjutnya, melalui program pada ESP32 dilakukan transmisi data dummy ke Node-Red menggunakan protokol HTTP metode GET dan protokol HTTP metode POST. Output dari percobaan ini berupa hasil dari serial monitor, debugging Node-Red, dan tampilan dashboard Node-RED.
   
## 2. Alat dan Bahan
1. Node-RED
2. ESP32
3. XAMPP

## 3. Source Code

1. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode GET 
![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/bacd5e0a-48b9-4907-9f7e-e7d924953846)

2. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode POST 
![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/dea4bc75-dbcd-4335-ab91-e06f2603e763)


## 4. Flow Program
1. Flow Program ESP32 transmisi data dummy menggunakan protokol HTTP metode GET 
![Flow Program](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/194596fc-6f65-4acd-93e5-cb21984d83c8)


2. Program ESP32 transmisi data dummy menggunakan protokol HTTP metode POST 
![Flow Program](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/58b5daaa-26d2-4e4f-bd7c-d5d3433cf2c5)



## 5. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode GET
### Dokumentasi Percobaan

1. Flow chart program ESP32
   
![1  Flow Chart program ESP32](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/3a16669d-bd62-482a-873e-686dc50b6c24)

  
   
2. Output serial monitor
   
  ![2  Output serial monitor](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/fe6f5bdf-09d6-43b9-9c29-645b3c2d8dcc)

   
3. Debug Node-RED
   
 ![3  Debug Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/19315c70-1acf-4586-8409-9370dabcbf92)

   
4. Dashboard Node-RED
   
   ![4  Dashboard Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/744950b3-bcd7-4911-96f7-46e1da8af285)

   
5. Tabel database MySQL
   
![5  Tabel database MySQL](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/04aca9a9-10d1-4d32-823b-cfed33f402df)

  


Kode tersebut adalah program ESP32 yang menggunakan perangkat WiFi (menggunakan library WiFi.h dan HTTPClient.h) untuk mengirimkan permintaan HTTP GET ke suatu server. Penjelasan dari kode tersebut berada di bawa ini:
1. **Inklusi Library:**
   ```cpp
   #include <WiFi.h>
   #include <HTTPClient.h>
   ```
   Dua library digunakan: WiFi.h untuk mengelola koneksi WiFi, dan HTTPClient.h untuk melakukan permintaan HTTP.

2. **Konfigurasi Koneksi WiFi:**
   ```cpp
   const char* ssid = "1165342";
   const char* password = "kitabisa";
   ```
   Nama dan kata sandi WiFi yang digunakan untuk mengakses jaringan.

3. **Konfigurasi Server:**
   ```cpp
   String serverName = "http://192.168.1.12:1880/flood/node1";
   ```
   Alamat URL server yang akan menerima permintaan HTTP GET. IP dan path disesuaikan dengan konfigurasi server yang sebenarnya.

4. **Inisialisasi Variabel:**
   ```cpp
   unsigned long lastTime = 0;
   unsigned long timerDelay = 5000;
   ```
   Variabel untuk melacak waktu terakhir permintaan HTTP GET dan interval waktu antar permintaan.

5. **Setup Function:**
   ```cpp
   void setup() {
     // Inisialisasi Serial dan koneksi WiFi
     Serial.begin(115200);
     WiFi.begin(ssid, password);
     
     Serial.println("Connecting");
     while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
     }
     
     Serial.println("");
     Serial.print("Connected to WiFi network with IP Address: ");
     Serial.println(WiFi.localIP());
     
     Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
   }
   ```
   Fungsi setup yang pertama kali dijalankan saat perangkat dinyalakan. Menginisialisasi Serial, menghubungkan ke WiFi, dan mencetak informasi koneksi.

6. **Loop Function:**
   ```cpp
   void loop() {
     float dev_id = 28, level = 5, rainfall = 10.2, flow = 12;
     
     if ((millis() - lastTime) > timerDelay) {
       // Melakukan permintaan HTTP GET setiap 5 detik
       
       // Memeriksa status koneksi WiFi
       if (WiFi.status() == WL_CONNECTED) {
         HTTPClient http;
         String serverPath = serverName + "?dev_id=" + dev_id + "&level=" + level + "&rainfall=" + rainfall + "&flow=" + flow;
         
         // Membuka koneksi HTTP ke server
         http.begin(serverPath.c_str());
         
         // Mengirim permintaan HTTP GET
         int httpResponseCode = http.GET();
         
         // Memproses respons HTTP
         if (httpResponseCode > 0) {
           Serial.print("HTTP Response code: ");
           Serial.println(httpResponseCode);
           String payload = http.getString();
           Serial.println(payload);
         } else {
           Serial.print("Error code: ");
           Serial.println(httpResponseCode);
         }
         
         // Menutup koneksi HTTP dan melepaskan sumber daya
         http.end();
       } else {
         Serial.println("WiFi Disconnected");
       }
       
       // Memperbarui waktu terakhir permintaan
       lastTime = millis();
     }
   }
   ```
   Fungsi loop yang berjalan terus-menerus setelah fungsi setup selesai. Dalam loop ini, terdapat logika untuk mengirimkan permintaan HTTP GET ke server setiap 5 detik. Informasi seperti `dev_id`, `level`, `rainfall`, dan `flow` diatur secara manual dan dapat disesuaikan sesuai kebutuhan aplikasi. Jika koneksi WiFi terputus, pesan "WiFi Disconnected" akan dicetak.

## 6. Hasil Percobaan Transmisi Data Dummy Menuju Node-Red Menggunakan Protokol HTTP Metode POST
### Dokumentasi Percobaan

1. Flow chart program ESP32
   
  ![1  Flow Chart program ESP32](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/473e2dfd-ae3d-4dff-b46a-b087c87cd5ae)


2. Output serial monitor
   
 ![2  Output serial monitor](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/f00d4e82-49ca-42db-9151-36b5e4957679)

   
3. Debug Node-RED
   
 ![3  Debug Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/8c002894-3f8c-412a-bfc2-6f4e414848ff)

   
4. Dashboard Node-RED
   
![4  Dashboard Node-RED](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/4c82b81f-8163-47a5-aa1e-b967099fc19a)

  

Kode tersebut adalah program ESP32 yang menggunakan perangkat WiFi untuk mengirimkan permintaan HTTP POST ke suatu server secara berkala. Di bawah ini adalah penjelasan singkat untuk setiap bagian dari kode tersebut:

1. **Inklusi Library:**
   ```cpp
   #include <WiFi.h>
   #include <HTTPClient.h>
   ```
   Library WiFi.h digunakan untuk mengelola koneksi WiFi, dan library HTTPClient.h untuk melakukan permintaan HTTP.

2. **Konfigurasi Koneksi WiFi:**
   ```cpp
   const char* ssid = "1163542";
   const char* password = "kitabisa";
   ```
   Nama dan kata sandi WiFi yang digunakan untuk mengakses jaringan.

3. **Konfigurasi Server:**
   ```cpp
   const char* serverName = "http://192.168.1.12:1880/flood/node1";
   ```
   Alamat URL server yang akan menerima permintaan HTTP POST. IP dan path disesuaikan dengan konfigurasi server yang sebenarnya.

4. **Inisialisasi Variabel:**
   ```cpp
   unsigned long lastTime = 0;
   unsigned long timerDelay = 5000;
   ```
   Variabel untuk melacak waktu terakhir permintaan HTTP POST dan interval waktu antar permintaan. Pada kode yang di-comment, interval waktu diatur menjadi 10 menit (`600000`).

5. **Setup Function:**
   ```cpp
   void setup() {
     // Inisialisasi Serial dan koneksi WiFi
     Serial.begin(115200);
     WiFi.begin(ssid, password);
     
     Serial.println("Connecting");
     while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
     }
     
     Serial.println("");
     Serial.print("Connected to WiFi network with IP Address: ");
     Serial.println(WiFi.localIP());
     Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
   }
   ```
   Fungsi setup yang pertama kali dijalankan saat perangkat dinyalakan. Menginisialisasi Serial, menghubungkan ke WiFi, dan mencetak informasi koneksi.

6. **Loop Function:**
   ```cpp
   void loop() {
     String dev_id = "28", level = "8", rainfall = "9.2", flow = "10";
     
     if ((millis() - lastTime) > timerDelay) {
       // Melakukan permintaan HTTP POST setiap 5 detik
       
       // Memeriksa status koneksi WiFi
       if (WiFi.status() == WL_CONNECTED) {
         WiFiClient client;
         HTTPClient http;
         
         // Membuka koneksi HTTP ke server
         http.begin(client, serverName);
         
         // Menambahkan header untuk tipe konten
         http.addHeader("Content-Type", "application/json");
         
         // Data JSON untuk dikirimkan dengan HTTP POST
         String httpRequestData = "{\"dev_id\":\"" + dev_id + "\",\"level\":\"" + level + "\",\"rainfall\":\"" + rainfall + "\",\"flow\":\"" + flow + "\"}";
         
         // Mengirim permintaan HTTP POST
         int httpResponseCode = http.POST(httpRequestData);
         
         // Menampilkan respons HTTP
         Serial.print("HTTP Response code is: ");
         Serial.println(httpResponseCode);
         
         // Menutup koneksi HTTP
         http.end();
       } else {
         Serial.println("WiFi Disconnected");
       }
       
       // Memperbarui waktu terakhir permintaan
       lastTime = millis();
     }
   }
   ```
   Fungsi loop yang berjalan terus-menerus setelah fungsi setup selesai. Dalam loop ini, terdapat logika untuk mengirimkan permintaan HTTP POST ke server setiap 5 detik. Informasi seperti `dev_id`, `level`, `rainfall`, dan `flow` diatur secara manual dan dapat disesuaikan sesuai kebutuhan aplikasi. Jika koneksi WiFi terputus, pesan "WiFi Disconnected" akan dicetak.


   # Analisa
   Program ini dirancang untuk dikompilasi dan dijalankan pada platform ESP dengan menggunakan Arduino IDE. Pastikan Anda telah menginstal pustaka yang diperlukan.
Perlakukan informasi WiFi dan URL server dengan hati-hati, pastikan sesuai dengan konfigurasi jaringan dan server yang akan digunakan.**Ringkasan Analisa Program:**

1. **Header dan Deklarasi Variabel:**
   - Program menggunakan library `WiFi.h` dan `HTTPClient.h` untuk mengakses fungsi WiFi dan HTTP pada ESP.
   - Mendeklarasikan variabel `ssid` dan `password` untuk menyimpan informasi SSID dan password WiFi.
   - Mendeklarasikan variabel `serverName` untuk menyimpan URL server yang akan dihubungi.
   - Mendeklarasikan variabel `lastTime` untuk menyimpan waktu terakhir program mengirimkan data.
   - Mendeklarasikan variabel `timerDelay` untuk menyimpan interval waktu antara pengiriman data (dalam milidetik).

2. **Fungsi `setup`:**
   - Inisialisasi serial communication dengan kecepatan 115200 bps.
   - Menghubungkan ke jaringan WiFi dengan menggunakan `WiFi.begin()`.
   - Menunggu hingga terhubung ke WiFi dengan loop yang menggantung (`while` loop).
   - Menampilkan informasi IP address setelah terhubung.

3. **Fungsi `loop`:**
   - Mengecek apakah sudah waktunya untuk mengirim data berdasarkan `timerDelay`.
   - Jika ya, program akan membuat objek `WiFiClient` dan `HTTPClient`, menyusun data JSON dengan nilai sensor, dan mengirimkan HTTP POST request ke server.
   - Memeriksa status koneksi WiFi dan menampilkan pesan jika tidak terhubung.
   - Mengatur ulang `lastTime` untuk waktu selanjutnya.

4. **Pengiriman Data:**
   - Membuat variabel string `dev_id`, `level`, `rainfall`, dan `flow` untuk menyimpan data sensor (mungkin placeholder, seharusnya data sesuai dengan sensor yang digunakan).
   - Membentuk data JSON dengan menggunakan string concatenation.

5. **HTTP Request:**
   - Membuka koneksi HTTP ke server dengan URL yang sudah dibentuk.
   - Menambahkan header `Content-Type` sebagai `application/json`.
   - Mengirimkan data JSON melalui HTTP POST request.
   - Menampilkan status code HTTP response.

6. **Pembersihan Sumber Daya:**
   - Mengakhiri koneksi HTTP setelah pengiriman data selesai.

7. **Penanganan Koneksi WiFi:**
   - Mengecek apakah koneksi WiFi masih aktif sebelum mengirimkan data.
