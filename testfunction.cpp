#include "test_window.h"
#include "ui_test_window.h"
#include <QtCharts/QChart>
#include <QtCharts/QChartView>


//charts宏
QT_CHARTS_USE_NAMESPACE

//静态成员初始化区
QSerialPort *mainUiTest::myPort = new QSerialPort();

Worker *mainUiTest::sendWork = new Worker();
decodeThread *mainUiTest::decodeWork = new decodeThread();

weigh* mainUiTest::myWeigh = new weigh;
motor* mainUiTest::myMotor = new motor;
materialDetails*  mainUiTest::material = new materialDetails;
WE20x * mainUiTest::we20x = new WE20x;

int mainUiTest::freshrate = 0;
//静态成员初始化区

void mainUiTest::initSystem()
{
    we20x->writeRegister(4,true);

    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    QThread *sendThread = new QThread;
    sendWork->moveToThread(sendThread);//sendWork进入子线程，有关于收发的函数均在子线程中执行
    sendWork->openReseiveChannal();//开接收

    QThread *decoThread = new QThread;
    decodeWork->moveToThread(decoThread);//decodeWork进入子线程，有关于解码的函数均在子线程中执行

    QThread *dataThread = new QThread;

    datasave->moveToThread(dataThread);

    connect(sendWork,&Worker::ReseiveMassage,[=](QString massage){
        decodeWork->decodeMessage(massage);
    });

    ui->graphicsView->setChart(chart);

    refreshUi();


}
void mainUiTest::refreshUi()//依靠此来更新界面同时记录数据(no!!)
{
    //载荷
    double load = myWeigh->detail.currentWeight;
    ui->load->display(QString::number(load,'f',2));

    //应力
    double stress = myWeigh->detail.currentWeight/material->materialArea;
    ui->stress->display(QString::number(stress,'f',2));

    //计算位移,理论位移
    QTime currentTime = QTime::currentTime();

    double timeDifference = startTime.msecsTo(currentTime)/1000.0;//时间差

    double theoreticallyLengthDifference = timeDifference*myMotor->detail.speed;
    ui->displacement->display(QString::number(theoreticallyLengthDifference,'f',2));

    //传感器的实际位移
    double displacement = myMotor->detail.currentAngle;

    ui->displacement_sensors->display(QString::number(displacement,'f',2));

    ui->strain->display(0);//应变????

    //耗时
    ui->Duration->display(QString::number(timeDifference,'f',2));

    //图像绘制
    drawer();



}


void mainUiTest::drawer()
{
    factSeries = dataSave::tempSeries;

    factSeries->setColor((100,100,100));
    if(!chart->series().isEmpty())chart->removeSeries(factSeries);
    chart->addSeries(factSeries);

    chart->legend()->hide();
    chart->createDefaultAxes();

}


void mainUiTest::saveMotor(QString filePath)
{
    saveJson(myMotor,filePath);
    refreshUi();
}


void mainUiTest::saveWeigh(QString filePath,bool clear)
{
    QFile weighfile(filePath);
    weighfile.open(QIODevice::ReadOnly);
    QByteArray jsonData = weighfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject Object = jsonDoc.object();
    weighfile.close();


    Object["weighIndex"] = myWeigh->detail.address;

    QString currentTime = QTime::currentTime().toString();
    QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");

    QString dateLog = QString::number(myWeigh->detail.currentWeight)+QStringLiteral("_kg_%1_%2").arg(currentDate).arg(currentTime);
    Object["leastWeight"] = dateLog;


    QJsonArray weightLog = Object["weightLog"].toArray();
    weightLog.append(dateLog);

    if(clear)weightLog = {};

    //ui->weightText->append(dateLog);
    Object["weightLog"] = weightLog;

    jsonDoc.setObject(Object);
    QString temp  = jsonDoc.toJson();
    weighfile.open(QIODevice::WriteOnly);
    weighfile.write(temp.toUtf8());
    weighfile.close();


}


void mainUiTest::buttonTwinkling(QString btnName,QString color,bool flag)//timer的生命周期有问题
{

    QPushButton *btn = new QPushButton;
    btn = findChild<QPushButton*>(btnName);

    if(flag)
    {
        int twinklingFlag = 1;
        connect(twinker,&QTimer::timeout,[=,&twinklingFlag](){

            if(twinklingFlag==1){
                btn->setStyleSheet(QStringLiteral("background-color: %1").arg(color));
                twinklingFlag = 0;
            }
            else
            {
                btn->setStyleSheet("background-color: white");
                twinklingFlag = 1;
            }
        });
        twinker->start(250);
    }
    else
    {
        btn->setStyleSheet("background-color: white");
        twinker->stop();
    }

}

void mainUiTest::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}

void mainUiTest::saveJson(motor* givenMotor,QString filePath)
{
    QFile motorfile(filePath);
    motorfile.open(QIODevice::ReadOnly);
    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    motorfile.close();

    QJsonObject Object = jsonDoc.object();

    // Object["motorName"] = givenMotor->detail.motorname;
    Object["motorID"] = givenMotor->detail.motorID;

    // Object["powerControl"] = givenMotor->detail.powerControl;

    Object["speedControl"] = givenMotor->detail.speed;
    Object["maxSpeed"] = givenMotor->detail.maxSpeed;

    Object["angleControl"] = givenMotor->detail.length;
    // Object["angleIncrement"] = givenMotor->detail.angleIncrement;


    jsonDoc.setObject(Object);
    QString temp  = jsonDoc.toJson();
    motorfile.open(QIODevice::WriteOnly);
    motorfile.write(temp.toUtf8());
    motorfile.close();
}



void mainUiTest::recodeTest(QString filePath)
{

    bool flag  = datasave->saveFact(filePath);
    if(!flag)
    {
        m_snackbar->addMessage("指定位置不存在!");
    }
    else
    {
        m_snackbar->addMessage("保存成功！");
    }
}


 void mainUiTest::resetThis()
 {
    freshrate = 0;
    myMotor->getLength();//读当前位置
    myWeigh->getWeight();//读当前位置
    delay(10);


    //所有显示模块归零
    for (auto LCD:findChildren<QLCDNumber*>())
    {
       LCD->display(0.);
    }
    datasave->resetThis();
    //图像序列删除
    factSeries->clear();
 }

