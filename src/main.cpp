#include <iostream>
#include "TemperatureSensor.hpp"

int main() {
    TemperatureSensor tempSensor;

    std::cout << tempSensor.getName() << " değeri: " << tempSensor.readValue() << std::endl;

    return 0;
}
