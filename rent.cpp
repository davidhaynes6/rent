#include "rent.h"
#include "propertiessheet.h"

rent::rent(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButtonSave, &QPushButton::clicked, this, &rent::save);
}

rent::~rent()
{}

void rent::initialize()
{
    // Load Properties from database
    DbProperty db;
    if (!db.databaseExists()) {
        db.createDatabaseAndTable();
        db.insertExampleData();
    }

    std::vector<Property> properties = db.loadFromDatabase();

    auto rows = 10;
    auto cols = 6;

    // Add Properties Spreadsheet
    PropertiesSheet* propertiessheet = new PropertiesSheet(properties, rows, cols, this);
    int tabIndex = ui.tabWidget->addTab(propertiessheet, tr("Properties2"));
    ui.tabWidget->setCurrentIndex(tabIndex);
}

void rent::save()
{
    DbProperty db;
    QWidget* tabWidget = ui.tabWidget->widget(PROPERTY_SHEET2);
    PropertiesSheet* propertiesSheet = dynamic_cast<PropertiesSheet*>(tabWidget);
    if (propertiesSheet != nullptr) {
        std::vector<Property> properties = propertiesSheet->collectPropertiesFromUI();
        db.saveToDatabase(properties);
    }
}