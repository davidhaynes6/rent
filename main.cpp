#include "rent.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rent w;
    w.show();
    return a.exec();
}