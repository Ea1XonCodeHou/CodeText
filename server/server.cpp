#include "server.h"
#include "ui_server.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Server");//对窗口标题命名
    server=new QTcpServer;
    QString s="127.0.0.1";
    server->listen(QHostAddress(s),8888);
    connect(server,&QTcpServer::newConnection,this,&Widget::newclienthandler);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::clientInfoSlot()
{
    QTcpSocket  *s=(QTcpSocket *)sender();
    ui->textEdit->setText(QString(s->readAll()));
}
void Widget::newclienthandler()
{
    QTcpSocket *socket=server->nextPendingConnection();
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);
}
