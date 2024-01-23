#include "motor.h"
#include "test_window.h"

motor::motor(QObject *parent) : QObject(parent)
{

}

//拉伸
void motor::modeStretch()
{
    angleMove();//开始运动
}

//压缩
void motor::modeCompress()
{
    detail.length = -detail.length;//反向

    angleMove();//开始运动
}

//往复
void motor::modereciprocate()
{
    InquireTimer->start(detail.cycle);//周期

    connect(InquireTimer,&QTimer::timeout,[=]()
    {
        angleMove();//开始运动
        detail.length = -detail.length;//反向
    });

}

//恒力
void motor::modeConstant()
{

    angleMove();//开始运动

    InquireTimer->start(20);
    connect(InquireTimer,&QTimer::timeout,[=]()
    {
        if(mainUiTest::myWeigh->detail.currentWeight<mainUiTest::myWeigh->detail.force)
        {
            angleMove();//开始运动
        }

        if(mainUiTest::myWeigh->detail.currentWeight>0.8*mainUiTest::myWeigh->detail.force)//当前力值大于设定值的8成
        {
            detail.speed = detail.speed/2;//速度减半
        }

        if(mainUiTest::myWeigh->detail.currentWeight>mainUiTest::myWeigh->detail.force)//当前力值大于设定值
        {
            stop();//停止
        }

    });
}


bool motor::open()
{
    int address = detail.motorID;
    QString command = motorcmd.motorOpenCMD.arg(QString::number(address,16));

    QByteArray openData = buildCmdData(command);

    bool openFlag = mainUiTest::sendWork->sendMessage(openData);
    return openFlag;
}

bool motor::close()
{
    int address = detail.motorID;

    QString command = motorcmd.motorCloseCMD.arg(QString::number(address,16));

    QByteArray closeData = buildCmdData(command);

    bool closeFlag = mainUiTest::sendWork->sendMessage(closeData);
    return closeFlag;
}

bool motor::stop()
{
    int address = detail.motorID;
    QString command = motorcmd.motorStopCMD.arg(QString::number(address,16));
    QByteArray stopData = buildCmdData(command);

    bool stopFlag = mainUiTest::sendWork->sendMessage(stopData);
    return stopFlag;
}

void motor::speedMove()
{
    int address = detail.motorID;
    QString command = motorcmd.speedConcrolCMD.arg(QString::number(address,16));

    QByteArray moveCMD = buildCmdData(command);

    mainUiTest::sendWork->sendMessage(moveCMD);

    //speed : mm/s        speed/pitch : r/s          36000*speed/pitch : 度%/s

    double speed = detail.speed;
    // speed = 0.01;
    double pitch = detail.pitch;//螺距mm
    // pitch = 0.01;
    QString speedBit = QString::number(int(36000*speed/pitch),16);

    int length = 8-speedBit.length();


    if (length>0)
    for(int i = 0;i<length;i++)
    {
        speedBit = "0"+speedBit;
    }

    QStringList speedChange;
    for(int i = 0; i<(speedBit).length()/2;i++)
    {
        speedChange.prepend((speedBit).mid(i*2,2));
    }
    qDebug()<<speedChange<<speedBit;
//    QStringList speedChange = {speedBit.mid(6,2),speedBit.mid(4,2),speedBit.mid(2,2),speedBit.mid(0,2)};

    QString temp = motordata.speedConcrolDATA.arg(speedChange[0]).arg(speedChange[1]).arg(speedChange[2]).arg(speedChange[3]);

    QByteArray moveData = buildCmdData(temp);

    mainUiTest::sendWork->sendMessage(moveData);

}

