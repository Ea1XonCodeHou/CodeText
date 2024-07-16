#include "signupframe.h"
#include "ui_signupframe.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QIcon>
#include <QSqlQuery>
#include <QSqlError>
QString verifycode="";

signupframe::signupframe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signupframe)
{
    ui->setupUi(this);
  connent_mysql();
    getverifycode();
    connect(ui->label_2,&mylabel::click,this,&signupframe::update_pic);
}

signupframe::~signupframe()
{
    delete ui;
}
void signupframe::update_pic()
{
    getverifycode();
    update();
}
void signupframe::connent_mysql()
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

void signupframe::create_user_database(const QString &username, const QString &password)
{
    QSqlQuery query;
    QString dbname = "USER_" + username;  // 为每个用户创建一个独立的数据库，名为 USER_username

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

    // 使用新数据库连接执行以下操作
    QSqlQuery query_new(db);

    // 创建个人信息表并插入账户和密码
    qs = QString("CREATE TABLE IF NOT EXISTS personal_info ("
                 "id VARCHAR(255) PRIMARY KEY,"
                 "password VARCHAR(255) NOT NULL,"
                 "balance DOUBLE DEFAULT 10000,"
                 "marketvalue DOUBLE DEFAULT 0,"
                 "total_profit_loss DOUBLE DEFAULT 0,"
                 "profit_loss_rate DOUBLE DEFAULT 0);"
                 "INSERT INTO personal_info (id, password) VALUES ('%1', '%2');")
             .arg(username).arg(password);
    if (!query_new.exec(qs)) {
        qDebug() << "Failed to create personal info table or insert data: " << query_new.lastError().text();
        QMessageBox::information(this, "注册", "创建个人信息表或数据插入失败");
    }

    // 创建交易记录表格，使用 transaction_time 作为主键，并添加 StockID 列
    qs = QString("CREATE TABLE IF NOT EXISTS transactions ("
                 "transaction_time DATETIME PRIMARY KEY,"
                 "StockID VARCHAR(255) NOT NULL," // 新增的股票代码字段
                 "stock_symbol VARCHAR(255) NOT NULL,"
                 "price DOUBLE NOT NULL,"
                 "quantity INT NOT NULL,"
                 "transaction_type VARCHAR(50) NOT NULL)");
    if (!query_new.exec(qs)) {
        qDebug() << "Failed to create transactions table: " << query_new.lastError().text();
        QMessageBox::information(this, "注册", "创建交易记录表失败");
    }
}


void signupframe::on_pushButton_clicked()
{
    //连接数据库 mysql
   // connent_mysql();

    QString newid = ui->lineEdit_id->text();
    QString newpassword = ui->lineEdit_password->text();
   // qDebug() << verifycode << " " << ui->lineEdit_test->text();
    if(verifycode.toLower() == ui->lineEdit_test->text().toLower()){
        QString qs_id = QString("SELECT * FROM user WHERE id = '%1'").arg(newid);
        QSqlQuery query_id(qs_id);
        if(newid == "" || newpassword == "")
            QMessageBox::information(this, "注册", "注册失败");
        else if(query_id.next())
            QMessageBox::information(this, "注册", "用户已存在");
        else {
            QString qs = QString("INSERT INTO user(id,password) VALUES('%1','%2')").arg(newid).arg(newpassword);
            QSqlQuery query;
            if (!query.exec(qs))
                QMessageBox::information(this, "注册", "注册失败");
             else {
                create_user_database(newid, newpassword);
                QMessageBox::information(this, "注册", "注册成功");
            }

        }
        ui->lineEdit_test->clear();
        ui->label_2->click();
    } else {
        qDebug() << verifycode.toLower() << " " << ui->lineEdit_test->text().toLower();
        QMessageBox::information(this, "注册", "验证码错误");
        ui->lineEdit_test->clear();
        ui->label_2->click();
    }
}


void signupframe::getverifycode()
{
    verifycode.clear();
    for(int i=0;i<4;i++)
    {
        int rand=QRandomGenerator::global()->bounded(1,1000);//最多26个字母
            //   qDebug()<<rand;
        if(rand%3==0)//数字
            verifycode+=QString::number(rand%10);
        else  if(rand%3==1)//小写字母
        {
            int temp='a';
            verifycode+=static_cast<QChar>(temp + rand%26);
        }
        else {//大写字母 这里不能单纯写if 不然只是与rand%3=1相反 应该所有都写else if
            int temp='A';
            verifycode+=static_cast<QChar>(temp + rand%26);
        }
    }
}
