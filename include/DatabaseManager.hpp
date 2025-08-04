#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include <mysql/mysql.h>
#include <string>
#include <iostream>

class DatabaseManager {
public:
    DatabaseManager(const std::string& host,
                    const std::string& user,
                    const std::string& password,
                    const std::string& database);

    ~DatabaseManager();

    bool insertSensorData(const std::string& sensorName, float value);

private:
    MYSQL* conn_;
};

#endif
