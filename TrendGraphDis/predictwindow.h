#ifndef PREDICTWINDOW_H
#define PREDICTWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include <QColor>
#include <QPainter>
#include <QToolTip>

struct StockData {
    QString date;
    double open;
    double close;
    double high;  // 最高价
    double low;   // 最低价
    double changeAmount;
    double changePercentage;
};

namespace Ui{
   class PredictWindow;
}

class PredictWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PredictWindow(QWidget *parent = nullptr);
    ~PredictWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override; // 添加鼠标移动事件处理函数

signals:

private:


    void parseJsonResponse(const QByteArray& responseData);
    double linearRegression(const QVector<double>& x, const QVector<double>& y);

    Ui::PredictWindow *ui;
    QNetworkAccessManager* networkManager;
    QVector<StockData> stockDataList;
    QVector<QRect> rectList;

private slots:
    void fetchStockData();
    void onNetworkReply(QNetworkReply* reply);
    void onReturnButtonClicked();
};

#endif // PREDICTWINDOW_H
