﻿#ifndef MAINUITEST_H
#define MAINUITEST_H

#include <QWidget>
#include"headers.h"

#include"weigh.h"
#include"motor.h"
#include"worker.h"
#include "decodethread.h"

namespace Ui {
class mainUiTest;
}

class mainUiTest : public QWidget
{
    Q_OBJECT

public:

    explicit mainUiTest(QWidget *parent = nullptr);
    ~mainUiTest();

    void delay(int time);
    void buttonTwinkling(QString btnName, QString color, bool flag);
    void saveJson(motor* givenMotor,QString filePath);

    void resetThis();

    static QSerialPort *myPort;
    static motor* myMotor;
    static weigh* myWeigh;
    static materialDetails *material;

    static Worker *sendWork;
    static decodeThread *decodeWork;

    static QList<QStringList> testLog;//这是电机记录的位移和拉力模块记录的数据,每个QStringList是一对一的关系；

    QList<double> lengthList;
    QList<double> weightList;

    QTimer* twinker =new QTimer;

    static int freshrate;

protected:
    void initSystem();
    void refreshUi();
    void drawer();

    void saveMotor(QString filePath);
    void saveWeigh(QString filePath,bool clear);




private slots:

    void on_startTest_clicked();

    void on_newTest_clicked();

    void on_saveTest_clicked();

    void on_stopTest_clicked();

    void on_emergency_clicked();

    void on_clearTest_clicked();

    void on_setLengthZero_clicked();

    void on_setWeighZero_clicked();

    void on_UP_clicked();

    void on_Down_clicked();

    void on_stop_clicked();

signals:
    void newTest();
    void saveTest();

private:
    Ui::mainUiTest *ui;
    QtMaterialSnackbar  *const m_snackbar;

    QLineSeries *factSeries = new QLineSeries();
    QLineSeries *theroySeries = new QLineSeries();
    QChart *chart = new QChart();

    void recodeTest(QString filePath);

    QTimer *startTimer = new QTimer;//ui刷新计时器
    QTimer *sendTimer = new QTimer;//位置查询计时器

    QTime startTime;//测试开始时间

    QString filePath;//文件保存位置

    //以下是老代码

    // QPointF zero;

    // int frameWidth,frameHeight;

    // QValueAxis *axisY = new QValueAxis();
    // QValueAxis *axisX = new QValueAxis();

    // QVector<QPointF> datas;
    // QVector<QPointF> DATA;

    // QPainterPath pathNormal;

};

#endif // MAINUITEST_H
