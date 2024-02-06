#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rent.h"

class rent : public QMainWindow
{
    Q_OBJECT

public:
    rent(QWidget *parent = nullptr);
    ~rent();

    void initialize();

private:
    Ui::rentClass ui;
};
