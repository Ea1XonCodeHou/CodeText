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
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QFont>
#include <QFontDatabase>
#include <cfloat>
#include <QObject>
#include<QPixmap>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{setWindowIcon(QIcon(":/new/prefix1/favicon.ico"));
    ui->setupUi(this);

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView { alternate-background-color: rgb(217, 225, 240); background: rgb(255, 255, 255); }");
    // 定义 QPixmap 对象并加载图片
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/risk3.png");
    // 将背景图片应用为窗口的背景
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    // 创建一个字体对象
    QFont font1("微软雅黑", 18);
    QFont font2("微软雅黑",10);
    // 设置字体
    ui->pushButton->setFont(font1);
    ui->label->setFont(font2);
    ui->label_2->setFont(font2);
     ui->label_3->setFont(font2);
    ui->pushButton->setStyleSheet("QPushButton {"
                                               "    background-color: #6495ED; "
                                               "    border: none;"
                                               "    color: white;"
                                               "    padding: 10px 20px;"
                                               "    text-align: center;"
                                               "    font-size: 16px;"

                                               "}"
                                               "QPushButton:pressed {"
                                               "    background-color: #4682B4; "
                                               "}");
    ui->textBrowser->setStyleSheet("QTextBrowser {"
                              "    background-color: #F0FFFF;"
                              "    border: 1px solid 	#191970;"
                              "    border-radius: 5px;"
                              "}"
                           );
    connect(ui->nextPageButton, &QPushButton::clicked, this, &Widget::nextPage);
    connect(ui->previousPageButton, &QPushButton::clicked, this, &Widget::previousPage);
    connect(ui->firstPageButton, &QPushButton::clicked, this, &Widget::firstPage);
    connect(ui->lastPageButton, &QPushButton::clicked, this, &Widget::lastPage);
}

Widget::~Widget()
{
    delete ui;
}


// void Widget::showSlot() {
//     QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//     db.setHostName("120.46.221.110");
//     db.setUserName("root");
//     db.setDatabaseName("股票模拟交易");
//     db.setPassword("123098Qazplm");
//     db.setPort(3306);
//     bool ok = db.open();

//     if (ok) {
//         QStandardItemModel *model = new QStandardItemModel(this);
//         model->setHorizontalHeaderLabels({tr("股票名称"), tr("股票代码"), tr("股数"), tr("持仓成本价"), tr("买入/卖出"), tr("现价"),tr("持仓盈亏")});
//         // 获取表格的水平表头视图
//         QHeaderView *header = ui->tableView->horizontalHeader();

//         // 创建一个Arial字体，大小为12，加粗
//         QFont font("Arial", 12);
//         font.setBold(true);

//         // 设置表头的字体为加粗字体
//         header->setFont(font);

//         // 更新表格视图的显示，确保修改生效
//         ui->tableView->setModel(model);
//     // 查询数据库并更新模型
//     QSqlQuery query("SELECT name, code, num, price, buyorsell FROM test");
//     int row = 0;
//     while (query.next()) {
//         QString name = query.value(0).toString();
//         QString code = query.value(1).toString();
//         int num = query.value(2).toInt();
//         double price = query.value(3).toDouble();
//         QString buyorsell = query.value(4).toString();

//         // 创建每个单元格的 QStandardItem
//         QStandardItem *nameItem = new QStandardItem(name);
//         QStandardItem *codeItem = new QStandardItem(code);
//         QStandardItem *numItem = new QStandardItem(QString::number(num));
//         QStandardItem *priceItem = new QStandardItem(QString::number(price));
//         QStandardItem *buyorsellItem = new QStandardItem(buyorsell);

//         // 设置前景色
//         nameItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
//         codeItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
//      priceItem->setData(QColor(Qt::darkYellow), Qt::ForegroundRole);

//         // 设置表头字体加粗
//         QFont headerFont = model->headerData(row, Qt::Horizontal, Qt::FontRole).value<QFont>();  // 获取表头的字体
//         headerFont.setBold(true);  // 设置加粗
//         model->setHeaderData(0, Qt::Horizontal, headerFont, Qt::FontRole);  // 应用修改后的字体到表头
//         // 设置模型项
//         model->setItem(row, 0, nameItem);
//         model->setItem(row, 1, codeItem);
//         model->setItem(row, 2, numItem);
//         model->setItem(row, 3, priceItem);
//         model->setItem(row, 4, buyorsellItem);

