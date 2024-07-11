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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
<<<<<<< HEAD
    QTableView *tableView;
    QPushButton *confirmButton;
=======
<<<<<<< HEAD
    QTableView *tableView;
    QPushButton *confirmButton;
=======
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *forwardButton;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e81c1a9 (第二次show)
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchLabel;
    QComboBox *serachBox;
    QHBoxLayout *horizontalLayout_3;
<<<<<<< HEAD
=======
=======
    QTableView *tableView;
    QPushButton *confirmButton;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_code;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_price;
    QHBoxLayout *horizontalLayout_4;
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)
    QComboBox *chooseBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e81c1a9 (第二次show)
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(40, 10, 256, 192));
        confirmButton = new QPushButton(Widget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(120, 400, 80, 20));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 220, 251, 22));
<<<<<<< HEAD
=======
=======
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(450, 370, 251, 22));
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");

        horizontalLayout->addWidget(backButton);

        forwardButton = new QPushButton(layoutWidget);
        forwardButton->setObjectName("forwardButton");

        horizontalLayout->addWidget(forwardButton);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e81c1a9 (第二次show)
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 280, 251, 81));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        searchLabel = new QLabel(layoutWidget1);
        searchLabel->setObjectName("searchLabel");

        horizontalLayout_2->addWidget(searchLabel);

        serachBox = new QComboBox(layoutWidget1);
        serachBox->setObjectName("serachBox");

        horizontalLayout_2->addWidget(serachBox);
<<<<<<< HEAD
=======
=======
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 20, 351, 571));
        confirmButton = new QPushButton(Widget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(530, 300, 80, 20));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 270, 201, 22));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(450, 140, 251, 117));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_code = new QLineEdit(widget);
        lineEdit_code->setObjectName("lineEdit_code");

        horizontalLayout_2->addWidget(lineEdit_code);
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)


        verticalLayout->addLayout(horizontalLayout_2);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e81c1a9 (第二次show)
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        chooseBox = new QComboBox(layoutWidget1);
        chooseBox->setObjectName("chooseBox");

        horizontalLayout_3->addWidget(chooseBox);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);
<<<<<<< HEAD
=======
=======
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout_5->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        lineEdit_price = new QLineEdit(widget);
        lineEdit_price->setObjectName("lineEdit_price");

        horizontalLayout_6->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        chooseBox = new QComboBox(widget);
        chooseBox->setObjectName("chooseBox");

        horizontalLayout_4->addWidget(chooseBox);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e81c1a9 (第二次show)
        confirmButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        searchLabel->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242\350\202\241\347\245\250\357\274\232", nullptr));
<<<<<<< HEAD
=======
=======
        backButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        confirmButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("Widget", "(\344\273\245\344\270\212\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\344\273\275\346\225\260)", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242\350\202\241\347\245\250\344\273\243\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "\350\202\241\347\245\250\345\275\223\345\211\215\344\273\267\346\240\274\357\274\232", nullptr));
>>>>>>> b651e12 (第二次show)
>>>>>>> e81c1a9 (第二次show)
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
