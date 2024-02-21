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

    //图表绘制
    connect(startTimer,&QTimer::timeout,this,[=]()
    {
        refreshUi();
    });


    connect(sendTimer,&QTimer::timeout,this,[=](){
        //查询位置和力
        myWeigh->getWeight();
        myMotor->getLength();
    });

}

mainUiTest::~mainUiTest()
{
    delete ui;
}



void mainUiTest::on_startTest_clicked()
{

    startTime = QTime::currentTime();//get start time

    startTimer->start(20); //ui固定刷新
    sendTimer->start(1000/material->sampleRate);//开启查询计时器（按照采样率）

    myMotor->open();// open motor

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
    sendTimer->stop();
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
    startTime = QTime::currentTime();//get start time
    if(!startTimer->isActive())
    {
        startTimer->start(20); //ui固定刷新
    }
    if(!sendTimer->isActive())
    {
        sendTimer->start(1000/material->sampleRate);//开启查询计时器（按照采样率）
        qDebug()<<0.5*1000/material->sampleRate;
    }
    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(speed);
}


void mainUiTest::on_Down_clicked()
{
    startTime = QTime::currentTime();//get start time
    if(!startTimer->isActive())
    {
        startTimer->start(20); //ui固定刷新
    }
    if(!sendTimer->isActive())
    {
        sendTimer->start(1000/material->sampleRate);//开启查询计时器（按照采样率）
    }

    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(-speed);
}


void mainUiTest::on_stop_clicked()
{
    myMotor->stop();

    startTimer->stop();
    sendTimer->stop();
}



