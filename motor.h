#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);



    QByteArray verifySUM(QString data);//数据校验


    bool open();//开电机
    bool close();//关电机
    bool stop();//电机停止

    void speedMove();//电机按照给定速度运动
    void angleMove();//电机按照给定长度运动，需带方向

    bool writeSpeedParam();//设置电机速度
    bool writeMaxAngleParam();//设置电机最大速度

    bool readState1();//读状态123
    bool readState2();
    bool readState3();

    bool clearError();//清除状态1中的报警

    void getLength();//读位置信息

    void modeStretch();//拉伸运动
    void modeCompress();//压缩运动
    void modereciprocate();//往复运动
    void modeConstant();//恒力保持(准备加入pid算法)

    motorDetails detail={0,0.,0.,0.,0.,0.,0.,0.};//初始化

private:
    QByteArray buildCmdData(QString command);//构建发送数据，带校验

    QTimer *InquireTimer;//查询计时器控制停止

    motorCMD motorcmd;
    motorDATA motordata;



signals:
    void MovementInPlace();//运动到位

public slots:
};

#endif // MOTOR_H
