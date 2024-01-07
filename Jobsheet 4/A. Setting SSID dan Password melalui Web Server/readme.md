# A. Setting SSID dan Password Wi-Fi ESP32 melalui Web Server

## 1. Alat dan Bahan
1) ESP32
2) Arduino IDE

## 2. Source Code
![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/dfade275-e0f1-4619-9a7c-3a3f26567eff)


## 3. Flowchart
![Flow Chart](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/fc2066aa-c64f-4eb8-b5e0-f0d6592d212d)



## 4. Hasil dan Pembahasan
### Dokumentasi Hasil
1. Tampilan Awal Serial Monitor Sebelum Dihubungkan

![1  Tampilan Awal Serial Monitor Sebelum Dihubungkan](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/44b02875-a99c-41b3-9c9a-e08512197419)


2. Tampilan Web
   
 ![2  tampilan web](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/6eb69119-9b9f-4eb0-9a04-47bf4bb9f5b0)
 
3. Serial Monitor Setelah Memasukkan SSID dan PASS
   
![3  serial monitor setelah memasukan ssid dan pass](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/940a3d55-d74d-4d81-9628-67cfab173cd5)

 
4. Serial Monitor Setelah Berhasil Terhubung
   
![4  Serial Monitor Setelah Berhasil Terhubung](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/4c166cf2-e7f7-4a4c-94e5-c99edc8052a4)


### Pembahasan Kode
#### **Fungsi Utama Kode:**

Kode ini berfungsi untuk menghubungkan perangkat ke jaringan WiFi. Jika koneksi gagal, kode ini akan menyediakan antarmuka web untuk pengguna mengubah kredensial WiFi.

#### **Alur Kode:**

Kode ini dibagi menjadi dua bagian utama, yaitu setup awal dan loop utama.

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

### Hasil:

![tampilan wifi](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/c474d279-964c-488a-aa0e-990665f07cbd)
![SSID dan Pass](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/3a995fff-74e4-4826-97a5-8d76231628b2)


  
### Kesimpulan:
Kode ini dirancang untuk memudahkan konfigurasi WiFi pada perangkat dengan menyediakan antarmuka web yang dapat diakses dari perangkat lain. Pengguna dapat mengubah kredensial WiFi tanpa perlu mengubah kode secara langsung.
