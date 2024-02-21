#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include"headers.h"
#include "motor.h"
#include "weigh.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    bool sendMessage(QByteArray message);
    bool openReseiveChannal();

    static QTimer *sendTimer;


private:
    void delay(int delayTime);
    static motor *tempMotor;
    static weigh *tempweigh;

    QList<QByteArray> sendMessageList;

    bool sendFlag;

signals:
    void ReseiveMassage(QString temp);


    void currentPosition(int motorID,double positon);
    void currentSpeed(int motorID,double speed);
    void currentVoltage(int motorID,double voltage);
    void currentCurrent(int motorID,double current);
    void currentTemperature(int motorID,double temperature);

    void currentWeight(int weighID, double weight);

    void weighError(int weighID);
    void motorError(int motorID);

public slots:
};

#endif // WORKER_H
