/********************************************************************************
** Form generated from reading UI file 'loginframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFRAME_H
#define UI_LOGINFRAME_H

#include <QtCore/QLocale>
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

QT_BEGIN_NAMESPACE

class Ui_loginframe
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_password;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *login;
    QPushButton *register_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *loginframe)
    {
        if (loginframe->objectName().isEmpty())
            loginframe->setObjectName("loginframe");
        loginframe->resize(368, 544);
        loginframe->setStyleSheet(QString::fromUtf8("#loginframe{background-color: rgb(255, 255, 255);}"));
        formLayout = new QFormLayout(loginframe);
        formLayout->setObjectName("formLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(loginframe);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("border-image:url(:/new/prefix1/resource/ais92-gjqqx-001.ico)"));
        label->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(loginframe);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setMaximumSize(QSize(100, 100));
        label_2->setStyleSheet(QString::fromUtf8("border-image:url(:/new/prefix1/resource/acumg-ybkhb-001.ico)"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 3);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, -1, 15, -1);
        lineEdit_id = new QLineEdit(loginframe);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        font.setHintingPreference(QFont::PreferDefaultHinting);
        lineEdit_id->setFont(font);
        lineEdit_id->setStyleSheet(QString::fromUtf8("border-radius: 11px;\n"
"border: 1px solid #000000;\n"
"border-color: rgb(84, 84, 84)"));

        verticalLayout_2->addWidget(lineEdit_id);

        lineEdit_password = new QLineEdit(loginframe);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setMinimumSize(QSize(0, 40));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius: 11px;\n"
"border: 1px solid #000000;\n"
"border-color: rgb(84, 84, 84)"));

        verticalLayout_2->addWidget(lineEdit_password);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, -1, 15, -1);
        login = new QPushButton(loginframe);
        login->setObjectName("login");
        login->setMinimumSize(QSize(0, 30));
        login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout->addWidget(login);

        register_2 = new QPushButton(loginframe);
        register_2->setObjectName("register_2");
        register_2->setMinimumSize(QSize(0, 30));
        register_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	border-radius: 15px;\n"
"	border: 3px solid #000000;\n"
"	border-color: rgb(223, 65, 67);\n"
"	font-size:11pt;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:rgb(223, 65, 67);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(register_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_3->addLayout(verticalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_3);


        retranslateUi(loginframe);

        QMetaObject::connectSlotsByName(loginframe);
    } // setupUi

    void retranslateUi(QWidget *loginframe)
    {
        loginframe->setWindowTitle(QCoreApplication::translate("loginframe", "\347\231\273\345\275\225", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("loginframe", "<html><head/><body><p><br/></p></body></html>", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("loginframe", "\347\224\250\346\210\267\345\220\215", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_password->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("loginframe", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201...", nullptr));
        login->setText(QCoreApplication::translate("loginframe", "\347\231\273 \345\275\225", nullptr));
        register_2->setText(QCoreApplication::translate("loginframe", "\346\263\250 \345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginframe: public Ui_loginframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFRAME_H
