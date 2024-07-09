#include "widget.h"
#include "ui_widget.h"
#include<QStandardItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    settable();
    //sumpage=
    //for(int curpage=1;curpage<sumpage;curpage++)
   // {
        download_file(1);
    //}

}

Widget::~Widget()
{
    delete ui;
}

void Widget::settable()
{
    // 创建数据模型
    model = new QStandardItemModel(3,2);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "股票名称");
    model->setHeaderData(1, Qt::Horizontal, "股票代码");
    model->setHeaderData(2, Qt::Horizontal, "股票价格");

    // 将数据模型绑定到表格中
    ui->tableView->setModel(model);

    QTimer *update_timer = new QTimer();
    connect(update_timer,SIGNAL(timeout()),this,SLOT(update()));
    update_timer->start(1000);
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
    QRegularExpression re(qreg1);
    auto pos1 = re.globalMatch(text);
    while(pos1.hasNext())
    {
        auto match = pos1.next();
        auto tmp = match.captured(0).mid(7,4); // 直接使用匹配组的内容
        qDebug()<<tmp;
       // model->setItem(0,0,new QStandardItemModel(temp));
        // 直接创建 QStandardItem 对象，不使用智能指针
     //   QStandardItem *temp1 = new QStandardItem(tmp);

        // 检查 model 是否为非空指针
   //     assert(model != nullptr); // 或者使用 if 语句检查

        // 假设你想要添加到模型中的行数与你的数据请求中返回的数据条目数相同
        // 这里我们假定每次请求返回的数据条目数为20

    //qDebug() << "Row:" << i << "Data:" << tmp; // 打印日志
    //    model->setItem(i,0,temp1);


        // 重要：在循环结束时删除 QStandardItem，避免内存泄漏
 //       delete temp1;
    }
     //   ui->tableView->show();
   /* if(fn!="f12"&&fn!="f14")qreg=qregdouble;
    QRegularExpression re(qreg);
    //用next函数实现跳转从而全局匹配
    QStringList strlist;
    auto pos=re.globalMatch(text);
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(fn.size()+3);
        if(fn=="f12"||fn=="f14")tmp=tmp.mid(1,tmp.size()-2);
        strlist.append(tmp);
    }*/
}
