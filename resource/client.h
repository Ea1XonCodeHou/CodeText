#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "userlog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class client;
}
QT_END_NAMESPACE

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void sendInfo();
    void connect_to_server();
    void connect_to_mysql();
    void recvmsg();
    void get_chat_history();
    void insertMessage(const QString &user, const QString &msg, const QString &date);

private:
    Ui::client *ui;
    QTcpSocket *socket;
    QTimer* recv_Timer;
    QString Ip, port;
    QSqlDatabase db;
};

#endif // CLIENT_H

