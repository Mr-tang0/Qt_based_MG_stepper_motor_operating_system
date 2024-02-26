#include "we20x.h"
#include "test_window.h"

WE20xDetails WE20x::details = {3};

WE20x::WE20x(QObject *parent)
    : QObject{parent}
{}

void WE20x::getSwitchStatus()
{
    QString temp_data = we20xCMD.WE20x_ReadMutiSwitchsCMD.arg(QString::number(details.address,16));

    QByteArray getSwitchStatusCMD;
    bool ok = false;
    for (const auto &chunk : temp_data.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "WE20x转换失败,数据存在错误" ;
            getSwitchStatusCMD.clear();
            continue;
        }
        else
        {
            getSwitchStatusCMD.append(char(byteValue));
        }
    }

    mainUiTest::sendWork->sendMessage(getSwitchStatusCMD+CRC16(temp_data));

}

void WE20x::writeRegister(int registerNumber,bool open)
{
    if(open)
    {
        switch (registerNumber) {
        case 1:
            registerNumber = 1;
            break;
        case 2:
            registerNumber = 2;
            break;
        case 3:
            registerNumber = 4;
            break;
        case 4:
            registerNumber = 8;
            break;
        default:
            break;
        }
    }
    else {
        registerNumber = 0;
    }

    QString temp_data = we20xCMD.WE20x_WriteMutiRegisterCMD.arg(QString::number(details.address,16)).arg(QString::number(registerNumber,16));

    QByteArray writeRegisterCMD;
    bool ok = false;
    for (const auto &chunk : temp_data.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "WE20x转换失败,数据存在错误" ;
            writeRegisterCMD.clear();
            continue;
        }
        else
        {
            writeRegisterCMD.append(char(byteValue));
        }
    }

    mainUiTest::sendWork->sendMessage(writeRegisterCMD+CRC16(temp_data));
    qDebug()<<(writeRegisterCMD+CRC16(temp_data)).toHex();
}

QByteArray WE20x::CRC16(QString data)
{
    QString temp_data = data;
    QByteArray builtData;
    bool ok = false;
    for (const auto &chunk : temp_data.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "WE20x转换失败,数据存在错误" ;
            builtData.clear();
            continue;
        }
        else
        {
            builtData.append(char(byteValue));
        }
    }

    //x16+x15+x2+1
    static const uint16_t crc16ModbusPoly = 0xa001;
    quint16 crc = 0xFFFF;

    for (int i = 0; i < builtData.size(); ++i)
    {
        char byte = builtData[i];

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


    for (const auto &chunk : temp.split(" "))
    {
        uchar byteValue = uchar(chunk.toUShort(&ok, 16));
        if (!ok)
        {
            // 转换失败后的操作，待定
            qDebug() << "WE20x转换失败,数据存在错误" ;
            return "";
        }
        else
        {
            dataChange.append(char(byteValue));
        }
    }

    return dataChange;//校验值，高位在后
}
