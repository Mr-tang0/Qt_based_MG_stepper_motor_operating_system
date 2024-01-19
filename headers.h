#ifndef HEADERS_H
#define HEADERS_H

#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>

#include <QFile>
#include <QTextStream>
#include <QButtonGroup>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QCoreApplication>

#include<QThread>
#include<QTimer>
#include<qmath.h>
#include<QPushButton>

#include<QTime>
#include<QDateTime>

#include <QByteArray>

#include <QCryptographicHash>
#include <QMessageBox>


#include "qtmaterialsnackbar.h"
#include "qtmaterialflatbutton.h"

//#include <QWebEngineView>
#include<QAction>

#include<QHBoxLayout>
#include<QStackedLayout>
#include<QListWidget>

#include <QList>
#include <QPointF>
#include <QPainterPath>
#include <QVector>
#include <QPainter>

#include<QLineEdit>


struct motorDetails
{
    QString motorname;
    int motorID;

    double powerControl;

    double speedControl;
    double maxSpeed;

    double angleControl;
    double angleIncrement;

    double currentAngle;

};

struct weighDetails
{
    int address;

    double currentWeight;

    QList<QString> weighLogList;


};

struct materialDetails
{
    double materialCrossSectional;



};




#endif // HEADERS_H
