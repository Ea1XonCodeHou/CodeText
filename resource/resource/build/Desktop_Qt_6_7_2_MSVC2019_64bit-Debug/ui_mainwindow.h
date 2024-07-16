/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QTableView *newsTableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *prevPageButton;
    QLabel *pages;
    QPushButton *nextPageButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(821, 720);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout_2 = new QFormLayout(centralwidget);
        formLayout_2->setObjectName("formLayout_2");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color:transparent;\n"
"	background-image:url(:/new/prefix1/resource/search.background.png);\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(30, 30));
        label->setStyleSheet(QString::fromUtf8("border-image:url(:/new/prefix1/resource/ais92-gjqqx-001.ico);"));

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        searchLineEdit = new QLineEdit(frame);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(300, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font.setPointSize(11);
        searchLineEdit->setFont(font);
        searchLineEdit->setStyleSheet(QString::fromUtf8("#searchLineEdit{\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
"border: 0px solid #000000;\n"
"background-color:rgb(255, 255, 255);\n"
"}"));

        horizontalLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(frame);
        searchButton->setObjectName("searchButton");
        searchButton->setMinimumSize(QSize(70, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font1.setPointSize(11);
        font1.setBold(false);
        searchButton->setFont(font1);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setFocusPolicy(Qt::StrongFocus);
        searchButton->setStyleSheet(QString::fromUtf8("#searchButton{\n"
"border-top-right-radius: 20px;\n"
"border-bottom-right-radius: 20px;\n"
"border: 0px solid #000000;\n"
"background-color:rgb(61, 122, 255);\n"
"border-image:url(:/new/prefix1/resource/search.png)  stretch;\n"
"}"));

        horizontalLayout->addWidget(searchButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        newsTableView = new QTableView(frame);
        newsTableView->setObjectName("newsTableView");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        font2.setPointSize(11);
        newsTableView->setFont(font2);
        newsTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"background-color:rgba(239, 239, 239, 155);\n"
"border: 0px solid #000000;\n"
"}\n"
"QTableView::item {\n"
"    height: 50px;\n"
"	border-radius: 2px;\n"
"}"));
        newsTableView->horizontalHeader()->setVisible(true);
        newsTableView->horizontalHeader()->setHighlightSections(true);
        newsTableView->verticalHeader()->setVisible(true);

        verticalLayout->addWidget(newsTableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        prevPageButton = new QPushButton(frame);
        prevPageButton->setObjectName("prevPageButton");
        prevPageButton->setMinimumSize(QSize(30, 30));
        prevPageButton->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(prevPageButton);

        pages = new QLabel(frame);
        pages->setObjectName("pages");
        pages->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(pages);

        nextPageButton = new QPushButton(frame);
        nextPageButton->setObjectName("nextPageButton");
        nextPageButton->setMinimumSize(QSize(30, 30));
        nextPageButton->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(nextPageButton);


        verticalLayout->addLayout(horizontalLayout_3);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        formLayout_2->setWidget(0, QFormLayout::SpanningRole, frame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242...", nullptr));
        searchButton->setText(QString());
        prevPageButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pages->setText(QString());
        nextPageButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
