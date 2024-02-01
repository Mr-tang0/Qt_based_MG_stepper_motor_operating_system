#include "test_window.h"
#include "ui_test_window.h"
#include "formfill.h"

mainUiTest::mainUiTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUiTest),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);

    initSystem();

    //图表绘制加采样
    connect(startTimer,&QTimer::timeout,this,[=]()
    {
        refreshUi();
    });

    //↓这是测试代码，timer的时间为上位机向下位机的状态查询周期，此周期必须小于采样周期，否则会失真


    connect(sendTimer,&QTimer::timeout,this,[=](){
        //查询位置和力
        myWeigh->getWeight();
        delay(15);
        myMotor->getLength();
        delay(15);

    });

    //↑这是测试代码，timer的时间为上位机向下位机的状态查询周期，此周期必须小于采样周期，否则会失真

    // connect(ui->startTest,&QPushButton::clicked,[=](){

    //     timer->start(1000/material->sampleRate);      //查询
    //     startTimer->start(1000/material->sampleRate); //采样

    // });

    // connect(ui->stopTest,&QPushButton::clicked,[=](){
    //     myMotor->stop();
    //     timer->stop();//查询
    //     startTimer->stop();//采样
    //     i =1;
    //     m_snackbar->addMessage("测试已停止！");


    // });

    // connect(ui->UP,&QPushButton::clicked,[=](){
    //     timer->start(1000/material->sampleRate);      //查询
    //     startTimer->start(1000/material->sampleRate); //采样
    // });


}

mainUiTest::~mainUiTest()
{
    delete ui;
}



void mainUiTest::on_startTest_clicked()
{

    startTime = QTime::currentTime();//get start time

    startTimer->start(1000/material->sampleRate); //开始采样更新ui:sampleRate设置采样率
    sendTimer->start(1000/material->sampleRate);//开启查询计时器

    myMotor->open();// open motor
    delay(5);

    ui->stateBox->append(material->testManner+"中");
    if(material->testManner == "拉伸")
    {
        myMotor->modeStretch();//拉伸
    }

    else if(material->testManner == "压缩")
    {
        myMotor->modeCompress();//压缩
    }

    else if(material->testManner == "往复加载")
    {

        myMotor->modereciprocate(myMotor->detail.cycle);//往复

    }
    else if(material->testManner == "恒力加载")
    {

        myMotor->modeConstant();//恒力

    }

    m_snackbar->addMessage("测试开始！");
}


void mainUiTest::on_newTest_clicked()
{
    emit newTest();
}

void mainUiTest::on_saveTest_clicked()
{
    recodeTest(FormFill::rootPath);
}

void mainUiTest::on_stopTest_clicked()
{
    startTimer->stop();
    sendTimer->stop();
}

void mainUiTest::on_emergency_clicked()
{
    myMotor->stop();
    myMotor->close();
    startTimer->stop();
    m_snackbar->addMessage("测试已停止！");
}

void mainUiTest::on_clearTest_clicked()
{
    resetThis();
}

void mainUiTest::on_setLengthZero_clicked()
{
    myMotor->detail.zero = myMotor->detail.currentAngle;
}


void mainUiTest::on_setWeighZero_clicked()
{
    myWeigh->shelling();
}


void mainUiTest::on_UP_clicked()
{
    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(speed);
}


void mainUiTest::on_Down_clicked()
{
    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(-speed);
}


void mainUiTest::on_stop_clicked()
{
    myMotor->stop();
}



void mainUiTest::on_moveTo_clicked()
{
    double length = ui->moveToEdit->text().toDouble();
    myMotor->angleMove(length,myMotor->detail.speed);
}

