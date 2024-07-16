#include "recharge.h"
#include "ui_recharge.h"

recharge::recharge(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::recharge)
{
    ui->setupUi(this);
    getorigin_pwd();
}

recharge::~recharge()
{
    delete ui;
}
void recharge::getorigin_pwd()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("userinfo");
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    //要加一句db.open 不然是不会打开的
    db.open();
    QSqlQuery sqlquery(db);
    QString cmd = QString("select * from user where id='%1'").arg(username);
    sqlquery.exec(cmd); sqlquery.next();
    pwd=sqlquery.value(2).toString();
}
void recharge::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text()!=ui->lineEdit_3->text())
    {  QMessageBox::warning(this, "Warning", "两次密码不一致");}
    else if(ui->lineEdit->text()!=pwd)
    {    QMessageBox::warning(this, "Warning", "原密码错误");}
    else if(ui->lineEdit_2->text().size())
    {
        QSqlQuery sqlquery(db);
        QString cmd = QString("update user SET password=%1 where id='%2'").arg(ui->lineEdit_2->text()).arg(username);
        sqlquery.exec(cmd);
        //更新修改后的密码
        pwd=ui->lineEdit_2->text();
       QMessageBox::information(this, "information", "修改成功", QMessageBox::NoButton, QMessageBox::Close);
    }
    else {
        QMessageBox::warning(this, "Warning", "密码不能为空");
    }
}

