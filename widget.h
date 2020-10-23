#ifndef WIDGET_H
#define WIDGET_H


#include "cellTable.h"
#include "cellType.h"
#include "ui_widget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    bool sudoku_solve(cellTable &grid, int spot_x, int spot_y);
    void setGridCell(cellType cell, QSpinBox* uiBox);
    void initBoxes();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
