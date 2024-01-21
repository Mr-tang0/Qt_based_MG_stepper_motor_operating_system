#include "test_window.h"
#include "ui_test_window.h"

//静态成员初始化区
QSerialPort *mainUiTest::myPort = new QSerialPort();

Worker *mainUiTest::sendWork = new Worker();
decodeThread *mainUiTest::decodeWork = new decodeThread();

weigh* mainUiTest::myWeigh = new weigh;
motor* mainUiTest::myMotor = new motor;
materialDetails*  mainUiTest::material = new materialDetails;

QList<QStringList> mainUiTest::testLog = {{"time","stress","Theoretical displacement","Actual displacement"}};
//静态成员初始化区

void mainUiTest::initSystem()
{
    QString rootPath  = QCoreApplication::applicationDirPath();

    loadMotorDetails(rootPath+"/log/motor_log.json");
    loadWeighDetails(rootPath+"/log/weigh_log.json");

    refreshUi();

    //buttonTwinkling("motor_1","yellow",true);

}
void mainUiTest::refreshUi()//依靠此来更新界面同时记录数据
{
    double load = myWeigh->detail.currentWeight;
    ui->load->display(load);//载荷

    double Area= material->materialArea;
    double stress = myWeigh->detail.currentWeight/Area;
    ui->stress->display(stress);//应力

    double speed = myMotor->detail.speed;
    QTime currentTime = QTime::currentTime();
    double timeDifference = startTime.msecsTo(currentTime)/1000.0;//时间差
    double theoreticallyLengthDifference = timeDifference*speed;
    ui->displacement->display(theoreticallyLengthDifference);//计算位移,理论位移

    double displacement = myMotor->detail.currentAngle;
    ui->displacement_sensors->display(displacement);//传感器的实际位移

    ui->strain->display(0);//应变

    ui->Duration->display(timeDifference);//耗时

    //图像绘制


    //实验记录
    QStringList couple = {QString::number(timeDifference),//时间
                          QString::number(stress),//应力
                          QString::number(theoreticallyLengthDifference),//理论位移
                          QString::number(displacement)//实际位移
                         };
    testLog.append(couple);

}

void mainUiTest::saveMotor(QString filePath)
{
//********************


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

    Object["weighIndex"] = myWeigh->address;

    QString currentTime = QTime::currentTime().toString();
    QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");

    QString dateLog = QString::number(myWeigh->currentWeight)+QStringLiteral("_kg_%1_%2").arg(currentDate).arg(currentTime);
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

    Object["motorName"] = givenMotor->detail.motorname;
    Object["motorID"] = givenMotor->detail.motorID;

    Object["powerControl"] = givenMotor->detail.powerControl;

    Object["speedControl"] = givenMotor->detail.speed;
    Object["maxSpeed"] = givenMotor->detail.maxSpeed;

    Object["angleControl"] = givenMotor->detail.length;
    Object["angleIncrement"] = givenMotor->detail.angleIncrement;


    jsonDoc.setObject(Object);
    QString temp  = jsonDoc.toJson();
    motorfile.open(QIODevice::WriteOnly);
    motorfile.write(temp.toUtf8());
    motorfile.close();
}

void mainUiTest::loadWeighDetails(QString filePath)
{
    QFile motorfile(filePath);

    try {
        motorfile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(filePath);
        return;
    }

    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    motorfile.close();

    myWeigh->address = jsonObject["weighIndex"].toInt();

    for (int i =0;i<jsonObject["weightLog"].toArray().size();i++) {
        myWeigh->weighLogList.append(jsonObject["weightLog"].toArray()[i].toString());
    }


}


void mainUiTest::loadMotorDetails(QString filePath)
{

    QFile motorfile(filePath);

    try {
        motorfile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(filePath);
        return;
    }

    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    motorfile.close();

    motorDetails detail =
    {
        jsonObject["motorName_"].toString(),    //motorname:
        jsonObject["motorID_"].toInt(),         //motorID:
        jsonObject["powerControl_"].toDouble(), //powerControl:
        jsonObject["speedControl_"].toDouble(), //speedControl:
        jsonObject["maxSpeed_"].toDouble(),     //maxSpeed:
        jsonObject["angleControl_"].toDouble(), //angleControl:
        jsonObject["angleIncrement_"].toDouble()//angleIncrement:
    };
    myMotor->detail = detail;

}

void mainUiTest::recodeTest(QString filePath)
{
    QFile labelFile(filePath);
    if(!labelFile.open(QIODevice::Append|QIODevice::Text))
    {
        m_snackbar->addMessage(filePathError[ChineseOrEnglish]);
    }
    else {
        QTextStream out(&labelFile);

        for (int i = 0;i<testLog.length();i++)
        {
            for (int j = 0;j<testLog[i].length();j++)
            {
                out<<testLog[i][j].toUtf8().toStdString().c_str();
                out<<",";
            }
            out<<"\n";
        }
        labelFile.close();
    }
    m_snackbar->addMessage(saveSucess[ChineseOrEnglish]);
    qDebug()<<testLog;
}

void mainUiTest::mageDrawing()
{

}


