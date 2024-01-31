/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtmaterialflatbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QtMaterialFlatButton *login;
    QtMaterialFlatButton *test;
    QtMaterialFlatButton *systemSet;
    QtMaterialFlatButton *help;
    QtMaterialFlatButton *about;
    QLabel *appVersion;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1563, 919);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 244, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(200, 200));
        widget_2->setMaximumSize(QSize(200, 200));
        widget_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(widget_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 50));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"color: rgb(140, 140, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        login = new QtMaterialFlatButton(centralwidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setMinimumSize(QSize(200, 50));
        login->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 217);\n"
"font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(login);

        test = new QtMaterialFlatButton(centralwidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setMinimumSize(QSize(200, 50));
        test->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 217);\n"
"font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(test);

        systemSet = new QtMaterialFlatButton(centralwidget);
        systemSet->setObjectName(QString::fromUtf8("systemSet"));
        systemSet->setMinimumSize(QSize(200, 50));
        systemSet->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 217);\n"
"font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(systemSet);

        help = new QtMaterialFlatButton(centralwidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setMinimumSize(QSize(200, 50));
        help->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"\345\271\274\345\234\206\";\n"
"color: rgb(0,0,0);"));

        verticalLayout->addWidget(help);

        about = new QtMaterialFlatButton(centralwidget);
        about->setObjectName(QString::fromUtf8("about"));
        about->setMinimumSize(QSize(200, 50));
        about->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 217);\n"
"font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(about);


        verticalLayout_2->addLayout(verticalLayout);

        appVersion = new QLabel(centralwidget);
        appVersion->setObjectName(QString::fromUtf8("appVersion"));
        appVersion->setMinimumSize(QSize(200, 50));
        appVersion->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\271\274\345\234\206\";\n"
"color: rgb(140, 140, 255);"));
        appVersion->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(appVersion);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(3, 7);
        verticalLayout_2->setStretch(4, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(1200, 800));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 255, 254);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(17, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 2, 1, 1);


        horizontalLayout->addWidget(widget);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1563, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "UserName", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267\347\231\273\345\275\225", nullptr));
        test->setText(QCoreApplication::translate("MainWindow", "\346\235\220\346\226\231\346\265\213\350\257\225", nullptr));
        systemSet->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266", nullptr));
        appVersion->setText(QCoreApplication::translate("MainWindow", "appvision", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
