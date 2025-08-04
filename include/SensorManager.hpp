#ifndef SENSORMANAGER_HPP
#define SENSORMANAGER_HPP

#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <memory>
#include "Sensor.hpp"

class SensorManager {
public:
    SensorManager();
    ~SensorManager();

    // Sensör ekle
    void addSensor(std::shared_ptr<Sensor> sensor);

    // Tüm sensörleri çalıştır
    void startAll();

    // Çalışan sensörleri durdur
    void stopAll();

    // Sensör verilerini al
    std::vector<std::pair<std::string, float>> getSensorData();

private:
    void sensorThreadFunc(std::shared_ptr<Sensor> sensor);

    std::vector<std::shared_ptr<Sensor>> sensors_;
    std::vector<std::thread> threads_;
    std::mutex dataMutex_;
    std::vector<std::pair<std::string, float>> sensorData_;
    std::atomic<bool> running_;
};

#endif // SENSORMANAGER_HPP
