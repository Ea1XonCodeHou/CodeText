/********************************************************************************
** Form generated from reading UI file 'loginframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFRAME_H
#define UI_LOGINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginframe
{
public:
    QPushButton *login;
    QPushButton *register_2;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *loginframe)
    {
        if (loginframe->objectName().isEmpty())
            loginframe->setObjectName("loginframe");
        loginframe->resize(480, 462);
        login = new QPushButton(loginframe);
        login->setObjectName("login");
        login->setGeometry(QRect(190, 240, 93, 28));
        register_2 = new QPushButton(loginframe);
        register_2->setObjectName("register_2");
        register_2->setGeometry(QRect(190, 300, 93, 28));
        lineEdit_id = new QLineEdit(loginframe);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(190, 140, 113, 25));
        lineEdit_password = new QLineEdit(loginframe);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(190, 190, 113, 25));
        label = new QLabel(loginframe);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 140, 69, 19));
        label_2 = new QLabel(loginframe);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 190, 69, 19));

        retranslateUi(loginframe);

        QMetaObject::connectSlotsByName(loginframe);
    } // setupUi

    void retranslateUi(QWidget *loginframe)
    {
        loginframe->setWindowTitle(QCoreApplication::translate("loginframe", "Form", nullptr));
        login->setText(QCoreApplication::translate("loginframe", "\347\231\273\345\275\225", nullptr));
        register_2->setText(QCoreApplication::translate("loginframe", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("loginframe", "id", nullptr));
        label_2->setText(QCoreApplication::translate("loginframe", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginframe: public Ui_loginframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFRAME_H
