#include "decodethread.h"
#include "test_window.h"
#include "qendian.h"

decodeThread::decodeThread(QObject *parent) : QObject(parent)
{

}

//串口接收解码
//判断来自motor还是weigh
//解码完毕后，发出信号，通知主线程处理ui、更新motor和weigh的信息
void decodeThread::decodeMessage(QString reseivedMessage)
{
    qDebug()<<reseivedMessage;


    //若来自motor，查询motor配置表，解码motor信息
    if(reseivedMessage.left(2)=="3e")
    {
        // qDebug()<<"motor"<<reseivedMessage;

        // QString verify = reseivedMessage.mid(8,2);
        // QString temp = reseivedMessage.mid(0,8);
        // QString reseiveVerify = tempMotor->verifySUM(temp).toHex();

        // if(verify!=reseiveVerify) return;//信息错误，退出解码

        //信息无错误：继续进行

        //多圈角度信息
        if(reseivedMessage.mid(2,2)=="92")
        {
            reseivedMessage = reseivedMessage.remove(0,10);//去除指令数据

            //判断数据有误错误略

            //计算距离
            double length = mutiAngleDecode(reseivedMessage);
            if(length==NULL)
            {
                length = mainUiTest::myMotor->detail.currentAngle;
            }

            mainUiTest::myMotor->detail.currentAngle = length;
            emit currentLength(length);

        }
        if(reseivedMessage.left(2)=="9A")
        {

        }
        else {
            emit motorError(false); //motor数据错误
        }
    }

    //若来自weigh，解码weigh信息
    else
    {
        QString verify = reseivedMessage.right(4);


        reseivedMessage = reseivedMessage.remove(reseivedMessage.length()-4,4);

        QByteArray temp = QByteArray::fromHex(reseivedMessage.toStdString().c_str());

        QString reseiveVerify = tempweigh->CRC16(temp).toHex();

        //判断数据完整无误
        int address = reseivedMessage.left(2).toInt();
        if(verify==reseiveVerify)
        {
            //力回复
            if (reseivedMessage.mid(2,2)=="03")
            {

                double weight = decodeCurrentWeight(reseivedMessage);
                mainUiTest::myWeigh->detail.currentWeight = weight;
                emit currentWeight(weight);
            }
        }
        else {
            emit weighError(address);//weigh数据错误
        }
    }
}



void decodeThread::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}

double decodeThread::mutiAngleDecode(QString message)
{
    QString usefulMessage = message.mid(0,16);//前十六位为数据

    //验证
    if(usefulMessage.length()<8)
    {
        qDebug()<<"motor错误";
        return NULL;
    }
    // QString verify = message.mid(16,2);//后二为验证
    // QString verifyMessage = usefulMessage;
    // int verifyMessageLength = verifyMessage.length();
    // for(int i = 0; i<verifyMessageLength/2;i++)
    // {
    //     verifyMessage = verifyMessage.insert(i*2+i," ");
    // }
    // if(verify!=mainUiTest::myMotor->verifySUM(verifyMessage).toHex())
    // {
    //     qDebug()<<"verify Error"<<verifyMessage;
    //     return NULL;
    // }

    //小端转化为大端
    QString changeUsefulMessage = "";
    for(int i = 0;i<usefulMessage.length()/2;i++)
    {
        changeUsefulMessage = usefulMessage.mid(i*2,2)+changeUsefulMessage;
    }

    //转化
    QByteArray byteArray = QByteArray::fromHex(changeUsefulMessage.toLatin1());
    bool ok;
    //正数
    qDebug()<<changeUsefulMessage.left(1);
    if(changeUsefulMessage.left(1)!="f")
    {

        int currentAngle = changeUsefulMessage.toInt(&ok,16);
        double pitch = mainUiTest::myMotor->detail.pitch;
        double length = pitch*currentAngle/36000.;
        return length;
    }
    //负数
    else
    {
        QByteArray invertedArr(byteArray.size(), Qt::Uninitialized);
        for(int i = 0;i<byteArray.size();i++)
        {
            char originalByte = static_cast<char>(byteArray.at(i));
            char invertedByte = ~originalByte;  // 取反操作
            invertedArr[i] = invertedByte;
        }

        int _currentAngle = -invertedArr.toHex().toUInt(&ok,16);

        double pitch = mainUiTest::myMotor->detail.pitch;
        double length = pitch*_currentAngle/36000.;
        return length;
    }

}

double decodeThread::decodeCurrentWeight(QString message)
{
    QString weightString = message.mid(6,8);

    if(weightString.length()<8)
    {
        qDebug()<<"weigh错误";
    }
    weightString = weightString.mid(4,4)+weightString.mid(0,4);
    double weight;

    bool ok;

    try {
        weight = weightString.toInt(&ok,16);
    } catch (...)
    {
        qDebug()<<"负数";
    }
    if(ok)
    {
        // 正数
        weight = weight*mainUiTest::myWeigh->detail.resolution;

        return weight;
    }
    else
    {
        //负数
        QByteArray ba = QByteArray::fromHex(weightString.toLatin1());
        weight = qint32(ba.toHex().toUInt(nullptr,16));//12

        weight = weight*mainUiTest::myWeigh->detail.resolution;
        return weight;
    }

}
