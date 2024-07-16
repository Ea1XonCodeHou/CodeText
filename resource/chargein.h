#ifndef CHARGEIN_H
#define CHARGEIN_H

#include <QWidget>
#include"tcQrencode.h"
#include<QMessageBox>
#include<QRandomGenerator>
#include<QSqlDatabase>
#include<QSqlQuery>
namespace Ui {
class chargein;
}

class chargein : public QWidget
{
    Q_OBJECT

public:
    Ui::chargein *ui;
    explicit chargein(QWidget *parent = nullptr);
    ~chargein();

private slots:
    void on_pushButton_4_clicked();
    void action();
private:
    void charge_account();
    QSqlDatabase db;
     TcQrencode* renders;
    QString qrcode;
     void codegenerate();
    double val[4]={10000,20000,50000,100000};
    int index=-1;
    QString username="ABC";
};

#endif // CHARGEIN_H
