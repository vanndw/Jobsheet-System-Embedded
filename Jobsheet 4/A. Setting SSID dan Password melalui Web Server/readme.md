# A. Setting SSID dan Password Wi-Fi ESP32 melalui Web Server

## 1. Alat dan Bahan
1) ESP32
2) Arduino IDE

## 2. Source Code
![Setting SSID dan PASS](![Penjelasan Kode](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/dfade275-e0f1-4619-9a7c-3a3f26567eff)
)

## 3. Flowchart
![jobsheet 4 A flowchart](![Flow Chart](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/fc2066aa-c64f-4eb8-b5e0-f0d6592d212d)
)


## 4. Hasil dan Pembahasan
### Dokumentasi Hasil
1. Tampilan Awal Serial Monitor Sebelum Dihubungkan

   ![Tampilan Awal Serial Monitor]()![1  Tampilan Awal Serial Monitor Sebelum Dihubungkan](https://github.com/vanndw/Jobsheet-System-Embedded/assets/151889936/10872d86-4999-42a5-8266-28aa47ab3d81)

2. Tampilan Web
   
   ![Tampilan Web](https://github.com/JustBadrun/Embeded_System/assets/128286595/0da30011-d430-45cf-b6d4-a1c536ae52fc)
3. Serial Monitor Setelah Memasukkan SSID dan PASS
   
   ![Serial Monitor Setelah Memasukkan SSID dan PASS](https://github.com/JustBadrun/Embeded_System/assets/128286595/b5b6295a-249e-4deb-8f9d-94e9efa34cd5)
4. Serial Monitor Setelah Berhasil Terhubung
   
   ![Serial Monitor Setelah Berhasil Terhubung](https://github.com/JustBadrun/Embeded_System/assets/128286595/edbb574a-82a5-4bf2-94b3-53a66fee9daa)

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
Kode ini dirancang untuk memudahkan konfigurasi WiFi pada perangkat dengan menyediakan antarmuka web yang dapat diakses dari perangkat lain. Pengguna dapat mengubah kredensial WiFi tanpa perlu mengubah kode secara langsung.
