#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
  //  download_timer=new QTimer();
    update_table_timer=new QTimer();
    settable();
   connect(update_table_timer,SIGNAL(timeout()),this,SLOT(update_table()));
  //  connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), ui->tableView, SLOT(update()));
    //不需要再用connect 只要model变化tableview就会变化 用model实现动态更新
    update_table_timer->start(1000);
}
void Widget::update_table()
{
    download_file(curpage);
    for(int i=0;i<20;i++){
        //这里必须得同步更新 否则会出错
         model->setData(model->index(i,0),code[i]);
        model->setData(model->index(i,1),name[i]);
        model->setData(model->index(i,2),cur_price[i]);
         model->setData(model->index(i,3),rise_fall_level[i]);
        model->setData(model->index(i,4),rise_fall_amount[i]);
    }
}
Widget::~Widget()
{
    delete ui;
}
void Widget::settable(){
    model=new QStandardItemModel(20,5);
     model->setHeaderData(0, Qt::Horizontal, "代码");
    model->setHeaderData(1, Qt::Horizontal, "名称");
       model->setHeaderData(2, Qt::Horizontal, "最新价");
      model->setHeaderData(3, Qt::Horizontal, "涨跌幅");
         model->setHeaderData(4, Qt::Horizontal, "涨跌额");
      ui->tableView->setModel(model);
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
            qDebug()<<text;
            name=match(text,"f14");
           code=match(text,"f12");
            cur_price=match(text,"f2");
           rise_fall_level=match(text,"f3");
            rise_fall_amount=match(text,"f4");
}
QStringList Widget::match(QString text,QString fn)
{
    QString qreg='\"'+fn+"\":\"(.*?)\"";//对于反斜杠要用转义字符表示
    QString qregdouble='\"'+fn+"\":(-?\\d+\\.\\d+)";
 //    QString qregdouble='\"'+fn+"\":(\\d+\\.\\d+)";
    if(fn!="f12"&&fn!="f14")qreg=qregdouble;
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
    }
    return strlist;
}
void Widget::on_pushButton_clicked()
{
    curpage++;
    if(curpage>maxpage)curpage=maxpage;//有时钟一直更新 所以只需更改curpage
   // update_table_timer->stop();
  //  update_table();
    ui->label_page->setText(QString::number(curpage,10));
}

QString Widget::getcodename(QString stockcode)
{
    QString str="https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=jQuery3510056998741720915014_1720423814031&secid=1.%1&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1%2Cf2%2Cf3%2Cf4%2Cf5%2Cf6&fields2=f51%2Cf52%2Cf53%2Cf54%2Cf55%2Cf56%2Cf57%2Cf58%2Cf59%2Cf60%2Cf61&klt=101&fqt=1&end=20500101&lmt=120&_=1720423814048";
        QString url_str=str.arg(stockcode);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    auto text=reply->readAll();
    QString qreg="\"name\":\"([^\"]+)";//qt不支持汉字的unicode编码
    QRegularExpression re(qreg);
    //用next函数实现跳转从而全局匹配
 //   QString codename;
    auto pos=re.globalMatch(text);
    qDebug()<<pos.hasNext();
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(8);
        return tmp;
    }
}
void Widget::on_pushButton_2_clicked()
{
    curpage--;

    if(curpage<minpage)curpage=minpage;
      ui->label_page->setText(QString::number(curpage,10));
}


void Widget::on_pushButton_3_clicked()
{
    curpage=maxpage;
     ui->label_page->setText(QString::number(curpage,10));
}


void Widget::on_pushButton_4_clicked()
{
    curpage=minpage;
     ui->label_page->setText(QString::number(curpage,10));
}


void Widget::on_lineEdit_code_editingFinished()
{
    ui->lineEdit_name->setText(getcodename(ui->lineEdit_code->text()));
}

