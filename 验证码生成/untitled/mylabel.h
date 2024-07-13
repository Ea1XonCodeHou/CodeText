#ifndef MYLABEL_H
#define MYLABEL_H
#include <QWidget>
#include <QLabel>
#include<QMouseEvent>
#include<QDebug>
#include<QEvent>
#include<QPainter>
#include<QPen>
#include<QRandomGenerator>
namespace Ui {
class mylabel;
}

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);
signals: void click();
protected:
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *event);
};

#endif // MYLABEL_H
