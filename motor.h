#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);

    QByteArray buildCmdData(QString command);

    QByteArray buildData(QString command,QString messageData);

    QByteArray verifySUM(QString data);


    bool open();
    bool close();
    bool stop();

    void speedMove();
    void angleMove();

    bool writeParam();

    bool readState1();
    bool readState2();
    bool readState3();
    bool clearError();

    void getLength();

    void modeStretch();//拉伸
    void modeCompress();//压缩
    void modereciprocate();//往复
    void modeConstant();//恒力

    motorDetails detail={0,0.,0.,0.,0.,0.,0.,0.};//初始化

private:


    QTimer *InquireTimer;//查询计时器控制停止

    motorCMD motorcmd;
    motorDATA motordata;
    motorParam motorparam;


signals:
    void MovementInPlace();//运动到位

public slots:
};

#endif // MOTOR_H
