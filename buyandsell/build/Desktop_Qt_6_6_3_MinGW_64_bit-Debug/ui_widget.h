/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableView *tableView;
    QPushButton *confirmButton;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_code;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_price;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *chooseBox;
    QLineEdit *lineEdit;
    QListView *listView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 620);
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(140, 0, 321, 681));
        confirmButton = new QPushButton(Widget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(570, 400, 80, 20));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(600, 360, 111, 20));
        QFont font;
        font.setPointSize(11);
        label_4->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(510, 200, 221, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");

        horizontalLayout->addWidget(backButton);

        forwardButton = new QPushButton(layoutWidget);
        forwardButton->setObjectName("forwardButton");

        horizontalLayout->addWidget(forwardButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        lineEdit_code = new QLineEdit(layoutWidget);
        lineEdit_code->setObjectName("lineEdit_code");

        horizontalLayout_2->addWidget(lineEdit_code);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout_3->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_price = new QLineEdit(layoutWidget);
        lineEdit_price->setObjectName("lineEdit_price");

        horizontalLayout_4->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        chooseBox = new QComboBox(layoutWidget);
        chooseBox->setObjectName("chooseBox");

        horizontalLayout_5->addWidget(chooseBox);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        listView = new QListView(Widget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(-5, 1, 821, 841));
        listView->setStyleSheet(QString::fromUtf8("background-image: url(:/picture/background.png);"));
        listView->raise();
        tableView->raise();
        confirmButton->raise();
        label_4->raise();
        layoutWidget->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        confirmButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\357\274\210\350\276\223\345\205\245\350\202\241\347\245\250\344\273\275\346\225\260\357\274\211", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\202\241\347\245\250\344\273\243\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\344\273\267\346\240\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
