#include "risktest.h"
#include "ui_risktest.h"

risktest::risktest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::risktest)

{
    setWindowIcon(QIcon(":/new/prefix1/resource/favicon.ico"));
    ui->setupUi(this);
    this->showSlot();
    connect(ui->nextPageButton, &QPushButton::clicked, this, &risktest::nextPage);
    connect(ui->previousPageButton, &QPushButton::clicked, this, &risktest::previousPage);
    connect(ui->firstPageButton, &QPushButton::clicked, this, &risktest::firstPage);
    connect(ui->lastPageButton, &QPushButton::clicked, this, &risktest::lastPage);
    connect(ui->pushButton,&QPushButton::clicked,this,&risktest::calculateBuySellRatio);
}
risktest::~risktest()
{
     delete ui;
}

void risktest::showSlot() {

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setDatabaseName("USER_ABC");
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
    int columnCount = model->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        QFont headerFont = model->headerData(col, Qt::Horizontal, Qt::FontRole).value<QFont>();
        headerFont.setBold(true);
        model->setHeaderData(col, Qt::Horizontal, headerFont, Qt::FontRole);
    }

    // 获取表头视图
    QHeaderView *header_view = ui->tableView->horizontalHeader();

    // 设置表格视图的编辑触发器为不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 连接信号槽，当数据模型的数据发生改变时，更新表格视图
    // QObject::connect(model, &QAbstractItemModel::dataChanged,
    //                  ui->tableView, &QTableView::update);
    // 初始化翻页相关变量
    currentPage = 1;
    rowsPerPage = 7;  // 每页显示7条数据

    QSqlQuery countQuery("SELECT COUNT(*) FROM transactions");

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

void risktest::nextPage() {
    if (currentPage < totalPages) {
        currentPage++;
        updateTableView();
    }
}

void risktest::previousPage() {
    if (currentPage > 1) {
        currentPage--;
        updateTableView();
    }
}

void risktest::firstPage() {
    currentPage = 1;
    updateTableView();
}

void risktest::lastPage() {
    currentPage = totalPages;
    updateTableView();
}

