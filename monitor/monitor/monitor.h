#ifndef MONITOR_H
#define MONITOR_H
#include <QWidget>
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QRandomGenerator>
#include<QMessageBox>
#include<QDate>
#include<QRegularExpression>
#include<QFile>
#include<QFileDialog>
extern QString verifycode;
QT_BEGIN_NAMESPACE
namespace Ui {
class monitor;
}
QT_END_NAMESPACE

class monitor : public QWidget
{
    Q_OBJECT

public:
    monitor(QWidget *parent = nullptr);
    ~monitor();

private slots:
    void on_pushButton_2_clicked();
    void download_pic();
    void on_pushButton_clicked();

private:
    Ui::monitor *ui;
    void connect_to_mysql();
    void getverifycode();
    void update_pic();
    void connect_to_userinfo();
    QSqlDatabase db2;
    QSqlTableModel* model;
};
#endif // MONITOR_H
