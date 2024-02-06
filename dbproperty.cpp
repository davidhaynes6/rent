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

bool DbProperty::createDatabaseAndTable() {
    if (!openDatabase()) return false;
    QSqlQuery query;
    bool result = query.exec("CREATE TABLE IF NOT EXISTS property ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "rental_address TEXT NOT NULL, "
        "date TEXT NOT NULL, "
        "initial_price INTEGER NOT NULL, "
        "interest REAL NOT NULL, "
        "zillow_estimate INTEGER NOT NULL, "
        "net_worth INTEGER NOT NULL)");
    if (!result) {
        qDebug() << "Failed to create table:" << query.lastError();
    } else {
        // Insert initial example data
        const char* initialData[] = {
            "INSERT INTO property (rental_address, date, initial_price, interest, zillow_estimate, net_worth) VALUES ('1038 Burns Avenue', '7/1/2019', 195000, 4.0, 376300, 181300)",
            "INSERT INTO property (rental_address, date, initial_price, interest, zillow_estimate, net_worth) VALUES ('3130 Coral Park Drive', '7/1/2020', 210000, 6.125, 247100, 37100)",
        };

        for (const char* sql : initialData) {
            if (!query.exec(sql)) {
                qDebug() << "Failed to insert initial data:" << query.lastError();
                result = false;
            }
        }
    }

    QSqlDatabase::database().close();
    return result;
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

        Property property(rentalAddress, date, initialPrice, interest, zillowEstimate, netWorth);
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
        query.prepare("INSERT INTO property (id, rental_address, date, initial_price, interest, zillow_estimate, net_worth) "
            "VALUES (:id, :rental_address, :date, :initial_price, :interest, :zillow_estimate, :net_worth) "
            "ON CONFLICT(id) DO UPDATE SET "
            "rental_address=:rental_address, date=:date, initial_price=:initial_price, "
            "interest=:interest, zillow_estimate=:zillow_estimate, net_worth=:net_worth");
        query.bindValue(":id", property.id());
        query.bindValue(":rental_address", property.rentalAddress());
        query.bindValue(":date", property.date());
        query.bindValue(":initial_price", property.initialPrice());
        query.bindValue(":interest", property.interest());
        query.bindValue(":zillow_estimate", property.zillowEstimate());
        query.bindValue(":net_worth", property.netWorth());

        if (!query.exec()) {
            qDebug() << "Failed to insert property data:" << query.lastError();
            result = false;
            break; // Exit loop on first failure
        }
    }

    if (result) {
        QSqlDatabase::database().commit(); // Commit transaction if all inserts were successful
    }
    else {
        QSqlDatabase::database().rollback(); // Rollback transaction on failure
    }

    return result;
}