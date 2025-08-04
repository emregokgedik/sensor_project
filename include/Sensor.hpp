#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual std::string getName() const = 0;
    virtual float readValue() = 0;
};

#endif // SENSOR_HPP
