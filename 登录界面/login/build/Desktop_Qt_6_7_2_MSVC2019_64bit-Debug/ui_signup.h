/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLabel *label_4;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(386, 483);
        label = new QLabel(signup);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 40, 151, 81));
        label_2 = new QLabel(signup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 150, 69, 19));
        label_3 = new QLabel(signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 200, 69, 19));
        lineEdit = new QLineEdit(signup);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 150, 181, 25));
        lineEdit_2 = new QLineEdit(signup);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 200, 181, 25));
        pushButton = new QPushButton(signup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 320, 141, 28));
        lineEdit_3 = new QLineEdit(signup);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(150, 250, 181, 25));
        label_4 = new QLabel(signup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 250, 91, 20));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("signup", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700; color:#0087c6;\">\346\263\250\345\206\214</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("signup", "\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
