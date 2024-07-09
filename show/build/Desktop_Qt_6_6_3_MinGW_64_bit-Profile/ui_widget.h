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
    QTableView *tableView;
    QPushButton *confirmButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchLabel;
    QComboBox *serachBox;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *chooseBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(40, 10, 256, 192));
        confirmButton = new QPushButton(Widget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(120, 400, 80, 20));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 220, 251, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");

        horizontalLayout->addWidget(backButton);

        forwardButton = new QPushButton(layoutWidget);
        forwardButton->setObjectName("forwardButton");

        horizontalLayout->addWidget(forwardButton);

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


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        chooseBox = new QComboBox(layoutWidget1);
        chooseBox->setObjectName("chooseBox");

        horizontalLayout_3->addWidget(chooseBox);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        confirmButton->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        searchLabel->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242\350\202\241\347\245\250\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
