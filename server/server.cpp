#include "server.h"
#include "ui_server.h"
//连接--接受信息-发送信息-断开链接
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect_to_mysql();
 setWindowTitle("Server");//对窗口标题命名
    server=new QTcpServer;
 init_table();
    read_mysql_history();
  //  QString s="120.46.221.110";
    QString s="127.0.0.1";
    server->listen(QHostAddress(s),8888);
    connect(server,&QTcpServer::newConnection,this,&Widget::newclienthandler);
}
void Widget::init_table()
{
     model=new QStandardItemModel(0,5);
   // QStandardItem
}
void Widget::read_mysql_history()//读取mysql历史记录
{
    QSqlQuery db_cursor(db);
    QString cmd = QString("select * from 聊天室记录");
    db_cursor.exec(cmd);
    while(db_cursor.next())
    {
        auto user=db_cursor.value(0).toString();
        auto msg=db_cursor.value(1).toString();
        auto date=db_cursor.value(2).toString();
        msg=user+'|'+msg+'|'+date;
        ui->textEdit->insertPlainText(msg);
    }
}
Widget::~Widget()
{
    db.close();
    delete ui;
}
void Widget::connect_to_mysql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("聊天室历史记录");
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    db.open();
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
    auto text=message.split('|');
    auto msg=text[0];
    auto user=text[1];
    auto date=text[2];
    msg='\n'+user+"   "+date+msg;
    ui->textEdit->insertPlainText(msg);
    insert_to_mysql(message);
    //2.再广播到各个客户端
    sendclientInfo(message);
}
void Widget::insert_to_mysql(QString message)
{
QSqlQuery query(db);
QStringList tmp=message.split("|");
QString user=tmp[1];QString msg=tmp[0];QString timedate=tmp[2];
QString sql=QString("INSERT INTO 聊天室记录(用户,信息,时间) values('%1','%2','%3')").arg(user).arg(msg).arg(timedate);
  query.exec(sql);
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
    for(int i=0;i< client_list.length();i++)//删除对应客户端
       if( client_list.at(i)->peerAddress() == tcpSocket->peerAddress()&&
            client_list.at(i)->peerPort() == tcpSocket->peerPort())
            {
                 client_list.removeAt(i);
                //下拉框去除该客户端
                break;
            }

    //lcd显示的数量减1
    client_num--;
    ui->lcdNumber->display(client_num);
    QSqlQuery query(db);
    QString sql = QString("update 在线人数 set 在线人数='%1'").arg(client_num);
    query.exec(sql);
    tcpSocket->close();
}

void Widget::newclienthandler()
{
    QTcpSocket *socket=server->nextPendingConnection();
    client_list.append(socket);
    client_num++;

    QSqlQuery query(db);
    QString sql = QString("update 在线人数 SET 在线人数='%1'").arg(client_num);
     query.exec(sql);
    ui->lcdNumber->display(client_num);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);//客户端发送信息开始处理
    connect(socket,&QTcpSocket::disconnected, this, &Widget::disconnect_client);//客户端断开处理
}
