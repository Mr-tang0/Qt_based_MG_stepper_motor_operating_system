#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);
    QByteArray buildData(int motorAddress,QString data);
    QByteArray verifySUM(QString data);
private:


signals:

public slots:
};

#endif // MOTOR_H
