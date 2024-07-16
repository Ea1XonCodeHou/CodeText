/********************************************************************************
** Form generated from reading UI file 'recharge.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHARGE_H
#define UI_RECHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recharge
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *turnback;

    void setupUi(QWidget *recharge)
    {
        if (recharge->objectName().isEmpty())
            recharge->setObjectName("recharge");
        recharge->resize(310, 425);
        label = new QLabel(recharge);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 130, 69, 19));
        label_3 = new QLabel(recharge);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 200, 69, 19));
        label_4 = new QLabel(recharge);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 260, 69, 19));
        lineEdit = new QLineEdit(recharge);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 130, 113, 25));
        lineEdit_2 = new QLineEdit(recharge);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 200, 113, 25));
        lineEdit_3 = new QLineEdit(recharge);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 260, 113, 25));
        pushButton = new QPushButton(recharge);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 350, 93, 28));
        turnback = new QPushButton(recharge);
        turnback->setObjectName("turnback");
        turnback->setGeometry(QRect(20, 340, 93, 28));

        retranslateUi(recharge);

        QMetaObject::connectSlotsByName(recharge);
    } // setupUi

    void retranslateUi(QWidget *recharge)
    {
        recharge->setWindowTitle(QCoreApplication::translate("recharge", "recharge", nullptr));
        label->setText(QCoreApplication::translate("recharge", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("recharge", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("recharge", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("recharge", "\347\241\256\345\256\232", nullptr));
        turnback->setText(QCoreApplication::translate("recharge", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recharge: public Ui_recharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHARGE_H
