#include <iostream>
#include <thread>
#include <chrono>
#include "SensorManager.hpp"
#include "TemperatureSensor.hpp"

int main() {
    SensorManager manager;

    // Sensör ekle
    auto tempSensor = std::make_shared<TemperatureSensor>();
    manager.addSensor(tempSensor);

    // Tüm sensörleri başlat
    manager.startAll();

    // 5 saniye boyunca sensör verilerini yazdır
    for (int i = 0; i < 5; ++i) {
        auto data = manager.getSensorData();
        for (const auto& [name, value] : data) {
            std::cout << name << " değeri: " << value << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Sensörleri durdur
    manager.stopAll();

    return 0;
}
