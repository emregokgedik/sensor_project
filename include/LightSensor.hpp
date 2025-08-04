#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include "Sensor.hpp"
#include <random>

class LightSensor : public Sensor {
public:
    std::string getName() const override {
        return "LightSensor";
    }

    float readValue() override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(0.0f, 10000.0f); // lux
        return dis(gen);
    }
};

#endif // LIGHT_SENSOR_HPP
