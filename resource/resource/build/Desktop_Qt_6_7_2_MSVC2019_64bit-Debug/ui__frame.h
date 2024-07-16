/********************************************************************************
** Form generated from reading UI file '_frame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__FRAME_H
#define UI__FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__frame
{
public:
    QFormLayout *formLayout;
    QFrame *backimage;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QStackedWidget *logORsigFrame;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *_frame)
    {
        if (_frame->objectName().isEmpty())
            _frame->setObjectName("_frame");
        _frame->resize(287, 496);
        _frame->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.2, y1:0.5, x2:0.4, y2:1.3, stop:1 rgb(0, 13, 255),stop:0.5 rgb(255, 0, 0), stop:0 rgb(255, 255, 255));"));
        formLayout = new QFormLayout(_frame);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(7, 7, 7, 7);
        backimage = new QFrame(_frame);
        backimage->setObjectName("backimage");
        backimage->setMinimumSize(QSize(200, 300));
        backimage->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        backimage->setFrameShape(QFrame::StyledPanel);
        backimage->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(backimage);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(backimage);
        pushButton->setObjectName("pushButton");
        QFont font;
        font.setPointSize(13);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0;\n"
"    background-color: transparent;\n"
"	color:rgb(54, 24, 97)\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(194, 194, 194);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        logORsigFrame = new QStackedWidget(backimage);
        logORsigFrame->setObjectName("logORsigFrame");

        verticalLayout->addWidget(logORsigFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        formLayout->setWidget(0, QFormLayout::SpanningRole, backimage);


        retranslateUi(_frame);

        QMetaObject::connectSlotsByName(_frame);
    } // setupUi

    void retranslateUi(QWidget *_frame)
    {
        _frame->setWindowTitle(QCoreApplication::translate("_frame", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("_frame", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _frame: public Ui__frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__FRAME_H
