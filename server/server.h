#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include <QList>
#include<QString>
#include<QByteArray>
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
private:
    Ui::Widget *ui;
    QTcpServer *server;
    QList<QTcpSocket*>client_list;
    void sendclientInfo(QString message);
    int client_num=0;
};
#endif // SERVER_H
