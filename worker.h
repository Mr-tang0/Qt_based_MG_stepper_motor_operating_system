#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include"headers.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    bool sendMessage(QByteArray message);
    bool openReseiveChannal();
    void decodeMessage(QString reseivedMessage);

    void delay(int delayTime);

signals:

public slots:
};

#endif // WORKER_H
