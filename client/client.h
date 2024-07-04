#ifndef CLIENT_H
#define CLIENT_H
#include <QElapsedTimer>
#include <QWidget>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDebug>
#include<QMessageBox>
#include<QByteArray>
#include<QTcpSocket>
#include <QTimer>
#include<QDateTime>
#include<QDataStream>
#include<QAbstractSocket>
#include<QTest>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;class clock;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void  sendInfo();
    void connect_to_server();
    void recvmsg();
private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    QTimer* recv_Timer;
    QString Ip,port;
};
#endif // CLIENT_H
