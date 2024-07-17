/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_monitor
{
public:
    QTableView *tableView;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QDateEdit *dateEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    mylabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *monitor)
    {
        if (monitor->objectName().isEmpty())
            monitor->setObjectName("monitor");
        monitor->resize(1167, 694);
        tableView = new QTableView(monitor);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(70, 130, 741, 471));
        label_2 = new QLabel(monitor);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 50, 41, 19));
        dateEdit = new QDateEdit(monitor);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(150, 44, 131, 31));
        label_3 = new QLabel(monitor);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 50, 31, 19));
        dateEdit_2 = new QDateEdit(monitor);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(340, 44, 141, 31));
        label_4 = new QLabel(monitor);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 100, 41, 19));
        lineEdit = new QLineEdit(monitor);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 100, 341, 25));
        pushButton = new QPushButton(monitor);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(530, 80, 111, 28));
        groupBox = new QGroupBox(monitor);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(860, 240, 291, 401));
        label = new mylabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 240, 181, 61));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 70, 69, 19));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 130, 61, 19));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(80, 70, 161, 25));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 130, 151, 25));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 190, 91, 19));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(110, 190, 131, 25));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 330, 93, 28));

        retranslateUi(monitor);

        QMetaObject::connectSlotsByName(monitor);
    } // setupUi

    void retranslateUi(QWidget *monitor)
    {
        monitor->setWindowTitle(QCoreApplication::translate("monitor", "monitor", nullptr));
        label_2->setText(QCoreApplication::translate("monitor", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("monitor", "\345\210\260", nullptr));
        label_4->setText(QCoreApplication::translate("monitor", "\346\217\217\350\277\260:", nullptr));
        pushButton->setText(QCoreApplication::translate("monitor", "\346\237\245\350\257\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("monitor", "\344\277\256\346\224\271\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("monitor", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("monitor", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("monitor", "\345\233\276\347\211\207\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("monitor", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monitor: public Ui_monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H