//         // 异步获取最新价格并更新模型
//         fetchDataForStockAsync(code, model, row);
//         // 获取当前股票价格
//         QModelIndex index = model->index(row, 5);  // 第六列是现价列
//         QVariant currentPriceVariant = model->data(index);
//         double currentStockPrice = currentPriceVariant.toDouble();

//         // 计算持仓盈亏
//         double currentPositionValue = num * price;
//         double positionProfitLoss = 0.0;
//         if (buyorsell == "买入") {
//             positionProfitLoss = currentPositionValue - (num * currentStockPrice);
//         } else if (buyorsell == "卖出") {
//             positionProfitLoss = (num * currentStockPrice) - currentPositionValue;
//         }
//         model->setItem(row, 6, new QStandardItem(QString::number(positionProfitLoss)));

//         ++row;
//     }

//     // 刷新表格视图
//     ui->tableView->setModel(model);
//     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//     // 实现数据改变自动刷新的功能
//     QObject::connect(model, &QAbstractItemModel::dataChanged,
//                      ui->tableView, QOverload<>::of(&QTableView::update));
//     }

//     else
//     {
//         QMessageBox::warning(this,"错误","未连接，请检查.");
//     }

// }

void Widget::showSlot() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setDatabaseName("股票模拟交易");
    db.setPassword("123098Qazplm");
    db.setPort(3306);
    bool ok = db.open();

    if (!ok) {
        qDebug() << "Failed to connect to database.";
        return;
    }

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({tr("股票名称"), tr("股票代码"), tr("股数"), tr("持仓成本价"), tr("买入/卖出"), tr("现价"), tr("持仓盈亏")});
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->tableView->setModel(model);
   //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // 设置表头字体加粗
    int columnCount = model->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        QFont headerFont = model->headerData(col, Qt::Horizontal, Qt::FontRole).value<QFont>();
        headerFont.setBold(true);
        model->setHeaderData(col, Qt::Horizontal, headerFont, Qt::FontRole);
    }
    // 设置表格视图的编辑触发器为不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 连接信号槽，当数据模型的数据发生改变时，更新表格视图
    // QObject::connect(model, &QAbstractItemModel::dataChanged,
    //                  ui->tableView, &QTableView::update);
    // 初始化翻页相关变量
    currentPage = 1;
    rowsPerPage = 7;  // 每页显示7条数据

    QSqlQuery countQuery("SELECT COUNT(*) FROM test");

    // 执行查询
    if (countQuery.exec() && countQuery.next()) {
        // 获取结果集中的第一列值，即 COUNT(*) 的结果
        totalRows = countQuery.value(0).toInt();

        // 计算总页数
        totalPages = (totalRows + rowsPerPage - 1) / rowsPerPage;
    } else {
        // 查询失败或没有结果
        totalRows = 0;
        totalPages = 0;
    }

    // 更新表格视图显示
    updateTableView();
}

void Widget::nextPage() {
    if (currentPage < totalPages) {
        currentPage++;
        updateTableView();
    }
}

void Widget::previousPage() {
    if (currentPage > 1) {
        currentPage--;
        updateTableView();
    }
}

void Widget::firstPage() {
    currentPage = 1;
    updateTableView();
}

void Widget::lastPage() {
    currentPage = totalPages;
    updateTableView();
}

