#ifndef USERLOG_H
#define USERLOG_H
#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDateTime>
#include <QtNetwork>
#include <QRegularExpression>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
namespace Ui {
class userlog;
}
class userlog : public QWidget
{
    Q_OBJECT

public:
    explicit userlog(QWidget *parent = nullptr);
   // void send_userlog(QString )
    void sendlog(QString type);
    void connect_to_logsql();
    void getlocate();
    void init(QString username_input);
    QSqlDatabase db_log;
    QString username,ip,locate;
};

#endif // USERLOG_H
