#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(const std::string& host,
                                 const std::string& user,
                                 const std::string& password,
                                 const std::string& database) {
    conn_ = mysql_init(nullptr);
    if (!conn_) {
        std::cerr << "MySQL init failed\n";
        exit(EXIT_FAILURE);
    }

    if (!mysql_real_connect(conn_, host.c_str(), user.c_str(), password.c_str(),
                            database.c_str(), 3306, nullptr, 0)) {
        std::cerr << "MySQL connection failed: " << mysql_error(conn_) << std::endl;
        exit(EXIT_FAILURE);
    }
}

DatabaseManager::~DatabaseManager() {
    if (conn_) {
        mysql_close(conn_);
    }
}

bool DatabaseManager::insertSensorData(const std::string& sensorName, float value) {
    std::string query = "INSERT INTO sensor_data (sensor_name, value) VALUES ('" + sensorName + "', " + std::to_string(value) + ")";
    if (mysql_query(conn_, query.c_str())) {
        std::cerr << "Insert failed: " << mysql_error(conn_) << std::endl;
        return false;
    }
    return true;
}
