/********************************************************************************
** Form generated from reading UI file 'signupframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFRAME_H
#define UI_SIGNUPFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_signupframe
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_test;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    mylabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *ChangePage;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *signupframe)
    {
        if (signupframe->objectName().isEmpty())
            signupframe->setObjectName("signupframe");
        signupframe->resize(379, 447);
        formLayout = new QFormLayout(signupframe);
        formLayout->setObjectName("formLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(signupframe);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 57, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, -1, -1, 10);
        lineEdit_id = new QLineEdit(signupframe);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setMinimumSize(QSize(0, 35));
        lineEdit_id->setStyleSheet(QString::fromUtf8("border-radius: 11px;\n"
"border: 1px solid #000000;\n"
"border-color: rgb(84, 84, 84)"));

        verticalLayout_2->addWidget(lineEdit_id);

        lineEdit_password = new QLineEdit(signupframe);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setMinimumSize(QSize(0, 35));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius: 11px;\n"
"border: 1px solid #000000;\n"
"border-color: rgb(84, 84, 84)"));

        verticalLayout_2->addWidget(lineEdit_password);

        lineEdit_test = new QLineEdit(signupframe);
        lineEdit_test->setObjectName("lineEdit_test");
        lineEdit_test->setMinimumSize(QSize(0, 35));
        lineEdit_test->setStyleSheet(QString::fromUtf8("border-radius: 11px;\n"
"border: 1px solid #000000;\n"
"border-color: rgb(84, 84, 84)"));

        verticalLayout_2->addWidget(lineEdit_test);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_2 = new mylabel(signupframe);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(200, 80));
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, -1, 10, -1);
        pushButton = new QPushButton(signupframe);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15px;\n"
"	border: 0px;\n"
"	font-size:11pt;\n"
"	font-weight:bold;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:2, stop:0 rgb(255, 53, 56), stop:1 rgb(56, 0, 197));\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.5, stop:0 rgb(116, 0, 0), stop:1 rgb(184, 0, 0));\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ChangePage = new QPushButton(signupframe);
        ChangePage->setObjectName("ChangePage");
        ChangePage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0;\n"
"    background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(194, 194, 194);\n"
"}\n"
""));

        horizontalLayout->addWidget(ChangePage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_3);


        retranslateUi(signupframe);

        QMetaObject::connectSlotsByName(signupframe);
    } // setupUi

    void retranslateUi(QWidget *signupframe)
    {
        signupframe->setWindowTitle(QCoreApplication::translate("signupframe", "Form", nullptr));
        label->setText(QCoreApplication::translate("signupframe", "<html><head/><body><p><span style=\" font-size:18pt;\">\346\263\250 \345\206\214</span></p></body></html>", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("signupframe", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("signupframe", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201...", nullptr));
        lineEdit_test->setText(QString());
        lineEdit_test->setPlaceholderText(QCoreApplication::translate("signupframe", "\350\276\223\345\205\245\345\233\276\347\211\207\351\252\214\350\257\201\347\240\201...", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("signupframe", "\346\263\250 \345\206\214", nullptr));
        ChangePage->setText(QCoreApplication::translate("signupframe", "<-\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupframe: public Ui_signupframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFRAME_H
