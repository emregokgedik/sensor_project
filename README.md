# Sensor Data Collection System

This project simulates a multi-sensor data collection system written in C++ with multithreading and MySQL database integration. It demonstrates how to manage multiple sensors running concurrently, collect their data, and store the readings in a MySQL database.

---

## Features

- **Multi-threaded Sensor Simulation:** Each sensor (Temperature, Pressure, Humidity, Light) runs in its own thread.
- **Thread-safe Data Access:** Uses mutexes and atomic flags to avoid data races.
- **Database Integration:** Sensor data is stored in a MySQL database (`sensor_db`) in real time.
- **Extensible Architecture:** Abstract base class `Sensor` allows easy addition of new sensor types.
- **Clean Code & Best Practices:** Uses modern C++ standards (C++17), smart pointers, and RAII.

---

## Prerequisites

- C++17 compatible compiler (e.g., g++ or clang++)
- MySQL server running locally or remotely
- MySQL C connector library installed (`libmysqlclient`)
- CMake or Make tool for building the project

---

## Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/sensor_project.git
   cd sensor_project


2. **Configure MySQL**
Create the database and table:
   ```bash
   CREATE DATABASE sensor_db;
USE sensor_db;

CREATE TABLE sensor_data (
  id INT AUTO_INCREMENT PRIMARY KEY,
  sensor_name VARCHAR(50),
  value FLOAT,
  timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

