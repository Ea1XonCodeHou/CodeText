#include "BuySell.h"
#include "ui_BuySell.h"
#include "global.h"
#include <QStandardItem>
#include <QFont>
#include <QBrush>
#include <QMessageBox>
#include <QJsonArray>

BuySell::BuySell(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuySell)
{
    ui->setupUi(this);

    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_price->setReadOnly(true);
    updateTimer = new QTimer();

    setTable();
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(filltable()));
    updateTimer->start(1000);
    comboBox();
    connectSql();

    curpage = 1;

    this->setObjectName("BuySell");
    this->setStyleSheet("#QWidget{background-image: url(:/Temp/risk3.png);}");

    singleRowModel = new QStandardItemModel(1, 5, this);
    singleRowModel->setHeaderData(0, Qt::Horizontal, "股票代码");
    singleRowModel->setHeaderData(1, Qt::Horizontal, "股票名称");
    singleRowModel->setHeaderData(2, Qt::Horizontal, "股票最新价格");
    singleRowModel->setHeaderData(3, Qt::Horizontal, "涨跌幅");
    singleRowModel->setHeaderData(4, Qt::Horizontal, "涨跌额");
    ui->tableView_singleRow->setModel(singleRowModel);
    ui->tableView_singleRow->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->lineEdit_code, &QLineEdit::textChanged, this, &BuySell::on_lineEdit_code_textChanged);

    lineEdit_pageJump = ui->lineEdit_pageJump;
    pageJumpButton = ui->pageJumpButton;
    connect(pageJumpButton, &QPushButton::clicked, this, &BuySell::on_pageJumpButton_clicked);

    singleRowUpdateTimer = new QTimer(this);
    connect(singleRowUpdateTimer, SIGNAL(timeout()), this, SLOT(updateSingleRow()));
    singleRowUpdateTimer->start(3000); // 设置定时器每5秒触发一次

    QString styleSheet = R"(
        QTableView {
            border: 1px solid gray;
            border-radius: 10px;
            padding: 5px;
            background-color:rgba(255,255,255,100%);
        }
        QLineEdit {
            border: 1px solid gray;
            border-radius: 10px;
            padding: 5px;
            background-color:rgba(255,255,255,100%);
        }
        QComboBox {
            border: 1px solid gray;
            border-radius: 10px;
            padding: 5px;
        }
        QPushButton {
            border: 1px solid gray;
            border-radius: 10px;
            padding: 5px;
            background-color:rgba(255,255,255,100%);
        }
        QLabel {
            border: 1px solid gray;
            border-radius: 10px;
            padding: 5px;
            background-color:rgba(255,255,255,100%);
        }
    )";

    ui->tableView->setStyleSheet(styleSheet);
    ui->tableView_singleRow->setStyleSheet(styleSheet);
    ui->lineEdit_code->setStyleSheet(styleSheet);
    ui->lineEdit_name->setStyleSheet(styleSheet);
    ui->lineEdit_price->setStyleSheet(styleSheet);
    ui->chooseBox->setStyleSheet(styleSheet);
    ui->lineEdit->setStyleSheet(styleSheet);
    ui->confirmButton->setStyleSheet(styleSheet);
    ui->backButton->setStyleSheet(styleSheet);
    ui->forwardButton->setStyleSheet(styleSheet);
    ui->pageJumpButton->setStyleSheet(styleSheet);
    ui->lineEdit_pageJump->setStyleSheet(styleSheet);
    ui->label->setStyleSheet(styleSheet);
    ui->label_2->setStyleSheet(styleSheet);
    ui->label_3->setStyleSheet(styleSheet);
    ui->label_4->setStyleSheet(styleSheet);
    ui->NoticeLabel->setStyleSheet(styleSheet);
}

BuySell::~BuySell()
{
    delete ui;
}

bool BuySell::isStockCodeValid(const QString &stockCode)
{
    QSqlDatabase dbSim = QSqlDatabase::addDatabase("QMYSQL", "sim_trading_connection");
    dbSim.setDatabaseName("模拟交易");
    dbSim.setHostName("120.46.221.110");
    dbSim.setUserName("root");
    dbSim.setPassword("123098Qazplm");

    if (!dbSim.open()) {
        qDebug() << "连接模拟交易数据库失败：" << dbSim.lastError().text();
        return false; // 如果无法连接到数据库，返回false
    }

    QSqlQuery query(dbSim);
    query.prepare("SELECT 1 FROM 获取股票 WHERE 代码 = :stockCode");
    query.bindValue(":stockCode", stockCode);

    if (query.exec() && query.next()) {
        dbSim.close();
        return true; // 如果找到股票代码，返回true
    } else {
        dbSim.close();
        return false; // 如果未找到股票代码，返回false
    }
}


