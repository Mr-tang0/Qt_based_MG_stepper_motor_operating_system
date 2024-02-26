#ifndef WE20X_H
#define WE20X_H

#include "headers.h"
#include <QObject>

class WE20x : public QObject
{
    Q_OBJECT
public:
    explicit WE20x(QObject *parent = nullptr);

    static WE20xDetails details;
    void getSwitchStatus();

    void writeRegister(int registerNumber,bool open);

private:
    QByteArray CRC16(QString data);//数据校验
    WE20xCMD we20xCMD;

signals:
};

#endif // WE20X_H
