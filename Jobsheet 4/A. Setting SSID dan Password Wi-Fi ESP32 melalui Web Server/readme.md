# A. Setting SSID dan Password Wi-Fi ESP32 melalui Web Server

## 1. Alat dan Bahan
1) ESP32
2) Arduino IDE

## 2. Source Code

![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/d2cf85c2-8789-46c3-8b23-9a82129b6a78)


## 3. Flowchart

![Flow Chart](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/994dbcd1-5e58-49a1-8935-6185d29deb5b)


## 4. Hasil dan Pembahasan
### Dokumentasi Hasil
1. Tampilan Awal Serial Monitor Sebelum Dihubungkan

  ![1  Tampilan Awal Serial Monitor Sebelum Dihubungkan](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/50383ca7-eba5-4af5-b16f-1f737d13aa67)

2. Tampilan Web
   
   ![2  tampilan web](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/fbfa5f47-a760-40f9-ac8c-465febac6bc7)

   
3. Serial Monitor Setelah Memasukkan SSID dan PASS
   
![3  serial monitor setelah memasukan ssid dan pass](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/04d56112-6d09-4ed5-9143-e7080aa66789)

     
4. Serial Monitor Setelah Berhasil Terhubung
   
![4  Serial Monitor Setelah Berhasil Terhubung](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/8d7a401f-8cab-4574-81ee-b7fe01724479)

   
### Pembahasan Kode
#### **Fungsi Utama Kode:**

  * Menghubungkan perangkat ke jaringan WiFi.
  * Memberikan opsi untuk mengubah kredensial WiFi melalui halaman web jika koneksi gagal.

#### **Penjelasan Alur Kode:**
  1. Setup Awal:
  * Memulai komunikasi serial untuk monitoring.
  * Menginisialisasi EEPROM untuk penyimpanan data.
  * Membaca kredensial WiFi yang tersimpan di EEPROM.
  * Mencoba menghubungkan ke WiFi menggunakan kredensial tersebut.

  2. Loop Utama:
  * Jika terkoneksi ke WiFi:
    * Mencetak pesan konfirmasi koneksi.
  * Jika tidak terkoneksi ke WiFi:
    * Mengecek status tombol untuk memaksa mode AP (Access Point).
    * Jika tombol tidak ditekan dan koneksi gagal, memulai mode AP dan membuat halaman web untuk konfigurasi WiFi.
    * Menunggu hingga terkoneksi ke WiFi.

  3. Fungsi testWifi:
  * Mencoba menghubungkan ke WiFi selama 10 detik.
  * Mengembalikan nilai 'true' jika terkoneksi, 'false' jika tidak.

  4. Fungsi launchWeb:
  * Mencetak informasi IP address perangkat (local dan softAP jika ada).
  * Menjalankan fungsi createWebServer untuk membuat halaman web konfigurasi WiFi.

  5. Fungsi setupAP:
  * Mengatur perangkat sebagai Access Point (AP) dengan nama "MiSREd IoT".
  * Mencari jaringan WiFi di sekitar dan menyimpan daftarnya dalam variabel st.
  * Menjalankan fungsi launchWeb untuk menampilkan halaman konfigurasi WiFi.

  6. Fungsi createWebServer:
  * Menangani permintaan ke halaman web:
    * '/' : Menampilkan halaman utama dengan daftar jaringan WiFi yang ditemukan dan formulir untuk memasukkan kredensial WiFi baru.
    * '/scan' : Memindai ulang jaringan WiFi dan menampilkan hasilnya.
    * '/setting' : Menerima kredensial WiFi baru, menyimpannya ke EEPROM, dan me-restart perangkat.
  
### Kesimpulan:
Kode ini dirancang untuk memudahkan konfigurasi WiFi pada perangkat dengan menyediakan antarmuka web yang dapat diakses dari perangkat lain. Pengguna dapat mengubah kredensial WiFi tanpa perlu mengubah kode secara langsung. Perintah yang digunakan adalah untuk menghidupkan hotspot WiFi. Hotspot WiFi tersebut akan memiliki nama "my-hotspot" dan kata sandi "my-password". Hotspot WiFi tersebut akan dapat diakses oleh perangkat lain di sekitar komputer. lain yang ditemukan di sekitar komputer, yaitu:
•	KENTUNGERS
•	Warung BNR
•	Redmi
•	My family
•	Griya Titi
•	Aisyah
•	Bacill
•	Sulistyo-5G. 
Kode program tersebut menggunakan kelas WiFi dan HTTPClient untuk mengirim permintaan HTTP. Kelas WiFi digunakan untuk menghubungkan perangkat ke jaringan WiFi. Kelas HTTPClient digunakan untuk mengirim permintaan HTTP ke server.
