#ifndef HEADERS_H
#define HEADERS_H

#include"command.h"

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
#include<QString>
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

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QtMath>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
//charts宏
QT_CHARTS_USE_NAMESPACE


//电机信息
struct motorDetails
{
    QString motorname;
    int motorID;


    double powerControl;

    double speed;

    double maxSpeed;//最大速度设置
    double pitch;//螺距

    double length;//运动距离
    double angleIncrement;

    double currentAngle;

};


//称重模块信息
struct weighDetails
{
    int address;

    double currentWeight;

    QList<QString> weighLogList;


};

//材料信息
struct materialDetails
{
    QString userName;
    QString TimeNumber;

    int selfNumber;

    QString material;//材质
    QString materialCrossSectional;//材料尺寸
    double materialLength;//材料长
    double materialArea;//材料横截面积
    double strainRate;//应变率

};



//语料库
static QList<QString> logined = {"登录成功！","Login successful!"};
static QList<QString> unlogined = {"用户名或密码错误!","Wrong username or password!"};
static QList<QString> emptyEdit = {"请输入用户名或密码!","Please enter your username or password!"};

static QList<QString> signUpError = {"用户已存在!","The user already exists!"};
static QList<QString> signUpDone = {"注册成功!","Registration is successful!"};

static QList<QString> inconsistency = {"两次密码输入不一致!","The password is inconsistent twice!"};
static QList<QString> shortPassword = {"密码不少于6位!","The password is not less than 6 digits!"};
static QList<QString> filePathError = {"指定位置不存在!","The specified location does not exist!"};
static QList<QString> fileError = {"文件格式错误!","File format error!"};
static QList<QString> saveSucess = {"保存成功！","Save successfully!"};
static QList<QString> alreadyHaveFile = {"当前位置已存在文件,不可覆盖！","The file already exists in the current location and cannot be overwritten!"};

static QList<QString>openAndClosee ={ "当前位置已存在文件,不可覆盖！","The file already exists in the current location and cannot be overwritten!"};

static QList<QString> startTestFlag = {"测试开始！","The test begins!"};
static QList<QString> stopTestFlag = {"测试已停止！","Testing has been stopped!"};

static int ChineseOrEnglish = 0; //预料切换,用不了




#endif // HEADERS_H
