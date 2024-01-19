#ifndef PORTUI_H
#define PORTUI_H

#include <QWidget>
#include "headers.h"

namespace Ui {
class portUi;
}

class portUi : public QWidget
{
    Q_OBJECT

public:
    explicit portUi(QWidget *parent = nullptr);
    ~portUi();

    void findAvailablePort();
    bool connectSerialPort(int baundRate,QString portName);
    void delay(int time);

private slots:
    void on_connect_clicked();


private:
    Ui::portUi *ui;

signals:
    void portConnected(bool connectflag);
};

#endif // PORTUI_H