void Widget::updateTableView() {
    // 计算当前页的偏移量
    int offset = (currentPage - 1) * rowsPerPage;

    // 清空模型中的所有数据
    model->removeRows(0, model->rowCount());

    // 构建查询字符串，限制结果集的行数和偏移量
    QString queryStr = QString("SELECT name, code, num, price, buyorsell FROM test LIMIT %1, %2")
                           .arg(offset).arg(rowsPerPage);

    // 执行查询
    QSqlQuery query(queryStr);

    // 遍历查询结果并更新模型
    int row = 0;
    while (query.next()) {
        // 从查询结果获取数据
        QString name = query.value(0).toString();
        QString code = query.value(1).toString();
        int num = query.value(2).toInt();
        double price = query.value(3).toDouble();
        QString buyorsell = query.value(4).toString();

        // 创建每个单元格的 QStandardItem
        QStandardItem *nameItem = new QStandardItem(name);
        QStandardItem *codeItem = new QStandardItem(code);
        QStandardItem *numItem = new QStandardItem(QString::number(num));
        QStandardItem *priceItem = new QStandardItem(QString::number(price));
        QStandardItem *buyorsellItem = new QStandardItem(buyorsell);

        // 设置前景色
        nameItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
        codeItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
        priceItem->setData(QColor(Qt::darkYellow), Qt::ForegroundRole);

        // 设置模型项
        model->setItem(row, 0, nameItem);
        model->setItem(row, 1, codeItem);
        model->setItem(row, 2, numItem);
        model->setItem(row, 3, priceItem);
        model->setItem(row, 4, buyorsellItem);

        // 异步获取最新价格并更新模型
        fetchDataForStockAsync(code, model, row);

        ++row;
    }
}
void Widget::updateTableViewWithoutOffset() {
    // 清空模型中的所有数据
    model->removeRows(0, model->rowCount());

    // 构建查询字符串，限制结果集的行数和偏移量
    QString queryStr = QString("SELECT name, code, num, price, buyorsell FROM test");


    // 执行查询
    QSqlQuery query(queryStr);

    // 遍历查询结果并更新模型
    int row = 0;
    while (query.next()) {
        // 从查询结果获取数据
        QString name = query.value(0).toString();
        QString code = query.value(1).toString();
        int num = query.value(2).toInt();
        double price = query.value(3).toDouble();
        QString buyorsell = query.value(4).toString();

        // 创建每个单元格的 QStandardItem
        QStandardItem *nameItem = new QStandardItem(name);
        QStandardItem *codeItem = new QStandardItem(code);
        QStandardItem *numItem = new QStandardItem(QString::number(num));
        QStandardItem *priceItem = new QStandardItem(QString::number(price));
        QStandardItem *buyorsellItem = new QStandardItem(buyorsell);

        // 设置前景色
        nameItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
        codeItem->setData(QColor(Qt::darkBlue), Qt::ForegroundRole);
        priceItem->setData(QColor(Qt::darkYellow), Qt::ForegroundRole);

        // 设置模型项
        model->setItem(row, 0, nameItem);
        model->setItem(row, 1, codeItem);
        model->setItem(row, 2, numItem);
        model->setItem(row, 3, priceItem);
        model->setItem(row, 4, buyorsellItem);

        // 异步获取最新价格并更新模型
        fetchDataForStockAsync(code, model, row);

        ++row;
    }

}

void Widget::fetchDataForCurrentPage() {
    int startIndex = (currentPage - 1) * rowsPerPage;
    int endIndex = qMin(startIndex + rowsPerPage - 1, totalRows - 1);

    for (int i = startIndex; i <= endIndex; ++i) {
        QModelIndex index = model->index(i, 5);  // 第六列是现价列
        QVariant currentPriceVariant = model->data(index);
        double currentStockPrice = currentPriceVariant.toDouble();

        // 获取持仓成本价和买入/卖出信息
        QModelIndex priceIndex = model->index(i, 3);  // 持仓成本价列
        QModelIndex buySellIndex = model->index(i, 4);  // 买入/卖出列

        double price = model->data(priceIndex).toDouble();
        QString buyorsell = model->data(buySellIndex).toString();

        // 计算持仓盈亏
        int num = model->data(model->index(i, 2)).toInt();  // 股数列
        double currentPositionValue = num * price;
        double positionProfitLoss = 0.0;
        if (buyorsell == "买入") {
            positionProfitLoss = currentPositionValue - (num * currentStockPrice);
        } else if (buyorsell == "卖出") {
            positionProfitLoss = (num * currentStockPrice) - currentPositionValue;
        }
        model->setItem(i, 6, new QStandardItem(QString::number(positionProfitLoss)));
    }
}



