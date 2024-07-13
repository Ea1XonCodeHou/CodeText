#include "widget.h"
#include "ui_widget.h"
  QString verifycode="";
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    getverifycode();
    // ui->label->installEventFilter(this);
    connect(ui->label,&mylabel::click,this,&Widget::update_pic);//标签被单击
}

Widget::~Widget()
{
    delete ui;
}
void Widget::update_pic()
{
    getverifycode();
    update();//通过update来更新画图
}
void Widget::getverifycode()
{
   //  verifycode="";
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
  //  qDebug()<<verifycode;
}
