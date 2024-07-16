#include "loginframe.h"
#include "ui_loginframe.h"

#include "global.h"

QString User_Name =" ";
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

void loginframe::create_user_database(const QString &username)
{
    QSqlQuery query;
    QString dbname = "user_" + username;

    // 创建用户独立数据库
    QString qs = QString("CREATE DATABASE IF NOT EXISTS %1").arg(dbname);
    if (!query.exec(qs)) {
        qDebug() << "Failed to create database: " << query.lastError().text();
        QMessageBox::information(this, "注册", "创建用户数据库失败");
        return;
    }

    // 连接到新创建的数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "user_connection");
    db.setHostName("120.46.221.110");
    db.setPort(3306);
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    db.setDatabaseName(dbname);

    if (!db.open()) {
        qDebug() << "Failed to connect to user database: " << db.lastError().text();
        QMessageBox::information(this, "注册", "连接用户数据库失败");
        return;
    }

    // 创建用户独立表格
    query = QSqlQuery(db);
    qs = QString("CREATE TABLE IF NOT EXISTS %1 ("
                 "id INT AUTO_INCREMENT PRIMARY KEY,"
                 "stock_symbol VARCHAR(255) NOT NULL,"
                 "buy_price DOUBLE NOT NULL,"
                 "buy_time DATETIME NOT NULL,"
                 "quantity INT NOT NULL,"
                 "transaction_type VARCHAR(50) NOT NULL,"
                 "transaction_time DATETIME NOT NULL)").arg(dbname);

    if (!query.exec(qs)) {
        qDebug() << "Failed to create user table: " << query.lastError().text();
        QMessageBox::information(this, "注册", "创建用户表失败");
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
            User_Name = id;
            emit this->this_closed();
            mainprogram *m = new mainprogram;
            m->setWindowFlags(Qt::FramelessWindowHint);
            m->show();

        }else{
            QMessageBox::information(this, "登录", "密码错误");
        }
    }
