#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include<QMap>
#include "customdelegate.h"
#include<QStandardItemModel>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
#include <QStyledItemDelegate>

class CustomDelegate;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void linkSlot();
    void showSlot();
    void calculateBuySellRatio();
    QMap<QString, QString> download_file(QString fn);
    void analyzeLoss(QStandardItemModel *model, QLabel *outputLabel);
    void setRiskAssessment(QStandardItemModel *model, QLabel *outputLabel);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
};
#endif // WIDGET_H
