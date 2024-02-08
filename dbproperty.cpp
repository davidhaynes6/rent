#include "dbproperty.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <vector>

// Database Functions
bool DbProperty::openDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(RENT_DATABASE);

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return false;
    }
    return true;
}

bool DbProperty::databaseExists() const {
    return QFile::exists(RENT_DATABASE);
}

bool DbProperty::createDatabaseAndTable() {
    if (!openDatabase()) return false;

    // Create the table if it doesn't exist
    QSqlQuery createQuery;
    bool result = createQuery.exec("CREATE TABLE IF NOT EXISTS Property ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "rental_address TEXT NOT NULL, "
        "date TEXT NOT NULL, "
        "initial_price INTEGER NOT NULL, "
        "interest REAL NOT NULL, "
        "zillow_estimate INTEGER NOT NULL, "
        "net_worth INTEGER NOT NULL)");

    if (!result) {
        qDebug() << "Failed to create Property table:" << createQuery.lastError();
        QSqlDatabase::database().close();
    }

    QSqlDatabase::database().close();
    return result;
}

bool DbProperty::insertExampleData() {
    // Example list of properties to insert
    std::vector<Property> exampleProperties = {
        Property(-1, "1234 Maple Street", "2022-01-01", 120000, 3.5, 125000, 130000),
        Property(-1, "5678 Oak Avenue", "2022-02-01", 150000, 3.2, 155000, 160000),
        Property(-1, "9101 Pine Lane", "2022-03-01", 100000, 3.8, 105000, 110000),
    };

    // Insert the example properties into the database
    return saveToDatabase(exampleProperties);
}

std::vector<Property> DbProperty::loadFromDatabase() {
    std::vector<Property> properties;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(RENT_DATABASE);
    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return properties;
    }

    QSqlQuery query("SELECT id, rental_address, date, initial_price, interest, zillow_estimate, net_worth FROM property");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString rentalAddress = query.value(1).toString();
        QString date = query.value(2).toString();
        int initialPrice = query.value(3).toInt();
        double interest = query.value(4).toDouble();
        int zillowEstimate = query.value(5).toInt();
        int netWorth = query.value(6).toInt();

        Property property(id, rentalAddress, date, initialPrice, interest, zillowEstimate, netWorth);
        properties.push_back(property);
    }

    if (query.lastError().isValid()) {
        qDebug() << "Database query error:" << query.lastError();
    }

    db.close();

    return properties;
}

bool DbProperty::saveToDatabase(const std::vector<Property>& properties) {
    QSqlQuery query;
    bool result = true;

    // Start a transaction for batch insertion
    QSqlDatabase::database().transaction();

    for (const Property& property : properties) {
        if (property.id() > 0) {
            // Update existing property
            query.prepare("UPDATE property SET "
                "rental_address=:rental_address, date=:date, initial_price=:initial_price, "
                "interest=:interest, zillow_estimate=:zillow_estimate, net_worth=:net_worth "
                "WHERE id=:id");
            query.bindValue(":id", property.id());
        }
        else {
            // Insert new property, omitting the ID to allow auto-increment
            query.prepare("INSERT INTO property (rental_address, date, initial_price, interest, zillow_estimate, net_worth) "
                "VALUES (:rental_address, :date, :initial_price, :interest, :zillow_estimate, :net_worth)");
        }

        // Bind the values for both insert and update operations
        query.bindValue(":rental_address", property.rentalAddress());
        query.bindValue(":date", property.date());
        query.bindValue(":initial_price", property.initialPrice());
        query.bindValue(":interest", property.interest());
        query.bindValue(":zillow_estimate", property.zillowEstimate());
        query.bindValue(":net_worth", property.netWorth());

        if (!query.exec()) {
            qDebug() << "Failed to save property data:" << query.lastError();
            result = false;
            break; // Exit loop on first failure
        }
    }

    if (result) {
        QSqlDatabase::database().commit(); // Commit transaction if all operations were successful
    }
    else {
        QSqlDatabase::database().rollback(); // Rollback transaction on failure
    }

    return result;
}
