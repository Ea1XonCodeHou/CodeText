/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
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
    QLabel *label_pageInfo;
    QTableView *tableView_singleRow;
    QLineEdit *lineEdit_pageJump;
    QPushButton *pageJumpButton;
    QLineEdit *lineEdit;
    QComboBox *chooseBox;
    QWidget *widget;
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1054, 793);
        Widget->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(70, 80, 611, 581));
        confirmButton = new QPushButton(Widget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(710, 530, 121, 41));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(900, 480, 141, 31));
        QFont font;
        font.setPointSize(11);
        font.setItalic(true);
        label_4->setFont(font);
        label_pageInfo = new QLabel(Widget);
        label_pageInfo->setObjectName("label_pageInfo");
        label_pageInfo->setGeometry(QRect(270, 20, 221, 31));
        label_pageInfo->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));
        tableView_singleRow = new QTableView(Widget);
        tableView_singleRow->setObjectName("tableView_singleRow");
        tableView_singleRow->setGeometry(QRect(700, 130, 321, 101));
        lineEdit_pageJump = new QLineEdit(Widget);
        lineEdit_pageJump->setObjectName("lineEdit_pageJump");
        lineEdit_pageJump->setGeometry(QRect(220, 690, 231, 51));
        pageJumpButton = new QPushButton(Widget);
        pageJumpButton->setObjectName("pageJumpButton");
        pageJumpButton->setGeometry(QRect(480, 690, 111, 51));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(790, 480, 101, 31));
        chooseBox = new QComboBox(Widget);
        chooseBox->setObjectName("chooseBox");
        chooseBox->setGeometry(QRect(710, 480, 71, 31));
        chooseBox->setMinimumSize(QSize(62, 22));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(710, 240, 291, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        backButton = new QPushButton(widget);
        backButton->setObjectName("backButton");
        QFont font1;
        font1.setPointSize(9);
        backButton->setFont(font1);

        horizontalLayout->addWidget(backButton);

        forwardButton = new QPushButton(widget);
        forwardButton->setObjectName("forwardButton");

        horizontalLayout->addWidget(forwardButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        lineEdit_code = new QLineEdit(widget);
        lineEdit_code->setObjectName("lineEdit_code");

        horizontalLayout_2->addWidget(lineEdit_code);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout_3->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_price = new QLineEdit(widget);
        lineEdit_price->setObjectName("lineEdit_price");

        horizontalLayout_4->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\344\271\260\345\215\226\347\225\214\351\235\242", nullptr));
        confirmButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\357\274\210\350\276\223\345\205\245\350\202\241\347\245\250\344\273\275\346\225\260\357\274\211", nullptr));
        label_pageInfo->setText(QString());
        pageJumpButton->setText(QCoreApplication::translate("Widget", "\350\267\263\350\275\254", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\205\255\344\275\215\350\202\241\347\245\250\344\273\243\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\344\273\267\346\240\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
