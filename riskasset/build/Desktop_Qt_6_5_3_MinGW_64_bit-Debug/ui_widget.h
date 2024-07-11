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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *textBrowser;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *nextPageButton;
    QPushButton *previousPageButton;
    QPushButton *firstPageButton;
    QPushButton *lastPageButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(767, 647);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(420, 350, 321, 291));
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 30, 711, 241));
        tableView->setMinimumSize(QSize(711, 0));
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::DashLine);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setMinimumSectionSize(30);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(520, 300, 121, 41));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 350, 281, 161));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 520, 161, 111));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 430, 241, 211));
        nextPageButton = new QPushButton(Widget);
        nextPageButton->setObjectName("nextPageButton");
        nextPageButton->setGeometry(QRect(19, 300, 81, 31));
        previousPageButton = new QPushButton(Widget);
        previousPageButton->setObjectName("previousPageButton");
        previousPageButton->setGeometry(QRect(120, 300, 81, 31));
        firstPageButton = new QPushButton(Widget);
        firstPageButton->setObjectName("firstPageButton");
        firstPageButton->setGeometry(QRect(220, 300, 81, 31));
        lastPageButton = new QPushButton(Widget);
        lastPageButton->setObjectName("lastPageButton");
        lastPageButton->setGeometry(QRect(320, 300, 81, 31));

        retranslateUi(Widget);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\237\245\347\234\213\344\272\244\346\230\223\345\216\206\345\217\262", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\243\216\351\231\251\350\257\204\344\274\260", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        nextPageButton->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        previousPageButton->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        firstPageButton->setText(QCoreApplication::translate("Widget", "\351\246\226\351\241\265", nullptr));
        lastPageButton->setText(QCoreApplication::translate("Widget", "\346\234\253\345\260\276\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
