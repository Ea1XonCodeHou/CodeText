#include "userlog.h"
userlog::userlog(QWidget *parent)
{

connect_to_logsql();
//init("32w");
}
void userlog::sendlog(QString type)
{
    QSqlQuery query(db_log);
   QString date= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//格式化时间
    QString sql=QString("INSERT INTO userlog(用户名,ip,归属地,动作,时间) values('%1','%2','%3','%4','%5')").arg(username).arg(ip).arg(locate).arg(type).arg(date);
    query.exec(sql);
}
void userlog::init(QString username_input)
{
    username=username_input;
    QList<QHostAddress> list =QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
        if(address.protocol() ==QAbstractSocket::IPv4Protocol){ ip=address.toString();break;}
    getlocate();

}
void userlog::getlocate()
{
    QString url="https://ip.useragentinfo.com/json";
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    qDebug()<<reply->readAll();
    QJsonObject json = doc.object();
    locate=json["province"].toString()+" ";
    locate+=json["city"].toString()+" ";
    locate+=json["area"].toString();
    qDebug()<<locate;
}
void userlog::connect_to_logsql()
{
    db_log = QSqlDatabase::addDatabase("QMYSQL");
    db_log.setHostName("120.46.221.110");  //连接本地主机
    db_log.setPort(3306);
    db_log.setDatabaseName("用户日志");
   db_log.setUserName("admin");
    db_log.setPassword("123098Qazplm@");
   db_log.open();
}
