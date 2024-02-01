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
    int motorID;//地址

    double speed;//速度
    double maxSpeed;//最大速度设置
    double length;//运动距离
    double maxLength;//最大运动距离

    double cycle;//往返运动周期

    double pitch;//螺距
    double currentAngle;//当前运动距离

    double zero;//约定0点
    double Backlash;//背隙补偿值

};


//称重模块信息
struct weighDetails
{
    int address;//地址

    double force;//恒力模式恒力
    double maxForce;//恒力模式最大恒力

    double currentWeight;//当前力
    double resolution;//分辨率

};

//材料信息
struct materialDetails
{
    QString userName;//用户名
    int selfNumber;//编号
    QString material;//材质
    QString materialtype;//材质样式

    double materialArea;//材料横截面积
    double materialLength;//材料长
    QString materialCrossSectional;//材料尺寸
    double strainRate;//应变率

    QString other;// 其他
    int sampleRate;//采样率

    QString testManner;//试验方式

};



// 语料库QString
static QStringList logined = {"登录成功！","Login successful!"};

static QStringList unlogined = {"用户名或密码错误!","Wrong username or password!"};
static QStringList emptyEdit = {"请输入用户名或密码!","Please enter your username or password!"};

static QStringList signUpError = {"用户已存在!","The user already exists!"};
static QStringList signUpDone = {"注册成功!","Registration is successful!"};

static QStringList inconsistency = {"两次密码输入不一致!","The password is inconsistent twice!"};
static QStringList shortPassword = {"密码不少于6位!","The password is not less than 6 digits!"};
static QStringList filePathError = {"指定位置不存在!","The specified location does not exist!"};
static QStringList fileError = {"文件格式错误!","File format error!"};
static QStringList saveSucess = {"保存成功！","Save successfully!"};
static QStringList alreadyHaveFile = {"当前位置已存在文件,不可覆盖！","The file already exists in the current location and cannot be overwritten!"};

static QStringList startTestFlag = {"测试开始！","The test begins!"};
static QStringList stopTestFlag = {"测试已停止！","Testing has been stopped!"};








#endif // HEADERS_H
