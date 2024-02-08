#pragma once
#include "property.h"
#include "spreadsheet.h"

class PropertiesSheet : public SpreadSheet
{
public:
    PropertiesSheet(std::vector<Property>& properties, int rows, int cols, QWidget* parent);
    std::vector<Property> collectPropertiesFromUI();

protected:
    void setupContents() override;

private:
    std::vector<Property>& properties;
};