void BuySell::setTable()
{
    model = new QStandardItemModel(20, 5);
    model->setHeaderData(0, Qt::Horizontal, "股票代码");
    model->setHeaderData(1, Qt::Horizontal, "股票名称");
    model->setHeaderData(2, Qt::Horizontal, "股票最新价格");
    model->setHeaderData(3, Qt::Horizontal, "涨跌幅");
    model->setHeaderData(4, Qt::Horizontal, "涨跌额");
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFont font;
    font.setBold(true);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_4->setFont(font);
}

void BuySell::filltable()
{
    downloadFile(curpage);

    int rowCount = model->rowCount();
    int dataSize = code.size();
    //qDebug() << "dataSize:" << dataSize;

    if (dataSize != 20) {
        qDebug() << "Error: Data size is not 20!";
        return;
    }

    for (int i = 0; i < rowCount && i < dataSize; i++) {
        //qDebug() << "code[" << i << "]:" << code[i];
        model->setData(model->index(i, 0), code[i]);
        model->setData(model->index(i, 1), name[i]);
        model->setData(model->index(i, 2), cur_price[i]);

        double rise_fall = rise_fall_level[i].toDouble();
        QFont font;
        font.setBold(true);
        QBrush brush;
        if (rise_fall > 0) {
            brush = QBrush(Qt::red);
        } else if (rise_fall < 0) {
            brush = QBrush(Qt::green);
        } else {
            brush = QBrush(Qt::black);
        }
        QString rise_fall_with_percent = QString::number(rise_fall, 'f', 2) + "%";
        model->setData(model->index(i, 3), rise_fall_with_percent);
        model->setData(model->index(i, 3), font, Qt::FontRole);
        model->setData(model->index(i, 3), brush, Qt::ForegroundRole);

        double rise_fall_amount_value = rise_fall_amount[i].toDouble();
        if (rise_fall_amount_value > 0) {
            brush = QBrush(Qt::red);
        } else if (rise_fall_amount_value < 0) {
            brush = QBrush(Qt::green);
        } else {
            brush = QBrush(Qt::black);
        }
        model->setData(model->index(i, 4), rise_fall_amount[i]);
        model->setData(model->index(i, 4), font, Qt::FontRole);
        model->setData(model->index(i, 4), brush, Qt::ForegroundRole);
    }
    ui->label_pageInfo->setText(QString("Page %1 of %2").arg(curpage).arg(totalPages-1));
}

void BuySell::on_forwardButton_clicked()
{
    if (curpage < totalPages) {
        curpage++;
        downloadFile(curpage);
        filltable();
    } else {
        QMessageBox::information(this, "提示", "已经是最后一页");
    }
}

void BuySell::on_backButton_clicked()
{
    if (curpage > 1) {
        curpage--;
        downloadFile(curpage);
        filltable();
    } else {
        QMessageBox::information(this, "提示", "已经是第一页");
    }
}

void BuySell::downloadFile(int pn)
{
    QString url = "https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=%1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QString url_str = url.arg(pn);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url_str));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    auto text = reply->readAll();

    name = match(text, "f14");
    code = match(text, "f12");
    cur_price = match(text, "f2");
    rise_fall_level = match(text, "f3");
    rise_fall_amount = match(text, "f4");

    int expectedSize = 20;
    if (name.size() != expectedSize || code.size() != expectedSize || cur_price.size() != expectedSize || rise_fall_level.size() != expectedSize || rise_fall_amount.size() != expectedSize) {
        qDebug() << "Error: List sizes are not equal!";
        qDebug() << "name.size():" << name.size();
        qDebug() << "code.size():" << code.size();
        qDebug() << "cur_price.size():" << cur_price.size();
        qDebug() << "rise_fall_level.size():" << rise_fall_level.size();
        qDebug() << "rise_fall_amount.size():" << rise_fall_amount.size();
        return;
    }

    QRegularExpression re("\"total\":(\\d+)");
    QRegularExpressionMatch match = re.match(text);
    if (match.hasMatch()) {
        int totalCount = match.captured(1).toInt();
        totalPages = (totalCount + pagerowcount - 1) / pagerowcount;
    }

    reply->deleteLater();
}

