#include "property.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <vector>

// Constructor
Property::Property(int id, const QString& rentalAddress, const QString& date, int initialPrice, double interest, int zillowEstimate, int netWorth)
    : m_id(id), m_rentalAddress(rentalAddress), m_date(date), m_initialPrice(initialPrice), m_interest(interest), m_zillowEstimate(zillowEstimate), m_netWorth(netWorth) {}

// Getters
int Property::id() const { return m_id; }
QString Property::rentalAddress() const { return m_rentalAddress; }
QString Property::date() const { return m_date; }
int Property::initialPrice() const { return m_initialPrice; }
double Property::interest() const { return m_interest; }
int Property::zillowEstimate() const { return m_zillowEstimate; }
int Property::netWorth() const { return m_netWorth; }

// Setters
void Property::setId(int id) { m_id = id; }
void Property::setRentalAddress(const QString& rentalAddress) { m_rentalAddress = rentalAddress; }
void Property::setDate(const QString& date) { m_date = date; }
void Property::setInitialPrice(int initialPrice) { m_initialPrice = initialPrice; }
void Property::setInterest(double interest) { m_interest = interest; }
void Property::setZillowEstimate(int zillowEstimate) { m_zillowEstimate = zillowEstimate; }
void Property::setNetWorth(int netWorth) { m_netWorth = netWorth; }
