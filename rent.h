#pragma once

#include <QtWidgets/QMainWindow>
#include "property.h"
#include "dbproperty.h"
#include "ui_rent.h"

class rent : public QMainWindow
{
    Q_OBJECT

public:
    static constexpr auto DASHBOARD_SHEET = 0;
    static constexpr auto PROPERTY_SHEET = 1;
    static constexpr auto MAINTENANCE_SHEET = 2;
    static constexpr auto PROPERTY_SHEET2 = 3;

    explicit rent(QWidget *parent = nullptr);
    ~rent();

    void initialize();

public slots:
    void save();

private:
    Ui::rentClass ui;
};
