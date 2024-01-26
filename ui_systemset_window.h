/********************************************************************************
** Form generated from reading UI file 'systemset_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSET_WINDOW_H
#define UI_SYSTEMSET_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemSet
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *language;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *color;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *red;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSlider *green;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QSlider *blue;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *filepath;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *systemSet)
    {
        if (systemSet->objectName().isEmpty())
            systemSet->setObjectName(QString::fromUtf8("systemSet"));
        systemSet->resize(1200, 800);
        gridLayout = new QGridLayout(systemSet);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_3);

        label_3 = new QLabel(systemSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(systemSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_4->addWidget(label);

        language = new QComboBox(systemSet);
        language->addItem(QString());
        language->addItem(QString());
        language->setObjectName(QString::fromUtf8("language"));
        language->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_4->addWidget(language);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(systemSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(label_2);

        color = new QComboBox(systemSet);
        color->addItem(QString());
        color->addItem(QString());
        color->addItem(QString());
        color->setObjectName(QString::fromUtf8("color"));
        color->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(color);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        red = new QSlider(systemSet);
        red->setObjectName(QString::fromUtf8("red"));
        red->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(red);

        label_4 = new QLabel(systemSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        green = new QSlider(systemSet);
        green->setObjectName(QString::fromUtf8("green"));
        green->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(green);

        label_5 = new QLabel(systemSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        blue = new QSlider(systemSet);
        blue->setObjectName(QString::fromUtf8("blue"));
        blue->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(blue);

        label_6 = new QLabel(systemSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(systemSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_7->addWidget(label_7);

        filepath = new QLineEdit(systemSet);
        filepath->setObjectName(QString::fromUtf8("filepath"));
        filepath->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_7->addWidget(filepath);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);


        retranslateUi(systemSet);

        QMetaObject::connectSlotsByName(systemSet);
    } // setupUi

    void retranslateUi(QWidget *systemSet)
    {
        systemSet->setWindowTitle(QApplication::translate("systemSet", "Form", nullptr));
        label_3->setText(QApplication::translate("systemSet", "SYSTEM SET", nullptr));
        label->setText(QApplication::translate("systemSet", "\347\263\273\347\273\237\350\257\255\350\250\200/language\357\274\232", nullptr));
        language->setItemText(0, QApplication::translate("systemSet", "\344\270\255\346\226\207", nullptr));
        language->setItemText(1, QApplication::translate("systemSet", "English", nullptr));

        label_2->setText(QApplication::translate("systemSet", "\347\216\257\345\242\203\351\242\234\350\211\262", nullptr));
        color->setItemText(0, QApplication::translate("systemSet", "\346\255\243\345\270\270", nullptr));
        color->setItemText(1, QApplication::translate("systemSet", "\346\232\227\350\211\262", nullptr));
        color->setItemText(2, QApplication::translate("systemSet", "\350\207\252\345\256\232\344\271\211", nullptr));

        label_4->setText(QApplication::translate("systemSet", "R", nullptr));
        label_5->setText(QApplication::translate("systemSet", "G", nullptr));
        label_6->setText(QApplication::translate("systemSet", "B", nullptr));
        label_7->setText(QApplication::translate("systemSet", "\351\273\230\350\256\244\345\255\230\345\202\250\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class systemSet: public Ui_systemSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSET_WINDOW_H
