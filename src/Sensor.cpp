#include "Sensor.hpp"
#include <chrono>

Sensor::~Sensor() {
    stop();
}

void Sensor::start() {
    if (running_) return;
    running_ = true;
    worker_ = std::thread(&Sensor::run, this);
}

void Sensor::stop() {
    running_ = false;
    if (worker_.joinable()) {
        worker_.join();
    }
}

void Sensor::run() {
    while (running_) {
        float val = readValue();
        {
            std::lock_guard<std::mutex> lock(value_mutex_);
            current_value_ = val;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

float Sensor::getCurrentValue() {
    std::lock_guard<std::mutex> lock(value_mutex_);
    return current_value_;
}
