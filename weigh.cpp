#include "weigh.h"
#include "widget.h"
weigh::weigh(QObject *parent) : QObject(parent)
{
    //以下代码暂时为用到
//    QString rootPath  = QCoreApplication::applicationDirPath();
//    QFile weighfile(rootPath+"/weigh_command.json");
//    if(!weighfile.open(QIODevice::ReadOnly))
//    {
//        qDebug()<<QStringLiteral("配置文件缺失：'%1'").arg(rootPath+"/weigh_command.json");
//    }
//    else
//    {
//        QByteArray jsonData = weighfile.readAll();
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//        weighObject = jsonDoc.object();
//        weighfile.close();
//    }

}

//实时重量
void weigh::getWeight(int weighAddress)
{
    QByteArray builtData = buildData(weighAddress,"00:00",false);
    Widget::newworker->sendMessage(builtData);
}

//去皮
void weigh::shelling(int weighAddress,bool shell)
{
    QByteArray builtData;

    builtData = buildData(weighAddress,"23:1",true);
    Widget::newworker->sendMessage(builtData);//关闭写保护

    if(shell)
        builtData = buildData(weighAddress,"15:1",true);
    else
        builtData = buildData(weighAddress,"15:2",true);

     Widget::newworker->sendMessage(builtData);

    builtData = buildData(weighAddress,"23:2",true);
     Widget::newworker->sendMessage(builtData);//开始写保护
}



//数据构建
QByteArray weigh::buildData(int weighAddress,QString data,bool optWork)//data= 1
{
    QByteArray builtData;
    QString temp_data,weigh_address,register_state,register_address,operate;

    weigh_address = QString::number(weighAddress);

    if(optWork)register_state = "06";
    else register_state = "03";

    switch (data.mid(0,2).toInt())
    {
        //关闭写保护/开启写保护
        case 23:
            register_address = "00 17";
            if(data.mid(3,1)=="1")
                operate = "00 01";//关闭写保护
            else operate = "00 00";//开启写保护
        break;

        //获取当前重量
        case 0:
            register_address = "00 00";
            operate = "00 02";
        break;

        //调零
        case 22:
            register_address = "00 16";
            operate = "00 01";
        break;

        //修改通讯速率
        case 14:
            register_address = "00 0E";
            data= QString::number(data.mid(3,-1).toInt(),16);
            operate = data.left(data.length()-2)+" "+data.right(2);
        break;

        //去皮/取消去皮
        case 15:
            register_address = "00 15";
            if(data.mid(3,-1)=="1")operate = "00 01";//去皮
            else operate = "00 02";//取消去皮
        break;

        default:

        break;

    }

    temp_data = weigh_address +" "+register_state+" "+register_address+" "+operate;

    bool ok = false;
    for (const auto &chunk : temp_data.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "转换失败,数据存在错误" ;
            builtData.clear();
            continue;
        }
        else
        {
            builtData.append(char(byteValue));
        }
    }

    //数据校验
    qDebug()<<builtData<<CRC16(builtData);
    if(ok) builtData = builtData+CRC16(builtData);


    return builtData;
}

//数据校验
QByteArray weigh::CRC16(QByteArray data)
{
    //x16+x15+x2+1
    static const uint16_t crc16ModbusPoly = 0xa001;
    quint16 crc = 0xFFFF;

    for (int i = 0; i < data.size(); ++i)
    {
        char byte = data[i];

        for (int j = 0; j < 8; ++j)
        {
            bool bit = byte & 0x01;
            byte >>= 1;
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= crc16ModbusPoly;
            } else {
                crc >>= 1;
            }
            if (bit) {
                crc ^= crc16ModbusPoly;
            }
        }
    }
    QString temp =QString::number(crc,16);
    temp =temp.right(2)+" "+temp.left(temp.length()-2);

    QByteArray dataChange;

    bool ok;
    for (const auto &chunk : temp.split(" "))
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
            dataChange.append(char(byteValue));
        }
    }

    return dataChange;//校验值，高位在后
}
