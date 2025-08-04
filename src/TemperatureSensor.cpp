#include "Sensor.hpp"
#include <random>

class TemperatureSensor : public Sensor {
public:
    std::string getName() const override {
        return "TemperatureSensor";
    }

    float readValue() override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<float> dis(20.0f, 30.0f);
        return dis(gen);
    }
};
