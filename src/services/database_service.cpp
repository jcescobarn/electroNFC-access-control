#include <iostream>
#include "database_service.hpp"
#include <sqlite3.h>
#include <string>


DatabaseService::DatabaseService(const std::string& dbPath)
    : dbPath(dbPath), db(nullptr) {}

DatabaseService::~DatabaseService() {
    if (db) {
        sqlite3_close(db);
    }
}

bool DatabaseService::open() {
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc) {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::cout << "Base de datos abierta correctamente." << std::endl;
    return true;
}

bool DatabaseService::close() {
    if (db) {
        int rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            std::cerr << "Error al cerrar la base de datos: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }
        std::cout << "Base de datos cerrada correctamente." << std::endl;
    }
    return true;
}

ResultSet DatabaseService::executeQuery(const std::string &query) {
    ResultSet resultSet;
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), [](void* data, int numColumns, char** columnValues, char** columnNames) {
        ResultSet* resultSet = static_cast<ResultSet*>(data);
        Row row;
        for (int i = 0; i < numColumns; ++i) {
            row.push_back(columnValues[i]);
        }
        resultSet->push_back(row);
        return 0;
    }, &resultSet, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al ejecutar la consulta: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Consulta ejecutada correctamente." << std::endl;
    }
    return resultSet;
}

bool DatabaseService::registerAccess(const std::string &user_dni){
    try{
        std::string query = "INSERT INTO access_history (user_dni, entry_time, entry_date) VALUES ('"+user_dni+"', time('now'), date('now'));";
        std::cout << query << std::endl;
        //executeQuery(query);
        return true;
    }catch(...){
        return false;
    }
}
