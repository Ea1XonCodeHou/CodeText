#include "client.h"
#include "ui_client.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    recv_Timer=new QTimer;
        socket =new QTcpSocket;
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
   connect_to_server();
}
void Widget::connect_to_server()
{
    Ip=ui->lineEdit->text();
     port=ui->lineEdit_2->text();
    socket->connectToHost(QHostAddress(Ip),port.toShort());  
  if(socket->state()!=QAbstractSocket::ConnectedState)
    QMessageBox::information(this,"提示","连接失败");//用socket的状态来判断是否连接失败
    connect(socket, &QIODevice::readyRead, this, &Widget::recvmsg);
}
void Widget::recvmsg()
{
    ui->textEdit->insertPlainText((QString)socket->readAll());
}
void Widget::on_pushButton_2_clicked()
{
    socket->connectToHost(QHostAddress(Ip),port.toShort());
    if(socket->state()==QAbstractSocket::ConnectedState)//只有联通才发送信息
    sendInfo();
    else  QMessageBox::information(this,"提示","连接失败");
}
void Widget::sendInfo()//得把相应的动作写成槽函数
{
    QString ba;
    ba.append(ui->lineEdit_3->text());
    ba+='|';ba.append(ui->lineEdit_4->text());ba+='|';
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString timestr = dateTime .toString("yyyy-MM-dd hh:mm:ss");
    ba+=timestr;
    socket->write(ba.toUtf8().data());//将string类型转成utf-8发送给服务
}

