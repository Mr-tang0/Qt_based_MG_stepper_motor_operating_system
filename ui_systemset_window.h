/********************************************************************************
** Form generated from reading UI file 'systemset_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSET_WINDOW_H
#define UI_SYSTEMSET_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemSet
{
public:
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *language_2;
    QComboBox *language_3;
    QLabel *label_9;
    QComboBox *language;
    QLabel *label;
    QLabel *label_6;
    QSlider *blue;
    QLabel *label_4;
    QSlider *red;
    QSlider *green;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *filepath;
    QLabel *label_2;
    QComboBox *color;

    void setupUi(QWidget *systemSet)
    {
        if (systemSet->objectName().isEmpty())
            systemSet->setObjectName(QString::fromUtf8("systemSet"));
        systemSet->resize(1200, 800);
        label_3 = new QLabel(systemSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(39, 39, 525, 93));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(systemSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 400, 190, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        language_2 = new QComboBox(systemSet);
        language_2->addItem(QString());
        language_2->addItem(QString());
        language_2->setObjectName(QString::fromUtf8("language_2"));
        language_2->setGeometry(QRect(257, 400, 100, 26));
        language_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        language_3 = new QComboBox(systemSet);
        language_3->addItem(QString());
        language_3->addItem(QString());
        language_3->setObjectName(QString::fromUtf8("language_3"));
        language_3->setGeometry(QRect(260, 460, 100, 26));
        language_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_9 = new QLabel(systemSet);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 470, 190, 20));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        language = new QComboBox(systemSet);
        language->addItem(QString());
        language->addItem(QString());
        language->setObjectName(QString::fromUtf8("language"));
        language->setGeometry(QRect(259, 164, 100, 26));
        language->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label = new QLabel(systemSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(62, 164, 190, 20));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_6 = new QLabel(systemSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(156, 299, 16, 20));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        blue = new QSlider(systemSet);
        blue->setObjectName(QString::fromUtf8("blue"));
        blue->setGeometry(QRect(65, 299, 84, 22));
        blue->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(systemSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(156, 237, 16, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        red = new QSlider(systemSet);
        red->setObjectName(QString::fromUtf8("red"));
        red->setGeometry(QRect(65, 237, 84, 22));
        red->setOrientation(Qt::Horizontal);
        green = new QSlider(systemSet);
        green->setObjectName(QString::fromUtf8("green"));
        green->setGeometry(QRect(65, 268, 84, 22));
        green->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(systemSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(156, 268, 16, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_7 = new QLabel(systemSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(62, 333, 120, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        filepath = new QLineEdit(systemSet);
        filepath->setObjectName(QString::fromUtf8("filepath"));
        filepath->setGeometry(QRect(190, 330, 205, 26));
        filepath->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_2 = new QLabel(systemSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(63, 200, 80, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        color = new QComboBox(systemSet);
        color->addItem(QString());
        color->addItem(QString());
        color->addItem(QString());
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(270, 200, 89, 26));
        color->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        retranslateUi(systemSet);

        QMetaObject::connectSlotsByName(systemSet);
    } // setupUi

    void retranslateUi(QWidget *systemSet)
    {
        systemSet->setWindowTitle(QCoreApplication::translate("systemSet", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("systemSet", "SYSTEM SET", nullptr));
        label_8->setText(QCoreApplication::translate("systemSet", "\344\270\235\346\235\206\350\236\272\350\267\235", nullptr));
        language_2->setItemText(0, QCoreApplication::translate("systemSet", "\344\270\255\346\226\207", nullptr));
        language_2->setItemText(1, QCoreApplication::translate("systemSet", "English", nullptr));

        language_3->setItemText(0, QCoreApplication::translate("systemSet", "\344\270\255\346\226\207", nullptr));
        language_3->setItemText(1, QCoreApplication::translate("systemSet", "English", nullptr));

        label_9->setText(QCoreApplication::translate("systemSet", "\350\236\272\350\267\235", nullptr));
        language->setItemText(0, QCoreApplication::translate("systemSet", "\344\270\255\346\226\207", nullptr));
        language->setItemText(1, QCoreApplication::translate("systemSet", "English", nullptr));

        label->setText(QCoreApplication::translate("systemSet", "\347\263\273\347\273\237\350\257\255\350\250\200/language\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("systemSet", "B", nullptr));
        label_4->setText(QCoreApplication::translate("systemSet", "R", nullptr));
        label_5->setText(QCoreApplication::translate("systemSet", "G", nullptr));
        label_7->setText(QCoreApplication::translate("systemSet", "\351\273\230\350\256\244\345\255\230\345\202\250\344\275\215\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("systemSet", "\347\216\257\345\242\203\351\242\234\350\211\262", nullptr));
        color->setItemText(0, QCoreApplication::translate("systemSet", "\346\255\243\345\270\270", nullptr));
        color->setItemText(1, QCoreApplication::translate("systemSet", "\346\232\227\350\211\262", nullptr));
        color->setItemText(2, QCoreApplication::translate("systemSet", "\350\207\252\345\256\232\344\271\211", nullptr));

    } // retranslateUi

};

namespace Ui {
    class systemSet: public Ui_systemSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSET_WINDOW_H
