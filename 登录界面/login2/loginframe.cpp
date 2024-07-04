#include "loginframe.h"
#include "ui_loginframe.h"


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

    db.setHostName("127.0.0.1");
    db.setPort(3306);                    //端口
    db.setUserName("root");
    db.setPassword("123098Qazplm@");
    db.setDatabaseName("userinfo");
    if(!db.open()){
        qDebug() << "未成功链接到数据库";
        QMessageBox::information(this, "infor", "link success");
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

    //    query.exec("select * from user");

    QString qs = QString("select * from user where id = '%1' and password='%2'").arg(id).arg(password);
    query.exec(qs);//执行SQL语句
    //        qDebug() << qs;//debug
    //        qDebug() <<query.size();//获取内容的大小//debug
    if(query.next()){          //获取查询结果集
        QMessageBox::information(this,"登录","登录成功");
        //    qDebug()<<query.value("account").toString();//debug
        this->close();
        mainprogram *m=new mainprogram;
        m->show();
    }
    else
    {
        QMessageBox::information(this,"登录","登录失败");
    }

    //    if(ui->lineEdit_account->text() == "admin" && ui->lineEdit_password->text() == "123456"){//debug
    //        this->close();
    //        MainWindow *h=new MainWindow;
    //        h->show();
    //    }else{
    //        QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码输入错误！"),QMessageBox::Ok);
    //        ui->lineEdit_account->clear();
    //        ui->lineEdit_password->clear();
    //        ui->lineEdit_password->setFocus();
    //    }//debug

}


void loginframe::on_register_2_clicked()
{
    //连接数据库 mysql
    connent_mysql();

    QString newid = ui->lineEdit_id->text();
    QString newpassword = ui->lineEdit_password->text();

    QSqlQuery query;


    QString qs = QString("insert into user(id,password) values('%1','%2')").arg(newid).arg(newpassword);
    if (!query.exec(qs)) {
        // 执行失败处理
        QMessageBox::information(this,"注册","注册失败");
    }
    else
    {
        QMessageBox::information(this,"注册","注册成功");
    }
}



