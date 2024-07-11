#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include<QMap>
#include "customdelegate.h"
#include<QStandardItemModel>
#include <QLabel>
#include<QNetworkAccessManager>
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
    // void analyzeLoss(QStandardItemModel *model, QLabel *outputLabel);
    // void setRiskAssessment(QStandardItemModel *model, QLabel *outputLabel_1,QLabel *outputLabel_2);
    void fetchDataForStockAsync(const QString &stockCode, QStandardItemModel *model, int row);
    void fetchDataForCurrentPage();
    void updateTableViewWithoutOffset();
private slots:
    void on_pushButton_clicked();
public slots:

    void nextPage();
    void previousPage();
    void firstPage();
    void lastPage();
private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QStandardItemModel *model;


    int currentPage;  // 当前页数
    int rowsPerPage;  // 每页显示的行数
    int totalRows;    // 总行数
    int totalPages;   // 总页数

    void updateTableView();
};
#endif // WIDGET_H
