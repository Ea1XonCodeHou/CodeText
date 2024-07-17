#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include <QList>
#include<QString>
#include<QByteArray>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QHostAddress>
#include<QStandardItemModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void newclienthandler();
    void clientInfoSlot();
    void  disconnect_client();
    void connect_to_mysql();
    void read_mysql_history();
    void insert_to_mysql(QString message);
private:
    Ui::Widget *ui;
    QTcpServer *server;
    QList<QTcpSocket*>client_list;
    void sendclientInfo(QString message);
    QSqlDatabase db;
    int client_num=0;
    QStandardItemModel *model;
    void init_table();
};
#endif // SERVER_H
