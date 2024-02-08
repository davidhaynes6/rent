#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "property.h"
#include <vector>
#include <QString>

class DbProperty {
public:
    // Database constant
    static constexpr auto RENT_DATABASE = "rent.db"; 

    // Database Functions
    std::vector<Property> loadFromDatabase();
    bool saveToDatabase(const std::vector<Property>& properties);
    bool createDatabaseAndTable();
    bool insertExampleData();
    bool databaseExists() const;

private:
    bool openDatabase(); // Utility function to open database connection
};