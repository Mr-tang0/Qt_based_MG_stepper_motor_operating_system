#ifndef HEADERS_H
#define HEADERS_H

#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>

#include <QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QCoreApplication>

#include<QThread>
#include<QTimer>
#include<qmath.h>
#include<QPushButton>

struct motorDetails
{
    QString motorname;
    double motorID;

    double powerControl;

    double speedControl;
    double maxSpeed;

    double angleControl;
    double angleIncrement;
};




#endif // HEADERS_H
