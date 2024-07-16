#include "loginframe.h"
#include "ui_loginframe.h"

#include "global.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QIcon>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

loginframe::loginframe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginframe)
{
    ui->setupUi(this);
}

loginframe::~loginframe()
{
    delete ui;
}

void loginframe::connent_mysql()
{
    //链接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("120.46.221.110");
    db.setPort(3306);                    //端口
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    db.setDatabaseName("userinfo"); // 默认数据库
    if(!db.open()){
        qDebug() << "未成功链接到数据库";
        QMessageBox::information(this, " ", "连接失败");
    }else{
        qDebug() << "成功链接到数据库";
    }
}


void loginframe::on_login_clicked()
{
    //连接数据库 mysql
    connent_mysql();

    QString id = ui->lineEdit_id->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery query;
    QString qs = QString("SELECT * FROM user WHERE id = '%1' AND password='%2'").arg(id).arg(password);
        query.exec(qs);
        if(query.next()){
            QMessageBox::information(this, "登录", "登录成功");
            this->close();
            //设置全局变量：用户
            Current_User_Name = id;
            emit this->this_closed();
            mainprogram *m = new mainprogram;
            m->setWindowFlags(Qt::FramelessWindowHint);
            m->show();

        }else{
            QMessageBox::information(this, "登录", "密码错误");
        }
    }
