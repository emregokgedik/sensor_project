#ifndef SENSORMANAGER_HPP
#define SENSORMANAGER_HPP

#include <vector>
#include <memory>
#include "Sensor.hpp"

class SensorManager {
public:
    SensorManager() = default;
    ~SensorManager();

    void addSensor(std::shared_ptr<Sensor> sensor);

    void startAll();
    void stopAll();

    std::vector<std::pair<std::string, float>> getSensorData();

private:
    std::vector<std::shared_ptr<Sensor>> sensors_;
};

#endif // SENSORMANAGER_HPP
