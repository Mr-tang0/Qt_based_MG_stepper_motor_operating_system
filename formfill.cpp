#include "formfill.h"
#include "ui_formfill.h"
#include "test_window.h"
#include "login_window.h"

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


    resetThis();
    findAvailablePort();

    connect(this,&FormFill::thisShow,[=](){
        resetThis();

    });

}

FormFill::~FormFill()
{
    delete ui;
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
    for (int i = 20;i<=400;i=i+20)
    {
        samplingRateList.append(QString::number(i));
    }
    ui->samplingRate->addItems(samplingRateList);

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


void FormFill::saveLabel(QString filePath)//保存csv文件并且更新port、motor和weigh地址
{
    QList<QStringList> data;
    //填材料信息
    {
    //用户
        mainUiTest::material->userName= ui->ExperimenterEdit->text();
    data.append({"User",ui->ExperimenterEdit->text()});

    //编号
    mainUiTest::material->selfNumber = ui->timeNumberEdit->text().toInt();
    data.append({"Number",ui->timeNumberEdit->text()});

    //材质
    mainUiTest::material->material = ui->MaterialEdit->text();
    data.append({"Material",ui->MaterialEdit->text()});

    //样式
    mainUiTest::material->materialtype = ui->sampleEdit->text();
    data.append({"Sample",ui->sampleEdit->text()});

    //很截面积
    mainUiTest::material->materialArea = ui->areaEdit->text().toDouble();
    data.append({"area",ui->areaEdit->text()});

    //长度
    mainUiTest::material->materialLength = ui->lengthEdit->text().toDouble();
    data.append({"length",ui->lengthEdit->text()});

    //尺寸略
    mainUiTest::material->materialCrossSectional = ui->sizeEdit->text();
    data.append({"size",ui->sizeEdit->text()});

    //应变率
    mainUiTest::material->strainRate = ui->strainRateEdit->text().toInt();
    data.append({"strainRate",ui->strainRateEdit->text()});

    //采样率
    mainUiTest::material->sampleRate = ui->samplingRate->currentText().toInt();
    data.append({"samplingRate",ui->samplingRate->currentText()});

    //操控方式↓
    QString testManner = "";
    QObject *selectBtn = ui->radioBtnGroup->checkedButton();
    if(selectBtn)testManner = selectBtn->property("text").toString();
    mainUiTest::material->testManner = testManner;
    data.append({"testManner",testManner});

    }

    //填电机信息
    {
        //电机地址
        mainUiTest::myMotor->detail.motorID = ui->driveBox->currentText().toInt();
        data.append({"driveBox",ui->driveBox->currentText()});

        //电机速度
        mainUiTest::myMotor->detail.speed = ui->motorSpeed->text().toDouble();
        data.append({"motorSpeed",ui->motorSpeed->text()});

        //电机最大速度
        mainUiTest::myMotor->detail.maxSpeed = ui->maxMotorSpeed->text().toDouble();
        data.append({"maxMotorSpeed",ui->maxMotorSpeed->text()});

        //运动距离
        mainUiTest::myMotor->detail.length = ui->motorLength->text().toDouble();
        data.append({"motorLength",ui->motorLength->text()});

        //最大运动距离
        mainUiTest::myMotor->detail.maxLength = ui->maxMotorLength->text().toDouble();
        data.append({"maxMotorLength",ui->maxMotorLength->text()});

        //往返运动周期
        mainUiTest::myMotor->detail.cycle = ui->motorCircle->text().toDouble();
        data.append({"motorCircle",ui->motorCircle->text()});

        //螺距在配置文件中初始化、
        //当前位置时刻改变并存入配置文件
    }

    //填称重模块
    {
        //称重传感器地址
        mainUiTest::myWeigh->detail.address = ui->sensorBox->currentText().toInt();
        data.append({"sensorBox",ui->sensorBox->currentText()});

        //恒力
        mainUiTest::myWeigh->detail.force = ui->weighForce->text().toDouble();
        data.append({"weighForce",ui->weighForce->text()});

        //最大恒力
        mainUiTest::myWeigh->detail.maxForce = ui->maxWeighForce->text().toDouble();
        data.append({"maxWeighForce",ui->maxWeighForce->text()});

        //当前质量实时更新
    }


    //限位器还没有
    // data.append({"limits",ui->limits->currentText()});//限位地址

    //时间
    data.append({"CurrentTime",QDateTime::currentDateTime().toString("yyyy-MM-dd-")+ui->currentTime->text()});//当前时间

    data.append({"more",ui->moreEdit->text()});

    saveCsvFile(filePath,data);
}

void FormFill::resetThis()
{
    currentName = Login::currentName;
    qDebug()<<currentName;

    for (auto edit:findChildren<QLineEdit*>())
    {
        edit->clear();
    }

    for (auto Box:findChildren<QDoubleSpinBox*>())
    {
        Box->clear();
    }

    showTime = QDateTime::currentDateTime().toString("yyyyMMddhhmm");
    ui->timeNumberEdit->setText(showTime);
    ui->currentTime->setText(QTime::currentTime().toString());
    rootPath  = QCoreApplication::applicationDirPath()+QStringLiteral("/users/data/%1_%2.csv").arg(currentName).arg(showTime);
    ui->filePathEdit->setText(rootPath);
    ui->ExperimenterEdit->setText(currentName);
}


void FormFill::saveCsvFile(QString filePath,QList<QStringList> data)
{
    if(filePath.mid(filePath.length()-3,-1)!="csv")
    {
        m_snackbar->addMessage("文件格式错误!");
        return;
    }

    QFile labelFile(filePath);

    if(!labelFile.open(QIODevice::ReadOnly))
    {
        if(!labelFile.open(QIODevice::WriteOnly))
        {
            m_snackbar->addMessage("指定位置不存在!");
            return;
        }
        else {
            m_snackbar->addMessage("保存成功！");
        }
    }
    else {
        m_snackbar->addMessage("当前位置已存在文件,不可覆盖！");
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


void FormFill::on_portRefresh_clicked()
{
    findAvailablePort();
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
