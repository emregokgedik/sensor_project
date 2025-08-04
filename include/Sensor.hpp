#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include <thread>
#include <atomic>
#include <mutex>

class Sensor {
public:
    virtual ~Sensor();

    virtual std::string getName() const = 0;
    virtual float readValue() = 0;

    void start();
    void stop();

    float getCurrentValue();

protected:
    virtual void run();

    std::atomic<bool> running_{false};
    std::thread worker_;
    std::mutex value_mutex_;
    float current_value_{0.0f};
};

#endif // SENSOR_HPP
