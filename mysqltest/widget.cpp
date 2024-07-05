#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("AS123456");
    bool ok = db.open();
    qDebug()<<ok;
   /* if (ok){
        QMessageBox::information(this, "infor", "link success");
    }
    else {
        QMessageBox::information(this, "infor", "link failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }*/
}

Widget::~Widget()
{
    delete ui;
}
