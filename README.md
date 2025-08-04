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

