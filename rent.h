#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rent.h"

class rent : public QMainWindow
{
    Q_OBJECT

public:
    rent(QWidget *parent = nullptr);
    ~rent();

private:
    Ui::rentClass ui;
};
