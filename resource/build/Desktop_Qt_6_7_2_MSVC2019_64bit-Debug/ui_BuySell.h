/********************************************************************************
** Form generated from reading UI file 'BuySell.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYSELL_H
#define UI_BUYSELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuySell
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
    QWidget *layoutWidget;
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
    QListView *listView;
    QLabel *NoticeLabel;

    void setupUi(QWidget *BuySell)
    {
        if (BuySell->objectName().isEmpty())
            BuySell->setObjectName("BuySell");
        BuySell->resize(866, 504);
        BuySell->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(BuySell);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 0, 471, 411));
        tableView->setStyleSheet(QString::fromUtf8(""));
        confirmButton = new QPushButton(BuySell);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(570, 380, 121, 41));
        confirmButton->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(BuySell);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(710, 330, 141, 31));
        QFont font;
        font.setPointSize(11);
        font.setItalic(true);
        label_4->setFont(font);
        label_pageInfo = new QLabel(BuySell);
        label_pageInfo->setObjectName("label_pageInfo");
        label_pageInfo->setGeometry(QRect(270, 20, 221, 31));
        label_pageInfo->setStyleSheet(QString::fromUtf8(""));
        tableView_singleRow = new QTableView(BuySell);
        tableView_singleRow->setObjectName("tableView_singleRow");
        tableView_singleRow->setGeometry(QRect(500, 10, 321, 101));
        tableView_singleRow->setStyleSheet(QString::fromUtf8(""));
        lineEdit_pageJump = new QLineEdit(BuySell);
        lineEdit_pageJump->setObjectName("lineEdit_pageJump");
        lineEdit_pageJump->setGeometry(QRect(60, 420, 231, 51));
        lineEdit_pageJump->setStyleSheet(QString::fromUtf8(""));
        pageJumpButton = new QPushButton(BuySell);
        pageJumpButton->setObjectName("pageJumpButton");
        pageJumpButton->setGeometry(QRect(320, 420, 111, 51));
        pageJumpButton->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(BuySell);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(610, 330, 101, 31));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        chooseBox = new QComboBox(BuySell);
        chooseBox->setObjectName("chooseBox");
        chooseBox->setGeometry(QRect(510, 330, 71, 31));
        chooseBox->setMinimumSize(QSize(62, 22));
        layoutWidget = new QWidget(BuySell);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(510, 120, 291, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");
        QFont font1;
        font1.setPointSize(9);
        backButton->setFont(font1);

        horizontalLayout->addWidget(backButton);

        forwardButton = new QPushButton(layoutWidget);
        forwardButton->setObjectName("forwardButton");

        horizontalLayout->addWidget(forwardButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        lineEdit_code = new QLineEdit(layoutWidget);
        lineEdit_code->setObjectName("lineEdit_code");

        horizontalLayout_2->addWidget(lineEdit_code);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout_3->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_price = new QLineEdit(layoutWidget);
        lineEdit_price->setObjectName("lineEdit_price");

        horizontalLayout_4->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_4);

        listView = new QListView(BuySell);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(-75, -19, 1211, 891));
        listView->setStyleSheet(QString::fromUtf8(""));
        NoticeLabel = new QLabel(BuySell);
        NoticeLabel->setObjectName("NoticeLabel");
        NoticeLabel->setGeometry(QRect(840, 530, 201, 41));
        listView->raise();
        tableView->raise();
        confirmButton->raise();
        label_4->raise();
        label_pageInfo->raise();
        tableView_singleRow->raise();
        lineEdit_pageJump->raise();
        pageJumpButton->raise();
        lineEdit->raise();
        chooseBox->raise();
        layoutWidget->raise();
        NoticeLabel->raise();

        retranslateUi(BuySell);

        QMetaObject::connectSlotsByName(BuySell);
    } // setupUi

    void retranslateUi(QWidget *BuySell)
    {
        BuySell->setWindowTitle(QCoreApplication::translate("BuySell", "\350\202\241\347\245\250\344\271\260\345\215\226\347\225\214\351\235\242", nullptr));
        confirmButton->setText(QCoreApplication::translate("BuySell", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("BuySell", "\357\274\210\350\276\223\345\205\245\350\202\241\347\245\250\344\273\275\346\225\260\357\274\211", nullptr));
        label_pageInfo->setText(QString());
        pageJumpButton->setText(QCoreApplication::translate("BuySell", "\350\267\263\350\275\254", nullptr));
        backButton->setText(QCoreApplication::translate("BuySell", "\344\270\212\344\270\200\351\241\265", nullptr));
        forwardButton->setText(QCoreApplication::translate("BuySell", "\344\270\213\344\270\200\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("BuySell", "\350\276\223\345\205\245\345\205\255\344\275\215\350\202\241\347\245\250\344\273\243\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("BuySell", "\350\202\241\347\245\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("BuySell", "\350\202\241\347\245\250\344\273\267\346\240\274\357\274\232", nullptr));
        NoticeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BuySell: public Ui_BuySell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYSELL_H
