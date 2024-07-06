#include "widget.h"
#include "ui_widget.h"
#include "CustomDelegate.h"
#include<QSqlDatabase>
#include <QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QSqlQueryModel>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include<QString>
#include<QStringList>
#include<QColor>
#include <QTextBrowser>
#include <QTableView>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QRegularExpression>
#include <QMap>
#include <QFont>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


 if (QSqlDatabase::contains("qt_sql_default_connection")) {
     QSqlDatabase::removeDatabase("qt_sql_default_connection");
 }

}

Widget::~Widget()
{
    delete ui;
}


void Widget::showSlot() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setDatabaseName("股票模拟交易");
    db.setPassword("123098Qazplm");
    db.setPort(3306);
    bool ok = db.open();

    if (ok) {
        QStandardItemModel *model = new QStandardItemModel(this);
        model->setHorizontalHeaderLabels({tr("股票名称"), tr("股票代码"), tr("股数"), tr("股价"), tr("买入/卖出"), tr("现价")});

        // 定义 QTimer 对象，每隔 10 秒触发一次获取最新价数据并更新模型
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            QMap<QString, QString> latestPrices = download_file("your_filename_here");

            // 清空现有模型数据
            model->removeRows(0, model->rowCount());

            // 重新查询数据库并更新模型
            QSqlQuery query("SELECT name, code, num, price, buyorsell FROM test");
            int row = 0;
            while (query.next()) {
                QString name = query.value(0).toString();
                QString code = query.value(1).toString();
                int num = query.value(2).toInt();
                double price = query.value(3).toDouble();
                QString buyorsell = query.value(4).toString();

                // 设置模型项
                model->setItem(row, 0, new QStandardItem(name));
                model->setItem(row, 1, new QStandardItem(code));
                model->setItem(row, 2, new QStandardItem(QString::number(num)));
                model->setItem(row, 3, new QStandardItem(QString::number(price)));
                model->setItem(row, 4, new QStandardItem(buyorsell));

                // 更新现价
                if (latestPrices.contains(code)) {
                    QString latestPrice = latestPrices.value(code);
                    model->setItem(row, 5, new QStandardItem(latestPrice));
                } else {
                    qDebug() << "Could not find latest price for code:" << code;
                    model->setItem(row, 5, new QStandardItem("100")); // 设置默认值或其他处理
                }

                ++row;
            }

            // 刷新表格视图
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        });

        // 第一次立即触发更新
        timer->start();
    }

    else
    {
        QMessageBox::warning(this,"错误","未连接，请检查.");
    }

}
void Widget::calculateBuySellRatio()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    if (!model) {
        QMessageBox::warning(this, "错误", "数据模型未设置或无效.");
        return;
    }

    int rowCount = model->rowCount();
    if (rowCount == 0) {
        QMessageBox::information(this, "提示", "没有数据可供分析.");
        return;
    }

    int buyCount = 0;
    int sellCount = 0;
    double totalInvestment = 0.0;
    double totalReturns = 0.0;
    int totalSharesTraded = 0;
    int maxShares = INT_MIN;
    int minShares = INT_MAX;

    // 遍历数据模型中的每一行，统计买入和卖出的次数，同时计算总投入、总回报和股票数量统计
    for (int i = 0; i < rowCount; ++i) {
        QModelIndex buySellIndex = model->index(i, 4); // 第5列是买入/卖出列
        QString buySell = model->data(buySellIndex).toString();

        QModelIndex numIndex = model->index(i, 2); // 第3列是股数列
        int num = model->data(numIndex).toInt();

        QModelIndex priceIndex = model->index(i, 3); // 第4列是股价列
        double price = model->data(priceIndex).toDouble();

        // 统计总投入和总回报
        if (buySell == "买入") {
            buyCount++;
            totalInvestment += num * price;
        } else if (buySell == "卖出") {
            sellCount++;
            totalReturns += num * price;
        }

        // 统计总股票数量
        totalSharesTraded += num;

        // 计算最大和最小交易量
        if (num > maxShares) {
            maxShares = num;
        }
        if (num < minShares) {
            minShares = num;
        }
    }

    // 计算平均每次交易的股票数量
    double averageSharesTraded = 0.0;
    if (buyCount + sellCount > 0) {
        averageSharesTraded = static_cast<double>(totalSharesTraded) / (buyCount + sellCount);
    }

    // 计算总体盈亏比例
    double totalProfitLossRatio = 0.0;
    if (totalInvestment > 0.0) {
        totalProfitLossRatio = ((totalReturns - totalInvestment) / totalInvestment) * 100.0;
    }

    // 在文本浏览器中显示结果
    QString resultText = QString("买入交易次数: %1\n卖出交易次数: %2\n"
                                 "总投入: %3\n总回报: %4\n"
                                 "买入交易比例: %5%\n卖出交易比例: %6%\n"
                                 "总体盈亏比例: %7%\n"
                                 "平均每次交易股票数量: %8\n"
                                 "最大交易股票数量: %9\n最小交易股票数量: %10\n")
                             .arg(buyCount)
                             .arg(sellCount)
                             .arg(QString::number(totalInvestment, 'f', 2))
                             .arg(QString::number(totalReturns, 'f', 2))
                             .arg(QString::number((double)buyCount / (buyCount + sellCount) * 100.0, 'f', 2))
                             .arg(QString::number((double)sellCount / (buyCount + sellCount) * 100.0, 'f', 2))
                             .arg(QString::number(totalProfitLossRatio, 'f', 2))
                             .arg(QString::number(averageSharesTraded, 'f', 2))
                             .arg(maxShares)
                             .arg(minShares);

    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("根据您的交易历史数据分析：\n");
    ui->textBrowser->insertPlainText(resultText);
    analyzeLoss(model,ui->label);
    ui->textBrowser->setReadOnly(true);
    setRiskAssessment(model, ui->label_2);
}

