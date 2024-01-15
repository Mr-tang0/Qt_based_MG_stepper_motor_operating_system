#ifndef WEIGH_H
#define WEIGH_H

#include <QObject>
#include"headers.h"

class weigh : public QObject
{
    Q_OBJECT
public:
    explicit weigh(QObject *parent = nullptr);
    
    void getWeight(int weighAddress);
    void shelling(int weighAddress,bool shell);

    int address;

private:
    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray CRC16(QByteArray data);

    QJsonObject weighObject;

signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
