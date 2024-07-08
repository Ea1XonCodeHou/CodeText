#ifndef WIDGET_H
#define WIDGET_H
#include <QFile>				// 用于打开文件
#include <QJsonParseError>		// 返回错误信息
#include <QJsonArray>			// Json数据对象
#include <QJsonDocument>		// Json文档对象
#include <QJsonObject>			// 普通Json对象
#include <QDebug>
#include <QWidget>
#include <QDir>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QFile>
#include<QString>
#include<QStringList>
#include <QTableView>
#include <QStandardItemModel>
#include<QMap>
#include<QPainter>
#include <QCommonStyle>
#include <QCompleter>
#include<QTimer>
#include<QObject>
#include <QApplication>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <iostream>
#include <thread>
#include <functional>
#include<my_thread.h>
#include <QStandardItemModel>
#include<QTest>
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
    void settable();
    void update_table();
//    void update();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_code_editingFinished();

public:
    Ui::Widget *ui;
    void download_file(int pn);
   QString  getcodename(QString stockcode);
    int minpage=1,maxpage=119;
    int curpage=1;
    QStringList code,name,cur_price,rise_fall_level,rise_fall_amount;
  //  QTimer *download_timer;
    QTimer *update_table_timer;
    int t=0;
    QStandardItemModel *model;
    QStringList match(QString text,QString fn);
};

#endif // WIDGET_H
