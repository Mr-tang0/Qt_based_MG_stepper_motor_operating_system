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
    QString motorname = "origal";
    int motorID = -1;

    int powerControl = -1;

    int speedControl = -1;
    int maxSpeed = -1;

    int angleControl = -1;
    int angleIncrement = -1;
};



#endif // HEADERS_H
