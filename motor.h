#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);

private:
    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray CRC16(QByteArray data);

signals:

public slots:
};

#endif // MOTOR_H
