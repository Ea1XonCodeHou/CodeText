#include "chargein.h"
#include "ui_chargein.h"
chargein::chargein(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chargein)
{
    ui->setupUi(this);
    codegenerate();
    connect(ui->pushButton,&QPushButton::clicked,this,&chargein::action);
     connect(ui->pushButton_2,&QPushButton::clicked,this,&chargein::action);
     connect(ui->pushButton_3,&QPushButton::clicked,this,&chargein::action);
      connect(ui->pushButton_5,&QPushButton::clicked,this,&chargein::action);
}

chargein::~chargein()
{
    delete ui;
}
void chargein::action()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>(sender());
    auto t=senderButton->text();
    if(t=="10000")index=0;
    else if(t=="20000")index=1;
    else if(t=="50000")index=2;
    else if(t=="100000")index=3;
}
void chargein::codegenerate()
{
    qrcode.clear();
    for(int i=0;i<10;i++)
    {
        int rand=QRandomGenerator::global()->bounded(1,1000);
        if(rand%3==0)  qrcode+=QString::number(rand%10);
        else if(rand%3==1)
        {
            int temp='a';
            qrcode+=static_cast<QChar>(temp + rand%26);
        }
        else {
            int temp='A';
            qrcode+=static_cast<QChar>(temp + rand%26);
        }
    }
    QImage a = renders->encodeImage(qrcode,8);
    ui->label->setPixmap(QPixmap::fromImage(a));
}
void chargein::charge_account()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");  //连接本地主机
    db.setPort(3306);
    QString database="USER_"+username;
    db.setDatabaseName(database);
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    //要加一句db.open 不然是不会打开的
    db.open();
    QSqlQuery sqlquery(db);
    QString cmd = QString("SELECT * FROM personal_info where id='%1'").arg(username);
    sqlquery.exec(cmd); sqlquery.next();
    double money=sqlquery.value(2).toDouble();
    money+=val[index];
     cmd = QString("UPDATE personal_info SET balance='%2' where id='%1'").arg(username).arg(money);
    sqlquery.exec(cmd);
}
void chargein::on_pushButton_4_clicked()
{
    if(index==-1){
        QMessageBox::warning(this, "Warning", "请选择要充值的金额");
    }
 else   if(qrcode.toUpper()==ui->lineEdit->text().toUpper())
    {
       QMessageBox::information(this, "information", "充值成功", QMessageBox::NoButton, QMessageBox::Close);
        charge_account();
    }
    else {
 QMessageBox::warning(this, "Warning", "密钥错误");
    }
    ui->lineEdit->clear();
     codegenerate();
}

