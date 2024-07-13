#include "widget.h"
#include "ui_widget.h"
#include <QStandardItem>
#include <QFont>
#include <QBrush>
#include <QMessageBox>
#include <QJsonArray>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_price->setReadOnly(true);
    updateTimer = new QTimer();

    setTable();
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(filltable()));
    updateTimer->start(1000);
    comboBox();
    connectSql();

    //ui->label_pageInfo = new QLabel(this);
    //ui->label_pageInfo->setGeometry(100, 1000, 100, 30); // 调整位置和大小
    curpage = 1;
    //getcodeprice("688163");

    this->setObjectName("widget");
    this->setStyleSheet("#QWidget{background-image: url(:/Temp/risk3.png);}");

    // 初始化单行表格
    singleRowModel = new QStandardItemModel(1, 5, this);
    singleRowModel->setHeaderData(0, Qt::Horizontal, "股票代码");
    singleRowModel->setHeaderData(1, Qt::Horizontal, "股票名称");
    singleRowModel->setHeaderData(2, Qt::Horizontal, "股票最新价格");
    singleRowModel->setHeaderData(3, Qt::Horizontal, "涨跌幅");
    singleRowModel->setHeaderData(4, Qt::Horizontal, "涨跌额");
    ui->tableView_singleRow->setModel(singleRowModel);
    ui->tableView_singleRow->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 连接搜索框的信号槽
    connect(ui->lineEdit_code, &QLineEdit::textChanged, this, &Widget::on_lineEdit_code_textChanged);

    // 设置页码跳转输入框和按钮
    lineEdit_pageJump = ui->lineEdit_pageJump;
    pageJumpButton = ui->pageJumpButton;
    connect(pageJumpButton, &QPushButton::clicked, this, &Widget::on_pageJumpButton_clicked);

    // 设置样式表

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
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setTable()
{
    // 创建数据模型
    model = new QStandardItemModel(20, 5);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "股票代码");
    model->setHeaderData(1, Qt::Horizontal, "股票名称");
    model->setHeaderData(2, Qt::Horizontal, "股票最新价格");
    model->setHeaderData(3, Qt::Horizontal, "涨跌幅");
    model->setHeaderData(4, Qt::Horizontal, "涨跌额");

    // 将数据模型绑定到表格中
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 字体加粗
    QFont font;
    font.setBold(true);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_4->setFont(font);
}

void Widget::filltable()
{
    downloadFile(curpage);

    int rowCount = model->rowCount();
    int dataSize = code.size(); // 假设所有列表的大小都相同
    qDebug() << "dataSize:" << dataSize;

    if (dataSize != 20) {
        qDebug() << "Error: Data size is not 20!";
        return;
    }

    for (int i = 0; i < rowCount && i < dataSize; i++) {
        qDebug() << "code[" << i << "]:" << code[i];
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
    // 更新页数信息
    ui->label_pageInfo->setText(QString("Page %1 of %2").arg(curpage).arg(totalPages-1));

}



void Widget::on_forwardButton_clicked()
{
    if (curpage < totalPages) {
        curpage++;
        downloadFile(curpage);
        filltable();
    } else {
        QMessageBox::information(this, "提示", "已经是最后一页");
    }
}

void Widget::on_backButton_clicked()
{
    if (curpage > 1) {
        curpage--;
        downloadFile(curpage);
        filltable();
    } else {
        QMessageBox::information(this, "提示", "已经是第一页");
    }
}

void Widget::downloadFile(int pn)
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

    // 确保所有列表大小一致
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

    // 获取总页数
    QRegularExpression re("\"total\":(\\d+)");
    QRegularExpressionMatch match = re.match(text);
    if (match.hasMatch()) {
        int totalCount = match.captured(1).toInt();
        totalPages = (totalCount + pagerowcount - 1) / pagerowcount; // 计算总页数
    }

    reply->deleteLater();
}

QStringList Widget::match(QString text, QString fn)
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

StockInfo Widget::getStockInfo(QString stockcode)
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

        // 直接获取代码和名称
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


void Widget::on_lineEdit_code_textChanged(const QString &text)
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

    // 设置股票名称字体为华文中宋加粗
    QFont fontName("STZhongsong", 10, QFont::Bold);

    // 设置股票名称字体和加粗效果
    singleRowModel->setData(singleRowModel->index(0, 1), fontName, Qt::FontRole);

    // 设置涨跌幅颜色和加粗效果
    double rise_fall_level = stockInfo.rise_fall_level.toDouble();
    if (rise_fall_level > 0) {
        singleRowModel->setData(singleRowModel->index(0, 3), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 3), brushRed, Qt::ForegroundRole);
    } else if (rise_fall_level < 0) {
        singleRowModel->setData(singleRowModel->index(0, 3), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 3), brushGreen, Qt::ForegroundRole);
    }

    // 设置涨跌额颜色和加粗效果
    double rise_fall_amount = stockInfo.rise_fall_amount.toDouble();
    if (rise_fall_amount > 0) {
        singleRowModel->setData(singleRowModel->index(0, 4), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 4), brushRed, Qt::ForegroundRole);
    } else if (rise_fall_amount < 0) {
        singleRowModel->setData(singleRowModel->index(0, 4), fontBold, Qt::FontRole);
        singleRowModel->setData(singleRowModel->index(0, 4), brushGreen, Qt::ForegroundRole);
    }
}

void Widget::comboBox()
{
    QStringList itemList;
    itemList << "买入" << "卖出";
    ui->chooseBox->addItems(itemList);
}

void Widget::connectSql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("股票模拟交易");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setPassword("123098Qazplm");
    if (db.open()) {
        qDebug() << "mysql连接成功";
    } else {
        qDebug() << "连接失败";
    }
}

void Widget::on_confirmButton_clicked()
{
    QDateTime time_ = QDateTime::currentDateTime();
    QString name_ = ui->lineEdit_name->text();
    int num = ui->lineEdit->text().toInt();
    QString code_ = ui->lineEdit_code->text();
    double price = ui->lineEdit_price->text().toDouble();
    QString buyOrSell = ui->chooseBox->currentText();
    double delta_ = price * num;
    if (ui->chooseBox->currentText() == "买入") {
        delta_ = -delta_;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO historyrecord (name, code, num, price, buyorsell, commerceTime, gainorcost)"
                  "VALUES (:name, :code, :num, :price, :buyorsell, :time, :delta)");

    // 绑定参数
    query.bindValue(":name", name_);
    query.bindValue(":code", code_);
    query.bindValue(":num", num);
    query.bindValue(":price", price);
    query.bindValue(":buyorsell", buyOrSell);
    query.bindValue(":time", time_.toString(Qt::ISODate));
    query.bindValue(":delta", delta_);

    bool ok = query.exec();
    if (ok) {
        qDebug() << "添加数据成功";
        QMessageBox::information(this, "添加提示", "添加成功");
    } else {
        qDebug() << "添加数据失败：" << query.lastError().text();
    }
}

void Widget::on_lineEdit_code_editingFinished()
{
    ui->lineEdit_name->setText(getStockInfo(ui->lineEdit_code->text()).name);
    ui->lineEdit_price->setText(getStockInfo(ui->lineEdit_code->text()).price);
}

void Widget::on_pageJumpButton_clicked()
{
    bool ok;
    int pageNumber = lineEdit_pageJump->text().toInt(&ok);
    if (!ok || pageNumber < 1 || pageNumber > 119) {
        QMessageBox::warning(this, "错误", "输入的页码无效，请输入正确的页码！");
        return;
    }

    curpage = pageNumber;
    downloadFile(curpage);
    filltable();
}

