/********************************************************************************
** Form generated from reading UI file 'signup_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_WINDOW_H
#define UI_SIGNUP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userName;
    QLineEdit *passWord_1;
    QLineEdit *passWord_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *confirm;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(1200, 800);
        signup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(signup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(375, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(signup);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setLayoutDirection(Qt::RightToLeft);
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        label_5 = new QLabel(signup);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        label = new QLabel(signup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        userName = new QLineEdit(signup);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setMinimumSize(QSize(0, 80));
        userName->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        userName->setEchoMode(QLineEdit::Normal);
        userName->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(userName);

        passWord_1 = new QLineEdit(signup);
        passWord_1->setObjectName(QString::fromUtf8("passWord_1"));
        passWord_1->setMinimumSize(QSize(0, 80));
        passWord_1->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        passWord_1->setEchoMode(QLineEdit::Password);
        passWord_1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(passWord_1);

        passWord_2 = new QLineEdit(signup);
        passWord_2->setObjectName(QString::fromUtf8("passWord_2"));
        passWord_2->setMinimumSize(QSize(0, 80));
        passWord_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        passWord_2->setEchoMode(QLineEdit::Password);
        passWord_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(passWord_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        confirm = new QPushButton(signup);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setMinimumSize(QSize(200, 80));
        confirm->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(223, 183, 255);\n"
"border-radius: 5px;"));

        verticalLayout->addWidget(confirm);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 1);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(375, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QApplication::translate("signup", "Form", nullptr));
        label_3->setText(QApplication::translate("signup", "SIGN UP", nullptr));
        label_6->setText(QApplication::translate("signup", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_5->setText(QApplication::translate("signup", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("signup", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        userName->setPlaceholderText(QString());
        passWord_1->setPlaceholderText(QString());
        passWord_2->setPlaceholderText(QString());
        confirm->setText(QApplication::translate("signup", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_WINDOW_H
