#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);
    QByteArray buildCmdData(int motorAddress,QString command,int commandDataLen);
    QByteArray buildData(QString command,QString messageData);
    QByteArray verifySUM(QString data);

    motorDetails detail={"",0.,0.,0.,0.,0.,0.};


private:
    QJsonObject motorCmdObject;


signals:

public slots:
};

#endif // MOTOR_H
