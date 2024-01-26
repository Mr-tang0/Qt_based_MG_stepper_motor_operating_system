/********************************************************************************
** Form generated from reading UI file 'formfill.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFILL_H
#define UI_FORMFILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFill
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ExperimenterEdit;
    QLabel *label_3;
    QLineEdit *timeNumberEdit;
    QLabel *label_5;
    QLineEdit *MaterialEdit;
    QLabel *label_4;
    QLineEdit *sampleEdit;
    QLabel *label;
    QLineEdit *currentTime;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *areaEdit;
    QLineEdit *lengthEdit;
    QLineEdit *sizeEdit;
    QLineEdit *strainRateEdit;
    QLineEdit *moreEdit;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_12;
    QComboBox *stopcondition;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *Compression;
    QRadioButton *stretching;
    QRadioButton *Reciprocating;
    QRadioButton *constantLoad;
    QRadioButton *Customize;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_39;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QVBoxLayout *verticalLayout_22;
    QDoubleSpinBox *motorSpeed;
    QDoubleSpinBox *maxMotorSpeed;
    QDoubleSpinBox *motorLength;
    QDoubleSpinBox *maxMotorLength;
    QDoubleSpinBox *motorCircle;
    QDoubleSpinBox *weighForce;
    QDoubleSpinBox *maxWeighForce;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLabel *drive;
    QLabel *sensor;
    QVBoxLayout *verticalLayout_3;
    QComboBox *SerialPort;
    QComboBox *driveBox;
    QComboBox *sensorBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *d2w;
    QVBoxLayout *verticalLayout_4;
    QComboBox *baudRate;
    QComboBox *limits;
    QComboBox *samplingRate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *portConnect;
    QPushButton *portRefresh;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLineEdit *filePathEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *submitBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_12;
    QButtonGroup *radioBtnGroup;

    void setupUi(QWidget *FormFill)
    {
        if (FormFill->objectName().isEmpty())
            FormFill->setObjectName(QString::fromUtf8("FormFill"));
        FormFill->resize(1200, 800);
        gridLayout = new QGridLayout(FormFill);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_10 = new QSpacerItem(1173, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        label_19 = new QLabel(FormFill);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(241, 131, 255);\n"
"	font: 16pt \"\345\271\274\345\234\206\";\n"
"}"));

        gridLayout->addWidget(label_19, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FormFill);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        ExperimenterEdit = new QLineEdit(FormFill);
        ExperimenterEdit->setObjectName(QString::fromUtf8("ExperimenterEdit"));
        ExperimenterEdit->setEnabled(true);
        ExperimenterEdit->setMinimumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(ExperimenterEdit);

        label_3 = new QLabel(FormFill);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        timeNumberEdit = new QLineEdit(FormFill);
        timeNumberEdit->setObjectName(QString::fromUtf8("timeNumberEdit"));
        timeNumberEdit->setMinimumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(timeNumberEdit);

        label_5 = new QLabel(FormFill);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        MaterialEdit = new QLineEdit(FormFill);
        MaterialEdit->setObjectName(QString::fromUtf8("MaterialEdit"));
        MaterialEdit->setMinimumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(MaterialEdit);

        label_4 = new QLabel(FormFill);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        sampleEdit = new QLineEdit(FormFill);
        sampleEdit->setObjectName(QString::fromUtf8("sampleEdit"));
        sampleEdit->setMinimumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(sampleEdit);

        label = new QLabel(FormFill);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_2->addWidget(label);

        currentTime = new QLineEdit(FormFill);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setEnabled(true);
        currentTime->setMinimumSize(QSize(80, 50));

        horizontalLayout_2->addWidget(currentTime);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        line = new QFrame(FormFill);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_20 = new QLabel(FormFill);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_7->addWidget(label_20);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_21 = new QLabel(FormFill);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_21);

        label_22 = new QLabel(FormFill);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_22);

        label_10 = new QLabel(FormFill);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_10);

        label_14 = new QLabel(FormFill);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_14);

        label_6 = new QLabel(FormFill);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        areaEdit = new QLineEdit(FormFill);
        areaEdit->setObjectName(QString::fromUtf8("areaEdit"));
        areaEdit->setMinimumSize(QSize(150, 30));

        verticalLayout->addWidget(areaEdit);

        lengthEdit = new QLineEdit(FormFill);
        lengthEdit->setObjectName(QString::fromUtf8("lengthEdit"));
        lengthEdit->setMinimumSize(QSize(150, 30));

        verticalLayout->addWidget(lengthEdit);

        sizeEdit = new QLineEdit(FormFill);
        sizeEdit->setObjectName(QString::fromUtf8("sizeEdit"));
        sizeEdit->setMinimumSize(QSize(150, 30));

        verticalLayout->addWidget(sizeEdit);

        strainRateEdit = new QLineEdit(FormFill);
        strainRateEdit->setObjectName(QString::fromUtf8("strainRateEdit"));
        strainRateEdit->setMinimumSize(QSize(150, 30));

        verticalLayout->addWidget(strainRateEdit);

        moreEdit = new QLineEdit(FormFill);
        moreEdit->setObjectName(QString::fromUtf8("moreEdit"));
        moreEdit->setMinimumSize(QSize(150, 30));

        verticalLayout->addWidget(moreEdit);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_12 = new QLabel(FormFill);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_17->addWidget(label_12);

        stopcondition = new QComboBox(FormFill);
        stopcondition->addItem(QString());
        stopcondition->addItem(QString());
        stopcondition->addItem(QString());
        stopcondition->addItem(QString());
        stopcondition->setObjectName(QString::fromUtf8("stopcondition"));
        stopcondition->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_17->addWidget(stopcondition);


        verticalLayout_7->addLayout(verticalLayout_17);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 4);
        verticalLayout_7->setStretch(2, 1);

        horizontalLayout_7->addLayout(verticalLayout_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_8 = new QLabel(FormFill);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_9->addWidget(label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        Compression = new QRadioButton(FormFill);
        radioBtnGroup = new QButtonGroup(FormFill);
        radioBtnGroup->setObjectName(QString::fromUtf8("radioBtnGroup"));
        radioBtnGroup->addButton(Compression);
        Compression->setObjectName(QString::fromUtf8("Compression"));
        Compression->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        Compression->setIconSize(QSize(40, 40));

        verticalLayout_8->addWidget(Compression);

        stretching = new QRadioButton(FormFill);
        radioBtnGroup->addButton(stretching);
        stretching->setObjectName(QString::fromUtf8("stretching"));
        stretching->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_8->addWidget(stretching);

        Reciprocating = new QRadioButton(FormFill);
        radioBtnGroup->addButton(Reciprocating);
        Reciprocating->setObjectName(QString::fromUtf8("Reciprocating"));
        Reciprocating->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_8->addWidget(Reciprocating);

        constantLoad = new QRadioButton(FormFill);
        radioBtnGroup->addButton(constantLoad);
        constantLoad->setObjectName(QString::fromUtf8("constantLoad"));
        constantLoad->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_8->addWidget(constantLoad);

        Customize = new QRadioButton(FormFill);
        radioBtnGroup->addButton(Customize);
        Customize->setObjectName(QString::fromUtf8("Customize"));
        Customize->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_8->addWidget(Customize);


        horizontalLayout_6->addLayout(verticalLayout_8);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        label_39 = new QLabel(FormFill);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        verticalLayout_23->addWidget(label_39);

        label_45 = new QLabel(FormFill);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        verticalLayout_23->addWidget(label_45);

        label_46 = new QLabel(FormFill);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        verticalLayout_23->addWidget(label_46);

        label_47 = new QLabel(FormFill);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        verticalLayout_23->addWidget(label_47);

        label_48 = new QLabel(FormFill);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        verticalLayout_23->addWidget(label_48);

        label_49 = new QLabel(FormFill);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        verticalLayout_23->addWidget(label_49);

        label_50 = new QLabel(FormFill);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        verticalLayout_23->addWidget(label_50);


        horizontalLayout_16->addLayout(verticalLayout_23);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        motorSpeed = new QDoubleSpinBox(FormFill);
        motorSpeed->setObjectName(QString::fromUtf8("motorSpeed"));

        verticalLayout_22->addWidget(motorSpeed);

        maxMotorSpeed = new QDoubleSpinBox(FormFill);
        maxMotorSpeed->setObjectName(QString::fromUtf8("maxMotorSpeed"));

        verticalLayout_22->addWidget(maxMotorSpeed);

        motorLength = new QDoubleSpinBox(FormFill);
        motorLength->setObjectName(QString::fromUtf8("motorLength"));

        verticalLayout_22->addWidget(motorLength);

        maxMotorLength = new QDoubleSpinBox(FormFill);
        maxMotorLength->setObjectName(QString::fromUtf8("maxMotorLength"));

        verticalLayout_22->addWidget(maxMotorLength);

        motorCircle = new QDoubleSpinBox(FormFill);
        motorCircle->setObjectName(QString::fromUtf8("motorCircle"));

        verticalLayout_22->addWidget(motorCircle);

        weighForce = new QDoubleSpinBox(FormFill);
        weighForce->setObjectName(QString::fromUtf8("weighForce"));

        verticalLayout_22->addWidget(weighForce);

        maxWeighForce = new QDoubleSpinBox(FormFill);
        maxWeighForce->setObjectName(QString::fromUtf8("maxWeighForce"));

        verticalLayout_22->addWidget(maxWeighForce);


        horizontalLayout_16->addLayout(verticalLayout_22);


        horizontalLayout_6->addLayout(horizontalLayout_16);


        verticalLayout_9->addLayout(horizontalLayout_6);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 5);

        horizontalLayout_7->addLayout(verticalLayout_9);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(2, 1);

        horizontalLayout_11->addLayout(horizontalLayout_7);

        horizontalLayout_11->setStretch(0, 20);

        gridLayout->addLayout(horizontalLayout_11, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 2, 1, 1);

        line_2 = new QFrame(FormFill);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_7 = new QLabel(FormFill);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        verticalLayout_11->addWidget(label_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_9 = new QLabel(FormFill);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_6->addWidget(label_9);

        drive = new QLabel(FormFill);
        drive->setObjectName(QString::fromUtf8("drive"));
        drive->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        drive->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_6->addWidget(drive);

        sensor = new QLabel(FormFill);
        sensor->setObjectName(QString::fromUtf8("sensor"));
        sensor->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        sensor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_6->addWidget(sensor);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        SerialPort = new QComboBox(FormFill);
        SerialPort->setObjectName(QString::fromUtf8("SerialPort"));
        SerialPort->setMinimumSize(QSize(100, 30));

        verticalLayout_3->addWidget(SerialPort);

        driveBox = new QComboBox(FormFill);
        driveBox->setObjectName(QString::fromUtf8("driveBox"));
        driveBox->setMinimumSize(QSize(100, 30));

        verticalLayout_3->addWidget(driveBox);

        sensorBox = new QComboBox(FormFill);
        sensorBox->setObjectName(QString::fromUtf8("sensorBox"));
        sensorBox->setMinimumSize(QSize(100, 30));

        verticalLayout_3->addWidget(sensorBox);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_13 = new QLabel(FormFill);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_13);

        label_17 = new QLabel(FormFill);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_17);

        d2w = new QLabel(FormFill);
        d2w->setObjectName(QString::fromUtf8("d2w"));
        d2w->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        d2w->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(d2w);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        baudRate = new QComboBox(FormFill);
        baudRate->setObjectName(QString::fromUtf8("baudRate"));
        baudRate->setMinimumSize(QSize(100, 30));

        verticalLayout_4->addWidget(baudRate);

        limits = new QComboBox(FormFill);
        limits->setObjectName(QString::fromUtf8("limits"));
        limits->setMinimumSize(QSize(100, 30));

        verticalLayout_4->addWidget(limits);

        samplingRate = new QComboBox(FormFill);
        samplingRate->setObjectName(QString::fromUtf8("samplingRate"));
        samplingRate->setMinimumSize(QSize(100, 30));

        verticalLayout_4->addWidget(samplingRate);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_10->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        portConnect = new QPushButton(FormFill);
        portConnect->setObjectName(QString::fromUtf8("portConnect"));
        portConnect->setMinimumSize(QSize(100, 40));
        portConnect->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(portConnect);

        portRefresh = new QPushButton(FormFill);
        portRefresh->setObjectName(QString::fromUtf8("portRefresh"));
        portRefresh->setMinimumSize(QSize(100, 40));
        portRefresh->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_5->addWidget(portRefresh);


        verticalLayout_10->addLayout(horizontalLayout_5);


        verticalLayout_11->addLayout(verticalLayout_10);


        horizontalLayout_9->addLayout(verticalLayout_11);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(FormFill);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 40));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout_8->addWidget(label_11);

        filePathEdit = new QLineEdit(FormFill);
        filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));
        filePathEdit->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(filePathEdit);


        verticalLayout_12->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        submitBtn = new QPushButton(FormFill);
        submitBtn->setObjectName(QString::fromUtf8("submitBtn"));
        submitBtn->setMinimumSize(QSize(100, 80));
        submitBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout->addWidget(submitBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelBtn = new QPushButton(FormFill);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(100, 80));
        cancelBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_12->addLayout(horizontalLayout);


        horizontalLayout_9->addLayout(verticalLayout_12);

        horizontalLayout_9->setStretch(0, 5);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 5);

        horizontalLayout_10->addLayout(horizontalLayout_9);

        horizontalLayout_10->setStretch(0, 20);

        gridLayout->addLayout(horizontalLayout_10, 6, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(1179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 7, 1, 1, 1);


        retranslateUi(FormFill);

        QMetaObject::connectSlotsByName(FormFill);
    } // setupUi

    void retranslateUi(QWidget *FormFill)
    {
        FormFill->setWindowTitle(QApplication::translate("FormFill", "Form", nullptr));
        label_19->setText(QApplication::translate("FormFill", "\350\257\225\351\252\214\350\241\250\345\215\225\345\241\253\345\206\231", nullptr));
        label_2->setText(QApplication::translate("FormFill", "\345\256\236\351\252\214\344\272\272\357\274\232", nullptr));
        label_3->setText(QApplication::translate("FormFill", "\346\240\267\346\234\254\347\274\226\345\217\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("FormFill", "\346\240\267\346\234\254\346\235\220\350\264\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("FormFill", "\346\240\267\346\234\254\346\240\267\345\274\217\357\274\232", nullptr));
        label->setText(QApplication::translate("FormFill", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        label_20->setText(QApplication::translate("FormFill", "*\346\235\220\346\226\231\344\277\241\346\201\257\357\274\232", nullptr));
        label_21->setText(QApplication::translate("FormFill", "*\346\240\207\350\267\235\346\256\265\346\210\252\351\235\242\347\247\257", nullptr));
        label_22->setText(QApplication::translate("FormFill", "*\346\240\207\350\267\235\346\256\265\351\225\277", nullptr));
        label_10->setText(QApplication::translate("FormFill", "\346\240\267\346\234\254\345\260\272\345\257\270", nullptr));
        label_14->setText(QApplication::translate("FormFill", "*\345\272\224\345\217\230\347\216\207", nullptr));
        label_6->setText(QApplication::translate("FormFill", "\345\244\207\346\263\250\344\277\241\346\201\257", nullptr));
        moreEdit->setPlaceholderText(QApplication::translate("FormFill", "...", nullptr));
        label_12->setText(QApplication::translate("FormFill", "\350\257\225\351\252\214\347\273\210\346\255\242\346\235\241\344\273\266", nullptr));
        stopcondition->setItemText(0, QApplication::translate("FormFill", "\346\234\200\345\244\247\345\212\240\350\275\275", nullptr));
        stopcondition->setItemText(1, QApplication::translate("FormFill", "\346\234\200\345\244\247\350\267\235\347\246\273", nullptr));
        stopcondition->setItemText(2, QApplication::translate("FormFill", "\346\214\207\345\256\232\346\227\266\351\227\264", nullptr));
        stopcondition->setItemText(3, QApplication::translate("FormFill", "\346\235\220\346\226\231\346\226\255\350\243\202", nullptr));

        label_8->setText(QApplication::translate("FormFill", "*\350\257\225\351\252\214\345\212\240\350\275\275\347\261\273\345\236\213\357\274\232", nullptr));
        Compression->setText(QApplication::translate("FormFill", "\345\216\213\347\274\251", nullptr));
        stretching->setText(QApplication::translate("FormFill", "\346\213\211\344\274\270", nullptr));
        Reciprocating->setText(QApplication::translate("FormFill", "\345\276\200\345\244\215\345\212\240\350\275\275", nullptr));
        constantLoad->setText(QApplication::translate("FormFill", "\346\201\222\345\256\232\350\275\275\350\215\267", nullptr));
        Customize->setText(QApplication::translate("FormFill", "\350\207\252\345\256\232\344\271\211", nullptr));
        label_39->setText(QApplication::translate("FormFill", "\350\256\276\347\275\256\351\200\237\345\272\246(mm/s)", nullptr));
        label_45->setText(QApplication::translate("FormFill", "\346\234\200\345\244\247\351\200\237\345\272\246(mm/s)", nullptr));
        label_46->setText(QApplication::translate("FormFill", "\350\256\276\347\275\256\350\267\235\347\246\273(mm)", nullptr));
        label_47->setText(QApplication::translate("FormFill", "\346\234\200\345\244\247\350\267\235\347\246\273(mm)", nullptr));
        label_48->setText(QApplication::translate("FormFill", "\350\256\276\347\275\256\345\221\250\346\234\237(s)", nullptr));
        label_49->setText(QApplication::translate("FormFill", "\350\256\276\347\275\256\345\212\240\350\275\275(N)", nullptr));
        label_50->setText(QApplication::translate("FormFill", "\346\234\200\345\244\247\345\212\240\350\275\275(N)", nullptr));
        label_7->setText(QApplication::translate("FormFill", "\347\263\273\347\273\237\345\217\202\346\225\260\357\274\232", nullptr));
        label_9->setText(QApplication::translate("FormFill", "\351\200\232\344\277\241\344\270\262\345\217\243\357\274\232 ", nullptr));
        drive->setText(QApplication::translate("FormFill", "\351\251\261\345\212\250\346\250\241\345\235\227\345\234\260\345\235\200\357\274\232 ", nullptr));
        sensor->setText(QApplication::translate("FormFill", "\344\274\240\346\204\237\345\231\250\345\234\260\345\235\200\357\274\232 ", nullptr));
        label_13->setText(QApplication::translate("FormFill", "\346\263\242\347\211\271\347\216\207\357\274\232 ", nullptr));
        label_17->setText(QApplication::translate("FormFill", "\351\231\220\344\275\215\345\234\260\345\235\200\357\274\232 ", nullptr));
        d2w->setText(QApplication::translate("FormFill", "\344\274\240\346\204\237\345\231\250\351\207\207\346\240\267\347\216\207\357\274\232", nullptr));
        portConnect->setText(QApplication::translate("FormFill", "\350\277\236\346\216\245", nullptr));
        portRefresh->setText(QApplication::translate("FormFill", "\345\210\267\346\226\260", nullptr));
        label_11->setText(QApplication::translate("FormFill", "\346\226\207\344\273\266\344\277\235\345\255\230\344\275\215\347\275\256", nullptr));
        submitBtn->setText(QApplication::translate("FormFill", "\346\217\220\344\272\244\344\275\234\344\270\232", nullptr));
        cancelBtn->setText(QApplication::translate("FormFill", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFill: public Ui_FormFill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFILL_H
