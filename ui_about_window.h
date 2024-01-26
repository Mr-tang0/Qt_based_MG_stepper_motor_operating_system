/********************************************************************************
** Form generated from reading UI file 'about_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_WINDOW_H
#define UI_ABOUT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qbout
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Qbout)
    {
        if (Qbout->objectName().isEmpty())
            Qbout->setObjectName(QString::fromUtf8("Qbout"));
        Qbout->resize(1200, 800);
        gridLayout = new QGridLayout(Qbout);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(Qbout);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        textBrowser = new QTextBrowser(Qbout);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Qbout);

        QMetaObject::connectSlotsByName(Qbout);
    } // setupUi

    void retranslateUi(QWidget *Qbout)
    {
        Qbout->setWindowTitle(QApplication::translate("Qbout", "Form", nullptr));
        label_3->setText(QApplication::translate("Qbout", "ABOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qbout: public Ui_Qbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_WINDOW_H
