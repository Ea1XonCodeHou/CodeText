#ifndef RECHARGE_H
#define RECHARGE_H

#include <QWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class recharge;
}
QT_END_NAMESPACE

class recharge : public QWidget
{
    Q_OBJECT

public:
    Ui::recharge *ui;
    recharge(QWidget *parent = nullptr);
    ~recharge();

private slots:
    void on_pushButton_clicked();

private:
    void getorigin_pwd();
     QSqlDatabase db;
    QString username="1223",pwd;
};
#endif // RECHARGE_H
