#ifndef LOGINFRAME_H
#define LOGINFRAME_H

#include <QWidget>
//数据库头文件
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
//主程序界面：
#include "mainprogram.h"

namespace Ui {
class loginframe;
}

class loginframe : public QWidget
{
    Q_OBJECT

public:
    explicit loginframe(QWidget *parent = nullptr);
    ~loginframe();

    void connent_mysql();

private slots:
    void on_login_clicked();

    void on_register_2_clicked();


private:
    Ui::loginframe *ui;
    mainprogram *m;
};

#endif // LOGINFRAME_H
