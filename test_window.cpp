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
    startTimer->start(20); //ui固定刷新

    // connect(sendTimer,&QTimer::timeout,this,[=](){
    //     //查询位置和力

    //     myWeigh->getWeight();
    //     myMotor->getLength();

    // });

}

mainUiTest::~mainUiTest()
{
    delete ui;
}



void mainUiTest::on_startTest_clicked()
{
    startTime = QTime::currentTime();//get start time

    datasave->runFunc(1000/material->sampleRate,true);//开启查询计时器（按照采样率）



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

    m_snackbar->addMessage(material->testManner+"中");
}

void mainUiTest::on_stopTest_clicked()
{
    datasave->runFunc(false);
    myMotor->stop();
    QTime temp;
    startTime = temp;

}



void mainUiTest::on_newTest_clicked()
{
    emit newTest();
}

void mainUiTest::on_saveTest_clicked()
{
    recodeTest(FormFill::rootPath);
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
    myMotor->angleMove(0,5);
}

void mainUiTest::on_setLengthZero_clicked()
{
    myWeigh->setSensitivity(60000,1);
}


void mainUiTest::on_setWeighZero_clicked()
{
    myWeigh->shelling();
}


void mainUiTest::on_UP_clicked()
{
    datasave->runFunc(1000/material->sampleRate,true);
    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(speed);

    if(!startTimer->isActive())
    {
        startTimer->start(24); //ui固定刷新
    }


}


void mainUiTest::on_Down_clicked()
{
    datasave->runFunc(1000/material->sampleRate,true);

    double speed = ui->matulSpeed->text().toDouble();
    myMotor->speedMove(-speed);


    if(!startTimer->isActive())
    {
        startTimer->start(24); //ui固定刷新
    }

}


void mainUiTest::on_stop_clicked()
{
    datasave->runFunc(false);
    myMotor->stop();
    sendTimer->stop();
}



