#include <iostream>
#include <thread>
#include <chrono>
#include "SensorManager.hpp"
#include "TemperatureSensor.hpp"
#include "DatabaseManager.hpp"

int main() {
    std::cout << "Program başladı." << std::endl;

    SensorManager manager;
    auto tempSensor = std::make_shared<TemperatureSensor>();
    manager.addSensor(tempSensor);
    manager.startAll();

    // Veritabanı bağlantısı - kendi kullanıcı adı, şifre ve db ismini gir
    DatabaseManager db("localhost", "root", "", "sensor_db");

    for (int i = 0; i < 5; ++i) {
        auto data = manager.getSensorData();
        for (const auto& [name, value] : data) {
            std::cout << name << " değeri: " << value << std::endl;
            db.insertSensorData(name, value);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    manager.stopAll();

    std::cout << "Program bitti." << std::endl;
    return 0;
}
