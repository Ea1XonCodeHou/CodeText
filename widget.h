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
#include<QCompleter>
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
    void comboBox();
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void qtimeSlot();
    void on_forwardButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Widget *ui;
   // QStringList name,number,price;
    QStandardItemModel *model;
    QTimer *update_timer;
    int curpage=1;
    int pagerowcount=20;
};
#endif // WIDGET_H
