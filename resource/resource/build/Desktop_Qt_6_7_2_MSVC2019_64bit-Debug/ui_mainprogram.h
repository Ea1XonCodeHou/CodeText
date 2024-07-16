/********************************************************************************
** Form generated from reading UI file 'mainprogram.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPROGRAM_H
#define UI_MAINPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainprogram
{
public:
    QFormLayout *formLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QFrame *frame_2;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *MiniButton;
    QPushButton *MaxButton;
    QPushButton *CloseButton;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *mainprogram)
    {
        if (mainprogram->objectName().isEmpty())
            mainprogram->setObjectName("mainprogram");
        mainprogram->resize(1085, 588);
        mainprogram->setMinimumSize(QSize(820, 517));
        mainprogram->setMaximumSize(QSize(1600, 1000));
        mainprogram->setStyleSheet(QString::fromUtf8("#mainprogram{\n"
"	background-color:rgb(255, 255, 255);\n"
"}"));
        formLayout_3 = new QFormLayout(mainprogram);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frame = new QFrame(mainprogram);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(278, 0));
        frame->setMaximumSize(QSize(278, 16777215));
        frame->setSizeIncrement(QSize(0, 0));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color:rgb(255, 255, 255);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(70, 70));
        label->setMaximumSize(QSize(70, 70));
        label->setStyleSheet(QString::fromUtf8("\n"
"#label{\n"
"border-image:url(:/new/prefix1/resource/ais92-gjqqx-001.ico);\n"
"}"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(70, 70));
        label_2->setMaximumSize(QSize(70, 70));
        label_2->setStyleSheet(QString::fromUtf8("#label_2{\n"
"border-image: url(:/new/prefix1/resource/acumg-ybkhb-001.ico)\n"
"}"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        listWidget = new QListWidget(frame);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resource/Calendar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resource/explorer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/resource/pad.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/resource/startmenu.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/resource/Systemtray.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/resource/Network.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/resource/virtualdesktop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/resource/ControlPlanel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget);
        __qlistwidgetitem7->setIcon(icon7);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        font.setPointSize(12);
        font.setBold(false);
        font.setStyleStrategy(QFont::PreferDefault);
        font.setHintingPreference(QFont::PreferDefaultHinting);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	background-color: transparent;\n"
"	border: 0;\n"
"}\n"
"QListView::item {\n"
"    height: 50px;\n"
"	border-radius: 2px;\n"
"}\n"
" QListView::Item:hover {\n"
" background: rgb(229, 237, 248);\n"
" }\n"
" \n"
"QListView::Item:selected  {\n"
"	background: rgb(204, 223, 248);\n"
"	color: rgb(0, 112, 249);\n"
"}\n"
"QWidget:focus{\n"
"outline: none;\n"
"}"));

        verticalLayout->addWidget(listWidget);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        horizontalLayout_3->addWidget(frame);

        frame_2 = new QFrame(mainprogram);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"#frame_2{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0.015, y2:0, stop:0 rgb(94, 94, 94), stop:1 rgb(202, 202, 202));\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(15, 0, 15, 15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        MiniButton = new QPushButton(frame_2);
        MiniButton->setObjectName("MiniButton");
        MiniButton->setMinimumSize(QSize(30, 30));
        MiniButton->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setPointSize(10);
        MiniButton->setFont(font1);
        MiniButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0;\n"
"	border-radius: 11px;\n"
"    background-color: rgb(255, 255, 255);\n"
"	color:rgb(54, 24, 97)\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(194, 194, 194);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(MiniButton);

        MaxButton = new QPushButton(frame_2);
        MaxButton->setObjectName("MaxButton");
        MaxButton->setMinimumSize(QSize(30, 30));
        MaxButton->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setPointSize(22);
        MaxButton->setFont(font2);
        MaxButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0;\n"
"	border-radius: 11px;\n"
"    background-color: rgb(232, 232, 232);\n"
"	color:rgb(54, 24, 97)\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(194, 194, 194);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(MaxButton);

        CloseButton = new QPushButton(frame_2);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setMinimumSize(QSize(30, 30));
        CloseButton->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setPointSize(18);
        CloseButton->setFont(font3);
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0;\n"
"	border-radius: 11px;\n"
"    background-color: rgb(255, 65, 65);\n"
"	color:rgb(255, 255, 255)\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(141, 0, 0);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(CloseButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"#stackedWidget{\n"
"background-color:rgb(255, 255, 255);\n"
"}"));

        verticalLayout_2->addWidget(stackedWidget);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, verticalLayout_2);


        horizontalLayout_3->addWidget(frame_2);


        formLayout_3->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_3);


        retranslateUi(mainprogram);
        QObject::connect(listWidget, &QListWidget::currentRowChanged, stackedWidget, &QStackedWidget::setCurrentIndex);

        QMetaObject::connectSlotsByName(mainprogram);
    } // setupUi

    void retranslateUi(QWidget *mainprogram)
    {
        mainprogram->setWindowTitle(QCoreApplication::translate("mainprogram", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("mainprogram", "\350\202\241\345\270\202\346\226\260\351\227\273", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("mainprogram", "\350\202\241\347\245\250\346\214\201\344\273\223", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("mainprogram", "\350\202\241\347\245\250\344\271\260\345\215\226", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("mainprogram", "\345\270\202\345\234\272\345\210\206\346\236\220", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("mainprogram", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("mainprogram", "\350\202\241\345\270\202\350\256\272\345\235\233", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("mainprogram", "\346\210\221\347\232\204\351\222\261\345\214\205", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("mainprogram", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        MiniButton->setText(QCoreApplication::translate("mainprogram", "\342\200\224", nullptr));
        MaxButton->setText(QCoreApplication::translate("mainprogram", "\342\226\242", nullptr));
        CloseButton->setText(QCoreApplication::translate("mainprogram", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainprogram: public Ui_mainprogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPROGRAM_H