QStringList BuySell::match(QString text, QString fn)
{
    QString qreg = '\"' + fn + "\":\"(.*?)\"";
    QString qregDouble = '\"' + fn + "\":(-?\\d+\\.\\d+)";
    if (fn != "f12" && fn != "f14") qreg = qregDouble;
    QRegularExpression re(qreg);
    QStringList strList;
    auto pos = re.globalMatch(text);
    while (pos.hasNext()) {
        auto match = pos.next();
        auto tmp = match.captured(1);
        strList.append(tmp);
    }
    return strList;
}

StockInfo BuySell::getStockInfo(QString stockcode)
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
        stockInfo.name = name;

        QJsonArray klines = dataObj["klines"].toArray();
        if (!klines.isEmpty()) {
            QStringList lastLine = klines.last().toString().split(",");
            if (lastLine.size() > 10) {
                stockInfo.price = lastLine[2];
                stockInfo.rise_fall_amount = lastLine[9];
                stockInfo.rise_fall_level = lastLine[8];
            }
        }
    }

    reply->deleteLater();
    return stockInfo;
}

void BuySell::on_lineEdit_code_textChanged(const QString &text)
{
    if (text.isEmpty()) {
        for (int i = 0; i < 5; ++i) {
            singleRowModel->setData(singleRowModel->index(0, i), "");
        }
        return;
    }

    StockInfo stockInfo = getStockInfo(text);
    singleRowModel->setData(singleRowModel->index(0, 0), stockInfo.code);
    singleRowModel->setData(singleRowModel->index(0, 1), stockInfo.name);
    singleRowModel->setData(singleRowModel->index(0, 2), stockInfo.price);
    singleRowModel->setData(singleRowModel->index(0, 3), stockInfo.rise_fall_level + "%");
    singleRowModel->setData(singleRowModel->index(0, 4), stockInfo.rise_fall_amount);

    QFont fontBold;
    fontBold.setBold(true);
    QBrush brushRed(Qt::red);
    QBrush brushGreen(Qt::green);

    QFont fontName("STZhongsong", 10, QFont::Bold);
    singleRowModel->setData(singleRowModel->index(0, 1), fontName, Qt::FontRole);

    double rise_fall_level = stockInfo.rise_fall_level.toDouble();
    if (rise_fall_level > 0) {
        singleRowModel->setData(singleRowModel->index(0, 3), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 3), brushRed, Qt::ForegroundRole);
    } else if (rise_fall_level < 0) {
        singleRowModel->setData(singleRowModel->index(0, 3), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 3), brushGreen, Qt::ForegroundRole);
    }

    double rise_fall_amount = stockInfo.rise_fall_amount.toDouble();
    if (rise_fall_amount > 0) {
        singleRowModel->setData(singleRowModel->index(0, 4), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 4), brushRed, Qt::ForegroundRole);
    } else if (rise_fall_amount < 0) {
        singleRowModel->setData(singleRowModel->index(0, 4), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 4), brushGreen, Qt::ForegroundRole);
    }
}

void BuySell::comboBox()
{
    QStringList itemList;
    itemList << "买入" << "卖出";
    ui->chooseBox->addItems(itemList);
}

void BuySell::connectSql()
{
    QString dbname = "USER_" + Current_User_Name;
    qDebug()<<Current_User_Name;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(dbname); // 连接到用户的独立数据库
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setPassword("123098Qazplm");
    if (db.open()) {
        qDebug() << "mysql连接成功";
    } else {
        qDebug() << "连接失败";
    }
}

