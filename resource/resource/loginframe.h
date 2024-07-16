#ifndef LOGINFRAME_H
#define LOGINFRAME_H

#include <QWidget>
//数据库头文件
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QIcon>
//主程序界面：
#include "mainprogram.h"

namespace Ui {
class loginframe;
}

class loginframe : public QWidget
{
    Q_OBJECT

public:
    Ui::loginframe *ui;
    explicit loginframe(QWidget *parent = nullptr);
    ~loginframe();

    // 连接数据库
    void connent_mysql();

    // 创建用户独立数据库和表
    void create_user_database(const QString &username);

private slots:
    // 登录按钮点击处理函数
    void on_login_clicked();

signals:
    void this_closed();

private:
    mainprogram *m;
};

#endif // LOGINFRAME_H

