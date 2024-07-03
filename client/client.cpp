#include "client.h"
#include "ui_client.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString Ip=ui->lineEdit->text();
    QString port=ui->lineEdit_2->text();
    socket =new QTcpSocket;
    socket->connectToHost(QHostAddress(Ip),port.toShort());
    connect(socket,&QTcpSocket::connected,[this](){//连接成功提示
        QMessageBox::information(this,"提示","连接成功");
    });
}


void Widget::on_pushButton_2_clicked()
{
    QString ba;
    ba.append(ui->lineEdit_3->text());
    socket->write(ba.toUtf8().data());//将string类型转成utf-8发送给服务器
}