void motor::angleMove()//根据motor.detail的angle和speed值进行运动，不同的运动方式应该修改其值
{
    //指令
    int address = detail.motorID;
    QString command = motorcmd.angleConcrolCMD2.arg(QString::number(address,16));

    QByteArray moveCMD = buildCmdData(command);

    mainUiTest::sendWork->sendMessage(moveCMD);

    //数据
    double moveLength = detail.length;//运动距离
    double pitch = detail.pitch;//螺距mm
    double maxSpeed = detail.maxSpeed;//最大速度

    // moveLength = pitch = maxSpeed = 0.01;
    //moveLength : mm        moveLength/pitch : r          36000*moveLength/pitch : 度%

    QString maxSpeedBit = QString::number(int(36000*maxSpeed/pitch),16);

    int length = 8-maxSpeedBit.length();
    if (length>0)
    for(int i = 0;i<length;i++)
    {
        maxSpeedBit = "0"+maxSpeedBit;
    }

    QString lengthBit = QString::number(int(36000*moveLength/pitch),16);

    length = 16-lengthBit.length();
    if (length>0)
    for(int i = 0;i<length;i++)
    {
        lengthBit = "0"+lengthBit;
    }


    QStringList angleConcrolChange;
    for(int i = 0; i<(lengthBit+maxSpeedBit).length()/2;i++)
    {
        angleConcrolChange.prepend((lengthBit+maxSpeedBit).mid(i*2,2));
    }
    QString temp;
    for(int i = 0; i<(lengthBit+maxSpeedBit).length()/2;i++)
    {
        temp = temp+angleConcrolChange[i]+" ";
    }

    QByteArray moveData = buildCmdData(temp);

    mainUiTest::sendWork->sendMessage(moveData);


}

bool motor::writeParam()//将motor detail的值发送给电机
{

    int address = detail.motorID;
    QString command = motorcmd.writeParameterToROMCMD.arg(QString::number(address,16));
    QByteArray writeData = buildCmdData(command);

    bool writeFlag = mainUiTest::sendWork->sendMessage(writeData);



    //参数还未写入
    return writeFlag;
}

bool motor::readState1()
{
    int address = detail.motorID;
    QString command = motorcmd.readMotorState1CMD.arg(QString::number(address,16));
    QByteArray readMotorState1Data = buildCmdData(command);

    bool readMotorState1DataFlag = mainUiTest::sendWork->sendMessage(readMotorState1Data);
    return readMotorState1DataFlag;
}

bool motor::readState2()
{
    int address = detail.motorID;
    QString command = motorcmd.readMotorState2CMD.arg(QString::number(address,16));
    QByteArray readMotorState2Data = buildCmdData(command);

    bool readMotorState2DataFlag = mainUiTest::sendWork->sendMessage(readMotorState2Data);
    return readMotorState2DataFlag;
}

bool motor::readState3()
{
    int address = detail.motorID;
    QString command = motorcmd.readMotorState3CMD.arg(QString::number(address,16));
    QByteArray readMotorState3Data = buildCmdData(command);

    bool readMotorState3DataFlag = mainUiTest::sendWork->sendMessage(readMotorState3Data);
    return readMotorState3DataFlag;
}

bool motor::clearError()
{
    int address = detail.motorID;
    QString command = motorcmd.clearMotorErrorCMD.arg(QString::number(address,16));
    QByteArray clearMotorErrorData = buildCmdData(command);

    bool clearMotorErrorFlag = mainUiTest::sendWork->sendMessage(clearMotorErrorData);
    return clearMotorErrorFlag;
}


void motor::getLength()
{
    int address = detail.motorID;
    QString command = motorcmd.readmotorangleCMD.arg(QString::number(address,16));
    QByteArray readmotorangleData = buildCmdData(command);

    mainUiTest::sendWork->sendMessage(readmotorangleData);
}


//命令帧,参数：地址，操作字，数据帧长度
QByteArray motor::buildCmdData(QString command)
{

    QString temp_data = command;
    while (temp_data.right(1)==" ") {
        temp_data.remove(temp_data.length()-1,1);
    }
    //构建命令帧
    QByteArray builtData;
    bool ok;
    for (const auto &chunk : temp_data.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "转换失败,数据存在错误" ;
            return "";
        }
        else
        {
            builtData.append(char(byteValue));
        }
    }

    //构建数据校验
    builtData = builtData+verifySUM(temp_data);

    //qDebug()<<"debug from buildCmdData"<<builtData.toHex();

    return builtData;

}

QByteArray motor::verifySUM(QString data)
{
    bool ok;
    uint num = 0;
    QByteArray builtData;

    for (const auto &chunk : data.split(" "))
    {
        uint temp = chunk.toUInt(&ok,16);
        if(ok)num = num + temp;
    }

    uchar byteValue = uchar(num) & 0x00ff;//注意这里的校验是舍弃高8位的

    builtData.append(char(byteValue));
    //qDebug()<<"debug from verifySUM"<<builtData.toHex();
    return builtData;
}