void risktest::updateTableView() {
    // 计算当前页的偏移量
    int offset = (currentPage - 1) * rowsPerPage;

    // 清空模型中的所有数据
    model->removeRows(0, model->rowCount());

    // 构建查询字符串，限制结果集的行数和偏移量
    QString queryStr = QString("SELECT stock_symbol, StockID, quantity, price, transaction_type FROM transactions LIMIT %1, %2")
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
void risktest::updateTableViewWithoutOffset() {
    // 清空模型中的所有数据
    model->removeRows(0, model->rowCount());

    // 构建查询字符串，限制结果集的行数和偏移量
    QString queryStr = QString("SELECT stock_symbol, StockID, quantity, price, transaction_type FROM transactions");


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

void risktest::fetchDataForCurrentPage() {
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

void risktest::calculateBuySellRatio()
{
    int minLossRow = -1;
    //QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    QStandardItemModel *model2 = new QStandardItemModel(0, 6);
    bool ok =db.open();
    if (!ok) {
        qDebug() << "Database connection failed.";
        delete model2;
        return;
    }
    QSqlQuery query("SELECT stock_symbol, StockID, quantity, price, transaction_type FROM transactions");
    int row = 0;
    while (query.next()) {
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

        // 设置模型项
        model2->setItem(row, 0, nameItem);
        model2->setItem(row, 1, codeItem);
        model2->setItem(row, 2, numItem);
        model2->setItem(row, 3, priceItem);
        model2->setItem(row, 4, buyorsellItem);

        // 异步获取最新价格并更新模型
        fetchDataForStockAsync(code, model2, row);

        ++row;
    }

    int rowCount = model2->rowCount();
    qDebug() << QString::number(rowCount);

    int buyCount = 0;
    int sellCount = 0;
    double totalInvestment = 0.0;
    double totalReturns = 0.0;
    int totalSharesTraded = 0;
    int maxShares = INT_MIN;
    int minShares = INT_MAX;

    for (int i = 0; i < rowCount; ++i) {
        QModelIndex buySellIndex = model2->index(i, 4);
        QString buySell = model2->data(buySellIndex).toString();

        QModelIndex numIndex = model2->index(i, 2);
        int num = model2->data(numIndex).toInt();

        QModelIndex priceIndex = model2->index(i, 3);
        double price = model2->data(priceIndex).toDouble();

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
            minLossRow=i;
        }
        if (num < minShares) {
            minShares = num;
        }

    }
   // qDebug() << QString::number(minLossRow);

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
    QFont font("华文隶书", 24);
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
    format.setForeground(Qt::darkBlue);  // 设置字体颜色

    // 插入文本到 QTextDocument
    cursor.insertText("根据您的交易历史数据分析：\n", format);  // 应用设置的格式
    cursor.insertText(resultText);  // 默认使用 QTextBrowser 的字体和格式

    // 将 QTextDocument 设置到 QTextBrowser
    ui->textBrowser->setDocument(document);

    // 如果找到最小损失值的行数不为 -1，则输出相关信息
    if (minLossRow != -1) {
        QModelIndex stockNameIndex = model2->index(minLossRow, 0);
        QModelIndex stockCodeIndex = model2->index(minLossRow, 1);
        QModelIndex purchasePriceIndex = model2->index(minLossRow, 3);
        QModelIndex buySellIndex = model2->index(minLossRow, 4);

        QString stockName = stockNameIndex.data(Qt::DisplayRole).toString();
        QString stockCode = stockCodeIndex.data(Qt::DisplayRole).toString();
        double purchasePrice = purchasePriceIndex.data(Qt::DisplayRole).toDouble();
        QString buySell = buySellIndex.data(Qt::DisplayRole).toString();

        QString outputText = "风险关联交易：\n";
        outputText += "股票名称：" + stockName + "\n";
        outputText += "股票代码：" + stockCode + "\n";
        outputText += "买入/卖出：" + buySell + "\n";
        outputText += "购买价格：" + QString::number(purchasePrice) + "\n";

        ui->label->setText(outputText);
    } else {
        ui->label->setText("未找到风险关联交易数据。");
    }

    QString investmentAdvice;
    QString riskAssessment;

    if (totalProfitLossRatio < 0.0 && buyRatio > 50.0) {
        investmentAdvice = "建议审查您的投资组合并降低风险敞口。";
        riskAssessment="高风险!";
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
    ui->label_3->setFont(font2);
    ui->textBrowser->setReadOnly(true);
    query.finish();
}



void risktest::fetchDataForStockAsync(const QString &stockCode, QStandardItemModel *model, int row) {
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
                                //qDebug() << "Third data:" << thirdData;
                                double currentStockPrice =thirdData.toDouble();
                                //qDebug() << "Current stock price:" << currentStockPrice;

                                    // 更新第五列的数据（第5列）
                                    QModelIndex currentPriceIndex = model->index(row, 5);
                                    model->setData(currentPriceIndex, QVariant(currentStockPrice));

                                    // 计算持仓盈亏
                                    QModelIndex index = model->index(row, 2);
                                    int num = model->data(index).toInt();
                                    index = model->index(row, 3);
                                    double purchaseprice = model->data(index).toDouble();
                                    index = model->index(row, 4);
                                    QString buyorsell = model->data(index).toString();
                                    double profitLoss = 0.0;

                                    // 计算盈亏并根据正负设置单元格内容和颜色
                                    if (buyorsell == "买入") {
                                        profitLoss = (currentStockPrice - purchaseprice) * num;
                                    } else if (buyorsell == "卖出") {
                                        profitLoss = (purchaseprice - currentStockPrice) * num;
                                    }

                                    // 将盈亏数值转换为字符串，这里假设 profitLossString 是一个 QString 类型的变量
                                    QString profitLossString = QString::number(profitLoss, 'f', 2); // 保留两位小数

                                    // 获取要更新的单元格索引
                                    QModelIndex profitLossIndex = model->index(row, 6);

                                    // 设置单元格的文本内容
                                    model->setData(profitLossIndex, QVariant(profitLossString), Qt::DisplayRole);

                                    // 根据盈亏情况设置前景色
                                    if (profitLoss > 0) {
                                        model->setData(profitLossIndex, QColor(Qt::darkGreen), Qt::ForegroundRole); // 设置前景色为深绿色
                                    } else if (profitLoss < 0) {
                                        model->setData(profitLossIndex, QColor(Qt::darkRed), Qt::ForegroundRole); // 设置前景色为深红色
                                    }
                                    // 更新第五列的颜色
                                    model->setData(currentPriceIndex, (profitLoss > 0 ? QColor(Qt::darkGreen) : QColor(Qt::darkRed)), Qt::ForegroundRole);

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

void risktest::on_pushButton_clicked()
{
    calculateBuySellRatio();
}
