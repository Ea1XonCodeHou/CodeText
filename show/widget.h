#ifndef WIDGET_H
#define WIDGET_H
#include<QWidget>
#include<QTimer>
#include<QStandardItemModel>
#include<QStringList>
#include<QTableView>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <QNetworkAccessManager>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void settable();
    void downloadall();
    void download_file(int pn);
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
   // QStringList name,number,price;
    QStandardItemModel *model;
    QTimer *update_timer;
    int curpage=1;
};
#endif // WIDGET_H
