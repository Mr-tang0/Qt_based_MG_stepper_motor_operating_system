#include "formfill.h"
#include "ui_formfill.h"
#include "test_window.h"

QString FormFill::rootPath = "";

FormFill::FormFill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFill),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    connect(ui->radioBtnGroup,QOverload<int>::of(&QButtonGroup::buttonClicked),[=](int id){
        ui->menu->setCurrentIndex(abs(id+2));


    });


    findAvailablePort();

    connect(this,&FormFill::thisShow,[=](){
        showTime = QDateTime::currentDateTime().toString("yyyyMMddhhmm");
        ui->timeNumberEdit->setText(showTime);
        ui->currentTime->setText(QTime::currentTime().toString());
        rootPath  = QCoreApplication::applicationDirPath()+QStringLiteral("/data/%1.csv").arg(showTime);
        ui->filePathEdit->setText(rootPath);
        ui->ExperimenterEdit->setText("UserName");
    });


    //connect(mainUiTest::myPort,&portUi::portConnected,&systemSet::freshPort);

}

FormFill::~FormFill()
{
    delete ui;
}

void FormFill::saveLabel(QString filePath)//保存csv文件并且更新port、motor和weigh地址
{
    materialDetails  materialdetail;

    QList<QStringList> data;

    materialdetail.userName = ui->ExperimenterEdit->text();
    data.append({"User",ui->ExperimenterEdit->text()});//用户

    materialdetail.selfNumber = ui->timeNumberEdit->text().toInt();
    data.append({"Number",ui->timeNumberEdit->text()});//编号

    materialdetail.material = ui->MaterialEdit->text();
    data.append({"Material",ui->MaterialEdit->text()});//材质

    data.append({"Sample",ui->sampleEdit->text()});//样式

    mainUiTest::myMotor->detail.motorID = ui->driveBox->currentText().toInt();
    data.append({"driveBox",ui->driveBox->currentText()});//电机地址

    mainUiTest::myWeigh->detail.address = ui->sensorBox->currentText().toInt();
    data.append({"sensorBox",ui->sensorBox->currentText()});//称重传感器地址

    //限位器还没有
    data.append({"limits",ui->limits->currentText()});//限位地址

    mainUiTest::sampleRate = ui->samplingRate->currentText().toInt();
    data.append({"samplingRate",ui->samplingRate->currentText()});//采样率


    data.append({"CurrentTime",QDateTime::currentDateTime().toString("yyyy-MM-dd-")+ui->currentTime->text()});//当前时间

    materialdetail.materialArea = ui->areaEdit->text().toDouble();
    data.append({"area",ui->areaEdit->text()});//很截面积

    materialdetail.materialLength = ui->lengthEdit->text().toDouble();
    data.append({"length",ui->lengthEdit->text()});//长度

    materialdetail.materialCrossSectional = ui->sizeEdit->text();
    data.append({"size",ui->sizeEdit->text()});//尺寸略

    materialdetail.strainRate = ui->strainRateEdit->text().toInt();
    data.append({"strainRate",ui->strainRateEdit->text()});//应变率

    data.append({"more",ui->moreEdit->text()});




    //操控方式↓
    QString testManner = "";
    QObject *selectBtn = ui->radioBtnGroup->checkedButton();
    if(selectBtn)
    {
        testManner = selectBtn->property("text").toString();
        int id = abs(ui->radioBtnGroup->checkedId()+2);
    }
    data.append({"test_manner",testManner});

    //记录不同操控方式得出的系统参数


//    data.append({"strainRate",ui->strainRateEdit->text()});

    saveCsvFile(filePath,data);



}


void FormFill::resetClass()
{
    for (auto edit:findChildren<QLineEdit*>())
    {
        edit->clear();
    }

    for (auto Box:findChildren<QDoubleSpinBox*>())
    {
        Box->clear();
    }
    showTime = QDateTime::currentDateTime().toString("yyyyMMddhhmm");
    rootPath  = QCoreApplication::applicationDirPath()+QStringLiteral("/data/%1.csv").arg(showTime);
    ui->filePathEdit->setText(rootPath);
}


void FormFill::saveCsvFile(QString filePath,QList<QStringList> data)
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


void FormFill::findAvailablePort()
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

    QStringList  samplingRateList;
    for (int i = 1;i<5000;i=i+100)
    {
        samplingRateList.append(QString::number(i));
    }
    ui->samplingRate->addItems(samplingRateList);

}
void FormFill::radioBtnChecked(int id)
{
    qDebug()<<id;
}

void FormFill::on_portRefresh_clicked()
{
    findAvailablePort();
}


bool FormFill::on_portConnect_clicked()
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

void FormFill::on_submitBtn_clicked()
{
    rootPath = ui->filePathEdit->text();
    emit saveSet(rootPath);
}

void FormFill::on_cancelBtn_clicked()
{
    emit cancelSet();
}
