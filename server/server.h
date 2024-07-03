#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
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
private:
    Ui::Widget *ui;
    QTcpServer *server;
};
#endif // SERVER_H
