# 📡 Çoklu Sensör Veri Toplama Uygulaması

Bu proje, C++ ile çoklu sensör simülasyonu, çoklu iş parçacığı (multithreading) kullanımı ve MySQL veritabanı entegrasyonunu gösteren bir uygulamadır. Birden fazla sensörün eş zamanlı olarak çalışmasını, verilerin toplanmasını ve bu verilerin MySQL veritabanına kaydedilmesini sağlar.


## Özellikler

- **Çoklu İş Parçacığı (Multithreading):** Her sensör (Sıcaklık, Basınç, Nem, Işık) kendi iş parçacığında çalışır.
- **Veri Yarışmasını Önleme:** Mutex ve atomic yapılar kullanılarak veri tutarlılığı sağlanır.
- **Veritabanı Entegrasyonu:** Sensör verileri gerçek zamanlı olarak MySQL veritabanına kaydedilir.
- **Esnek Tasarım:** Soyut `Sensor` sınıfı sayesinde yeni sensör tipleri kolayca eklenebilir.
- **Modern C++ Standartları:** C++17 kullanımı, akıllı işaretçiler ve RAII prensipleri uygulanmıştır.

---

## Gereksinimler
- C++17 uyumlu derleyici (g++ veya clang++ önerilir)
- MySQL sunucusu (yerel veya uzaktan)
- MySQL C bağlantı kütüphanesi (`libmysqlclient`)
- Make aracı (proje derlemesi için)
---

## Kurulum

1. **Projeyi klonlayın**
   ```bash
   git clone https://github.com/yourusername/sensor_project.git
   cd sensor_project
   ```


2. **MySQL veritabanını hazırlayın**
   ```bash
    CREATE DATABASE sensor_db;
    USE sensor_db;

    CREATE TABLE sensor_data (
        id INT AUTO_INCREMENT PRIMARY KEY,
        sensor_name VARCHAR(50),
        value FLOAT,
        timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    );
    ```



3. **Bağlantı ayarlarını main.cpp içinde güncelleyin**
Host, kullanıcı adı, şifre ve veritabanı ismini kendi ortamınıza göre ayarlayın.



4. **Projeyi derleyin**
   ```bash
   make
   ```



5. **Uygulamayı çalıştırın**
   ```bash
   ./sensor_app
   ```


## Uygulamadan Görseller:
<img width="425" height="372" alt="Ekran Resmi 2025-08-05 03 30 21" src="https://github.com/user-attachments/assets/21e92585-a59b-49fc-8f99-5617a5c749cc" />
<img width="410" height="276" alt="Ekran Resmi 2025-08-05 03 28 47" src="https://github.com/user-attachments/assets/8c2adb13-9faf-433f-b8b3-6b49294b60dd" />


