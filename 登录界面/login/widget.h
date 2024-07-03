#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "signup.h"
#include "mainprogramwindow.h"

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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    signup *signupwindow = new signup;
    MainprogramWindow *mainprogram = new MainprogramWindow;
};
#endif // WIDGET_H
