#include "widget.h"
#include "ui_widget.h"
#include<QStandardItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    settable();
    download_file(1);
    comboBox();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::settable()
{
    // 创建数据模型
    model = new QStandardItemModel(20,3);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "股票名称");
    model->setHeaderData(1, Qt::Horizontal, "股票代码");
    model->setHeaderData(2, Qt::Horizontal, "股票价格");

    // 将数据模型绑定到表格中
    ui->tableView->setModel(model);

    QTimer *update_timer = new QTimer(this);
    connect(update_timer,SIGNAL(timeout()),this,SLOT(qtimeSlot()));
    update_timer->start(1000);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // 填充数据
   // for(int i=0;i<)
   /* for(int i=0;i<20;i++)
    {
        model->setData(model->index(i,0),name[i]);
     //   model->setData(model->index(i,1),code[i]);
        model->setData(model->index(i,2),price[i]);
    }*/


  /*  ui->tableView->setModel(model);

        // 实现数据改变自动刷新的功能
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->show();*/
}
void Widget::download_file(int pn)//下载第pn页的股票数据
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
    QString qreg1="\"f14\"\\s*:\\s*\"(.*?)\"";//对于反斜杠要用转义字符表示
    QString qreg2="\"f12\"\\s*:\\s*\"(.*?)\"";
    QString qreg3="\\b\"f2\":(\\d+(\\.\\d+)?)\\b";
    QRegularExpression re1(qreg1);
    QRegularExpression re2(qreg2);
    QRegularExpression re3(qreg3);
    auto pos1 = re1.globalMatch(text);
    auto pos2 = re2.globalMatch(text);
    auto pos3 = re3.globalMatch(text);
    int i=0;
    while(pos1.hasNext())
    {
        auto match = pos1.next();
        auto match2=pos2.next();
        auto match3=pos3.next();
        auto tmp = match.captured(0).mid(7,4);        // 直接使用匹配组的内容
        auto tmp2=match2.captured(0).mid(7,6);
        auto tmp3=match3.captured(0);
        qDebug()<<tmp3;
        qDebug()<<tmp2;
        qDebug()<<tmp;
        model->setData(model->index(i,0),tmp);
        model->setData(model->index(i,1),tmp2);
        model->setData(model->index(i,2),tmp3);
        qDebug()<<"在第"<<i<<"行"<<tmp;
        i++;

        //searchBox
        ui->searchBox->addItem(tmp);
        ui->searchBox->setEditable(true);
    }
}
void Widget::comboBox()
{
    QStringList itemList;
    itemList<<"买入"<<"卖出";
    ui->chooseBox->addItems(itemList);

}
void Widget::qtimeSlot()
{

}

void Widget::on_forwardButton_clicked()
{
    curpage++;
    download_file(curpage);
}


void Widget::on_backButton_clicked()
{
    curpage--;
    download_file(curpage);
}

