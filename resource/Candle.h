#ifndef CANDLE_H
#define CANDLE_H

#include <QWidget>
#include <QChart>
#include <QCandlestickSeries>
#include <QCandlestickSet>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QStringList>
#include <QRegularExpression>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QStandardItemModel>
#include <QPixmap>
#include <QList>
#include <QGraphicsSimpleTextItem>
#include <QLabel>
#include<QTimer>
#include<QSqlDatabase>
#include<QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class Candle;
}
QT_END_NAMESPACE

class Candle : public QWidget
{
    Q_OBJECT

public:
    explicit Candle(QWidget *parent = nullptr);
    ~Candle();
    QCandlestickSet *add_candle(double open, double high, double low, double close,QString date);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_buyin_clicked();
    void on_pushButton_sellout_clicked();
    void handleCandleHovered(bool status, double open, double high, double low, double close,QString date); // 添加悬停事件处理函数

    void on_pushButton_2_clicked();
    void update_candle();

private:
    Ui::Candle *ui;
    QCandlestickSeries *series;
    QValueAxis *axisY;
    QBarCategoryAxis *Ax;
    QChart *chart;
    QStringList category;
    QStringList text_split;
    QStandardItemModel *model;
    QStandardItemModel *model_profit;
    QList<QCandlestickSet*> series_list;

    double totalmoney = 100000;
    int cur_date = 0;
    int maxbuyin = 0;
    int maxsellout = 0;
    int trade_id = 0;
    int maxqueue[500]={0}, minqueue[500]={0};
    int h_max = 0, t_max = 0, h_min = 0, t_min = 0;
    QString code,name;
    int totalStocks = 0; // 新增：持有的总股票数量
    double totalCost = 0; // 新增：持有股票的总成本

    void init();
    void init_table();
    void insert_data_into_candle(int m);
    void add_data_to_table(const QString &trade_type); // 修改为const QString &
    void update_profittable();
    void drawarrow(int type);
    QString download_kline(const QString &code);
    QStringList match_kline(const QString &text);
    QByteArray download_arrow(int type);
    QTimer *update_timer;
    QLabel *hoverLabel; // 添加用于显示价格信息的标签
    int max_date;
};

#endif // CANDLE_H
