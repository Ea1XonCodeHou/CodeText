#include "widget.h"
#include "ui_widget.h"
#include<QStandardItem>

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

    //getcodeprice("688163");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setTable()
{
    // 创建数据模型
    model = new QStandardItemModel(20,5);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "股票代码");
    model->setHeaderData(1, Qt::Horizontal, "股票名称");
    model->setHeaderData(2, Qt::Horizontal, "股票最新价格");
    model->setHeaderData(3, Qt::Horizontal, "涨跌幅");
    model->setHeaderData(4, Qt::Horizontal, "涨跌额");

    // 将数据模型绑定到表格中
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //字体加粗
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
    for(int i=0;i<20;i++){
        model->setData(model->index(i,0),code[i]);
        model->setData(model->index(i,1),name[i]);
        model->setData(model->index(i,2),cur_price[i]);
        model->setData(model->index(i,3),rise_fall_level[i]);
        model->setData(model->index(i,4),rise_fall_amount[i]);
    }
}
void Widget::downloadFile(int pn)//下载第pn页的股票数据
{
    //f12--代码 f14-名称 f2-最新价 f3-涨跌幅 f4-涨跌额
    //两种类型 1.double  2.中文(代码)
    QString url="https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=%1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QString url_str=url.arg(pn);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    auto text=reply->readAll();
    name=match(text,"f14");
    code=match(text,"f12");
    cur_price=match(text,"f2");
    rise_fall_level=match(text,"f3");
    rise_fall_amount=match(text,"f4");

}
QStringList Widget::match(QString text,QString fn)
{
    QString qreg='\"'+fn+"\":\"(.*?)\"";
    QString qregDouble='\"'+fn+"\":(-?\\d+\\.\\d+)";
    //    QString qregdouble='\"'+fn+"\":(\\d+\\.\\d+)";
    if(fn!="f12"&&fn!="f14")qreg=qregDouble;
    QRegularExpression re(qreg);
    //用next函数实现跳转从而全局匹配
    QStringList strList;
    auto pos=re.globalMatch(text);
    //qDebug()<<"match"<<pos.hasNext();
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(fn.size()+3);
        //qDebug()<<tmp;
        if(fn=="f12"||fn=="f14")tmp=tmp.mid(1,tmp.size()-2);
        strList.append(tmp);
    }
    return strList;
}

QString Widget::search(QString stockCode,QString fn)
{
    QString str="https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=jQuery3510056998741720915014_1720423814031&secid=1.%1&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1%2Cf2%2Cf3%2Cf4%2Cf5%2Cf6&fields2=f51%2Cf52%2Cf53%2Cf54%2Cf55%2Cf56%2Cf57%2Cf58%2Cf59%2Cf60%2Cf61&klt=101&fqt=1&end=20500101&lmt=120&_=1720423814048";
    QString url_str=str.arg(stockCode);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    auto text=reply->readAll();
    qDebug()<<text;
    QString qreg='\"'+fn+"\":\"(.*?)\"";
    QString qregdouble='\"'+fn+"\":(-?\\d+\\.\\d+)";
    if(fn!="f12"&&fn!="f14")qreg=qregdouble;
    QRegularExpression re(qreg);
    auto pos=re.globalMatch(text);
    qDebug()<<"search"<<pos.hasNext();
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(8);
        qDebug()<<tmp;
        return tmp;
    }
}
void Widget::comboBox()
{
    QStringList itemList;
    itemList<<"买入"<<"卖出";
    ui->chooseBox->addItems(itemList);

}

void Widget::on_forwardButton_clicked()
{
    curpage++;
    downloadFile(curpage);
    qDebug()<<"下一页";
}


void Widget::on_backButton_clicked()
{
    curpage--;
    if(curpage<1)
    {
        curpage=1;
    }

    downloadFile(curpage);
    qDebug()<<"上一页";
}

void Widget::connectSql()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("股票模拟交易");
    db.setHostName("120.46.221.110");
    db.setUserName("root");
    db.setPassword("123098Qazplm");
    if(db.open())
    {
        qDebug()<<"mysql连接成功";
    }
    else
    {
        qDebug()<<"连接失败";
    }
}
void Widget::on_confirmButton_clicked()
{

    QDateTime time_= QDateTime::currentDateTime();
    QString name_=ui->lineEdit_name->text();
    int num=ui->lineEdit->text().toInt();
    QString code_=ui->lineEdit_code->text();
    double price=ui->lineEdit_price->text().toDouble();
    QString buyOrSell=ui->chooseBox->currentText();
    double delta_=price*num;
    if(ui->chooseBox->currentText()=="买入")
    {
        delta_=-delta_;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO historyrecord (股票名称, 股票代码, 数量, 当前价, 买入或卖出, 交易时间, 差价)"
                  "VALUES (:name, :code, :num, :price, :buyorsell, :time, :delta)");

    // 绑定参数
    query.bindValue(":name", name_);
    query.bindValue(":code", code_);
    query.bindValue(":num", num);
    query.bindValue(":price", price);
    query.bindValue(":buyorsell", buyOrSell);
    query.bindValue(":time", time_.toString(Qt::ISODate)); // 根据数据库要求的时间格式转换
    query.bindValue(":delta", delta_);

    bool ok = query.exec();
    if (ok) {
        qDebug() << "添加数据成功";
        QMessageBox::information(this, "添加提示", "添加成功");
    } else {
        qDebug() << "添加数据失败：" <<query.lastError().text();
    }
}

QString Widget::getCodeName(QString stockcode)
{
    QString str="https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=jQuery3510056998741720915014_1720423814031&secid=1.%1&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1%2Cf2%2Cf3%2Cf4%2Cf5%2Cf6&fields2=f51%2Cf52%2Cf53%2Cf54%2Cf55%2Cf56%2Cf57%2Cf58%2Cf59%2Cf60%2Cf61&klt=101&fqt=1&end=20500101&lmt=120&_=1720423814048";
    QString url_str=str.arg(stockcode);
    qDebug()<<url_str;
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    auto text=reply->readAll();
    QString qreg="\"name\":\"([^\"]+)";//qt不支持汉字的unicode编码
    QRegularExpression re(qreg);
    auto pos=re.globalMatch(text);
    qDebug()<<pos.hasNext();
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(8);
        qDebug()<<tmp;
        return tmp;

    }
}

QString Widget::getCodePrice(QString stockcode)
{
    QString str="https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QString url_str=str.arg(stockcode);
    qDebug()<<url_str;
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QRegularExpression re("\"f2\":\\s*(\\d+(\\.\\d*)?),");
        QRegularExpressionMatch match = re.match(data);
        if (match.hasMatch()) {
            double price = match.captured(1).toDouble();
            return QString::number(price);
        }
    }

    reply->deleteLater();
}
void Widget::on_lineEdit_code_editingFinished()
{


    ui->lineEdit_name->setText(getCodeName(ui->lineEdit_code->text()));
    ui->lineEdit_price->setText(getCodePrice(ui->lineEdit_code->text()));

}

