#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtNetwork/QNetworkRequest>
#include <QEventLoop>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap background(":/test.png");

    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
    QPixmap userpic(":/userpic.png");
    ui->userpicLabel->setPixmap(userpic);
    QPixmap housepic("://favicon.ico");
    ui->houseLabel->setPixmap(housepic);

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({tr("股票名称"), tr("股票代码"), tr("股数"), tr("持仓成本价"),  tr("现价"), tr("持仓盈亏")});

    // 获取表格的水平表头视图
    QHeaderView *header = ui->tableView->horizontalHeader();
    QFont font("华文中宋", 14);
    font.setBold(true);

    // 设置表头的字体为加粗字体
    header->setFont(font);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView { alternate-background-color: rgb(217, 225, 240); background: rgb(255, 255, 255); }");
    ui->tableView->verticalHeader()->setHidden(true);

    ui->tableView->setModel(model);

    connectSql();
    loadData();

    // 创建网络管理器
    networkManager = new QNetworkAccessManager(this);

    // 创建定时器，每5秒刷新一次价格
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &Widget::updatePrices);
    updateTimer->start(5000); // 5秒刷新一次
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectSql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("user_Hyc777");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setPassword("123098Qazplm");
    if (!db.open()) {
        QMessageBox::critical(this, "数据库连接失败", db.lastError().text());
    }
}

void Widget::loadPersonalInfo()
{
    QSqlQuery query(db);
    query.prepare("SELECT id FROM personal_info");
    if (query.exec() && query.next()) {
        QString userId = query.value("id").toString();
        ui->idLabel->setText(userId);
    } else {
        QMessageBox::critical(this, "查询失败", "无法加载个人信息");
    }

    // 设置初始资产
    ui->AllMoneyLabel->setText(QString::number(initialAsset, 'f', 2) + " 元");
}

void Widget::loadData()
{
    QSqlQuery query(db);
    query.prepare("SELECT stock_symbol, id, "
                  "SUM(CASE WHEN transaction_type = '买入' THEN quantity ELSE 0 END) - "
                  "SUM(CASE WHEN transaction_type = '卖出' THEN quantity ELSE 0 END) AS net_quantity, "
                  "SUM(CASE WHEN transaction_type = '买入' THEN quantity * price ELSE 0 END) / "
                  "SUM(CASE WHEN transaction_type = '买入' THEN quantity ELSE 0 END) AS avg_cost "
                  "FROM transactions "
                  "GROUP BY stock_symbol, id "
                  "HAVING net_quantity > 0");

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", query.lastError().text());
        return;
    }

    double totalMarketValue = 0.0;
    double totalProfitLoss = 0.0;

    int row = 0;
    while (query.next()) {
        QString stockSymbol = query.value("stock_symbol").toString();
        QString stockId = query.value("id").toString();
        int netQuantity = query.value("net_quantity").toInt();
        double avgCost = query.value("avg_cost").toDouble();
        double currentPrice = getStockInfo(stockId).currentprice; // 获取当前价格
        double marketValue = currentPrice * netQuantity;
        double profitLoss = (currentPrice - avgCost) * netQuantity;

        totalMarketValue += marketValue;
        totalProfitLoss += profitLoss;

        model->setItem(row, 0, new QStandardItem(stockSymbol));
        model->setItem(row, 1, new QStandardItem(stockId));
        model->setItem(row, 2, new QStandardItem(QString::number(netQuantity)));
        model->setItem(row, 3, new QStandardItem(QString::number(avgCost, 'f', 2)));
        model->setItem(row, 4, new QStandardItem(QString::number(currentPrice, 'f', 2)));
        model->setItem(row, 5, new QStandardItem(QString::number(profitLoss, 'f', 2)));

        // 设置每一项的字体和颜色
        QFont font("华文中宋", 15); // 设置字体大小为15号
        for (int col = 0; col < model->columnCount(); ++col) {
            QStandardItem *item = model->item(row, col);
            if (item) {
                item->setFont(font); // 设置字体
                if (col == 5) { // 盈亏列
                    if (profitLoss > 0) {
                        item->setForeground(QBrush(Qt::red)); // 盈亏大于0，红色
                        item->setFont(font);
                    } else if (profitLoss < 0) {
                        item->setForeground(QBrush(Qt::green)); // 盈亏小于0，绿色
                        item->setFont(font);
                    } else {
                        item->setForeground(QBrush(Qt::black)); // 盈亏等于0，黑色
                        item->setFont(font);
                    }
                }
            }
        }

        row++;
    }

    // 更新标签
    updateLabels(totalMarketValue, totalProfitLoss);
}


StockInfo Widget::getStockInfo(const QString &stockcode)
{
    QString url = QString("https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=&secid=1.%1&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1,f2,f3,f4,f5,f6&fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61&klt=101&fqt=1&end=20500101&lmt=120").arg(stockcode);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    StockInfo stockInfo;
    stockInfo.code = stockcode;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObj = jsonDoc.object();
        QJsonObject dataObj = jsonObj["data"].toObject();

        QString code = dataObj["code"].toString();
        QString name = dataObj["name"].toString();

        stockInfo.code = code;


        QJsonArray klines = dataObj["klines"].toArray();
        if (!klines.isEmpty()) {
            QStringList lastLine = klines.last().toString().split(",");
            if (lastLine.size() > 10) {
                stockInfo.currentprice = lastLine[2].toDouble();
            }
        }
    }

    reply->deleteLater();
    return stockInfo;
}

void Widget::updatePrices()
{
    double totalMarketValue = 0.0;
    double totalProfitLoss = 0.0;

    int rowCount = model->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        QString stockId = model->item(row, 1)->text();
        double currentPrice = getStockInfo(stockId).currentprice;
        model->setItem(row, 4, new QStandardItem(QString::number(currentPrice, 'f', 2)));

        double avgCost = model->item(row, 3)->text().toDouble();
        int netQuantity = model->item(row, 2)->text().toInt();
        double profitLoss = (currentPrice - avgCost) * netQuantity;
        model->setItem(row, 5, new QStandardItem(QString::number(profitLoss, 'f', 2)));

        double marketValue = currentPrice * netQuantity;
        totalMarketValue += marketValue;
        totalProfitLoss += profitLoss;
    }

    // 更新标签
    updateLabels(totalMarketValue, totalProfitLoss);
}

void Widget::updateLabels(double marketValue, double totalProfitLoss)
{
    QFont Tempfont("华文中宋", 13);
    ui->MarketValueLabel->setText("市值"+QString::number(marketValue, 'f', 2) + " 元");
    ui->MarketValueLabel->setFont(Tempfont);
    ui->WinLoseLabel->setText("当前盈亏"+QString::number(totalProfitLoss, 'f', 2) + " 元");
    ui->WinLoseLabel->setFont(Tempfont);
    double totalAsset = initialAsset + totalProfitLoss;
    ui->AllMoneyLabel->setText("总资产"+QString::number(totalAsset, 'f', 2) + " 元");
    ui->AllMoneyLabel->setFont(Tempfont);
}
