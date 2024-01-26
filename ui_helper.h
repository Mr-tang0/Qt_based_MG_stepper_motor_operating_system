/********************************************************************************
** Form generated from reading UI file 'helper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPER_H
#define UI_HELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Helper
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Helper)
    {
        if (Helper->objectName().isEmpty())
            Helper->setObjectName(QString::fromUtf8("Helper"));
        Helper->resize(1200, 800);
        gridLayout = new QGridLayout(Helper);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(Helper);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        textBrowser = new QTextBrowser(Helper);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Helper);

        QMetaObject::connectSlotsByName(Helper);
    } // setupUi

    void retranslateUi(QWidget *Helper)
    {
        Helper->setWindowTitle(QApplication::translate("Helper", "Form", nullptr));
        label_3->setText(QApplication::translate("Helper", "HELPER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Helper: public Ui_Helper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPER_H
