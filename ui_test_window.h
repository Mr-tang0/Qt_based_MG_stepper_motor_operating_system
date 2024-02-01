/********************************************************************************
** Form generated from reading UI file 'test_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_WINDOW_H
#define UI_TEST_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_mainUiTest
{
public:
    QRadioButton *blue;
    QRadioButton *red;
    QRadioButton *black;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *load;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLCDNumber *stress;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLCDNumber *displacement;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLCDNumber *displacement_sensors;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QLCDNumber *strain;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QLCDNumber *Duration;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *emergency;
    QHBoxLayout *horizontalLayout_4;
    QChartView *graphicsView;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_5;
    QPushButton *newTest;
    QVBoxLayout *verticalLayout_3;
    QPushButton *startTest;
    QPushButton *stopTest;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *clearTest;
    QPushButton *saveTest;
    QTextBrowser *stateBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *matulSpeed;
    QPushButton *UP;
    QSpacerItem *verticalSpacer_3;
    QPushButton *stop;
    QSpacerItem *verticalSpacer_4;
    QPushButton *Down;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *setLengthZero;
    QPushButton *setWeighZero;
    QButtonGroup *colorBtnGrp;

    void setupUi(QWidget *mainUiTest)
    {
        if (mainUiTest->objectName().isEmpty())
            mainUiTest->setObjectName(QString::fromUtf8("mainUiTest"));
        mainUiTest->resize(1200, 800);
        blue = new QRadioButton(mainUiTest);
        colorBtnGrp = new QButtonGroup(mainUiTest);
        colorBtnGrp->setObjectName(QString::fromUtf8("colorBtnGrp"));
        colorBtnGrp->addButton(blue);
        blue->setObjectName(QString::fromUtf8("blue"));
        blue->setGeometry(QRect(309, 760, 71, 27));
        red = new QRadioButton(mainUiTest);
        colorBtnGrp->addButton(red);
        red->setObjectName(QString::fromUtf8("red"));
        red->setGeometry(QRect(605, 760, 62, 27));
        black = new QRadioButton(mainUiTest);
        colorBtnGrp->addButton(black);
        black->setObjectName(QString::fromUtf8("black"));
        black->setGeometry(QRect(900, 760, 79, 27));
        gridLayout_2 = new QGridLayout(mainUiTest);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(mainUiTest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        load = new QLCDNumber(mainUiTest);
        load->setObjectName(QString::fromUtf8("load"));
        load->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 0, 4);\n"
"}\n"
""));

        verticalLayout->addWidget(load);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(mainUiTest);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        stress = new QLCDNumber(mainUiTest);
        stress->setObjectName(QString::fromUtf8("stress"));

        verticalLayout_7->addWidget(stress);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_9 = new QLabel(mainUiTest);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_9);

        displacement = new QLCDNumber(mainUiTest);
        displacement->setObjectName(QString::fromUtf8("displacement"));

        verticalLayout_9->addWidget(displacement);


        horizontalLayout->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_8 = new QLabel(mainUiTest);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_8);

        displacement_sensors = new QLCDNumber(mainUiTest);
        displacement_sensors->setObjectName(QString::fromUtf8("displacement_sensors"));

        verticalLayout_8->addWidget(displacement_sensors);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_10 = new QLabel(mainUiTest);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_10);

        strain = new QLCDNumber(mainUiTest);
        strain->setObjectName(QString::fromUtf8("strain"));

        verticalLayout_10->addWidget(strain);


        horizontalLayout->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_11 = new QLabel(mainUiTest);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\271\274\345\234\206\";"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_11);

        Duration = new QLCDNumber(mainUiTest);
        Duration->setObjectName(QString::fromUtf8("Duration"));

        verticalLayout_11->addWidget(Duration);


        horizontalLayout->addLayout(verticalLayout_11);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 2);

        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_4->setStretch(0, 3);

        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        emergency = new QPushButton(mainUiTest);
        emergency->setObjectName(QString::fromUtf8("emergency"));
        emergency->setMinimumSize(QSize(120, 100));
        emergency->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\271\274\345\234\206\";\n"
"background-color: rgb(255, 131, 131);"));

        horizontalLayout_3->addWidget(emergency);

        horizontalLayout_3->setStretch(0, 8);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        graphicsView = new QChartView(mainUiTest);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_4->addWidget(graphicsView);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));

        horizontalLayout_4->addLayout(verticalLayout_12);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        newTest = new QPushButton(mainUiTest);
        newTest->setObjectName(QString::fromUtf8("newTest"));
        newTest->setMinimumSize(QSize(100, 40));
        newTest->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));

        verticalLayout_5->addWidget(newTest);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        startTest = new QPushButton(mainUiTest);
        startTest->setObjectName(QString::fromUtf8("startTest"));
        startTest->setMinimumSize(QSize(120, 50));
        startTest->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_3->addWidget(startTest);

        stopTest = new QPushButton(mainUiTest);
        stopTest->setObjectName(QString::fromUtf8("stopTest"));
        stopTest->setMinimumSize(QSize(120, 50));
        stopTest->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_3->addWidget(stopTest);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        clearTest = new QPushButton(mainUiTest);
        clearTest->setObjectName(QString::fromUtf8("clearTest"));
        clearTest->setMinimumSize(QSize(100, 50));
        clearTest->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(clearTest);

        saveTest = new QPushButton(mainUiTest);
        saveTest->setObjectName(QString::fromUtf8("saveTest"));
        saveTest->setMinimumSize(QSize(100, 50));
        saveTest->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(saveTest);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_3);

        stateBox = new QTextBrowser(mainUiTest);
        stateBox->setObjectName(QString::fromUtf8("stateBox"));

        verticalLayout_5->addWidget(stateBox);

        widget = new QWidget(mainUiTest);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        matulSpeed = new QDoubleSpinBox(widget);
        matulSpeed->setObjectName(QString::fromUtf8("matulSpeed"));
        matulSpeed->setMinimumSize(QSize(100, 40));
        matulSpeed->setMinimum(0.010000000000000);
        matulSpeed->setMaximum(9999.000000000000000);

        horizontalLayout_2->addWidget(matulSpeed);


        verticalLayout_2->addLayout(horizontalLayout_2);

        UP = new QPushButton(widget);
        UP->setObjectName(QString::fromUtf8("UP"));
        UP->setMinimumSize(QSize(50, 50));
        UP->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_2->addWidget(UP);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        stop = new QPushButton(widget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setMinimumSize(QSize(50, 50));
        stop->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_2->addWidget(stop);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        Down = new QPushButton(widget);
        Down->setObjectName(QString::fromUtf8("Down"));
        Down->setMinimumSize(QSize(50, 50));
        Down->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_2->addWidget(Down);

        verticalLayout_2->setStretch(1, 11);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 2, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        setLengthZero = new QPushButton(widget);
        setLengthZero->setObjectName(QString::fromUtf8("setLengthZero"));

        horizontalLayout_6->addWidget(setLengthZero);

        setWeighZero = new QPushButton(widget);
        setWeighZero->setObjectName(QString::fromUtf8("setWeighZero"));

        horizontalLayout_6->addWidget(setWeighZero);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);


        verticalLayout_5->addWidget(widget);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(0, 8);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout_6->addLayout(horizontalLayout_4);

        verticalLayout_6->setStretch(0, 2);

        gridLayout_2->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(mainUiTest);

        QMetaObject::connectSlotsByName(mainUiTest);
    } // setupUi

    void retranslateUi(QWidget *mainUiTest)
    {
        mainUiTest->setWindowTitle(QCoreApplication::translate("mainUiTest", "Form", nullptr));
        blue->setText(QCoreApplication::translate("mainUiTest", "blue", nullptr));
        red->setText(QCoreApplication::translate("mainUiTest", "red", nullptr));
        black->setText(QCoreApplication::translate("mainUiTest", "black", nullptr));
        label->setText(QCoreApplication::translate("mainUiTest", "\350\275\275\350\215\267", nullptr));
        label_7->setText(QCoreApplication::translate("mainUiTest", "\345\272\224\345\212\233", nullptr));
        label_9->setText(QCoreApplication::translate("mainUiTest", "\350\256\241\347\256\227\344\275\215\347\247\273", nullptr));
        label_8->setText(QCoreApplication::translate("mainUiTest", "\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        label_10->setText(QCoreApplication::translate("mainUiTest", "\345\272\224\345\217\230", nullptr));
        label_11->setText(QCoreApplication::translate("mainUiTest", "\346\227\266\351\225\277", nullptr));
        emergency->setText(QCoreApplication::translate("mainUiTest", "\346\200\245\345\201\234", nullptr));
        newTest->setText(QCoreApplication::translate("mainUiTest", "\346\226\260\345\273\272\346\265\213\350\257\225", nullptr));
        startTest->setText(QCoreApplication::translate("mainUiTest", "\345\274\200\345\247\213", nullptr));
        stopTest->setText(QCoreApplication::translate("mainUiTest", "\345\201\234\346\255\242", nullptr));
        clearTest->setText(QCoreApplication::translate("mainUiTest", "\350\277\230\345\216\237\345\275\223\345\211\215", nullptr));
        saveTest->setText(QCoreApplication::translate("mainUiTest", "\344\277\235\345\255\230\345\275\223\345\211\215", nullptr));
        UP->setText(QCoreApplication::translate("mainUiTest", "\344\270\212", nullptr));
        stop->setText(QCoreApplication::translate("mainUiTest", "\345\201\234", nullptr));
        Down->setText(QCoreApplication::translate("mainUiTest", "\344\270\213", nullptr));
        setLengthZero->setText(QCoreApplication::translate("mainUiTest", "\350\256\276\347\275\2560\347\202\271", nullptr));
        setWeighZero->setText(QCoreApplication::translate("mainUiTest", "\345\216\273\347\232\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainUiTest: public Ui_mainUiTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_WINDOW_H
