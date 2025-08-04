#include "SensorManager.hpp"
#include <chrono>
#include <iostream>

SensorManager::SensorManager() : running_(false) {}

SensorManager::~SensorManager() {
    stopAll();
}

void SensorManager::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors_.push_back(sensor);
}

void SensorManager::startAll() {
    running_ = true;
    for (auto& sensor : sensors_) {
        threads_.emplace_back(&SensorManager::sensorThreadFunc, this, sensor);
    }
}

void SensorManager::stopAll() {
    running_ = false;
    for (auto& t : threads_) {
        if (t.joinable()) {
            t.join();
        }
    }
    threads_.clear();
}

void SensorManager::sensorThreadFunc(std::shared_ptr<Sensor> sensor) {
    while (running_) {
        float value = sensor->readValue();

        {
            std::lock_guard<std::mutex> lock(dataMutex_);
            bool updated = false;
            for (auto& data : sensorData_) {
                if (data.first == sensor->getName()) {
                    data.second = value;
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                sensorData_.emplace_back(sensor->getName(), value);
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::vector<std::pair<std::string, float>> SensorManager::getSensorData() {
    std::lock_guard<std::mutex> lock(dataMutex_);
    return sensorData_;
}
