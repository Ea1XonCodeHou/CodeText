#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    settable();
      download_file("f23");
    /*QFile file(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\\\url_data.txt");
    file.open( QIODevice::ReadOnly);//file一定要open才行*/
 /*   QRegularExpression re("\"f14\":\"(.*?)\"");
    //用next函数实现跳转从而全局匹配
   auto pos=re.globalMatch(text);
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto tmp=match.captured(0).mid(7);
        qDebug()<<tmp.left(tmp.size()-1)<<" ";
    }*/
}
void Widget::settable()
{
    QStringList m_Header;
    ui->tableWidget->setColumnCount(5);
    m_Header<<QString("代码")<<QString("名称")<<QString("现价")<<QString("涨幅额")<<QString("涨幅");
    ui->tableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->tableWidget->horizontalHeader()->setVisible(true);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::download_file(QString fn)
{
    //分三种类型 double int 中文
    QString url_str="https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    text=reply->readAll();

   QString qregnum='\"'+fn+"\":(\\d+)";//对于反斜杠要用转义字符表示
    QString qreg='\"'+fn+"\":\"(.*?)\"";
   QString qregdouble='\"'+fn+"\":(\\d+\\.\\d+)";
   if(fn!="f14")qreg=qregnum;
    QRegularExpression re(qregdouble);
    //用next函数实现跳转从而全局匹配
    auto pos=re.globalMatch(text);
    qDebug()<<pos.hasNext();
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto tmp=match.captured(0);
        qDebug()<<tmp<<" ";
    }
}