QMap<QString, QString> Widget::download_file(QString fn)
{ Q_UNUSED(fn); // 使用 Q_UNUSED 宏来消除警告
    // Replace with your actual URL
    QString url_str = "https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=";

    // Setup network manager and perform synchronous request
    QNetworkAccessManager manager;
    QNetworkRequest request(url_str + QString::number(QDateTime::currentMSecsSinceEpoch()));
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Read and process reply
    QString text = reply->readAll();
    delete reply;

    // Regular expressions to extract code and price
    QRegularExpression reCode("\"f12\":\"(\\d+)\"");
    QRegularExpression rePrice("\"f2\":(\\d+\\.\\d+)");

    QMap<QString, QString> result;

    // Extract codes
    QStringList codes;
    auto posCode = reCode.globalMatch(text);
    while (posCode.hasNext())
    {
        auto match = posCode.next();
        QString code = match.captured(1);
        codes.append(code);
    }

    // Extract prices
    QStringList prices;
    auto posPrice = rePrice.globalMatch(text);
    while (posPrice.hasNext())
    {
        auto match = posPrice.next();
        QString price = match.captured(1);
        prices.append(price);
    }

    // Combine codes and prices into key-value pairs
    for (int i = 0; i < qMin(codes.size(), prices.size()); ++i)
    {
        result.insert(codes.at(i), prices.at(i));
    }

    return result;
}

void Widget::on_pushButton_clicked()
{
    calculateBuySellRatio();

}

void Widget::analyzeLoss(QStandardItemModel *model, QLabel *outputLabel) {
    double maxLoss = 0.0;
    int maxLossRow = -1;

    // 遍历每一行数据
    for (int row = 0; row < model->rowCount(); ++row) {
        int numShares = model->item(row, 2)->text().toInt();
        double purchasePrice = model->item(row, 3)->text().toDouble();
        double currentPrice = model->item(row, 5)->text().toDouble();

        // 计算亏损（假设这里是简单的买入后的价差）
        double profitLoss = (currentPrice - purchasePrice) * numShares;

        // 比较找出最大亏损的交易
        if (profitLoss < maxLoss) {
            maxLoss = profitLoss;
            maxLossRow = row;
        }
    }

    // 输出造成最大亏损的交易数据到 QLabel
    if (maxLossRow != -1) {
        QString stockName = model->item(maxLossRow, 0)->text();
        QString stockCode = model->item(maxLossRow, 1)->text();
        double purchasePrice = model->item(maxLossRow, 3)->text().toDouble();
        QString buySell = model->item(maxLossRow, 4)->text();
        double currentPrice = model->item(maxLossRow, 5)->text().toDouble();

        QString outputText = "风险关联交易：\n";
        outputText += "股票名称：" + stockName + "\n";
        outputText += "股票代码：" + stockCode + "\n";
        outputText += "买入/卖出：" + buySell + "\n";
        outputText += "购买价格：" + QString::number(purchasePrice) + "\n";
        outputText += "当前价格：" + QString::number(currentPrice) + "\n";
        outputText += "盈亏：" + QString::number(maxLoss);

        outputLabel->setText(outputText);
    } else {
        outputLabel->setText("未找到任何造成亏损的交易数据。");

    }
}
void Widget::setRiskAssessment(QStandardItemModel *model, QLabel *outputLabel)  {
    int buyCount = 0, sellCount = 0;
    double totalInvestment = 0.0, totalReturn = 0.0;
    double buyPercentage = 0.0 ,sellPercentage = 0.0, overallProfitLossPercentage = 0.0;

    // 计算交易数据指标
    for (int row = 0; row < model->rowCount(); ++row) {
        QString transactionType = model->index(row, 0).data().toString();
        double amount = model->index(row, 1).data().toDouble();

        if (transactionType == "Buy") {
            buyCount++;
            totalInvestment += amount;
        } else if (transactionType == "Sell") {
            sellCount++;
            totalReturn += amount;
        }
    }

    // 计算买入、卖出交易比例
    int totalTransactions = buyCount + sellCount;
    if (totalTransactions > 0) {
        buyPercentage = (buyCount * 100.0) / totalTransactions;
        sellPercentage = (sellCount * 100.0) / totalTransactions;
    }

    // 计算总体盈亏比例
    if (totalInvestment > 0) {
        overallProfitLossPercentage = ((totalReturn - totalInvestment) / totalInvestment) * 100.0;
    }

    QString riskAssessment;
    if (overallProfitLossPercentage > 10.0 && buyPercentage > 50.0) {
        riskAssessment = "高风险";
    } else if (overallProfitLossPercentage < 0.0 && buyPercentage < 30.0) {
        riskAssessment = "低风险";
    } else {
        riskAssessment = "中风险";
    }

    QFont font("Arial", 20);
    outputLabel->setFont(font);
    // 返回风险评估结果
    outputLabel->setText("评估结果: " + riskAssessment);

}
