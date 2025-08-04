#ifndef PRESSURE_SENSOR_HPP
#define PRESSURE_SENSOR_HPP

#include "Sensor.hpp"
#include <random>

class PressureSensor : public Sensor {
public:
    std::string getName() const override {
        return "PressureSensor";
    }

    float readValue() override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(950.0f, 1050.0f); // hPa
        return dis(gen);
    }
};

#endif // PRESSURE_SENSOR_HPP
