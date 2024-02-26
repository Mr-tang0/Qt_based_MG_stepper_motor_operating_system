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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemSet
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *envColor;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *filepath;
    QPushButton *openPath;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *language;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *smoothCurve;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *precision;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *buandrate;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *motorAddress;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *weighAddress;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *limitAddress;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QDoubleSpinBox *pitch;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *weighCorrect;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *saveSet;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_15;

    void setupUi(QWidget *systemSet)
    {
        if (systemSet->objectName().isEmpty())
            systemSet->setObjectName(QString::fromUtf8("systemSet"));
        systemSet->resize(1200, 800);
        gridLayout = new QGridLayout(systemSet);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(systemSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 50pt \"Arial\";\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(systemSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_2);

        label_7 = new QLabel(systemSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_7);

        label = new QLabel(systemSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label);

        label_10 = new QLabel(systemSet);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(systemSet);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        label_14 = new QLabel(systemSet);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_14);

        label_9 = new QLabel(systemSet);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_9);

        label_12 = new QLabel(systemSet);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(systemSet);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_13);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        label_8 = new QLabel(systemSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_8);

        label_15 = new QLabel(systemSet);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout->addWidget(label_15);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        envColor = new QComboBox(systemSet);
        envColor->addItem(QString());
        envColor->addItem(QString());
        envColor->setObjectName(QString::fromUtf8("envColor"));
        envColor->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout->addWidget(envColor);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        filepath = new QLineEdit(systemSet);
        filepath->setObjectName(QString::fromUtf8("filepath"));
        filepath->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_11->addWidget(filepath);

        openPath = new QPushButton(systemSet);
        openPath->setObjectName(QString::fromUtf8("openPath"));

        horizontalLayout_11->addWidget(openPath);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        language = new QComboBox(systemSet);
        language->addItem(QString());
        language->addItem(QString());
        language->setObjectName(QString::fromUtf8("language"));
        language->setMinimumSize(QSize(100, 0));
        language->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_2->addWidget(language);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        smoothCurve = new QComboBox(systemSet);
        smoothCurve->addItem(QString());
        smoothCurve->addItem(QString());
        smoothCurve->setObjectName(QString::fromUtf8("smoothCurve"));
        smoothCurve->setMinimumSize(QSize(100, 0));
        smoothCurve->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_3->addWidget(smoothCurve);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        precision = new QComboBox(systemSet);
        precision->addItem(QString());
        precision->addItem(QString());
        precision->addItem(QString());
        precision->addItem(QString());
        precision->setObjectName(QString::fromUtf8("precision"));
        precision->setMinimumSize(QSize(100, 0));
        precision->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_4->addWidget(precision);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        buandrate = new QComboBox(systemSet);
        buandrate->addItem(QString());
        buandrate->addItem(QString());
        buandrate->addItem(QString());
        buandrate->setObjectName(QString::fromUtf8("buandrate"));
        buandrate->setMinimumSize(QSize(100, 0));
        buandrate->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(buandrate);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        motorAddress = new QComboBox(systemSet);
        motorAddress->addItem(QString());
        motorAddress->addItem(QString());
        motorAddress->addItem(QString());
        motorAddress->setObjectName(QString::fromUtf8("motorAddress"));
        motorAddress->setMinimumSize(QSize(100, 0));
        motorAddress->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_6->addWidget(motorAddress);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        weighAddress = new QComboBox(systemSet);
        weighAddress->addItem(QString());
        weighAddress->addItem(QString());
        weighAddress->addItem(QString());
        weighAddress->setObjectName(QString::fromUtf8("weighAddress"));
        weighAddress->setMinimumSize(QSize(100, 0));
        weighAddress->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_7->addWidget(weighAddress);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        limitAddress = new QComboBox(systemSet);
        limitAddress->addItem(QString());
        limitAddress->addItem(QString());
        limitAddress->addItem(QString());
        limitAddress->setObjectName(QString::fromUtf8("limitAddress"));
        limitAddress->setMinimumSize(QSize(100, 0));
        limitAddress->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_8->addWidget(limitAddress);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pitch = new QDoubleSpinBox(systemSet);
        pitch->setObjectName(QString::fromUtf8("pitch"));
        pitch->setMinimumSize(QSize(100, 0));

        horizontalLayout_9->addWidget(pitch);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        weighCorrect = new QDoubleSpinBox(systemSet);
        weighCorrect->setObjectName(QString::fromUtf8("weighCorrect"));
        weighCorrect->setMinimumSize(QSize(100, 0));

        horizontalLayout_10->addWidget(weighCorrect);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_12->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_16);

        saveSet = new QPushButton(systemSet);
        saveSet->setObjectName(QString::fromUtf8("saveSet"));
        saveSet->setMinimumSize(QSize(0, 50));
        saveSet->setIconSize(QSize(20, 50));

        horizontalLayout_13->addWidget(saveSet);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);

        horizontalLayout_13->setStretch(0, 3);
        horizontalLayout_13->setStretch(1, 5);
        horizontalLayout_13->setStretch(2, 3);

        verticalLayout_3->addLayout(horizontalLayout_13);

        verticalLayout_3->setStretch(0, 8);
        verticalLayout_3->setStretch(1, 2);

        horizontalLayout_14->addLayout(verticalLayout_3);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_15);

        horizontalLayout_14->setStretch(0, 4);
        horizontalLayout_14->setStretch(1, 6);

        verticalLayout_4->addLayout(horizontalLayout_14);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 8);

        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(systemSet);

        QMetaObject::connectSlotsByName(systemSet);
    } // setupUi

    void retranslateUi(QWidget *systemSet)
    {
        systemSet->setWindowTitle(QCoreApplication::translate("systemSet", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("systemSet", "SYSTEM SET", nullptr));
        label_2->setText(QCoreApplication::translate("systemSet", "\347\216\257\345\242\203\351\242\234\350\211\262", nullptr));
        label_7->setText(QCoreApplication::translate("systemSet", "\346\225\260\346\215\256\351\273\230\350\256\244\345\255\230\345\202\250\344\275\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("systemSet", "\347\263\273\347\273\237\350\257\255\350\250\200/language\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("systemSet", "\346\233\262\347\272\277\345\271\263\346\273\221", nullptr));
        label_11->setText(QCoreApplication::translate("systemSet", "\346\230\276\347\244\272\347\262\276\345\272\246\357\274\210\345\260\217\346\225\260\357\274\211", nullptr));
        label_14->setText(QCoreApplication::translate("systemSet", "\351\273\230\350\256\244\351\200\232\350\256\257\346\263\242\347\211\271\347\216\207", nullptr));
        label_9->setText(QCoreApplication::translate("systemSet", "\351\273\230\350\256\244\347\224\265\346\234\272\345\234\260\345\235\200", nullptr));
        label_12->setText(QCoreApplication::translate("systemSet", "\351\273\230\350\256\244\344\274\240\346\204\237\345\231\250\345\234\260\345\235\200", nullptr));
        label_13->setText(QCoreApplication::translate("systemSet", "\351\273\230\350\256\244\351\231\220\344\275\215\345\231\250\345\234\260\345\235\200", nullptr));
        label_8->setText(QCoreApplication::translate("systemSet", "\344\270\235\346\235\206\350\236\272\350\267\235", nullptr));
        label_15->setText(QCoreApplication::translate("systemSet", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250\344\277\256\346\255\243\346\257\224\344\276\213\345\200\274", nullptr));
        envColor->setItemText(0, QCoreApplication::translate("systemSet", "\346\255\243\345\270\270", nullptr));
        envColor->setItemText(1, QCoreApplication::translate("systemSet", "\346\232\227\350\211\262", nullptr));

        openPath->setText(QCoreApplication::translate("systemSet", "\346\211\223\345\274\200\344\275\215\347\275\256", nullptr));
        language->setItemText(0, QCoreApplication::translate("systemSet", "\344\270\255\346\226\207", nullptr));
        language->setItemText(1, QCoreApplication::translate("systemSet", "English", nullptr));

        smoothCurve->setItemText(0, QCoreApplication::translate("systemSet", "\345\274\200\345\220\257", nullptr));
        smoothCurve->setItemText(1, QCoreApplication::translate("systemSet", "\345\205\263\351\227\255", nullptr));

        precision->setItemText(0, QCoreApplication::translate("systemSet", "0", nullptr));
        precision->setItemText(1, QCoreApplication::translate("systemSet", "1", nullptr));
        precision->setItemText(2, QCoreApplication::translate("systemSet", "2", nullptr));
        precision->setItemText(3, QCoreApplication::translate("systemSet", "3", nullptr));

        buandrate->setItemText(0, QCoreApplication::translate("systemSet", "9600", nullptr));
        buandrate->setItemText(1, QCoreApplication::translate("systemSet", "28800", nullptr));
        buandrate->setItemText(2, QCoreApplication::translate("systemSet", "115200", nullptr));

        motorAddress->setItemText(0, QCoreApplication::translate("systemSet", "1", nullptr));
        motorAddress->setItemText(1, QCoreApplication::translate("systemSet", "2", nullptr));
        motorAddress->setItemText(2, QCoreApplication::translate("systemSet", "3", nullptr));

        weighAddress->setItemText(0, QCoreApplication::translate("systemSet", "1", nullptr));
        weighAddress->setItemText(1, QCoreApplication::translate("systemSet", "2", nullptr));
        weighAddress->setItemText(2, QCoreApplication::translate("systemSet", "3", nullptr));

        limitAddress->setItemText(0, QCoreApplication::translate("systemSet", "1", nullptr));
        limitAddress->setItemText(1, QCoreApplication::translate("systemSet", "2", nullptr));
        limitAddress->setItemText(2, QCoreApplication::translate("systemSet", "3", nullptr));

        saveSet->setText(QCoreApplication::translate("systemSet", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class systemSet: public Ui_systemSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSET_WINDOW_H
