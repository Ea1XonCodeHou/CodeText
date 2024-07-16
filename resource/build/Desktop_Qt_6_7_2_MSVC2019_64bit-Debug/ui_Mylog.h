/********************************************************************************
** Form generated from reading UI file 'Mylog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOG_H
#define UI_MYLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mylog
{
public:
    QLabel *userpicLabel;
    QPushButton *chargein;
    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *MarketValueLabel;
    QTableView *tableView;
    QLabel *houseLabel;
    QLabel *label;
    QLabel *AllMoneyLabel;
    QLabel *WinLoseLabel;
    QPushButton *setuserinfo;

    void setupUi(QWidget *Mylog)
    {
        if (Mylog->objectName().isEmpty())
            Mylog->setObjectName("Mylog");
        Mylog->resize(769, 544);
        userpicLabel = new QLabel(Mylog);
        userpicLabel->setObjectName("userpicLabel");
        userpicLabel->setGeometry(QRect(70, 360, 101, 101));
        chargein = new QPushButton(Mylog);
        chargein->setObjectName("chargein");
        chargein->setGeometry(QRect(610, 100, 93, 28));
        idLabel = new QLabel(Mylog);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(10, 120, 171, 41));
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 246, 255);\n"
"border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */"));
        nameLabel = new QLabel(Mylog);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(30, 60, 171, 41));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 246, 255);\n"
"border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px;"));
        MarketValueLabel = new QLabel(Mylog);
        MarketValueLabel->setObjectName("MarketValueLabel");
        MarketValueLabel->setGeometry(QRect(30, 230, 171, 41));
        MarketValueLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"background-color: rgb(239, 246, 255)"));
        tableView = new QTableView(Mylog);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(220, 130, 521, 391));
        houseLabel = new QLabel(Mylog);
        houseLabel->setObjectName("houseLabel");
        houseLabel->setGeometry(QRect(30, 320, 161, 81));
        label = new QLabel(Mylog);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 50, 271, 91));
        label->setStyleSheet(QString::fromUtf8(""));
        AllMoneyLabel = new QLabel(Mylog);
        AllMoneyLabel->setObjectName("AllMoneyLabel");
        AllMoneyLabel->setGeometry(QRect(30, 170, 171, 41));
        AllMoneyLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"background-color: rgb(239, 246, 255)"));
        WinLoseLabel = new QLabel(Mylog);
        WinLoseLabel->setObjectName("WinLoseLabel");
        WinLoseLabel->setGeometry(QRect(40, 280, 171, 41));
        WinLoseLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"background-color: rgb(239, 246, 255)"));
        setuserinfo = new QPushButton(Mylog);
        setuserinfo->setObjectName("setuserinfo");
        setuserinfo->setGeometry(QRect(510, 80, 93, 28));

        retranslateUi(Mylog);

        QMetaObject::connectSlotsByName(Mylog);
    } // setupUi

    void retranslateUi(QWidget *Mylog)
    {
        Mylog->setWindowTitle(QCoreApplication::translate("Mylog", "Widget", nullptr));
        userpicLabel->setText(QString());
        chargein->setText(QCoreApplication::translate("Mylog", "\345\205\205\345\200\274", nullptr));
        idLabel->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\264\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        nameLabel->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        MarketValueLabel->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\270\202\345\200\274\357\274\232</span></p></body></html>", nullptr));
        houseLabel->setText(QString());
        label->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\346\226\260\351\255\217'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:33pt; color: #000000;\">\350\257\201\345\210\270\346\214\201\344\273\223</span></p></body></html>", nullptr));
        AllMoneyLabel->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\265\204\344\272\247\357\274\232</span></p></body></html>", nullptr));
        WinLoseLabel->setText(QCoreApplication::translate("Mylog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\347\233\210\344\272\217\357\274\232</span></p></body></html>", nullptr));
        setuserinfo->setText(QCoreApplication::translate("Mylog", "\344\277\256\346\224\271\350\264\246\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mylog: public Ui_Mylog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOG_H
