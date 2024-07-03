/********************************************************************************
** Form generated from reading UI file 'mainprogramwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPROGRAMWINDOW_H
#define UI_MAINPROGRAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainprogramWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainprogramWindow)
    {
        if (MainprogramWindow->objectName().isEmpty())
            MainprogramWindow->setObjectName("MainprogramWindow");
        MainprogramWindow->resize(800, 600);
        centralwidget = new QWidget(MainprogramWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 130, 161, 101));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 130, 161, 101));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(560, 130, 161, 101));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(70, 320, 161, 101));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(310, 320, 161, 101));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(560, 320, 161, 101));
        MainprogramWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainprogramWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainprogramWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainprogramWindow);
        statusBar->setObjectName("statusBar");
        MainprogramWindow->setStatusBar(statusBar);

        retranslateUi(MainprogramWindow);

        QMetaObject::connectSlotsByName(MainprogramWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainprogramWindow)
    {
        MainprogramWindow->setWindowTitle(QCoreApplication::translate("MainprogramWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainprogramWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainprogramWindow: public Ui_MainprogramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPROGRAMWINDOW_H
