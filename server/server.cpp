#include "server.h"
#include "ui_server.h"
//连接--接受信息-发送信息-断开链接
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
    //1.先显示
    QString message;
    QTcpSocket  *s=(QTcpSocket *)sender();
    QTextCursor cursor=ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
    message=QString(s->readAll())+'\n';
    ui->textEdit->insertPlainText(message);
    //2.再广播到各个客户端
    sendclientInfo(message);
}
void Widget::sendclientInfo(QString message)
{
    for(int i=0;i<client_list.length();i++)
    {
        auto tmp_socket=client_list.at(i);
        QByteArray sendmsg=message.toUtf8();
        tmp_socket->write(sendmsg);
    }
}
void Widget::disconnect_client()
{
   QTcpSocket *tcpSocket = (QTcpSocket *)this->sender();//得到发出信号的客户端
  /*  QString temp = QString("[%1:%2]:退出").arg(tcpSocket->peerAddress().toString()).arg(tcpSocket->peerPort());
    ui->textEditReadonly->append(temp);
    //从链表中删除
    for(int i=0;i<clients.length();i++)
    {
        if(clients.at(i)->peerAddress() == tcpSocket->peerAddress())
        {
            if(clients.at(i)->peerPort() == tcpSocket->peerPort())
            {
                clients.removeAt(i);
                //下拉框去除该客户端
                ui->comboBox_clientLink->removeItem(i+1);
                break;
            }
        }
    }*/
    //lcd显示的数量减1
    client_num--;
    ui->lcdNumber->display(client_num);
    tcpSocket->close();
}

void Widget::newclienthandler()
{
    QTcpSocket *socket=server->nextPendingConnection();
    client_list.append(socket);
    client_num++;
    ui->lcdNumber->display(client_num);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);//客户端发送信息开始处理
    connect(socket,&QTcpSocket::disconnected, this, &Widget::disconnect_client);//客户端断开处理
}
