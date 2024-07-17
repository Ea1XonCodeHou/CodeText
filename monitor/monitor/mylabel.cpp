#include "mylabel.h"
//调用全局变量就引用那个头文件
mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
    //设置默认追踪鼠标
    this->setMouseTracking(true);
}
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    emit click();
}
int mylabel::rand()
{
    return QRandomGenerator::global()->bounded(1,10000);
}
void mylabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event); // Call base class implementation to handle default painting
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QFont font("楷体",25,QFont::Bold,true);
    painter.setFont(font);
    QPen pen;
    for(int i=0;i<100;i++)//画点
    {
        pen = QPen(QColor(50+rand()%206,50+rand()%206,50+rand()%206));
        painter.setPen(pen);
        painter.drawPoint(rand()%180,rand()%80);
    }
    for(int i=0;i<5;i++)//画线
    {
        pen = QPen(QColor(50+rand()%206,50+rand()%206,50+rand()%206));
        painter.setPen(pen);
        painter.drawLine(rand()%180,rand()%80,rand()%180,rand()%80);
    }
    for(int i=0;i<4;i++)
    {
        pen = QPen(QColor(30+rand()%206,30+rand()%206,30+rand()%206));
        painter.setPen(pen);
        painter.drawText(15+35*i,10+rand()%15,30,40,Qt::AlignCenter, verifycode[i]);
    }

}
