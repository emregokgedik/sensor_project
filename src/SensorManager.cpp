#include "SensorManager.hpp"

SensorManager::~SensorManager() {
    stopAll();
}

void SensorManager::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors_.push_back(sensor);
}

void SensorManager::startAll() {
    for (auto& sensor : sensors_) {
        sensor->start();
    }
}

void SensorManager::stopAll() {
    for (auto& sensor : sensors_) {
        sensor->stop();
    }
}

std::vector<std::pair<std::string, float>> SensorManager::getSensorData() {
    std::vector<std::pair<std::string, float>> data;
    for (const auto& sensor : sensors_) {
        data.emplace_back(sensor->getName(), sensor->getCurrentValue());
    }
    return data;
}
