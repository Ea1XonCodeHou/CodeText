#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

struct StockInfo {
    QString code;
    double currentprice;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void updatePrices();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QStandardItemModel *model;

    QTimer *updateTimer;
    QNetworkAccessManager *networkManager;
    double initialAsset = 10000.0;

    void connectSql();
    void loadData();

    void loadPersonalInfo();
    void updateLabels(double marketValue, double totalProfitLoss);

    StockInfo getStockInfo(const QString &stockcode);
};
#endif // WIDGET_H
