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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableView *tableView;
    QLabel *userpicLabel;
    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *AllMoneyLabel;
    QLabel *label;
    QLabel *houseLabel;
    QLabel *WinLoseLabel;
    QLabel *MarketValueLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(190, 121, 601, 461));
        userpicLabel = new QLabel(Widget);
        userpicLabel->setObjectName("userpicLabel");
        userpicLabel->setGeometry(QRect(40, 100, 101, 101));
        idLabel = new QLabel(Widget);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(10, 270, 171, 41));
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 246, 255);\n"
"border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.5); /* \350\256\276\347\275\256\351\230\264\345\275\261 */"));
        nameLabel = new QLabel(Widget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(10, 190, 171, 41));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 246, 255);\n"
"border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.5); /* \350\256\276\347\275\256\351\230\264\345\275\261 */"));
        AllMoneyLabel = new QLabel(Widget);
        AllMoneyLabel->setObjectName("AllMoneyLabel");
        AllMoneyLabel->setGeometry(QRect(10, 350, 171, 41));
        AllMoneyLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.5); /* \350\256\276\347\275\256\351\230\264\345\275\261 */background-color: rgb(239, 246, 255)"));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 30, 271, 91));
        label->setStyleSheet(QString::fromUtf8(""));
        houseLabel = new QLabel(Widget);
        houseLabel->setObjectName("houseLabel");
        houseLabel->setGeometry(QRect(380, 40, 101, 81));
        WinLoseLabel = new QLabel(Widget);
        WinLoseLabel->setObjectName("WinLoseLabel");
        WinLoseLabel->setGeometry(QRect(10, 510, 171, 41));
        WinLoseLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.5); /* \350\256\276\347\275\256\351\230\264\345\275\261 */background-color: rgb(239, 246, 255)"));
        MarketValueLabel = new QLabel(Widget);
        MarketValueLabel->setObjectName("MarketValueLabel");
        MarketValueLabel->setGeometry(QRect(10, 430, 171, 41));
        MarketValueLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 3px 3px 5px rgba(0, 0, 0, 0.5); /* \350\256\276\347\275\256\351\230\264\345\275\261 */background-color: rgb(239, 246, 255)"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        userpicLabel->setText(QString());
        idLabel->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\264\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        nameLabel->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        AllMoneyLabel->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\265\204\344\272\247\357\274\232</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\346\226\260\351\255\217'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:33pt; color: #000000;\">\350\257\201\345\210\270\346\214\201\344\273\223</span></p></body></html>", nullptr));
        houseLabel->setText(QString());
        WinLoseLabel->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\347\233\210\344\272\217\357\274\232</span></p></body></html>", nullptr));
        MarketValueLabel->setText(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\270\202\345\200\274\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
