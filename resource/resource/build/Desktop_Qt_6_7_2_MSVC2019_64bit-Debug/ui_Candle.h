/********************************************************************************
** Form generated from reading UI file 'Candle.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDLE_H
#define UI_CANDLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Candle
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_profit;
    QLabel *label_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_maxbuyin;
    QLabel *label_5;
    QLabel *label_maxsellout;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *label_arrow;
    QLabel *label_close;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLabel *label_date;
    QTableView *tableView_profit;
    QTableView *tableView;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_totalmoney;
    QLabel *label_title;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_sellout;
    QPushButton *pushButton_buyin;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Candle)
    {
        if (Candle->objectName().isEmpty())
            Candle->setObjectName("Candle");
        Candle->resize(1143, 889);
        pushButton = new QPushButton(Candle);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 420, 231, 131));
        pushButton->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));
        layoutWidget = new QWidget(Candle);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 641, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(layoutWidget);
        widget->setObjectName("widget");

        verticalLayout->addWidget(widget);

        layoutWidget_2 = new QWidget(Candle);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(670, 140, 321, 28));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_profit = new QLabel(layoutWidget_2);
        label_profit->setObjectName("label_profit");

        horizontalLayout_5->addWidget(label_profit);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_5->addWidget(label_2);

        layoutWidget_3 = new QWidget(Candle);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(670, 270, 321, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        label_maxbuyin = new QLabel(layoutWidget_3);
        label_maxbuyin->setObjectName("label_maxbuyin");
        label_maxbuyin->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_3->addWidget(label_maxbuyin);

        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        label_maxsellout = new QLabel(layoutWidget_3);
        label_maxsellout->setObjectName("label_maxsellout");
        label_maxsellout->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_3->addWidget(label_maxsellout);

        layoutWidget_4 = new QWidget(Candle);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(670, 90, 341, 34));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_4);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        label_arrow = new QLabel(layoutWidget_4);
        label_arrow->setObjectName("label_arrow");
        label_arrow->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_4->addWidget(label_arrow);

        label_close = new QLabel(layoutWidget_4);
        label_close->setObjectName("label_close");
        label_close->setStyleSheet(QString::fromUtf8("font: 17pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_4->addWidget(label_close);

        layoutWidget_5 = new QWidget(Candle);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(670, 220, 321, 33));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(label_7);

        label_date = new QLabel(layoutWidget_5);
        label_date->setObjectName("label_date");
        label_date->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_7->addWidget(label_date);

        tableView_profit = new QTableView(Candle);
        tableView_profit->setObjectName("tableView_profit");
        tableView_profit->setGeometry(QRect(450, 760, 431, 61));
        tableView_profit->setStyleSheet(QString::fromUtf8("\n"
"gridline-color: rgb(117, 177, 255);"));
        tableView_profit->horizontalHeader()->setCascadingSectionResizes(true);
        tableView = new QTableView(Candle);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(340, 420, 721, 301));
        tableView->setStyleSheet(QString::fromUtf8("gridline-color: rgb(229, 229, 229)"));
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::DashLine);
        layoutWidget_6 = new QWidget(Candle);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(50, 590, 240, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget_6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_6);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget_6);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout->addWidget(lineEdit);

        layoutWidget_7 = new QWidget(Candle);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(670, 180, 321, 28));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_7);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        label_totalmoney = new QLabel(layoutWidget_7);
        label_totalmoney->setObjectName("label_totalmoney");
        label_totalmoney->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));

        horizontalLayout_6->addWidget(label_totalmoney);

        label_title = new QLabel(Candle);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(700, 20, 351, 81));
        layoutWidget_8 = new QWidget(Candle);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(20, 660, 281, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_sellout = new QPushButton(layoutWidget_8);
        pushButton_sellout->setObjectName("pushButton_sellout");
        pushButton_sellout->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton_sellout);

        pushButton_buyin = new QPushButton(layoutWidget_8);
        pushButton_buyin->setObjectName("pushButton_buyin");
        pushButton_buyin->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton_buyin);

        pushButton_2 = new QPushButton(Candle);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(670, 320, 301, 61));

        retranslateUi(Candle);

        QMetaObject::connectSlotsByName(Candle);
    } // setupUi

    void retranslateUi(QWidget *Candle)
    {
        Candle->setWindowTitle(QCoreApplication::translate("Candle", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Candle", "\346\250\241\346\213\237\344\270\213\344\270\200\345\244\251", nullptr));
        label_profit->setText(QCoreApplication::translate("Candle", "\347\233\210\344\272\217\357\274\232", nullptr));
        label_2->setText(QString());
        label_4->setText(QCoreApplication::translate("Candle", "\346\234\200\345\244\247\345\217\257\344\271\260\357\274\232", nullptr));
        label_maxbuyin->setText(QString());
        label_5->setText(QCoreApplication::translate("Candle", "\346\234\200\345\244\247\345\217\257\345\215\226\357\274\232", nullptr));
        label_maxsellout->setText(QString());
        label->setText(QCoreApplication::translate("Candle", "\346\224\266\347\233\230\344\273\267\357\274\232", nullptr));
        label_arrow->setText(QString());
        label_close->setText(QString());
        label_7->setText(QCoreApplication::translate("Candle", "\345\275\223\345\211\215\346\227\245\346\234\237\357\274\232", nullptr));
        label_date->setText(QString());
        label_3->setText(QCoreApplication::translate("Candle", "\344\272\244\346\230\223\350\202\241\346\225\260", nullptr));
        lineEdit->setText(QCoreApplication::translate("Candle", "100", nullptr));
        label_6->setText(QCoreApplication::translate("Candle", "\345\275\223\345\211\215\350\265\204\344\272\247\357\274\232", nullptr));
        label_totalmoney->setText(QString());
        label_title->setText(QCoreApplication::translate("Candle", "\346\250\241\346\213\237\347\202\222\350\202\241-A\350\202\241", nullptr));
        pushButton_sellout->setText(QCoreApplication::translate("Candle", "\345\215\226\345\207\272", nullptr));
        pushButton_buyin->setText(QCoreApplication::translate("Candle", "\344\271\260\345\205\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Candle", "\345\220\257\347\224\250\350\207\252\345\212\250\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Candle: public Ui_Candle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDLE_H
