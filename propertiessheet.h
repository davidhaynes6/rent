#pragma once
#include "spreadsheet.h"

class PropertiesSheet : public SpreadSheet
{
public:
    PropertiesSheet(int rows, int cols, QWidget* parent = nullptr);

protected:
    void setupContents() override;
};