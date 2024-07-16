#ifndef SIGNUPFRAME_H
#define SIGNUPFRAME_H
#include<QString>
extern  QString verifycode;
#include <QWidget>

namespace Ui {
class signupframe;
}

class signupframe : public QWidget
{
    Q_OBJECT

public:

    Ui::signupframe *ui;
    explicit signupframe(QWidget *parent = nullptr);
    ~signupframe();
    void create_user_database(const QString &username,const QString &password);
    void connent_mysql();
    void update_pic();
    void getverifycode();

private slots:
    void on_pushButton_clicked();

private:
};

#endif // SIGNUPFRAME_H
