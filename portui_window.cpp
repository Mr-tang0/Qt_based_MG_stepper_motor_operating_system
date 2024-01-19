#include "portui_window.h"
#include "ui_portui_window.h"
#include "test_window.h"


portUi::portUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portUi)
{
    ui->setupUi(this);
    this->setWindowTitle("串口设置");
    findAvailablePort();
}

portUi::~portUi()
{
    delete ui;
}

void portUi::findAvailablePort()
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo &serialPortInfo, serialPorts)
    {
        ui->portName->addItem(serialPortInfo.portName());
    }
    QStringList  baundRateList={"4800","9600","19200","28800","38400"};
    foreach(QString item,baundRateList)
    {
        ui->baundRate->addItem(item);
    }
}

bool portUi::connectSerialPort(int baundRate,QString portName)
{
    mainUiTest::myPort->setPortName(portName);
    mainUiTest::myPort->setBaudRate(baundRate);

    bool openFlag = mainUiTest::myPort->open(QIODevice::ReadWrite);
    return openFlag;
}

void portUi::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}

void portUi::on_connect_clicked()
{
    int baundRate = ui->baundRate->currentText().toInt();
    QString portName = ui->portName->currentText();
    bool openFlag = connectSerialPort(baundRate,portName);
    if(openFlag)
    {
        ui->connect->setStyleSheet("background-color: yellow");
        ui->text->setText(QStringLiteral("当前连接：%1\n波特率：%2").arg(portName).arg(baundRate));
    }
    else {
        mainUiTest::myPort->close();
        ui->connect->setStyleSheet("background-color: white");
        ui->text->setText("已断开");
    }

    emit portConnected(openFlag);
}
