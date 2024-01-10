#include "widget.h"
#include "ui_widget.h"

QSerialPort *Widget::myPort = new QSerialPort();

void Widget::findAvailablePort()
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo &serialPortInfo, serialPorts)
    {
        qDebug()<<serialPortInfo.portName();
    }
}

bool Widget::connectSerialPort(int baundRate,QString portName)
{
    myPort->setPortName(portName);
    myPort->setBaudRate(baundRate);
    bool openFlag = myPort->open(QIODevice::ReadWrite);
    return openFlag;
}
