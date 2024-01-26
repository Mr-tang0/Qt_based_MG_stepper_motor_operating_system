/********************************************************************************
** Form generated from reading UI file 'login_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

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

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *userName;
    QLineEdit *passWord;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *signUpBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1200, 800);
        Login->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        userName = new QLineEdit(Login);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setMinimumSize(QSize(300, 80));
        userName->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"background-color: rgb(230, 230, 230);"));
        userName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(userName);

        passWord = new QLineEdit(Login);
        passWord->setObjectName(QString::fromUtf8("passWord"));
        passWord->setMinimumSize(QSize(300, 80));
        passWord->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"background-color: rgb(230, 230, 230);"));
        passWord->setEchoMode(QLineEdit::Password);
        passWord->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passWord);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setMinimumSize(QSize(200, 80));
        loginBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(188, 240, 255);\n"
" border-radius: 5px;"));

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        signUpBtn = new QPushButton(Login);
        signUpBtn->setObjectName(QString::fromUtf8("signUpBtn"));
        signUpBtn->setMinimumSize(QSize(200, 80));
        signUpBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(188, 240, 255);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(signUpBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(354, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(354, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label_3->setText(QApplication::translate("Login", "LOGIN", nullptr));
        userName->setText(QString());
        userName->setPlaceholderText(QApplication::translate("Login", "UserName", nullptr));
        passWord->setPlaceholderText(QApplication::translate("Login", "Password", nullptr));
        loginBtn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        signUpBtn->setText(QApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WINDOW_H
