#ifndef BUYSELL_H
#define BUYSELL_H

#include <QWidget>
#include <QTimer>
#include <QStandardItemModel>
#include <QStringList>
#include <QTableView>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QRegularExpression>
#include <QCompleter>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlError>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui {
class BuySell;
}
QT_END_NAMESPACE

struct StockInfo {
    QString code;
    QString name;
    QString price;
    QString rise_fall_amount;
    QString rise_fall_level;
};

class BuySell : public QWidget
{
    Q_OBJECT


public:
    void setTable();
    void downloadAll();
    void downloadFile(int pn);
    void comboBox();
    void connectSql();
    void fillLine();

    QString search(QString text,QString fn);
    StockInfo getStockInfo(QString code);
    QStringList match(QString text,QString fn);

    BuySell(QWidget *parent = nullptr);
    ~BuySell();
private slots:
    void filltable();
    void on_forwardButton_clicked();
    void on_backButton_clicked();
    void on_confirmButton_clicked();
    void on_lineEdit_code_editingFinished();
    void on_lineEdit_code_textChanged(const QString &text); // 新增槽函数
    void on_pageJumpButton_clicked(); // 新增槽函数
    void updateSingleRow();


private:
    Ui::BuySell *ui;
    // QStringList name,number,price;
    QStandardItemModel *model;
    QStandardItemModel *singleRowModel;

    QTimer *updateTimer;
    QTimer *singleRowUpdateTimer;

    QLabel *label_pageInfo; // 添加页数标签
    QLineEdit *lineEdit_pageJump; // 新增成员
    QPushButton *pageJumpButton;  // 新增成员


    int curpage=1;
    int totalPages = 1; // 添加totalPages变量
    int pagerowcount=20;
    QStringList name,code,cur_price,rise_fall_level,rise_fall_amount;
    QSqlDatabase db;

    bool isStockCodeValid(const QString &stockCode);
};
#endif // BUYSELL_H
