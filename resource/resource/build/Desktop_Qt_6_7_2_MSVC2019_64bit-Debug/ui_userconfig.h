/********************************************************************************
** Form generated from reading UI file 'userconfig.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCONFIG_H
#define UI_USERCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userconfig
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *userconfig)
    {
        if (userconfig->objectName().isEmpty())
            userconfig->setObjectName("userconfig");
        userconfig->resize(470, 356);
        pushButton = new QPushButton(userconfig);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 140, 93, 28));
        pushButton_2 = new QPushButton(userconfig);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 140, 93, 28));

        retranslateUi(userconfig);

        QMetaObject::connectSlotsByName(userconfig);
    } // setupUi

    void retranslateUi(QWidget *userconfig)
    {
        userconfig->setWindowTitle(QCoreApplication::translate("userconfig", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("userconfig", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userconfig", "\350\264\246\346\210\267\345\205\205\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userconfig: public Ui_userconfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCONFIG_H
