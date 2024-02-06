#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QLineEdit;
class QToolBar;
class QTableWidgetItem;
class QTableWidget;
QT_END_NAMESPACE

class SpreadSheet : public QMainWindow
{
    Q_OBJECT
public:
    SpreadSheet(int rows, int cols, QWidget* parent = nullptr);

public slots:
    void updateStatus(QTableWidgetItem* item);
    void updateColor(QTableWidgetItem* item);
    void updateLineEdit(QTableWidgetItem* item);
    void returnPressed();
    void selectColor();
    void selectFont();
    void clear();
    void actionSum();
    void actionSubtract();
    void actionAdd();
    void actionMultiply();
    void actionDivide();

protected:
    void setupContextMenu();
    virtual void setupContents();
    void createActions();

    void actionMath_helper(const QString& title, const QString& op);
    bool runInputDialog(const QString& title,
        const QString& c1Text,
        const QString& c2Text,
        const QString& opText,
        const QString& outText,
        QString* cell1, QString* cell2, QString* outCell);

    QToolBar* toolBar;
    QAction* colorAction;
    QAction* fontAction;
    QAction* firstSeparator;
    QAction* cell_sumAction;
    QAction* cell_addAction;
    QAction* cell_subAction;
    QAction* cell_mulAction;
    QAction* cell_divAction;
    QAction* secondSeparator;
    QAction* clearAction;
    QAction* aboutSpreadSheet;
    QLabel* cellLabel;
    QTableWidget* table;
    QLineEdit* formulaInput;

};

void decode_pos(const QString& pos, int* row, int* col);
QString encode_pos(int row, int col);
