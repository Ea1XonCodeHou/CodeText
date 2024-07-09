/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox_num;
    QLineEdit *lineEdit_price;
    QTableWidget *tableWidget_history;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_page;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_code;
    QLabel *label_5;
    QLineEdit *lineEdit_name;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1500, 798);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setMaximumSize(QSize(1500, 1500));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 640, 61, 19));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 690, 41, 19));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 740, 41, 19));
        spinBox_num = new QSpinBox(Widget);
        spinBox_num->setObjectName("spinBox_num");
        spinBox_num->setGeometry(QRect(120, 690, 81, 25));
        spinBox_num->setMinimum(1);
        lineEdit_price = new QLineEdit(Widget);
        lineEdit_price->setObjectName("lineEdit_price");
        lineEdit_price->setGeometry(QRect(110, 740, 81, 25));
        lineEdit_price->setReadOnly(true);
        tableWidget_history = new QTableWidget(Widget);
        tableWidget_history->setObjectName("tableWidget_history");
        tableWidget_history->setGeometry(QRect(830, 60, 561, 451));
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 80, 601, 381));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 530, 101, 28));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(410, 530, 93, 28));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(540, 530, 69, 19));
        label_page = new QLabel(Widget);
        label_page->setObjectName("label_page");
        label_page->setGeometry(QRect(620, 530, 69, 19));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 580, 93, 28));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(420, 580, 93, 28));
        lineEdit_code = new QLineEdit(Widget);
        lineEdit_code->setObjectName("lineEdit_code");
        lineEdit_code->setGeometry(QRect(120, 640, 91, 25));
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 640, 69, 19));
        lineEdit_name = new QLineEdit(Widget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(320, 640, 111, 25));
        lineEdit_name->setReadOnly(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\344\273\243\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\225\260\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\273\267\346\240\274", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\351\241\265\346\225\260:", nullptr));
        label_page->setText(QCoreApplication::translate("Widget", "1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\210\260\345\260\276\351\241\265", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\345\210\260\351\246\226\351\241\265", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
