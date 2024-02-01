#include "motor.h"
#include "test_window.h"

motor::motor(QObject *parent) : QObject(parent)
{

}

//拉伸
void motor::modeStretch()
{
    qDebug()<<"modeStretch"<<detail.length<<detail.speed;
    angleMove(detail.length,detail.speed);//开始运动
}

//压缩
void motor::modeCompress()
{

    angleMove(-detail.length,detail.speed);//开始运动
}

//往复
void motor::modereciprocate(double cycle)
{
    connect(InquireTimer,&QTimer::timeout,[=]()
    {
        if(Timerflag)
        {
            qDebug()<<"正转";
            angleMove(detail.length,detail.speed);//开始运动
        }
        else
        {
           qDebug()<<"反转";
           angleMove(-detail.length,detail.speed);//开始运动
        }
        // angleMove(i*detail.length,detail.speed);//开始运动
        Timerflag = !Timerflag;
    });
    InquireTimer->start(cycle);//周期
}

//恒力
void motor::modeConstant()
{

    speedMove(detail.speed);//开始运动

    InquireTimer->start(20);

    connect(InquireTimer,&QTimer::timeout,[=]()
    {
        if(mainUiTest::myWeigh->detail.currentWeight<mainUiTest::myWeigh->detail.force)
        {
            speedMove(detail.speed);//开始运动
        }

        if(mainUiTest::myWeigh->detail.currentWeight>0.8*mainUiTest::myWeigh->detail.force)//当前力值大于设定值的8成
        {
            speedMove(detail.speed/2);//开始运动
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
    // if(InquireTimer->isActive())
    // {
    //     InquireTimer->stop();
    // }
    bool stopFlag = mainUiTest::sendWork->sendMessage(stopData);
    return stopFlag;
}

void motor::speedMove(double moveSpeed)
{
    int address = detail.motorID;
    QString command = motorcmd.speedConcrolCMD.arg(QString::number(address,16));

    QByteArray moveCMD = buildCmdData(command);

    mainUiTest::sendWork->sendMessage(moveCMD);


    //speed : mm/s        speed/pitch : r/s          36000*speed/pitch : 度%/s

    double speed = moveSpeed;

    double pitch = detail.pitch;//螺距mm

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
    // qDebug()<<speedChange<<speedBit;
//    QStringList speedChange = {speedBit.mid(6,2),speedBit.mid(4,2),speedBit.mid(2,2),speedBit.mid(0,2)};

    QString temp = motordata.speedConcrolDATA.arg(speedChange[0]).arg(speedChange[1]).arg(speedChange[2]).arg(speedChange[3]);

    QByteArray moveData = buildCmdData(temp);

    mainUiTest::sendWork->sendMessage(moveData);


}

void motor::angleMove(double moveLen,double moveSpeed)
{
    qDebug()<<"angleMove"<<moveLen<<moveSpeed;
    //指令
    int address = detail.motorID;
    QString command = motorcmd.angleConcrolCMD2.arg(QString::number(address,16));

    QByteArray moveCMD = buildCmdData(command);

    mainUiTest::sendWork->sendMessage(moveCMD);

    //数据
    double moveLength = moveLen;//实际  运动距离

    double pitch = detail.pitch;//螺距mm

    //转换为16进制并取倒置
    QString lengthBit = QString::number(int(36000*moveLength/pitch),16);

    //补0
    int temp = lengthBit.length();

    for(int i = 0;i<16-temp;i++)
    {
        lengthBit = "0"+lengthBit;
    }

    //反转
    QString changelengthBit = "";
    for (int i = 0; i<lengthBit.length()/2;i++)
    {
        changelengthBit = lengthBit.mid(i*2,2)+changelengthBit;
    }

    QString speedBit = QString::number(int(36000*moveSpeed/pitch),16);

    //补0
    int temp2 = speedBit.length();

    for(int i = 0;i<8-temp2;i++)
    {
        speedBit = "0"+speedBit;
    }
    //反转
    QString changeSpeedBit = "";
    for (int i = 0; i<speedBit.length()/2;i++)
    {
        changeSpeedBit = speedBit.mid(i*2,2)+changeSpeedBit;
    }

    QString data = changelengthBit+changeSpeedBit;

    //补空位
    int temp3 = data.length();
    for (int i = 0;i<temp3/2;i++)
    {
        data.insert(2*i+i," ");
    }

    QByteArray moveData = buildCmdData(data);

    mainUiTest::sendWork->sendMessage(moveData);


}

bool motor::writeSpeedParam()//将motor detail的值发送给电机
{
    int address = detail.motorID;
    QString command = motorcmd.writeParameterToROMCMD.arg(QString::number(address,16));
    QByteArray writeData = buildCmdData(command);

    bool writeFlag = mainUiTest::sendWork->sendMessage(writeData);

    //写速度参数
    {
        int anglePid = 36000*detail.speed/detail.pitch;//转angle速度，一定为int
        QString speedStr = QString::number(anglePid,16);
        for (int i = 0;i<12-speedStr.length();i++)
        {
            speedStr  = "0" + speedStr;
        }
        for (int i = 0; i<6;i++)
        {
            motordata.speedPid = motordata.speedPid +  " " +speedStr.right(2);
            speedStr.remove(speedStr.length()-2,2);
        }
        QByteArray speedParamData = buildCmdData(speedStr);

        if(writeFlag) writeFlag = mainUiTest::sendWork->sendMessage(speedParamData);
    }
    return writeFlag;
}

bool motor::writeMaxAngleParam()
{
    int address = detail.motorID;
    QString command = motorcmd.writeParameterToROMCMD.arg(QString::number(address,16));
    QByteArray writeData = buildCmdData(command);

    bool writeFlag = mainUiTest::sendWork->sendMessage(writeData);

    //写最大速度参数
    {    int maxanglePid = 36000*detail.maxSpeed/detail.pitch;//转angle速度，一定为int
        QString maxspeedStr = QString::number(maxanglePid,16);
        for (int i = 0;i<12-maxspeedStr.length();i++)
        {
            maxspeedStr  = "0" + maxspeedStr;
        }
        for (int i = 0; i<6;i++)
        {
            motordata.maxSpeed = motordata.maxSpeed +  " " +maxspeedStr.right(2);
            maxspeedStr.remove(maxspeedStr.length()-2,2);
        }
        QByteArray maxSpeedParamData = buildCmdData(maxspeedStr);

        if(writeFlag) writeFlag = mainUiTest::sendWork->sendMessage(maxSpeedParamData);
    }
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
    while (temp_data.left(1)==" ") {
        temp_data.remove(0,1);
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

    // qDebug()<<"debug from verifySUM"<<builtData.toHex();

    return builtData;
}



