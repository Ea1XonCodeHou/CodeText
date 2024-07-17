#include "monitor.h"
#include "ui_monitor.h"
#include<QTimer>
QString verifycode="";
monitor::monitor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::monitor)
{
    ui->setupUi(this);
    setWindowTitle("用户日志");
    connect_to_mysql();
    QTimer *t=new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(download_pic()));
    t->start(100);
    model=new QSqlTableModel(this, QSqlDatabase::database("1"));
    model->setTable("userlog");
    model->select();
    ui->tableView->setModel(model);
    connect_to_userinfo();
    getverifycode();
  connect(ui->label,&mylabel::click,this,&monitor::update_pic);
    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime());
}
void monitor::download_pic()
{
    update_pic();
}
void monitor::update_pic()
{
    getverifycode();
    QPixmap pixmap(ui->label->size());
     QFile file("C:\\Users\\TomGeller\\Desktop\\验证码图片\\列表.txt");
    file.open(QIODevice::Append | QIODevice::Text);
   ui->label->render(&pixmap);
    pixmap.save("C:\\Users\\TomGeller\\Desktop\\验证码图片\\"+verifycode+".jpg");
   QString str= verifycode+'\n';
   //打开文件，不存在则创建
   //写入文件需要字符串为QByteArray格式
   file.write(str.toUtf8());
    file.close();
   // QString fileName = QFileDialog::getSaveFileName(nullptr, "Save Image", "C:\Users\TomGeller\Desktop", "Images (*.png *.xpm *.jpg)");
    update();//通过update来更新画图
}
void monitor::getverifycode()
{
    verifycode.clear();
    for(int i=0;i<4;i++)
    {
        int rand=QRandomGenerator::global()->bounded(1,1000);//最多26个字母
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
monitor::~monitor()
{
    delete ui;
}
void monitor::connect_to_mysql()
{
    QSqlDatabase sqldb = QSqlDatabase::addDatabase("QMYSQL","1");
    sqldb.setHostName("120.46.221.110");
    sqldb.setDatabaseName("用户日志");
    sqldb.setUserName("admin");
    sqldb.setPassword("123098Qazplm@");
    sqldb.open();
    model=new QSqlTableModel(this);
    model->setTable("userlog");
    model->select();
       ui->tableView->setModel(model);
}
void monitor::connect_to_userinfo()
{
    db2 = QSqlDatabase::addDatabase("QMYSQL","2");
    db2.setHostName("120.46.221.110");  //连接本地主机
    db2.setPort(3306);
    db2.setDatabaseName("userinfo");
    db2.setUserName("admin");
    db2.setPassword("123098Qazplm@");
    //要加一句db.open 不然是不会打开的
    db2.open();
}
void monitor::on_pushButton_2_clicked()
{
    QString username=ui->lineEdit_2->text();
    QSqlQuery sqlquery(db2);
    QString cmd = QString("SELECT * FROM user where id='%1'").arg(username);
    sqlquery.exec(cmd);
    if(!ui->lineEdit_3->text().size()) QMessageBox::warning(this, "Warning", "新密码不能为空");
    else if(ui->lineEdit_4->text().toLower()!=verifycode.toLower())QMessageBox::warning(this, "Warning", "验证码错误");
    else   if(sqlquery.next()){
        cmd=QString("UPDATE user SET password='%1' where id ='%2'").arg(ui->lineEdit_3->text()).arg(username);
     sqlquery.exec(cmd);
     QMessageBox::information(this, "information", "修改成功", QMessageBox::NoButton, QMessageBox::Close);
    }
    else
       QMessageBox::warning(this, "Warning", "用户不存在");
    update_pic();
}


void monitor::on_pushButton_clicked()
{
    int row=model->rowCount();
    for(int i=0;i<row;i++) ui->tableView->setRowHidden(i,false);
    QDate date1,date2;
    date1=ui->dateEdit->date();//提取开始时间
    date2=ui->dateEdit_2->date();
    if(date1>date2) QMessageBox::warning(this, "Warning", "日期输入有误");
    else {
        QString str=ui->lineEdit->text();
        str.remove(QRegularExpression("\\s"));
        for(int i=0;i<row;i++)
        {
            int flag=0;
            auto x=model->data(model->index(i,4)).toDate();
            if(date1>x||date2<x){ui->tableView->setRowHidden(i,true);flag=1;}
            QString r;
            for(int j=0;j<5;j++)
            {auto index=model->index(i,j);
                r+=model->data(index).toString();}
            r.remove(QRegularExpression("\\s"));
            if(r.contains(str,Qt::CaseSensitive)&&!flag)
            {ui->tableView->setRowHidden(i,false);
            }
            else ui->tableView->setRowHidden(i,true);
        }

    }

}