//
void Widget::calculateBuySellRatio()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    int rowCount =model->rowCount();
    int buyCount = 0;
    int sellCount = 0;
    double totalInvestment = 0.0;
    double totalReturns = 0.0;
    int totalSharesTraded = 0;
    int maxShares = INT_MIN;
    int minShares = INT_MAX;


    for (int i = 0; i < rowCount; ++i) {
        QModelIndex buySellIndex = model->index(i, 4);
        QString buySell = model->data(buySellIndex).toString();

        QModelIndex numIndex = model->index(i, 2);
        int num = model->data(numIndex).toInt();

        QModelIndex priceIndex = model->index(i, 3);
        double price = model->data(priceIndex).toDouble();

        if (buySell == "买入") {
            buyCount++;
            totalInvestment += num * price;
        } else if (buySell == "卖出") {
            sellCount++;
            totalReturns += num * price;
        }

        totalSharesTraded += num;
        if (num > maxShares) {
            maxShares = num;
        }
        if (num < minShares) {
            minShares = num;
        }
    }

    double totalTransactions = buyCount + sellCount;
    double buyRatio = totalTransactions > 0 ? (static_cast<double>(buyCount) / totalTransactions) * 100.0 : 0.0;
    double sellRatio = totalTransactions > 0 ? (static_cast<double>(sellCount) / totalTransactions) * 100.0 : 0.0;
    double totalProfitLossRatio = totalInvestment != 0.0 ? ((totalReturns - totalInvestment) / totalInvestment) * 100.0 : 0.0;
    double averageSharesTraded = rowCount > 0 ? static_cast<double>(totalSharesTraded) / rowCount : 0.0;

    QString resultText = QString::asprintf("买入交易次数: %d\n卖出交易次数: %d\n"
                                           "总投入: %.2f\n总回报: %.2f\n"
                                           "买入交易比例: %.2f%%\n卖出交易比例: %.2f%%\n"
                                           "总体盈亏比例: %.2f%%\n"
                                           "平均每次交易股票数量: %.2f\n"
                                           "最大交易股票数量: %d\n最小交易股票数量: %d\n",
                                           buyCount,
                                           sellCount,
                                           totalInvestment,
                                           totalReturns,
                                           buyRatio,
                                           sellRatio,
                                           totalProfitLossRatio,
                                           averageSharesTraded,
                                           maxShares,
                                           minShares);

    // 格式化输出结果
    QFont font("宋体", 22);
    QFont font2("宋体", 13);
    font2.setBold(true);
    font2.setItalic(true);

    // 创建 QTextDocument
    QTextDocument *document = new QTextDocument();

    // 创建 QTextCursor
    QTextCursor cursor(document);

    // 设置字体和颜色
    QTextCharFormat format;
    format.setFont(font2);
    format.setForeground(Qt::darkBlue);  // 设置字体颜色为红色，可以根据需要更改颜色

    // 插入文本到 QTextDocument
    cursor.insertText("根据您的交易历史数据分析：\n", format);  // 应用设置的格式
    cursor.insertText(resultText);  // 默认使用 QTextBrowser 的字体和格式

    // 将 QTextDocument 设置到 QTextBrowser
    ui->textBrowser->setDocument(document);
    double maxLoss = 0.0;
    int maxLossRow = -1;
    // 遍历每一行数据
    for (int row = 0; row < model->rowCount(); ++row) {
        int numShares = model->item(row, 2)->text().toInt();
        double purchasePrice = model->item(row, 3)->text().toDouble();
        double currentPrice = model->item(row, 5)->text().toDouble();
        QString buySell = model->item(row, 4)->text();

        // 计算亏损（根据买入/卖出的不同应用不同的逻辑）
        double profitLoss;
        if (buySell == "买入") {
            profitLoss = (currentPrice - purchasePrice) * numShares;
        } else if (buySell == "卖出") {
            profitLoss = (purchasePrice - currentPrice) * numShares;
        } else {
            // 如果买入/卖出字段不是预期的值（买入或卖出），这里可以考虑如何处理，例如跳过或记录错误。
            continue;
        }

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

        ui->label->setText(outputText);
    } else {
        ui->label->setText("未找到任何造成亏损的交易数据。");
    }


    // 计算投资建议 风险评估
    QString investmentAdvice;
    QString riskAssessment;


    if (totalProfitLossRatio < 0.0 && buyRatio > 50.0) {
        investmentAdvice = "建议审查您的投资组合并降低风险敞口。";
        riskAssessment="高风险";
    } else if (totalProfitLossRatio < 30.0 && buyRatio < 30.0) {
        riskAssessment="低风险";
        investmentAdvice = "可以考虑增加投资敞口以提升收益。";
    } else {riskAssessment="中风险";
        investmentAdvice = "建议保持投资组合的平衡。";
    }


    // 设置字体和文本
    ui->label_2->setFont(font);
    ui->label_2->setText(riskAssessment);
