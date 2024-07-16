#ifndef MYLOG_H
#define MYLOG_H

#include <QWidget>
#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


QT_BEGIN_NAMESPACE
namespace Ui {
class Mylog;
}
QT_END_NAMESPACE

struct StockInfo2 {
    QString code;
    double currentprice;
};

class Mylog : public QWidget
{
    Q_OBJECT

public:
    Ui::Mylog *ui;
    Mylog(QWidget *parent = nullptr);
    ~Mylog();

private slots:
    void updatePrices();

private:
    QSqlDatabase db;
    QStandardItemModel *model;

    QTimer *updateTimer;
    QTimer *dbUpdateTimer; // 新增定时器用于更新数据库

    QNetworkAccessManager *networkManager;
    double initialAsset = 10000.0;

    void connectSql();
    void loadData();

    void loadPersonalInfo();
    void updateLabels(double marketValue, double totalProfitLoss);
    void updateDatabase(); // 新的槽函数用于更新数据库

    StockInfo2 getStockInfo(const QString &stockcode);
};
#endif // MYLOG_H
