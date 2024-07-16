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

class Ui_client
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLabel *userpicLabel;
    QLabel *label_3;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName("client");
        client->resize(774, 620);
        textEdit = new QTextEdit(client);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 21, 461, 451));
        textEdit->setReadOnly(true);
        label = new QLabel(client);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 170, 91, 61));
        pushButton = new QPushButton(client);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(540, 230, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: linear-gradient(120deg, #a1c4fd 0%, #c2e9fb 100%);"));
        label_2 = new QLabel(client);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 470, 101, 61));
        lineEdit_3 = new QLineEdit(client);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(60, 490, 411, 23));
        pushButton_2 = new QPushButton(client);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 520, 201, 41));
        lineEdit_4 = new QLineEdit(client);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(520, 190, 181, 31));
        userpicLabel = new QLabel(client);
        userpicLabel->setObjectName("userpicLabel");
        userpicLabel->setGeometry(QRect(560, 60, 91, 111));
        label_3 = new QLabel(client);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 360, 211, 181));

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Widget", nullptr));
        label->setText(QCoreApplication::translate("client", "\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton->setText(QCoreApplication::translate("client", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("client", "\350\201\212\345\244\251\345\206\205\345\256\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("client", "\345\217\221\351\200\201", nullptr));
        userpicLabel->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
