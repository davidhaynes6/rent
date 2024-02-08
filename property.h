#pragma once
#include <QString>

class Property {
public:
    // Constructor
    Property(int id, const QString& rentalAddress, const QString& date, int initialPrice, double interest, int zillowEstimate, int netWorth);

    // Getters
    int id() const;
    QString rentalAddress() const;
    QString date() const;
    int initialPrice() const;
    double interest() const;
    int zillowEstimate() const;
    int netWorth() const;

    // Setters
    void setId(int id);
    void setRentalAddress(const QString& rentalAddress);
    void setDate(const QString& date);
    void setInitialPrice(int initialPrice);
    void setInterest(double interest);
    void setZillowEstimate(int zillowEstimate);
    void setNetWorth(int netWorth);

private:
    int m_id; // Primary key ID
    QString m_rentalAddress;
    QString m_date;
    int m_initialPrice;
    double m_interest;
    int m_zillowEstimate;
    int m_netWorth;
};