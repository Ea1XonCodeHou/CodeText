/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 370, 181, 28));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(550, 270, 141, 28));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 130, 231, 25));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 250, 251, 25));
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(550, 170, 181, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
