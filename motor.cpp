#include "motor.h"
#include "widget.h"
motor::motor(QObject *parent) : QObject(parent)
{

}

QByteArray motor::buildData(int motorAddress,QString command)
{
    QString header = "3e";
    QString motor_address = QString::number(motorAddress,16);

    //此处导入json配置表----------------------------------------------此处导入json配置表
    QString rootPath  = QCoreApplication::applicationDirPath();
    QFile file(rootPath+"/motor_command.json");

    bool openflag = file.open(QIODevice::ReadOnly);
    if(!openflag)
    {
        qDebug()<<QStringLiteral("配置文件缺失：'%1'").arg(rootPath+"/motor_command.json");
    }
    QByteArray jsonData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject myObject = jsonDoc.object();
    file.close();

    //配置命令myObject[command]
    if(myObject[command].isNull())//命令不存在就退出返回
    {
        qDebug()<<QStringLiteral("命令'%1'不存在。").arg(command);
        return "";
    }
    QString temp_data = header+" " + myObject[command].toString() + " "+motor_address+" 00";//"00"为发送数据字符长度始终为0

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

    //数据校验
    builtData = builtData+verifySUM(temp_data);

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

    return builtData;
}
