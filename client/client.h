#ifndef CLIENT_H
#define CLIENT_H

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};
#endif // CLIENT_H