// ui->label_3->setFont(font);
    ui->label_3->setText(investmentAdvice);
    ui->textBrowser->setReadOnly(true);

}



void Widget::fetchDataForStockAsync(const QString &stockCode, QStandardItemModel *model, int row) {
    QString url = QString("https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=jQuery3510239574743616513_1720409636981&secid=1.%1"
                          "&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1%2Cf2%2Cf3%2Cf4%2Cf5%2Cf6&fields2=f51%2Cf52%2Cf53%2Cf54%2Cf55%2Cf56%2Cf57%2Cf58%2Cf59%2Cf60%2Cf61"
                          "&klt=101&fqt=1&end=20500101&lmt=120&_=1720409637009").arg(stockCode);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);

    // 发送GET请求
    QNetworkReply *reply = manager->get(request);

    // 处理请求完成
    QObject::connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error:" << reply->errorString();
        } else {
            // 读取返回的数据
            QByteArray responseData = reply->readAll();
            // 去掉返回数据中的前缀
            QString response = QString::fromUtf8(responseData).remove("jQuery3510239574743616513_1720409636981(").remove(");");
            // 解析JSON数据
            QJsonDocument jsonDoc = QJsonDocument::fromJson(response.toUtf8());
            if (!jsonDoc.isNull()) {
                QJsonObject jsonObj = jsonDoc.object();
                if (jsonObj.contains("data")) {
                    QJsonObject dataObj = jsonObj["data"].toObject();
                    if (dataObj.contains("klines")) {
                        QJsonArray klinesArray = dataObj["klines"].toArray();
                        if (!klinesArray.isEmpty()) {
                            // 取最后一行数据
                            QString lastKline = klinesArray.last().toString();
                            // 分割数据以逗号分隔
                            QStringList klineParts = lastKline.split(',');
                            // 获取第二个数据（索引为2，从0开始）
                            if (klineParts.size() > 2) {
                                QString thirdData = klineParts[2];
                                double currentStockPrice =thirdData.toDouble();
                                // 更新模型
                                QStandardItem *item = new QStandardItem(thirdData);
                                 model->setItem(row, 5, item);
                                // 计算持仓盈亏
                                QModelIndex index = model->index(row, 2);
                                int num = model->data(index).toInt();
                                index = model->index(row, 3);
                                double purchaseprice = model->data(index).toDouble();
                                index = model->index(row, 4);
                                QString buyorsell = model->data(index).toString();
                                double profitLoss=0.0;
                                if (buyorsell == "买入") {
                                    profitLoss = (currentStockPrice - purchaseprice) * num;
                                } else if (buyorsell == "卖出") {
                                    profitLoss = (purchaseprice - currentStockPrice) * num;
                                }

                                QString profitLossString = QString::number(profitLoss);
                                QStandardItem *profitLossItem = new QStandardItem(profitLossString);

                                if (profitLoss > 0) {
                                    profitLossItem->setData(QColor(Qt::darkGreen), Qt::ForegroundRole); // 盈利，设置为深绿色
                                    item->setData(QColor(Qt::darkGreen),Qt::ForegroundRole);
                                } else if (profitLoss < 0) {
                                    profitLossItem->setData(QColor(Qt::darkRed), Qt::ForegroundRole);
                                    item->setData(QColor(Qt::darkRed),Qt::ForegroundRole);    // 亏损，设置为深红色
                                }
                                model->setItem(row, 6, profitLossItem);
                            }
                        }
                    }
                }
            }
        }
        // 释放资源
        reply->deleteLater();
        manager->deleteLater();
    });
}



void Widget::on_pushButton_clicked()
{
    calculateBuySellRatio();
}
