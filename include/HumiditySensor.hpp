#ifndef HUMIDITY_SENSOR_HPP
#define HUMIDITY_SENSOR_HPP

#include "Sensor.hpp"
#include <random>

class HumiditySensor : public Sensor {
public:
    std::string getName() const override {
        return "HumiditySensor";
    }

    float readValue() override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(0.0f, 100.0f); // %
        return dis(gen);
    }
};

#endif // HUMIDITY_SENSOR_HPP
