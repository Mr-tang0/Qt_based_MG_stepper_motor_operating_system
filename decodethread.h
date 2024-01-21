#ifndef DECODETHREAD_H
#define DECODETHREAD_H

#include <QObject>
#include "headers.h"
#include "weigh.h"
#include "motor.h"

class decodeThread : public QObject
{
    Q_OBJECT
public:
    explicit decodeThread(QObject *parent = nullptr);

    void decodeMessage(QString reseivedMessage);

    double mutiAngleDecode(QString message);//返回距离
    double decodeCurrentWeight(QString message);//返回质量
    void delay(int delayTime);

private:
    weigh *tempweigh = new weigh;
    motor *tempMotor = new motor;

signals:
    void currentLength(double Length);

    void currentSpeed(int motorID,double speed);
    void currentVoltage(int motorID,double voltage);
    void currentCurrent(int motorID,double current);
    void currentTemperature(int motorID,double temperature);

    void currentWeight(double weight);

    void weighError(int weighID);
    void motorError(int motorID);
};

#endif // DECODETHREAD_H
