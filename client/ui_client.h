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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(885, 657);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(640, 70, 45, 19));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(13, 448, 60, 19));
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(80, 448, 461, 25));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 480, 401, 81));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 130, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: linear-gradient(120deg, #a1c4fd 0%, #c2e9fb 100%);"));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 20, 581, 411));
        textEdit->setReadOnly(true);
        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(710, 60, 171, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\201\212\345\244\251\345\206\205\345\256\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
