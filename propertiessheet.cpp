#include "propertiessheet.h"
#include "spreadsheetitem.h"

PropertiesSheet::PropertiesSheet(int rows, int cols, QWidget* parent)
    : SpreadSheet(rows, cols, parent) 
{
    setupContents();
}

void PropertiesSheet::setupContents()
{
    QBrush titleBackground(Qt::lightGray);
    QFont titleFont = table->font();
    titleFont.setBold(true);

    // column 0
    table->setItem(0, 0, new SpreadSheetItem("Rental Address"));
    table->item(0, 0)->setBackground(titleBackground);
    table->item(0, 0)->setToolTip("This column shows property address");
    table->item(0, 0)->setFont(titleFont);

    table->setItem(1, 0, new SpreadSheetItem("1038 Burns Avenue"));
    table->setItem(2, 0, new SpreadSheetItem("3130 Coral Park Drive"));
    table->setItem(3, 0, new SpreadSheetItem("8587 Eagle Ridge Drive"));
    table->setItem(4, 0, new SpreadSheetItem("4608 Snowbird Avenue"));
    table->setItem(5, 0, new SpreadSheetItem("4167 School Section Road"));
    table->setItem(6, 0, new SpreadSheetItem("5175 Cleves Warsaw Road"));
    table->setItem(7, 0, new SpreadSheetItem("8128 Hollybrook Court"));
    table->setItem(8, 0, new SpreadSheetItem("11999 Marwood Road"));
    table->setItem(9, 0, new SpreadSheetItem("Total:"));

    table->item(9, 0)->setFont(titleFont);
    table->item(9, 0)->setBackground(titleBackground);

    // column 1
    table->setItem(0, 1, new SpreadSheetItem("Date"));
    table->item(0, 1)->setBackground(titleBackground);
    table->item(0, 1)->setToolTip("This column shows the purchase date");
    table->item(0, 1)->setFont(titleFont);

    table->setItem(1, 1, new SpreadSheetItem("7/1/2019"));
    table->setItem(2, 1, new SpreadSheetItem("7/1/2020"));
    table->setItem(3, 1, new SpreadSheetItem("7/1/2014"));
    table->setItem(4, 1, new SpreadSheetItem("7/1/2004"));
    table->setItem(5, 1, new SpreadSheetItem("7/1/2016"));
    table->setItem(6, 1, new SpreadSheetItem("7/1/2018"));
    table->setItem(7, 1, new SpreadSheetItem("7/1/2008"));
    table->setItem(8, 1, new SpreadSheetItem("8/1/2006"));

    table->setItem(9, 1, new SpreadSheetItem());
    table->item(9, 1)->setBackground(titleBackground);

    // column 2
    table->setItem(0, 2, new SpreadSheetItem("Initial Price"));
    table->item(0, 2)->setBackground(titleBackground);
    table->item(0, 2)->setToolTip("This column shows the initial property price");
    table->item(0, 2)->setFont(titleFont);

    table->setItem(1, 2, new SpreadSheetItem("195000"));
    table->setItem(2, 2, new SpreadSheetItem("210000"));
    table->setItem(3, 2, new SpreadSheetItem("318000"));
    table->setItem(4, 2, new SpreadSheetItem("180000"));
    table->setItem(5, 2, new SpreadSheetItem("95000"));
    table->setItem(6, 2, new SpreadSheetItem("220000"));
    table->setItem(7, 2, new SpreadSheetItem("110000"));
    table->setItem(8, 2, new SpreadSheetItem("53000"));

    table->setItem(9, 2, new SpreadSheetItem());
    table->item(9, 2)->setBackground(Qt::lightGray);

    // column 3
    table->setItem(0, 3, new SpreadSheetItem("Interest"));
    table->item(0, 3)->setBackground(titleBackground);
    table->item(0, 3)->setToolTip("This column shows the currency");
    table->item(0, 3)->setFont(titleFont);

    table->setItem(1, 3, new SpreadSheetItem("4.000"));
    table->setItem(2, 3, new SpreadSheetItem("6.125"));
    table->setItem(3, 3, new SpreadSheetItem("2.750"));
    table->setItem(4, 3, new SpreadSheetItem("3.500"));
    table->setItem(5, 3, new SpreadSheetItem("3.990"));
    table->setItem(6, 3, new SpreadSheetItem("2.750"));
    table->setItem(7, 3, new SpreadSheetItem("0.000"));
    table->setItem(8, 3, new SpreadSheetItem("0.000"));

    table->setItem(9, 3, new SpreadSheetItem());
    table->item(9, 3)->setBackground(Qt::lightGray);

    // column 4
    table->setItem(0, 4, new SpreadSheetItem("Zillow Estimate"));
    table->item(0, 4)->setBackground(titleBackground);
    table->item(0, 4)->setToolTip("This column shows the exchange rate to NOK");
    table->item(0, 4)->setFont(titleFont);

    table->setItem(1, 4, new SpreadSheetItem("376300"));
    table->setItem(2, 4, new SpreadSheetItem("247100"));
    table->setItem(3, 4, new SpreadSheetItem("525800"));
    table->setItem(4, 4, new SpreadSheetItem("357000"));
    table->setItem(5, 4, new SpreadSheetItem("183000"));
    table->setItem(6, 4, new SpreadSheetItem("280300"));
    table->setItem(7, 4, new SpreadSheetItem("170400"));
    table->setItem(8, 4, new SpreadSheetItem("160300"));

    table->setItem(9, 4, new SpreadSheetItem());
    table->item(9, 4)->setBackground(titleBackground);

    // column 5
    table->setItem(0, 5, new SpreadSheetItem("Net Worth"));
    table->item(0, 5)->setBackground(titleBackground);
    table->item(0, 5)->setToolTip("This column shows the expenses in NOK");
    table->item(0, 5)->setFont(titleFont);

    table->setItem(1, 5, new SpreadSheetItem("- E2 C2"));
    table->setItem(2, 5, new SpreadSheetItem("- E3 C3"));
    table->setItem(3, 5, new SpreadSheetItem("- E4 C4"));
    table->setItem(4, 5, new SpreadSheetItem("- E5 C5"));
    table->setItem(5, 5, new SpreadSheetItem("- E6 C6"));
    table->setItem(6, 5, new SpreadSheetItem("- E7 C7"));
    table->setItem(7, 5, new SpreadSheetItem("- E8 C8"));
    table->setItem(8, 5, new SpreadSheetItem("- E9 C9"));

    table->setItem(9, 5, new SpreadSheetItem("sum F2 F9"));
    table->item(9, 5)->setBackground(titleBackground);
}
