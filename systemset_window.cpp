#include "systemset_window.h"
#include "ui_systemset_window.h"
#include "test_window.h"
#include "portui_window.h"

QString systemSet::rootPath = "";

systemSet::systemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systemSet),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    group = new QButtonGroup(this);
    group->addButton(ui->Compression);
    group->addButton(ui->stretching);
    group->addButton(ui->Reciprocating);
    group->addButton(ui->Manually);
    group->addButton(ui->Customize);

    findAvailablePort();



    connect(this,&systemSet::thisShow,[=](){
        showTime = QDateTime::currentDateTime().toString("yyyyMMddhhmm");
        rootPath  = QCoreApplication::applicationDirPath()+QStringLiteral("/data/%1.csv").arg(showTime);
        ui->filePathEdit->setText(rootPath);
    });


    //connect(mainUiTest::myPort,&portUi::portConnected,&systemSet::freshPort);

}

systemSet::~systemSet()
{
    delete ui;
}




void systemSet::saveLabel(QString filePath)//保存csv文件并且更新port、motor和weigh地址
{
    materialDetails  materialdetail;

    QList<QStringList> data;

    materialdetail.userName = ui->ExperimenterEdit->text();
    data.append({"User",ui->ExperimenterEdit->text()});

    materialdetail.selfNumber = ui->timeNumberEdit->text().toInt();
    data.append({"Number",ui->timeNumberEdit->text()});

    materialdetail.material = ui->MaterialEdit->text();
    data.append({"Material",ui->MaterialEdit->text()});


    data.append({"Sample",ui->sampleEdit->text()});

    data.append({"CurrentTime",ui->currentTime->text()});

    materialdetail.materialArea = ui->areaEdit->text().toDouble();
    data.append({"area",ui->areaEdit->text()});

    materialdetail.materialLength = ui->lengthEdit->text().toDouble();
    data.append({"length",ui->lengthEdit->text()});

    materialdetail.materialCrossSectional = ui->sizeEdit->text();
    data.append({"size",ui->sizeEdit->text()});

    materialdetail.strainRate = ui->strainRateEdit->text().toInt();
    data.append({"strainRate",ui->strainRateEdit->text()});

    data.append({"more",ui->moreEdit->text()});
//    data.append({"strainRate",ui->strainRateEdit->text()});


    //操控方式↓
    QString testManner = "";
    QObject *selectBtn = group->checkedButton();
    if(selectBtn)
    {
        testManner = selectBtn->property("text").toString();
    }

    data.append({"test manner",testManner});

//    data.append({"strainRate",ui->strainRateEdit->text()});

    saveCsvFile(filePath,data);



}

void systemSet::saveCsvFile(QString filePath,QList<QStringList> data)
{
    if(filePath.mid(filePath.length()-3,-1)!="csv")
    {
        m_snackbar->addMessage(fileError[ChineseOrEnglish]);
        return;
    }

    QFile labelFile(filePath);

    if(!labelFile.open(QIODevice::ReadOnly))
    {
        if(!labelFile.open(QIODevice::WriteOnly))
        {
            m_snackbar->addMessage(filePathError[ChineseOrEnglish]);
            return;
        }
        else {
            m_snackbar->addMessage(saveSucess[ChineseOrEnglish]);
        }
    }
    else {
        m_snackbar->addMessage(alreadyHaveFile[ChineseOrEnglish]);
        return;
    }

    for (int i =0;i<data.length();i++)
    {
        for (int j = 0;j<data[i].length();j++)
        {
            labelFile.write(data[i][j].toUtf8().toStdString().c_str());
            labelFile.write(",");
        }
        labelFile.write("\n");
    }
    labelFile.close();

}


void systemSet::findAvailablePort()
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo &serialPortInfo, serialPorts)
    {
        ui->SerialPort->addItem(serialPortInfo.portName());
    }

    QStringList  baundRateList={"4800","9600","19200","28800","38400"};
    ui->baudRate->addItems(baundRateList);


    QStringList number = {"1","2","3"};
    ui->driveBox->addItems(number);
    ui->sensorBox->addItems(number);
    ui->limits->addItems(number);

    QStringList  samplingRateList={"1000","1500","2000","2500","3000"};
    ui->samplingRate->addItems(samplingRateList);

}

void systemSet::on_portRefresh_clicked()
{
    findAvailablePort();
}

bool systemSet::on_portConnect_clicked()
{
    bool openFlag = false;
    if(ui->portConnect->text()=="连接")
    {
        mainUiTest::myPort->setPortName(ui->SerialPort->currentText());
        mainUiTest::myPort->setBaudRate(ui->baudRate->currentText().toInt());

        openFlag= mainUiTest::myPort->open(QIODevice::ReadWrite);

        if(openFlag)ui->portConnect->setText("断开");
    }
    else {
        mainUiTest::myPort->close();
        ui->portConnect->setText("连接");
    }
    return openFlag;
}

void systemSet::on_submitBtn_clicked()
{
    rootPath = ui->filePathEdit->text();
    emit saveSet(rootPath);
}

void systemSet::on_cancelBtn_clicked()
{
    emit cancelSet();
}
