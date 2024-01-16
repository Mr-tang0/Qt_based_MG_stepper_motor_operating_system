#include "motor.h"
#include "widget.h"

motor::motor(QObject *parent) : QObject(parent)
{
    //导入配置文件
    QString rootPath  = QCoreApplication::applicationDirPath();

    QFile motorfile(rootPath+"/motor_command.json");

    if(!motorfile.open(QIODevice::ReadOnly))
    {
        qDebug()<<QStringLiteral("配置文件缺失：'%1'").arg(rootPath+"/motor_command.json");
    }
    else
    {
        QByteArray jsonData = motorfile.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        motorCmdObject = jsonDoc.object();
        motorfile.close();
    }
}

bool motor::motorOpen(bool open)
{
    int address = detail.motorID;
    QByteArray openData;
    if(open)
    {
        openData = buildCmdData(address,"motor_open",0);
    }
    else {
        openData = buildCmdData(address,"motor_close",0);
    }

    if(Widget::newworker->sendMessage(openData))
        motorOpenFlag = open;
    return motorOpenFlag;
}

void motor::motorPowerMove(bool direction)
{
    stopMove();

    int address = detail.motorID;
    QByteArray cmdData,data;
    cmdData = buildCmdData(address,"open_circle",2);
    Widget::newworker->sendMessage(cmdData);

    int16_t power = detail.powerControl;
    if(power>850) power = 850;
    else if(power<-850) power = -850;

    if(direction){
        data = buildData("open_circle",QString::number(power));
    }
    else {
        data = buildData("open_circle",QString::number(-power));
    }

    Widget::newworker->sendMessage(data);
}

void motor::stopMove()
{
    int address = detail.motorID;
    QByteArray stopData;
    stopData = buildCmdData(address,"motor_stop",0);
    Widget::newworker->sendMessage(stopData);

}
void motor::moveToSetPosition()
{

}

//数据帧,参数：操作字，数据内容
QByteArray motor::buildData(QString command,QString messageData)
{       

    if(motorCmdObject[command+"_type"].isNull())//命令不存在就退出返回
    {
        qDebug()<<QStringLiteral("命令'%1'不存在。").arg(command+"_type");
        return "";
    }

    QByteArray builtData;
    bool ok;
    QString byte;
    QString temp_data;



    if(motorCmdObject[command+"_type"].toString()=="int_16t")
    {
        byte = QString::number(messageData.toInt(),16);
    }
    else if (motorCmdObject[command+"_type"].toString()=="int_32t") {
        byte = QString::number(messageData.toInt(),32);
    }
    else if (motorCmdObject[command+"_type"].toString()=="int_64t") {
        byte = QString::number(messageData.toInt(),64);
    }
    else if (motorCmdObject[command+"_type"].toString()=="int_64t+int_32t") {
        byte = QString::number(messageData.toInt(),64);
    }

    double len = byte.length();

    for(int i = 0;i<qCeil(len/2);i++)
    {
        uchar byteValue = byte.right(2).toUShort(&ok, 16);
        if(ok)
        {
            temp_data =temp_data+byte.right(2)+" ";
            builtData.append(byteValue);
        }
        else return "";
        byte = QString::number(messageData.toInt(),16).remove(byte.length()-2,2);
    }

    builtData = builtData+verifySUM(temp_data);

    //qDebug()<<"debug from buildData"<<builtData.toHex();

    return builtData;
}


//命令帧,参数：地址，操作字，数据帧长度
QByteArray motor::buildCmdData(int motorAddress,QString command,int commandDataLen)
{
    QString header = "3e";
    QString motor_address = QString::number(motorAddress,16);

    //配置命令 motorObject[command]

    if(motorCmdObject[command].isNull())//命令不存在就退出返回
    {
        qDebug()<<QStringLiteral("命令'%1'不存在。").arg(command);
        return "";
    }

    QString temp_data = header+" "
            + motorCmdObject[command].toString() + " "
            +motor_address+" "
            +QString::number(commandDataLen,16);


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

