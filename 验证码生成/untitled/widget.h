#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QPainter>
#include<QRandomGenerator>
extern QString verifycode;//必须得实例化 否则出错
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
  public  slots:
    void update_pic();
private:
    Ui::Widget *ui;
    void getverifycode();
};
#endif // WIDGET_H
