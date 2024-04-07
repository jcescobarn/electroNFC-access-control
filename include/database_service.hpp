#ifndef DATABASE_SERVICE_HPP
#define DATABASE_SERVICE_HPP

#include <string>
#include <vector>
#include <sqlite3.h>

using Row = std::vector<std::string>;
using ResultSet = std::vector<Row>;

class DatabaseService {
public:  // Declarar el constructor como público
    DatabaseService(const std::string& dbPath);
    ~DatabaseService();
    bool open();
    bool close();
    ResultSet executeQuery(const std::string &query);
    bool registerAccess(const std::string &user_dni);

private:
    std::string dbPath;
    sqlite3* db; 
};

#endif
