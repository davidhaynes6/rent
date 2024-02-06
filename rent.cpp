#include "rent.h"
#include "dbproperty.h"
#include "propertiessheet.h"

rent::rent(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    auto rows = 10;
    auto cols = 6;

    // Add Properties Spreadsheet
    PropertiesSheet* propertiessheet = new PropertiesSheet(rows, cols, this);
    int tabIndex = ui.tabWidget->addTab(propertiessheet, tr("Properties2"));
    ui.tabWidget->setCurrentIndex(tabIndex);
}

rent::~rent()
{}

void rent::initialize()
{
    // Load Properties from database
    DbProperty db;
    db.createDatabaseAndTable();
}