void BuySell::on_confirmButton_clicked()
{
    QDateTime time_ = QDateTime::currentDateTime();
    QString stockCode = ui->lineEdit_code->text();
    double price = ui->lineEdit_price->text().toDouble();
    int num = ui->lineEdit->text().toInt();
    QString buyOrSell = ui->chooseBox->currentText();

    // 查询用户的总资产和市值
    double totalAssets, marketValue;
    QSqlQuery query(db);
    query.prepare("SELECT balance, marketvalue FROM personal_info WHERE id = :userId");
    query.bindValue(":userId", Current_User_Name); // 确保有正确的用户ID
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "查询失败", "无法获取用户资产信息。");
        return;
    }
    totalAssets = query.value("balance").toDouble();
    marketValue = query.value("marketvalue").toDouble();

    double availableFunds = totalAssets - marketValue;
    int maxAffordableShares = static_cast<int>(availableFunds / price / 100) * 100;

    if (buyOrSell == "买入") {
        if (num > maxAffordableShares) {
            QMessageBox::warning(this, "购买失败", QString("您的余额只剩 %1 元，无法买入这么多，只能买入 %2 股。").arg(QString::number(availableFunds, 'f', 2), QString::number(maxAffordableShares)));
            return;
        }
    }

    // 检查卖出数量是否超出持仓数量
    if (buyOrSell == "卖出") {
        QSqlQuery checkQuery(db);
        checkQuery.prepare("SELECT (SELECT COALESCE(SUM(quantity), 0) FROM transactions WHERE StockID = :id AND stock_symbol = :stock_symbol AND transaction_type = '买入') - (SELECT COALESCE(SUM(quantity), 0) FROM transactions WHERE StockID = :id AND stock_symbol = :stock_symbol AND transaction_type = '卖出') AS total_quantity");
        checkQuery.bindValue(":id", stockCode);
        checkQuery.bindValue(":stock_symbol", ui->lineEdit_name->text());

        if (!checkQuery.exec() || !checkQuery.next() || num > checkQuery.value("total_quantity").toInt()) {
            QMessageBox::warning(this, "卖出失败", "您的持仓数量不足以卖出这么多股票。");
            return;
        }
    }

    QString transactionTime = time_.toString(Qt::ISODateWithMs);
    query.prepare("INSERT INTO transactions (StockID, stock_symbol, price, quantity, transaction_type, transaction_time) VALUES (:StockID, :stock_symbol, :price, :quantity, :transaction_type, :transaction_time)");
    query.bindValue(":StockID", stockCode);
    query.bindValue(":stock_symbol", ui->lineEdit_name->text());
    query.bindValue(":price", price);
    query.bindValue(":quantity", num);
    query.bindValue(":transaction_type", buyOrSell);
    query.bindValue(":transaction_time", transactionTime);

    if (query.exec()) {
        QMessageBox::information(this, "交易提示", QString("操作成功！您已%s %1股。").arg(buyOrSell));
    } else {
        QMessageBox::warning(this, "交易失败", "添加交易记录失败，请检查数据！");
    }
}


void BuySell::on_lineEdit_code_editingFinished()
{
    QString stockCode = ui->lineEdit_code->text();

    if (stockCode.isEmpty()) {
        return;
    }

    if (!isStockCodeValid(stockCode)) {
        QMessageBox::warning(this, "错误", "您输入的股票代码不存在，请重新输入");
        ui->lineEdit_code->clear(); // 清空输入框
        ui->lineEdit_name->clear(); // 清空股票名称
        ui->lineEdit_price->clear(); // 清空股票价格
        return;
    }

    StockInfo info = getStockInfo(stockCode);
    ui->lineEdit_name->setText(info.name);
    ui->lineEdit_price->setText(info.price);

    // 查询总资产和市值
    double totalAssets, marketValue;
    QSqlQuery query(db);
    query.prepare("SELECT balance, marketvalue FROM personal_info WHERE id = :userId");
    query.bindValue(":userId", Current_User_Name); // 这里需要确保你有正确的用户ID
    if (query.exec() && query.next()) {
        totalAssets = query.value("balance").toDouble();
        marketValue = query.value("marketvalue").toDouble();
    } else {
        qDebug() << "查询资产和市值失败：" << query.lastError().text();
        return;
    }

    double availableFunds = totalAssets - marketValue;
    double stockPrice = info.price.toDouble();
    int maxAffordableShares = static_cast<int>(availableFunds / stockPrice / 100) * 100; // 计算可购买的最大整百股数

    ui->NoticeLabel->setText(QString("您可以购买最多 %1 股 %2").arg(maxAffordableShares).arg(info.name));
    qDebug() << "Setting text to NoticeLabel:" << QString("您可以购买最多 %1 股 %2").arg(maxAffordableShares).arg(info.name);
}

void BuySell::on_pageJumpButton_clicked()
{
    bool ok;
    int pageNumber = lineEdit_pageJump->text().toInt(&ok);
    if (!ok || pageNumber < 1 || pageNumber > totalPages) {
        QMessageBox::warning(this, "错误", "输入的页码无效，请输入正确的页码！");
        return;
    }

    curpage = pageNumber;
    downloadFile(curpage);
    filltable();
}

void BuySell::updateSingleRow()
{
    QString stockCode = ui->lineEdit_code->text();
    if (!stockCode.isEmpty()) {
        StockInfo stockInfo = getStockInfo(stockCode);
        singleRowModel->setData(singleRowModel->index(0, 0), stockInfo.code);
        singleRowModel->setData(singleRowModel->index(0, 1), stockInfo.name);
        singleRowModel->setData(singleRowModel->index(0, 2), stockInfo.price);
        singleRowModel->setData(singleRowModel->index(0, 3), stockInfo.rise_fall_level + "%");
        singleRowModel->setData(singleRowModel->index(0, 4), stockInfo.rise_fall_amount);
    }
}
