#include "test_window.h"
#include "ui_test_window.h"
#include "mainwindow.h"

mainUiTest::mainUiTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUiTest),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);

    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    QThread *sendThread = new QThread;
    sendWork->moveToThread(sendThread);//sendWork进入子线程，有关于收发的函数均在子线程中执行
    sendWork->openReseiveChannal();//开接收

    QThread *decodeThread = new QThread;
    decodeWork->moveToThread(decodeThread);//decodeWork进入子线程，有关于解码的函数均在子线程中执行
    connect(sendWork,&Worker::ReseiveMassage,[=](QString massage){
        decodeWork->decodeMessage(massage);
    });

    initSystem();

    //图表绘制加采样
    connect(startTimer,&QTimer::timeout,[=]()
    {
        refreshUi();
    });

    //↓这是测试代码，timer的时间为上位机向下位机的状态查询周期，此周期必须小于采样周期，否则会失真
    QTimer *timer = new QTimer;


    static int i =1;
    connect(timer,&QTimer::timeout,[=](){
        //正常这两个值是decode里修改的，这里为了演示在计时器里更新，
        myWeigh->detail.currentWeight = i;//x
        myMotor->detail.currentAngle = abs(i*sin(i*0.01));//y

        myWeigh->getWeight();
        myMotor->getLength();
        i+=1;
    });
    //↑这是测试代码，timer的时间为上位机向下位机的状态查询周期，此周期必须小于采样周期，否则会失真

    connect(ui->startTest,&QPushButton::clicked,[=](){
        timer->start(50);      //查询
        startTimer->start(5); //采样

    });

    connect(ui->stopTest,&QPushButton::clicked,[=](){
        timer->stop();
        i =1;
    });



}

mainUiTest::~mainUiTest()
{
    delete ui;
}



void mainUiTest::on_startTest_clicked()
{
     startTime = QTime::currentTime();


//     startTimer->start(1000/sampleRate);//sampleRate设置采样率
     myMotor->open();
     myMotor->angleMove();
     m_snackbar->addMessage(startTestFlag[ChineseOrEnglish]);
}


void mainUiTest::on_newTest_clicked()
{
    emit newTest();
}


//开始测试，读电机设置，称重模块设置，测试参数（计算运动参数）
void mainUiTest::on_saveTest_clicked()
{
    recodeTest(FormFill::rootPath);

}

void mainUiTest::on_stopTest_clicked()
{
    myMotor->stop();
    startTimer->stop();
    m_snackbar->addMessage(stopTestFlag[ChineseOrEnglish]);
}

void mainUiTest::on_emergency_clicked()
{
    myMotor->stop();
    myMotor->close();
    startTimer->stop();
    m_snackbar->addMessage(stopTestFlag[ChineseOrEnglish]);
}

void mainUiTest::on_clearTest_clicked()
{
    datas.clear();
//    pathNormal.clear();
}
