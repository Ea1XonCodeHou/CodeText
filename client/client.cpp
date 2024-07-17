#include "client.h"
#include "ui_client.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    recv_Timer=new QTimer;
    socket =new QTcpSocket;
    connect_to_mysql();
    get_chat_history();
}
Widget::~Widget()
{
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
   //要加一句db.open 不然是不会打开的
    db.open();
}
void Widget::get_chat_history()
{
    QSqlQuery db_cursor(db);
    QString cmd = QString("select * from 聊天室记录");
    db_cursor.exec(cmd);
    while(db_cursor.next())
    {
        auto user=db_cursor.value(0).toString();
        auto msg=db_cursor.value(1).toString();
        auto date=db_cursor.value(2).toString();
        msg='\n'+user+"   "+date+msg;
        ui->textEdit->insertPlainText(msg);
    }
}
void Widget::on_pushButton_clicked()
{
   connect_to_server();
}
void Widget::connect_to_server()
{
    Ip="120.46.221.110";
     port="8888";
    socket->connectToHost(QHostAddress(Ip),port.toShort());  
  if(socket->state()!=QAbstractSocket::ConnectedState)
    QMessageBox::information(this,"提示","连接失败");//用socket的状态来判断是否连接失败
    connect(socket, &QIODevice::readyRead, this, &Widget::recvmsg);
}
void Widget::recvmsg()
{
    auto msg=(QString)socket->readAll();
  QStringList text=msg.split('|');
    QTextCursor cursor=ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
    auto user=text[1];
     msg=text[0];
    auto date=text[2];
    msg='\n'+user+"   "+date+msg+'\n';
    ui->textEdit->insertPlainText(msg);
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
    ba+='|';
    if(ui->lineEdit_4->text().isEmpty())ba.append("匿名用户");
else    ba.append(ui->lineEdit_4->text());
    ba+='|';
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString timestr = dateTime .toString("yyyy-MM-dd hh:mm:ss");
    ba+=timestr;
    socket->write(ba.toUtf8().data());//将string类型转成utf-8发送给服务
    auto t=new userlog();
    t->init("测试");
    t->sendlog("发送信息:"+ui->lineEdit_3->text());
}

